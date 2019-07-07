#include "appender_file.h"
#include "appender_file_p.h"

#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QCache>
#include <QTextCodec>
#include <QRegularExpression>
#include <QStandardPaths>

#include "../core/loggerevent.h"

#include <Qpe/Core/Enum>

namespace Qpe
{

namespace LoggerPrivate
{

static const QLatin1String REG_EX_FILENAME1		("^([A-Za-z]:[\\\\" "\\/])?(.*)");
static const QLatin1String REG_EX_FILENAME2		("[*:?\"<>|]");

static const QLatin1String PROP_HEADER			("header");
static const QLatin1String PROP_FLUSH			("immediateFlush");
static const QLatin1String PROP_CONTROLLER_TIME	("controllerCreationTime");
static const QLatin1String PROP_ENCODING		("encoding");
static const QLatin1String PROP_FILE_CACHE_SIZE	("filecachesize");
static const QLatin1String PROP_FILE_NAME		("fileName");

static const QLatin1String PROP_TYPE			("type");
static const QLatin1String PROP_INDEX			("index");
static const QLatin1String INDEX_LAST			("last");

static const QLatin1String FORMAT_TIME			("yyyy-MM-dd hh:mm:ss,zzz");
static const QLatin1String FORMAT_HEADER		("%1 %2 - %3 %4\n");

static const QLatin1String VALUE_UNDERSCORE		("_");

static const QLatin1String EN_s					("s");
static const QLatin1String EN_stdPath			("stdPath");

#define FILES_CACHE_SIZE 32
#define FILES_HEADERS_CACHE_SIZE 1024

// --------------------------------------------------------------------

struct FileNameFactory
{
	static QString createExpression(
		const QString& expressionName, const QVariantMap& properties);
	static QStringList expressionNames();
};

QString FileNameFactory::createExpression(const QString& en, const QVariantMap& p)
{
	if ((en == EN_s) || (en == EN_stdPath)) {
		typedef Enum<QStandardPaths::StandardLocation> StdLocation;

		StdLocation locationType(p.value(PROP_TYPE).toByteArray(),
			QStandardPaths::HomeLocation, Qt::CaseInsensitive);

		QString location;
		QStringList locations = QStandardPaths::standardLocations(locationType.value());
		if (!locations.isEmpty()) {
			QVariant index = p.value(PROP_INDEX);
			location = (index.toString() == INDEX_LAST)
				? locations.last()
				: locations.value(index.toInt());
		}
		return location;
	}
	return QString();
}

QStringList FileNameFactory::expressionNames()
{
	return QStringList() << EN_s << EN_stdPath;
}

// --------------------------------------------------------------------

class FileHelper
{
public:
	inline FileHelper()
		: _fileHeaders(FILES_HEADERS_CACHE_SIZE)
		, _file(nullptr)
		, _codec(nullptr)
		, _headerEnabled(true)
		, _immediateFlush(true)
		, _filenameRegex1(REG_EX_FILENAME1)
		, _filenameRegex2(REG_EX_FILENAME2)
	{
	}
	virtual ~FileHelper() { }

	virtual bool initialize(const QVariantMap& properties)
	{
		_headerEnabled = properties.value(PROP_HEADER, true).toBool();
		_immediateFlush = properties.value(PROP_FLUSH, true).toBool();
		if (_headerEnabled) {
			_headerTime = properties
				.value(PROP_CONTROLLER_TIME, QDateTime::currentDateTime())
				.toDateTime().toString(FORMAT_TIME);
		}
		return initializeCodec(properties.value(PROP_ENCODING).toByteArray());
	}

	virtual void changeFile(const LoggerEvent* loggerEvent)
	{
		Q_UNUSED(loggerEvent)
	}

	inline void setFile(QFile* file) { _file = file; }
	inline bool write(const QString& text)
	{
		_file->write(_codec->fromUnicode(text));
		if (_immediateFlush)
			_file->flush();
		return true;
	}
	inline bool open()
	{
		return
			isFileOpen() || (
				createPath() &&
				openFile() &&
				writeHeader()
			);
	}
protected:
	inline QString correctFileName(const QString& filename) const
	{
		QRegularExpressionMatch m = _filenameRegex1.match(filename);
		Q_ASSERT(m.hasMatch());
		return m.captured(1).append(m.captured(2).replace(_filenameRegex2, VALUE_UNDERSCORE));
	}
private:
	inline bool initializeCodec(const QByteArray& encoding)
	{
		return
			(_codec = QTextCodec::codecForName(encoding)) ||
			(_codec = QTextCodec::codecForName("utf-8"));
	}
	inline bool isFileOpen() { return _file->isOpen(); }
	inline bool createPath()
	{
		QDir dir = QFileInfo(_file->fileName()).absoluteDir();
		return QDir().mkpath(dir.path());
	}
	inline bool openFile() {
		return _file->open(
			QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
	}
	inline bool writeHeader()
	{
		if	(_headerEnabled &&
			(_fileHeaders.object(_file->fileName()) == nullptr))
		{
			QString s(40, '-');
			s = QString(FORMAT_HEADER)
				.arg(s, _headerTime, _file->fileName(), s);
			write(s);
			_fileHeaders.insert(_file->fileName(), new int(1));
		}
		return true;
	}
	QCache<QString, int> _fileHeaders;
	QFile* _file;
	QTextCodec* _codec;
	QString _headerTime;
	bool _headerEnabled;
	bool _immediateFlush;
	QRegularExpression _filenameRegex1;
	QRegularExpression _filenameRegex2;
};

class FileHelperSingle : public FileHelper
{
public:
	FileHelperSingle(const QString& fileName)
		: FileHelper()
		, file(correctFileName(fileName))
	{
		setFile(&file);
	}
private:
	QFile file;
};

class FileHelperCached : public FileHelper
{
	typedef QCache<QString, QFile> Files;
public:
	FileHelperCached(const Pattern& fileNamePattern)
		: FileHelper()
		, fileNamePattern(fileNamePattern)
		, files(FILES_CACHE_SIZE)
	{
	}
	virtual bool initialize(const QVariantMap& properties)
	{
		return
			FileHelper::initialize(properties) &&
			initializeCache(properties.value(PROP_FILE_CACHE_SIZE).toInt());
	}
	virtual void changeFile(const LoggerEvent* loggerEvent)
	{
		EventWrapper ew(loggerEvent);
		QString fileName = correctFileName(fileNamePattern.createString(ew));
		QFile* f = files.object(fileName);
		if (f == nullptr) {
			f = new QFile(fileName);
			files.insert(fileName, f);
		}
		setFile(f);
	}
private:
	inline bool initializeCache(int fileCacheSize)
	{
		if (fileCacheSize > 0)
			files.setMaxCost(fileCacheSize);
		return true;
	}
	Pattern fileNamePattern;
	Files files;
};

} // namespace LoggerPrivate

// ------------------------------------------------------------------------

FileLoggerAppenderPrivate::FileLoggerAppenderPrivate()
	: AbstractPatternLoggerAppenderPrivate()
{
}

FileLoggerAppenderPrivate::~FileLoggerAppenderPrivate()
{
}

QString FileLoggerAppenderPrivate::parseFileName(const QVariantMap& p)
{
	QString fileName = p.value(LoggerPrivate::PROP_FILE_NAME).toString();
	if (fileName.isEmpty()) { return fileName; }
	SimpleConversionPattern pattern;
	typedef LoggerPrivate::FileNameFactory Factory;
	pattern.initialize(
		fileName, Factory::expressionNames(), &Factory::createExpression);
	return pattern.createString();
}

bool FileLoggerAppenderPrivate::initializeFile(const QVariantMap& properties)
{
	QString fileName = parseFileName(properties);
	bool result = !fileName.isEmpty();
	if (result) {
		LoggerPrivate::Pattern pattern;
		typedef LoggerPrivate::Factory Factory;
		pattern.initialize(
			fileName, Factory::expressionNames(), &Factory::createExpression);
		if (pattern.containsExpressions()) {
			fileHelper.reset(new LoggerPrivate::FileHelperCached(pattern));
		} else {
			fileHelper.reset(new LoggerPrivate::FileHelperSingle(fileName));
		}
		result = fileHelper->initialize(properties);
	}
	return result;
}

void FileLoggerAppenderPrivate::write(
	const LoggerEvent* loggerEvent, const QString& text)
{
	fileHelper->changeFile(loggerEvent);
	if (fileHelper->open()) {
		fileHelper->write(text);
	}
}

// ---------------------------------------------------------------------------

FileLoggerAppender::FileLoggerAppender(FileLoggerAppenderPrivate* dd)
	: AbstractPatternLoggerAppender(dd)
{
}

FileLoggerAppender::FileLoggerAppender()
	: AbstractPatternLoggerAppender(new FileLoggerAppenderPrivate())
{
}

FileLoggerAppender::~FileLoggerAppender()
{
}

bool FileLoggerAppender::initialize(const QVariantMap& properties)
{
	QA_D();
	return
		d->initializeFile(properties) &&
		AbstractPatternLoggerAppender::initialize(properties);
}

void FileLoggerAppender::write(
	const LoggerEvent* loggerEvent, const QString& message)
{
	QA_D();
	d->write(loggerEvent, message);
}

} // namespace Qpe

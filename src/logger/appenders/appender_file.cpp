#include "appender_file.h"
#include "appender_file_p.h"

#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QCache>
#include <QTextCodec>
#include <QRegularExpression>
#include <QStandardPaths>

#include <Qpe/Core/DateStringifier>
#include <Qpe/Core/Enum>

#include <Qpe/Logger/LoggerEvent>

namespace Qpe
{

namespace LoggerPrivate
{

static const QRegularExpression REGEXP_FILENAME_MATCH	("^([A-Za-z]:[\\\\" "\\/])?(.*)");
static const QRegularExpression REGEXP_FILENAME_REPLACE	("[*:?\"<>|]");

static const QLatin1String PROP_HEADER					("header");
static const QLatin1String PROP_HEADER_PATTERN			("header.pattern");
static const QLatin1String PROP_HEADER_PATTERN_DEFAULT	("%40E{padding=-} %T %F %40E{padding=-}\n");
static const QLatin1String PROP_FLUSH					("flush");
static const QLatin1String PROP_CONTROLLER_TIME			("controllerCreationTime");
static const QLatin1String PROP_ENCODING				("encoding");
static const QLatin1String PROP_FILE_CACHE_SIZE			("fileCacheSize");
static const QLatin1String PROP_FILE_NAME				("fileName");

static const QLatin1String VALUE_UNDERSCORE				("_");

static const QLatin1String EN__STDPATH					("stdPath");
static const QLatin1String EN__STDPATH__SHORT			("s");
static const QLatin1String PROP__STDPATH__TYPE			("type");
static const QLatin1String PROP__STDPATH__INDEX			("index");
static const QLatin1String INDEX_LAST					("last");

static const QLatin1String EN__TIME						("time");
static const QLatin1String EN__TIME__SHORT				("T");
static const QLatin1String PROP__TIME__FORMAT			("format");
static const QLatin1String PROP__TIME__FORMAT__DEFAULT	("yyyy-MM-dd hh:mm:ss,zzztt");

static const QLatin1String EN__EMPTY					("empty");
static const QLatin1String EN__EMPTY__SHORT				("E");

static const QLatin1String EN__FILE						("fileName");
static const QLatin1String EN__FILE__SHORT				("F");

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
	if ((en == EN__STDPATH__SHORT) || (en == EN__STDPATH)) {
		typedef Enum<QStandardPaths::StandardLocation> StdLocation;

		StdLocation locationType(p.value(PROP__STDPATH__TYPE).toByteArray(),
			QStandardPaths::HomeLocation, Qt::CaseInsensitive);

		QString location;
		QStringList locations = QStandardPaths::standardLocations(locationType.value());
		if (!locations.isEmpty()) {
			QVariant index = p.value(PROP__STDPATH__INDEX);
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
	return { EN__STDPATH, EN__STDPATH__SHORT };
}

// ------------------------------------------------------------------------

class FileHelper;
typedef Qpe::ConversionPattern<FileHelper> HeaderPattern;

class FileHelper
{
public:
	FileHelper();
	virtual ~FileHelper() = default;

	virtual bool initialize(const QVariantMap& properties);
	virtual void changeFile(const LoggerEvent* loggerEvent);

	QString fileName() const;
	QDateTime headerTime() const;

	void setFile(QFile* file);
	bool write(const QString& text) const;

	bool open();
protected:
	static QString correctFileName(const QString& filename);
private:
	bool initializeCodec(const QByteArray& encoding);
	bool isFileOpen() const;
	bool createPath() const;
	bool openFile();
	bool writeHeader();
private:
	QCache<QString, int> fileHeaders;
	QFile* file;
	QTextCodec* codec;
	QDateTime time;
	HeaderPattern headerPattern;
	bool headerEnabled;
	bool immediateFlush;
};

// --------------------------------------------------------------------

struct HeaderFactory
{
	static HeaderPattern::ExpressionFunctor createExpression(
		const QString& expressionName, const QVariantMap& properties);
	static QStringList expressionNames();
};
HeaderPattern::ExpressionFunctor HeaderFactory::createExpression(
	const QString& en, const QVariantMap& p)
{
	if ((en == EN__TIME) || (en == EN__TIME__SHORT)) {
		Qpe::DateStringifier s;
		s.setFormatString(
			p.value(PROP__TIME__FORMAT,
					PROP__TIME__FORMAT__DEFAULT).toString());
		return [s] (const FileHelper& d) { return s.format(d.headerTime()); };
	} else
	if ((en == EN__FILE) || (en == EN__FILE__SHORT)) {
		return [] (const FileHelper& d) { return d.fileName(); };
	} else
	if ((en == EN__EMPTY) || (en == EN__EMPTY__SHORT)) {
		return [] (const FileHelper&) { return QString(); };
	}
	return [] (const FileHelper&) { return QString(); };
}

QStringList HeaderFactory::expressionNames()
{
	return
	{
		EN__TIME, EN__TIME__SHORT,
		EN__FILE, EN__FILE__SHORT,
		EN__EMPTY, EN__EMPTY__SHORT
	};
}

// --------------------------------------------------------------------

FileHelper::FileHelper()
	: fileHeaders(FILES_HEADERS_CACHE_SIZE)
	, file(nullptr)
	, codec(nullptr)
	, headerEnabled(true)
	, immediateFlush(true)
{
}

bool FileHelper::initialize(const QVariantMap& properties)
{
	immediateFlush = properties.value(PROP_FLUSH, true).toBool();

	time = properties.value(
		PROP_CONTROLLER_TIME, QDateTime::currentDateTime()).toDateTime();

	headerEnabled = properties.value(PROP_HEADER, true).toBool();
	if (headerEnabled) {
		QString p = properties.value(
			PROP_HEADER_PATTERN, PROP_HEADER_PATTERN_DEFAULT).toString();
		headerEnabled = !p.isEmpty();
		headerPattern.initialize(p,
			HeaderFactory::expressionNames(), &HeaderFactory::createExpression);
	}
	return initializeCodec(properties.value(PROP_ENCODING).toByteArray());
}

void FileHelper::changeFile(const LoggerEvent* loggerEvent)
{
	Q_UNUSED(loggerEvent);
}

QString FileHelper::fileName() const
{
	return file->fileName();
}

QDateTime FileHelper::headerTime() const
{
	return time;
}

void FileHelper::setFile(QFile* f)
{
	file = f;
}

bool FileHelper::write(const QString& text) const
{
	file->write(codec->fromUnicode(text));
	if (immediateFlush)
		file->flush();
	return true;
}

bool FileHelper::open()
{
	return isFileOpen() || (createPath() && openFile() && writeHeader());
}

QString FileHelper::correctFileName(const QString& filename)
{
	QRegularExpressionMatch m = REGEXP_FILENAME_MATCH.match(filename);
	Q_ASSERT(m.hasMatch());
	return m.captured(1)
			.append(m.captured(2).replace(REGEXP_FILENAME_REPLACE, VALUE_UNDERSCORE));
}

bool FileHelper::initializeCodec(const QByteArray& encoding)
{
	return
		(codec = QTextCodec::codecForName(encoding)) ||
		(codec = QTextCodec::codecForName("utf-8"));
}

bool FileHelper::isFileOpen() const
{
	return file->isOpen();
}

bool FileHelper::createPath() const
{
	QDir dir = QFileInfo(file->fileName()).absoluteDir();
	return QDir().mkpath(dir.path());
}

bool FileHelper::openFile()
{
	return file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
}

bool FileHelper::writeHeader()
{
	if  (headerEnabled &&
		(fileHeaders.object(fileName()) == nullptr))
	{
		QString h = headerPattern.createString(*this);
		write(h);
		fileHeaders.insert(fileName(), new int(1));
	}
	return true;
}

// ------------------------------------------------------------------------

class FileHelperSingle : public FileHelper
{
public:
	FileHelperSingle(const QString& fileName);
	virtual ~FileHelperSingle() Q_DECL_OVERRIDE = default;
private:
	QFile file;
};

FileHelperSingle::FileHelperSingle(const QString& fileName)
	: FileHelper()
	, file(correctFileName(fileName))
{
	setFile(&file);
}

// ------------------------------------------------------------------------

class FileHelperCached : public FileHelper
{
	typedef QCache<QString, QFile> Files;
public:
	FileHelperCached(const Pattern& fileNamePattern);
	virtual ~FileHelperCached() Q_DECL_OVERRIDE = default;

	virtual bool initialize(const QVariantMap& properties) Q_DECL_OVERRIDE;
	virtual void changeFile(const LoggerEvent* loggerEvent) Q_DECL_OVERRIDE;
private:
	bool initializeCache(int fileCacheSize);
	Pattern fileNamePattern;
	Files files;
};

FileHelperCached::FileHelperCached(const Pattern& fileNamePattern)
	: FileHelper()
	, fileNamePattern(fileNamePattern)
	, files(FILES_CACHE_SIZE)
{
}

bool FileHelperCached::initialize(const QVariantMap& properties)
{
	return
		FileHelper::initialize(properties) &&
		initializeCache(properties.value(PROP_FILE_CACHE_SIZE).toInt());
}

void FileHelperCached::changeFile(const LoggerEvent* loggerEvent)
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

bool FileHelperCached::initializeCache(int fileCacheSize)
{
	if (fileCacheSize > 0)
		files.setMaxCost(fileCacheSize);
	return true;
}

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

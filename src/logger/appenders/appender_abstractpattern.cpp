#include "appender_abstractpattern.h"
#include "appender_abstractpattern_p.h"

#include <QTextStream>

#include <Qpe/Core/Stringifier>
#include <Qpe/Core/DateStringifier>

#include <Qpe/Logger/LoggerEvent>

/*!
 * \class Qpe::AbstractPatternLoggerAppender
 * \inmodule logger
 * \brief Абстрактный шаблонный appender.
 * \inheaderfile Qpe/Logger/Private/abstractpatternloggerappender_p.h
 * \ingroup logger
 *
 * Необходимые параметры инициализации метода AbstractPatternLoggerAppender::initialize():
 * \table
 *   \header
 *   \row \li Наименование \li Описание
 *   \row \li \b pattern      \li шаблон для преобразования сообщения
 *   \row \li \b pattern.N    \li тоже что и pattern; N - последовательность 0..<=99
 * \endtable
 *
 * Если найден параметр \b pattern будет использоваться однострочный шаблон.
 *
 * Иначе если найден параметр \b pattern.N будет использоваться многострочный шаблон.
 *
 * Шаблоны строк могут содержать следующие выражения:
 * \table
 *   \header
 *   \row \li Имя элемента  \li Сокращение \li параметры \li описание
 *   \row \li clasName      \li c          \li           \li имя класса
 *   \row \li componentName \li N          \li           \li имя компонента
 *   \row \li message       \li m          \li           \li сообщение
 *   \row \li eventId       \li e          \li format    \li идентификатор события\sup 1; format - Qpe::Stringifier::setFormatString()
 *   \row \li loggerId      \li l          \li format    \li идентификатор logger'a\sup 1; format - Qpe::Stringifier::setFormatString()
 *   \row \li dateTime      \li d          \li format    \li время события; format - Qpe::DateStringifier::setFormatString()
 *   \row \li eventType     \li p          \li           \li тип события
 *   \row \li newLine       \li n          \li           \li перевод строки, лучше использовать \\n
 *   \row \li objectAddress \li O          \li format    \li адрес объекта\sup 2; format - Qpe::Stringifier::setFormatString()
 *   \row \li objectName    \li o          \li           \li
 *   \row \li threadAddress \li T          \li format    \li адрес потока\sup 2; format - Qpe::Stringifier::setFormatString()
 *   \row \li threadName    \li t          \li           \li
 *   \row \li %             \li -          \li           \li
 * \endtable
 * \sup 1 - формат по умолчанию: десятичное число без ведущих нулей
 *
 * \sup 2 - формат адреса по умолчанию: шестнадцатеричное число с префиксом '0x' и ведущими нулями
 */

namespace Qpe
{

namespace PrivateLogger
{

static const QLatin1String EN_className		("className");
static const QLatin1String EN_c				("c");
static const QLatin1String EN_componentName	("componentName");
static const QLatin1String EN_N				("N");
static const QLatin1String EN_message		("message");
static const QLatin1String EN_m				("m");
static const QLatin1String EN_eventId		("eventId");
static const QLatin1String EN_e				("e");
static const QLatin1String EN_loggerId		("loggerId");
static const QLatin1String EN_l				("l");
static const QLatin1String EN_dateTime		("dateTime");
static const QLatin1String EN_d				("d");
static const QLatin1String EN_eventType		("eventType");
static const QLatin1String EN_p				("p");
static const QLatin1String EN_newLine		("newLine");
static const QLatin1String EN_n				("n");
static const QLatin1String EN_objectAddress	("objectAddress");
static const QLatin1String EN_O				("O");
static const QLatin1String EN_objectName	("objectName");
static const QLatin1String EN_o				("o");
static const QLatin1String EN_threadAddress	("threadAddress");
static const QLatin1String EN_T				("T");
static const QLatin1String EN_threadName	("threadName");
static const QLatin1String EN_t				("t");
static const QLatin1String EN_percent		("%");

static const QLatin1String PROP_FORMAT		("format");
static const QLatin1String PROP_PATTERN		("pattern");

static const QLatin1String FORMAT_ADDRESS	("16pl");

static const QLatin1String VALUE_NEW_LINE	("\n");
static const QLatin1String VALUE_PERCENT	("%");

class LineAdapter
{
public:
	virtual ~LineAdapter() { }

	virtual void setText(const QString& t) = 0;
	virtual bool hasText() = 0;
	virtual QString line() = 0;
};

class SingleLineAdapter : public LineAdapter
{
public:
	virtual void setText(const QString& t) { text = t; readed = false; }
	virtual bool hasText() { return !readed; }
	virtual QString line() { readed = true; return text; }
private:
	QString text;
	bool readed;
};

class MultiLineAdapter : public LineAdapter
{
public:
	virtual void setText(const QString& t)
	{
		text = t;
		stream.setString(&text, QIODevice::ReadOnly);
		readed = false;
	}
	virtual bool hasText()
	{
		readed = false;
		return !stream.atEnd();
	}
	virtual QString line()
	{
		if (readed) {
			return textLine;
		} else {
			readed = true;
			return textLine = stream.readLine();
		}
	}
private:
	QString text;
	QTextStream stream;
	bool readed;
	QString textLine;
};

// ------------------------------------------------------------------------

EventWrapper::EventWrapper(const LoggerEvent* le, const LineAdapterPointer& la)
	: loggerEvent(le), lineAdapter(la)
{
}

EventWrapper::EventWrapper(const LoggerEvent* le)
	: loggerEvent(le), lineAdapter(new SingleLineAdapter())
{
	lineAdapter->setText(le->message());
}

EventWrapper::~EventWrapper() { }

uint EventWrapper::loggerId() const { return loggerEvent->loggerId(); }
uint EventWrapper::eventId() const { return loggerEvent->eventId(); }
QString EventWrapper::componentName() const { return loggerEvent->componentName(); }
QObject* EventWrapper::object() const { return loggerEvent->object(); }
QString EventWrapper::objectName() const { return loggerEvent->objectName(); }
QString EventWrapper::className() const { return loggerEvent->className(); }
EventType EventWrapper::eventType() const { return loggerEvent->eventType(); }
QString EventWrapper::eventTypeName() const { return loggerEvent->eventTypeName(); }
QThread* EventWrapper::thread() const { return loggerEvent->thread(); }
QString EventWrapper::threadName() const { return loggerEvent->threadName(); }
QDateTime EventWrapper::dateTime() const { return loggerEvent->dateTime(); }
bool EventWrapper::hasMessage() const { return lineAdapter->hasText(); }
QString EventWrapper::message() const { return lineAdapter->line(); }

// ------------------------------------------------------------------------

Pattern::ExpressionFunctor Factory::createExpression(
	const QString& en, const QVariantMap& p)
{
	if ((en == EN_c) || (en == EN_className)) {
		return [] (const EventWrapper& e) { return e.className(); };
	} else
	if ((en == EN_N) || (en == EN_componentName)) {
		return [] (const EventWrapper& e) { return e.componentName(); };
	} else
	if ((en == EN_m) || (en == EN_message)) {
		return [] (const EventWrapper& e) { return e.message(); };
	} else
	if ((en == EN_e) || (en == EN_eventId)) {
		Qpe::Stringifier s;
		if (p.contains(PROP_FORMAT)) { s.setFormatString(p.value(PROP_FORMAT).toString()); }
		QString cache;
		return [s, cache] (const EventWrapper& e) mutable
		{ return s.format(e.eventId(), cache); };
	} else
	if ((en == EN_l) || (en == EN_loggerId)) {
		Qpe::Stringifier s;
		if (p.contains(PROP_FORMAT)) { s.setFormatString(p.value(PROP_FORMAT).toString()); }
		QString cache;
		return [s, cache] (const EventWrapper& e) mutable
		{ return s.format(e.loggerId(), cache); };
	} else
	if ((en == EN_d) || (en == EN_dateTime)) {
		Qpe::DateStringifier s;
		if (p.contains(PROP_FORMAT)) { s.setFormatString(p.value(PROP_FORMAT).toString()); }
		return [s] (const EventWrapper& e) { return s.format(e.dateTime()); };
	} else
	if ((en == EN_p) || (en == EN_eventType)) {
		return [] (const EventWrapper& e) { return e.eventTypeName(); };
	} else
	if ((en == EN_n) || (en == EN_newLine)) {
		return [] (const EventWrapper&) { return VALUE_NEW_LINE; };
	} else
	if ((en == EN_O) || (en == EN_objectAddress)) {
		Qpe::Stringifier s;
		s.setFormatString(p.contains(PROP_FORMAT)
			? p.value(PROP_FORMAT).toString()
			: FORMAT_ADDRESS);
		QString cache;
		return [s, cache] (const EventWrapper& e) mutable
		{ return s.format(e.object(), cache); };
	} else
	if ((en == EN_o) || (en == EN_objectName)) {
		return [] (const EventWrapper& e) { return e.objectName(); };
	} else
	if (en == EN_percent) {
		return [] (const EventWrapper&) { return VALUE_PERCENT; };
	} else
	if ((en == EN_T) || (en == EN_threadAddress)) {
		Qpe::Stringifier s;
		s.setFormatString(p.contains(PROP_FORMAT)
			? p.value(PROP_FORMAT).toString()
			: FORMAT_ADDRESS);
		QString cache;
		return [s, cache] (const EventWrapper& e) mutable
		{ return s.format(e.thread(), cache); };
	} else
	if ((en == EN_t) || (en == EN_threadName)) {
		return [] (const EventWrapper& e) { return e.threadName(); };
	}
	Q_UNREACHABLE();
}

QStringList Factory::expressionNames()
{
	return QStringList()
		<< EN_c << EN_className
		<< EN_N << EN_componentName
		<< EN_m << EN_message
		<< EN_e << EN_eventId
		<< EN_l << EN_loggerId
		<< EN_d << EN_dateTime
		<< EN_p << EN_eventType
		<< EN_n << EN_newLine
		<< EN_O << EN_objectAddress
		<< EN_o << EN_objectName
		<< EN_percent
		<< EN_T << EN_threadAddress
		<< EN_t << EN_threadName;
}

} // namespace PrivateLogger

// ------------------------------------------------------------------------

AbstractPatternLoggerAppenderPrivate::AbstractPatternLoggerAppenderPrivate()
{
}

AbstractPatternLoggerAppenderPrivate::~AbstractPatternLoggerAppenderPrivate()
{
}

bool AbstractPatternLoggerAppenderPrivate::initializePatterns(
	const QVariantMap& properties)
{
	typedef PrivateLogger::Factory Factory;
	typedef PrivateLogger::Pattern Pattern;
	auto appendPattern = [this, properties] (QVariantMap::const_iterator it) -> bool
	{
		if (it == properties.end()) { return false; }
		QString p = it->toString();
		patterns.append(Pattern(p, Factory::expressionNames(), &Factory::createExpression));
		return true;
	};
	// если есть свойство "pattern" - логи однострочные
	if (appendPattern(properties.find(PrivateLogger::PROP_PATTERN))) {
		lineAdapter.reset(new PrivateLogger::SingleLineAdapter());
		return true;
	}
	// иначе считаем, что логи многострочные
	lineAdapter.reset(new PrivateLogger::MultiLineAdapter());
	// и пытаемся разобрать свойства "pattern.i"
	for (int i = 0; i < 100; ++i) {
		auto it = properties.find(QString("%1.%2").arg(
				PrivateLogger::PROP_PATTERN, QString::number(i)));
		if (!appendPattern(it)) { break; }
	}
	return !patterns.isEmpty();
}

QString AbstractPatternLoggerAppenderPrivate::createMessage(
	const LoggerEvent* loggerEvent)
{
	int patternsCount = patterns.size();
	if (patternsCount == 0) { return QString(); }

	lineAdapter->setText(loggerEvent->message());
	PrivateLogger::EventWrapper ew(loggerEvent, lineAdapter);
	QString messageText;
	int i = 0;
	while (ew.hasMessage()) {
		messageText.append(patterns[i++].createString(ew));
		if (patternsCount == i) { --i; }
	}
	return messageText;
}

// ------------------------------------------------------------------------

AbstractPatternLoggerAppender::AbstractPatternLoggerAppender(AbstractPatternLoggerAppenderPrivate* dd)
	: d_ptr(dd)
{
	QA_D();
	d->q_ptr = this;
}

AbstractPatternLoggerAppender::AbstractPatternLoggerAppender()
	: d_ptr(new AbstractPatternLoggerAppenderPrivate())
{
	QA_D();
	d->q_ptr = this;
}

AbstractPatternLoggerAppender::~AbstractPatternLoggerAppender()
{
}

/*!
 * \fn bool AbstractPatternLoggerAppender::initialize(const QVariantMap& properties)
 * \reimp
 */
bool AbstractPatternLoggerAppender::initialize(const QVariantMap& properties)
{
	QA_D();
	return d->initializePatterns(properties);
}

/*!
 * \fn void AbstractPatternLoggerAppender::append(const LoggerEvent* loggerEvent)
 * \reimp
 */
void AbstractPatternLoggerAppender::append(const LoggerEvent* loggerEvent)
{
	QA_D();
	write(loggerEvent, d->createMessage(loggerEvent));
}

/*!
 * \fn void AbstractPatternLoggerAppender::write(const LoggerEvent* loggerEvent, const QString& message)
 * Вывод подготовленного сообщения \a message в лог.
 * Сообщение \a message строится из \a loggerEvent на основании логики
 * класса AbstractPatternLoggerAppender.
 */

} // namespace Qpe

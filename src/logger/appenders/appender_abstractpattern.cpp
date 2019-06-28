#include "appender_abstractpattern.h"
#include "appender_abstractpattern_p.h"

#include <QTextStream>

#include <Qpe/Core/Stringifier>
#include <Qpe/Core/DateStringifier>

#include "../core/loggerevent.h"

namespace Qpe
{

namespace LoggerPrivate
{

static const QLatin1String EN_className		("className");
static const QLatin1String EN_c				("c");
static const QLatin1String EN_pluginName	("pluginName");
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
static const QLatin1String PROP_PATTERN_2	("otherLinePattern");

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
QString EventWrapper::pluginName() const { return loggerEvent->pluginName(); }
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
	if ((en == EN_N) || (en == EN_pluginName)) {
		return [] (const EventWrapper& e) { return e.pluginName(); };
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
		<< EN_N << EN_pluginName
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

} // namespace LoggerPrivate

// ------------------------------------------------------------------------

AbstractPatternLoggerAppenderPrivate::AbstractPatternLoggerAppenderPrivate()
{
}

AbstractPatternLoggerAppenderPrivate::~AbstractPatternLoggerAppenderPrivate()
{
}

void AbstractPatternLoggerAppenderPrivate::initializePattern(
	const QString& firstLinePattern, const QString& otherLinePattern)
{
	typedef LoggerPrivate::Factory Factory;
	pattern1.initialize(
		firstLinePattern, Factory::expressionNames(), &Factory::createExpression);
	if (otherLinePattern.isEmpty()) {
		lineAdapter.reset(new LoggerPrivate::SingleLineAdapter());
	} else {
		pattern2.initialize(
			otherLinePattern, Factory::expressionNames(), &Factory::createExpression);
		lineAdapter.reset(new LoggerPrivate::MultiLineAdapter());
	}
}

QString AbstractPatternLoggerAppenderPrivate::createMessage(
	const LoggerEvent* loggerEvent)
{
	lineAdapter->setText(loggerEvent->message());
	LoggerPrivate::EventWrapper ew(loggerEvent, lineAdapter);
	QString messageText = pattern1.createString(ew);
	while (ew.hasMessage()) {
		messageText.append(pattern2.createString(ew));
	}
	return messageText;
}

// ------------------------------------------------------------------------

AbstractPatternLoggerAppender::AbstractPatternLoggerAppender(AbstractPatternLoggerAppenderPrivate* dd)
	: d_ptr(dd)
{
	Q_D(AbstractPatternLoggerAppender);
	d->q_ptr = this;
}

AbstractPatternLoggerAppender::AbstractPatternLoggerAppender()
	: d_ptr(new AbstractPatternLoggerAppenderPrivate())
{
	Q_D(AbstractPatternLoggerAppender);
	d->q_ptr = this;
}

AbstractPatternLoggerAppender::~AbstractPatternLoggerAppender()
{
}

bool AbstractPatternLoggerAppender::initialize(const QVariantMap& properties)
{
	Q_D(AbstractPatternLoggerAppender);
	QString pattern = properties.value(LoggerPrivate::PROP_PATTERN).toString();
	bool result = !pattern.isEmpty();
	if (result)
		d->initializePattern(pattern, properties.value(LoggerPrivate::PROP_PATTERN_2).toString());
	return result;
}

void AbstractPatternLoggerAppender::append(const LoggerEvent* loggerEvent)
{
	Q_D(AbstractPatternLoggerAppender);
	write(loggerEvent, d->createMessage(loggerEvent));
}

} // namespace Qpe

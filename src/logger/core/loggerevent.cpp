#include "loggerevent.h"
#include "loggerevent_p.h"

#include <QMetaEnum>

namespace Qpe
{

template <typename Enum>
inline QString enumToString(Enum e)
{
	static QMetaEnum me = QMetaEnum::fromType<Enum>();
	return me.valueToKey(static_cast<int>(e));
}

LoggerEventPrivate::LoggerEventPrivate(
		uint lid,
		const QString& pn,
		QObject* o,
		const QString& on,
		const QString& cn,
		EventType et,
		QThread* t,
		const QString& tn,
		const QString& m,
		const LoggerAppenderList& a,
		const LoggerFilterList& f)
	: eventIdEmpty(true)
	, eventId(0)
	, loggerId(lid)
	, pluginName(pn)
	, object(o)
	, objectName(on)
	, className(cn)
	, eventType(et)
	, eventTypeName(enumToString(et))
	, thread(t)
	, threadName(tn)
	, message(m)
	, dateTime(QDateTime::currentDateTime())
	, appenders(a)
	, filters(f)
{
}

LoggerEventPrivate::~LoggerEventPrivate()
{
}

uint LoggerEventPrivate::newEventId()
{
	static QAtomicInteger<uint> eventId(0);
	return eventId.fetchAndAddOrdered(1);
}


// ---------------------------------------------------------------------------

LoggerEvent::LoggerEvent(int loggerId,
	const QString& pluginName,
	QObject* object,
	const QString& objectName,
	const QString& className,
	EventType eventType,
	QThread* thread,
	const QString& threadName,
	const QString& message,
	const LoggerAppenderList& appenders,
	const LoggerFilterList& filters)
	: d_ptr(new LoggerEventPrivate(
		loggerId, pluginName, object, objectName, className,
		eventType, thread, threadName, message, appenders, filters))
{
	Q_D(LoggerEvent);
	d->q_ptr = this;
}

LoggerEvent::~LoggerEvent()
{
}

uint LoggerEvent::loggerId() const
{
	Q_D(const LoggerEvent);
	return d->loggerId;
}

uint LoggerEvent::eventId() const
{
	Q_D(const LoggerEvent);
	if (d->eventIdEmpty) {
		d->eventId = d->newEventId();
		d->eventIdEmpty = false;
	}
	return d->eventId;
}

QString LoggerEvent::pluginName() const
{
	Q_D(const LoggerEvent);
	return d->pluginName;
}

QObject* LoggerEvent::object() const
{
	Q_D(const LoggerEvent);
	return d->object;
}

QString LoggerEvent::objectName() const
{
	Q_D(const LoggerEvent);
	return d->objectName;
}

QString LoggerEvent::className() const
{
	Q_D(const LoggerEvent);
	return d->className;
}

EventType LoggerEvent::eventType() const
{
	Q_D(const LoggerEvent);
	return d->eventType;
}

QString LoggerEvent::eventTypeName() const
{
	Q_D(const LoggerEvent);
	return d->eventTypeName;
}

QThread* LoggerEvent::thread() const
{
	Q_D(const LoggerEvent);
	return d->thread;
}

QString LoggerEvent::threadName() const
{
	Q_D(const LoggerEvent);
	return d->threadName;
}

QString LoggerEvent::message() const
{
	Q_D(const LoggerEvent);
	return d->message;
}

QDateTime LoggerEvent::dateTime() const
{
	Q_D(const LoggerEvent);
	return d->dateTime;
}

LoggerAppenderList LoggerEvent::appenders() const
{
	Q_D(const LoggerEvent);
	return d->appenders;
}

LoggerFilterList LoggerEvent::filters() const
{
	Q_D(const LoggerEvent);
	return d->filters;
}

} // namespace Qpe

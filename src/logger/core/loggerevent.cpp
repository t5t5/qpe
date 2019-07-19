#include "loggerevent.h"
#include "loggerevent_p.h"

#include <Qpe/Core/Enum>

/*!
 * \class Qpe::LoggerEvent
 * \inmodule logger
 * \brief Класс хранит подробную инфомацию о логгируемом сообщении.
 * \inheaderfile Qpe/Logger/LoggerEvent
 * \ingroup logger
 */

namespace Qpe
{

template <typename TEnum>
inline QString enumToString(TEnum e)
{
	return Flag<TEnum, QString>::valueToKey(e);
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
	, componentName(pn)
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

LoggerEvent::LoggerEvent(
	uint loggerId,
	const QString& componentName,
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
		loggerId, componentName, object, objectName, className,
		eventType, thread, threadName, message, appenders, filters))
{
	QA_D();
	d->q_ptr = this;
}

LoggerEvent::~LoggerEvent()
{
}

/*!
 * \fn uint LoggerEvent::loggerId() const
 * Вернуть идентификатор logger'а.
 */
uint LoggerEvent::loggerId() const
{
	QA_D();
	return d->loggerId;
}

/*!
 * \fn uint LoggerEvent::eventId() const
 * Вернуть идентификатор события.
 */
uint LoggerEvent::eventId() const
{
	QA_D();
	if (d->eventIdEmpty) {
		d->eventId = d->newEventId();
		d->eventIdEmpty = false;
	}
	return d->eventId;
}

/*!
 * \fn QString LoggerEvent::componentName() const
 * Вернуть имя компонента.
 */
QString LoggerEvent::componentName() const
{
	QA_D();
	return d->componentName;
}

/*!
 * \fn QObject* LoggerEvent::object() const
 * Вернуть адрес объекта.
 *
 * \note Содержимое объекта использовать нельзя, т.к. на момент использования
 * данного события, объект может уже не существовать.
 */
QObject* LoggerEvent::object() const
{
	QA_D();
	return d->object;
}

/*!
 * \fn QString LoggerEvent::objectName() const
 * Вернуть имя объекта.
 */
QString LoggerEvent::objectName() const
{
	QA_D();
	return d->objectName;
}

/*!
 * \fn QString LoggerEvent::className() const
 * Вернуть имя класса.
 */
QString LoggerEvent::className() const
{
	QA_D();
	return d->className;
}

/*!
 * \fn EventType LoggerEvent::eventType() const
 * Вернуть тип события.
 */
EventType LoggerEvent::eventType() const
{
	QA_D();
	return d->eventType;
}

/*!
 * \fn QString LoggerEvent::eventTypeName() const
 * Вернуть имя типа события.
 */
QString LoggerEvent::eventTypeName() const
{
	QA_D();
	return d->eventTypeName;
}

/*!
 * \fn QThread* LoggerEvent::thread() const
 * Вернуть адрес объекта потока.
 *
 * \note Содержимое объекта использовать нельзя, т.к. на момент использования
 * данного события, объект может уже не существовать.
 */
QThread* LoggerEvent::thread() const
{
	QA_D();
	return d->thread;
}

/*!
 * \fn QString LoggerEvent::threadName() const
 * Вернуть имя потока.
 */
QString LoggerEvent::threadName() const
{
	QA_D();
	return d->threadName;
}

/*!
 * \fn QString LoggerEvent::message() const
 * Вернуть сообщение.
 */
QString LoggerEvent::message() const
{
	QA_D();
	return d->message;
}

/*!
 * \fn QDateTime LoggerEvent::dateTime() const
 * Вернуть время формирования события.
 */
QDateTime LoggerEvent::dateTime() const
{
	QA_D();
	return d->dateTime;
}

/*!
 * \fn LoggerAppenderList LoggerEvent::appenders() const
 * Вернуть список appender'ов.
 */
LoggerAppenderList LoggerEvent::appenders() const
{
	QA_D();
	return d->appenders;
}

/*!
 * \fn LoggerFilterList LoggerEvent::filters() const
 * Вернуть список фильтров.
 */
LoggerFilterList LoggerEvent::filters() const
{
	QA_D();
	return d->filters;
}

} // namespace Qpe

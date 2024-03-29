#ifndef CORE_LOGGEREVENT_P_H
#define CORE_LOGGEREVENT_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <QDateTime>

#include <Qpe/Logger/LoggerAppender>
#include <Qpe/Logger/LoggerFilter>
#include <Qpe/Logger/EventType>

namespace Qpe
{

class LoggerEvent;
class LoggerEventPrivate
{
	QPE_DECLARE_PUBLIC(LoggerEvent)
protected:
	LoggerEvent* q_ptr;
public:
	LoggerEventPrivate(
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
		const LoggerFilterList& filters);
	~LoggerEventPrivate();

	mutable bool eventIdEmpty;
	mutable uint eventId;
	uint loggerId;
	QString componentName;
	QObject* object;
	QString objectName;
	QString className;
	EventType eventType;
	QString eventTypeName;
	QThread* thread;
	QString threadName;
	QString message;
	QDateTime dateTime;

	LoggerAppenderList appenders;
	LoggerFilterList filters;

	inline static uint newEventId();
};

} // namespace Qpe

#endif // Q_QDOC

#endif // CORE_LOGGEREVENT_P_H

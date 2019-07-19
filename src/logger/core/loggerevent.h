#ifndef CORE_LOGGEREVENT_H
#define CORE_LOGGEREVENT_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QDateTime>

#include <Qpe/Logger/LoggerAppender>
#include <Qpe/Logger/LoggerFilter>
#include <Qpe/Logger/EventType>

class QThread;

namespace Qpe
{

class LoggerEventPrivate;
class QPE_LOGGER_EXPORT LoggerEvent
{
	QPE_DECLARE_PRIVATE(LoggerEvent)
protected:
	QScopedPointer<LoggerEventPrivate> d_ptr;
public:
	LoggerEvent(
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
	~LoggerEvent();

	uint loggerId() const;
	uint eventId() const;
	QString componentName() const;
	QObject* object() const;
	QString objectName() const;
	QString className() const;
	EventType eventType() const;
	QString eventTypeName() const;
	QThread* thread() const;
	QString threadName() const;
	QString message() const;
	QDateTime dateTime() const;

	LoggerAppenderList appenders() const;
	LoggerFilterList filters() const;
private:
	LoggerEvent(const LoggerEvent&);
	LoggerEvent& operator=(const LoggerEvent&);
};

} // namespace Qpe

#endif // CORE_LOGGEREVENT_H

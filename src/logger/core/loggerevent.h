#ifndef CORE_LOGGEREVENT_H
#define CORE_LOGGEREVENT_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QDateTime>

#include "eventtype.h"
#include "loggerappender.h"
#include "loggerfilter.h"

class QThread;

namespace Qpe
{

class LoggerEventPrivate;
class LoggerEvent
{
	Q_DECLARE_PRIVATE(LoggerEvent)
protected:
	QScopedPointer<LoggerEventPrivate> d_ptr;
public:
	LoggerEvent(
		int loggerId,
		const QString& pluginName,
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
	QString pluginName() const;
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

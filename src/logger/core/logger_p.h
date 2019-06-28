#ifndef CORE_LOGGER_P_H
#define CORE_LOGGER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QObject>
#include <QString>

#include "eventtype.h"
#include "loggerappender.h"
#include "loggerfilter.h"

namespace Qpe
{

class Logger;
class LoggerPrivate
{
	QPE_DECLARE_PUBLIC(Logger)
protected:
	Logger* q_ptr;
public:
	LoggerPrivate();
	~LoggerPrivate();

	void initialize();

	void write(EventType eventType, const QString& message) const;
private:
	inline static uint newLoggerId();

	void updateConfig();

	uint loggerId;

	QObject* object;
	QString objectName;
	QString pluginName;
	QString className;
	QThread* thread;
	QString threadName;

	LoggerAppenderList appenders;
	LoggerFilterList filters;
};

} // namespace Qpe

#endif // CORE_LOGGER_P_H
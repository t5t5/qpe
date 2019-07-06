#ifndef APPENDERS_LOGGERAPPENDER_H
#define APPENDERS_LOGGERAPPENDER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QSharedPointer>
#include <QList>

#include <functional>

namespace Qpe
{

class LoggerEvent;
class LoggerAppender
{
public:
	LoggerAppender() { }
	virtual ~LoggerAppender() { }

	virtual bool initialize(const QVariantMap& properties) = 0;
	virtual void append(const LoggerEvent* loggerEvent) = 0;
private:
	LoggerAppender(const LoggerAppender&);
	LoggerAppender& operator=(const LoggerAppender&);
};

typedef QSharedPointer<LoggerAppender> LoggerAppenderPointer;
typedef QList<LoggerAppenderPointer> LoggerAppenderList;

typedef std::function<LoggerAppenderPointer (const QVariantMap&)> LoggerAppenderCreator;

} // namespace Qpe

#endif // APPENDERS_LOGGERAPPENDER_H

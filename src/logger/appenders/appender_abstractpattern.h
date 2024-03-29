#ifndef APPENDERS_APPENDER_ABSTRACTPATTERN_H
#define APPENDERS_APPENDER_ABSTRACTPATTERN_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>

#include <Qpe/Qpe>
#include <Qpe/Logger/LoggerAppender>

namespace Qpe
{

class AbstractPatternLoggerAppenderPrivate;
class AbstractPatternLoggerAppender : public LoggerAppender
{
	QPE_DECLARE_PRIVATE(AbstractPatternLoggerAppender)
protected:
	QScopedPointer<AbstractPatternLoggerAppenderPrivate> d_ptr;
	AbstractPatternLoggerAppender(AbstractPatternLoggerAppenderPrivate* dd);
public:
	AbstractPatternLoggerAppender();
	virtual ~AbstractPatternLoggerAppender();

	// LoggerAppender interface
	virtual bool initialize(const QVariantMap& properties);
	virtual void append(const LoggerEvent* loggerEvent);
protected:
	virtual void write(const LoggerEvent* loggerEvent, const QString& message) = 0;
};

} // namespace Qpe

#endif // APPENDERS_APPENDER_ABSTRACTPATTERN_H

#ifndef APPENDERS_APPENDER_FILE_H
#define APPENDERS_APPENDER_FILE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>

#include <Qpe/Qpe>
#include <Qpe/Logger/AbstractPatternLoggerAppender>

namespace Qpe
{

class FileLoggerAppenderPrivate;
class FileLoggerAppender : public AbstractPatternLoggerAppender
{
	QPE_DECLARE_PRIVATE(FileLoggerAppender)
protected:
	FileLoggerAppender(FileLoggerAppenderPrivate* dd);
public:
	FileLoggerAppender();
	virtual ~FileLoggerAppender();

	// AbstractPatternLoggerAppender interface
	virtual bool initialize(const QVariantMap& properties);
protected:
	virtual void write(const LoggerEvent* loggerEvent, const QString& message);
};

} // namespace Qpe

#endif // APPENDERS_APPENDER_FILE_H

#ifndef QPE_APPENDERS_APPENDER_FILE_P_H
#define QPE_APPENDERS_APPENDER_FILE_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Qpe/Qpe>
#include <Qpe/Logger/Private/abstractpatternloggerappender_p.h>

namespace Qpe
{

namespace LoggerPrivate
{

class FileHelper;

} // namespace LoggerPrivate

class FileLoggerAppenderPrivate : public AbstractPatternLoggerAppenderPrivate
{
	QPE_DECLARE_PUBLIC(FileLoggerAppender)
public:
	FileLoggerAppenderPrivate();
	virtual ~FileLoggerAppenderPrivate();

	QString parseFileName(const QVariantMap& properties);

	bool initializeFile(const QVariantMap& properties);
	void write(const LoggerEvent* loggerEvent, const QString& text);
private:
	QScopedPointer<LoggerPrivate::FileHelper> fileHelper;

};

} // namespace Qpe

#endif // QPE_APPENDERS_APPENDER_FILE_P_H

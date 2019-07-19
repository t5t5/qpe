#ifndef APPENDERS_APPENDER_FILE_P_H
#define APPENDERS_APPENDER_FILE_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <Qpe/Qpe>
#include <Qpe/Logger/Private/abstractpatternloggerappender_p.h>

namespace Qpe
{

namespace PrivateLogger
{

class FileHelper;

} // namespace PrivateLogger

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
	QScopedPointer<PrivateLogger::FileHelper> fileHelper;

};

} // namespace Qpe

#endif // Q_QDOC

#endif // APPENDERS_APPENDER_FILE_P_H

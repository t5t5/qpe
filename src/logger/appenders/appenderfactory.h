#ifndef APPENDER_APPENDERFACTORY_H
#define APPENDER_APPENDERFACTORY_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <functional>

#include <QSharedPointer>
#include <QHash>
#include <QReadWriteLock>

namespace Qpe
{

class LoggerAppender;
typedef QSharedPointer<LoggerAppender> LoggerAppenderPointer;
typedef std::function<LoggerAppenderPointer (const QVariantMap&)> LoggerAppenderCreator;

class LoggerAppenderFactory
{
public:
	LoggerAppenderFactory() = default;
	~LoggerAppenderFactory() = default;

	LoggerAppenderPointer create(const QVariantMap& properties) const;

	void registerAppender(const QString& appenderType, LoggerAppenderCreator&& creator);
	void unregisterAppender(const QString& appenderType);
private:
	mutable QReadWriteLock lock;
	QHash<QString, LoggerAppenderCreator> appenderCreators;
};

} // namespace Qpe

#endif // APPENDER_APPENDERFACTORY_H

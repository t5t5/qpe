#ifndef CORE_LOGGER_H
#define CORE_LOGGER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <functional>

#include <QScopedPointer>
#include <QVariant>
#include <QObject>

#include <Qpe/Qpe>

#include <Qpe/Logger/EventType>

namespace Qpe
{

class LoggerAppender;
typedef QSharedPointer<LoggerAppender> LoggerAppenderPointer;
typedef std::function<LoggerAppenderPointer (const QVariantMap&)> LoggerAppenderCreator;

class LoggerFilter;
typedef QSharedPointer<LoggerFilter> LoggerFilterPointer;
typedef std::function<LoggerFilterPointer (const QVariantMap&)> LoggerFilterCreator;

class LoggerPrivate;
class QPE_LOGGER_EXPORT Logger : public QObject
{
	Q_OBJECT
	QPE_DECLARE_PRIVATE(Logger)
protected:
	QScopedPointer<LoggerPrivate> d_ptr;
public:
	Logger(QObject* parent = nullptr);
	Logger(const QString& pluginName, QObject* o, QObject* parent = nullptr);
	Logger(const QString& pluginName, const QString& className, QObject* parent = nullptr);
	~Logger();

	void initialize(const QString& pluginName, QObject* o);
	void initialize(const QString& pluginName, const QString& className);

	void write(EventType eventType, const QString& s) const;
public slots:
	void fatal(const QString& s) const;
	void error(const QString& s) const;
	void warn(const QString& s) const;
	void info(const QString& s) const;
	void debug(const QString& s) const;
	void trace(const QString& s) const;

public:
	static void setApplicationDirPath(const QString& path);
	static void setApplicationDataPath(const QString& path);
	static void setApplicationLocalPath(const QString& path);

	static void registerAppenderType(
		const QString& appenderType, LoggerAppenderCreator&& creator);
	static void registerFilterType(
		const QString& filterType, LoggerFilterCreator&& creator);
	static void unregisterAppenderType(const QString& appenderType);
	static void unregisterFilterType(const QString& filterType);

	static QString registerSettings(
		const QString& fileName, const char* codecNames = nullptr);
	static QString registerSettings(
		const QString& settingsName, const QVariantMap& properties);
	static void unregisterSettings(const QString& settingsName);
};

} // namespace Qpe

#endif // CORE_LOGGER_H

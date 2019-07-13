#ifndef CORE_LOGGERCONTROLLER_H
#define CORE_LOGGERCONTROLLER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QStringList>

#include <Qpe/Qpe>

#include <Qpe/Logger/LoggerAppender>
#include <Qpe/Logger/LoggerFilter>

namespace Qpe
{

class LoggerEvent;

namespace Private
{

class LoggerControllerPrivate;
class LoggerController : public QObject
{
	Q_OBJECT
	QPE_DECLARE_PRIVATE(LoggerController)
protected:
	QScopedPointer<LoggerControllerPrivate> d_ptr;
public:
	LoggerController();
	~LoggerController();

	static LoggerController& instance();

	void registerAppenderType(const QString& appenderType, LoggerAppenderCreator&& creator);
	void registerFilterType(const QString& filterType, LoggerFilterCreator&& creator);
	void unregisterAppenderType(const QString& appenderType);
	void unregisterFilterType(const QString& filterType);

	QString registerSettings(const QString& fileName, const char* codecName = nullptr);
	QString registerSettings(const QString& name, const QVariantMap& properties);
	void unregisterSettings(const QString& settingsName);

	void config(const QStringList& configNames,
		LoggerAppenderList* appenders, LoggerFilterList* filters);

	void appendEvent(const LoggerEvent* loggerEvent);
signals:
	void configUpdated();
};

} // namespace Private

} // namespace Qpe

#endif // CORE_LOGGERCONTROLLER_H

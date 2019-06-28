#ifndef CORE_LOGGERCONTROLLER_H
#define CORE_LOGGERCONTROLLER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QStringList>

#include <Qpe/Qpe>
//#include <QpeCore/Singleton> // TODO: remove

#include "loggerappender.h"
#include "loggerfilter.h"

namespace Qpe
{

class LoggerEvent;

namespace Private
{

class LoggerControllerPrivate;
class LoggerController : public QObject
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(LoggerController)
protected:
	QScopedPointer<LoggerControllerPrivate> d_ptr;
public:
	LoggerController();
	~LoggerController();

	static LoggerController& instance();

	void setApplicationDirPath(const QString& path);
	void setApplicationDataPath(const QString& path);
	void setApplicationLocalPath(const QString& path);

	void registerAppenderType(
		const QString& appenderType, LoggerAppenderCreator creator);
	void registerFilterType(
		const QString& filterType, LoggerFilterCreator creator);
	void unregisterAppenderType(const QString& appenderType);
	void unregisterFilterType(const QString& filterType);

	QString registerSettings(const QString& fileName, const char* codecName = nullptr);
	QString registerSettings(
		const QString& configName,
		const QMap<QString, QVariantMap>& appenders,
		const QMap<QString, QVariantMap>& filters,
		const QMap<QString, QVariantMap>& cleaners);
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

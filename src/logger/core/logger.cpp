#include "logger.h"
#include "logger_p.h"

#include <QThread>

#include "loggercontroller.h"
#include "loggerappender.h"
#include "loggerfilter.h"
#include "loggerevent.h"

namespace Qpe
{

LoggerPrivate::LoggerPrivate()
	: q_ptr(nullptr)
	, loggerId(newLoggerId())
{
}

LoggerPrivate::~LoggerPrivate()
{
}

void LoggerPrivate::initialize()
{
	Q_Q(Logger);
	QObject::connect(
		&Private::LoggerController::instance(), &Private::LoggerController::configUpdated,
		q, [this] () { updateConfig(); }, Qt::QueuedConnection);
	updateConfig();
}

void LoggerPrivate::write(EventType eventType, const QString& message) const
{
	if (appenders.isEmpty()) { return; }

	LoggerEvent* loggerEvent =
		new LoggerEvent(
			loggerId,
			pluginName,
			object,
			objectName,
			className,
			eventType,
			thread,
			threadName,
			message,
			appenders,
			filters);
	Private::LoggerController::instance().appendEvent(loggerEvent);
}

uint LoggerPrivate::newLoggerId()
{
	static QAtomicInteger<uint> loggerId(0);
	return loggerId.fetchAndAddOrdered(1);
}

void LoggerPrivate::updateConfig()
{
	QStringList configNames;
	configNames.append(QString("%1.%2").arg(pluginName, className));
	configNames.append(pluginName);
	configNames.append("root");
	Private::LoggerController::instance().config(
		configNames, &appenders, &filters);
}

// ---------------------------------------------------------------------------

Logger::Logger(QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
}

Logger::Logger(const QString& pluginName, QObject* o, QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
	initialize(pluginName, o);
}

Logger::Logger(const QString& pluginName, const QString& className, QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
	initialize(pluginName, className);
}

Logger::~Logger()
{
}

void Logger::initialize(const QString& pluginName, QObject* o)
{
	Q_ASSERT(o);
	Q_D(Logger);
	if (d->q_ptr) { return; }

	d->q_ptr = this;

	d->pluginName = pluginName;

	d->object = o;
	d->className = o->metaObject()->className();
	d->objectName = o->objectName();

	d->thread = o->thread();
	d->threadName = o->thread()->objectName();

	d->initialize();
}

void Logger::initialize(const QString& pluginName, const QString& className)
{
	Q_D(Logger);
	if (d->q_ptr) { return; }

	d->q_ptr = this;

	d->pluginName = pluginName;

	d->object = NULL;
	d->className = className;

	d->thread = NULL;

	d->initialize();
}

void Logger::write(EventType eventType, const QString& s) const
{
	Q_D(const Logger);
	d->write(eventType, s);
}

void Logger::fatal(const QString& s) const
{
	Q_D(const Logger);
	d->write(FATAL, s);
}

void Logger::error(const QString& s) const
{
	Q_D(const Logger);
	d->write(ERROR, s);
}

void Logger::warn(const QString& s) const
{

	Q_D(const Logger);
	d->write(WARN, s);
}

void Logger::info(const QString& s) const
{
	Q_D(const Logger);
	d->write(INFO, s);
}

void Logger::debug(const QString& s) const
{
	Q_D(const Logger);
	d->write(DEBUG, s);

}

void Logger::trace(const QString& s) const
{
	Q_D(const Logger);
	d->write(TRACE, s);
}

void Logger::registerAppenderType(
	const QString& appenderType, LoggerAppenderCreator creator)
{
	Private::LoggerController::instance().registerAppenderType(appenderType, creator);
}

void Logger::registerFilterType(
	const QString& filterType, LoggerFilterCreator creator)
{
	Private::LoggerController::instance().registerFilterType(filterType, creator);
}

void Logger::unregisterAppenderType(const QString& appenderType)
{
	Private::LoggerController::instance().unregisterAppenderType(appenderType);
}

void Logger::unregisterFilterType(const QString& filterType)
{
	Private::LoggerController::instance().unregisterFilterType(filterType);
}

QString Logger::registerSettings(
	const QString& fileName, const char* codecNames /* = nullptr */)
{
	return Private::LoggerController::instance()
		.registerSettings(fileName, codecNames);
}

QString Logger::registerSettings(
	const QString& configName,
	const QMap<QString, QVariantMap>& appenders,
	const QMap<QString, QVariantMap>& filters /* = QMap<QString, QVariantMap>() */,
	const QMap<QString, QVariantMap>& cleaners /* = QMap<QString, QVariantMap>() */)
{
	return Private::LoggerController::instance()
		.registerSettings(configName, appenders, filters, cleaners);
}

void Logger::unregisterSettings(const QString& settingsName)
{
	return Private::LoggerController::instance().unregisterSettings(settingsName);
}

void Logger::setApplicationDirPath(const QString& path)
{
	Private::LoggerController::instance().setApplicationDirPath(path);
}

void Logger::setApplicationDataPath(const QString& path)
{
	Private::LoggerController::instance().setApplicationDataPath(path);
}

void Logger::setApplicationLocalPath(const QString& path)
{
	Private::LoggerController::instance().setApplicationLocalPath(path);
}

} // namespace Qpe

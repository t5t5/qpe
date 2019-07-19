#include "logger.h"
#include "logger_p.h"

#include <QThread>

#include <Qpe/Logger/LoggerEvent>

#include "loggercontroller.h"

/*!
 * \class Qpe::Logger
 * \inmodule logger
 * \brief Класс журналирования.
 * \inheaderfile Qpe/Logger/Logger
 * \ingroup logger
 */

namespace Qpe
{

using namespace PrivateLogger;

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
	QA_Q();
	QObject::connect(
		&LoggerController::instance(), &LoggerController::configUpdated,
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
	LoggerController::instance().appendEvent(loggerEvent);
}

uint LoggerPrivate::newLoggerId()
{
	static QAtomicInteger<uint> loggerId(0);
	return loggerId.fetchAndAddOrdered(1);
}

void LoggerPrivate::updateConfig()
{
	QStringList configNames;
	configNames.append(QString("%1#%2").arg(pluginName, className));
	configNames.append(pluginName);
	configNames.append("root");
	LoggerController::instance().config(configNames, &appenders, &filters);
}

// ---------------------------------------------------------------------------

/*!
 * \fn Logger::Logger(QObject* parent = nullptr)
 * Конструктор. Создать неинициализированный logger.
 * \a parent - родительский QObject
 *
 * \note После создания обязательно необходимо вызвать Logger::initialize()
 */
Logger::Logger(QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
}

/*!
 * \fn Logger::Logger(const QString& pluginName, QObject* o, QObject* parent = nullptr)
 * Конструктор. Создать и инициализировать logger.
 * \a pluginName - имя компонента, \a o - объект действия которого будут логироваться;
 * \a parent - родительский QObject
 */
Logger::Logger(const QString& pluginName, QObject* o, QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
	initialize(pluginName, o);
}

/*!
 * \fn Logger::Logger(const QString& pluginName, const QString& className, QObject* parent = nullptr)
 * Конструктор. Создать и инициализировать logger.
 * \a pluginName - имя компонента, \a className - имя класса действия которого будут логироваться;
 * \a parent - родительский QObject
 */
Logger::Logger(const QString& pluginName, const QString& className, QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new LoggerPrivate())
{
	initialize(pluginName, className);
}

Logger::~Logger()
{
}

/*!
 * \fn void Logger::initialize(const QString& pluginName, QObject* o)
 * Настроить logger.
 * \a pluginName - имя компонента, \a o - объект действия которого будут логироваться.
 */
void Logger::initialize(const QString& pluginName, QObject* o)
{
	Q_ASSERT(o);
	QA_D();
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

/*!
 * \fn void Logger::initialize(const QString& pluginName, const QString& className)
 * Настроить logger.
 * \a pluginName - имя компонента, \a className - имя класса действия которого будут логироваться.
 */
void Logger::initialize(const QString& pluginName, const QString& className)
{
	QA_D();
	if (d->q_ptr) { return; }

	d->q_ptr = this;

	d->pluginName = pluginName;

	d->object = nullptr;
	d->className = className;

	d->thread = nullptr;

	d->initialize();
}

/*!
 * \fn void Logger::write(EventType eventType, const QString& s) const
 * Вывести сообщение \a s типа \a eventType в лог.
 */
void Logger::write(EventType eventType, const QString& s) const
{
	QA_D();
	d->write(eventType, s);
}

/*!
 * \fn void Logger::fatal(const QString& s) const
 * Вывести сообщение \a s о фатальной ошибке в лог.
 */
void Logger::fatal(const QString& s) const
{
	QA_D();
	d->write(FATAL, s);
}

/*!
 * \fn void Logger::error(const QString& s) const
 * Вывести сообщение \a s об ошибке в лог.
 */
void Logger::error(const QString& s) const
{
	QA_D();
	d->write(ERROR, s);
}

/*!
 * \fn void Logger::warn(const QString& s) const
 * Вывести предупреждение \a s в лог.
 */
void Logger::warn(const QString& s) const
{

	QA_D();
	d->write(WARN, s);
}

/*!
 * \fn void Logger::info(const QString& s) const
 * Вывести сообщение \a s в лог.
 */
void Logger::info(const QString& s) const
{
	QA_D();
	d->write(INFO, s);
}

/*!
 * \fn void Logger::debug(const QString& s) const
 * Вывести отладочное сообщение \a s в лог.
 */
void Logger::debug(const QString& s) const
{
	QA_D();
	d->write(DEBUG, s);

}

/*!
 * \fn void Logger::trace(const QString& s) const
 * Вывести трассировочное сообщение \a s в лог.
 */
void Logger::trace(const QString& s) const
{
	QA_D();
	d->write(TRACE, s);
}

/*!
 * \fn void Logger::registerAppenderType(const QString& appenderType, LoggerAppenderCreator&& creator)
 * Зарегистрировать функцию создания \a creator appender'а с типом \a appenderType.
 */
void Logger::registerAppenderType(
	const QString& appenderType, LoggerAppenderCreator&& creator)
{
	LoggerController::instance().registerAppenderType(
		appenderType, std::forward<LoggerAppenderCreator>(creator));
}

/*!
 * \fn void Logger::registerFilterType(const QString& filterType, LoggerFilterCreator&& creator)
 * Зарегистрировать функцию создания \a creator фильтра сообщений с типом \a filterType.
 */
void Logger::registerFilterType(
	const QString& filterType, LoggerFilterCreator&& creator)
{
	LoggerController::instance().registerFilterType(
		filterType, std::forward<LoggerFilterCreator>(creator));
}

/*!
 * \fn void Logger::unregisterAppenderType(const QString& appenderType)
 * Убрать регистрацию appender'a с типом \a appenderType.
 */
void Logger::unregisterAppenderType(const QString& appenderType)
{
	LoggerController::instance().unregisterAppenderType(appenderType);
}

/*!
 * \fn void Logger::unregisterFilterType(const QString& filterType)
 * Убрать регистрацию фильтра собщений с типом \a filterType.
 */
void Logger::unregisterFilterType(const QString& filterType)
{
	LoggerController::instance().unregisterFilterType(filterType);
}

/*!
 * \fn QString Logger::registerSettings(const QString& fileName, const char* codecNames = nullptr)
 * Внести настройки logger'а из файла \a fileName, для файла использовать кодек \a codecNames.
 * Вернуть идентификатор ресурса, по которому можно будет вызвать Logger::unregisterSettings.
 * Если возвращенная строка пуста, настройки не внесены.
 *
 * \note Для чтения настроек испльзуется QSettings.
 * \note Все существующие logger'ы получат уведомление об изменении конфигурации.
 */
QString Logger::registerSettings(
	const QString& fileName, const char* codecNames /* = nullptr */)
{
	return LoggerController::instance().registerSettings(fileName, codecNames);
}

/*!
 * \fn QString Logger::registerSettings(const QString& settingsName, const QVariantMap& properties)
 * Внести настройки logger'а из карты \a properties, \a settingsName - имя настроек.
 *
 * Вернуть идентификатор ресурса, по которому можно будет вызвать Logger::unregisterSettings.
 * Если возвращенная строка пуста, настройки не внесены.
 *
 * \note Все существующие logger'ы получат уведомление об изменении конфигурации.
 */
QString Logger::registerSettings(
	const QString& settingsName, const QVariantMap& properties)
{
	return LoggerController::instance().registerSettings(settingsName, properties);
}

/*!
 * \fn void Logger::unregisterSettings(const QString& settingsName)
 * Убрать регистрацию настроек logger'а по имени \a settingsName.
 *
 * \note Все существующие logger'ы получат уведомление об изменении конфигурации.
 */
void Logger::unregisterSettings(const QString& settingsName)
{
	return LoggerController::instance().unregisterSettings(settingsName);
}

} // namespace Qpe

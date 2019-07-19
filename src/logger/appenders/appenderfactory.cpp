#include "appenderfactory.h"

#include <QVariant>

#include "appender_file.h"

/*!
 * \class Qpe::LoggerAppenderFactory
 * \inmodule logger
 * \brief Фабрика appender'ов.
 * \inheaderfile
 * \ingroup logger
 */

namespace Qpe
{

static const QLatin1String PROPERTY__TYPE("type");

static const QLatin1String APPENDER__FILE_APPENDER("FileAppender");

/*!
 * \fn LoggerAppenderPointer LoggerAppenderFactory::create(const QVariantMap& properties) const
 * Создать appender, настроить его свойствами \a properties.
 */
LoggerAppenderPointer LoggerAppenderFactory::create(const QVariantMap& properties) const
{
	auto it = properties.find(PROPERTY__TYPE);
	if (it == properties.end()) { return LoggerAppenderPointer(); }

	LoggerAppenderPointer appender;

	QString type = it->toString();
	if (type == APPENDER__FILE_APPENDER) {
		appender.reset(new FileLoggerAppender());
	} else {
		QReadLocker locker(&lock);
		auto it = appenderCreators.find(type);
		if (it != appenderCreators.end()) {
			appender = (*it)(properties);
		}
	}
	if (appender && !appender->initialize(properties)) {
		appender.clear();
	}

	return appender;
}

/*!
 * \fn void LoggerAppenderFactory::registerAppender(
 *          const QString& appenderType, LoggerAppenderCreator&& creator)
 * Зарегистрировать функцию создания \a creator appender'а с типом \a appenderType.
 */
void LoggerAppenderFactory::registerAppender(
	const QString& appenderType, LoggerAppenderCreator&& creator)
{
	if (appenderType == APPENDER__FILE_APPENDER) { return; }

	QWriteLocker locker(&lock);
	appenderCreators.insert(appenderType, creator);
}

/*!
 * \fn void LoggerAppenderFactory::unregisterAppender(const QString& appenderType)
 * Убрать регистрацию appender'a с типом \a appenderType.
 */
void LoggerAppenderFactory::unregisterAppender(const QString& appenderType)
{
	QWriteLocker locker(&lock);
	appenderCreators.remove(appenderType);
}

} // namespace Qpe

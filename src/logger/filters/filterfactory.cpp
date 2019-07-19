#include "filterfactory.h"

#include <QVariant>

#include "filter_classname.h"
#include "filter_eventtype.h"

/*!
 * \class Qpe::LoggerFilterFactory
 * \inmodule logger
 * \brief Фабрика фильтров
 * \inheaderfile
 * \ingroup logger
 */

namespace Qpe
{

static const QLatin1String PROPERTY__TYPE("type");

static const QLatin1String FILTER__EVENT_TYPE("EventTypeFilter");
static const QLatin1String FILTER__CLASS_NAME("ClassNameFilter");

/*!
 * \fn LoggerFilterPointer LoggerFilterFactory::create(const QVariantMap& properties) const
 * Создать фильтр, настроить его свойствами \a properties.
 */
LoggerFilterPointer LoggerFilterFactory::create(const QVariantMap& properties) const
{
	auto it = properties.find(PROPERTY__TYPE);
	if (it == properties.end()) { return LoggerFilterPointer(); }

	LoggerFilterPointer filter;

	QString type = it->toString();
	if (type == FILTER__EVENT_TYPE) {
		filter.reset(new EventTypeLoggerFilter());
	} else
	if (type == FILTER__CLASS_NAME) {
		filter.reset(new ClassNameLoggerFilter());
	} else {
		QReadLocker locker(&lock);
		auto it = filterCreators.find(type);
		if (it != filterCreators.end()) {
			filter = (*it)(properties);
		}
	}
	if (filter && !filter->initialize(properties)) {
		filter.clear();
	}

	return filter;
}

/*!
 * \fn void LoggerFilterFactory::registerFilter(
 *          const QString& filterType, LoggerFilterCreator&& creator)
 * Зарегистрировать функцию создания \a creator фильтра сообщений с типом \a filterType.
 */
void LoggerFilterFactory::registerFilter(
	const QString& filterType, LoggerFilterCreator&& creator)
{
	if (filterType == FILTER__EVENT_TYPE) { return; }
	if (filterType == FILTER__CLASS_NAME) { return; }

	QWriteLocker locker(&lock);
	filterCreators.insert(filterType, creator);
}

/*!
 * \fn void LoggerFilterFactory::unregisterFilter(const QString& filterType)
 * Убрать регистрацию фильтра собщений с типом \a filterType.
 */
void LoggerFilterFactory::unregisterFilter(const QString& filterType)
{
	QWriteLocker locker(&lock);
	filterCreators.remove(filterType);
}

} // namespace Qpe

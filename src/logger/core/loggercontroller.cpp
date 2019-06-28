#include "loggercontroller.h"
#include "loggercontroller_p.h"

#include <QCoreApplication>
#include <QStandardPaths>
#include <QDateTime>
#include <QSettings>
#include <QFile>

#include "loggerevent.h"

#include "../appenders/appender_file.h"
#include "../filters/filter_classname.h"
#include "../filters/filter_eventtype.h"
#include "../cleaners/cleaner_date.h"

//#include <QpeCore/Algorithm>	// TODO: <QpeCore/Algorithm>

namespace Qpe {

namespace Private {

LoggerCleanerContainer::LoggerCleanerContainer()
	: QObject()
{
	registerCleanerType("DateCleaner",
		[] (const QVariantMap& properties) -> LoggerCleanerPointer
		{
			LoggerCleanerPointer cleaner(new DateLoggerCleaner());
			return cleaner->initialize(properties) ? cleaner : LoggerCleanerPointer();
		});;
}

LoggerCleanerContainer::~LoggerCleanerContainer()
{
}

void LoggerCleanerContainer::start(
	const QString& cleanerName, const QVariantMap& properties)
{
	if (cleanerName.isEmpty()) { return; }
	LoggerCleanerPointer cleaner = createCleaner(properties);
	if (!cleaner) { return; }
	cleaners.insert(cleanerName, cleaner);
}

void LoggerCleanerContainer::stop(const QString& cleanerName)
{
	if (cleanerName.isEmpty()) { return; }
	cleaners.remove(cleanerName);
}

void LoggerCleanerContainer::registerCleanerType(const QString& cleanerType, LoggerCleanerCreator creator)
{
	QWriteLocker locker(&cleanerFactoryLock);
	cleanerFactory.insert(cleanerType, creator);
}

void LoggerCleanerContainer::unregisterCleanerType(const QString& cleanerType)
{
	QWriteLocker locker(&cleanerFactoryLock);
	cleanerFactory.remove(cleanerType);
}

LoggerCleanerPointer LoggerCleanerContainer::createCleaner(const QVariantMap& p)
{
	if (!p.contains("type")) { return LoggerCleanerPointer(); }
	QString type = p.value("type").toString();
	LoggerCleanerCreator creator;
	{
		QReadLocker locker(&cleanerFactoryLock);
		creator = cleanerFactory.value(type);
	}
	return creator ? creator(p) : LoggerCleanerPointer();
}

// ------------------------------------------------------------------------

static const QLatin1String appender_prefix("appender_");
static const QLatin1String filter_prefix("filter_");
static const QLatin1String cleaner_prefix("cleaner_");
static const QLatin1String appenders_setting("appenders");
static const QLatin1String filter_setting("filters");

class SettingsFileReader
{
public:
	static LoggerSettings read(const QString& fileName, const char* codecName)
	{
		LoggerSettings result;
		QSettings* settings;
		if ((settings = openSettings(fileName, codecName))) {
			result.name = settings->fileName();
			readSettings(settings, &result);
			delete settings;
		}
		return result;
	}
private:
	static QSettings* openSettings(const QString& fileName, const char* codecName)
	{
		if (QFile::exists(fileName)) {
			QSettings* settings = new QSettings(fileName, QSettings::IniFormat);
			if (codecName) {
				settings->setIniCodec(codecName);
			}
			return settings;
		}
		return nullptr;
	}

	static QVariantMap readProperties(QSettings* settings, const QString& group)
	{
		settings->beginGroup(group);
		QStringList propertyNames(settings->childKeys());
		QVariantMap properties;
		auto it = propertyNames.constBegin();
		while (it != propertyNames.constEnd()) {
			const QString& propertyName = *it++;
			properties.insert(propertyName, settings->value(propertyName));
		}
		settings->endGroup();
		return properties;
	}

	static void readSettings(QSettings* settings, LoggerSettings* l)
	{
		QStringList groups = settings->childGroups();
		auto it = groups.constBegin();
		while (it != groups.constEnd()) {
			const QString& group = *it++;
			QVariantMap properties = readProperties(settings, group);
			if (group.startsWith(appender_prefix)) {
				QString appenderName = group.mid(appender_prefix.size());
				l->appenders.insert(appenderName, properties);
			} else
			if (group.startsWith(filter_prefix)) {
				QString filterName = group.mid(filter_prefix.size());
				l->filters.insert(filterName, properties);
			} else
			if (group.startsWith(cleaner_prefix)) {
				QString cleanerName = group.mid(cleaner_prefix.size());
				l->cleaners.insert(cleanerName, properties);
			} else {
				QRegExp emptyFilter("^.+$");
				QString configName = group;
				QStringList appenders =
					properties.value(appenders_setting).toStringList().filter(emptyFilter);
				QStringList filters =
					properties.value(filter_setting).toStringList().filter(emptyFilter);
				l->configs.insert(configName,
					LoggerSettings::AppendersFilters(appenders, filters));
			}
		}
	}
};

// ------------------------------------------------------------------------

LoggerControllerPrivate::LoggerControllerPrivate(QObject* parent /* = NULL */)
	: QObject(parent)
	, startTime(QDateTime::currentDateTime())
{
	applicationDirPath = QCoreApplication::applicationDirPath();
	applicationDataPath =
		QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).at(0);
	applicationLocalPath =
		QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0);

	registerAppenderType("FileAppender",
		[] (const QVariantMap& properties) -> LoggerAppenderPointer
		{
			LoggerAppenderPointer appender(new FileLoggerAppender());
			appender->initialize(properties);
			return appender;
		});

	registerFilterType("EventTypeFilter",
		[] (const QVariantMap& properties) -> LoggerFilterPointer
		{
			LoggerFilterPointer filter(new EventTypeLoggerFilter());
			filter->initialize(properties);
			return filter;
		});
	registerFilterType("ClassNameFilter",
		[] (const QVariantMap& properties) -> LoggerFilterPointer
		{
			LoggerFilterPointer filter(new ClassNameLoggerFilter());
			filter->initialize(properties);
			return filter;
		});

	workThread.setObjectName("LoggerControllerPrivate_Thread");
	this->moveToThread(&workThread);
	workThread.start(QThread::LowPriority);

	cleanerThread.setObjectName("LoggerCleanerContainer_Thread");
	cleaners = QSharedPointer<LoggerCleanerContainer>(
		new LoggerCleanerContainer(), &QObject::deleteLater);
	cleaners->moveToThread(&cleanerThread);
	cleanerThread.start();

	connect(
		this, &LoggerControllerPrivate::aboutCleanerStart,
		cleaners.data(), &LoggerCleanerContainer::start, Qt::QueuedConnection);
	connect(
		this, &LoggerControllerPrivate::aboutCleanerStop,
		cleaners.data(), &LoggerCleanerContainer::stop, Qt::QueuedConnection);

	connect(
		this, &LoggerControllerPrivate::eventAdded,
		this, &LoggerControllerPrivate::processQueues, Qt::QueuedConnection);
}

LoggerControllerPrivate::~LoggerControllerPrivate()
{
	cleanerThread.quit();
	cleanerThread.wait();

	workThread.quit();
	workThread.wait();
}

void LoggerControllerPrivate::appendEvent(const LoggerEvent* loggerEvent)
{
	queueMutex.lock();
	events.enqueue(loggerEvent);
	queueMutex.unlock();
	emit eventAdded();
}

void LoggerControllerPrivate::processQueues()
{
	while (true) {
		const LoggerEvent* loggerEvent;
		{
			QMutexLocker locker(&queueMutex);
			if (events.isEmpty()) { break; }
			loggerEvent = events.dequeue();
		}
		processEvent(loggerEvent);
		delete loggerEvent;
	}
}

void LoggerControllerPrivate::startCleaners(const QMap<QString, QVariantMap>& cleaners)
{
	if (cleaners.isEmpty()) { return; }
//	Qpe::Map::for_each(cleaners,
//	[this] (const QString& name, const QVariantMap& p)
//	{
//		emit aboutCleanerStart(name, insertStandardProperties(p));
//	});

	auto it = cleaners.begin();
	while (it != cleaners.end()) {
		const QString& name = it.key();
		const QVariantMap& p = it.value();
		emit aboutCleanerStart(name, insertStandardProperties(p));
	}
}

void LoggerControllerPrivate::stopCleaners(const QMap<QString, QVariantMap>& cleaners)
{
	if (cleaners.isEmpty()) { return; }
	auto it = cleaners.begin();
	while (it != cleaners.end()) {
		const QString& name = it.key();
		emit aboutCleanerStop(name);
	}
}

void LoggerControllerPrivate::processEvent(const LoggerEvent* loggerEvent)
{
	LoggerAppenderList appenders = loggerEvent->appenders();
	if (appenders.isEmpty()) { return; }

	LoggerFilterList filters = loggerEvent->filters();
	if (!filters.isEmpty()) {
		auto filterIt = filters.constBegin();
		while (filterIt != filters.constEnd()) {
			const LoggerFilterPointer& filter = *filterIt++;
			if (!filter->testEvent(loggerEvent))
				return;
		}
	}

	// если фильтры прошли успешно, идем дальше
	// передать событие всем необходимым appenders
	auto appenderIt = appenders.constBegin();
	while (appenderIt != appenders.constEnd()) {
		const LoggerAppenderPointer& appender = *appenderIt++;
		appender->append(loggerEvent);
	}
}

QVariantMap LoggerControllerPrivate::insertStandardProperties(const QVariantMap& p)
{
	QVariantMap r(p);
	r.insert("controllerCreationTime", startTime);
	{
		QWriteLocker locker(&pathLock);
		r.insert("applicationDirPath", applicationDirPath);
		r.insert("applicationDataPath", applicationDataPath);
		r.insert("applicationLocalPath", applicationLocalPath);
	}
	return r;
}

LoggerAppenderPointer LoggerControllerPrivate::createAppender(
	const QString& appenderName, const QVariantMap& p)
{
	if (!p.contains("type")) { return LoggerAppenderPointer(); }
	QString type = p.value("type").toString();
	QMutexLocker locker(&appenderCreateMutex);
	LoggerAppenderPointer appender = appendersCache.value(appenderName);
	if (appender) { return appender; }
	LoggerAppenderCreator creator = appenderFactory.value(type);
	if (!creator) { return appender; }
	appender = creator(insertStandardProperties(p));
	appendersCache.insert(appenderName, appender);
	return appender;
}

LoggerFilterPointer LoggerControllerPrivate::createFilter(
	const QString& filterName, const QVariantMap& p)
{
	if (!p.contains("type")) { return LoggerFilterPointer(); }
	QString type = p.value("type").toString();
	QMutexLocker locker(&filterCreateMutex);
	LoggerFilterPointer filter = filtersCache.value(filterName);
	if (filter) { return filter; }
	LoggerFilterCreator creator = filterFactory.value(type);
	if (!creator) { return filter; }
	filter = creator(p);
	filtersCache.insert(filterName, filter);
	return filter;
}

void LoggerControllerPrivate::registerAppenderType(
	const QString& appenderType, LoggerAppenderCreator creator)
{
	QMutexLocker locker(&appenderCreateMutex);
	appenderFactory.insert(appenderType, creator);
}

void LoggerControllerPrivate::registerFilterType(
	const QString& filterType, LoggerFilterCreator creator)
{
	QMutexLocker locker(&filterCreateMutex);
	filterFactory.insert(filterType, creator);
}

void LoggerControllerPrivate::unregisterAppenderType(const QString& appenderType)
{
	QMutexLocker locker(&appenderCreateMutex);
	appenderFactory.remove(appenderType);
}

void LoggerControllerPrivate::unregisterFilterType(const QString& filterType)
{
	QMutexLocker locker(&filterCreateMutex);
	filterFactory.remove(filterType);
}

template <typename map, typename iterator>
void calculate(
	const map& newCleaners, const map& oldCleaners,
	iterator b, iterator e, iterator current,
	map& starting, map& stopping)
{
	// temp = oldCleaners ⋃ newCleaners
	// TODO: temp = oldCleaners ⋃ newCleaners
//	auto temp =
//		oldCleaners.isEmpty()
//			? newCleaners
//			: (newCleaners.isEmpty()
//				? oldCleaners
//				: Map::constUnite(oldCleaners, newCleaners));
//	{
//		// temp = (temp \ i[end - 1].cleaners \ .. \ i[current + 1].cleaners)
//		auto it = e;
//		iterator next = current + 1;
//		while ((it != next) && !temp.isEmpty()) {
//			--it;
//			const LoggerSettings& s = *it;
//			Map::subtract(temp, s.cleaners);
//		}
//	}
//	{
//		// starting = (newCleaners ⋂ temp) ⋃ (i[current - 1].cleaners ⋂ temp) ⋃ .. ⋃ (i[begin].cleners ⋂ temp)
//		// stopping = (oldCleaners ⋂ temp) ⋃ (i[current - 1].cleaners ⋂ temp) ⋃ .. ⋃ (i[begin].cleners ⋂ temp)
//		auto startingTemp = temp;
//		auto stoppingTemp = temp;
//		auto it = current + 1;
//		while ((it != b) &&
//			(!startingTemp.isEmpty() || !stoppingTemp.isEmpty()))
//		{
//			--it;
//			const LoggerSettings& ls = *it;
//			if (!startingTemp.isEmpty()) {
//				auto startingIt = startingTemp.begin();
//				while (startingIt != startingTemp.end()) {
//					const QString& name = startingIt.key();
//					QVariantMap value = (it == current)
//						? newCleaners.value(name) : ls.cleaners.value(name);
//					if (!value.isEmpty()) {
//						starting.insert(name, value);
//						startingIt = startingTemp.erase(startingIt);
//					} else {
//						++startingIt;
//					}
//				}
//			}
//			if (!stoppingTemp.isEmpty()) {
//				auto stoppingIt = stoppingTemp.begin();
//				while (stoppingIt != stoppingTemp.end()) {
//					const QString& name = stoppingIt.key();
//					QVariantMap value = (it == current)
//						? oldCleaners.value(name) : ls.cleaners.value(name);
//					if (!value.isEmpty()) {
//						stopping.insert(name, value);
//						stoppingIt = stoppingTemp.erase(stoppingIt);
//					} else {
//						++stoppingIt;
//					}
//				}
//			}
//		}
//	}
}

QString LoggerControllerPrivate::registerSettings(const LoggerSettings& s)
{
	if (s.name.isEmpty()) { return QString(); }

	QWriteLocker locker(&settingsLock);
	QMap<QString, QVariantMap> starting;
	QMap<QString, QVariantMap> stopping;
	if (!settings.isEmpty()) {
		auto begin = settings.begin();
		auto end = settings.end();
		auto it = begin;
		while (it != end) {
			LoggerSettings& current = *it;
			if (current.name == s.name) {
				calculate(
					s.cleaners, current.cleaners,
					begin, end, it,
					starting, stopping);
				current = s;
				goto startAndStop;
			}
			++it;
		}
	}
	settings.append(s);
	calculate(s.cleaners, QMap<QString, QVariantMap>(),
		settings.begin(), settings.end(), settings.end() - 1,
		starting, stopping);
startAndStop:
	stopCleaners(stopping);
	startCleaners(starting);
	return s.name;
}

bool LoggerControllerPrivate::unregisterSettings(const QString& settingsName)
{
	if (settingsName.isEmpty()) { return false; }

	QWriteLocker locker(&settingsLock);
	auto it = settings.begin();
	while (it != settings.end()) {
		LoggerSettings& current = *it;
		if (current.name == settingsName) {
			QMap<QString, QVariantMap> starting;
			QMap<QString, QVariantMap> stopping;
			calculate(
				QMap<QString, QVariantMap>(), current.cleaners,
				settings.begin(), settings.end(), it,
				starting, stopping);
			it = settings.erase(it);
			stopCleaners(stopping);
			startCleaners(starting);
			return true;
		} else {
			++it;
		}
	}
	return false;
}

void LoggerControllerPrivate::config(
	const QStringList& configNames,
	LoggerAppenderList* appenders, LoggerFilterList* filters)
{
	appenders->clear();
	filters->clear();
	QStringList appenderNames;
	QStringList filterNames;
	QReadLocker locker(&settingsLock);
	{
		auto it = settings.constEnd();
		while (it-- != settings.constBegin()) {
			const LoggerSettings& s = *it;
			auto configNamesIt = configNames.constBegin();
			while (configNamesIt != configNames.constEnd()) {
				const QString& configName = *configNamesIt++;
				if (s.configs.contains(configName)) {
					const LoggerSettings::AppendersFilters& af = s.configs[configName];
					appenderNames = af.appenders;
					filterNames = af.filters;
					goto afterLoop;
				}
			}
		}
	}
afterLoop:
	{
		auto it = settings.constEnd();
		while (
			(appenderNames.size() || filterNames.size()) &&
			(it-- != settings.constBegin()))
		{
			const LoggerSettings& s = *it;
			if (!appenderNames.isEmpty()) {
				auto appenderNamesIt = appenderNames.begin();
				while (appenderNamesIt != appenderNames.end()) {
					const QString& appenderName = *appenderNamesIt;
					if (s.appenders.contains(appenderName)) {
						LoggerAppenderPointer p = createAppender(appenderName, s.appenders[appenderName]);
						if (p) { appenders->append(p); }
						appenderNamesIt = appenderNames.erase(appenderNamesIt);
					} else {
						++appenderNamesIt;
					}
				}
			}
			if (!filterNames.isEmpty()) {
				auto filterNamesIt = filterNames.begin();
				while (filterNamesIt != filterNames.end()) {
					const QString& filterName = *filterNamesIt;
					if (s.filters.contains(filterName)) {
						LoggerFilterPointer p = createFilter(filterName, s.filters[filterName]);
						if (p) { filters->append(p); }
						filterNamesIt = filterNames.erase(filterNamesIt);
					} else {
						++filterNamesIt;
					}
				}
			}
		}
	}
}

// ------------------------------------------------------------------------

LoggerController::LoggerController()
	: QObject()
	, d_ptr(new LoggerControllerPrivate())
{
	Q_D(LoggerController);
	d->q_ptr = this;
}

LoggerController::~LoggerController()
{
}

LoggerController& LoggerController::instance()
{
	static LoggerController o;
	return o;
}

void LoggerController::setApplicationDirPath(const QString& path)
{
	Q_D(LoggerController);
	QWriteLocker locker(&d->pathLock);
	d->applicationDirPath = path;
}

void LoggerController::setApplicationDataPath(const QString& path)
{
	Q_D(LoggerController);
	QWriteLocker locker(&d->pathLock);
	d->applicationDataPath = path;
}

void LoggerController::setApplicationLocalPath(const QString& path)
{
	Q_D(LoggerController);
	QWriteLocker locker(&d->pathLock);
	d->applicationLocalPath = path;
}

void LoggerController::registerAppenderType(
	const QString& appenderType, LoggerAppenderCreator creator)
{
	Q_D(LoggerController);
	d->registerAppenderType(appenderType, creator);
	emit configUpdated();
}

void LoggerController::registerFilterType(
	const QString& filterType, LoggerFilterCreator creator)
{
	Q_D(LoggerController);
	d->registerFilterType(filterType, creator);
	emit configUpdated();
}

void LoggerController::unregisterAppenderType(const QString& appenderType)
{
	Q_D(LoggerController);
	d->unregisterAppenderType(appenderType);
	emit configUpdated();
}

void LoggerController::unregisterFilterType(const QString& filterType)
{
	Q_D(LoggerController);
	d->unregisterFilterType(filterType);
	emit configUpdated();
}

QString LoggerController::registerSettings(
	const QString& fileName, const char* codecName /* = nullptr */)
{
	Q_D(LoggerController);
	LoggerSettings s = SettingsFileReader::read(fileName, codecName);
	QString result = d->registerSettings(s);
	if (!result.isEmpty()) {
		emit configUpdated();
	}
	return result;
}

QString LoggerController::registerSettings(const QString& configName,
	const QMap<QString, QVariantMap>& appenders,
	const QMap<QString, QVariantMap>& filters,
	const QMap<QString, QVariantMap>& cleaners)
{
	Q_D(LoggerController);
	LoggerSettings s;
	s.name = configName;
	s.configs.insert(configName,
		LoggerSettings::AppendersFilters(appenders.keys(), filters.keys()));
	s.appenders = appenders;
	s.filters = filters;
	s.cleaners = cleaners;

	QString result = d->registerSettings(s);
	if (!result.isEmpty()) {
		emit configUpdated();
	}
	return result;
}

void LoggerController::unregisterSettings(const QString& settingsName)
{
	Q_D(LoggerController);
	if (d->unregisterSettings(settingsName)) {
		emit configUpdated();
	}
}

void LoggerController::config(const QStringList& configNames,
	LoggerAppenderList* appenders, LoggerFilterList* filters)
{
	Q_D(LoggerController);
	d->config(configNames, appenders, filters);
}

void LoggerController::appendEvent(const LoggerEvent* loggerEvent)
{
	Q_D(LoggerController);
	d->appendEvent(loggerEvent);
}

} // namespace Private

} // namespace Qpe

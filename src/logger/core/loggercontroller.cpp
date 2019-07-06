#include "loggercontroller.h"
#include "loggercontroller_p.h"

#include <QCoreApplication>
#include <QStandardPaths>
#include <QDateTime>
#include <QRegularExpression>
#include <QSet>

#include "loggerevent.h"

namespace Qpe
{

namespace Private
{

LoggerControllerPrivate::LoggerControllerPrivate(QObject* parent /* = nullptr */)
	: QObject(parent)
	, startTime(QDateTime::currentDateTime())
{
	applicationDirPath = QCoreApplication::applicationDirPath();
	applicationDataPath =
		QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).at(0);
	applicationLocalPath =
		QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0);
	documentsPath =
		QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0);
	homePath =
		QStandardPaths::standardLocations(QStandardPaths::HomeLocation).at(0);

	workThread.setObjectName("LoggerControllerPrivate_Thread");
	this->moveToThread(&workThread);
	workThread.start(QThread::LowPriority);

	connect(
		this, &LoggerControllerPrivate::eventAdded,
		this, &LoggerControllerPrivate::processQueues, Qt::QueuedConnection);
}

LoggerControllerPrivate::~LoggerControllerPrivate()
{
	workThread.quit();
	workThread.wait();
}

void LoggerControllerPrivate::appendEvent(const LoggerEvent* loggerEvent)
{
	{
		QMutexLocker locker(&queueMutex);
		events.enqueue(loggerEvent);
	}
	emit eventAdded();
}

void LoggerControllerPrivate::processQueues()
{
	while (true) {
		const LoggerEvent* loggerEvent = nullptr;
		{
			QMutexLocker locker(&queueMutex);
			if (events.isEmpty()) { break; }
			loggerEvent = events.dequeue();
		}
		processEvent(loggerEvent);
		delete loggerEvent;
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
	LoggerAppenderPointer appender = appendersCache.value(appenderName);
	if (appender) { return appender; }
	appender = appenderFactory.create(p);
	if (!appender) { return appender; }
	appendersCache.insert(appenderName, appender);
	return appender;
}

LoggerFilterPointer LoggerControllerPrivate::createFilter(
	const QString& filterName, const QVariantMap& p)
{
	LoggerFilterPointer filter = filtersCache.value(filterName);
	if (filter) { return filter; }
	filter = filterFactory.create(p);
	if (!filter) { return filter; }
	filtersCache.insert(filterName, filter);
	return filter;
}

template <typename TMap>
TMap& uniteMaps(TMap& m1, const TMap& m2)
{
	auto it = m2.constEnd();
	auto b = m2.constBegin();
	while (it != b) {
		--it;
		auto key = it.key();
		if (!m1.contains(key)) {
			m1.insert(key, it.value());
		}
	}
	return m1;
}

QString LoggerControllerPrivate::registerSettings(const LoggerSettings& s)
{
	if (s.name.isEmpty()) { return QString(); }

	QWriteLocker locker(&settingsLock);
	{
		// если уже есть настройки с таким же именем - выходим
		auto it = std::find_if(settings.constBegin(), settings.constEnd(),
			[s] (const LoggerSettings& i) { return s.name == i.name; });
		if (it != settings.constEnd()) { return QString(); }
	}

	{
		actualLoggers = s.loggers;
		actualAppenders = s.appenders;
		actualFilters = s.filters;

		auto it = settings.constEnd();
		while (it != settings.constBegin()) {
			--it;
			const LoggerSettings& i = *it;
			uniteMaps(actualLoggers, i.loggers);
			uniteMaps(actualAppenders, i.appenders);
			uniteMaps(actualFilters, i.filters);
		}
		settings.append(s);
	}
	return s.name;
}

bool LoggerControllerPrivate::unregisterSettings(const QString& settingsName)
{
	if (settingsName.isEmpty()) { return false; }

	QWriteLocker locker(&settingsLock);
	{
		// если нет настройки с таким же именем - выходим
		auto it = std::find_if(settings.begin(), settings.end(),
			[settingsName] (const LoggerSettings& i) { return settingsName == i.name; });
		if (it == settings.end()) { return false; }
		settings.erase(it);
	}

	{
		actualLoggers.clear();
		actualAppenders.clear();
		actualFilters.clear();

		auto it = settings.constEnd();
		while (it != settings.constBegin()) {
			--it;
			const LoggerSettings& i = *it;
			uniteMaps(actualLoggers, i.loggers);
			uniteMaps(actualAppenders, i.appenders);
			uniteMaps(actualFilters, i.filters);
		}
	}
	return true;
}

void LoggerControllerPrivate::config(
	const QStringList& configNames,
	LoggerAppenderList* appenders, LoggerFilterList* filters)
{
	appenders->clear();
	filters->clear();

	QSet<QString> appenderNames;
	auto addAppender = [this, &appenders, &appenderNames] (const QVariant& v)
	{
		QStringList names;
		if (v.type() == QVariant::StringList) {
			names = v.toStringList().filter(QRegularExpression("^.+$"));
		} else {
			QRegularExpression spliter("\\s*(,|\\||\\+)\\s*");
			names = v.toString().split(spliter, QString::SkipEmptyParts);
		}
		for (const QString& name : qAsConst(names)) {
			if (appenderNames.contains(name)) { continue; } // уже есть, пропускаем

			QVariantMap properties = actualAppenders.value(name);
			if (properties.isEmpty()) { continue; } // свойств нету, пропускаем

			auto appender = createAppender(name, properties);
			if (!appender) { continue; } // не создали, пропускаем

			appenders->append(appender);
			appenderNames.insert(name);
		}
	};

	QSet<QString> filterNames;
	auto addFilter = [this, &filters, &filterNames] (const QVariant& v)
	{
		QStringList names;
		if (v.type() == QVariant::StringList) {
			names = v.toStringList().filter(QRegularExpression("^.+$"));
		} else {
			QRegularExpression spliter("\\s*(,|\\||\\+)\\s*");
			names = v.toString().split(spliter, QString::SkipEmptyParts);
		}
		for (const QString& name : qAsConst(names)) {
			if (filterNames.contains(name)) { continue; } // уже есть, пропускаем

			QVariantMap properties = actualFilters.value(name);
			if (properties.isEmpty()) { continue; } // свойств нету, пропускаем

			auto filter = createFilter(name, properties);
			if (!filter) { continue; } // не создали, пропускаем

			filters->append(filter);
			filterNames.insert(name);
		}
	};

	QReadLocker locker(&settingsLock);
	{
		auto it = actualLoggers.constBegin();
		while (it != actualLoggers.constEnd()) {
			const QString& loggerName = it.key();
			if (configNames.contains(loggerName)) {
				const QVariantMap& properties = it.value();
				addAppender(properties.value("appenders"));
				addFilter(properties.value("filters"));
			}
			++it;
		}
	}
}

// ------------------------------------------------------------------------

LoggerController::LoggerController()
	: QObject()
	, d_ptr(new LoggerControllerPrivate())
{
	QA_D();
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
	QA_D();
	QWriteLocker locker(&d->pathLock);
	d->applicationDirPath = path;
}

void LoggerController::setApplicationDataPath(const QString& path)
{
	QA_D();
	QWriteLocker locker(&d->pathLock);
	d->applicationDataPath = path;
}

void LoggerController::setApplicationLocalPath(const QString& path)
{
	QA_D();
	QWriteLocker locker(&d->pathLock);
	d->applicationLocalPath = path;
}

void LoggerController::registerAppenderType(
	const QString& appenderType, LoggerAppenderCreator&& creator)
{
	QA_D();
	d->appenderFactory.registerAppender(
			appenderType, std::forward<LoggerAppenderCreator>(creator));
	emit configUpdated();
}

void LoggerController::registerFilterType(
	const QString& filterType, LoggerFilterCreator&& creator)
{
	QA_D();
	d->filterFactory.registerFilter(
			filterType, std::forward<LoggerFilterCreator>(creator));
	emit configUpdated();
}

void LoggerController::unregisterAppenderType(const QString& appenderType)
{
	QA_D();
	d->appenderFactory.unregisterAppender(appenderType);
	emit configUpdated();
}

void LoggerController::unregisterFilterType(const QString& filterType)
{
	QA_D();
	d->filterFactory.unregisterFilter(filterType);
	emit configUpdated();
}

QString LoggerController::registerSettings(
	const QString& fileName, const char* codecName /* = nullptr */)
{
	QA_D();
	LoggerSettings s = LoggerSettings::fromSettings(fileName, codecName);
	QString result = d->registerSettings(s);
	if (!result.isEmpty()) {
		emit configUpdated();
	}
	return result;
}

QString LoggerController::registerSettings(
	const QString& name, const QVariantMap& properties)
{
	QA_D();
	LoggerSettings s = LoggerSettings::fromProperties(name, properties);
	QString result = d->registerSettings(s);
	if (!result.isEmpty()) {
		emit configUpdated();
	}
	return result;
}

void LoggerController::unregisterSettings(const QString& settingsName)
{
	QA_D();
	if (d->unregisterSettings(settingsName)) {
		emit configUpdated();
	}
}

void LoggerController::config(const QStringList& configNames,
	LoggerAppenderList* appenders, LoggerFilterList* filters)
{
	QA_D();
	d->config(configNames, appenders, filters);
}

void LoggerController::appendEvent(const LoggerEvent* loggerEvent)
{
	QA_D();
	d->appendEvent(loggerEvent);
}

} // namespace Private

} // namespace Qpe

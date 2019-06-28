#ifndef CORE_LOGGERCONTROLLER_P_H
#define CORE_LOGGERCONTROLLER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QThread>
#include <QMutex>
#include <QQueue>
#include <QStringList>
#include <QMap>
#include <QDateTime>
#include <QReadWriteLock>

#include <Qpe/Qpe>

#include "loggerappender.h"
#include "loggerfilter.h"
#include "loggercleaner.h"

namespace Qpe {

class LoggerEvent;

namespace Private {

struct LoggerSettings
{
	QString name;

	struct AppendersFilters
	{
		AppendersFilters() { }
		AppendersFilters(const QStringList& a, const QStringList& f)
			: appenders(a), filters(f) { }
		QStringList appenders;
		QStringList filters;
	};

	QMap<QString, AppendersFilters> configs;
	QMap<QString, QVariantMap> appenders;
	QMap<QString, QVariantMap> filters;
	QMap<QString, QVariantMap> cleaners;
};

class LoggerCleanerContainer : public QObject
{
	Q_OBJECT
public:
	LoggerCleanerContainer();
	~LoggerCleanerContainer();

public slots:
	void start(const QString& cleanerName, const QVariantMap& properties);
	void stop(const QString& cleanerName);
private:
	void registerCleanerType(
		const QString& cleanerType, LoggerCleanerCreator creator);
	void unregisterCleanerType(const QString& cleanerType);

	LoggerCleanerPointer createCleaner(const QVariantMap& properties);

	QMap<QString, LoggerCleanerPointer> cleaners;

	QReadWriteLock cleanerFactoryLock;
	QHash<QString, LoggerCleanerCreator> cleanerFactory;
};

class LoggerController;
class LoggerControllerPrivate : public QObject
{
	Q_OBJECT
	Q_DECLARE_PUBLIC(LoggerController)
protected:
	LoggerController* q_ptr;
public:
	LoggerControllerPrivate(QObject* parent = nullptr);
	~LoggerControllerPrivate();

	void appendEvent(const LoggerEvent* loggerEvent);

	void registerAppenderType(
		const QString& appenderType, LoggerAppenderCreator creator);
	void registerFilterType(
		const QString& filterType, LoggerFilterCreator creator);
	void unregisterAppenderType(const QString& appenderType);
	void unregisterFilterType(const QString& filterType);

	QString registerSettings(const LoggerSettings& s);
	bool unregisterSettings(const QString& settingsName);

	void config(const QStringList& configNames,
		LoggerAppenderList* appenders, LoggerFilterList* filters);
private slots:
	void processQueues();
signals:
	void eventAdded();
	void aboutCleanerStart(const QString& cleanerName, const QVariantMap& properties);
	void aboutCleanerStop(const QString& cleanerName);
private:
	void startCleaners(const QMap<QString, QVariantMap>& cleaners);
	void stopCleaners(const QMap<QString, QVariantMap>& cleaners);

	void processEvent(const LoggerEvent* loggerEvent);

	QVariantMap insertStandardProperties(const QVariantMap& properties);
	LoggerAppenderPointer createAppender(
		const QString& appenderName, const QVariantMap& properties);
	LoggerFilterPointer createFilter(
		const QString& filterName, const QVariantMap& properties);
	LoggerCleanerPointer createCleaner(const QVariantMap& properties);

	QReadWriteLock pathLock;
	QString applicationDirPath;
	QString applicationDataPath;
	QString applicationLocalPath;

	QThread workThread;
	QMutex queueMutex;

	QThread cleanerThread;
	QSharedPointer<LoggerCleanerContainer> cleaners;

	typedef QQueue<const LoggerEvent*> EventQueue;
	EventQueue events;

	QDateTime startTime;

	QReadWriteLock settingsLock;
	QList<LoggerSettings> settings;

	QMutex appenderCreateMutex;
	QMutex filterCreateMutex;
	QHash<QString, LoggerAppenderCreator> appenderFactory;
	QHash<QString, LoggerFilterCreator> filterFactory;

	QHash<QString, LoggerAppenderPointer> appendersCache;
	QHash<QString, LoggerFilterPointer> filtersCache;
};

} // namespace Private

} // namespace Qpe

#endif // CORE_LOGGERCONTROLLER_P_H

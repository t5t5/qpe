#ifndef CORE_LOGGERCONTROLLER_P_H
#define CORE_LOGGERCONTROLLER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <QThread>
#include <QMutex>
#include <QQueue>
#include <QStringList>
#include <QMap>
#include <QDateTime>
#include <QReadWriteLock>

#include <Qpe/Qpe>

#include <Qpe/Logger/LoggerAppender>
#include "../appenders/appenderfactory.h"

#include <Qpe/Logger/LoggerFilter>
#include "../filters/filterfactory.h"

#include "loggersettings.h"

namespace Qpe
{

class LoggerEvent;

namespace PrivateLogger
{

class LoggerController;
class LoggerControllerPrivate : public QObject
{
	Q_OBJECT
	QPE_DECLARE_PUBLIC(LoggerController)
protected:
	LoggerController* q_ptr;
public:
	LoggerControllerPrivate(QObject* parent = nullptr);
	~LoggerControllerPrivate();

	void appendEvent(const LoggerEvent* loggerEvent);

	QString registerSettings(const LoggerSettings& s);
	bool unregisterSettings(const QString& settingsName);

	void config(const QStringList& configNames,
		LoggerAppenderList* appenders, LoggerFilterList* filters);
private slots:
	void processQueues();
signals:
	void eventAdded();
private:
	void processEvent(const LoggerEvent* loggerEvent);

	QVariantMap insertStandardProperties(const QVariantMap& properties);

	LoggerAppenderPointer createAppender(
		const QString& appenderName, const QVariantMap& properties);
	LoggerFilterPointer createFilter(
		const QString& filterName, const QVariantMap& properties);

	QThread workThread;
	QMutex queueMutex;

	typedef QQueue<const LoggerEvent*> EventQueue;
	EventQueue events;

	QDateTime startTime;

	QReadWriteLock settingsLock;
	QList<LoggerSettings> settings;
	QMap<QString, QVariantMap> actualLoggers;
	QMap<QString, QVariantMap> actualAppenders;
	QMap<QString, QVariantMap> actualFilters;

	LoggerAppenderFactory appenderFactory;
	LoggerFilterFactory filterFactory;

	QHash<QString, LoggerAppenderPointer> appendersCache;
	QHash<QString, LoggerFilterPointer> filtersCache;
};

} // namespace PrivateLogger

} // namespace Qpe

#endif // Q_QDOC

#endif // CORE_LOGGERCONTROLLER_P_H

#ifndef FILTER_FILTERFACTORY_H
#define FILTER_FILTERFACTORY_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <functional>

#include <QSharedPointer>
#include <QHash>
#include <QReadWriteLock>

namespace Qpe
{

class LoggerFilter;
typedef QSharedPointer<LoggerFilter> LoggerFilterPointer;
typedef std::function<LoggerFilterPointer (const QVariantMap&)> LoggerFilterCreator;

class LoggerFilterFactory
{
public:
	LoggerFilterFactory() = default;
	~LoggerFilterFactory() = default;

	LoggerFilterPointer create(const QVariantMap& properties) const;

	void registerFilter(const QString& filterType, LoggerFilterCreator&& creator);
	void unregisterFilter(const QString& filterType);
private:
	mutable QReadWriteLock lock;
	QHash<QString, LoggerFilterCreator> filterCreators;
};

} // namespace Qpe

#endif // FILTER_FILTERFACTORY_H

#ifndef CORE_LOGGERFILTER_H
#define CORE_LOGGERFILTER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QSharedPointer>
#include <QList>

#include <functional>

namespace Qpe
{

class LoggerEvent;
class LoggerFilter
{
public:
	LoggerFilter() { }
	virtual ~LoggerFilter() { }

	virtual bool initialize(const QVariantMap& properties) = 0;
	virtual bool testEvent(const LoggerEvent* loggerEvent) const = 0;
private:
	LoggerFilter(const LoggerFilter&);
	LoggerFilter& operator=(const LoggerFilter&);
};

typedef QSharedPointer<LoggerFilter> LoggerFilterPointer;
typedef QList<LoggerFilterPointer> LoggerFilterList;

typedef std::function<LoggerFilterPointer (const QVariantMap&)> LoggerFilterCreator;

} // namespace Qpe

#endif // CORE_LOGGERFILTER_H

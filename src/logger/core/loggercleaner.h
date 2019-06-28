#ifndef CORE_LOGGERCLEANER_H
#define CORE_LOGGERCLEANER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QSharedPointer>
#include <QList>

#include <functional>

namespace Qpe
{

class LoggerCleaner
{
public:
	LoggerCleaner() { }
	virtual ~LoggerCleaner() { }

	virtual bool initialize(const QVariantMap& properties) = 0;
private:
	LoggerCleaner(const LoggerCleaner&);
	LoggerCleaner& operator=(const LoggerCleaner&);
};

typedef QSharedPointer<LoggerCleaner> LoggerCleanerPointer;
typedef QList<LoggerCleanerPointer> LoggerCleanerList;

typedef std::function<LoggerCleanerPointer (const QVariantMap&)> LoggerCleanerCreator;

} // namespace Qpe

#endif // CORE_LOGGERCLEANER_H

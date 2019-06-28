#ifndef QPE_CLEANERS_CLEANER_DATE_P_H
#define QPE_CLEANERS_CLEANER_DATE_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QRegularExpression>
#include <QSharedPointer>
#include <QDir>

#include "cleaner_date_p_enum.h"

#include <Qpe/Core/Enum>

namespace Qpe
{

class CronTimer;
class DateLoggerCleaner;
class DateLoggerCleanerPrivate
{
	Q_DECLARE_PUBLIC(DateLoggerCleaner)
protected:
	DateLoggerCleaner* q_ptr;
public:
	DateLoggerCleanerPrivate();
	~DateLoggerCleanerPrivate();

	bool isEnabled(const QVariant& value) const;
	bool initializePath(const QVariantMap& properties);
	bool initializeFilters(const QVariant& value);
	bool initializeKeepInterval(const QString& interval);
	bool initializeFileNamePattern(const QString& pattern);

	bool start(const QString& cron);
private:
	void clean();
	bool shouldClean(const QDate& date) const;

	typedef Enum<KeepIntervalType, QString> KeepInterval;
	typedef Flag<FilterType, QString> Filter;

	QDir path;
	QRegularExpression fileNamePattern;
	KeepInterval keepInterval;
	int keepIntervalValue;
	QSharedPointer<CronTimer> cronTimer;
};

} // namespace Qpe

#endif // QPE_CLEANERS_CLEANER_DATE_P_H

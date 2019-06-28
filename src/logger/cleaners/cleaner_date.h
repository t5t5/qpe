#ifndef QPE_CLEANERS_CLEANER_DATE_H
#define QPE_CLEANERS_CLEANER_DATE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include "../core/loggercleaner.h"

namespace Qpe
{

class DateLoggerCleanerPrivate;
class DateLoggerCleaner : public LoggerCleaner
{
	Q_DECLARE_PRIVATE(DateLoggerCleaner)
protected:
	QScopedPointer<DateLoggerCleanerPrivate> d_ptr;
	DateLoggerCleaner(DateLoggerCleanerPrivate* dd);
public:
	DateLoggerCleaner();
	virtual ~DateLoggerCleaner();

	// LoggerCleaner interface
	virtual bool initialize(const QVariantMap& properties);
};

} // namespace Qpe

#endif // QPE_CLEANERS_CLEANER_DATE_H

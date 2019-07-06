#include "filter_classname.h"
#include "filter_classname_p.h"

#include <QRegularExpression>

#include "../core/loggerevent.h"

namespace Qpe
{

ClassNameLoggerFilterPrivate::ClassNameLoggerFilterPrivate()
{
}

ClassNameLoggerFilterPrivate::~ClassNameLoggerFilterPrivate()
{
}

// ---------------------------------------------------------------------------

ClassNameLoggerFilter::ClassNameLoggerFilter(ClassNameLoggerFilterPrivate* dd)
	: d_ptr(dd)
{
	QA_D();
	d->q_ptr = this;
}

ClassNameLoggerFilter::ClassNameLoggerFilter()
	: d_ptr(new ClassNameLoggerFilterPrivate())
{
	QA_D();
	d->q_ptr = this;
}

ClassNameLoggerFilter::~ClassNameLoggerFilter()
{
}

bool ClassNameLoggerFilter::initialize(const QVariantMap& properties)
{
	QA_D();
	QRegularExpression emptyFilter("^.+$");
	QStringList included =
		properties.value("included").toStringList().filter(emptyFilter);
	d->includedClasses = included.toSet();

	QStringList excluded =
		properties.value("excluded").toStringList().filter(emptyFilter);
	d->excludedClasses = excluded.toSet();
	return true;
}

bool ClassNameLoggerFilter::testEvent(const LoggerEvent* loggerEvent) const
{
	QA_D();
	return
		(d->includedClasses.isEmpty() ||
		(d->includedClasses.contains(loggerEvent->className()))) &&
		(d->excludedClasses.isEmpty() ||
		(!d->excludedClasses.contains(loggerEvent->className())));
}

} // namespace Qpe

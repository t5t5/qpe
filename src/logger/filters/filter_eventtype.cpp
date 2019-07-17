#include "filter_eventtype.h"
#include "filter_eventtype_p.h"

#include <QRegularExpression>
#include <QStringList>
#include <QVariant>

#include <Qpe/Logger/LoggerEvent>

namespace Qpe
{

bool EventTypeLoggerFilterPrivate::initialize(const QVariantMap& properties)
{
	QVariant types = properties.value("eventTypes");
	if (types.isNull()) { return true; }

	QStringList typeList;
	if (types.type() == QVariant::StringList) {
		typeList = types.toStringList().filter(QRegularExpression("^.+$"));
	} else {
		QRegularExpression spliter("\\s*(,|\\||\\+)\\s*");
		typeList = types.toString().split(spliter, QString::SkipEmptyParts);
	}
	if (typeList.contains("all", Qt::CaseInsensitive)) {
		permittedTypes.setValue(permittedTypes.mask());
	} else {
		permittedTypes = FlagEventType(typeList, Qt::CaseInsensitive);
	}
	return true;
}

// ---------------------------------------------------------------------------

EventTypeLoggerFilter::EventTypeLoggerFilter(EventTypeLoggerFilterPrivate* dd)
	: d_ptr(dd)
{
	QA_D();
	d->q_ptr = this;
}

EventTypeLoggerFilter::EventTypeLoggerFilter()
	: d_ptr(new EventTypeLoggerFilterPrivate())
{
	QA_D();
	d->q_ptr = this;
}

EventTypeLoggerFilter::~EventTypeLoggerFilter()
{
}

bool EventTypeLoggerFilter::initialize(const QVariantMap& properties)
{
	QA_D();
	return d->initialize(properties);
}

bool EventTypeLoggerFilter::testEvent(const LoggerEvent* loggerEvent) const
{
	QA_D();
	return d->permittedTypes.test(loggerEvent->eventType());
}

} // namespace Qpe

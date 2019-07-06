#ifndef FILTERS_FILTER_EVENTTYPE_H
#define FILTERS_FILTER_EVENTTYPE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>

#include <Qpe/Qpe>
#include <Qpe/Logger/LoggerFilter>

namespace Qpe
{

class EventTypeLoggerFilterPrivate;
class EventTypeLoggerFilter : public LoggerFilter
{
	QPE_DECLARE_PRIVATE(EventTypeLoggerFilter)
protected:
	QScopedPointer<EventTypeLoggerFilterPrivate> d_ptr;
	EventTypeLoggerFilter(EventTypeLoggerFilterPrivate* dd);
public:
	EventTypeLoggerFilter();
	virtual ~EventTypeLoggerFilter();

	// LoggerFilter interface
	virtual bool initialize(const QVariantMap& properties);
	virtual bool testEvent(const LoggerEvent* loggerEvent) const;
};

} // namespace Qpe

#endif // FILTERS_FILTER_EVENTTYPE_H

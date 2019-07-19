#ifndef FILTERS_FILTER_EVENTTYPE_P_H
#define FILTERS_FILTER_EVENTTYPE_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <Qpe/Core/Enum>

#include <Qpe/Logger/EventType>

namespace Qpe
{

class EventTypeLoggerFilter;
class EventTypeLoggerFilterPrivate
{
	QPE_DECLARE_PUBLIC(EventTypeLoggerFilter)
protected:
	EventTypeLoggerFilter* q_ptr;
public:
	EventTypeLoggerFilterPrivate() = default;
	~EventTypeLoggerFilterPrivate() = default;

	bool initialize(const QVariantMap& properties);

	typedef Flag<EventType, QString> FlagEventType;
	FlagEventType permittedTypes;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // FILTERS_FILTER_EVENTTYPE_P_H

#ifndef QPE_FILTERS_FILTER_EVENTTYPE_P_H
#define QPE_FILTERS_FILTER_EVENTTYPE_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

//#include "../core/eventtypewrapper.h"	// TODO: remove

#include <Qpe/Logger/EventType>

namespace Qpe
{

class EventTypeLoggerFilter;
class EventTypeLoggerFilterPrivate
{
	Q_DECLARE_PUBLIC(EventTypeLoggerFilter)
protected:
	EventTypeLoggerFilter* q_ptr;
public:
	EventTypeLoggerFilterPrivate();
	~EventTypeLoggerFilterPrivate();

	EventTypes permittedTypes;
//	Private::EventTypeWrapper permittedTypes; // TODO: remove
};

} // namespace Qpe

#endif // QPE_FILTERS_FILTER_EVENTTYPE_P_H
#ifndef CORE_EVENTTYPE_H
#define CORE_EVENTTYPE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Qpe/Qpe>
#include <QObject>

namespace Qpe
{

#ifndef Q_QDOC
inline namespace qpe_eventtype
{
QPE_LOGGER_EXPORT Q_NAMESPACE
#endif // Q_QDOC

enum EventType
{
	FATAL	= 0x01,
	ERROR	= 0x02,
	WARN	= 0x04,
	INFO	= 0x08,
	DEBUG	= 0x10,
	TRACE	= 0x20,
};
Q_FLAG_NS(EventType)
Q_DECLARE_FLAGS(EventTypes, EventType)

#ifndef Q_QDOC
} // namespace qpe_eventtype
#endif // Q_QDOC

} // namespace Qpe

Q_DECLARE_OPERATORS_FOR_FLAGS(Qpe::qpe_eventtype::EventTypes)

#endif // CORE_EVENTTYPE_H

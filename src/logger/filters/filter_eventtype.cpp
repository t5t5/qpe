#include "filter_eventtype.h"
#include "filter_eventtype_p.h"

#include <QRegularExpression>
#include <QStringList>
#include <QVariant>
#include <QMetaEnum>

#include "../core/loggerevent.h"

namespace Qpe
{

EventTypeLoggerFilterPrivate::EventTypeLoggerFilterPrivate()
{
}

EventTypeLoggerFilterPrivate::~EventTypeLoggerFilterPrivate()
{
}

// ---------------------------------------------------------------------------

EventTypeLoggerFilter::EventTypeLoggerFilter(EventTypeLoggerFilterPrivate* dd)
	: d_ptr(dd)
{
	Q_D(EventTypeLoggerFilter);
	d->q_ptr = this;
}

EventTypeLoggerFilter::EventTypeLoggerFilter()
	: d_ptr(new EventTypeLoggerFilterPrivate())
{
	Q_D(EventTypeLoggerFilter);
	d->q_ptr = this;
}

EventTypeLoggerFilter::~EventTypeLoggerFilter()
{
}

bool EventTypeLoggerFilter::initialize(const QVariantMap& properties)
{
	Q_D(EventTypeLoggerFilter);
	// TODO: debug
	QVariant types = properties.value("eventTypes");
	if (types.isNull()) { return true; }

	QStringList typeList;
	if (types.type() == QVariant::StringList) {
		// TODO: debug QStringList.filter in Qt 5.5
		typeList = types.toStringList().filter(QRegularExpression("^.+$"));
	} else {
		QRegularExpression spliter("\\s*(,|\\||\\+)\\s*");
		typeList = types.toString().split(spliter, QString::SkipEmptyParts);
	}
	if (typeList.contains("ALL", Qt::CaseInsensitive)) {
		d->permittedTypes =
			EventType::FATAL | EventType::ERROR | EventType::WARN |
			EventType::INFO | EventType::DEBUG | EventType::TRACE;
	} else {
		// TODO: refactor
		static QMetaEnum me = QMetaEnum::fromType<EventType>();
		for (const QString& s : qAsConst(typeList)) {
			EventType v = static_cast<EventType>(me.keyToValue(s.toLatin1().data()));
			d->permittedTypes |= v;
		}
//		std::for_each(typeList.constBegin(), typeList.constEnd(),
//			[d] (const QString& t)
//			{
//				Private::EventTypeWrapper eventType(t, Qt::CaseInsensitive);
//				if (eventType.isValid()) {
//					d->permittedTypes |= eventType;
//				}
//			});
	}
	return true;
}

bool EventTypeLoggerFilter::testEvent(const LoggerEvent* loggerEvent) const
{
	Q_D(const EventTypeLoggerFilter);
	return d->permittedTypes.testFlag(loggerEvent->eventType());
}

} // namespace Qpe

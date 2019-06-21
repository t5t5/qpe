#ifndef TOOLS_CRONTIMER_CRONTIMER_P_H
#define TOOLS_CRONTIMER_CRONTIMER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <QTimer>

#include <Qpe/Core/CronTimerExpression>

namespace Qpe
{

class CronTimer;
class CronTimerPrivate
{
	Q_DECLARE_PUBLIC(CronTimer)
protected:
	CronTimer* q_ptr;
public:
	void initialize();
	bool setFormat(const QString& format, const QDateTime& startTime);

	void testWakeUpTime();

	Qpe::CronTimerExpression expression;
	QDateTime lastWakeUpTime;
	QTimer timer;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_CRONTIMER_CRONTIMER_P_H

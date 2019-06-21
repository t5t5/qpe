#ifndef TOOLS_CRONTIMER_CRONTIMEREXPRESSION_H
#define TOOLS_CRONTIMER_CRONTIMEREXPRESSION_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QDateTime>

#include <Qpe/Qpe>

namespace Qpe
{

class CronTimerExpressionPrivate;
class QPE_CORE_EXPORT CronTimerExpression
{
	QPE_DECLARE_PRIVATE(CronTimerExpression)
protected:
	QScopedPointer<CronTimerExpressionPrivate> d_ptr;
public:
	CronTimerExpression();
	CronTimerExpression(
		const QString& cronFormat,
		const QDateTime& startTime = QDateTime::currentDateTime());
	~CronTimerExpression();

	QString format() const;
	bool setFormat(
		const QString& cronFormat,
		const QDateTime& startTime = QDateTime::currentDateTime());

	QDateTime startTime() const;

	bool isValid() const;

	bool test(const QDateTime& time) const;
};

} // namespace Qpe

#endif // TOOLS_CRONTIMER_CRONTIMEREXPRESSION_H

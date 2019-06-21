#ifndef TOOLS_CRONTIMER_CRONTIMEREXPRESSION_P_H
#define TOOLS_CRONTIMER_CRONTIMEREXPRESSION_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <type_traits>

#include <QRegularExpression>
#include <QStringList>
#include <QDate>
#include <QSet>

namespace Qpe
{

namespace Private
{

enum CronExpressionType
{
	Minute,
	Hour,
	Day,
	Month,
	WDay,
	Year
};

template <int TMin, int TMax>
struct CronExpression
{
	static_assert(TMin >= 0, "TMin can't less than 0");
	static_assert(TMax >= 0, "TMax can't less than 0");
	static_assert(TMin <= TMax, "TMin can't greater than TMax");

	static const int size = TMax - TMin + 1;
	static_assert(size <= 64, "[TMax - TMin + 1] can't greater than 64");

	typedef
		typename std::conditional<
			(size >= 32),
			quint64,
			typename std::conditional<
				(size >= 16),
				quint32,
				typename std::conditional<(size >= 8), quint16, quint8>::type
			>::type
		>::type type;

	type value;
	inline CronExpression() : value(0) { }

	inline bool set(int v)
	{
		bool shouldSet = (v >= TMin) && (v <= TMax);
		if (shouldSet) {
			value |= static_cast<type>(1) << (v - TMin);
		}
		return shouldSet;
	}

	inline bool setRange(int step)
	{
		if (step == 0) { step = 1; }
		for (int i = TMin; i <= TMax; i += step) {
			value |= static_cast<type>(1) << (i - TMin);
		}
		return true;
	}

	inline bool setRange(int step, int start, int end)
	{
		start = start ? qMax(start, TMin) : TMin;
		end = end ? qMin(end, TMax) : TMax;
		if (step == 0) { step = 1; }

		bool shouldSet = (start >= TMin) && (start <= TMax) && (start <= end);
		if (shouldSet) {
			for (int i = start; i <= end; i += step) {
				value |= static_cast<type>(1) << (i - TMin);
			}
		}
		return shouldSet;
	}

	inline bool test(int v) const
	{
		return ((v >= TMin) && (v <= TMax))
			? value & (static_cast<type>(1) << (v - TMin))
			: false;
	}
};

class CronExpressionYear
{
public:
	inline CronExpressionYear()
	{
		currentYear = QDate::currentDate().year();
		centuryYear = currentYear - currentYear % 100;
		maxYear = currentYear + 100;
	}
	inline bool set(int year)
	{
		if (year < 100) { year += centuryYear; }
		bool shouldSet = (year >= currentYear) && (year <= maxYear);
		if (shouldSet) {
			years.insert(year);
		}
		return true;
	}

	inline bool setRange(int step)
	{
		if (step == 0) { step = 1; }
		for (int year = currentYear; year <= maxYear; year += step) {
			years.insert(year);
		}
		return true;
	}
	inline bool setRange(int step, int start, int end)
	{
		if (step == 0) { step = 1; }
		if (start < 100) { start += centuryYear; }
		if (end == 0) {
			end = maxYear;
		} else
		if (end < 100) {
			end += centuryYear;
		}
		start = qMax(start, currentYear);
		end = qMin(end, maxYear);
		bool shouldSet = (start >= centuryYear) && (start <= maxYear) && (start <= end);
		if (shouldSet) {
			for (int year = start; year <= end; year += step) {
				years.insert(year);
			}
		}
		return true;
	}

	inline bool test(int year) const
	{
		return years.isEmpty() || years.contains(year);
	}
private:
	QSet<int> years;
	int currentYear;
	int centuryYear;
	int maxYear;
};

} // namespace Private

// ------------------------------------------------------------------------

class CronTimerExpression;
class CronTimerExpressionPrivate
{
	friend class CronTimerExpression;
public:
	CronTimerExpressionPrivate();

	bool setFormat(const QString& format, const QDateTime& startTime);
private:
	QRegularExpression partRegularExpression(
		Private::CronExpressionType expressionType) const;
	template <class TExpr>
	bool setPart(
		const QString& data, Private::CronExpressionType,
		int currentValue, TExpr& p);

	bool test(const QDateTime& time) const;

	QDateTime startTime;
	QString format;
	bool valid;
	Private::CronExpression<0, 59> minutes;
	Private::CronExpression<0, 23> hours;
	Private::CronExpression<1, 31> days;
	Private::CronExpression<1, 12> months;
	Private::CronExpression<1, 7> wdays;
	Private::CronExpressionYear years;

	QStringList monthList;
	QStringList wdayList;

	QRegularExpression formatRegEx;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_CRONTIMER_CRONTIMEREXPRESSION_P_H

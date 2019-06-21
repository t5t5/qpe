#include "crontimerexpression.h"
#include "crontimerexpression_p.h"

/*!
  \class Qpe::CronTimerExpression
  \inmodule core
  \brief Выражение для cron-таймера.
  \inheaderfile Qpe/Core/CronTimerExpression
  \ingroup core

  \section1 Cron-формат.

  Cron-формат - это простой, но мощный и гибкий способ описания времени и
  периодичности действий.

  Cron-формат состоит из пяти полей или шести полей, разделенных пробелами:
  \code
  <Минуты> <Часы> <Дни_месяца> <Месяцы> <Дни_недели>
  \endcode
  или
  \code
  <Минуты> <Часы> <Дни_месяца> <Месяцы> <Дни_недели> <Годы>
  \endcode
  Схема:
  \code
  * * * * * *
  | | | | | |
  | | | | | +--- Годы       (диапазон: Текущий ... Текущий + 100)
  | | | | +----- Дни недели (диапазон: 1-7)
  | | | +------- Месяцы     (диапазон: 1-12)
  | | +--------- Дни месяца (диапазон: 1-31)
  | +----------- Часы       (диапазон: 0-23)
  +------------- Минуты     (диапазон: 0-59)
  \endcode

  \table
    \header \li Обозначение
            \li Допустимые поля
            \li Описание
    \row    \li \b *
            \li Все поля
            \li Все возможные значения
    \row    \li \b ?
            \li Минуты, Часы, Дни месяца, Месяцы
            \li Становится равным моменту запуска таймера
    \row    \li 1,3,7 (последовательность разделенная запятыми)
            \li Все поля
            \li Конкретное значение
    \row    \li 1-5 (диапазон)
            \li Все поля
            \li Диапазон значений
    \row    \li x/n
            \li Все поля
            \li После косой черты указывается шаг
    \row    \li jan,feb,...,dec
            \li Месяцы
            \li Конкретное указание месяца
    \row    \li mon,tue,...,sun
            \li Дни недели
            \li Конкретное указание дня недели
  \endtable

  Примеры:
  \code
* * * * * *                           Каждую минуту

59 23 31 12 5 *                       За минуту до конца года, если последний день года -
                                      пятница

59 23 31 Dec Fri *                    За минуту до конца года, если последний день года -
                                      пятница (еще один вариант записи)

45 17 7 6 * *                         Каждый год 7-го июня в 17:45

45 17 7 6 * 2001,2002                 Раз в год 7-го июня в 17:45, если сейчас 2001-й или
                                      2002-й год

0,15,30,45 0,6,12,18 1,15,31 * 1-5 *  В 00:00, 00:15, 00:30, 00:45, 06:00, 06:15, 06:30,
                                      06:45, 12:00, 12:15, 12:30, 12:45, 18:00, 18:15,
                                      18:30, 18:45, если сейчас 1-е, 15-е или 31-е число
                                      любого месяца и только по рабочим дням недели

*\15 *\6 1,15,31 * 1-5 *              В 00:00, 00:15, 00:30, 00:45, 06:00, 06:15, 06:30,
                                      06:45, 12:00, 12:15, 12:30, 12:45, 18:00, 18:15,
                                      18:30, 18:45, если сейчас 1-е, 15-е или 31-е число
                                      любого месяца и только по рабочим дням недели (еще
                                      один вариант записи) (слеш должен быть прямой)

0 12 * * 1-5 * (0 12 * * Mon-Fri *)   В полдень по рабочим дням

* * * 1,3,5,7,9,11 * *                Каждую минуту в январе, марте, мае, июле, сентябре
                                      и ноябре

1,2,3,5,20-25,30-35,59 23 31 12 * *   В последний день года в 23:01, 23:02, 23:03, 23:05,
                                      23:20, 23:21, 23:22, 23:23, 23:24, 23:25, 23:30,
                                      23:31, 23:32, 23:33, 23:34, 23:35, 23:59

0 9 1-7 * 1 *                         Первый понедельник каждого месяца, в 9 утра

0 0 1 * * *                           В полночь, первого числа, каждый месяц

* 0-11 * * *                          Каждую минуту до полудня

* * * 1,2,3 * *                       Каждую минуту в январе, феврале и марте

* * * Jan,Feb,Mar * *                 Каждую минуту в январе, феврале и марте

0 0 * * * *                           Каждый день в полночь

0 0 * * 3 *                           Каждую среду в полночь
  \endcode
 */


namespace Qpe
{

CronTimerExpressionPrivate::CronTimerExpressionPrivate()
	: valid(false)
#ifndef Q_COMPILER_INITIALIZER_LISTS
	, monthList(QStringList()
		<< "jan" << "feb" << "mar" << "apr"
		<< "may" << "jun" << "jul" << "aug"
		<< "sep" << "okt" << "nov" << "dec")
	, wdayList(QStringList()
		<< "mon" << "tue" << "wed" << "thu" << "fri" << "sat" << "sun")
#else
	, monthList({
		"jan", "feb", "mar", "apr",
		"may", "jun", "jul", "aug",
		"sep", "oct", "nov", "dec"
	  })
	, wdayList({"mon", "tue", "wed", "thu", "fri", "sat", "sun"})
#endif
	, formatRegEx("^"
			"(?<minute>\\S+)\\s+"
			"(?<hour>\\S+)\\s+"
			"(?<day>\\S+)\\s+"
			"(?<month>\\S+)\\s+"
			"(?<wday>\\S+)"
			"(?:\\s+(?<year>\\S+))?"
		"$")
{
}

bool CronTimerExpressionPrivate::setFormat(const QString& f, const QDateTime& st)
{
	format = f;

	startTime = st;

	QDate date = st.date();
	QTime time = st.time();

	QRegularExpressionMatch m = formatRegEx.match(format);
	valid =
		setPart(m.captured("minute"), Private::Minute, time.minute(), minutes) &&
		setPart(m.captured("hour"), Private::Hour, time.hour(), hours) &&
		setPart(m.captured("day"), Private::Day, date.day(), days) &&
		setPart(m.captured("month"), Private::Month, date.month(), months) &&
		setPart(m.captured("wday"), Private::WDay, 0, wdays);
	if (valid) {
		QString yearCapture = m.captured("year");
		if (!yearCapture.isEmpty()) {
			valid = setPart(yearCapture, Private::Year, 0, years);
			years.setInitialized();
		}
	}
	return valid;
}

QRegularExpression CronTimerExpressionPrivate::partRegularExpression(
	Private::CronExpressionType expressionType) const
{
	QString pattern = QString(
			"(?:"
				"(?:(?<asterisk>\\*)(?:/(?<step1>\\d+))?)"
				"%1"
				"|"
				"(?:"
					"(?<range1>\\d+)"
					"(?:\\-(?<range2>\\d+))?"
					"(?:/(?<step2>\\d+))?"
				")"
				"%2"
				"%3"
			"),?")
		.arg(
			((expressionType == Private::Minute) ||
			(expressionType == Private::Hour) ||
			(expressionType == Private::Day) ||
			(expressionType == Private::Month))
				? QString(
					"|"
					"(?<question>\\?)")
				: QString()
			,
			(expressionType == Private::Month)
				? QString(
					"|"
					"(?:"
						"(?<rangeMonth1>(?:%1))"
						"(?:\\-(?<rangeMonth2>(?:%1)))?"
						"(?:/(?<step3>\\d+))?"
					")"
					).arg(monthList.join('|'))
				: QString()
			,
			(expressionType == Private::WDay)
				? QString(
					"|"
					"(?:"
						"(?<rangeWDay1>(?:%1))"
						"(?:\\-(?<rangeWDay2>(?:%1)))?"
						"(?:/(?<step4>\\d+))?"
					")"
					).arg(wdayList.join('|'))
				: QString()
		);
	return QRegularExpression(pattern, QRegularExpression::CaseInsensitiveOption);
}

bool CronTimerExpressionPrivate::test(const QDateTime& time) const
{
	QDate d = time.date();
	QTime t = time.time();

	return
		minutes.test(t.minute()) &&
		hours.test(t.hour()) &&
		days.test(d.day()) &&
		months.test(d.month()) &&
		wdays.test(d.dayOfWeek()) &&
		years.test(d.year());
}

template <class TExpr>
bool CronTimerExpressionPrivate::setPart(
	const QString& data, Private::CronExpressionType expressionType,
	int currentValue, TExpr& p)
{
	QRegularExpression r = partRegularExpression(expressionType);

	QRegularExpressionMatch m;
	int pos = 0;
	bool result = true;
	while ((m = r.match(data, pos,
			QRegularExpression::NormalMatch,
			QRegularExpression::AnchoredMatchOption)).hasMatch() && result)
	{
		if (!m.captured("question").isEmpty()) {
			result &= p.set(currentValue);
		} else
		if (!m.captured("asterisk").isEmpty()) {
			result &= p.setRange(m.captured("step1").toInt());
		} else
		if (!m.captured("range1").isEmpty() &&
			m.captured("range2").isEmpty() &&
			m.captured("step2").isEmpty())
		{
			result &= p.set(m.captured("range1").toInt());
		} else
		if (!m.captured("range1").isEmpty()) {
			result &= p.setRange(
				m.captured("step2").toInt(),
				m.captured("range1").toInt(),
				m.captured("range2").toInt());
		} else
		if ((expressionType == Private::Month) &&
			!m.captured("rangeMonth1").isEmpty() &&
			m.captured("rangeMonth2").isEmpty() &&
			m.captured("step3").isEmpty())
		{
			int range1 = monthList.indexOf(QRegularExpression(
					m.captured("rangeMonth1"), QRegularExpression::CaseInsensitiveOption)) + 1;
			result &= p.set(range1);
		} else
		if ((expressionType == Private::Month) &&
			!m.captured("rangeMonth1").isEmpty())
		{
			int range1 = monthList.indexOf(QRegularExpression(
					m.captured("rangeMonth1"), QRegularExpression::CaseInsensitiveOption)) + 1;
			int range2 = monthList.indexOf(QRegularExpression(
					m.captured("rangeMonth2"), QRegularExpression::CaseInsensitiveOption)) + 1;
			result &= p.setRange(m.captured("step3").toInt(), range1, range2);
		} else
		if ((expressionType == Private::WDay) &&
			!m.captured("rangeWDay1").isEmpty() &&
			m.captured("rangeWDay2").isEmpty() &&
			m.captured("step4").isEmpty())
		{
			int range1 = wdayList.indexOf(QRegularExpression(
					m.captured("rangeWDay1"), QRegularExpression::CaseInsensitiveOption)) + 1;
			result &= p.set(range1);
		} else
		if ((expressionType == Private::WDay) &&
			!m.captured("rangeWDay1").isEmpty())
		{
			int range1 = wdayList.indexOf(QRegularExpression(
					m.captured("rangeWDay1"), QRegularExpression::CaseInsensitiveOption)) + 1;
			int range2 = wdayList.indexOf(QRegularExpression(
					m.captured("rangeWDay2"), QRegularExpression::CaseInsensitiveOption)) + 1;
			result &= p.setRange(m.captured("step4").toInt(), range1, range2);
		}

		pos += m.capturedLength();
	}
	return result && (pos >= data.size());
}

// ---------------------------------------------------------------------------

CronTimerExpression::CronTimerExpression()
	: d_ptr(new CronTimerExpressionPrivate())
{
}

/*!
 * \fn CronTimerExpression::CronTimerExpression(
		const QString& cronFormat,
		const QDateTime& startTime = QDateTime::currentDateTime())
 * Конструктор. Установить формат cron-таймера в \a cronFormat.
 * Время запуска таймера \a startTime необходимо для cron-выражения "?".
 */
CronTimerExpression::CronTimerExpression(
		const QString& cronFormat,
		const QDateTime& startTime /* = QDateTime::currentDateTime() */)
	: d_ptr(new CronTimerExpressionPrivate())
{
	QA_D();
	d->setFormat(cronFormat, startTime);
}

CronTimerExpression::~CronTimerExpression()
{
}

/*!
 * \fn QString CronTimerExpression::format() const
 * Получить строку формата таймера.
 */
QString CronTimerExpression::format() const
{
	QA_D();
	return d->format;
}

/*!
 * \fn void CronTimerExpression::setFormat(
		const QString& cronFormat,
		const QDateTime& startTime = QDateTime::currentDateTime())
 * Установить формат cron-таймера в \a cronFormat.
 * Время запуска таймера \a startTime необходимо для cron-выражения "?".
 * Возвращает \c true, если формат установлен корректно, иначе \c false.
 */
bool CronTimerExpression::setFormat(
		const QString& cronFormat,
		const QDateTime& startTime /* = QDateTime::currentDateTime() */)
{
	QA_D();
	return d->setFormat(cronFormat, startTime);
}

/*!
 * \fn QDateTime CronTimerExpression::startTime() const
 * Возвращает время запуска таймера.
 *
 * \sa setFormat()
 */
QDateTime CronTimerExpression::startTime() const
{
	QA_D();
	return d->startTime;
}

/*!
 * \fn bool CronTimerExpression::isValid() const
 * Возвращает \c true, если формат распознан, иначе \c false.
 */
bool CronTimerExpression::isValid() const
{
	QA_D();
	return d->valid;
}

/*!
 * \fn bool CronTimerExpression::test(const QDateTime& time) const
 * Протестировать удовлетворяет ли время \a time заданному выражению.
 */
bool CronTimerExpression::test(const QDateTime& time) const
{
	QA_D();
	return time.isValid() ? d->test(time) : false;
}

} // namespace Qpe

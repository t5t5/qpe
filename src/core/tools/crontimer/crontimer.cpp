#include "crontimer.h"
#include "crontimer_p.h"

#include <QRegularExpression>
#include <QDateTime>

/*!
  \class Qpe::CronTimer
  \inmodule core
  \brief Cron таймер.
  \inheaderfile Qpe/Core/CronTimer
  \ingroup core

  \sa Qpe::CronTimerExpression
 */

namespace Qpe
{

void CronTimerPrivate::initialize()
{
	Q_Q(CronTimer);
	timer.setInterval(30000); // 30 seconds
	timer.setSingleShot(false);

	QObject::connect(&timer, &QTimer::timeout,
	q, [this] () { testWakeUpTime(); });
}

void CronTimerPrivate::testWakeUpTime()
{
	QDate d = QDate::currentDate();
	QTime t = QTime::currentTime();
	QDateTime dt(d, QTime(t.hour(), t.minute()));

	if ((lastWakeUpTime != dt) && expression.test(dt)) {
		QA_Q();
		lastWakeUpTime = dt;
		emit q->wakeUp();
	}
}

// ---------------------------------------------------------------------------

CronTimer::CronTimer(QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new CronTimerPrivate())
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
}

CronTimer::~CronTimer()
{
}

/*!
 * \fn QString CronTimer::format() const
 * Получить строку формата таймера.
 */
QString CronTimer::format() const
{
	QA_D();
	return d->expression.format();
}

/*!
 * \fn bool CronTimer::isValid() const
 * Возвращает \c true, если формат распознан, иначе \c false.
 */
bool CronTimer::isValid() const
{
	QA_D();
	return d->expression.isValid();
}

/*!
 * \fn bool CronTimer::isActive() const
 * Возвращает \c true, если таймер запущен, иначе \c false.
 */
bool CronTimer::isActive() const
{
	QA_D();
	return d->timer.isActive();
}

/*!
 * \fn QDateTime CronTimer::startTime() const
 * Возвращает время запуска таймера.
 */
QDateTime CronTimer::startTime() const
{
	QA_D();
	return d->expression.startTime();
}

/*!
 * \fn QDateTime CronTimer::lastWakeUpTime() const
 * Возвращает время последнего срабатывания таймера.
 */
QDateTime CronTimer::lastWakeUpTime() const
{
	QA_D();
	return d->lastWakeUpTime;
}

/*!
 * \fn void CronTimer::start(const QString& cronFormat)
 * Запустить таймер с заданым форматом времени срабатывания \a cronFormat.
 */
void CronTimer::start(const QString& cronFormat)
{
	QA_D();
	stop();

	d->lastWakeUpTime = QDateTime();
	bool valid = d->expression.setFormat(cronFormat);
	if (valid) {
		d->timer.start();
	}
	if (d->timer.isActive()) {
		d->testWakeUpTime();
	}
}

/*!
 * \fn void CronTimer::stop()
 * Останивить таймер.
 */
void CronTimer::stop()
{
	QA_D();
	d->timer.stop();
}

/*!
 * \fn void CronTimer::wakeUp()
 * Событие о срабатывании таймера.
 */

} // namespace Qpe

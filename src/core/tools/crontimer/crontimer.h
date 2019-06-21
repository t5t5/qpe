#ifndef TOOLS_CRONTIMER_CRONTIMER_H
#define TOOLS_CRONTIMER_CRONTIMER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QObject>

#include <Qpe/Qpe>

namespace Qpe
{

class CronTimerPrivate;
class QPE_CORE_EXPORT CronTimer : public QObject
{
	Q_OBJECT
	QPE_DECLARE_PRIVATE(CronTimer)
protected:
	QScopedPointer<CronTimerPrivate> d_ptr;
public:
	CronTimer(QObject* parent = nullptr);
	virtual ~CronTimer();

	QString format() const;

	bool isValid() const;
	bool isActive() const;

	QDateTime startTime() const;
	QDateTime lastWakeUpTime() const;
public slots:
	void start(const QString& cronFormat);
	void stop();
signals:
	void wakeUp();
};

} // namespace Qpe

#endif // TOOLS_CRONTIMER_CRONTIMER_H

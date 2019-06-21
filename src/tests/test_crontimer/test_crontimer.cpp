#include <QtTest/QTest>
#include <QDebug>
#include <QVariant>
#include <QSignalSpy>

#include <Qpe/Qpe>

#include <Qpe/Core/CronTimer>

class TestConversion : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void test();
private:
	Qpe::CronTimer* timer;
};

void TestConversion::initTestCase()
{
	timer = new Qpe::CronTimer(this);
}

void TestConversion::test()
{
	QSignalSpy spy(timer, &Qpe::CronTimer::wakeUp);

	QVERIFY(!timer->isValid());
	QVERIFY(!timer->isActive());
	timer->start("20 * * * * *");
	QVERIFY(timer->isValid());
	QVERIFY(timer->isActive());

	spy.wait(60000);
	QVERIFY(spy.count() == 1);
}

QTEST_MAIN(TestConversion)

#include "test_crontimer.moc"

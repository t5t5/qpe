#include <QtTest/QTest>
#include <QDebug>
#include <QVariant>
#include <QSignalSpy>

#include <Qpe/Qpe>

#include <Qpe/Core/CronTimer>
#include <Qpe/Core/CronTimerExpression>

class TestCronTimer : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();

	void test_cronformat_1();
	void test_cronformat_2();
	void test_cronformat_3();
	void test_cronformat_4();
	void test_cronformat_5();
	void test_cronformat_6();
	void test_cronformat_7();
	void test_cronformat_8();
	void test_cronformat_9();
	void test_cronformat_10();
	void test_cronformat_11();
	void test_cronformat_12();

	void test_signal();
private:
	QDateTime dt(int y, int mon, int d, int h, int min) const;
	QDateTime dt(const QDate& d, int h, int min) const;
	QDateTime dt(int mon, int d) const;
	QDateTime dt(const QDateTime& dt, int y) const;
	Qpe::CronTimer* timer;
};

QDateTime TestCronTimer::dt(int y, int mon, int d, int h, int min) const
{
	return QDateTime(QDate(y, mon, d), QTime(h, min));
}

QDateTime TestCronTimer::dt(const QDate& d, int h, int min) const
{
	return QDateTime(d, QTime(h, min));
}

QDateTime TestCronTimer::dt(int mon, int d) const
{
	QDate dd(2019, mon, d);
	return QDateTime(dd, QTime::currentTime());
}

QDateTime TestCronTimer::dt(const QDateTime& d, int y) const
{
	QDate date = d.date();
	QDate ndate(y, date.month(), date.day());
	return QDateTime(ndate, d.time());
}

void TestCronTimer::initTestCase()
{
	timer = new Qpe::CronTimer(this);
}

void TestCronTimer::test_signal()
{
	QSignalSpy spy(timer, &Qpe::CronTimer::wakeUp);

	QTime t = QTime::currentTime();
	int minute = t.minute() + 1;
	QVERIFY(!timer->isValid());
	QVERIFY(!timer->isActive());
	timer->start(QString("%1 * * * * *").arg(minute));
	QVERIFY(timer->isValid());
	QVERIFY(timer->isActive());

	spy.wait(120000);
	QVERIFY(spy.count() == 1);
}

void TestCronTimer::test_cronformat_1()
{
	QDate d = QDate::currentDate();
	Qpe::CronTimerExpression exp("* * * * * *");
	QVERIFY(exp.test(dt(d,  0, 0)));
	QVERIFY(exp.test(dt(d,  1, 0)));
	QVERIFY(exp.test(dt(d,  2, 0)));
	QVERIFY(exp.test(dt(d,  3, 0)));
	QVERIFY(exp.test(dt(d,  4, 0)));
	QVERIFY(exp.test(dt(d,  5, 0)));
	QVERIFY(exp.test(dt(d,  6, 0)));
	QVERIFY(exp.test(dt(d,  7, 0)));
	QVERIFY(exp.test(dt(d,  8, 0)));
	QVERIFY(exp.test(dt(d,  9, 0)));
	QVERIFY(exp.test(dt(d, 10, 0)));
	QVERIFY(exp.test(dt(d, 11, 0)));
	QVERIFY(exp.test(dt(d, 12, 0)));
	QVERIFY(exp.test(dt(d, 13, 0)));
	QVERIFY(exp.test(dt(d, 14, 0)));
	QVERIFY(exp.test(dt(d, 15, 0)));
	QVERIFY(exp.test(dt(d, 16, 0)));
	QVERIFY(exp.test(dt(d, 17, 0)));
	QVERIFY(exp.test(dt(d, 18, 0)));
	QVERIFY(exp.test(dt(d, 19, 0)));
	QVERIFY(exp.test(dt(d, 20, 0)));
	QVERIFY(exp.test(dt(d, 21, 0)));
	QVERIFY(exp.test(dt(d, 22, 0)));
	QVERIFY(exp.test(dt(d, 23, 0)));

	QVERIFY(exp.test(dt(d, 0,  0)));
	QVERIFY(exp.test(dt(d, 0,  1)));
	QVERIFY(exp.test(dt(d, 0,  2)));
	QVERIFY(exp.test(dt(d, 0,  3)));
	QVERIFY(exp.test(dt(d, 0,  4)));
	QVERIFY(exp.test(dt(d, 0,  5)));
	QVERIFY(exp.test(dt(d, 0,  6)));
	QVERIFY(exp.test(dt(d, 0,  7)));
	QVERIFY(exp.test(dt(d, 0,  8)));
	QVERIFY(exp.test(dt(d, 0,  9)));
	QVERIFY(exp.test(dt(d, 0, 10)));
	QVERIFY(exp.test(dt(d, 0, 11)));
	QVERIFY(exp.test(dt(d, 0, 12)));
	QVERIFY(exp.test(dt(d, 0, 13)));
	QVERIFY(exp.test(dt(d, 0, 14)));
	QVERIFY(exp.test(dt(d, 0, 15)));
	QVERIFY(exp.test(dt(d, 0, 16)));
	QVERIFY(exp.test(dt(d, 0, 17)));
	QVERIFY(exp.test(dt(d, 0, 18)));
	QVERIFY(exp.test(dt(d, 0, 19)));
	QVERIFY(exp.test(dt(d, 0, 20)));
	QVERIFY(exp.test(dt(d, 0, 21)));
	QVERIFY(exp.test(dt(d, 0, 22)));
	QVERIFY(exp.test(dt(d, 0, 23)));
	QVERIFY(exp.test(dt(d, 0, 24)));
	QVERIFY(exp.test(dt(d, 0, 25)));
	QVERIFY(exp.test(dt(d, 0, 26)));
	QVERIFY(exp.test(dt(d, 0, 27)));
	QVERIFY(exp.test(dt(d, 0, 28)));
	QVERIFY(exp.test(dt(d, 0, 29)));
	QVERIFY(exp.test(dt(d, 0, 30)));
	QVERIFY(exp.test(dt(d, 0, 31)));
	QVERIFY(exp.test(dt(d, 0, 32)));
	QVERIFY(exp.test(dt(d, 0, 33)));
	QVERIFY(exp.test(dt(d, 0, 34)));
	QVERIFY(exp.test(dt(d, 0, 35)));
	QVERIFY(exp.test(dt(d, 0, 36)));
	QVERIFY(exp.test(dt(d, 0, 37)));
	QVERIFY(exp.test(dt(d, 0, 38)));
	QVERIFY(exp.test(dt(d, 0, 39)));
	QVERIFY(exp.test(dt(d, 0, 40)));
	QVERIFY(exp.test(dt(d, 0, 41)));
	QVERIFY(exp.test(dt(d, 0, 42)));
	QVERIFY(exp.test(dt(d, 0, 43)));
	QVERIFY(exp.test(dt(d, 0, 44)));
	QVERIFY(exp.test(dt(d, 0, 45)));
	QVERIFY(exp.test(dt(d, 0, 46)));
	QVERIFY(exp.test(dt(d, 0, 47)));
	QVERIFY(exp.test(dt(d, 0, 48)));
	QVERIFY(exp.test(dt(d, 0, 49)));
	QVERIFY(exp.test(dt(d, 0, 50)));
	QVERIFY(exp.test(dt(d, 0, 51)));
	QVERIFY(exp.test(dt(d, 0, 52)));
	QVERIFY(exp.test(dt(d, 0, 53)));
	QVERIFY(exp.test(dt(d, 0, 54)));
	QVERIFY(exp.test(dt(d, 0, 55)));
	QVERIFY(exp.test(dt(d, 0, 56)));
	QVERIFY(exp.test(dt(d, 0, 57)));
	QVERIFY(exp.test(dt(d, 0, 58)));
	QVERIFY(exp.test(dt(d, 0, 59)));
}

void TestCronTimer::test_cronformat_2()
{
	QDate d = QDate::currentDate();
	Qpe::CronTimerExpression exp("*/4 */3 * * * *");
	QVERIFY( exp.test(dt(d,  0, 0)));
	QVERIFY(!exp.test(dt(d,  1, 0)));
	QVERIFY(!exp.test(dt(d,  2, 0)));
	QVERIFY( exp.test(dt(d,  3, 0)));
	QVERIFY(!exp.test(dt(d,  4, 0)));
	QVERIFY(!exp.test(dt(d,  5, 0)));
	QVERIFY( exp.test(dt(d,  6, 0)));
	QVERIFY(!exp.test(dt(d,  7, 0)));
	QVERIFY(!exp.test(dt(d,  8, 0)));
	QVERIFY( exp.test(dt(d,  9, 0)));
	QVERIFY(!exp.test(dt(d, 10, 0)));
	QVERIFY(!exp.test(dt(d, 11, 0)));
	QVERIFY( exp.test(dt(d, 12, 0)));
	QVERIFY(!exp.test(dt(d, 13, 0)));
	QVERIFY(!exp.test(dt(d, 14, 0)));
	QVERIFY( exp.test(dt(d, 15, 0)));
	QVERIFY(!exp.test(dt(d, 16, 0)));
	QVERIFY(!exp.test(dt(d, 17, 0)));
	QVERIFY( exp.test(dt(d, 18, 0)));
	QVERIFY(!exp.test(dt(d, 19, 0)));
	QVERIFY(!exp.test(dt(d, 20, 0)));
	QVERIFY( exp.test(dt(d, 21, 0)));
	QVERIFY(!exp.test(dt(d, 22, 0)));
	QVERIFY(!exp.test(dt(d, 23, 0)));

	QVERIFY( exp.test(dt(d, 0,  0)));
	QVERIFY(!exp.test(dt(d, 0,  1)));
	QVERIFY(!exp.test(dt(d, 0,  2)));
	QVERIFY(!exp.test(dt(d, 0,  3)));
	QVERIFY( exp.test(dt(d, 0,  4)));
	QVERIFY(!exp.test(dt(d, 0,  5)));
	QVERIFY(!exp.test(dt(d, 0,  6)));
	QVERIFY(!exp.test(dt(d, 0,  7)));
	QVERIFY( exp.test(dt(d, 0,  8)));
	QVERIFY(!exp.test(dt(d, 0,  9)));
	QVERIFY(!exp.test(dt(d, 0, 10)));
	QVERIFY(!exp.test(dt(d, 0, 11)));
	QVERIFY( exp.test(dt(d, 0, 12)));
	QVERIFY(!exp.test(dt(d, 0, 13)));
	QVERIFY(!exp.test(dt(d, 0, 14)));
	QVERIFY(!exp.test(dt(d, 0, 15)));
	QVERIFY( exp.test(dt(d, 0, 16)));
	QVERIFY(!exp.test(dt(d, 0, 17)));
	QVERIFY(!exp.test(dt(d, 0, 18)));
	QVERIFY(!exp.test(dt(d, 0, 19)));
	QVERIFY( exp.test(dt(d, 0, 20)));
	QVERIFY(!exp.test(dt(d, 0, 21)));
	QVERIFY(!exp.test(dt(d, 0, 22)));
	QVERIFY(!exp.test(dt(d, 0, 23)));
	QVERIFY( exp.test(dt(d, 0, 24)));
	QVERIFY(!exp.test(dt(d, 0, 25)));
	QVERIFY(!exp.test(dt(d, 0, 26)));
	QVERIFY(!exp.test(dt(d, 0, 27)));
	QVERIFY( exp.test(dt(d, 0, 28)));
	QVERIFY(!exp.test(dt(d, 0, 29)));
	QVERIFY(!exp.test(dt(d, 0, 30)));
	QVERIFY(!exp.test(dt(d, 0, 31)));
	QVERIFY( exp.test(dt(d, 0, 32)));
	QVERIFY(!exp.test(dt(d, 0, 33)));
	QVERIFY(!exp.test(dt(d, 0, 34)));
	QVERIFY(!exp.test(dt(d, 0, 35)));
	QVERIFY( exp.test(dt(d, 0, 36)));
	QVERIFY(!exp.test(dt(d, 0, 37)));
	QVERIFY(!exp.test(dt(d, 0, 38)));
	QVERIFY(!exp.test(dt(d, 0, 39)));
	QVERIFY( exp.test(dt(d, 0, 40)));
	QVERIFY(!exp.test(dt(d, 0, 41)));
	QVERIFY(!exp.test(dt(d, 0, 42)));
	QVERIFY(!exp.test(dt(d, 0, 43)));
	QVERIFY( exp.test(dt(d, 0, 44)));
	QVERIFY(!exp.test(dt(d, 0, 45)));
	QVERIFY(!exp.test(dt(d, 0, 46)));
	QVERIFY(!exp.test(dt(d, 0, 47)));
	QVERIFY( exp.test(dt(d, 0, 48)));
	QVERIFY(!exp.test(dt(d, 0, 49)));
	QVERIFY(!exp.test(dt(d, 0, 50)));
	QVERIFY(!exp.test(dt(d, 0, 51)));
	QVERIFY( exp.test(dt(d, 0, 52)));
	QVERIFY(!exp.test(dt(d, 0, 53)));
	QVERIFY(!exp.test(dt(d, 0, 54)));
	QVERIFY(!exp.test(dt(d, 0, 55)));
	QVERIFY( exp.test(dt(d, 0, 56)));
	QVERIFY(!exp.test(dt(d, 0, 57)));
	QVERIFY(!exp.test(dt(d, 0, 58)));
	QVERIFY(!exp.test(dt(d, 0, 59)));
}

void TestCronTimer::test_cronformat_3()
{
	QDate d = QDate::currentDate();
	Qpe::CronTimerExpression exp("20-35/3 4-13/4 * * * *");
	QVERIFY(!exp.test(dt(d,  0, 0)));
	QVERIFY(!exp.test(dt(d,  1, 0)));
	QVERIFY(!exp.test(dt(d,  2, 0)));
	QVERIFY(!exp.test(dt(d,  3, 0)));
	QVERIFY(!exp.test(dt(d,  4, 0)));
	QVERIFY( exp.test(dt(d,  4, 20)));
	QVERIFY( exp.test(dt(d,  4, 23)));
	QVERIFY( exp.test(dt(d,  4, 26)));
	QVERIFY( exp.test(dt(d,  4, 29)));
	QVERIFY( exp.test(dt(d,  4, 32)));
	QVERIFY( exp.test(dt(d,  4, 35)));
	QVERIFY(!exp.test(dt(d,  4, 36)));
	QVERIFY(!exp.test(dt(d,  5, 0)));
	QVERIFY(!exp.test(dt(d,  6, 0)));
	QVERIFY(!exp.test(dt(d,  7, 0)));
	QVERIFY(!exp.test(dt(d,  8, 0)));
	QVERIFY( exp.test(dt(d,  8, 20)));
	QVERIFY( exp.test(dt(d,  8, 23)));
	QVERIFY( exp.test(dt(d,  8, 26)));
	QVERIFY( exp.test(dt(d,  8, 29)));
	QVERIFY( exp.test(dt(d,  8, 32)));
	QVERIFY( exp.test(dt(d,  8, 35)));
	QVERIFY(!exp.test(dt(d,  8, 36)));
	QVERIFY(!exp.test(dt(d,  9, 0)));
	QVERIFY(!exp.test(dt(d, 10, 0)));
	QVERIFY(!exp.test(dt(d, 11, 0)));
	QVERIFY(!exp.test(dt(d, 12, 0)));
	QVERIFY( exp.test(dt(d, 12, 20)));
	QVERIFY( exp.test(dt(d, 12, 23)));
	QVERIFY( exp.test(dt(d, 12, 26)));
	QVERIFY( exp.test(dt(d, 12, 29)));
	QVERIFY( exp.test(dt(d, 12, 32)));
	QVERIFY( exp.test(dt(d, 12, 35)));
	QVERIFY(!exp.test(dt(d, 12, 36)));
	QVERIFY(!exp.test(dt(d, 13, 0)));
	QVERIFY(!exp.test(dt(d, 14, 0)));
	QVERIFY(!exp.test(dt(d, 15, 0)));
	QVERIFY(!exp.test(dt(d, 16, 0)));
	QVERIFY(!exp.test(dt(d, 17, 0)));
	QVERIFY(!exp.test(dt(d, 18, 0)));
	QVERIFY(!exp.test(dt(d, 19, 0)));
	QVERIFY(!exp.test(dt(d, 20, 0)));
	QVERIFY(!exp.test(dt(d, 21, 0)));
	QVERIFY(!exp.test(dt(d, 22, 0)));
	QVERIFY(!exp.test(dt(d, 23, 0)));

}

void TestCronTimer::test_cronformat_4()
{
	Qpe::CronTimerExpression exp("* * * * * *");
	QVERIFY( exp.test(dt( 1, 1)));
	QVERIFY( exp.test(dt( 2, 1)));
	QVERIFY( exp.test(dt( 3, 1)));
	QVERIFY( exp.test(dt( 4, 1)));
	QVERIFY( exp.test(dt( 5, 1)));
	QVERIFY( exp.test(dt( 6, 1)));
	QVERIFY( exp.test(dt( 7, 1)));
	QVERIFY( exp.test(dt( 8, 1)));
	QVERIFY( exp.test(dt( 9, 1)));
	QVERIFY( exp.test(dt(10, 1)));
	QVERIFY( exp.test(dt(11, 1)));
	QVERIFY( exp.test(dt(12, 1)));

	QVERIFY( exp.test(dt(1,  1)));
	QVERIFY( exp.test(dt(1,  2)));
	QVERIFY( exp.test(dt(1,  3)));
	QVERIFY( exp.test(dt(1,  4)));
	QVERIFY( exp.test(dt(1,  5)));
	QVERIFY( exp.test(dt(1,  6)));
	QVERIFY( exp.test(dt(1,  7)));
	QVERIFY( exp.test(dt(1,  8)));
	QVERIFY( exp.test(dt(1,  9)));
	QVERIFY( exp.test(dt(1, 10)));
	QVERIFY( exp.test(dt(1, 11)));
	QVERIFY( exp.test(dt(1, 12)));
	QVERIFY( exp.test(dt(1, 13)));
	QVERIFY( exp.test(dt(1, 14)));
	QVERIFY( exp.test(dt(1, 15)));
	QVERIFY( exp.test(dt(1, 16)));
	QVERIFY( exp.test(dt(1, 17)));
	QVERIFY( exp.test(dt(1, 18)));
	QVERIFY( exp.test(dt(1, 19)));
	QVERIFY( exp.test(dt(1, 20)));
	QVERIFY( exp.test(dt(1, 21)));
	QVERIFY( exp.test(dt(1, 22)));
	QVERIFY( exp.test(dt(1, 23)));
	QVERIFY( exp.test(dt(1, 24)));
	QVERIFY( exp.test(dt(1, 25)));
	QVERIFY( exp.test(dt(1, 26)));
	QVERIFY( exp.test(dt(1, 27)));
	QVERIFY( exp.test(dt(1, 28)));
	QVERIFY( exp.test(dt(1, 29)));
	QVERIFY( exp.test(dt(1, 30)));
	QVERIFY( exp.test(dt(1, 31)));
}

void TestCronTimer::test_cronformat_5()
{
	Qpe::CronTimerExpression exp("* * */3 */4 * *");
	QVERIFY( exp.test(dt( 1, 1)));
	QVERIFY(!exp.test(dt( 2, 1)));
	QVERIFY(!exp.test(dt( 3, 1)));
	QVERIFY(!exp.test(dt( 4, 1)));
	QVERIFY( exp.test(dt( 5, 1)));
	QVERIFY(!exp.test(dt( 6, 1)));
	QVERIFY(!exp.test(dt( 7, 1)));
	QVERIFY(!exp.test(dt( 8, 1)));
	QVERIFY( exp.test(dt( 9, 1)));
	QVERIFY(!exp.test(dt(10, 1)));
	QVERIFY(!exp.test(dt(11, 1)));
	QVERIFY(!exp.test(dt(12, 1)));

	QVERIFY( exp.test(dt(1,  1)));
	QVERIFY(!exp.test(dt(1,  2)));
	QVERIFY(!exp.test(dt(1,  3)));
	QVERIFY( exp.test(dt(1,  4)));
	QVERIFY(!exp.test(dt(1,  5)));
	QVERIFY(!exp.test(dt(1,  6)));
	QVERIFY( exp.test(dt(1,  7)));
	QVERIFY(!exp.test(dt(1,  8)));
	QVERIFY(!exp.test(dt(1,  9)));
	QVERIFY( exp.test(dt(1, 10)));
	QVERIFY(!exp.test(dt(1, 11)));
	QVERIFY(!exp.test(dt(1, 12)));
	QVERIFY( exp.test(dt(1, 13)));
	QVERIFY(!exp.test(dt(1, 14)));
	QVERIFY(!exp.test(dt(1, 15)));
	QVERIFY( exp.test(dt(1, 16)));
	QVERIFY(!exp.test(dt(1, 17)));
	QVERIFY(!exp.test(dt(1, 18)));
	QVERIFY( exp.test(dt(1, 19)));
	QVERIFY(!exp.test(dt(1, 20)));
	QVERIFY(!exp.test(dt(1, 21)));
	QVERIFY( exp.test(dt(1, 22)));
	QVERIFY(!exp.test(dt(1, 23)));
	QVERIFY(!exp.test(dt(1, 24)));
	QVERIFY( exp.test(dt(1, 25)));
	QVERIFY(!exp.test(dt(1, 26)));
	QVERIFY(!exp.test(dt(1, 27)));
	QVERIFY( exp.test(dt(1, 28)));
	QVERIFY(!exp.test(dt(1, 29)));
	QVERIFY(!exp.test(dt(1, 30)));
	QVERIFY( exp.test(dt(1, 31)));
}

void TestCronTimer::test_cronformat_6()
{
	Qpe::CronTimerExpression exp("* * * * 1-5 *");
	QVERIFY( exp.test(dt(5,  1)));
	QVERIFY( exp.test(dt(5,  2)));
	QVERIFY( exp.test(dt(5,  3)));
	QVERIFY(!exp.test(dt(5,  4)));
	QVERIFY(!exp.test(dt(5,  5)));
	QVERIFY( exp.test(dt(5,  6)));
	QVERIFY( exp.test(dt(5,  7)));
	QVERIFY( exp.test(dt(5,  8)));
	QVERIFY( exp.test(dt(5,  9)));
	QVERIFY( exp.test(dt(5, 10)));
	QVERIFY(!exp.test(dt(5, 11)));
	QVERIFY(!exp.test(dt(5, 12)));
	QVERIFY( exp.test(dt(5, 13)));
	QVERIFY( exp.test(dt(5, 14)));
	QVERIFY( exp.test(dt(5, 15)));
	QVERIFY( exp.test(dt(5, 16)));
	QVERIFY( exp.test(dt(5, 17)));
	QVERIFY(!exp.test(dt(5, 18)));
	QVERIFY(!exp.test(dt(5, 19)));
	QVERIFY( exp.test(dt(5, 20)));
	QVERIFY( exp.test(dt(5, 21)));
	QVERIFY( exp.test(dt(5, 22)));
	QVERIFY( exp.test(dt(5, 23)));
	QVERIFY( exp.test(dt(5, 24)));
	QVERIFY(!exp.test(dt(5, 25)));
	QVERIFY(!exp.test(dt(5, 26)));
	QVERIFY( exp.test(dt(5, 27)));
	QVERIFY( exp.test(dt(5, 28)));
	QVERIFY( exp.test(dt(5, 29)));
	QVERIFY( exp.test(dt(5, 30)));
	QVERIFY( exp.test(dt(5, 31)));
}

void TestCronTimer::test_cronformat_7()
{
	Qpe::CronTimerExpression exp("* * * * sat,sun *");
	QVERIFY(exp.isValid());
	QVERIFY(!exp.test(dt(5,  1)));
	QVERIFY(!exp.test(dt(5,  2)));
	QVERIFY(!exp.test(dt(5,  3)));
	QVERIFY( exp.test(dt(5,  4)));
	QVERIFY( exp.test(dt(5,  5)));
	QVERIFY(!exp.test(dt(5,  6)));
	QVERIFY(!exp.test(dt(5,  7)));
	QVERIFY(!exp.test(dt(5,  8)));
	QVERIFY(!exp.test(dt(5,  9)));
	QVERIFY(!exp.test(dt(5, 10)));
	QVERIFY( exp.test(dt(5, 11)));
	QVERIFY( exp.test(dt(5, 12)));
	QVERIFY(!exp.test(dt(5, 13)));
	QVERIFY(!exp.test(dt(5, 14)));
	QVERIFY(!exp.test(dt(5, 15)));
	QVERIFY(!exp.test(dt(5, 16)));
	QVERIFY(!exp.test(dt(5, 17)));
	QVERIFY( exp.test(dt(5, 18)));
	QVERIFY( exp.test(dt(5, 19)));
	QVERIFY(!exp.test(dt(5, 20)));
	QVERIFY(!exp.test(dt(5, 21)));
	QVERIFY(!exp.test(dt(5, 22)));
	QVERIFY(!exp.test(dt(5, 23)));
	QVERIFY(!exp.test(dt(5, 24)));
	QVERIFY( exp.test(dt(5, 25)));
	QVERIFY( exp.test(dt(5, 26)));
	QVERIFY(!exp.test(dt(5, 27)));
	QVERIFY(!exp.test(dt(5, 28)));
	QVERIFY(!exp.test(dt(5, 29)));
	QVERIFY(!exp.test(dt(5, 30)));
	QVERIFY(!exp.test(dt(5, 31)));
}

void TestCronTimer::test_cronformat_8()
{
	Qpe::CronTimerExpression exp("* * * * wed,fri-sun *");
	QVERIFY(exp.isValid());
	QVERIFY( exp.test(dt(5,  1)));
	QVERIFY(!exp.test(dt(5,  2)));
	QVERIFY( exp.test(dt(5,  3)));
	QVERIFY( exp.test(dt(5,  4)));
	QVERIFY( exp.test(dt(5,  5)));
	QVERIFY(!exp.test(dt(5,  6)));
	QVERIFY(!exp.test(dt(5,  7)));
	QVERIFY( exp.test(dt(5,  8)));
	QVERIFY(!exp.test(dt(5,  9)));
	QVERIFY( exp.test(dt(5, 10)));
	QVERIFY( exp.test(dt(5, 11)));
	QVERIFY( exp.test(dt(5, 12)));
	QVERIFY(!exp.test(dt(5, 13)));
	QVERIFY(!exp.test(dt(5, 14)));
	QVERIFY( exp.test(dt(5, 15)));
	QVERIFY(!exp.test(dt(5, 16)));
	QVERIFY( exp.test(dt(5, 17)));
	QVERIFY( exp.test(dt(5, 18)));
	QVERIFY( exp.test(dt(5, 19)));
	QVERIFY(!exp.test(dt(5, 20)));
	QVERIFY(!exp.test(dt(5, 21)));
	QVERIFY( exp.test(dt(5, 22)));
	QVERIFY(!exp.test(dt(5, 23)));
	QVERIFY( exp.test(dt(5, 24)));
	QVERIFY( exp.test(dt(5, 25)));
	QVERIFY( exp.test(dt(5, 26)));
	QVERIFY(!exp.test(dt(5, 27)));
	QVERIFY(!exp.test(dt(5, 28)));
	QVERIFY( exp.test(dt(5, 29)));
	QVERIFY(!exp.test(dt(5, 30)));
	QVERIFY( exp.test(dt(5, 31)));
}

void TestCronTimer::test_cronformat_9()
{
	Qpe::CronTimerExpression exp("* * * * wed,fri-sun/2 *");
	QVERIFY(exp.isValid());
	QVERIFY( exp.test(dt(5,  1)));
	QVERIFY(!exp.test(dt(5,  2)));
	QVERIFY( exp.test(dt(5,  3)));
	QVERIFY(!exp.test(dt(5,  4)));
	QVERIFY( exp.test(dt(5,  5)));
	QVERIFY(!exp.test(dt(5,  6)));
	QVERIFY(!exp.test(dt(5,  7)));
	QVERIFY( exp.test(dt(5,  8)));
	QVERIFY(!exp.test(dt(5,  9)));
	QVERIFY( exp.test(dt(5, 10)));
	QVERIFY(!exp.test(dt(5, 11)));
	QVERIFY( exp.test(dt(5, 12)));
	QVERIFY(!exp.test(dt(5, 13)));
	QVERIFY(!exp.test(dt(5, 14)));
	QVERIFY( exp.test(dt(5, 15)));
	QVERIFY(!exp.test(dt(5, 16)));
	QVERIFY( exp.test(dt(5, 17)));
	QVERIFY(!exp.test(dt(5, 18)));
	QVERIFY( exp.test(dt(5, 19)));
	QVERIFY(!exp.test(dt(5, 20)));
	QVERIFY(!exp.test(dt(5, 21)));
	QVERIFY( exp.test(dt(5, 22)));
	QVERIFY(!exp.test(dt(5, 23)));
	QVERIFY( exp.test(dt(5, 24)));
	QVERIFY(!exp.test(dt(5, 25)));
	QVERIFY( exp.test(dt(5, 26)));
	QVERIFY(!exp.test(dt(5, 27)));
	QVERIFY(!exp.test(dt(5, 28)));
	QVERIFY( exp.test(dt(5, 29)));
	QVERIFY(!exp.test(dt(5, 30)));
	QVERIFY( exp.test(dt(5, 31)));
}

void TestCronTimer::test_cronformat_10()
{
	{
		Qpe::CronTimerExpression exp("* * * feb,nov * *");
		QVERIFY(exp.isValid());
		QVERIFY(!exp.test(dt( 1, 1)));
		QVERIFY( exp.test(dt( 2, 1)));
		QVERIFY(!exp.test(dt( 3, 1)));
		QVERIFY(!exp.test(dt( 4, 1)));
		QVERIFY(!exp.test(dt( 5, 1)));
		QVERIFY(!exp.test(dt( 6, 1)));
		QVERIFY(!exp.test(dt( 7, 1)));
		QVERIFY(!exp.test(dt( 8, 1)));
		QVERIFY(!exp.test(dt( 9, 1)));
		QVERIFY(!exp.test(dt(10, 1)));
		QVERIFY( exp.test(dt(11, 1)));
		QVERIFY(!exp.test(dt(12, 1)));
	}
	{
		Qpe::CronTimerExpression exp("* * * oct-nov * *");
		QVERIFY(exp.isValid());
		QVERIFY(!exp.test(dt( 1, 1)));
		QVERIFY(!exp.test(dt( 2, 1)));
		QVERIFY(!exp.test(dt( 3, 1)));
		QVERIFY(!exp.test(dt( 4, 1)));
		QVERIFY(!exp.test(dt( 5, 1)));
		QVERIFY(!exp.test(dt( 6, 1)));
		QVERIFY(!exp.test(dt( 7, 1)));
		QVERIFY(!exp.test(dt( 8, 1)));
		QVERIFY(!exp.test(dt( 9, 1)));
		QVERIFY( exp.test(dt(10, 1)));
		QVERIFY( exp.test(dt(11, 1)));
		QVERIFY(!exp.test(dt(12, 1)));
	}
	{
		Qpe::CronTimerExpression exp("* * * feb,sep-nov/2 * *");
		QVERIFY(exp.isValid());
		QVERIFY(!exp.test(dt( 1, 1)));
		QVERIFY( exp.test(dt( 2, 1)));
		QVERIFY(!exp.test(dt( 3, 1)));
		QVERIFY(!exp.test(dt( 4, 1)));
		QVERIFY(!exp.test(dt( 5, 1)));
		QVERIFY(!exp.test(dt( 6, 1)));
		QVERIFY(!exp.test(dt( 7, 1)));
		QVERIFY(!exp.test(dt( 8, 1)));
		QVERIFY( exp.test(dt( 9, 1)));
		QVERIFY(!exp.test(dt(10, 1)));
		QVERIFY( exp.test(dt(11, 1)));
		QVERIFY(!exp.test(dt(12, 1)));
	}
	{
		Qpe::CronTimerExpression exp("* * * feb,9-11 * *");
		QVERIFY(exp.isValid());
		QVERIFY(!exp.test(dt( 1, 1)));
		QVERIFY( exp.test(dt( 2, 1)));
		QVERIFY(!exp.test(dt( 3, 1)));
		QVERIFY(!exp.test(dt( 4, 1)));
		QVERIFY(!exp.test(dt( 5, 1)));
		QVERIFY(!exp.test(dt( 6, 1)));
		QVERIFY(!exp.test(dt( 7, 1)));
		QVERIFY(!exp.test(dt( 8, 1)));
		QVERIFY( exp.test(dt( 9, 1)));
		QVERIFY( exp.test(dt(10, 1)));
		QVERIFY( exp.test(dt(11, 1)));
		QVERIFY(!exp.test(dt(12, 1)));
	}
	{
		Qpe::CronTimerExpression exp("* * * feb,9-11/2 * *");
		QVERIFY(exp.isValid());
		QVERIFY(!exp.test(dt( 1, 1)));
		QVERIFY( exp.test(dt( 2, 1)));
		QVERIFY(!exp.test(dt( 3, 1)));
		QVERIFY(!exp.test(dt( 4, 1)));
		QVERIFY(!exp.test(dt( 5, 1)));
		QVERIFY(!exp.test(dt( 6, 1)));
		QVERIFY(!exp.test(dt( 7, 1)));
		QVERIFY(!exp.test(dt( 8, 1)));
		QVERIFY( exp.test(dt( 9, 1)));
		QVERIFY(!exp.test(dt(10, 1)));
		QVERIFY( exp.test(dt(11, 1)));
		QVERIFY(!exp.test(dt(12, 1)));
	}
}

void TestCronTimer::test_cronformat_11()
{
	QDate date = QDate::currentDate();
	QTime time = QTime::currentTime();
	int y = date.year();
	QDateTime d(date, time);
	{
		Qpe::CronTimerExpression exp(QString("* * * * * %1").arg(y - 1));
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y - 1)));
		QVERIFY(!exp.test(dt(d, y)));
		QVERIFY(!exp.test(dt(d, y + 99)));
		QVERIFY(!exp.test(dt(d, y + 100)));
	}
	{
		Qpe::CronTimerExpression exp(QString("* * * * * %1").arg(y));
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y - 1)));
		QVERIFY( exp.test(dt(d, y)));
		QVERIFY(!exp.test(dt(d, y + 99)));
		QVERIFY(!exp.test(dt(d, y + 100)));
	}
	{
		Qpe::CronTimerExpression exp(QString("* * * * * %1").arg(y + 99));
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y - 1)));
		QVERIFY(!exp.test(dt(d, y)));
		QVERIFY( exp.test(dt(d, y + 99)));
		QVERIFY(!exp.test(dt(d, y + 100)));
	}
	{
		Qpe::CronTimerExpression exp(QString("* * * * * %1").arg(y + 100));
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y - 1)));
		QVERIFY(!exp.test(dt(d, y)));
		QVERIFY(!exp.test(dt(d, y + 99)));
		QVERIFY( exp.test(dt(d, y + 100)));
	}
	{
		Qpe::CronTimerExpression exp(QString("* * * * * %1").arg(y + 101));
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y - 1)));
		QVERIFY(!exp.test(dt(d, y)));
		QVERIFY(!exp.test(dt(d, y + 99)));
		QVERIFY(!exp.test(dt(d, y + 100)));
		QVERIFY(!exp.test(dt(d, y + 101)));
	}
	{
		Qpe::CronTimerExpression exp("* * * * * */5");
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, y -   1)));
		QVERIFY( exp.test(dt(d, y +   0)));
		QVERIFY(!exp.test(dt(d, y +   1)));
		QVERIFY(!exp.test(dt(d, y +   2)));
		QVERIFY(!exp.test(dt(d, y +   3)));
		QVERIFY(!exp.test(dt(d, y +   4)));
		QVERIFY( exp.test(dt(d, y +   5)));
		QVERIFY(!exp.test(dt(d, y +   6)));
		QVERIFY(!exp.test(dt(d, y +   7)));
		QVERIFY(!exp.test(dt(d, y +   8)));
		QVERIFY(!exp.test(dt(d, y +   9)));
		QVERIFY( exp.test(dt(d, y +  10)));
		QVERIFY(!exp.test(dt(d, y +  11)));
		QVERIFY( exp.test(dt(d, y +  15)));
		QVERIFY(!exp.test(dt(d, y +  21)));
		QVERIFY(!exp.test(dt(d, y +  99)));
		QVERIFY( exp.test(dt(d, y + 100)));
		QVERIFY(!exp.test(dt(d, y + 101)));
	}
	{
		Qpe::CronTimerExpression exp("* * * * * 2018-2032/5");
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, 2018)));
		QVERIFY(!exp.test(dt(d, 2019)));
		QVERIFY(!exp.test(dt(d, 2020)));
		QVERIFY(!exp.test(dt(d, 2021)));
		QVERIFY(!exp.test(dt(d, 2022)));
		QVERIFY( exp.test(dt(d, 2023)));
		QVERIFY(!exp.test(dt(d, 2024)));
		QVERIFY(!exp.test(dt(d, 2025)));
		QVERIFY(!exp.test(dt(d, 2026)));
		QVERIFY(!exp.test(dt(d, 2027)));
		QVERIFY( exp.test(dt(d, 2028)));
		QVERIFY(!exp.test(dt(d, 2029)));
		QVERIFY(!exp.test(dt(d, 2030)));
		QVERIFY(!exp.test(dt(d, 2031)));
		QVERIFY(!exp.test(dt(d, 2032)));
		QVERIFY(!exp.test(dt(d, 2033)));
	}
	{
		Qpe::CronTimerExpression exp("* * * * * 2018/5");
		QVERIFY( exp.isValid());
		QVERIFY(!exp.test(dt(d, 2018)));
		QVERIFY(!exp.test(dt(d, 2019)));
		QVERIFY(!exp.test(dt(d, 2020)));
		QVERIFY(!exp.test(dt(d, 2021)));
		QVERIFY(!exp.test(dt(d, 2022)));
		QVERIFY( exp.test(dt(d, 2023)));
		QVERIFY(!exp.test(dt(d, 2024)));
		QVERIFY(!exp.test(dt(d, 2025)));
		QVERIFY(!exp.test(dt(d, 2026)));
		QVERIFY(!exp.test(dt(d, 2027)));
		QVERIFY( exp.test(dt(d, 2028)));
		QVERIFY(!exp.test(dt(d, 2029)));
		QVERIFY(!exp.test(dt(d, 2030)));
		QVERIFY(!exp.test(dt(d, 2031)));
		QVERIFY(!exp.test(dt(d, 2032)));
		QVERIFY( exp.test(dt(d, 2033)));
	}
}

void TestCronTimer::test_cronformat_12()
{
	// format without year
	QDate d = QDate::currentDate();
	Qpe::CronTimerExpression exp("20-35/3 4-13/4 * * *");
	QVERIFY( exp.isValid());
	QVERIFY(!exp.test(dt(d,  0, 0)));
	QVERIFY(!exp.test(dt(d,  1, 0)));
	QVERIFY(!exp.test(dt(d,  2, 0)));
	QVERIFY(!exp.test(dt(d,  3, 0)));
	QVERIFY(!exp.test(dt(d,  4, 0)));
	QVERIFY( exp.test(dt(d,  4, 20)));
	QVERIFY( exp.test(dt(d,  4, 23)));
	QVERIFY( exp.test(dt(d,  4, 26)));
	QVERIFY( exp.test(dt(d,  4, 29)));
	QVERIFY( exp.test(dt(d,  4, 32)));
	QVERIFY( exp.test(dt(d,  4, 35)));
	QVERIFY(!exp.test(dt(d,  4, 36)));
	QVERIFY(!exp.test(dt(d,  5, 0)));
	QVERIFY(!exp.test(dt(d,  6, 0)));
	QVERIFY(!exp.test(dt(d,  7, 0)));
	QVERIFY(!exp.test(dt(d,  8, 0)));
	QVERIFY( exp.test(dt(d,  8, 20)));
	QVERIFY( exp.test(dt(d,  8, 23)));
	QVERIFY( exp.test(dt(d,  8, 26)));
	QVERIFY( exp.test(dt(d,  8, 29)));
	QVERIFY( exp.test(dt(d,  8, 32)));
	QVERIFY( exp.test(dt(d,  8, 35)));
	QVERIFY(!exp.test(dt(d,  8, 36)));
	QVERIFY(!exp.test(dt(d,  9, 0)));
	QVERIFY(!exp.test(dt(d, 10, 0)));
	QVERIFY(!exp.test(dt(d, 11, 0)));
	QVERIFY(!exp.test(dt(d, 12, 0)));
	QVERIFY( exp.test(dt(d, 12, 20)));
	QVERIFY( exp.test(dt(d, 12, 23)));
	QVERIFY( exp.test(dt(d, 12, 26)));
	QVERIFY( exp.test(dt(d, 12, 29)));
	QVERIFY( exp.test(dt(d, 12, 32)));
	QVERIFY( exp.test(dt(d, 12, 35)));
	QVERIFY(!exp.test(dt(d, 12, 36)));
	QVERIFY(!exp.test(dt(d, 13, 0)));
	QVERIFY(!exp.test(dt(d, 14, 0)));
	QVERIFY(!exp.test(dt(d, 15, 0)));
	QVERIFY(!exp.test(dt(d, 16, 0)));
	QVERIFY(!exp.test(dt(d, 17, 0)));
	QVERIFY(!exp.test(dt(d, 18, 0)));
	QVERIFY(!exp.test(dt(d, 19, 0)));
	QVERIFY(!exp.test(dt(d, 20, 0)));
	QVERIFY(!exp.test(dt(d, 21, 0)));
	QVERIFY(!exp.test(dt(d, 22, 0)));
	QVERIFY(!exp.test(dt(d, 23, 0)));
}

QTEST_MAIN(TestCronTimer)

#include "test_crontimer.moc"

#include <QtTest/QTest>
#include <QDebug>
#include <QVariant>

#include <Qpe/Qpe>
#include <Qpe/Logger/Logger>

class TestLogger : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void test();
};

void TestLogger::initTestCase()
{
	QString res1 = Qpe::Logger::registerSettings("qpelogger.cfg");
}

void TestLogger::test()
{
	Qpe::Logger logger("TEST", this);
	for (int i = 0; i < 10; ++i) {
//		logger.info(QString("message %1").arg(i));
		logger.info(QString("test message [%1]").arg(i));
	}
	logger.warn("test");

	QTest::qWait(15000);
}

QTEST_MAIN(TestLogger)

#include "test_logger.moc"

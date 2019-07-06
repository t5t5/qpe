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

//	QString res1 = Qpe::Logger::registerSettings("qpelogger.cfg");
	QVariantMap s;
	s["logger.root.appenders"]          = "root";
	s["logger.root.filters"]            = "root";

	s["appender.root.type"]             = "FileAppender";
	s["appender.root.fileName"]         = "log/%d{format=yyyy-MM-dd}/%N__%c.log.txt";
	s["appender.root.pattern"]          = "e:%e{format=10l} (l=%l{format=10l}) [T=%T] %d{format=yyyy-MM-dd HH:mm:ss,zzz} %-6p [%-25.25c] | %m\n";
	s["appender.root.otherLinePattern"] = "e:%-100e{format=10l}| %m\n";

	s["filter.root.type"]               = "EventTypeFilter";
	s["filter.root.eventTypes"]         = "ALL";
	QString res1 = Qpe::Logger::registerSettings("prop.cfg", s);
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

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
	QVariantMap s;
	s["logger.root.appenders"]         = "root";
	s["logger.root.filters"]           = "root";

	s["logger.TEST_SINGLE.appenders"]  = "TEST_SINGLE";
	s["logger.TEST_SINGLE.filters"]    = "root";

	s["logger.TEST_MULTI.appenders"]   = "TEST_MULTI";
	s["logger.TEST_MULTI.filters"]     = "TEST_MULTI";

	s["appender.root.type"]            = "FileAppender";
	s["appender.root.fileName"]        = "log/%d{format=yyyy-MM-dd}/root_%N__%c.log.txt";
	s["appender.root.pattern.0"]       = "e:%e{format=10l} (l=%l{format=10l}) [T=%T] %d{format=yyyy-MM-dd HH:mm:ss,zzz} %-6p [%-25.25c] | %m\n";
	s["appender.root.header"]          = "true";
	s["appender.root.header.pattern"]  = "%40E{padding=-} %T %F %40E{padding=-}\n";

	s["appender.TEST_SINGLE.type"]     = "FileAppender";
	s["appender.TEST_SINGLE.fileName"] = "log/%d{format=yyyy-MM-dd}/%N__%c.log.txt";
	s["appender.TEST_SINGLE.pattern"]  = "e:%e{format=10l} (l=%l{format=10l}) [T=%T] %d{format=yyyy-MM-dd HH:mm:ss,zzz} %-6p [%-25.25c] | %m\n";

	s["appender.TEST_MULTI.type"]      = "FileAppender";
	s["appender.TEST_MULTI.fileName"]  = "log/%d{format=yyyy-MM-dd}/%N__%c.log.txt";
	s["appender.TEST_MULTI.pattern.0"] = "e:%e{format=10l} (l=%l{format=10l}) [T=%T] %d{format=yyyy-MM-dd HH:mm:ss,zzz} %-6p [%-25.25c] | %m\n";
	s["appender.TEST_MULTI.pattern.1"] = "e:%-108e{format=10l}| %m\n";

	s["filter.root.type"]              = "EventTypeFilter";
	s["filter.root.eventTypes"]        = "all";

	s["filter.TEST_MULTI.type"]        = "EventTypeFilter";
	s["filter.TEST_MULTI.eventTypes"]  = "info, warn";

	QString res1 = Qpe::Logger::registerSettings("prop.cfg", s);
}

void TestLogger::test()
{
	Qpe::Logger logger1("TEST_SINGLE", this);
	for (int i = 0; i < 10; ++i) {
		logger1.info(QString("single line\nmessage[%1]").arg(i));
	}
	logger1.warn("test");

	Qpe::Logger logger2("TEST_MULTI", this);
	for (int i = 0; i < 10; ++i) {
		logger2.info(QString("multi\nline\nmessage [%1]").arg(i));
	}
	logger2.warn("test");

	QTest::qWait(15000);
}

QTEST_MAIN(TestLogger)

#include "test_logger.moc"

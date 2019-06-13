#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Qpe>
#include <Qpe/Core/TypeTraits>

class TestTypeTraits : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void test();
};

void TestTypeTraits::initTestCase()
{
}

void TestTypeTraits::test()
{
	{
		typedef Qpe::integer_traits<qint64> num_trait;
		QVERIFY(num_trait::Digits10 == 19);
	}
	{
		typedef Qpe::integer_traits<quint64> num_trait;
		QVERIFY(num_trait::Digits10 == 20);
	}
}

QTEST_MAIN(TestTypeTraits)

#include "test_typetraits.moc"

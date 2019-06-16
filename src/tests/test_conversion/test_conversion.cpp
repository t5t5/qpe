#include <QtTest/QTest>
#include <QDebug>
#include <QVariant>

#include <Qpe/Qpe>

#include <Qpe/Core/ConversionPattern>

class TestConversion : public QObject
{
	Q_OBJECT
private slots:
	void test();
	void test_ConversionPattern();
	void test_SimpleConversionPattern();
};

void TestConversion::test()
{

}

void TestConversion::test_ConversionPattern()
{
	QString pattern = "some %s1{upper;delim=\\;;format=yyyy;} other %-10s2{padding==;char=\\{} text";

	typedef Qpe::ConversionPattern<QVariantMap>	Conversion;

	QVariantMap prop1;
	QVariantMap prop2;

	auto factory = [&prop1, &prop2] (const QString& el, const QVariantMap& prop)
		-> Conversion::ExpressionFunctor
	{
		if (el == "s1") {
			prop1 = prop;
			return [el, prop] (const QVariantMap& data)
			{
				QString value = data.value(el).toString();
				if (prop.value("upper").toBool()) {
					value = value.toUpper();
				}
				return value;
			};
		} else
		if (el == "s2") {
			prop2 = prop;
			return [el, prop] (const QVariantMap& data)
			{
				QString value = data.value(el).toString();
				if (prop.value("upper").toBool()) {
					value = value.toUpper();
				}
				return value;
			};
		};
		return [el, prop] (const QVariantMap& ) { return QString(); };
	};

	Conversion c(pattern, factory);

	QVERIFY(prop1.size() == 3);
	QVERIFY(prop1.value("upper") == QVariant(true));
	QVERIFY(prop1.value("delim") == ";");
	QVERIFY(prop1.value("format") == "yyyy");

	QVERIFY(prop2.value("char") == "{");

	QString s = c.createString(
			QVariantMap({ { "s1", "s1_value"}, { "s2", "s2_value" } }));
	qDebug() << s;
	QVERIFY(s == "some S1_VALUE other s2_value== text");
}

void TestConversion::test_SimpleConversionPattern()
{
	QString pattern = "some %s1{upper;delim=\\;;format=yyyy;} other %-10s2{padding==;char=\\{} text";

	QVariantMap prop1;
	QVariantMap prop2;

	QVariantMap data({ { "s1", "s1_value"}, { "s2", "s2_value" } });

	auto factory = [&prop1, &prop2, data]
		(const QString& el, const QVariantMap& prop)
	{
		if (el == "s1") {
			prop1 = prop;

			QString value = data.value(el).toString();
			if (prop.value("upper").toBool()) {
				value = value.toUpper();
			}
			return value;
		} else
		if (el == "s2") {
			prop2 = prop;
			QString value = data.value(el).toString();
			if (prop.value("upper").toBool()) {
				value = value.toUpper();
			}
			return value;
		}
		return QString();
	};

	Qpe::SimpleConversionPattern c(pattern, factory);

	QVERIFY(prop1.size() == 3);
	QVERIFY(prop1.value("upper") == QVariant(true));
	QVERIFY(prop1.value("delim") == ";");
	QVERIFY(prop1.value("format") == "yyyy");

	QVERIFY(prop2.value("char") == "{");

	QString s = c.createString();
	qDebug() << s;
	QVERIFY(s == "some S1_VALUE other s2_value== text");

}

QTEST_MAIN(TestConversion)

#include "test_conversion.moc"

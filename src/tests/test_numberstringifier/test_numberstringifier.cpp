#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/Stringifier>
#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

class TestNumberStringifier : public QObject
{
	Q_OBJECT
private slots:
	void benchIntStringifierValue();
	void benchIntStaticStringifierValue();
	void benchIntStaticStringifierRef();
	void benchIntDataByteStatic();
	void benchIntDataByteMember();
	void benchIntStdString();

	void testFormatDecChar();
	void testFormatDecCharLz();
	void testFormatDecShort();
	void testFormatDecShortLz();
	void testFormatDecInt();
	void testFormatDecIntLz();
	void testFormatDecLong();
	void testFormatDecLongLz();
	void testFormatDecInt64();
	void testFormatDecInt64Lz();

	void testFormatHexChar();
	void testFormatHexCharUpper();
	void testFormatHexCharLz();
	void testFormatHexCharLzUpper();
	void testFormatHexShort();
	void testFormatHexShortUpper();
	void testFormatHexShortLz();
	void testFormatHexShortLzUpper();
	void testFormatHexInt();
	void testFormatHexIntUpper();
	void testFormatHexIntLz();
	void testFormatHexIntLzUpper();
	void testFormatHexLong();
	void testFormatHexLongUpper();
	void testFormatHexLongLz();
	void testFormatHexLongLzUpper();
	void testFormatHexInt64();
	void testFormatHexInt64Upper();
	void testFormatHexInt64Lz();
	void testFormatHexInt64LzUpper();

	void testFormatHexCharPrefix();
	void testFormatHexCharUpperPrefix();
	void testFormatHexCharLzPrefix();
	void testFormatHexCharLzUpperPrefix();
	void testFormatHexShortPrefix();
	void testFormatHexShortUpperPrefix();
	void testFormatHexShortLzPrefix();
	void testFormatHexShortLzUpperPrefix();
	void testFormatHexIntPrefix();
	void testFormatHexIntUpperPrefix();
	void testFormatHexIntLzPrefix();
	void testFormatHexIntLzUpperPrefix();
	void testFormatHexLongPrefix();
	void testFormatHexLongUpperPrefix();
	void testFormatHexLongLzPrefix();
	void testFormatHexLongLzUpperPrefix();
	void testFormatHexInt64Prefix();
	void testFormatHexInt64UpperPrefix();
	void testFormatHexInt64LzPrefix();
	void testFormatHexInt64LzUpperPrefix();

	void testFormatDecChar_str();
	void testFormatDecCharLz_str();
	void testFormatDecShort_str();
	void testFormatDecShortLz_str();
	void testFormatDecInt_str();
	void testFormatDecIntLz_str();
	void testFormatDecLong_str();
	void testFormatDecLongLz_str();
	void testFormatDecInt64_str();
	void testFormatDecInt64Lz_str();

	void testFormatHexChar_str();
	void testFormatHexCharUpper_str();
	void testFormatHexCharLz_str();
	void testFormatHexCharLzUpper_str();
	void testFormatHexShort_str();
	void testFormatHexShortUpper_str();
	void testFormatHexShortLz_str();
	void testFormatHexShortLzUpper_str();
	void testFormatHexInt_str();
	void testFormatHexIntUpper_str();
	void testFormatHexIntLz_str();
	void testFormatHexIntLzUpper_str();
	void testFormatHexLong_str();
	void testFormatHexLongUpper_str();
	void testFormatHexLongLz_str();
	void testFormatHexLongLzUpper_str();
	void testFormatHexInt64_str();
	void testFormatHexInt64Upper_str();
	void testFormatHexInt64Lz_str();
	void testFormatHexInt64LzUpper_str();

	void testFormatHexCharPrefix_str();
	void testFormatHexCharUpperPrefix_str();
	void testFormatHexCharLzPrefix_str();
	void testFormatHexCharLzUpperPrefix_str();
	void testFormatHexShortPrefix_str();
	void testFormatHexShortUpperPrefix_str();
	void testFormatHexShortLzPrefix_str();
	void testFormatHexShortLzUpperPrefix_str();
	void testFormatHexIntPrefix_str();
	void testFormatHexIntUpperPrefix_str();
	void testFormatHexIntLzPrefix_str();
	void testFormatHexIntLzUpperPrefix_str();
	void testFormatHexLongPrefix_str();
	void testFormatHexLongUpperPrefix_str();
	void testFormatHexLongLzPrefix_str();
	void testFormatHexLongLzUpperPrefix_str();
	void testFormatHexInt64Prefix_str();
	void testFormatHexInt64UpperPrefix_str();
	void testFormatHexInt64LzPrefix_str();
	void testFormatHexInt64LzUpperPrefix_str();
};

void TestNumberStringifier::benchIntStringifierValue()
{
	Qpe::Stringifier st;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += st.format(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::benchIntStaticStringifierValue()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> h;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += h::format(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::benchIntStaticStringifierRef()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> h;

	QByteArray x;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += h::format(i, x).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::benchIntDataByteStatic()
{
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += QByteArray::number(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::benchIntDataByteMember()
{
	QByteArray x;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += x.setNum(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::benchIntStdString()
{
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += std::to_string(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier::testFormatDecChar()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "10");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "99");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "100");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "255");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "255");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "247");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "246");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "10");
	QVERIFY(s.format(static_cast<char>(99), result) == "99");
	QVERIFY(s.format(static_cast<char>(100), result) == "100");
	QVERIFY(s.format(static_cast<char>(127), result) == "127");

	QVERIFY(s.format(static_cast<char>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<char>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<char>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<char>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<char>(-128), result) == "-128");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "10");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "99");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "100");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "127");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<signed char>(-128), result) == "-128");
}

void TestNumberStringifier::testFormatDecCharLz()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "000");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "009");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "010");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "099");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "100");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "255");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "255");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "247");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "246");

	QVERIFY(s.format(static_cast<char>(0), result) == "000");
	QVERIFY(s.format(static_cast<char>(9), result) == "009");
	QVERIFY(s.format(static_cast<char>(10), result) == "010");
	QVERIFY(s.format(static_cast<char>(99), result) == "099");
	QVERIFY(s.format(static_cast<char>(100), result) == "100");
	QVERIFY(s.format(static_cast<char>(127), result) == "127");

	QVERIFY(s.format(static_cast<char>(-1), result) == "-001");
	QVERIFY(s.format(static_cast<char>(-9), result) == "-009");
	QVERIFY(s.format(static_cast<char>(-10), result) == "-010");
	QVERIFY(s.format(static_cast<char>(-99), result) == "-099");
	QVERIFY(s.format(static_cast<char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<char>(-128), result) == "-128");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "000");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "009");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "010");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "099");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "100");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "127");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "-001");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "-009");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "-010");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "-099");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<signed char>(-128), result) == "-128");
}

void TestNumberStringifier::testFormatDecShort()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "10");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "99");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "255");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "256");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "65526");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "10");
	QVERIFY(s.format(static_cast<short>(99), result) == "99");
	QVERIFY(s.format(static_cast<short>(100), result) == "100");
	QVERIFY(s.format(static_cast<short>(255), result) == "255");
	QVERIFY(s.format(static_cast<short>(256), result) == "256");
	QVERIFY(s.format(static_cast<short>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<short>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<short>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<short>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<short>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<short>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<short>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<short>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<short>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "-32767");
}

void TestNumberStringifier::testFormatDecShortLz()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "00000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "00009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "00010");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "00099");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "00100");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00255");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "00256");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "65526");

	QVERIFY(s.format(static_cast<short>(0), result) == "00000");
	QVERIFY(s.format(static_cast<short>(9), result) == "00009");
	QVERIFY(s.format(static_cast<short>(10), result) == "00010");
	QVERIFY(s.format(static_cast<short>(99), result) == "00099");
	QVERIFY(s.format(static_cast<short>(100), result) == "00100");
	QVERIFY(s.format(static_cast<short>(255), result) == "00255");
	QVERIFY(s.format(static_cast<short>(256), result) == "00256");
	QVERIFY(s.format(static_cast<short>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<short>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<short>(-1), result) == "-00001");
	QVERIFY(s.format(static_cast<short>(-9), result) == "-00009");
	QVERIFY(s.format(static_cast<short>(-10), result) == "-00010");
	QVERIFY(s.format(static_cast<short>(-99), result) == "-00099");
	QVERIFY(s.format(static_cast<short>(-100), result) == "-00100");
	QVERIFY(s.format(static_cast<short>(-255), result) == "-00255");
	QVERIFY(s.format(static_cast<short>(-256), result) == "-00256");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "-01000");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "-32767");
}

void TestNumberStringifier::testFormatDecInt()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "10");
	QVERIFY(s.format(static_cast<uint>(99), result) == "99");
	QVERIFY(s.format(static_cast<uint>(100), result) == "100");
	QVERIFY(s.format(static_cast<uint>(255), result) == "255");
	QVERIFY(s.format(static_cast<uint>(256), result) == "256");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "10");
	QVERIFY(s.format(static_cast<int>(99), result) == "99");
	QVERIFY(s.format(static_cast<int>(100), result) == "100");
	QVERIFY(s.format(static_cast<int>(255), result) == "255");
	QVERIFY(s.format(static_cast<int>(256), result) == "256");
	QVERIFY(s.format(static_cast<int>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "-1");

	QVERIFY(s.format(static_cast<int>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<int>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<int>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<int>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<int>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<int>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<int>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatDecIntLz()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<int>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<int>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<int>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<int>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<int>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "-0000000001");

	QVERIFY(s.format(static_cast<int>(-1), result) == "-0000000001");
	QVERIFY(s.format(static_cast<int>(-9), result) == "-0000000009");
	QVERIFY(s.format(static_cast<int>(-10), result) == "-0000000010");
	QVERIFY(s.format(static_cast<int>(-99), result) == "-0000000099");
	QVERIFY(s.format(static_cast<int>(-100), result) == "-0000000100");
	QVERIFY(s.format(static_cast<int>(-255), result) == "-0000000255");
	QVERIFY(s.format(static_cast<int>(-256), result) == "-0000000256");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "-0000001000");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0000000001");
}

void TestNumberStringifier::testFormatDecLong()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "10");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "99");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "255");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "256");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "10");
	QVERIFY(s.format(static_cast<long>(99), result) == "99");
	QVERIFY(s.format(static_cast<long>(100), result) == "100");
	QVERIFY(s.format(static_cast<long>(255), result) == "255");
	QVERIFY(s.format(static_cast<long>(256), result) == "256");
	QVERIFY(s.format(static_cast<long>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "-1");

	QVERIFY(s.format(static_cast<long>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<long>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<long>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<long>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<long>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<long>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<long>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatDecLongLz()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<long>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<long>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<long>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<long>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<long>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "-0000000001");

	QVERIFY(s.format(static_cast<long>(-1), result) == "-0000000001");
	QVERIFY(s.format(static_cast<long>(-9), result) == "-0000000009");
	QVERIFY(s.format(static_cast<long>(-10), result) == "-0000000010");
	QVERIFY(s.format(static_cast<long>(-99), result) == "-0000000099");
	QVERIFY(s.format(static_cast<long>(-100), result) == "-0000000100");
	QVERIFY(s.format(static_cast<long>(-255), result) == "-0000000255");
	QVERIFY(s.format(static_cast<long>(-256), result) == "-0000000256");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "-0000001000");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0000000001");
}

void TestNumberStringifier::testFormatDecInt64()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "10");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "99");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "255");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "256");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "18446744073709551606");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "10");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "99");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "255");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "256");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "-1");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatDecInt64Lz()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "00000000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "00000000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "00000000000000000010");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "00000000000000000099");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "00000000000000000100");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000000255");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "00000000000000000256");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000000001000");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "18446744073709551606");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0000000000000000010");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000000099");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000000100");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0000000000000000255");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000000256");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0000000000000001000");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "-0000000000000000001");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "-0000000000000000001");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "-0000000000000000009");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "-0000000000000000010");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "-0000000000000000099");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "-0000000000000000100");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "-0000000000000000255");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "-0000000000000000256");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "-0000000000000001000");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000000001");
}

void TestNumberStringifier::testFormatHexChar()
{
	// ---- without leading zero
	Qpe::Stringifier s(16);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "ff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "f6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "a");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9c");
}

void TestNumberStringifier::testFormatHexCharUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "FF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "F6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "A");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9C");
}

void TestNumberStringifier::testFormatHexCharLz()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "ff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "f6");

	QVERIFY(s.format(static_cast<char>(0), result) == "00");
	QVERIFY(s.format(static_cast<char>(9), result) == "09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0a");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9c");
}

void TestNumberStringifier::testFormatHexCharLzUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "FF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "F6");

	QVERIFY(s.format(static_cast<char>(0), result) == "00");
	QVERIFY(s.format(static_cast<char>(9), result) == "09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0A");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9C");
}

void TestNumberStringifier::testFormatHexShort()
{
	// ---- without leading zero
	Qpe::Stringifier s(16);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "fff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "a");
	QVERIFY(s.format(static_cast<short>(99), result) == "63");
	QVERIFY(s.format(static_cast<short>(100), result) == "64");
	QVERIFY(s.format(static_cast<short>(255), result) == "ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "FFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "A");
	QVERIFY(s.format(static_cast<short>(99), result) == "63");
	QVERIFY(s.format(static_cast<short>(100), result) == "64");
	QVERIFY(s.format(static_cast<short>(255), result) == "FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortLz()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "000a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "fff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "000a");
	QVERIFY(s.format(static_cast<short>(99), result) == "0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortLzUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "000A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "FFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "000A");
	QVERIFY(s.format(static_cast<short>(99), result) == "0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexInt()
{
	// ---- without leading zero
	Qpe::Stringifier s(16);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "a");
	QVERIFY(s.format(static_cast<int>(99), result) == "63");
	QVERIFY(s.format(static_cast<int>(100), result) == "64");
	QVERIFY(s.format(static_cast<int>(255), result) == "ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexIntUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "A");
	QVERIFY(s.format(static_cast<int>(99), result) == "63");
	QVERIFY(s.format(static_cast<int>(100), result) == "64");
	QVERIFY(s.format(static_cast<int>(255), result) == "FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexIntLz()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<int>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexIntLzUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<int>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexLong()
{
	// ---- without leading zero
	Qpe::Stringifier s(16);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "a");
	QVERIFY(s.format(static_cast<long>(99), result) == "63");
	QVERIFY(s.format(static_cast<long>(100), result) == "64");
	QVERIFY(s.format(static_cast<long>(255), result) == "ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexLongUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "A");
	QVERIFY(s.format(static_cast<long>(99), result) == "63");
	QVERIFY(s.format(static_cast<long>(100), result) == "64");
	QVERIFY(s.format(static_cast<long>(255), result) == "FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexLongLz()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<long>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexLongLzUpper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<long>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexInt64()
{
	// ---- without leading zero
	Qpe::Stringifier s(16);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "fffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatHexInt64Upper()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatHexInt64Lz()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "fffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000001");
}

void TestNumberStringifier::testFormatHexInt64LzUpper()
{
	// ---- with leading zero
	Qpe::Stringifier s(16, true, false, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000001");
}

void TestNumberStringifier::testFormatHexCharPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xf6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<char>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9c");
}

void TestNumberStringifier::testFormatHexCharUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xF6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<char>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9C");
}

void TestNumberStringifier::testFormatHexCharLzPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xf6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9c");
}

void TestNumberStringifier::testFormatHexCharLzUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xF6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9C");
}

void TestNumberStringifier::testFormatHexShortPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xfff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<short>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<short>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xFFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<short>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<short>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortLzPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xfff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortLzUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xFFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexIntPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<int>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<int>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexIntUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<int>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<int>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexIntLzPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexIntLzUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexLongPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<long>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<long>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexLongUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<long>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<long>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexLongLzPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexLongLzUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexInt64Prefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xfffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexInt64UpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, false, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexInt64LzPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xfffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

void TestNumberStringifier::testFormatHexInt64LzUpperPrefix()
{
	// ---- without leading zero
	Qpe::Stringifier s(16, true, true, Qpe::Stringifier::UpperCase);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

void TestNumberStringifier::testFormatDecChar_str()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "10");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "99");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "100");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "255");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "255");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "247");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "246");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "10");
	QVERIFY(s.format(static_cast<char>(99), result) == "99");
	QVERIFY(s.format(static_cast<char>(100), result) == "100");
	QVERIFY(s.format(static_cast<char>(127), result) == "127");

	QVERIFY(s.format(static_cast<char>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<char>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<char>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<char>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<char>(-128), result) == "-128");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "10");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "99");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "100");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "127");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<signed char>(-128), result) == "-128");
}

void TestNumberStringifier::testFormatDecCharLz_str()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "000");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "009");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "010");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "099");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "100");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "255");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "255");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "247");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "246");

	QVERIFY(s.format(static_cast<char>(0), result) == "000");
	QVERIFY(s.format(static_cast<char>(9), result) == "009");
	QVERIFY(s.format(static_cast<char>(10), result) == "010");
	QVERIFY(s.format(static_cast<char>(99), result) == "099");
	QVERIFY(s.format(static_cast<char>(100), result) == "100");
	QVERIFY(s.format(static_cast<char>(127), result) == "127");

	QVERIFY(s.format(static_cast<char>(-1), result) == "-001");
	QVERIFY(s.format(static_cast<char>(-9), result) == "-009");
	QVERIFY(s.format(static_cast<char>(-10), result) == "-010");
	QVERIFY(s.format(static_cast<char>(-99), result) == "-099");
	QVERIFY(s.format(static_cast<char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<char>(-128), result) == "-128");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "000");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "009");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "010");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "099");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "100");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "127");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "-001");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "-009");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "-010");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "-099");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<signed char>(-128), result) == "-128");
}

void TestNumberStringifier::testFormatDecShort_str()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "10");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "99");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "255");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "256");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "65526");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "10");
	QVERIFY(s.format(static_cast<short>(99), result) == "99");
	QVERIFY(s.format(static_cast<short>(100), result) == "100");
	QVERIFY(s.format(static_cast<short>(255), result) == "255");
	QVERIFY(s.format(static_cast<short>(256), result) == "256");
	QVERIFY(s.format(static_cast<short>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<short>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<short>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<short>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<short>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<short>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<short>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<short>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<short>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "-32767");
}

void TestNumberStringifier::testFormatDecShortLz_str()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "00000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "00009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "00010");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "00099");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "00100");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00255");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "00256");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "65526");

	QVERIFY(s.format(static_cast<short>(0), result) == "00000");
	QVERIFY(s.format(static_cast<short>(9), result) == "00009");
	QVERIFY(s.format(static_cast<short>(10), result) == "00010");
	QVERIFY(s.format(static_cast<short>(99), result) == "00099");
	QVERIFY(s.format(static_cast<short>(100), result) == "00100");
	QVERIFY(s.format(static_cast<short>(255), result) == "00255");
	QVERIFY(s.format(static_cast<short>(256), result) == "00256");
	QVERIFY(s.format(static_cast<short>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<short>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<short>(-1), result) == "-00001");
	QVERIFY(s.format(static_cast<short>(-9), result) == "-00009");
	QVERIFY(s.format(static_cast<short>(-10), result) == "-00010");
	QVERIFY(s.format(static_cast<short>(-99), result) == "-00099");
	QVERIFY(s.format(static_cast<short>(-100), result) == "-00100");
	QVERIFY(s.format(static_cast<short>(-255), result) == "-00255");
	QVERIFY(s.format(static_cast<short>(-256), result) == "-00256");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "-01000");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "-32767");
}

void TestNumberStringifier::testFormatDecInt_str()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "10");
	QVERIFY(s.format(static_cast<uint>(99), result) == "99");
	QVERIFY(s.format(static_cast<uint>(100), result) == "100");
	QVERIFY(s.format(static_cast<uint>(255), result) == "255");
	QVERIFY(s.format(static_cast<uint>(256), result) == "256");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "10");
	QVERIFY(s.format(static_cast<int>(99), result) == "99");
	QVERIFY(s.format(static_cast<int>(100), result) == "100");
	QVERIFY(s.format(static_cast<int>(255), result) == "255");
	QVERIFY(s.format(static_cast<int>(256), result) == "256");
	QVERIFY(s.format(static_cast<int>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "-1");

	QVERIFY(s.format(static_cast<int>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<int>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<int>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<int>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<int>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<int>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<int>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatDecIntLz_str()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<int>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<int>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<int>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<int>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<int>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "-0000000001");

	QVERIFY(s.format(static_cast<int>(-1), result) == "-0000000001");
	QVERIFY(s.format(static_cast<int>(-9), result) == "-0000000009");
	QVERIFY(s.format(static_cast<int>(-10), result) == "-0000000010");
	QVERIFY(s.format(static_cast<int>(-99), result) == "-0000000099");
	QVERIFY(s.format(static_cast<int>(-100), result) == "-0000000100");
	QVERIFY(s.format(static_cast<int>(-255), result) == "-0000000255");
	QVERIFY(s.format(static_cast<int>(-256), result) == "-0000000256");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "-0000001000");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0000000001");
}

void TestNumberStringifier::testFormatDecLong_str()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "10");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "99");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "255");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "256");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "10");
	QVERIFY(s.format(static_cast<long>(99), result) == "99");
	QVERIFY(s.format(static_cast<long>(100), result) == "100");
	QVERIFY(s.format(static_cast<long>(255), result) == "255");
	QVERIFY(s.format(static_cast<long>(256), result) == "256");
	QVERIFY(s.format(static_cast<long>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "-1");

	QVERIFY(s.format(static_cast<long>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<long>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<long>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<long>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<long>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<long>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<long>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatDecLongLz_str()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "4294967286");

	QVERIFY(s.format(static_cast<long>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<long>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<long>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<long>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<long>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "-0000000001");

	QVERIFY(s.format(static_cast<long>(-1), result) == "-0000000001");
	QVERIFY(s.format(static_cast<long>(-9), result) == "-0000000009");
	QVERIFY(s.format(static_cast<long>(-10), result) == "-0000000010");
	QVERIFY(s.format(static_cast<long>(-99), result) == "-0000000099");
	QVERIFY(s.format(static_cast<long>(-100), result) == "-0000000100");
	QVERIFY(s.format(static_cast<long>(-255), result) == "-0000000255");
	QVERIFY(s.format(static_cast<long>(-256), result) == "-0000000256");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "-0000001000");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0000000001");
}

void TestNumberStringifier::testFormatDecInt64_str()
{
	// ---- without leading zero
	Qpe::Stringifier s(10);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "10");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "99");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "255");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "256");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "18446744073709551606");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "10");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "99");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "255");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "256");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "-1");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatDecInt64Lz_str()
{
	// ---- with leading zero
	Qpe::Stringifier s(10, true);
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "00000000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "00000000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "00000000000000000010");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "00000000000000000099");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "00000000000000000100");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000000255");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "00000000000000000256");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000000001000");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "18446744073709551606");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0000000000000000010");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000000099");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000000100");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0000000000000000255");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000000256");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0000000000000001000");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "-0000000000000000001");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "-0000000000000000001");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "-0000000000000000009");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "-0000000000000000010");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "-0000000000000000099");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "-0000000000000000100");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "-0000000000000000255");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "-0000000000000000256");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "-0000000000000001000");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000000001");
}

void TestNumberStringifier::testFormatHexChar_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "ff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "f6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "a");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9c");
}

void TestNumberStringifier::testFormatHexCharUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16u");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "FF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "F6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0");
	QVERIFY(s.format(static_cast<char>(9), result) == "9");
	QVERIFY(s.format(static_cast<char>(10), result) == "A");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9C");
}

void TestNumberStringifier::testFormatHexCharLz_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16l");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "ff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "f6");

	QVERIFY(s.format(static_cast<char>(0), result) == "00");
	QVERIFY(s.format(static_cast<char>(9), result) == "09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0a");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9c");
}

void TestNumberStringifier::testFormatHexCharLzUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lu");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "FF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "F6");

	QVERIFY(s.format(static_cast<char>(0), result) == "00");
	QVERIFY(s.format(static_cast<char>(9), result) == "09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0A");
	QVERIFY(s.format(static_cast<char>(99), result) == "63");
	QVERIFY(s.format(static_cast<char>(100), result) == "64");
	QVERIFY(s.format(static_cast<char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "9C");
}

void TestNumberStringifier::testFormatHexShort_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "fff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "a");
	QVERIFY(s.format(static_cast<short>(99), result) == "63");
	QVERIFY(s.format(static_cast<short>(100), result) == "64");
	QVERIFY(s.format(static_cast<short>(255), result) == "ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16u");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "FFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0");
	QVERIFY(s.format(static_cast<short>(9), result) == "9");
	QVERIFY(s.format(static_cast<short>(10), result) == "A");
	QVERIFY(s.format(static_cast<short>(99), result) == "63");
	QVERIFY(s.format(static_cast<short>(100), result) == "64");
	QVERIFY(s.format(static_cast<short>(255), result) == "FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortLz_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16l");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "000a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "fff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "000a");
	QVERIFY(s.format(static_cast<short>(99), result) == "0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexShortLzUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lu");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "000A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "FFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "000A");
	QVERIFY(s.format(static_cast<short>(99), result) == "0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "8001");
}

void TestNumberStringifier::testFormatHexInt_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "a");
	QVERIFY(s.format(static_cast<int>(99), result) == "63");
	QVERIFY(s.format(static_cast<int>(100), result) == "64");
	QVERIFY(s.format(static_cast<int>(255), result) == "ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexIntUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16u");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0");
	QVERIFY(s.format(static_cast<int>(9), result) == "9");
	QVERIFY(s.format(static_cast<int>(10), result) == "A");
	QVERIFY(s.format(static_cast<int>(99), result) == "63");
	QVERIFY(s.format(static_cast<int>(100), result) == "64");
	QVERIFY(s.format(static_cast<int>(255), result) == "FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexIntLz_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16l");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<int>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexIntLzUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lu");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<int>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexLong_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "a");
	QVERIFY(s.format(static_cast<long>(99), result) == "63");
	QVERIFY(s.format(static_cast<long>(100), result) == "64");
	QVERIFY(s.format(static_cast<long>(255), result) == "ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexLongUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16u");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0");
	QVERIFY(s.format(static_cast<long>(9), result) == "9");
	QVERIFY(s.format(static_cast<long>(10), result) == "A");
	QVERIFY(s.format(static_cast<long>(99), result) == "63");
	QVERIFY(s.format(static_cast<long>(100), result) == "64");
	QVERIFY(s.format(static_cast<long>(255), result) == "FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "1");
}

void TestNumberStringifier::testFormatHexLongLz_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16l");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "fffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<long>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexLongLzUpper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lu");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "FFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<long>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "00000001");
}

void TestNumberStringifier::testFormatHexInt64_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "fffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatHexInt64Upper_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16u");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "1");
}

void TestNumberStringifier::testFormatHexInt64Lz_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16l");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "fffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000001");
}

void TestNumberStringifier::testFormatHexInt64LzUpper_str()
{
	// ---- with leading zero
	Qpe::Stringifier s("16lu");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0000000000000001");
}

void TestNumberStringifier::testFormatHexCharPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16p");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xf6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<char>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9c");
}

void TestNumberStringifier::testFormatHexCharUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16pu");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xF6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<char>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9C");
}

void TestNumberStringifier::testFormatHexCharLzPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lp");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xf6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9c");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9c");
}

void TestNumberStringifier::testFormatHexCharLzUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16plu");
	QString result;
	QVERIFY(s.format(static_cast<uchar>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<uchar>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<uchar>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<uchar>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uchar>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uchar>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<uchar>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<uchar>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<uchar>(-10), result) == "0xF6");

	QVERIFY(s.format(static_cast<char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<char>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<char>(-100), result) == "0x9C");

	QVERIFY(s.format(static_cast<signed char>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<signed char>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<signed char>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<signed char>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<signed char>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<signed char>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<signed char>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<signed char>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<signed char>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<signed char>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<signed char>(-100), result) == "0x9C");
}

void TestNumberStringifier::testFormatHexShortPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16p");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xfff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<short>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<short>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16up");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xFFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<short>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<short>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortLzPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16pl");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xfff6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexShortLzUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16upl");
	QString result;
	QVERIFY(s.format(static_cast<ushort>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<ushort>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<ushort>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<ushort>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<ushort>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<ushort>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<ushort>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<ushort>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<ushort>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<ushort>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<ushort>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<ushort>(-10), result) == "0xFFF6");

	QVERIFY(s.format(static_cast<short>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<short>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<short>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<short>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<short>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<short>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<short>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<short>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<short>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<short>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<short>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<short>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<short>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<short>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<short>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<short>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<short>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<short>(-32767), result) == "0x8001");
}

void TestNumberStringifier::testFormatHexIntPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16p");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<int>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<int>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexIntUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16pu");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<int>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<int>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexIntLzPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lp");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexIntLzUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16ulp");
	QString result;
	QVERIFY(s.format(static_cast<uint>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<uint>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<uint>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<uint>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<uint>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<uint>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<uint>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<uint>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<uint>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<uint>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<uint>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<uint>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<int>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<int>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<int>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<int>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<int>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<int>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<int>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<int>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<int>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<int>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<int>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<int>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<int>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<int>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<int>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<int>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<int>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<int>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<int>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<int>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexLongPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16p");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<long>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<long>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexLongUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16pu");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<long>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<long>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexLongLzPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lp");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xfffffff6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexLongLzUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16upl");
	QString result;
	QVERIFY(s.format(static_cast<ulong>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<ulong>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<ulong>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<ulong>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<ulong>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<ulong>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<ulong>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<ulong>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<ulong>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<ulong>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<ulong>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<ulong>(-10), result) == "0xFFFFFFF6");

	QVERIFY(s.format(static_cast<long>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<long>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<long>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<long>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<long>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<long>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<long>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<long>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<long>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<long>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<long>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<long>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<long>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<long>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<long>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<long>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<long>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<long>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<long>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<long>(0-4294967295UL), result) == "0x00000001");
}

void TestNumberStringifier::testFormatHexInt64Prefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16p");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xfffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexInt64UpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16pu");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x1");
}

void TestNumberStringifier::testFormatHexInt64LzPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lp");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xfffffffffffffff6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

void TestNumberStringifier::testFormatHexInt64LzUpperPrefix_str()
{
	// ---- without leading zero
	Qpe::Stringifier s("16lup");
	QString result;
	QVERIFY(s.format(static_cast<quint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<quint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<quint64>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<quint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<quint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<quint64>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<quint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<quint64>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<quint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<quint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<quint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<quint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s.format(static_cast<qint64>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<qint64>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<qint64>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<qint64>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<qint64>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<qint64>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<qint64>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<qint64>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<qint64>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<qint64>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<qint64>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<qint64>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<qint64>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<qint64>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<qint64>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<qint64>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<qint64>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<qint64>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<qint64>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}


QTEST_MAIN(TestNumberStringifier)
#include "test_numberstringifier.moc"

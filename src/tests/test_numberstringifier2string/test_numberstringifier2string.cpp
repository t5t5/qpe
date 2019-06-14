#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/StaticStringifierDec>
//#include <Qpe/Core/Static/StringifierDec2Digits>
//#include <Qpe/Core/Static/StringifierDec3Digits>
//#include <Qpe/Core/Static/StringifierDec4Digits>
#include <Qpe/Core/StaticStringifierHex>

//#include <Qpe/Core/Stringifier>

class TestNumberStringifier2String : public QObject
{
	Q_OBJECT
private slots:
//	void benchIntStringifierValue();
	void benchIntStaticStringifier_ByteArray();
	void benchIntStaticStringifier_ByteArray_ref();
	void benchIntByteArray_number_static();
	void benchIntByteArray_setNum();

	void benchIntStaticStringifier_QString_ref();

	void benchIntQString_number_static();
	void benchIntQString_setNum();

	void testStaticFormatDecAddress();
	void testStaticFormatHexAddress();

	void testStaticFormatDecChar();
	void testStaticFormatDecCharLz();
	void testStaticFormatDecShort();
	void testStaticFormatDecShortLz();
	void testStaticFormatDecInt();
	void testStaticFormatDecIntLz();
	void testStaticFormatDecLong();
	void testStaticFormatDecLongLz();
	void testStaticFormatDecInt64();
	void testStaticFormatDecInt64Lz();

	void testStaticFormatDec2DigitsChar();
	void testStaticFormatDec2DigitsShort();
	void testStaticFormatDec2DigitsInt();
	void testStaticFormatDec2DigitsLong();
	void testStaticFormatDec2DigitsInt64();

	void testStaticFormatDec3DigitsChar();
	void testStaticFormatDec3DigitsShort();
	void testStaticFormatDec3DigitsInt();
	void testStaticFormatDec3DigitsLong();
	void testStaticFormatDec3DigitsInt64();

	void testStaticFormatDec4DigitsChar();
	void testStaticFormatDec4DigitsShort();
	void testStaticFormatDec4DigitsInt();
	void testStaticFormatDec4DigitsLong();
	void testStaticFormatDec4DigitsInt64();

	void testStaticFormatHexChar();
	void testStaticFormatHexCharUpper();
	void testStaticFormatHexCharLz();
	void testStaticFormatHexCharLzUpper();
	void testStaticFormatHexShort();
	void testStaticFormatHexShortUpper();
	void testStaticFormatHexShortLz();
	void testStaticFormatHexShortLzUpper();
	void testStaticFormatHexInt();
	void testStaticFormatHexIntUpper();
	void testStaticFormatHexIntLz();
	void testStaticFormatHexIntLzUpper();
	void testStaticFormatHexLong();
	void testStaticFormatHexLongUpper();
	void testStaticFormatHexLongLz();
	void testStaticFormatHexLongLzUpper();
	void testStaticFormatHexInt64();
	void testStaticFormatHexInt64Upper();
	void testStaticFormatHexInt64Lz();
	void testStaticFormatHexInt64LzUpper();

	void testStaticFormatHexCharPrefix();
	void testStaticFormatHexCharUpperPrefix();
	void testStaticFormatHexCharLzPrefix();
	void testStaticFormatHexCharLzUpperPrefix();
	void testStaticFormatHexShortPrefix();
	void testStaticFormatHexShortUpperPrefix();
	void testStaticFormatHexShortLzPrefix();
	void testStaticFormatHexShortLzUpperPrefix();
	void testStaticFormatHexIntPrefix();
	void testStaticFormatHexIntUpperPrefix();
	void testStaticFormatHexIntLzPrefix();
	void testStaticFormatHexIntLzUpperPrefix();
	void testStaticFormatHexLongPrefix();
	void testStaticFormatHexLongUpperPrefix();
	void testStaticFormatHexLongLzPrefix();
	void testStaticFormatHexLongLzUpperPrefix();
	void testStaticFormatHexInt64Prefix();
	void testStaticFormatHexInt64UpperPrefix();
	void testStaticFormatHexInt64LzPrefix();
	void testStaticFormatHexInt64LzUpperPrefix();
};

//void TestNumberStringifier2String::benchIntStringifierValue()
//{
//	Qpe::Stringifier st;
//	int n = 0;
//	QBENCHMARK {
//		for (int i = -500000; i <= 500000; ++i) {
//			n += st.format(i).size();
//		}
//	}
//	qDebug() << n;
//}

void TestNumberStringifier2String::benchIntStaticStringifier_ByteArray()
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

void TestNumberStringifier2String::benchIntStaticStringifier_ByteArray_ref()
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

void TestNumberStringifier2String::benchIntByteArray_number_static()
{
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += QByteArray::number(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier2String::benchIntByteArray_setNum()
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

void TestNumberStringifier2String::benchIntStaticStringifier_QString_ref()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> h;

	QString x;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += h::format(i, x).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier2String::benchIntQString_number_static()
{
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += QString::number(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier2String::benchIntQString_setNum()
{
	QString x;
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += x.setNum(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier2String::testStaticFormatDecAddress()
{
	int n = 0;
	int* address = &n;

	QString s1;

	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;

	s::format(address, s1);

	QString s2 = QString::number(reinterpret_cast<quintptr>(address));

	QVERIFY(s1 == s2);
}

void TestNumberStringifier2String::testStaticFormatHexAddress()
{
	int n = 0;
	int* address = &n;

	QString s1;

	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;

	s::format(address, s1);

	QString s2 = QString::number(reinterpret_cast<quintptr>(address), 16);

	QVERIFY(s1 == s2);
}

void TestNumberStringifier2String::testStaticFormatDecChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0");
	QVERIFY(s::format<uchar>(9, result) == "9");
	QVERIFY(s::format<uchar>(10, result) == "10");
	QVERIFY(s::format<uchar>(99, result) == "99");
	QVERIFY(s::format<uchar>(100, result) == "100");
	QVERIFY(s::format<uchar>(255, result) == "255");

	QVERIFY(s::format<uchar>(-1, result) == "255");
	QVERIFY(s::format<uchar>(-9, result) == "247");
	QVERIFY(s::format<uchar>(-10, result) == "246");

	QVERIFY(s::format<char>(0, result) == "0");
	QVERIFY(s::format<char>(9, result) == "9");
	QVERIFY(s::format<char>(10, result) == "10");
	QVERIFY(s::format<char>(99, result) == "99");
	QVERIFY(s::format<char>(100, result) == "100");
	QVERIFY(s::format<char>(127, result) == "127");

	QVERIFY(s::format<char>(-1, result) == "-1");
	QVERIFY(s::format<char>(-9, result) == "-9");
	QVERIFY(s::format<char>(-10, result) == "-10");
	QVERIFY(s::format<char>(-99, result) == "-99");
	QVERIFY(s::format<char>(-100, result) == "-100");
//	QVERIFY(s::format<char>(-128, result) == "-128");

	QVERIFY(s::format<signed char>(0, result) == "0");
	QVERIFY(s::format<signed char>(9, result) == "9");
	QVERIFY(s::format<signed char>(10, result) == "10");
	QVERIFY(s::format<signed char>(99, result) == "99");
	QVERIFY(s::format<signed char>(100, result) == "100");
	QVERIFY(s::format<signed char>(127, result) == "127");

	QVERIFY(s::format<signed char>(-1, result) == "-1");
	QVERIFY(s::format<signed char>(-9, result) == "-9");
	QVERIFY(s::format<signed char>(-10, result) == "-10");
	QVERIFY(s::format<signed char>(-99, result) == "-99");
	QVERIFY(s::format<signed char>(-100, result) == "-100");
//	QVERIFY(s::format<signed char>(-128, result) == "-128");
}

void TestNumberStringifier2String::testStaticFormatDecCharLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "000");
	QVERIFY(s::format<uchar>(9, result) == "009");
	QVERIFY(s::format<uchar>(10, result) == "010");
	QVERIFY(s::format<uchar>(99, result) == "099");
	QVERIFY(s::format<uchar>(100, result) == "100");
	QVERIFY(s::format<uchar>(255, result) == "255");

	QVERIFY(s::format<uchar>(-1, result) == "255");
	QVERIFY(s::format<uchar>(-9, result) == "247");
	QVERIFY(s::format<uchar>(-10, result) == "246");

	QVERIFY(s::format<char>(0, result) == "000");
	QVERIFY(s::format<char>(9, result) == "009");
	QVERIFY(s::format<char>(10, result) == "010");
	QVERIFY(s::format<char>(99, result) == "099");
	QVERIFY(s::format<char>(100, result) == "100");
	QVERIFY(s::format<char>(127, result) == "127");

	QVERIFY(s::format<char>(-1, result) == "-001");
	QVERIFY(s::format<char>(-9, result) == "-009");
	QVERIFY(s::format<char>(-10, result) == "-010");
	QVERIFY(s::format<char>(-99, result) == "-099");
	QVERIFY(s::format<char>(-100, result) == "-100");
//	QVERIFY(s::format<char>(-128, result) == "-128");

	QVERIFY(s::format<signed char>(0, result) == "000");
	QVERIFY(s::format<signed char>(9, result) == "009");
	QVERIFY(s::format<signed char>(10, result) == "010");
	QVERIFY(s::format<signed char>(99, result) == "099");
	QVERIFY(s::format<signed char>(100, result) == "100");
	QVERIFY(s::format<signed char>(127, result) == "127");

	QVERIFY(s::format<signed char>(-1, result) == "-001");
	QVERIFY(s::format<signed char>(-9, result) == "-009");
	QVERIFY(s::format<signed char>(-10, result) == "-010");
	QVERIFY(s::format<signed char>(-99, result) == "-099");
	QVERIFY(s::format<signed char>(-100, result) == "-100");
//	QVERIFY(s::format<signed char>(-128, result) == "-128");
}

void TestNumberStringifier2String::testStaticFormatDecShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0");
	QVERIFY(s::format<ushort>(9, result) == "9");
	QVERIFY(s::format<ushort>(10, result) == "10");
	QVERIFY(s::format<ushort>(99, result) == "99");
	QVERIFY(s::format<ushort>(100, result) == "100");
	QVERIFY(s::format<ushort>(255, result) == "255");
	QVERIFY(s::format<ushort>(256, result) == "256");
	QVERIFY(s::format<ushort>(1000, result) == "1000");
	QVERIFY(s::format<ushort>(65535, result) == "65535");

	QVERIFY(s::format<ushort>(-1, result) == "65535");
	QVERIFY(s::format<ushort>(-9, result) == "65527");
	QVERIFY(s::format<ushort>(-10, result) == "65526");

	QVERIFY(s::format<short>(0, result) == "0");
	QVERIFY(s::format<short>(9, result) == "9");
	QVERIFY(s::format<short>(10, result) == "10");
	QVERIFY(s::format<short>(99, result) == "99");
	QVERIFY(s::format<short>(100, result) == "100");
	QVERIFY(s::format<short>(255, result) == "255");
	QVERIFY(s::format<short>(256, result) == "256");
	QVERIFY(s::format<short>(1000, result) == "1000");
	QVERIFY(s::format<short>(32767, result) == "32767");

	QVERIFY(s::format<short>(-1, result) == "-1");
	QVERIFY(s::format<short>(-9, result) == "-9");
	QVERIFY(s::format<short>(-10, result) == "-10");
	QVERIFY(s::format<short>(-99, result) == "-99");
	QVERIFY(s::format<short>(-100, result) == "-100");
	QVERIFY(s::format<short>(-255, result) == "-255");
	QVERIFY(s::format<short>(-256, result) == "-256");
	QVERIFY(s::format<short>(-1000, result) == "-1000");
	QVERIFY(s::format<short>(-32767, result) == "-32767");
}

void TestNumberStringifier2String::testStaticFormatDecShortLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "00000");
	QVERIFY(s::format<ushort>(9, result) == "00009");
	QVERIFY(s::format<ushort>(10, result) == "00010");
	QVERIFY(s::format<ushort>(99, result) == "00099");
	QVERIFY(s::format<ushort>(100, result) == "00100");
	QVERIFY(s::format<ushort>(255, result) == "00255");
	QVERIFY(s::format<ushort>(256, result) == "00256");
	QVERIFY(s::format<ushort>(1000, result) == "01000");
	QVERIFY(s::format<ushort>(65535, result) == "65535");

	QVERIFY(s::format<ushort>(-1, result) == "65535");
	QVERIFY(s::format<ushort>(-9, result) == "65527");
	QVERIFY(s::format<ushort>(-10, result) == "65526");

	QVERIFY(s::format<short>(0, result) == "00000");
	QVERIFY(s::format<short>(9, result) == "00009");
	QVERIFY(s::format<short>(10, result) == "00010");
	QVERIFY(s::format<short>(99, result) == "00099");
	QVERIFY(s::format<short>(100, result) == "00100");
	QVERIFY(s::format<short>(255, result) == "00255");
	QVERIFY(s::format<short>(256, result) == "00256");
	QVERIFY(s::format<short>(1000, result) == "01000");
	QVERIFY(s::format<short>(32767, result) == "32767");

	QVERIFY(s::format<short>(-1, result) == "-00001");
	QVERIFY(s::format<short>(-9, result) == "-00009");
	QVERIFY(s::format<short>(-10, result) == "-00010");
	QVERIFY(s::format<short>(-99, result) == "-00099");
	QVERIFY(s::format<short>(-100, result) == "-00100");
	QVERIFY(s::format<short>(-255, result) == "-00255");
	QVERIFY(s::format<short>(-256, result) == "-00256");
	QVERIFY(s::format<short>(-1000, result) == "-01000");
	QVERIFY(s::format<short>(-32767, result) == "-32767");
}

void TestNumberStringifier2String::testStaticFormatDecInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0");
	QVERIFY(s::format<uint>(9, result) == "9");
	QVERIFY(s::format<uint>(10, result) == "10");
	QVERIFY(s::format<uint>(99, result) == "99");
	QVERIFY(s::format<uint>(100, result) == "100");
	QVERIFY(s::format<uint>(255, result) == "255");
	QVERIFY(s::format<uint>(256, result) == "256");
	QVERIFY(s::format<uint>(1000, result) == "1000");
	QVERIFY(s::format<uint>(4294967295, result) == "4294967295");

	QVERIFY(s::format<uint>(-1, result) == "4294967295");
	QVERIFY(s::format<uint>(-9, result) == "4294967287");
	QVERIFY(s::format<uint>(-10, result) == "4294967286");

	QVERIFY(s::format<int>(0, result) == "0");
	QVERIFY(s::format<int>(9, result) == "9");
	QVERIFY(s::format<int>(10, result) == "10");
	QVERIFY(s::format<int>(99, result) == "99");
	QVERIFY(s::format<int>(100, result) == "100");
	QVERIFY(s::format<int>(255, result) == "255");
	QVERIFY(s::format<int>(256, result) == "256");
	QVERIFY(s::format<int>(1000, result) == "1000");
	QVERIFY(s::format<int>(2147483647, result) == "2147483647");
	QVERIFY(s::format<int>(4294967295, result) == "-1");

	QVERIFY(s::format<int>(-1, result) == "-1");
	QVERIFY(s::format<int>(-9, result) == "-9");
	QVERIFY(s::format<int>(-10, result) == "-10");
	QVERIFY(s::format<int>(-99, result) == "-99");
	QVERIFY(s::format<int>(-100, result) == "-100");
	QVERIFY(s::format<int>(-255, result) == "-255");
	QVERIFY(s::format<int>(-256, result) == "-256");
	QVERIFY(s::format<int>(-1000, result) == "-1000");
	QVERIFY(s::format<int>(-2147483647, result) == "-2147483647");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatDecIntLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0000000000");
	QVERIFY(s::format<uint>(9, result) == "0000000009");
	QVERIFY(s::format<uint>(10, result) == "0000000010");
	QVERIFY(s::format<uint>(99, result) == "0000000099");
	QVERIFY(s::format<uint>(100, result) == "0000000100");
	QVERIFY(s::format<uint>(255, result) == "0000000255");
	QVERIFY(s::format<uint>(256, result) == "0000000256");
	QVERIFY(s::format<uint>(1000, result) == "0000001000");
	QVERIFY(s::format<uint>(4294967295, result) == "4294967295");

	QVERIFY(s::format<uint>(-1, result) == "4294967295");
	QVERIFY(s::format<uint>(-9, result) == "4294967287");
	QVERIFY(s::format<uint>(-10, result) == "4294967286");

	QVERIFY(s::format<int>(0, result) == "0000000000");
	QVERIFY(s::format<int>(9, result) == "0000000009");
	QVERIFY(s::format<int>(10, result) == "0000000010");
	QVERIFY(s::format<int>(99, result) == "0000000099");
	QVERIFY(s::format<int>(100, result) == "0000000100");
	QVERIFY(s::format<int>(255, result) == "0000000255");
	QVERIFY(s::format<int>(256, result) == "0000000256");
	QVERIFY(s::format<int>(1000, result) == "0000001000");
	QVERIFY(s::format<int>(2147483647, result) == "2147483647");
	QVERIFY(s::format<int>(4294967295, result) == "-0000000001");

	QVERIFY(s::format<int>(-1, result) == "-0000000001");
	QVERIFY(s::format<int>(-9, result) == "-0000000009");
	QVERIFY(s::format<int>(-10, result) == "-0000000010");
	QVERIFY(s::format<int>(-99, result) == "-0000000099");
	QVERIFY(s::format<int>(-100, result) == "-0000000100");
	QVERIFY(s::format<int>(-255, result) == "-0000000255");
	QVERIFY(s::format<int>(-256, result) == "-0000000256");
	QVERIFY(s::format<int>(-1000, result) == "-0000001000");
	QVERIFY(s::format<int>(-2147483647, result) == "-2147483647");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0000000001");
}

void TestNumberStringifier2String::testStaticFormatDecLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0");
	QVERIFY(s::format<ulong>(9, result) == "9");
	QVERIFY(s::format<ulong>(10, result) == "10");
	QVERIFY(s::format<ulong>(99, result) == "99");
	QVERIFY(s::format<ulong>(100, result) == "100");
	QVERIFY(s::format<ulong>(255, result) == "255");
	QVERIFY(s::format<ulong>(256, result) == "256");
	QVERIFY(s::format<ulong>(1000, result) == "1000");
	QVERIFY(s::format<ulong>(4294967295, result) == "4294967295");

	QVERIFY(s::format<ulong>(-1, result) == "4294967295");
	QVERIFY(s::format<ulong>(-9, result) == "4294967287");
	QVERIFY(s::format<ulong>(-10, result) == "4294967286");

	QVERIFY(s::format<long>(0, result) == "0");
	QVERIFY(s::format<long>(9, result) == "9");
	QVERIFY(s::format<long>(10, result) == "10");
	QVERIFY(s::format<long>(99, result) == "99");
	QVERIFY(s::format<long>(100, result) == "100");
	QVERIFY(s::format<long>(255, result) == "255");
	QVERIFY(s::format<long>(256, result) == "256");
	QVERIFY(s::format<long>(1000, result) == "1000");
	QVERIFY(s::format<long>(2147483647, result) == "2147483647");
	QVERIFY(s::format<long>(4294967295, result) == "-1");

	QVERIFY(s::format<long>(-1, result) == "-1");
	QVERIFY(s::format<long>(-9, result) == "-9");
	QVERIFY(s::format<long>(-10, result) == "-10");
	QVERIFY(s::format<long>(-99, result) == "-99");
	QVERIFY(s::format<long>(-100, result) == "-100");
	QVERIFY(s::format<long>(-255, result) == "-255");
	QVERIFY(s::format<long>(-256, result) == "-256");
	QVERIFY(s::format<long>(-1000, result) == "-1000");
	QVERIFY(s::format<long>(-2147483647, result) == "-2147483647");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatDecLongLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0000000000");
	QVERIFY(s::format<ulong>(9, result) == "0000000009");
	QVERIFY(s::format<ulong>(10, result) == "0000000010");
	QVERIFY(s::format<ulong>(99, result) == "0000000099");
	QVERIFY(s::format<ulong>(100, result) == "0000000100");
	QVERIFY(s::format<ulong>(255, result) == "0000000255");
	QVERIFY(s::format<ulong>(256, result) == "0000000256");
	QVERIFY(s::format<ulong>(1000, result) == "0000001000");
	QVERIFY(s::format<ulong>(4294967295, result) == "4294967295");

	QVERIFY(s::format<ulong>(-1, result) == "4294967295");
	QVERIFY(s::format<ulong>(-9, result) == "4294967287");
	QVERIFY(s::format<ulong>(-10, result) == "4294967286");

	QVERIFY(s::format<long>(0, result) == "0000000000");
	QVERIFY(s::format<long>(9, result) == "0000000009");
	QVERIFY(s::format<long>(10, result) == "0000000010");
	QVERIFY(s::format<long>(99, result) == "0000000099");
	QVERIFY(s::format<long>(100, result) == "0000000100");
	QVERIFY(s::format<long>(255, result) == "0000000255");
	QVERIFY(s::format<long>(256, result) == "0000000256");
	QVERIFY(s::format<long>(1000, result) == "0000001000");
	QVERIFY(s::format<long>(2147483647, result) == "2147483647");
	QVERIFY(s::format<long>(4294967295, result) == "-0000000001");

	QVERIFY(s::format<long>(-1, result) == "-0000000001");
	QVERIFY(s::format<long>(-9, result) == "-0000000009");
	QVERIFY(s::format<long>(-10, result) == "-0000000010");
	QVERIFY(s::format<long>(-99, result) == "-0000000099");
	QVERIFY(s::format<long>(-100, result) == "-0000000100");
	QVERIFY(s::format<long>(-255, result) == "-0000000255");
	QVERIFY(s::format<long>(-256, result) == "-0000000256");
	QVERIFY(s::format<long>(-1000, result) == "-0000001000");
	QVERIFY(s::format<long>(-2147483647, result) == "-2147483647");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0000000001");
}

void TestNumberStringifier2String::testStaticFormatDecInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0");
	QVERIFY(s::format<quint64>(9, result) == "9");
	QVERIFY(s::format<quint64>(10, result) == "10");
	QVERIFY(s::format<quint64>(99, result) == "99");
	QVERIFY(s::format<quint64>(100, result) == "100");
	QVERIFY(s::format<quint64>(255, result) == "255");
	QVERIFY(s::format<quint64>(256, result) == "256");
	QVERIFY(s::format<quint64>(1000, result) == "1000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "18446744073709551615");

	QVERIFY(s::format<quint64>(-1, result) == "18446744073709551615");
	QVERIFY(s::format<quint64>(-9, result) == "18446744073709551607");
	QVERIFY(s::format<quint64>(-10, result) == "18446744073709551606");

	QVERIFY(s::format<qint64>(0, result) == "0");
	QVERIFY(s::format<qint64>(9, result) == "9");
	QVERIFY(s::format<qint64>(10, result) == "10");
	QVERIFY(s::format<qint64>(99, result) == "99");
	QVERIFY(s::format<qint64>(100, result) == "100");
	QVERIFY(s::format<qint64>(255, result) == "255");
	QVERIFY(s::format<qint64>(256, result) == "256");
	QVERIFY(s::format<qint64>(1000, result) == "1000");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "9223372036854775807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "-1");

	QVERIFY(s::format<qint64>(-1, result) == "-1");
	QVERIFY(s::format<qint64>(-9, result) == "-9");
	QVERIFY(s::format<qint64>(-10, result) == "-10");
	QVERIFY(s::format<qint64>(-99, result) == "-99");
	QVERIFY(s::format<qint64>(-100, result) == "-100");
	QVERIFY(s::format<qint64>(-255, result) == "-255");
	QVERIFY(s::format<qint64>(-256, result) == "-256");
	QVERIFY(s::format<qint64>(-1000, result) == "-1000");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "-9223372036854775807");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatDecInt64Lz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "00000000000000000000");
	QVERIFY(s::format<quint64>(9, result) == "00000000000000000009");
	QVERIFY(s::format<quint64>(10, result) == "00000000000000000010");
	QVERIFY(s::format<quint64>(99, result) == "00000000000000000099");
	QVERIFY(s::format<quint64>(100, result) == "00000000000000000100");
	QVERIFY(s::format<quint64>(255, result) == "00000000000000000255");
	QVERIFY(s::format<quint64>(256, result) == "00000000000000000256");
	QVERIFY(s::format<quint64>(1000, result) == "00000000000000001000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "18446744073709551615");

	QVERIFY(s::format<quint64>(-1, result) == "18446744073709551615");
	QVERIFY(s::format<quint64>(-9, result) == "18446744073709551607");
	QVERIFY(s::format<quint64>(-10, result) == "18446744073709551606");

	QVERIFY(s::format<qint64>(0, result) == "0000000000000000000");
	QVERIFY(s::format<qint64>(9, result) == "0000000000000000009");
	QVERIFY(s::format<qint64>(10, result) == "0000000000000000010");
	QVERIFY(s::format<qint64>(99, result) == "0000000000000000099");
	QVERIFY(s::format<qint64>(100, result) == "0000000000000000100");
	QVERIFY(s::format<qint64>(255, result) == "0000000000000000255");
	QVERIFY(s::format<qint64>(256, result) == "0000000000000000256");
	QVERIFY(s::format<qint64>(1000, result) == "0000000000000001000");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "9223372036854775807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "-0000000000000000001");

	QVERIFY(s::format<qint64>(-1, result) == "-0000000000000000001");
	QVERIFY(s::format<qint64>(-9, result) == "-0000000000000000009");
	QVERIFY(s::format<qint64>(-10, result) == "-0000000000000000010");
	QVERIFY(s::format<qint64>(-99, result) == "-0000000000000000099");
	QVERIFY(s::format<qint64>(-100, result) == "-0000000000000000100");
	QVERIFY(s::format<qint64>(-255, result) == "-0000000000000000255");
	QVERIFY(s::format<qint64>(-256, result) == "-0000000000000000256");
	QVERIFY(s::format<qint64>(-1000, result) == "-0000000000000001000");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "-9223372036854775807");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0000000000000000001");
}

void TestNumberStringifier2String::testStaticFormatDec2DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "00");
	QVERIFY(s::format<uchar>(9, result) == "09");
	QVERIFY(s::format<uchar>(10, result) == "10");
	QVERIFY(s::format<uchar>(99, result) == "99");
	QVERIFY(s::format<uchar>(100, result) == "00");
	QVERIFY(s::format<uchar>(255, result) == "55");

	QVERIFY(s::format<uchar>(-1, result) == "55");
	QVERIFY(s::format<uchar>(-9, result) == "47");
	QVERIFY(s::format<uchar>(-10, result) == "46");

	QVERIFY(s::format<char>(0, result) == "00");
	QVERIFY(s::format<char>(9, result) == "09");
	QVERIFY(s::format<char>(10, result) == "10");
	QVERIFY(s::format<char>(99, result) == "99");
	QVERIFY(s::format<char>(100, result) == "00");
	QVERIFY(s::format<char>(127, result) == "27");

	QVERIFY(s::format<char>(-1, result) == "55");
	QVERIFY(s::format<char>(-9, result) == "47");
	QVERIFY(s::format<char>(-10, result) == "46");
	QVERIFY(s::format<char>(-99, result) == "57");
	QVERIFY(s::format<char>(-100, result) == "56");

	QVERIFY(s::format<signed char>(0, result) == "00");
	QVERIFY(s::format<signed char>(9, result) == "09");
	QVERIFY(s::format<signed char>(10, result) == "10");
	QVERIFY(s::format<signed char>(99, result) == "99");
	QVERIFY(s::format<signed char>(100, result) == "00");
	QVERIFY(s::format<signed char>(127, result) == "27");

	QVERIFY(s::format<signed char>(-1, result) == "55");
	QVERIFY(s::format<signed char>(-9, result) == "47");
	QVERIFY(s::format<signed char>(-10, result) == "46");
	QVERIFY(s::format<signed char>(-99, result) == "57");
	QVERIFY(s::format<signed char>(-100, result) == "56");
}

void TestNumberStringifier2String::testStaticFormatDec2DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "00");
	QVERIFY(s::format<ushort>(9, result) == "09");
	QVERIFY(s::format<ushort>(10, result) == "10");
	QVERIFY(s::format<ushort>(99, result) == "99");
	QVERIFY(s::format<ushort>(100, result) == "00");
	QVERIFY(s::format<ushort>(255, result) == "55");
	QVERIFY(s::format<ushort>(256, result) == "56");
	QVERIFY(s::format<ushort>(1000, result) == "00");
	QVERIFY(s::format<ushort>(65535, result) == "35");

	QVERIFY(s::format<ushort>(-1, result) == "35");
	QVERIFY(s::format<ushort>(-9, result) == "27");
	QVERIFY(s::format<ushort>(-10, result) == "26");

	QVERIFY(s::format<short>(0, result) == "00");
	QVERIFY(s::format<short>(9, result) == "09");
	QVERIFY(s::format<short>(10, result) == "10");
	QVERIFY(s::format<short>(99, result) == "99");
	QVERIFY(s::format<short>(100, result) == "00");
	QVERIFY(s::format<short>(255, result) == "55");
	QVERIFY(s::format<short>(256, result) == "56");
	QVERIFY(s::format<short>(1000, result) == "00");
	QVERIFY(s::format<short>(32767, result) == "67");

	QVERIFY(s::format<short>(-1, result) == "35");
	QVERIFY(s::format<short>(-9, result) == "27");
	QVERIFY(s::format<short>(-10, result) == "26");
	QVERIFY(s::format<short>(-99, result) == "37");
	QVERIFY(s::format<short>(-100, result) == "36");
	QVERIFY(s::format<short>(-255, result) == "81");
	QVERIFY(s::format<short>(-256, result) == "80");
	QVERIFY(s::format<short>(-1000, result) == "36");
	QVERIFY(s::format<short>(-32767, result) == "69");
}

void TestNumberStringifier2String::testStaticFormatDec2DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "00");
	QVERIFY(s::format<uint>(9, result) == "09");
	QVERIFY(s::format<uint>(10, result) == "10");
	QVERIFY(s::format<uint>(99, result) == "99");
	QVERIFY(s::format<uint>(100, result) == "00");
	QVERIFY(s::format<uint>(255, result) == "55");
	QVERIFY(s::format<uint>(256, result) == "56");
	QVERIFY(s::format<uint>(1000, result) == "00");
	QVERIFY(s::format<uint>(4294967295, result) == "95");

	QVERIFY(s::format<uint>(-1, result) == "95");
	QVERIFY(s::format<uint>(-9, result) == "87");
	QVERIFY(s::format<uint>(-10, result) == "86");

	QVERIFY(s::format<int>(0, result) == "00");
	QVERIFY(s::format<int>(9, result) == "09");
	QVERIFY(s::format<int>(10, result) == "10");
	QVERIFY(s::format<int>(99, result) == "99");
	QVERIFY(s::format<int>(100, result) == "00");
	QVERIFY(s::format<int>(255, result) == "55");
	QVERIFY(s::format<int>(256, result) == "56");
	QVERIFY(s::format<int>(1000, result) == "00");
	QVERIFY(s::format<int>(2147483647, result) == "47");
	QVERIFY(s::format<int>(4294967295, result) == "95");

	QVERIFY(s::format<int>(-1, result) == "95");
	QVERIFY(s::format<int>(-9, result) == "87");
	QVERIFY(s::format<int>(-10, result) == "86");
	QVERIFY(s::format<int>(-99, result) == "97");
	QVERIFY(s::format<int>(-100, result) == "96");
	QVERIFY(s::format<int>(-255, result) == "41");
	QVERIFY(s::format<int>(-256, result) == "40");
	QVERIFY(s::format<int>(-1000, result) == "96");
	QVERIFY(s::format<int>(-2147483647, result) == "49");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "01");
}

void TestNumberStringifier2String::testStaticFormatDec2DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "00");
	QVERIFY(s::format<ulong>(9, result) == "09");
	QVERIFY(s::format<ulong>(10, result) == "10");
	QVERIFY(s::format<ulong>(99, result) == "99");
	QVERIFY(s::format<ulong>(100, result) == "00");
	QVERIFY(s::format<ulong>(255, result) == "55");
	QVERIFY(s::format<ulong>(256, result) == "56");
	QVERIFY(s::format<ulong>(1000, result) == "00");
	QVERIFY(s::format<ulong>(4294967295, result) == "95");

	QVERIFY(s::format<ulong>(-1, result) == "95");
	QVERIFY(s::format<ulong>(-9, result) == "87");
	QVERIFY(s::format<ulong>(-10, result) == "86");

	QVERIFY(s::format<long>(0, result) == "00");
	QVERIFY(s::format<long>(9, result) == "09");
	QVERIFY(s::format<long>(10, result) == "10");
	QVERIFY(s::format<long>(99, result) == "99");
	QVERIFY(s::format<long>(100, result) == "00");
	QVERIFY(s::format<long>(255, result) == "55");
	QVERIFY(s::format<long>(256, result) == "56");
	QVERIFY(s::format<long>(1000, result) == "00");
	QVERIFY(s::format<long>(2147483647, result) == "47");
	QVERIFY(s::format<long>(4294967295, result) == "95");

	QVERIFY(s::format<long>(-1, result) == "95");
	QVERIFY(s::format<long>(-9, result) == "87");
	QVERIFY(s::format<long>(-10, result) == "86");
	QVERIFY(s::format<long>(-99, result) == "97");
	QVERIFY(s::format<long>(-100, result) == "96");
	QVERIFY(s::format<long>(-255, result) == "41");
	QVERIFY(s::format<long>(-256, result) == "40");
	QVERIFY(s::format<long>(-1000, result) == "96");
	QVERIFY(s::format<long>(-2147483647, result) == "49");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "01");
}

void TestNumberStringifier2String::testStaticFormatDec2DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "00");
	QVERIFY(s::format<quint64>(9, result) == "09");
	QVERIFY(s::format<quint64>(10, result) == "10");
	QVERIFY(s::format<quint64>(99, result) == "99");
	QVERIFY(s::format<quint64>(100, result) == "00");
	QVERIFY(s::format<quint64>(255, result) == "55");
	QVERIFY(s::format<quint64>(256, result) == "56");
	QVERIFY(s::format<quint64>(1000, result) == "00");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "15");

	QVERIFY(s::format<quint64>(-1, result) == "15");
	QVERIFY(s::format<quint64>(-9, result) == "07");
	QVERIFY(s::format<quint64>(-10, result) == "06");

	QVERIFY(s::format<qint64>(0, result) == "00");
	QVERIFY(s::format<qint64>(9, result) == "09");
	QVERIFY(s::format<qint64>(10, result) == "10");
	QVERIFY(s::format<qint64>(99, result) == "99");
	QVERIFY(s::format<qint64>(100, result) == "00");
	QVERIFY(s::format<qint64>(255, result) == "55");
	QVERIFY(s::format<qint64>(256, result) == "56");
	QVERIFY(s::format<qint64>(1000, result) == "00");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "07");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "15");

	QVERIFY(s::format<qint64>(-1, result) == "15");
	QVERIFY(s::format<qint64>(-9, result) == "07");
	QVERIFY(s::format<qint64>(-10, result) == "06");
	QVERIFY(s::format<qint64>(-99, result) == "17");
	QVERIFY(s::format<qint64>(-100, result) == "16");
	QVERIFY(s::format<qint64>(-255, result) == "61");
	QVERIFY(s::format<qint64>(-256, result) == "60");
	QVERIFY(s::format<qint64>(-1000, result) == "16");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "09");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "01");
}

void TestNumberStringifier2String::testStaticFormatDec3DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "000");
	QVERIFY(s::format<uchar>(9, result) == "009");
	QVERIFY(s::format<uchar>(10, result) == "010");
	QVERIFY(s::format<uchar>(99, result) == "099");
	QVERIFY(s::format<uchar>(100, result) == "100");
	QVERIFY(s::format<uchar>(255, result) == "255");

	QVERIFY(s::format<uchar>(-1, result) == "255");
	QVERIFY(s::format<uchar>(-9, result) == "247");
	QVERIFY(s::format<uchar>(-10, result) == "246");

	QVERIFY(s::format<char>(0, result) == "000");
	QVERIFY(s::format<char>(9, result) == "009");
	QVERIFY(s::format<char>(10, result) == "010");
	QVERIFY(s::format<char>(99, result) == "099");
	QVERIFY(s::format<char>(100, result) == "100");
	QVERIFY(s::format<char>(127, result) == "127");

	QVERIFY(s::format<char>(-1, result) == "255");
	QVERIFY(s::format<char>(-9, result) == "247");
	QVERIFY(s::format<char>(-10, result) == "246");
	QVERIFY(s::format<char>(-99, result) == "157");
	QVERIFY(s::format<char>(-100, result) == "156");

	QVERIFY(s::format<signed char>(0, result) == "000");
	QVERIFY(s::format<signed char>(9, result) == "009");
	QVERIFY(s::format<signed char>(10, result) == "010");
	QVERIFY(s::format<signed char>(99, result) == "099");
	QVERIFY(s::format<signed char>(100, result) == "100");
	QVERIFY(s::format<signed char>(127, result) == "127");

	QVERIFY(s::format<signed char>(-1, result) == "255");
	QVERIFY(s::format<signed char>(-9, result) == "247");
	QVERIFY(s::format<signed char>(-10, result) == "246");
	QVERIFY(s::format<signed char>(-99, result) == "157");
	QVERIFY(s::format<signed char>(-100, result) == "156");
}

void TestNumberStringifier2String::testStaticFormatDec3DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "000");
	QVERIFY(s::format<ushort>(9, result) == "009");
	QVERIFY(s::format<ushort>(10, result) == "010");
	QVERIFY(s::format<ushort>(99, result) == "099");
	QVERIFY(s::format<ushort>(100, result) == "100");
	QVERIFY(s::format<ushort>(255, result) == "255");
	QVERIFY(s::format<ushort>(256, result) == "256");
	QVERIFY(s::format<ushort>(1000, result) == "000");
	QVERIFY(s::format<ushort>(65535, result) == "535");

	QVERIFY(s::format<ushort>(-1, result) == "535");
	QVERIFY(s::format<ushort>(-9, result) == "527");
	QVERIFY(s::format<ushort>(-10, result) == "526");

	QVERIFY(s::format<short>(0, result) == "000");
	QVERIFY(s::format<short>(9, result) == "009");
	QVERIFY(s::format<short>(10, result) == "010");
	QVERIFY(s::format<short>(99, result) == "099");
	QVERIFY(s::format<short>(100, result) == "100");
	QVERIFY(s::format<short>(255, result) == "255");
	QVERIFY(s::format<short>(256, result) == "256");
	QVERIFY(s::format<short>(1000, result) == "000");
	QVERIFY(s::format<short>(32767, result) == "767");

	QVERIFY(s::format<short>(-1, result) == "535");
	QVERIFY(s::format<short>(-9, result) == "527");
	QVERIFY(s::format<short>(-10, result) == "526");
	QVERIFY(s::format<short>(-99, result) == "437");
	QVERIFY(s::format<short>(-100, result) == "436");
	QVERIFY(s::format<short>(-255, result) == "281");
	QVERIFY(s::format<short>(-256, result) == "280");
	QVERIFY(s::format<short>(-1000, result) == "536");
	QVERIFY(s::format<short>(-32767, result) == "769");
}

void TestNumberStringifier2String::testStaticFormatDec3DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "000");
	QVERIFY(s::format<uint>(9, result) == "009");
	QVERIFY(s::format<uint>(10, result) == "010");
	QVERIFY(s::format<uint>(99, result) == "099");
	QVERIFY(s::format<uint>(100, result) == "100");
	QVERIFY(s::format<uint>(255, result) == "255");
	QVERIFY(s::format<uint>(256, result) == "256");
	QVERIFY(s::format<uint>(1000, result) == "000");
	QVERIFY(s::format<uint>(4294967295, result) == "295");

	QVERIFY(s::format<uint>(-1, result) == "295");
	QVERIFY(s::format<uint>(-9, result) == "287");
	QVERIFY(s::format<uint>(-10, result) == "286");

	QVERIFY(s::format<int>(0, result) == "000");
	QVERIFY(s::format<int>(9, result) == "009");
	QVERIFY(s::format<int>(10, result) == "010");
	QVERIFY(s::format<int>(99, result) == "099");
	QVERIFY(s::format<int>(100, result) == "100");
	QVERIFY(s::format<int>(255, result) == "255");
	QVERIFY(s::format<int>(256, result) == "256");
	QVERIFY(s::format<int>(1000, result) == "000");
	QVERIFY(s::format<int>(2147483647, result) == "647");
	QVERIFY(s::format<int>(4294967295, result) == "295");

	QVERIFY(s::format<int>(-1, result) == "295");
	QVERIFY(s::format<int>(-9, result) == "287");
	QVERIFY(s::format<int>(-10, result) == "286");
	QVERIFY(s::format<int>(-99, result) == "197");
	QVERIFY(s::format<int>(-100, result) == "196");
	QVERIFY(s::format<int>(-255, result) == "041");
	QVERIFY(s::format<int>(-256, result) == "040");
	QVERIFY(s::format<int>(-1000, result) == "296");
	QVERIFY(s::format<int>(-2147483647, result) == "649");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "001");
}

void TestNumberStringifier2String::testStaticFormatDec3DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "000");
	QVERIFY(s::format<ulong>(9, result) == "009");
	QVERIFY(s::format<ulong>(10, result) == "010");
	QVERIFY(s::format<ulong>(99, result) == "099");
	QVERIFY(s::format<ulong>(100, result) == "100");
	QVERIFY(s::format<ulong>(255, result) == "255");
	QVERIFY(s::format<ulong>(256, result) == "256");
	QVERIFY(s::format<ulong>(1000, result) == "000");
	QVERIFY(s::format<ulong>(4294967295, result) == "295");

	QVERIFY(s::format<ulong>(-1, result) == "295");
	QVERIFY(s::format<ulong>(-9, result) == "287");
	QVERIFY(s::format<ulong>(-10, result) == "286");

	QVERIFY(s::format<long>(0, result) == "000");
	QVERIFY(s::format<long>(9, result) == "009");
	QVERIFY(s::format<long>(10, result) == "010");
	QVERIFY(s::format<long>(99, result) == "099");
	QVERIFY(s::format<long>(100, result) == "100");
	QVERIFY(s::format<long>(255, result) == "255");
	QVERIFY(s::format<long>(256, result) == "256");
	QVERIFY(s::format<long>(1000, result) == "000");
	QVERIFY(s::format<long>(2147483647, result) == "647");
	QVERIFY(s::format<long>(4294967295, result) == "295");

	QVERIFY(s::format<long>(-1, result) == "295");
	QVERIFY(s::format<long>(-9, result) == "287");
	QVERIFY(s::format<long>(-10, result) == "286");
	QVERIFY(s::format<long>(-99, result) == "197");
	QVERIFY(s::format<long>(-100, result) == "196");
	QVERIFY(s::format<long>(-255, result) == "041");
	QVERIFY(s::format<long>(-256, result) == "040");
	QVERIFY(s::format<long>(-1000, result) == "296");
	QVERIFY(s::format<long>(-2147483647, result) == "649");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "001");
}

void TestNumberStringifier2String::testStaticFormatDec3DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "000");
	QVERIFY(s::format<quint64>(9, result) == "009");
	QVERIFY(s::format<quint64>(10, result) == "010");
	QVERIFY(s::format<quint64>(99, result) == "099");
	QVERIFY(s::format<quint64>(100, result) == "100");
	QVERIFY(s::format<quint64>(255, result) == "255");
	QVERIFY(s::format<quint64>(256, result) == "256");
	QVERIFY(s::format<quint64>(1000, result) == "000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "615");

	QVERIFY(s::format<quint64>(-1, result) == "615");
	QVERIFY(s::format<quint64>(-9, result) == "607");
	QVERIFY(s::format<quint64>(-10, result) == "606");

	QVERIFY(s::format<qint64>(0, result) == "000");
	QVERIFY(s::format<qint64>(9, result) == "009");
	QVERIFY(s::format<qint64>(10, result) == "010");
	QVERIFY(s::format<qint64>(99, result) == "099");
	QVERIFY(s::format<qint64>(100, result) == "100");
	QVERIFY(s::format<qint64>(255, result) == "255");
	QVERIFY(s::format<qint64>(256, result) == "256");
	QVERIFY(s::format<qint64>(1000, result) == "000");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "615");

	QVERIFY(s::format<qint64>(-1, result) == "615");
	QVERIFY(s::format<qint64>(-9, result) == "607");
	QVERIFY(s::format<qint64>(-10, result) == "606");
	QVERIFY(s::format<qint64>(-99, result) == "517");
	QVERIFY(s::format<qint64>(-100, result) == "516");
	QVERIFY(s::format<qint64>(-255, result) == "361");
	QVERIFY(s::format<qint64>(-256, result) == "360");
	QVERIFY(s::format<qint64>(-1000, result) == "616");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "809");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "001");
}

void TestNumberStringifier2String::testStaticFormatDec4DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0000");
	QVERIFY(s::format<uchar>(9, result) == "0009");
	QVERIFY(s::format<uchar>(10, result) == "0010");
	QVERIFY(s::format<uchar>(99, result) == "0099");
	QVERIFY(s::format<uchar>(100, result) == "0100");
	QVERIFY(s::format<uchar>(255, result) == "0255");

	QVERIFY(s::format<uchar>(-1, result) == "0255");
	QVERIFY(s::format<uchar>(-9, result) == "0247");
	QVERIFY(s::format<uchar>(-10, result) == "0246");

	QVERIFY(s::format<char>(0, result) == "0000");
	QVERIFY(s::format<char>(9, result) == "0009");
	QVERIFY(s::format<char>(10, result) == "0010");
	QVERIFY(s::format<char>(99, result) == "0099");
	QVERIFY(s::format<char>(100, result) == "0100");
	QVERIFY(s::format<char>(127, result) == "0127");

	QVERIFY(s::format<char>(-1, result) == "0255");
	QVERIFY(s::format<char>(-9, result) == "0247");
	QVERIFY(s::format<char>(-10, result) == "0246");
	QVERIFY(s::format<char>(-99, result) == "0157");
	QVERIFY(s::format<char>(-100, result) == "0156");

	QVERIFY(s::format<signed char>(0, result) == "0000");
	QVERIFY(s::format<signed char>(9, result) == "0009");
	QVERIFY(s::format<signed char>(10, result) == "0010");
	QVERIFY(s::format<signed char>(99, result) == "0099");
	QVERIFY(s::format<signed char>(100, result) == "0100");
	QVERIFY(s::format<signed char>(127, result) == "0127");

	QVERIFY(s::format<signed char>(-1, result) == "0255");
	QVERIFY(s::format<signed char>(-9, result) == "0247");
	QVERIFY(s::format<signed char>(-10, result) == "0246");
	QVERIFY(s::format<signed char>(-99, result) == "0157");
	QVERIFY(s::format<signed char>(-100, result) == "0156");
}

void TestNumberStringifier2String::testStaticFormatDec4DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0000");
	QVERIFY(s::format<ushort>(9, result) == "0009");
	QVERIFY(s::format<ushort>(10, result) == "0010");
	QVERIFY(s::format<ushort>(99, result) == "0099");
	QVERIFY(s::format<ushort>(100, result) == "0100");
	QVERIFY(s::format<ushort>(255, result) == "0255");
	QVERIFY(s::format<ushort>(256, result) == "0256");
	QVERIFY(s::format<ushort>(1000, result) == "1000");
	QVERIFY(s::format<ushort>(65535, result) == "5535");

	QVERIFY(s::format<ushort>(-1, result) == "5535");
	QVERIFY(s::format<ushort>(-9, result) == "5527");
	QVERIFY(s::format<ushort>(-10, result) == "5526");

	QVERIFY(s::format<short>(0, result) == "0000");
	QVERIFY(s::format<short>(9, result) == "0009");
	QVERIFY(s::format<short>(10, result) == "0010");
	QVERIFY(s::format<short>(99, result) == "0099");
	QVERIFY(s::format<short>(100, result) == "0100");
	QVERIFY(s::format<short>(255, result) == "0255");
	QVERIFY(s::format<short>(256, result) == "0256");
	QVERIFY(s::format<short>(1000, result) == "1000");
	QVERIFY(s::format<short>(32767, result) == "2767");

	QVERIFY(s::format<short>(-1, result) == "5535");
	QVERIFY(s::format<short>(-9, result) == "5527");
	QVERIFY(s::format<short>(-10, result) == "5526");
	QVERIFY(s::format<short>(-99, result) == "5437");
	QVERIFY(s::format<short>(-100, result) == "5436");
	QVERIFY(s::format<short>(-255, result) == "5281");
	QVERIFY(s::format<short>(-256, result) == "5280");
	QVERIFY(s::format<short>(-1000, result) == "4536");
	QVERIFY(s::format<short>(-32767, result) == "2769");
}

void TestNumberStringifier2String::testStaticFormatDec4DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0000");
	QVERIFY(s::format<uint>(9, result) == "0009");
	QVERIFY(s::format<uint>(10, result) == "0010");
	QVERIFY(s::format<uint>(99, result) == "0099");
	QVERIFY(s::format<uint>(100, result) == "0100");
	QVERIFY(s::format<uint>(255, result) == "0255");
	QVERIFY(s::format<uint>(256, result) == "0256");
	QVERIFY(s::format<uint>(1000, result) == "1000");
	QVERIFY(s::format<uint>(4294967295, result) == "7295");

	QVERIFY(s::format<uint>(-1, result) == "7295");
	QVERIFY(s::format<uint>(-9, result) == "7287");
	QVERIFY(s::format<uint>(-10, result) == "7286");

	QVERIFY(s::format<int>(0, result) == "0000");
	QVERIFY(s::format<int>(9, result) == "0009");
	QVERIFY(s::format<int>(10, result) == "0010");
	QVERIFY(s::format<int>(99, result) == "0099");
	QVERIFY(s::format<int>(100, result) == "0100");
	QVERIFY(s::format<int>(255, result) == "0255");
	QVERIFY(s::format<int>(256, result) == "0256");
	QVERIFY(s::format<int>(1000, result) == "1000");
	QVERIFY(s::format<int>(2147483647, result) == "3647");
	QVERIFY(s::format<int>(4294967295, result) == "7295");

	QVERIFY(s::format<int>(-1, result) == "7295");
	QVERIFY(s::format<int>(-9, result) == "7287");
	QVERIFY(s::format<int>(-10, result) == "7286");
	QVERIFY(s::format<int>(-99, result) == "7197");
	QVERIFY(s::format<int>(-100, result) == "7196");
	QVERIFY(s::format<int>(-255, result) == "7041");
	QVERIFY(s::format<int>(-256, result) == "7040");
	QVERIFY(s::format<int>(-1000, result) == "6296");
	QVERIFY(s::format<int>(-2147483647, result) == "3649");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0001");
}

void TestNumberStringifier2String::testStaticFormatDec4DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0000");
	QVERIFY(s::format<ulong>(9, result) == "0009");
	QVERIFY(s::format<ulong>(10, result) == "0010");
	QVERIFY(s::format<ulong>(99, result) == "0099");
	QVERIFY(s::format<ulong>(100, result) == "0100");
	QVERIFY(s::format<ulong>(255, result) == "0255");
	QVERIFY(s::format<ulong>(256, result) == "0256");
	QVERIFY(s::format<ulong>(1000, result) == "1000");
	QVERIFY(s::format<ulong>(4294967295, result) == "7295");

	QVERIFY(s::format<ulong>(-1, result) == "7295");
	QVERIFY(s::format<ulong>(-9, result) == "7287");
	QVERIFY(s::format<ulong>(-10, result) == "7286");

	QVERIFY(s::format<long>(0, result) == "0000");
	QVERIFY(s::format<long>(9, result) == "0009");
	QVERIFY(s::format<long>(10, result) == "0010");
	QVERIFY(s::format<long>(99, result) == "0099");
	QVERIFY(s::format<long>(100, result) == "0100");
	QVERIFY(s::format<long>(255, result) == "0255");
	QVERIFY(s::format<long>(256, result) == "0256");
	QVERIFY(s::format<long>(1000, result) == "1000");
	QVERIFY(s::format<long>(2147483647, result) == "3647");
	QVERIFY(s::format<long>(4294967295, result) == "7295");

	QVERIFY(s::format<long>(-1, result) == "7295");
	QVERIFY(s::format<long>(-9, result) == "7287");
	QVERIFY(s::format<long>(-10, result) == "7286");
	QVERIFY(s::format<long>(-99, result) == "7197");
	QVERIFY(s::format<long>(-100, result) == "7196");
	QVERIFY(s::format<long>(-255, result) == "7041");
	QVERIFY(s::format<long>(-256, result) == "7040");
	QVERIFY(s::format<long>(-1000, result) == "6296");
	QVERIFY(s::format<long>(-2147483647, result) == "3649");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0001");
}

void TestNumberStringifier2String::testStaticFormatDec4DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0000");
	QVERIFY(s::format<quint64>(9, result) == "0009");
	QVERIFY(s::format<quint64>(10, result) == "0010");
	QVERIFY(s::format<quint64>(99, result) == "0099");
	QVERIFY(s::format<quint64>(100, result) == "0100");
	QVERIFY(s::format<quint64>(255, result) == "0255");
	QVERIFY(s::format<quint64>(256, result) == "0256");
	QVERIFY(s::format<quint64>(1000, result) == "1000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "1615");

	QVERIFY(s::format<quint64>(-1, result) == "1615");
	QVERIFY(s::format<quint64>(-9, result) == "1607");
	QVERIFY(s::format<quint64>(-10, result) == "1606");

	QVERIFY(s::format<qint64>(0, result) == "0000");
	QVERIFY(s::format<qint64>(9, result) == "0009");
	QVERIFY(s::format<qint64>(10, result) == "0010");
	QVERIFY(s::format<qint64>(99, result) == "0099");
	QVERIFY(s::format<qint64>(100, result) == "0100");
	QVERIFY(s::format<qint64>(255, result) == "0255");
	QVERIFY(s::format<qint64>(256, result) == "0256");
	QVERIFY(s::format<qint64>(1000, result) == "1000");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "5807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "1615");

	QVERIFY(s::format<qint64>(-1, result) == "1615");
	QVERIFY(s::format<qint64>(-9, result) == "1607");
	QVERIFY(s::format<qint64>(-10, result) == "1606");
	QVERIFY(s::format<qint64>(-99, result) == "1517");
	QVERIFY(s::format<qint64>(-100, result) == "1516");
	QVERIFY(s::format<qint64>(-255, result) == "1361");
	QVERIFY(s::format<qint64>(-256, result) == "1360");
	QVERIFY(s::format<qint64>(-1000, result) == "0616");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "5809");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0001");
}

void TestNumberStringifier2String::testStaticFormatHexChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0");
	QVERIFY(s::format<uchar>(9, result) == "9");
	QVERIFY(s::format<uchar>(10, result) == "a");
	QVERIFY(s::format<uchar>(99, result) == "63");
	QVERIFY(s::format<uchar>(100, result) == "64");
	QVERIFY(s::format<uchar>(255, result) == "ff");

	QVERIFY(s::format<uchar>(-1, result) == "ff");
	QVERIFY(s::format<uchar>(-9, result) == "f7");
	QVERIFY(s::format<uchar>(-10, result) == "f6");

	QVERIFY(s::format<char>(0, result) == "0");
	QVERIFY(s::format<char>(9, result) == "9");
	QVERIFY(s::format<char>(10, result) == "a");
	QVERIFY(s::format<char>(99, result) == "63");
	QVERIFY(s::format<char>(100, result) == "64");
	QVERIFY(s::format<char>(127, result) == "7f");

	QVERIFY(s::format<char>(-1, result) == "ff");
	QVERIFY(s::format<char>(-9, result) == "f7");
	QVERIFY(s::format<char>(-10, result) == "f6");
	QVERIFY(s::format<char>(-99, result) == "9d");
	QVERIFY(s::format<char>(-100, result) == "9c");

	QVERIFY(s::format<signed char>(0, result) == "0");
	QVERIFY(s::format<signed char>(9, result) == "9");
	QVERIFY(s::format<signed char>(10, result) == "a");
	QVERIFY(s::format<signed char>(99, result) == "63");
	QVERIFY(s::format<signed char>(100, result) == "64");
	QVERIFY(s::format<signed char>(127, result) == "7f");

	QVERIFY(s::format<signed char>(-1, result) == "ff");
	QVERIFY(s::format<signed char>(-9, result) == "f7");
	QVERIFY(s::format<signed char>(-10, result) == "f6");
	QVERIFY(s::format<signed char>(-99, result) == "9d");
	QVERIFY(s::format<signed char>(-100, result) == "9c");
}

void TestNumberStringifier2String::testStaticFormatHexCharUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0");
	QVERIFY(s::format<uchar>(9, result) == "9");
	QVERIFY(s::format<uchar>(10, result) == "A");
	QVERIFY(s::format<uchar>(99, result) == "63");
	QVERIFY(s::format<uchar>(100, result) == "64");
	QVERIFY(s::format<uchar>(255, result) == "FF");

	QVERIFY(s::format<uchar>(-1, result) == "FF");
	QVERIFY(s::format<uchar>(-9, result) == "F7");
	QVERIFY(s::format<uchar>(-10, result) == "F6");

	QVERIFY(s::format<char>(0, result) == "0");
	QVERIFY(s::format<char>(9, result) == "9");
	QVERIFY(s::format<char>(10, result) == "A");
	QVERIFY(s::format<char>(99, result) == "63");
	QVERIFY(s::format<char>(100, result) == "64");
	QVERIFY(s::format<char>(127, result) == "7F");

	QVERIFY(s::format<char>(-1, result) == "FF");
	QVERIFY(s::format<char>(-9, result) == "F7");
	QVERIFY(s::format<char>(-10, result) == "F6");
	QVERIFY(s::format<char>(-99, result) == "9D");
	QVERIFY(s::format<char>(-100, result) == "9C");

	QVERIFY(s::format<signed char>(0, result) == "0");
	QVERIFY(s::format<signed char>(9, result) == "9");
	QVERIFY(s::format<signed char>(10, result) == "A");
	QVERIFY(s::format<signed char>(99, result) == "63");
	QVERIFY(s::format<signed char>(100, result) == "64");
	QVERIFY(s::format<signed char>(127, result) == "7F");

	QVERIFY(s::format<signed char>(-1, result) == "FF");
	QVERIFY(s::format<signed char>(-9, result) == "F7");
	QVERIFY(s::format<signed char>(-10, result) == "F6");
	QVERIFY(s::format<signed char>(-99, result) == "9D");
	QVERIFY(s::format<signed char>(-100, result) == "9C");
}

void TestNumberStringifier2String::testStaticFormatHexCharLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "00");
	QVERIFY(s::format<uchar>(9, result) == "09");
	QVERIFY(s::format<uchar>(10, result) == "0a");
	QVERIFY(s::format<uchar>(99, result) == "63");
	QVERIFY(s::format<uchar>(100, result) == "64");
	QVERIFY(s::format<uchar>(255, result) == "ff");

	QVERIFY(s::format<uchar>(-1, result) == "ff");
	QVERIFY(s::format<uchar>(-9, result) == "f7");
	QVERIFY(s::format<uchar>(-10, result) == "f6");

	QVERIFY(s::format<char>(0, result) == "00");
	QVERIFY(s::format<char>(9, result) == "09");
	QVERIFY(s::format<char>(10, result) == "0a");
	QVERIFY(s::format<char>(99, result) == "63");
	QVERIFY(s::format<char>(100, result) == "64");
	QVERIFY(s::format<char>(127, result) == "7f");

	QVERIFY(s::format<char>(-1, result) == "ff");
	QVERIFY(s::format<char>(-9, result) == "f7");
	QVERIFY(s::format<char>(-10, result) == "f6");
	QVERIFY(s::format<char>(-99, result) == "9d");
	QVERIFY(s::format<char>(-100, result) == "9c");

	QVERIFY(s::format<signed char>(0, result) == "00");
	QVERIFY(s::format<signed char>(9, result) == "09");
	QVERIFY(s::format<signed char>(10, result) == "0a");
	QVERIFY(s::format<signed char>(99, result) == "63");
	QVERIFY(s::format<signed char>(100, result) == "64");
	QVERIFY(s::format<signed char>(127, result) == "7f");

	QVERIFY(s::format<signed char>(-1, result) == "ff");
	QVERIFY(s::format<signed char>(-9, result) == "f7");
	QVERIFY(s::format<signed char>(-10, result) == "f6");
	QVERIFY(s::format<signed char>(-99, result) == "9d");
	QVERIFY(s::format<signed char>(-100, result) == "9c");
}

void TestNumberStringifier2String::testStaticFormatHexCharLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "00");
	QVERIFY(s::format<uchar>(9, result) == "09");
	QVERIFY(s::format<uchar>(10, result) == "0A");
	QVERIFY(s::format<uchar>(99, result) == "63");
	QVERIFY(s::format<uchar>(100, result) == "64");
	QVERIFY(s::format<uchar>(255, result) == "FF");

	QVERIFY(s::format<uchar>(-1, result) == "FF");
	QVERIFY(s::format<uchar>(-9, result) == "F7");
	QVERIFY(s::format<uchar>(-10, result) == "F6");

	QVERIFY(s::format<char>(0, result) == "00");
	QVERIFY(s::format<char>(9, result) == "09");
	QVERIFY(s::format<char>(10, result) == "0A");
	QVERIFY(s::format<char>(99, result) == "63");
	QVERIFY(s::format<char>(100, result) == "64");
	QVERIFY(s::format<char>(127, result) == "7F");

	QVERIFY(s::format<char>(-1, result) == "FF");
	QVERIFY(s::format<char>(-9, result) == "F7");
	QVERIFY(s::format<char>(-10, result) == "F6");
	QVERIFY(s::format<char>(-99, result) == "9D");
	QVERIFY(s::format<char>(-100, result) == "9C");

	QVERIFY(s::format<signed char>(0, result) == "00");
	QVERIFY(s::format<signed char>(9, result) == "09");
	QVERIFY(s::format<signed char>(10, result) == "0A");
	QVERIFY(s::format<signed char>(99, result) == "63");
	QVERIFY(s::format<signed char>(100, result) == "64");
	QVERIFY(s::format<signed char>(127, result) == "7F");

	QVERIFY(s::format<signed char>(-1, result) == "FF");
	QVERIFY(s::format<signed char>(-9, result) == "F7");
	QVERIFY(s::format<signed char>(-10, result) == "F6");
	QVERIFY(s::format<signed char>(-99, result) == "9D");
	QVERIFY(s::format<signed char>(-100, result) == "9C");
}

void TestNumberStringifier2String::testStaticFormatHexShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0");
	QVERIFY(s::format<ushort>(9, result) == "9");
	QVERIFY(s::format<ushort>(10, result) == "a");
	QVERIFY(s::format<ushort>(99, result) == "63");
	QVERIFY(s::format<ushort>(100, result) == "64");
	QVERIFY(s::format<ushort>(255, result) == "ff");
	QVERIFY(s::format<ushort>(256, result) == "100");
	QVERIFY(s::format<ushort>(1000, result) == "3e8");
	QVERIFY(s::format<ushort>(65535, result) == "ffff");

	QVERIFY(s::format<ushort>(-1, result) == "ffff");
	QVERIFY(s::format<ushort>(-9, result) == "fff7");
	QVERIFY(s::format<ushort>(-10, result) == "fff6");

	QVERIFY(s::format<short>(0, result) == "0");
	QVERIFY(s::format<short>(9, result) == "9");
	QVERIFY(s::format<short>(10, result) == "a");
	QVERIFY(s::format<short>(99, result) == "63");
	QVERIFY(s::format<short>(100, result) == "64");
	QVERIFY(s::format<short>(255, result) == "ff");
	QVERIFY(s::format<short>(256, result) == "100");
	QVERIFY(s::format<short>(1000, result) == "3e8");
	QVERIFY(s::format<short>(32767, result) == "7fff");

	QVERIFY(s::format<short>(-1, result) == "ffff");
	QVERIFY(s::format<short>(-9, result) == "fff7");
	QVERIFY(s::format<short>(-10, result) == "fff6");
	QVERIFY(s::format<short>(-99, result) == "ff9d");
	QVERIFY(s::format<short>(-100, result) == "ff9c");
	QVERIFY(s::format<short>(-255, result) == "ff01");
	QVERIFY(s::format<short>(-256, result) == "ff00");
	QVERIFY(s::format<short>(-1000, result) == "fc18");
	QVERIFY(s::format<short>(-32767, result) == "8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0");
	QVERIFY(s::format<ushort>(9, result) == "9");
	QVERIFY(s::format<ushort>(10, result) == "A");
	QVERIFY(s::format<ushort>(99, result) == "63");
	QVERIFY(s::format<ushort>(100, result) == "64");
	QVERIFY(s::format<ushort>(255, result) == "FF");
	QVERIFY(s::format<ushort>(256, result) == "100");
	QVERIFY(s::format<ushort>(1000, result) == "3E8");
	QVERIFY(s::format<ushort>(65535, result) == "FFFF");

	QVERIFY(s::format<ushort>(-1, result) == "FFFF");
	QVERIFY(s::format<ushort>(-9, result) == "FFF7");
	QVERIFY(s::format<ushort>(-10, result) == "FFF6");

	QVERIFY(s::format<short>(0, result) == "0");
	QVERIFY(s::format<short>(9, result) == "9");
	QVERIFY(s::format<short>(10, result) == "A");
	QVERIFY(s::format<short>(99, result) == "63");
	QVERIFY(s::format<short>(100, result) == "64");
	QVERIFY(s::format<short>(255, result) == "FF");
	QVERIFY(s::format<short>(256, result) == "100");
	QVERIFY(s::format<short>(1000, result) == "3E8");
	QVERIFY(s::format<short>(32767, result) == "7FFF");

	QVERIFY(s::format<short>(-1, result) == "FFFF");
	QVERIFY(s::format<short>(-9, result) == "FFF7");
	QVERIFY(s::format<short>(-10, result) == "FFF6");
	QVERIFY(s::format<short>(-99, result) == "FF9D");
	QVERIFY(s::format<short>(-100, result) == "FF9C");
	QVERIFY(s::format<short>(-255, result) == "FF01");
	QVERIFY(s::format<short>(-256, result) == "FF00");
	QVERIFY(s::format<short>(-1000, result) == "FC18");
	QVERIFY(s::format<short>(-32767, result) == "8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0000");
	QVERIFY(s::format<ushort>(9, result) == "0009");
	QVERIFY(s::format<ushort>(10, result) == "000a");
	QVERIFY(s::format<ushort>(99, result) == "0063");
	QVERIFY(s::format<ushort>(100, result) == "0064");
	QVERIFY(s::format<ushort>(255, result) == "00ff");
	QVERIFY(s::format<ushort>(256, result) == "0100");
	QVERIFY(s::format<ushort>(1000, result) == "03e8");
	QVERIFY(s::format<ushort>(65535, result) == "ffff");

	QVERIFY(s::format<ushort>(-1, result) == "ffff");
	QVERIFY(s::format<ushort>(-9, result) == "fff7");
	QVERIFY(s::format<ushort>(-10, result) == "fff6");

	QVERIFY(s::format<short>(0, result) == "0000");
	QVERIFY(s::format<short>(9, result) == "0009");
	QVERIFY(s::format<short>(10, result) == "000a");
	QVERIFY(s::format<short>(99, result) == "0063");
	QVERIFY(s::format<short>(100, result) == "0064");
	QVERIFY(s::format<short>(255, result) == "00ff");
	QVERIFY(s::format<short>(256, result) == "0100");
	QVERIFY(s::format<short>(1000, result) == "03e8");
	QVERIFY(s::format<short>(32767, result) == "7fff");

	QVERIFY(s::format<short>(-1, result) == "ffff");
	QVERIFY(s::format<short>(-9, result) == "fff7");
	QVERIFY(s::format<short>(-10, result) == "fff6");
	QVERIFY(s::format<short>(-99, result) == "ff9d");
	QVERIFY(s::format<short>(-100, result) == "ff9c");
	QVERIFY(s::format<short>(-255, result) == "ff01");
	QVERIFY(s::format<short>(-256, result) == "ff00");
	QVERIFY(s::format<short>(-1000, result) == "fc18");
	QVERIFY(s::format<short>(-32767, result) == "8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0000");
	QVERIFY(s::format<ushort>(9, result) == "0009");
	QVERIFY(s::format<ushort>(10, result) == "000A");
	QVERIFY(s::format<ushort>(99, result) == "0063");
	QVERIFY(s::format<ushort>(100, result) == "0064");
	QVERIFY(s::format<ushort>(255, result) == "00FF");
	QVERIFY(s::format<ushort>(256, result) == "0100");
	QVERIFY(s::format<ushort>(1000, result) == "03E8");
	QVERIFY(s::format<ushort>(65535, result) == "FFFF");

	QVERIFY(s::format<ushort>(-1, result) == "FFFF");
	QVERIFY(s::format<ushort>(-9, result) == "FFF7");
	QVERIFY(s::format<ushort>(-10, result) == "FFF6");

	QVERIFY(s::format<short>(0, result) == "0000");
	QVERIFY(s::format<short>(9, result) == "0009");
	QVERIFY(s::format<short>(10, result) == "000A");
	QVERIFY(s::format<short>(99, result) == "0063");
	QVERIFY(s::format<short>(100, result) == "0064");
	QVERIFY(s::format<short>(255, result) == "00FF");
	QVERIFY(s::format<short>(256, result) == "0100");
	QVERIFY(s::format<short>(1000, result) == "03E8");
	QVERIFY(s::format<short>(32767, result) == "7FFF");

	QVERIFY(s::format<short>(-1, result) == "FFFF");
	QVERIFY(s::format<short>(-9, result) == "FFF7");
	QVERIFY(s::format<short>(-10, result) == "FFF6");
	QVERIFY(s::format<short>(-99, result) == "FF9D");
	QVERIFY(s::format<short>(-100, result) == "FF9C");
	QVERIFY(s::format<short>(-255, result) == "FF01");
	QVERIFY(s::format<short>(-256, result) == "FF00");
	QVERIFY(s::format<short>(-1000, result) == "FC18");
	QVERIFY(s::format<short>(-32767, result) == "8001");
}

void TestNumberStringifier2String::testStaticFormatHexInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0");
	QVERIFY(s::format<uint>(9, result) == "9");
	QVERIFY(s::format<uint>(10, result) == "a");
	QVERIFY(s::format<uint>(99, result) == "63");
	QVERIFY(s::format<uint>(100, result) == "64");
	QVERIFY(s::format<uint>(255, result) == "ff");
	QVERIFY(s::format<uint>(256, result) == "100");
	QVERIFY(s::format<uint>(1000, result) == "3e8");
	QVERIFY(s::format<uint>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<uint>(-1, result) == "ffffffff");
	QVERIFY(s::format<uint>(-9, result) == "fffffff7");
	QVERIFY(s::format<uint>(-10, result) == "fffffff6");

	QVERIFY(s::format<int>(0, result) == "0");
	QVERIFY(s::format<int>(9, result) == "9");
	QVERIFY(s::format<int>(10, result) == "a");
	QVERIFY(s::format<int>(99, result) == "63");
	QVERIFY(s::format<int>(100, result) == "64");
	QVERIFY(s::format<int>(255, result) == "ff");
	QVERIFY(s::format<int>(256, result) == "100");
	QVERIFY(s::format<int>(1000, result) == "3e8");
	QVERIFY(s::format<int>(2147483647, result) == "7fffffff");
	QVERIFY(s::format<int>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<int>(-1, result) == "ffffffff");
	QVERIFY(s::format<int>(-9, result) == "fffffff7");
	QVERIFY(s::format<int>(-10, result) == "fffffff6");
	QVERIFY(s::format<int>(-99, result) == "ffffff9d");
	QVERIFY(s::format<int>(-100, result) == "ffffff9c");
	QVERIFY(s::format<int>(-255, result) == "ffffff01");
	QVERIFY(s::format<int>(-256, result) == "ffffff00");
	QVERIFY(s::format<int>(-1000, result) == "fffffc18");
	QVERIFY(s::format<int>(-2147483647, result) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexIntUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0");
	QVERIFY(s::format<uint>(9, result) == "9");
	QVERIFY(s::format<uint>(10, result) == "A");
	QVERIFY(s::format<uint>(99, result) == "63");
	QVERIFY(s::format<uint>(100, result) == "64");
	QVERIFY(s::format<uint>(255, result) == "FF");
	QVERIFY(s::format<uint>(256, result) == "100");
	QVERIFY(s::format<uint>(1000, result) == "3E8");
	QVERIFY(s::format<uint>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<uint>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<uint>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<uint>(-10, result) == "FFFFFFF6");

	QVERIFY(s::format<int>(0, result) == "0");
	QVERIFY(s::format<int>(9, result) == "9");
	QVERIFY(s::format<int>(10, result) == "A");
	QVERIFY(s::format<int>(99, result) == "63");
	QVERIFY(s::format<int>(100, result) == "64");
	QVERIFY(s::format<int>(255, result) == "FF");
	QVERIFY(s::format<int>(256, result) == "100");
	QVERIFY(s::format<int>(1000, result) == "3E8");
	QVERIFY(s::format<int>(2147483647, result) == "7FFFFFFF");
	QVERIFY(s::format<int>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<int>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<int>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<int>(-10, result) == "FFFFFFF6");
	QVERIFY(s::format<int>(-99, result) == "FFFFFF9D");
	QVERIFY(s::format<int>(-100, result) == "FFFFFF9C");
	QVERIFY(s::format<int>(-255, result) == "FFFFFF01");
	QVERIFY(s::format<int>(-256, result) == "FFFFFF00");
	QVERIFY(s::format<int>(-1000, result) == "FFFFFC18");
	QVERIFY(s::format<int>(-2147483647, result) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexIntLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "00000000");
	QVERIFY(s::format<uint>(9, result) == "00000009");
	QVERIFY(s::format<uint>(10, result) == "0000000a");
	QVERIFY(s::format<uint>(99, result) == "00000063");
	QVERIFY(s::format<uint>(100, result) == "00000064");
	QVERIFY(s::format<uint>(255, result) == "000000ff");
	QVERIFY(s::format<uint>(256, result) == "00000100");
	QVERIFY(s::format<uint>(1000, result) == "000003e8");
	QVERIFY(s::format<uint>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<uint>(-1, result) == "ffffffff");
	QVERIFY(s::format<uint>(-9, result) == "fffffff7");
	QVERIFY(s::format<uint>(-10, result) == "fffffff6");

	QVERIFY(s::format<int>(0, result) == "00000000");
	QVERIFY(s::format<int>(9, result) == "00000009");
	QVERIFY(s::format<int>(10, result) == "0000000a");
	QVERIFY(s::format<int>(99, result) == "00000063");
	QVERIFY(s::format<int>(100, result) == "00000064");
	QVERIFY(s::format<int>(255, result) == "000000ff");
	QVERIFY(s::format<int>(256, result) == "00000100");
	QVERIFY(s::format<int>(1000, result) == "000003e8");
	QVERIFY(s::format<int>(2147483647, result) == "7fffffff");
	QVERIFY(s::format<int>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<int>(-1, result) == "ffffffff");
	QVERIFY(s::format<int>(-9, result) == "fffffff7");
	QVERIFY(s::format<int>(-10, result) == "fffffff6");
	QVERIFY(s::format<int>(-99, result) == "ffffff9d");
	QVERIFY(s::format<int>(-100, result) == "ffffff9c");
	QVERIFY(s::format<int>(-255, result) == "ffffff01");
	QVERIFY(s::format<int>(-256, result) == "ffffff00");
	QVERIFY(s::format<int>(-1000, result) == "fffffc18");
	QVERIFY(s::format<int>(-2147483647, result) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "00000001");
}

void TestNumberStringifier2String::testStaticFormatHexIntLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "00000000");
	QVERIFY(s::format<uint>(9, result) == "00000009");
	QVERIFY(s::format<uint>(10, result) == "0000000A");
	QVERIFY(s::format<uint>(99, result) == "00000063");
	QVERIFY(s::format<uint>(100, result) == "00000064");
	QVERIFY(s::format<uint>(255, result) == "000000FF");
	QVERIFY(s::format<uint>(256, result) == "00000100");
	QVERIFY(s::format<uint>(1000, result) == "000003E8");
	QVERIFY(s::format<uint>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<uint>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<uint>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<uint>(-10, result) == "FFFFFFF6");

	QVERIFY(s::format<int>(0, result) == "00000000");
	QVERIFY(s::format<int>(9, result) == "00000009");
	QVERIFY(s::format<int>(10, result) == "0000000A");
	QVERIFY(s::format<int>(99, result) == "00000063");
	QVERIFY(s::format<int>(100, result) == "00000064");
	QVERIFY(s::format<int>(255, result) == "000000FF");
	QVERIFY(s::format<int>(256, result) == "00000100");
	QVERIFY(s::format<int>(1000, result) == "000003E8");
	QVERIFY(s::format<int>(2147483647, result) == "7FFFFFFF");
	QVERIFY(s::format<int>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<int>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<int>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<int>(-10, result) == "FFFFFFF6");
	QVERIFY(s::format<int>(-99, result) == "FFFFFF9D");
	QVERIFY(s::format<int>(-100, result) == "FFFFFF9C");
	QVERIFY(s::format<int>(-255, result) == "FFFFFF01");
	QVERIFY(s::format<int>(-256, result) == "FFFFFF00");
	QVERIFY(s::format<int>(-1000, result) == "FFFFFC18");
	QVERIFY(s::format<int>(-2147483647, result) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "00000001");
}

void TestNumberStringifier2String::testStaticFormatHexLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0");
	QVERIFY(s::format<ulong>(9, result) == "9");
	QVERIFY(s::format<ulong>(10, result) == "a");
	QVERIFY(s::format<ulong>(99, result) == "63");
	QVERIFY(s::format<ulong>(100, result) == "64");
	QVERIFY(s::format<ulong>(255, result) == "ff");
	QVERIFY(s::format<ulong>(256, result) == "100");
	QVERIFY(s::format<ulong>(1000, result) == "3e8");
	QVERIFY(s::format<ulong>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<ulong>(-1, result) == "ffffffff");
	QVERIFY(s::format<ulong>(-9, result) == "fffffff7");
	QVERIFY(s::format<ulong>(-10, result) == "fffffff6");

	QVERIFY(s::format<long>(0, result) == "0");
	QVERIFY(s::format<long>(9, result) == "9");
	QVERIFY(s::format<long>(10, result) == "a");
	QVERIFY(s::format<long>(99, result) == "63");
	QVERIFY(s::format<long>(100, result) == "64");
	QVERIFY(s::format<long>(255, result) == "ff");
	QVERIFY(s::format<long>(256, result) == "100");
	QVERIFY(s::format<long>(1000, result) == "3e8");
	QVERIFY(s::format<long>(2147483647, result) == "7fffffff");
	QVERIFY(s::format<long>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<long>(-1, result) == "ffffffff");
	QVERIFY(s::format<long>(-9, result) == "fffffff7");
	QVERIFY(s::format<long>(-10, result) == "fffffff6");
	QVERIFY(s::format<long>(-99, result) == "ffffff9d");
	QVERIFY(s::format<long>(-100, result) == "ffffff9c");
	QVERIFY(s::format<long>(-255, result) == "ffffff01");
	QVERIFY(s::format<long>(-256, result) == "ffffff00");
	QVERIFY(s::format<long>(-1000, result) == "fffffc18");
	QVERIFY(s::format<long>(-2147483647, result) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexLongUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0");
	QVERIFY(s::format<ulong>(9, result) == "9");
	QVERIFY(s::format<ulong>(10, result) == "A");
	QVERIFY(s::format<ulong>(99, result) == "63");
	QVERIFY(s::format<ulong>(100, result) == "64");
	QVERIFY(s::format<ulong>(255, result) == "FF");
	QVERIFY(s::format<ulong>(256, result) == "100");
	QVERIFY(s::format<ulong>(1000, result) == "3E8");
	QVERIFY(s::format<ulong>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<ulong>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<ulong>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<ulong>(-10, result) == "FFFFFFF6");

	QVERIFY(s::format<long>(0, result) == "0");
	QVERIFY(s::format<long>(9, result) == "9");
	QVERIFY(s::format<long>(10, result) == "A");
	QVERIFY(s::format<long>(99, result) == "63");
	QVERIFY(s::format<long>(100, result) == "64");
	QVERIFY(s::format<long>(255, result) == "FF");
	QVERIFY(s::format<long>(256, result) == "100");
	QVERIFY(s::format<long>(1000, result) == "3E8");
	QVERIFY(s::format<long>(2147483647, result) == "7FFFFFFF");
	QVERIFY(s::format<long>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<long>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<long>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<long>(-10, result) == "FFFFFFF6");
	QVERIFY(s::format<long>(-99, result) == "FFFFFF9D");
	QVERIFY(s::format<long>(-100, result) == "FFFFFF9C");
	QVERIFY(s::format<long>(-255, result) == "FFFFFF01");
	QVERIFY(s::format<long>(-256, result) == "FFFFFF00");
	QVERIFY(s::format<long>(-1000, result) == "FFFFFC18");
	QVERIFY(s::format<long>(-2147483647, result) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexLongLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "00000000");
	QVERIFY(s::format<ulong>(9, result) == "00000009");
	QVERIFY(s::format<ulong>(10, result) == "0000000a");
	QVERIFY(s::format<ulong>(99, result) == "00000063");
	QVERIFY(s::format<ulong>(100, result) == "00000064");
	QVERIFY(s::format<ulong>(255, result) == "000000ff");
	QVERIFY(s::format<ulong>(256, result) == "00000100");
	QVERIFY(s::format<ulong>(1000, result) == "000003e8");
	QVERIFY(s::format<ulong>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<ulong>(-1, result) == "ffffffff");
	QVERIFY(s::format<ulong>(-9, result) == "fffffff7");
	QVERIFY(s::format<ulong>(-10, result) == "fffffff6");

	QVERIFY(s::format<long>(0, result) == "00000000");
	QVERIFY(s::format<long>(9, result) == "00000009");
	QVERIFY(s::format<long>(10, result) == "0000000a");
	QVERIFY(s::format<long>(99, result) == "00000063");
	QVERIFY(s::format<long>(100, result) == "00000064");
	QVERIFY(s::format<long>(255, result) == "000000ff");
	QVERIFY(s::format<long>(256, result) == "00000100");
	QVERIFY(s::format<long>(1000, result) == "000003e8");
	QVERIFY(s::format<long>(2147483647, result) == "7fffffff");
	QVERIFY(s::format<long>(4294967295, result) == "ffffffff");

	QVERIFY(s::format<long>(-1, result) == "ffffffff");
	QVERIFY(s::format<long>(-9, result) == "fffffff7");
	QVERIFY(s::format<long>(-10, result) == "fffffff6");
	QVERIFY(s::format<long>(-99, result) == "ffffff9d");
	QVERIFY(s::format<long>(-100, result) == "ffffff9c");
	QVERIFY(s::format<long>(-255, result) == "ffffff01");
	QVERIFY(s::format<long>(-256, result) == "ffffff00");
	QVERIFY(s::format<long>(-1000, result) == "fffffc18");
	QVERIFY(s::format<long>(-2147483647, result) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "00000001");
}

void TestNumberStringifier2String::testStaticFormatHexLongLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "00000000");
	QVERIFY(s::format<ulong>(9, result) == "00000009");
	QVERIFY(s::format<ulong>(10, result) == "0000000A");
	QVERIFY(s::format<ulong>(99, result) == "00000063");
	QVERIFY(s::format<ulong>(100, result) == "00000064");
	QVERIFY(s::format<ulong>(255, result) == "000000FF");
	QVERIFY(s::format<ulong>(256, result) == "00000100");
	QVERIFY(s::format<ulong>(1000, result) == "000003E8");
	QVERIFY(s::format<ulong>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<ulong>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<ulong>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<ulong>(-10, result) == "FFFFFFF6");

	QVERIFY(s::format<long>(0, result) == "00000000");
	QVERIFY(s::format<long>(9, result) == "00000009");
	QVERIFY(s::format<long>(10, result) == "0000000A");
	QVERIFY(s::format<long>(99, result) == "00000063");
	QVERIFY(s::format<long>(100, result) == "00000064");
	QVERIFY(s::format<long>(255, result) == "000000FF");
	QVERIFY(s::format<long>(256, result) == "00000100");
	QVERIFY(s::format<long>(1000, result) == "000003E8");
	QVERIFY(s::format<long>(2147483647, result) == "7FFFFFFF");
	QVERIFY(s::format<long>(4294967295, result) == "FFFFFFFF");

	QVERIFY(s::format<long>(-1, result) == "FFFFFFFF");
	QVERIFY(s::format<long>(-9, result) == "FFFFFFF7");
	QVERIFY(s::format<long>(-10, result) == "FFFFFFF6");
	QVERIFY(s::format<long>(-99, result) == "FFFFFF9D");
	QVERIFY(s::format<long>(-100, result) == "FFFFFF9C");
	QVERIFY(s::format<long>(-255, result) == "FFFFFF01");
	QVERIFY(s::format<long>(-256, result) == "FFFFFF00");
	QVERIFY(s::format<long>(-1000, result) == "FFFFFC18");
	QVERIFY(s::format<long>(-2147483647, result) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "00000001");
}

void TestNumberStringifier2String::testStaticFormatHexInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0");
	QVERIFY(s::format<quint64>(9, result) == "9");
	QVERIFY(s::format<quint64>(10, result) == "a");
	QVERIFY(s::format<quint64>(99, result) == "63");
	QVERIFY(s::format<quint64>(100, result) == "64");
	QVERIFY(s::format<quint64>(255, result) == "ff");
	QVERIFY(s::format<quint64>(256, result) == "100");
	QVERIFY(s::format<quint64>(1000, result) == "3e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "ffffffffffffffff");

	QVERIFY(s::format<quint64>(-1, result) == "ffffffffffffffff");
	QVERIFY(s::format<quint64>(-9, result) == "fffffffffffffff7");
	QVERIFY(s::format<quint64>(-10, result) == "fffffffffffffff6");

	QVERIFY(s::format<qint64>(0, result) == "0");
	QVERIFY(s::format<qint64>(9, result) == "9");
	QVERIFY(s::format<qint64>(10, result) == "a");
	QVERIFY(s::format<qint64>(99, result) == "63");
	QVERIFY(s::format<qint64>(100, result) == "64");
	QVERIFY(s::format<qint64>(255, result) == "ff");
	QVERIFY(s::format<qint64>(256, result) == "100");
	QVERIFY(s::format<qint64>(1000, result) == "3e8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "ffffffffffffffff");

	QVERIFY(s::format<qint64>(-1, result) == "ffffffffffffffff");
	QVERIFY(s::format<qint64>(-9, result) == "fffffffffffffff7");
	QVERIFY(s::format<qint64>(-10, result) == "fffffffffffffff6");
	QVERIFY(s::format<qint64>(-99, result) == "ffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100, result) == "ffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255, result) == "ffffffffffffff01");
	QVERIFY(s::format<qint64>(-256, result) == "ffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000, result) == "fffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexInt64Upper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0");
	QVERIFY(s::format<quint64>(9, result) == "9");
	QVERIFY(s::format<quint64>(10, result) == "A");
	QVERIFY(s::format<quint64>(99, result) == "63");
	QVERIFY(s::format<quint64>(100, result) == "64");
	QVERIFY(s::format<quint64>(255, result) == "FF");
	QVERIFY(s::format<quint64>(256, result) == "100");
	QVERIFY(s::format<quint64>(1000, result) == "3E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1, result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9, result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10, result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0, result) == "0");
	QVERIFY(s::format<qint64>(9, result) == "9");
	QVERIFY(s::format<qint64>(10, result) == "A");
	QVERIFY(s::format<qint64>(99, result) == "63");
	QVERIFY(s::format<qint64>(100, result) == "64");
	QVERIFY(s::format<qint64>(255, result) == "FF");
	QVERIFY(s::format<qint64>(256, result) == "100");
	QVERIFY(s::format<qint64>(1000, result) == "3E8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1, result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9, result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10, result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99, result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100, result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255, result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256, result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000, result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "1");
}

void TestNumberStringifier2String::testStaticFormatHexInt64Lz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0000000000000000");
	QVERIFY(s::format<quint64>(9, result) == "0000000000000009");
	QVERIFY(s::format<quint64>(10, result) == "000000000000000a");
	QVERIFY(s::format<quint64>(99, result) == "0000000000000063");
	QVERIFY(s::format<quint64>(100, result) == "0000000000000064");
	QVERIFY(s::format<quint64>(255, result) == "00000000000000ff");
	QVERIFY(s::format<quint64>(256, result) == "0000000000000100");
	QVERIFY(s::format<quint64>(1000, result) == "00000000000003e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "ffffffffffffffff");

	QVERIFY(s::format<quint64>(-1, result) == "ffffffffffffffff");
	QVERIFY(s::format<quint64>(-9, result) == "fffffffffffffff7");
	QVERIFY(s::format<quint64>(-10, result) == "fffffffffffffff6");

	QVERIFY(s::format<qint64>(0, result) == "0000000000000000");
	QVERIFY(s::format<qint64>(9, result) == "0000000000000009");
	QVERIFY(s::format<qint64>(10, result) == "000000000000000a");
	QVERIFY(s::format<qint64>(99, result) == "0000000000000063");
	QVERIFY(s::format<qint64>(100, result) == "0000000000000064");
	QVERIFY(s::format<qint64>(255, result) == "00000000000000ff");
	QVERIFY(s::format<qint64>(256, result) == "0000000000000100");
	QVERIFY(s::format<qint64>(1000, result) == "00000000000003e8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "ffffffffffffffff");

	QVERIFY(s::format<qint64>(-1, result) == "ffffffffffffffff");
	QVERIFY(s::format<qint64>(-9, result) == "fffffffffffffff7");
	QVERIFY(s::format<qint64>(-10, result) == "fffffffffffffff6");
	QVERIFY(s::format<qint64>(-99, result) == "ffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100, result) == "ffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255, result) == "ffffffffffffff01");
	QVERIFY(s::format<qint64>(-256, result) == "ffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000, result) == "fffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0000000000000001");
}

void TestNumberStringifier2String::testStaticFormatHexInt64LzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0000000000000000");
	QVERIFY(s::format<quint64>(9, result) == "0000000000000009");
	QVERIFY(s::format<quint64>(10, result) == "000000000000000A");
	QVERIFY(s::format<quint64>(99, result) == "0000000000000063");
	QVERIFY(s::format<quint64>(100, result) == "0000000000000064");
	QVERIFY(s::format<quint64>(255, result) == "00000000000000FF");
	QVERIFY(s::format<quint64>(256, result) == "0000000000000100");
	QVERIFY(s::format<quint64>(1000, result) == "00000000000003E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1, result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9, result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10, result) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0, result) == "0000000000000000");
	QVERIFY(s::format<qint64>(9, result) == "0000000000000009");
	QVERIFY(s::format<qint64>(10, result) == "000000000000000A");
	QVERIFY(s::format<qint64>(99, result) == "0000000000000063");
	QVERIFY(s::format<qint64>(100, result) == "0000000000000064");
	QVERIFY(s::format<qint64>(255, result) == "00000000000000FF");
	QVERIFY(s::format<qint64>(256, result) == "0000000000000100");
	QVERIFY(s::format<qint64>(1000, result) == "00000000000003E8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1, result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9, result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10, result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99, result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100, result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255, result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256, result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000, result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0000000000000001");
}

void TestNumberStringifier2String::testStaticFormatHexCharPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0x0");
	QVERIFY(s::format<uchar>(9, result) == "0x9");
	QVERIFY(s::format<uchar>(10, result) == "0xa");
	QVERIFY(s::format<uchar>(99, result) == "0x63");
	QVERIFY(s::format<uchar>(100, result) == "0x64");
	QVERIFY(s::format<uchar>(255, result) == "0xff");

	QVERIFY(s::format<uchar>(-1, result) == "0xff");
	QVERIFY(s::format<uchar>(-9, result) == "0xf7");
	QVERIFY(s::format<uchar>(-10, result) == "0xf6");

	QVERIFY(s::format<char>(0, result) == "0x0");
	QVERIFY(s::format<char>(9, result) == "0x9");
	QVERIFY(s::format<char>(10, result) == "0xa");
	QVERIFY(s::format<char>(99, result) == "0x63");
	QVERIFY(s::format<char>(100, result) == "0x64");
	QVERIFY(s::format<char>(127, result) == "0x7f");

	QVERIFY(s::format<char>(-1, result) == "0xff");
	QVERIFY(s::format<char>(-9, result) == "0xf7");
	QVERIFY(s::format<char>(-10, result) == "0xf6");
	QVERIFY(s::format<char>(-99, result) == "0x9d");
	QVERIFY(s::format<char>(-100, result) == "0x9c");

	QVERIFY(s::format<signed char>(0, result) == "0x0");
	QVERIFY(s::format<signed char>(9, result) == "0x9");
	QVERIFY(s::format<signed char>(10, result) == "0xa");
	QVERIFY(s::format<signed char>(99, result) == "0x63");
	QVERIFY(s::format<signed char>(100, result) == "0x64");
	QVERIFY(s::format<signed char>(127, result) == "0x7f");

	QVERIFY(s::format<signed char>(-1, result) == "0xff");
	QVERIFY(s::format<signed char>(-9, result) == "0xf7");
	QVERIFY(s::format<signed char>(-10, result) == "0xf6");
	QVERIFY(s::format<signed char>(-99, result) == "0x9d");
	QVERIFY(s::format<signed char>(-100, result) == "0x9c");
}

void TestNumberStringifier2String::testStaticFormatHexCharUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0x0");
	QVERIFY(s::format<uchar>(9, result) == "0x9");
	QVERIFY(s::format<uchar>(10, result) == "0xA");
	QVERIFY(s::format<uchar>(99, result) == "0x63");
	QVERIFY(s::format<uchar>(100, result) == "0x64");
	QVERIFY(s::format<uchar>(255, result) == "0xFF");

	QVERIFY(s::format<uchar>(-1, result) == "0xFF");
	QVERIFY(s::format<uchar>(-9, result) == "0xF7");
	QVERIFY(s::format<uchar>(-10, result) == "0xF6");

	QVERIFY(s::format<char>(0, result) == "0x0");
	QVERIFY(s::format<char>(9, result) == "0x9");
	QVERIFY(s::format<char>(10, result) == "0xA");
	QVERIFY(s::format<char>(99, result) == "0x63");
	QVERIFY(s::format<char>(100, result) == "0x64");
	QVERIFY(s::format<char>(127, result) == "0x7F");

	QVERIFY(s::format<char>(-1, result) == "0xFF");
	QVERIFY(s::format<char>(-9, result) == "0xF7");
	QVERIFY(s::format<char>(-10, result) == "0xF6");
	QVERIFY(s::format<char>(-99, result) == "0x9D");
	QVERIFY(s::format<char>(-100, result) == "0x9C");

	QVERIFY(s::format<signed char>(0, result) == "0x0");
	QVERIFY(s::format<signed char>(9, result) == "0x9");
	QVERIFY(s::format<signed char>(10, result) == "0xA");
	QVERIFY(s::format<signed char>(99, result) == "0x63");
	QVERIFY(s::format<signed char>(100, result) == "0x64");
	QVERIFY(s::format<signed char>(127, result) == "0x7F");

	QVERIFY(s::format<signed char>(-1, result) == "0xFF");
	QVERIFY(s::format<signed char>(-9, result) == "0xF7");
	QVERIFY(s::format<signed char>(-10, result) == "0xF6");
	QVERIFY(s::format<signed char>(-99, result) == "0x9D");
	QVERIFY(s::format<signed char>(-100, result) == "0x9C");
}

void TestNumberStringifier2String::testStaticFormatHexCharLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0x00");
	QVERIFY(s::format<uchar>(9, result) == "0x09");
	QVERIFY(s::format<uchar>(10, result) == "0x0a");
	QVERIFY(s::format<uchar>(99, result) == "0x63");
	QVERIFY(s::format<uchar>(100, result) == "0x64");
	QVERIFY(s::format<uchar>(255, result) == "0xff");

	QVERIFY(s::format<uchar>(-1, result) == "0xff");
	QVERIFY(s::format<uchar>(-9, result) == "0xf7");
	QVERIFY(s::format<uchar>(-10, result) == "0xf6");

	QVERIFY(s::format<char>(0, result) == "0x00");
	QVERIFY(s::format<char>(9, result) == "0x09");
	QVERIFY(s::format<char>(10, result) == "0x0a");
	QVERIFY(s::format<char>(99, result) == "0x63");
	QVERIFY(s::format<char>(100, result) == "0x64");
	QVERIFY(s::format<char>(127, result) == "0x7f");

	QVERIFY(s::format<char>(-1, result) == "0xff");
	QVERIFY(s::format<char>(-9, result) == "0xf7");
	QVERIFY(s::format<char>(-10, result) == "0xf6");
	QVERIFY(s::format<char>(-99, result) == "0x9d");
	QVERIFY(s::format<char>(-100, result) == "0x9c");

	QVERIFY(s::format<signed char>(0, result) == "0x00");
	QVERIFY(s::format<signed char>(9, result) == "0x09");
	QVERIFY(s::format<signed char>(10, result) == "0x0a");
	QVERIFY(s::format<signed char>(99, result) == "0x63");
	QVERIFY(s::format<signed char>(100, result) == "0x64");
	QVERIFY(s::format<signed char>(127, result) == "0x7f");

	QVERIFY(s::format<signed char>(-1, result) == "0xff");
	QVERIFY(s::format<signed char>(-9, result) == "0xf7");
	QVERIFY(s::format<signed char>(-10, result) == "0xf6");
	QVERIFY(s::format<signed char>(-99, result) == "0x9d");
	QVERIFY(s::format<signed char>(-100, result) == "0x9c");
}

void TestNumberStringifier2String::testStaticFormatHexCharLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uchar>(0, result) == "0x00");
	QVERIFY(s::format<uchar>(9, result) == "0x09");
	QVERIFY(s::format<uchar>(10, result) == "0x0A");
	QVERIFY(s::format<uchar>(99, result) == "0x63");
	QVERIFY(s::format<uchar>(100, result) == "0x64");
	QVERIFY(s::format<uchar>(255, result) == "0xFF");

	QVERIFY(s::format<uchar>(-1, result) == "0xFF");
	QVERIFY(s::format<uchar>(-9, result) == "0xF7");
	QVERIFY(s::format<uchar>(-10, result) == "0xF6");

	QVERIFY(s::format<char>(0, result) == "0x00");
	QVERIFY(s::format<char>(9, result) == "0x09");
	QVERIFY(s::format<char>(10, result) == "0x0A");
	QVERIFY(s::format<char>(99, result) == "0x63");
	QVERIFY(s::format<char>(100, result) == "0x64");
	QVERIFY(s::format<char>(127, result) == "0x7F");

	QVERIFY(s::format<char>(-1, result) == "0xFF");
	QVERIFY(s::format<char>(-9, result) == "0xF7");
	QVERIFY(s::format<char>(-10, result) == "0xF6");
	QVERIFY(s::format<char>(-99, result) == "0x9D");
	QVERIFY(s::format<char>(-100, result) == "0x9C");

	QVERIFY(s::format<signed char>(0, result) == "0x00");
	QVERIFY(s::format<signed char>(9, result) == "0x09");
	QVERIFY(s::format<signed char>(10, result) == "0x0A");
	QVERIFY(s::format<signed char>(99, result) == "0x63");
	QVERIFY(s::format<signed char>(100, result) == "0x64");
	QVERIFY(s::format<signed char>(127, result) == "0x7F");

	QVERIFY(s::format<signed char>(-1, result) == "0xFF");
	QVERIFY(s::format<signed char>(-9, result) == "0xF7");
	QVERIFY(s::format<signed char>(-10, result) == "0xF6");
	QVERIFY(s::format<signed char>(-99, result) == "0x9D");
	QVERIFY(s::format<signed char>(-100, result) == "0x9C");
}

void TestNumberStringifier2String::testStaticFormatHexShortPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0x0");
	QVERIFY(s::format<ushort>(9, result) == "0x9");
	QVERIFY(s::format<ushort>(10, result) == "0xa");
	QVERIFY(s::format<ushort>(99, result) == "0x63");
	QVERIFY(s::format<ushort>(100, result) == "0x64");
	QVERIFY(s::format<ushort>(255, result) == "0xff");
	QVERIFY(s::format<ushort>(256, result) == "0x100");
	QVERIFY(s::format<ushort>(1000, result) == "0x3e8");
	QVERIFY(s::format<ushort>(65535, result) == "0xffff");

	QVERIFY(s::format<ushort>(-1, result) == "0xffff");
	QVERIFY(s::format<ushort>(-9, result) == "0xfff7");
	QVERIFY(s::format<ushort>(-10, result) == "0xfff6");

	QVERIFY(s::format<short>(0, result) == "0x0");
	QVERIFY(s::format<short>(9, result) == "0x9");
	QVERIFY(s::format<short>(10, result) == "0xa");
	QVERIFY(s::format<short>(99, result) == "0x63");
	QVERIFY(s::format<short>(100, result) == "0x64");
	QVERIFY(s::format<short>(255, result) == "0xff");
	QVERIFY(s::format<short>(256, result) == "0x100");
	QVERIFY(s::format<short>(1000, result) == "0x3e8");
	QVERIFY(s::format<short>(32767, result) == "0x7fff");

	QVERIFY(s::format<short>(-1, result) == "0xffff");
	QVERIFY(s::format<short>(-9, result) == "0xfff7");
	QVERIFY(s::format<short>(-10, result) == "0xfff6");
	QVERIFY(s::format<short>(-99, result) == "0xff9d");
	QVERIFY(s::format<short>(-100, result) == "0xff9c");
	QVERIFY(s::format<short>(-255, result) == "0xff01");
	QVERIFY(s::format<short>(-256, result) == "0xff00");
	QVERIFY(s::format<short>(-1000, result) == "0xfc18");
	QVERIFY(s::format<short>(-32767, result) == "0x8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0x0");
	QVERIFY(s::format<ushort>(9, result) == "0x9");
	QVERIFY(s::format<ushort>(10, result) == "0xA");
	QVERIFY(s::format<ushort>(99, result) == "0x63");
	QVERIFY(s::format<ushort>(100, result) == "0x64");
	QVERIFY(s::format<ushort>(255, result) == "0xFF");
	QVERIFY(s::format<ushort>(256, result) == "0x100");
	QVERIFY(s::format<ushort>(1000, result) == "0x3E8");
	QVERIFY(s::format<ushort>(65535, result) == "0xFFFF");

	QVERIFY(s::format<ushort>(-1, result) == "0xFFFF");
	QVERIFY(s::format<ushort>(-9, result) == "0xFFF7");
	QVERIFY(s::format<ushort>(-10, result) == "0xFFF6");

	QVERIFY(s::format<short>(0, result) == "0x0");
	QVERIFY(s::format<short>(9, result) == "0x9");
	QVERIFY(s::format<short>(10, result) == "0xA");
	QVERIFY(s::format<short>(99, result) == "0x63");
	QVERIFY(s::format<short>(100, result) == "0x64");
	QVERIFY(s::format<short>(255, result) == "0xFF");
	QVERIFY(s::format<short>(256, result) == "0x100");
	QVERIFY(s::format<short>(1000, result) == "0x3E8");
	QVERIFY(s::format<short>(32767, result) == "0x7FFF");

	QVERIFY(s::format<short>(-1, result) == "0xFFFF");
	QVERIFY(s::format<short>(-9, result) == "0xFFF7");
	QVERIFY(s::format<short>(-10, result) == "0xFFF6");
	QVERIFY(s::format<short>(-99, result) == "0xFF9D");
	QVERIFY(s::format<short>(-100, result) == "0xFF9C");
	QVERIFY(s::format<short>(-255, result) == "0xFF01");
	QVERIFY(s::format<short>(-256, result) == "0xFF00");
	QVERIFY(s::format<short>(-1000, result) == "0xFC18");
	QVERIFY(s::format<short>(-32767, result) == "0x8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0x0000");
	QVERIFY(s::format<ushort>(9, result) == "0x0009");
	QVERIFY(s::format<ushort>(10, result) == "0x000a");
	QVERIFY(s::format<ushort>(99, result) == "0x0063");
	QVERIFY(s::format<ushort>(100, result) == "0x0064");
	QVERIFY(s::format<ushort>(255, result) == "0x00ff");
	QVERIFY(s::format<ushort>(256, result) == "0x0100");
	QVERIFY(s::format<ushort>(1000, result) == "0x03e8");
	QVERIFY(s::format<ushort>(65535, result) == "0xffff");

	QVERIFY(s::format<ushort>(-1, result) == "0xffff");
	QVERIFY(s::format<ushort>(-9, result) == "0xfff7");
	QVERIFY(s::format<ushort>(-10, result) == "0xfff6");

	QVERIFY(s::format<short>(0, result) == "0x0000");
	QVERIFY(s::format<short>(9, result) == "0x0009");
	QVERIFY(s::format<short>(10, result) == "0x000a");
	QVERIFY(s::format<short>(99, result) == "0x0063");
	QVERIFY(s::format<short>(100, result) == "0x0064");
	QVERIFY(s::format<short>(255, result) == "0x00ff");
	QVERIFY(s::format<short>(256, result) == "0x0100");
	QVERIFY(s::format<short>(1000, result) == "0x03e8");
	QVERIFY(s::format<short>(32767, result) == "0x7fff");

	QVERIFY(s::format<short>(-1, result) == "0xffff");
	QVERIFY(s::format<short>(-9, result) == "0xfff7");
	QVERIFY(s::format<short>(-10, result) == "0xfff6");
	QVERIFY(s::format<short>(-99, result) == "0xff9d");
	QVERIFY(s::format<short>(-100, result) == "0xff9c");
	QVERIFY(s::format<short>(-255, result) == "0xff01");
	QVERIFY(s::format<short>(-256, result) == "0xff00");
	QVERIFY(s::format<short>(-1000, result) == "0xfc18");
	QVERIFY(s::format<short>(-32767, result) == "0x8001");
}

void TestNumberStringifier2String::testStaticFormatHexShortLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ushort>(0, result) == "0x0000");
	QVERIFY(s::format<ushort>(9, result) == "0x0009");
	QVERIFY(s::format<ushort>(10, result) == "0x000A");
	QVERIFY(s::format<ushort>(99, result) == "0x0063");
	QVERIFY(s::format<ushort>(100, result) == "0x0064");
	QVERIFY(s::format<ushort>(255, result) == "0x00FF");
	QVERIFY(s::format<ushort>(256, result) == "0x0100");
	QVERIFY(s::format<ushort>(1000, result) == "0x03E8");
	QVERIFY(s::format<ushort>(65535, result) == "0xFFFF");

	QVERIFY(s::format<ushort>(-1, result) == "0xFFFF");
	QVERIFY(s::format<ushort>(-9, result) == "0xFFF7");
	QVERIFY(s::format<ushort>(-10, result) == "0xFFF6");

	QVERIFY(s::format<short>(0, result) == "0x0000");
	QVERIFY(s::format<short>(9, result) == "0x0009");
	QVERIFY(s::format<short>(10, result) == "0x000A");
	QVERIFY(s::format<short>(99, result) == "0x0063");
	QVERIFY(s::format<short>(100, result) == "0x0064");
	QVERIFY(s::format<short>(255, result) == "0x00FF");
	QVERIFY(s::format<short>(256, result) == "0x0100");
	QVERIFY(s::format<short>(1000, result) == "0x03E8");
	QVERIFY(s::format<short>(32767, result) == "0x7FFF");

	QVERIFY(s::format<short>(-1, result) == "0xFFFF");
	QVERIFY(s::format<short>(-9, result) == "0xFFF7");
	QVERIFY(s::format<short>(-10, result) == "0xFFF6");
	QVERIFY(s::format<short>(-99, result) == "0xFF9D");
	QVERIFY(s::format<short>(-100, result) == "0xFF9C");
	QVERIFY(s::format<short>(-255, result) == "0xFF01");
	QVERIFY(s::format<short>(-256, result) == "0xFF00");
	QVERIFY(s::format<short>(-1000, result) == "0xFC18");
	QVERIFY(s::format<short>(-32767, result) == "0x8001");
}

void TestNumberStringifier2String::testStaticFormatHexIntPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0x0");
	QVERIFY(s::format<uint>(9, result) == "0x9");
	QVERIFY(s::format<uint>(10, result) == "0xa");
	QVERIFY(s::format<uint>(99, result) == "0x63");
	QVERIFY(s::format<uint>(100, result) == "0x64");
	QVERIFY(s::format<uint>(255, result) == "0xff");
	QVERIFY(s::format<uint>(256, result) == "0x100");
	QVERIFY(s::format<uint>(1000, result) == "0x3e8");
	QVERIFY(s::format<uint>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<uint>(-1, result) == "0xffffffff");
	QVERIFY(s::format<uint>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<uint>(-10, result) == "0xfffffff6");

	QVERIFY(s::format<int>(0, result) == "0x0");
	QVERIFY(s::format<int>(9, result) == "0x9");
	QVERIFY(s::format<int>(10, result) == "0xa");
	QVERIFY(s::format<int>(99, result) == "0x63");
	QVERIFY(s::format<int>(100, result) == "0x64");
	QVERIFY(s::format<int>(255, result) == "0xff");
	QVERIFY(s::format<int>(256, result) == "0x100");
	QVERIFY(s::format<int>(1000, result) == "0x3e8");
	QVERIFY(s::format<int>(2147483647, result) == "0x7fffffff");
	QVERIFY(s::format<int>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<int>(-1, result) == "0xffffffff");
	QVERIFY(s::format<int>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<int>(-10, result) == "0xfffffff6");
	QVERIFY(s::format<int>(-99, result) == "0xffffff9d");
	QVERIFY(s::format<int>(-100, result) == "0xffffff9c");
	QVERIFY(s::format<int>(-255, result) == "0xffffff01");
	QVERIFY(s::format<int>(-256, result) == "0xffffff00");
	QVERIFY(s::format<int>(-1000, result) == "0xfffffc18");
	QVERIFY(s::format<int>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexIntUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0x0");
	QVERIFY(s::format<uint>(9, result) == "0x9");
	QVERIFY(s::format<uint>(10, result) == "0xA");
	QVERIFY(s::format<uint>(99, result) == "0x63");
	QVERIFY(s::format<uint>(100, result) == "0x64");
	QVERIFY(s::format<uint>(255, result) == "0xFF");
	QVERIFY(s::format<uint>(256, result) == "0x100");
	QVERIFY(s::format<uint>(1000, result) == "0x3E8");
	QVERIFY(s::format<uint>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<uint>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<uint>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<uint>(-10, result) == "0xFFFFFFF6");

	QVERIFY(s::format<int>(0, result) == "0x0");
	QVERIFY(s::format<int>(9, result) == "0x9");
	QVERIFY(s::format<int>(10, result) == "0xA");
	QVERIFY(s::format<int>(99, result) == "0x63");
	QVERIFY(s::format<int>(100, result) == "0x64");
	QVERIFY(s::format<int>(255, result) == "0xFF");
	QVERIFY(s::format<int>(256, result) == "0x100");
	QVERIFY(s::format<int>(1000, result) == "0x3E8");
	QVERIFY(s::format<int>(2147483647, result) == "0x7FFFFFFF");
	QVERIFY(s::format<int>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<int>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<int>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<int>(-10, result) == "0xFFFFFFF6");
	QVERIFY(s::format<int>(-99, result) == "0xFFFFFF9D");
	QVERIFY(s::format<int>(-100, result) == "0xFFFFFF9C");
	QVERIFY(s::format<int>(-255, result) == "0xFFFFFF01");
	QVERIFY(s::format<int>(-256, result) == "0xFFFFFF00");
	QVERIFY(s::format<int>(-1000, result) == "0xFFFFFC18");
	QVERIFY(s::format<int>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexIntLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0x00000000");
	QVERIFY(s::format<uint>(9, result) == "0x00000009");
	QVERIFY(s::format<uint>(10, result) == "0x0000000a");
	QVERIFY(s::format<uint>(99, result) == "0x00000063");
	QVERIFY(s::format<uint>(100, result) == "0x00000064");
	QVERIFY(s::format<uint>(255, result) == "0x000000ff");
	QVERIFY(s::format<uint>(256, result) == "0x00000100");
	QVERIFY(s::format<uint>(1000, result) == "0x000003e8");
	QVERIFY(s::format<uint>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<uint>(-1, result) == "0xffffffff");
	QVERIFY(s::format<uint>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<uint>(-10, result) == "0xfffffff6");

	QVERIFY(s::format<int>(0, result) == "0x00000000");
	QVERIFY(s::format<int>(9, result) == "0x00000009");
	QVERIFY(s::format<int>(10, result) == "0x0000000a");
	QVERIFY(s::format<int>(99, result) == "0x00000063");
	QVERIFY(s::format<int>(100, result) == "0x00000064");
	QVERIFY(s::format<int>(255, result) == "0x000000ff");
	QVERIFY(s::format<int>(256, result) == "0x00000100");
	QVERIFY(s::format<int>(1000, result) == "0x000003e8");
	QVERIFY(s::format<int>(2147483647, result) == "0x7fffffff");
	QVERIFY(s::format<int>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<int>(-1, result) == "0xffffffff");
	QVERIFY(s::format<int>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<int>(-10, result) == "0xfffffff6");
	QVERIFY(s::format<int>(-99, result) == "0xffffff9d");
	QVERIFY(s::format<int>(-100, result) == "0xffffff9c");
	QVERIFY(s::format<int>(-255, result) == "0xffffff01");
	QVERIFY(s::format<int>(-256, result) == "0xffffff00");
	QVERIFY(s::format<int>(-1000, result) == "0xfffffc18");
	QVERIFY(s::format<int>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0x00000001");
}

void TestNumberStringifier2String::testStaticFormatHexIntLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<uint>(0, result) == "0x00000000");
	QVERIFY(s::format<uint>(9, result) == "0x00000009");
	QVERIFY(s::format<uint>(10, result) == "0x0000000A");
	QVERIFY(s::format<uint>(99, result) == "0x00000063");
	QVERIFY(s::format<uint>(100, result) == "0x00000064");
	QVERIFY(s::format<uint>(255, result) == "0x000000FF");
	QVERIFY(s::format<uint>(256, result) == "0x00000100");
	QVERIFY(s::format<uint>(1000, result) == "0x000003E8");
	QVERIFY(s::format<uint>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<uint>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<uint>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<uint>(-10, result) == "0xFFFFFFF6");

	QVERIFY(s::format<int>(0, result) == "0x00000000");
	QVERIFY(s::format<int>(9, result) == "0x00000009");
	QVERIFY(s::format<int>(10, result) == "0x0000000A");
	QVERIFY(s::format<int>(99, result) == "0x00000063");
	QVERIFY(s::format<int>(100, result) == "0x00000064");
	QVERIFY(s::format<int>(255, result) == "0x000000FF");
	QVERIFY(s::format<int>(256, result) == "0x00000100");
	QVERIFY(s::format<int>(1000, result) == "0x000003E8");
	QVERIFY(s::format<int>(2147483647, result) == "0x7FFFFFFF");
	QVERIFY(s::format<int>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<int>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<int>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<int>(-10, result) == "0xFFFFFFF6");
	QVERIFY(s::format<int>(-99, result) == "0xFFFFFF9D");
	QVERIFY(s::format<int>(-100, result) == "0xFFFFFF9C");
	QVERIFY(s::format<int>(-255, result) == "0xFFFFFF01");
	QVERIFY(s::format<int>(-256, result) == "0xFFFFFF00");
	QVERIFY(s::format<int>(-1000, result) == "0xFFFFFC18");
	QVERIFY(s::format<int>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL, result) == "0x00000001");
}

void TestNumberStringifier2String::testStaticFormatHexLongPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0x0");
	QVERIFY(s::format<ulong>(9, result) == "0x9");
	QVERIFY(s::format<ulong>(10, result) == "0xa");
	QVERIFY(s::format<ulong>(99, result) == "0x63");
	QVERIFY(s::format<ulong>(100, result) == "0x64");
	QVERIFY(s::format<ulong>(255, result) == "0xff");
	QVERIFY(s::format<ulong>(256, result) == "0x100");
	QVERIFY(s::format<ulong>(1000, result) == "0x3e8");
	QVERIFY(s::format<ulong>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<ulong>(-1, result) == "0xffffffff");
	QVERIFY(s::format<ulong>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<ulong>(-10, result) == "0xfffffff6");

	QVERIFY(s::format<long>(0, result) == "0x0");
	QVERIFY(s::format<long>(9, result) == "0x9");
	QVERIFY(s::format<long>(10, result) == "0xa");
	QVERIFY(s::format<long>(99, result) == "0x63");
	QVERIFY(s::format<long>(100, result) == "0x64");
	QVERIFY(s::format<long>(255, result) == "0xff");
	QVERIFY(s::format<long>(256, result) == "0x100");
	QVERIFY(s::format<long>(1000, result) == "0x3e8");
	QVERIFY(s::format<long>(2147483647, result) == "0x7fffffff");
	QVERIFY(s::format<long>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<long>(-1, result) == "0xffffffff");
	QVERIFY(s::format<long>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<long>(-10, result) == "0xfffffff6");
	QVERIFY(s::format<long>(-99, result) == "0xffffff9d");
	QVERIFY(s::format<long>(-100, result) == "0xffffff9c");
	QVERIFY(s::format<long>(-255, result) == "0xffffff01");
	QVERIFY(s::format<long>(-256, result) == "0xffffff00");
	QVERIFY(s::format<long>(-1000, result) == "0xfffffc18");
	QVERIFY(s::format<long>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexLongUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0x0");
	QVERIFY(s::format<ulong>(9, result) == "0x9");
	QVERIFY(s::format<ulong>(10, result) == "0xA");
	QVERIFY(s::format<ulong>(99, result) == "0x63");
	QVERIFY(s::format<ulong>(100, result) == "0x64");
	QVERIFY(s::format<ulong>(255, result) == "0xFF");
	QVERIFY(s::format<ulong>(256, result) == "0x100");
	QVERIFY(s::format<ulong>(1000, result) == "0x3E8");
	QVERIFY(s::format<ulong>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<ulong>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<ulong>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<ulong>(-10, result) == "0xFFFFFFF6");

	QVERIFY(s::format<long>(0, result) == "0x0");
	QVERIFY(s::format<long>(9, result) == "0x9");
	QVERIFY(s::format<long>(10, result) == "0xA");
	QVERIFY(s::format<long>(99, result) == "0x63");
	QVERIFY(s::format<long>(100, result) == "0x64");
	QVERIFY(s::format<long>(255, result) == "0xFF");
	QVERIFY(s::format<long>(256, result) == "0x100");
	QVERIFY(s::format<long>(1000, result) == "0x3E8");
	QVERIFY(s::format<long>(2147483647, result) == "0x7FFFFFFF");
	QVERIFY(s::format<long>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<long>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<long>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<long>(-10, result) == "0xFFFFFFF6");
	QVERIFY(s::format<long>(-99, result) == "0xFFFFFF9D");
	QVERIFY(s::format<long>(-100, result) == "0xFFFFFF9C");
	QVERIFY(s::format<long>(-255, result) == "0xFFFFFF01");
	QVERIFY(s::format<long>(-256, result) == "0xFFFFFF00");
	QVERIFY(s::format<long>(-1000, result) == "0xFFFFFC18");
	QVERIFY(s::format<long>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexLongLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0x00000000");
	QVERIFY(s::format<ulong>(9, result) == "0x00000009");
	QVERIFY(s::format<ulong>(10, result) == "0x0000000a");
	QVERIFY(s::format<ulong>(99, result) == "0x00000063");
	QVERIFY(s::format<ulong>(100, result) == "0x00000064");
	QVERIFY(s::format<ulong>(255, result) == "0x000000ff");
	QVERIFY(s::format<ulong>(256, result) == "0x00000100");
	QVERIFY(s::format<ulong>(1000, result) == "0x000003e8");
	QVERIFY(s::format<ulong>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<ulong>(-1, result) == "0xffffffff");
	QVERIFY(s::format<ulong>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<ulong>(-10, result) == "0xfffffff6");

	QVERIFY(s::format<long>(0, result) == "0x00000000");
	QVERIFY(s::format<long>(9, result) == "0x00000009");
	QVERIFY(s::format<long>(10, result) == "0x0000000a");
	QVERIFY(s::format<long>(99, result) == "0x00000063");
	QVERIFY(s::format<long>(100, result) == "0x00000064");
	QVERIFY(s::format<long>(255, result) == "0x000000ff");
	QVERIFY(s::format<long>(256, result) == "0x00000100");
	QVERIFY(s::format<long>(1000, result) == "0x000003e8");
	QVERIFY(s::format<long>(2147483647, result) == "0x7fffffff");
	QVERIFY(s::format<long>(4294967295, result) == "0xffffffff");

	QVERIFY(s::format<long>(-1, result) == "0xffffffff");
	QVERIFY(s::format<long>(-9, result) == "0xfffffff7");
	QVERIFY(s::format<long>(-10, result) == "0xfffffff6");
	QVERIFY(s::format<long>(-99, result) == "0xffffff9d");
	QVERIFY(s::format<long>(-100, result) == "0xffffff9c");
	QVERIFY(s::format<long>(-255, result) == "0xffffff01");
	QVERIFY(s::format<long>(-256, result) == "0xffffff00");
	QVERIFY(s::format<long>(-1000, result) == "0xfffffc18");
	QVERIFY(s::format<long>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0x00000001");
}

void TestNumberStringifier2String::testStaticFormatHexLongLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<ulong>(0, result) == "0x00000000");
	QVERIFY(s::format<ulong>(9, result) == "0x00000009");
	QVERIFY(s::format<ulong>(10, result) == "0x0000000A");
	QVERIFY(s::format<ulong>(99, result) == "0x00000063");
	QVERIFY(s::format<ulong>(100, result) == "0x00000064");
	QVERIFY(s::format<ulong>(255, result) == "0x000000FF");
	QVERIFY(s::format<ulong>(256, result) == "0x00000100");
	QVERIFY(s::format<ulong>(1000, result) == "0x000003E8");
	QVERIFY(s::format<ulong>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<ulong>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<ulong>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<ulong>(-10, result) == "0xFFFFFFF6");

	QVERIFY(s::format<long>(0, result) == "0x00000000");
	QVERIFY(s::format<long>(9, result) == "0x00000009");
	QVERIFY(s::format<long>(10, result) == "0x0000000A");
	QVERIFY(s::format<long>(99, result) == "0x00000063");
	QVERIFY(s::format<long>(100, result) == "0x00000064");
	QVERIFY(s::format<long>(255, result) == "0x000000FF");
	QVERIFY(s::format<long>(256, result) == "0x00000100");
	QVERIFY(s::format<long>(1000, result) == "0x000003E8");
	QVERIFY(s::format<long>(2147483647, result) == "0x7FFFFFFF");
	QVERIFY(s::format<long>(4294967295, result) == "0xFFFFFFFF");

	QVERIFY(s::format<long>(-1, result) == "0xFFFFFFFF");
	QVERIFY(s::format<long>(-9, result) == "0xFFFFFFF7");
	QVERIFY(s::format<long>(-10, result) == "0xFFFFFFF6");
	QVERIFY(s::format<long>(-99, result) == "0xFFFFFF9D");
	QVERIFY(s::format<long>(-100, result) == "0xFFFFFF9C");
	QVERIFY(s::format<long>(-255, result) == "0xFFFFFF01");
	QVERIFY(s::format<long>(-256, result) == "0xFFFFFF00");
	QVERIFY(s::format<long>(-1000, result) == "0xFFFFFC18");
	QVERIFY(s::format<long>(-2147483647, result) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL, result) == "0x00000001");
}

void TestNumberStringifier2String::testStaticFormatHexInt64Prefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0x0");
	QVERIFY(s::format<quint64>(9, result) == "0x9");
	QVERIFY(s::format<quint64>(10, result) == "0xa");
	QVERIFY(s::format<quint64>(99, result) == "0x63");
	QVERIFY(s::format<quint64>(100, result) == "0x64");
	QVERIFY(s::format<quint64>(255, result) == "0xff");
	QVERIFY(s::format<quint64>(256, result) == "0x100");
	QVERIFY(s::format<quint64>(1000, result) == "0x3e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "0xffffffffffffffff");

	QVERIFY(s::format<quint64>(-1, result) == "0xffffffffffffffff");
	QVERIFY(s::format<quint64>(-9, result) == "0xfffffffffffffff7");
	QVERIFY(s::format<quint64>(-10, result) == "0xfffffffffffffff6");

	QVERIFY(s::format<qint64>(0, result) == "0x0");
	QVERIFY(s::format<qint64>(9, result) == "0x9");
	QVERIFY(s::format<qint64>(10, result) == "0xa");
	QVERIFY(s::format<qint64>(99, result) == "0x63");
	QVERIFY(s::format<qint64>(100, result) == "0x64");
	QVERIFY(s::format<qint64>(255, result) == "0xff");
	QVERIFY(s::format<qint64>(256, result) == "0x100");
	QVERIFY(s::format<qint64>(1000, result) == "0x3e8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "0x7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "0xffffffffffffffff");

	QVERIFY(s::format<qint64>(-1, result) == "0xffffffffffffffff");
	QVERIFY(s::format<qint64>(-9, result) == "0xfffffffffffffff7");
	QVERIFY(s::format<qint64>(-10, result) == "0xfffffffffffffff6");
	QVERIFY(s::format<qint64>(-99, result) == "0xffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100, result) == "0xffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255, result) == "0xffffffffffffff01");
	QVERIFY(s::format<qint64>(-256, result) == "0xffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000, result) == "0xfffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexInt64UpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0x0");
	QVERIFY(s::format<quint64>(9, result) == "0x9");
	QVERIFY(s::format<quint64>(10, result) == "0xA");
	QVERIFY(s::format<quint64>(99, result) == "0x63");
	QVERIFY(s::format<quint64>(100, result) == "0x64");
	QVERIFY(s::format<quint64>(255, result) == "0xFF");
	QVERIFY(s::format<quint64>(256, result) == "0x100");
	QVERIFY(s::format<quint64>(1000, result) == "0x3E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1, result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9, result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10, result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0, result) == "0x0");
	QVERIFY(s::format<qint64>(9, result) == "0x9");
	QVERIFY(s::format<qint64>(10, result) == "0xA");
	QVERIFY(s::format<qint64>(99, result) == "0x63");
	QVERIFY(s::format<qint64>(100, result) == "0x64");
	QVERIFY(s::format<qint64>(255, result) == "0xFF");
	QVERIFY(s::format<qint64>(256, result) == "0x100");
	QVERIFY(s::format<qint64>(1000, result) == "0x3E8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1, result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9, result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10, result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99, result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100, result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255, result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256, result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000, result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0x1");
}

void TestNumberStringifier2String::testStaticFormatHexInt64LzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0x0000000000000000");
	QVERIFY(s::format<quint64>(9, result) == "0x0000000000000009");
	QVERIFY(s::format<quint64>(10, result) == "0x000000000000000a");
	QVERIFY(s::format<quint64>(99, result) == "0x0000000000000063");
	QVERIFY(s::format<quint64>(100, result) == "0x0000000000000064");
	QVERIFY(s::format<quint64>(255, result) == "0x00000000000000ff");
	QVERIFY(s::format<quint64>(256, result) == "0x0000000000000100");
	QVERIFY(s::format<quint64>(1000, result) == "0x00000000000003e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "0xffffffffffffffff");

	QVERIFY(s::format<quint64>(-1, result) == "0xffffffffffffffff");
	QVERIFY(s::format<quint64>(-9, result) == "0xfffffffffffffff7");
	QVERIFY(s::format<quint64>(-10, result) == "0xfffffffffffffff6");

	QVERIFY(s::format<qint64>(0, result) == "0x0000000000000000");
	QVERIFY(s::format<qint64>(9, result) == "0x0000000000000009");
	QVERIFY(s::format<qint64>(10, result) == "0x000000000000000a");
	QVERIFY(s::format<qint64>(99, result) == "0x0000000000000063");
	QVERIFY(s::format<qint64>(100, result) == "0x0000000000000064");
	QVERIFY(s::format<qint64>(255, result) == "0x00000000000000ff");
	QVERIFY(s::format<qint64>(256, result) == "0x0000000000000100");
	QVERIFY(s::format<qint64>(1000, result) == "0x00000000000003e8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "0x7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "0xffffffffffffffff");

	QVERIFY(s::format<qint64>(-1, result) == "0xffffffffffffffff");
	QVERIFY(s::format<qint64>(-9, result) == "0xfffffffffffffff7");
	QVERIFY(s::format<qint64>(-10, result) == "0xfffffffffffffff6");
	QVERIFY(s::format<qint64>(-99, result) == "0xffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100, result) == "0xffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255, result) == "0xffffffffffffff01");
	QVERIFY(s::format<qint64>(-256, result) == "0xffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000, result) == "0xfffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0x0000000000000001");
}

void TestNumberStringifier2String::testStaticFormatHexInt64LzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format<quint64>(0, result) == "0x0000000000000000");
	QVERIFY(s::format<quint64>(9, result) == "0x0000000000000009");
	QVERIFY(s::format<quint64>(10, result) == "0x000000000000000A");
	QVERIFY(s::format<quint64>(99, result) == "0x0000000000000063");
	QVERIFY(s::format<quint64>(100, result) == "0x0000000000000064");
	QVERIFY(s::format<quint64>(255, result) == "0x00000000000000FF");
	QVERIFY(s::format<quint64>(256, result) == "0x0000000000000100");
	QVERIFY(s::format<quint64>(1000, result) == "0x00000000000003E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL, result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1, result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9, result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10, result) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0, result) == "0x0000000000000000");
	QVERIFY(s::format<qint64>(9, result) == "0x0000000000000009");
	QVERIFY(s::format<qint64>(10, result) == "0x000000000000000A");
	QVERIFY(s::format<qint64>(99, result) == "0x0000000000000063");
	QVERIFY(s::format<qint64>(100, result) == "0x0000000000000064");
	QVERIFY(s::format<qint64>(255, result) == "0x00000000000000FF");
	QVERIFY(s::format<qint64>(256, result) == "0x0000000000000100");
	QVERIFY(s::format<qint64>(1000, result) == "0x00000000000003E8");
	QVERIFY(s::format<qint64>(9223372036854775807, result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL, result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1, result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9, result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10, result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99, result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100, result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255, result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256, result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000, result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807, result) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL, result) == "0x0000000000000001");
}

QTEST_MAIN(TestNumberStringifier2String)
#include "test_numberstringifier2string.moc"

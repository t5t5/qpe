#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

class TestNumberStringifier2ByteArray : public QObject
{
	Q_OBJECT
private slots:
	void benchIntStringifierValue();
	void benchIntStaticStringifierValue();
	void benchIntStaticStringifierRef();
	void benchIntDataByteStatic();
	void benchIntDataByteMember();

	void testDecimalDigitsCount();
	void testHexadecimalDigitsCount();
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

void TestNumberStringifier2ByteArray::benchIntStringifierValue()
{
//	Qpe::Stringifier st;
//	int n = 0;
//	QBENCHMARK {
//		for (int i = -500000; i <= 500000; ++i) {
//			n += st.format(i).size();
//		}
//	}
//	qDebug() << n;
}

void TestNumberStringifier2ByteArray::benchIntStaticStringifierValue()
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

void TestNumberStringifier2ByteArray::benchIntStaticStringifierRef()
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

void TestNumberStringifier2ByteArray::benchIntDataByteStatic()
{
	int n = 0;
	QBENCHMARK {
		for (int i = -500000; i <= 500000; ++i) {
			n += QByteArray::number(i).size();
		}
	}
	qDebug() << n;
}

void TestNumberStringifier2ByteArray::benchIntDataByteMember()
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

void TestNumberStringifier2ByteArray::testDecimalDigitsCount()
{
	QVERIFY(Qpe::decimalDigitsCount<uchar>(255) == 3);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<uchar>(0) == 1);

	QVERIFY(Qpe::decimalDigitsCount<ushort>(65535) == 5);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<ushort>(0) == 1);

	QVERIFY(Qpe::decimalDigitsCount<uint>(4294967295) == 10);
	QVERIFY(Qpe::decimalDigitsCount<uint>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<uint>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<uint>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<uint>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<uint>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<uint>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<uint>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<uint>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<uint>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<uint>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<uint>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<uint>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<uint>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<uint>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<uint>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<uint>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<uint>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<uint>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<uint>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<uint>(0) == 1);

	QVERIFY(Qpe::decimalDigitsCount<ulong>(4294967295) == 10);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<ulong>(0) == 1);

	QVERIFY(Qpe::decimalDigitsCount<quint64>(0xffffffffffffffffULL) == 20);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000000000000000000ULL) == 20);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999999999999999999ULL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<quint64>(0) == 1);

	QVERIFY(Qpe::decimalDigitsCount<char>(127) == 3);
	QVERIFY(Qpe::decimalDigitsCount<char>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<char>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<char>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<char>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<char>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<char>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<char>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<char>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<char>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<char>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<char>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<char>(-128) == 3);

	QVERIFY(Qpe::decimalDigitsCount<short>(32767) == 5);
	QVERIFY(Qpe::decimalDigitsCount<short>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<short>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<short>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<short>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<short>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<short>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<short>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<short>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<short>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<short>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<short>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<short>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<short>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<short>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<short>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<short>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<short>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<short>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<short>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<short>(-32768) == 5);

	QVERIFY(Qpe::decimalDigitsCount<int>(2147483647) == 10);
	QVERIFY(Qpe::decimalDigitsCount<int>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<int>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<int>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<int>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<int>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<int>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<int>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<int>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<int>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<int>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<int>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<int>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<int>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<int>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<int>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<int>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<int>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<int>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<int>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<int>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<int>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<int>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<int>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<int>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<int>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<int>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<int>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<int>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<int>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<int>(-99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<int>(-100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<int>(-999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<int>(-1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<int>(-9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<int>(-10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<int>(-99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<int>(-100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<int>(-999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<int>(-1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<int>((-2147483647L - 1)) == 10);

	QVERIFY(Qpe::decimalDigitsCount<qint64>(9223372036854775807LL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999999999999999999ULL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<qint64>(-9223372036854775807LL - 1) == 19);
}

void TestNumberStringifier2ByteArray::testHexadecimalDigitsCount()
{
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0xff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x10) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x0f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x01) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x00) == 1);

	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0xffff) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x1000) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0fff) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0100) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x00ff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0010) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x000f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0001) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0000) == 1);

	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0xffffffff) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x10000000) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x0fffffff) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x01000000) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00ffffff) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00100000) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x000fffff) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00010000) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x0000ffff) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00001000) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00000fff) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00000100) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x000000ff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00000010) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x0000000f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00000001) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uint>(0x00000000) == 1);

	QVERIFY(Qpe::hexadecimalDigitsCount<long>(0xffffffff) == 8);

	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0xffffffff) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x10000000) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x0fffffff) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x01000000) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00ffffff) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00100000) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x000fffff) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00010000) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x0000ffff) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00001000) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00000fff) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00000100) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x000000ff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00000010) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x0000000f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00000001) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ulong>(0x00000000) == 1);

	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0xffffffffffffffff) == 16);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x1fffffffffffffff) == 16);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0fffffffffffffff) == 15);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x01ffffffffffffff) == 15);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00ffffffffffffff) == 14);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x001fffffffffffff) == 14);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x000fffffffffffff) == 13);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00010000ffffffff) == 13);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000ffffffffffff) == 12);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00001000ffffffff) == 12);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000fffffffffff) == 11);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000100ffffffff) == 11);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x000000ffffffffff) == 10);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000010ffffffff) == 10);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000fffffffff) == 9);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000001ffffffff) == 9);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000000ffffffff) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000010000000) == 8);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x000000000fffffff) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000001000000) == 7);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000ffffff) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000100000) == 6);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000000000fffff) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000010000) == 5);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x000000000000ffff) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000001000) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000000fff) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000000100) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x00000000000000ff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000000010) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x000000000000000f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000000001) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<quint64>(0x0000000000000000) == 1);
}

void TestNumberStringifier2ByteArray::testStaticFormatDecChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format<uchar>(0) == "0");
	QVERIFY(s::format<uchar>(9) == "9");
	QVERIFY(s::format<uchar>(10) == "10");
	QVERIFY(s::format<uchar>(99) == "99");
	QVERIFY(s::format<uchar>(100) == "100");
	QVERIFY(s::format<uchar>(255) == "255");

	QVERIFY(s::format<uchar>(-1) == "255");
	QVERIFY(s::format<uchar>(-9) == "247");
	QVERIFY(s::format<uchar>(-10) == "246");

	QVERIFY(s::format<char>(0) == "0");
	QVERIFY(s::format<char>(9) == "9");
	QVERIFY(s::format<char>(10) == "10");
	QVERIFY(s::format<char>(99) == "99");
	QVERIFY(s::format<char>(100) == "100");
	QVERIFY(s::format<char>(127) == "127");

	QVERIFY(s::format<char>(-1) == "-1");
	QVERIFY(s::format<char>(-9) == "-9");
	QVERIFY(s::format<char>(-10) == "-10");
	QVERIFY(s::format<char>(-99) == "-99");
	QVERIFY(s::format<char>(-100) == "-100");
//	QVERIFY(s::format<char>(-128) == "-128");
	QVERIFY(s::format<char>(-255 & 0xff) == "1");

	QVERIFY(s::format<signed char>(0) == "0");
	QVERIFY(s::format<signed char>(9) == "9");
	QVERIFY(s::format<signed char>(10) == "10");
	QVERIFY(s::format<signed char>(99) == "99");
	QVERIFY(s::format<signed char>(100) == "100");
	QVERIFY(s::format<signed char>(127) == "127");

	QVERIFY(s::format<signed char>(-1) == "-1");
	QVERIFY(s::format<signed char>(-9) == "-9");
	QVERIFY(s::format<signed char>(-10) == "-10");
	QVERIFY(s::format<signed char>(-99) == "-99");
	QVERIFY(s::format<signed char>(-100) == "-100");
//	QVERIFY(s::format<signed char>(-128) == "-128");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecCharLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<uchar>(0) == "000");
	QVERIFY(s::format<uchar>(9) == "009");
	QVERIFY(s::format<uchar>(10) == "010");
	QVERIFY(s::format<uchar>(99) == "099");
	QVERIFY(s::format<uchar>(100) == "100");
	QVERIFY(s::format<uchar>(255) == "255");

	QVERIFY(s::format<uchar>(-1) == "255");
	QVERIFY(s::format<uchar>(-9) == "247");
	QVERIFY(s::format<uchar>(-10) == "246");

	QVERIFY(s::format<char>(0) == "000");
	QVERIFY(s::format<char>(9) == "009");
	QVERIFY(s::format<char>(10) == "010");
	QVERIFY(s::format<char>(99) == "099");
	QVERIFY(s::format<char>(100) == "100");
	QVERIFY(s::format<char>(127) == "127");

	QVERIFY(s::format<char>(-1) == "-001");
	QVERIFY(s::format<char>(-9) == "-009");
	QVERIFY(s::format<char>(-10) == "-010");
	QVERIFY(s::format<char>(-99) == "-099");
	QVERIFY(s::format<char>(-100) == "-100");
//	QVERIFY(s::format<char>(-128) == "-128");
	QVERIFY(s::format<char>(-255 & 0xff) == "001");

	QVERIFY(s::format<signed char>(0) == "000");
	QVERIFY(s::format<signed char>(9) == "009");
	QVERIFY(s::format<signed char>(10) == "010");
	QVERIFY(s::format<signed char>(99) == "099");
	QVERIFY(s::format<signed char>(100) == "100");
	QVERIFY(s::format<signed char>(127) == "127");

	QVERIFY(s::format<signed char>(-1) == "-001");
	QVERIFY(s::format<signed char>(-9) == "-009");
	QVERIFY(s::format<signed char>(-10) == "-010");
	QVERIFY(s::format<signed char>(-99) == "-099");
	QVERIFY(s::format<signed char>(-100) == "-100");
//	QVERIFY(s::format<signed char>(-128) == "-128");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format<ushort>(0) == "0");
	QVERIFY(s::format<ushort>(9) == "9");
	QVERIFY(s::format<ushort>(10) == "10");
	QVERIFY(s::format<ushort>(99) == "99");
	QVERIFY(s::format<ushort>(100) == "100");
	QVERIFY(s::format<ushort>(255) == "255");
	QVERIFY(s::format<ushort>(256) == "256");
	QVERIFY(s::format<ushort>(1000) == "1000");
	QVERIFY(s::format<ushort>(65535) == "65535");

	QVERIFY(s::format<ushort>(-1) == "65535");
	QVERIFY(s::format<ushort>(-9) == "65527");
	QVERIFY(s::format<ushort>(-10) == "65526");

	QVERIFY(s::format<short>(0) == "0");
	QVERIFY(s::format<short>(9) == "9");
	QVERIFY(s::format<short>(10) == "10");
	QVERIFY(s::format<short>(99) == "99");
	QVERIFY(s::format<short>(100) == "100");
	QVERIFY(s::format<short>(255) == "255");
	QVERIFY(s::format<short>(256) == "256");
	QVERIFY(s::format<short>(1000) == "1000");
	QVERIFY(s::format<short>(32767) == "32767");

	QVERIFY(s::format<short>(-1) == "-1");
	QVERIFY(s::format<short>(-9) == "-9");
	QVERIFY(s::format<short>(-10) == "-10");
	QVERIFY(s::format<short>(-99) == "-99");
	QVERIFY(s::format<short>(-100) == "-100");
	QVERIFY(s::format<short>(-255) == "-255");
	QVERIFY(s::format<short>(-256) == "-256");
	QVERIFY(s::format<short>(-1000) == "-1000");
	QVERIFY(s::format<short>(-32767) == "-32767");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecShortLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<ushort>(0) == "00000");
	QVERIFY(s::format<ushort>(9) == "00009");
	QVERIFY(s::format<ushort>(10) == "00010");
	QVERIFY(s::format<ushort>(99) == "00099");
	QVERIFY(s::format<ushort>(100) == "00100");
	QVERIFY(s::format<ushort>(255) == "00255");
	QVERIFY(s::format<ushort>(256) == "00256");
	QVERIFY(s::format<ushort>(1000) == "01000");
	QVERIFY(s::format<ushort>(65535) == "65535");

	QVERIFY(s::format<ushort>(-1) == "65535");
	QVERIFY(s::format<ushort>(-9) == "65527");
	QVERIFY(s::format<ushort>(-10) == "65526");

	QVERIFY(s::format<short>(0) == "00000");
	QVERIFY(s::format<short>(9) == "00009");
	QVERIFY(s::format<short>(10) == "00010");
	QVERIFY(s::format<short>(99) == "00099");
	QVERIFY(s::format<short>(100) == "00100");
	QVERIFY(s::format<short>(255) == "00255");
	QVERIFY(s::format<short>(256) == "00256");
	QVERIFY(s::format<short>(1000) == "01000");
	QVERIFY(s::format<short>(32767) == "32767");

	QVERIFY(s::format<short>(-1) == "-00001");
	QVERIFY(s::format<short>(-9) == "-00009");
	QVERIFY(s::format<short>(-10) == "-00010");
	QVERIFY(s::format<short>(-99) == "-00099");
	QVERIFY(s::format<short>(-100) == "-00100");
	QVERIFY(s::format<short>(-255) == "-00255");
	QVERIFY(s::format<short>(-256) == "-00256");
	QVERIFY(s::format<short>(-1000) == "-01000");
	QVERIFY(s::format<short>(-32767) == "-32767");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "00001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format<uint>(0) == "0");
	QVERIFY(s::format<uint>(9) == "9");
	QVERIFY(s::format<uint>(10) == "10");
	QVERIFY(s::format<uint>(99) == "99");
	QVERIFY(s::format<uint>(100) == "100");
	QVERIFY(s::format<uint>(255) == "255");
	QVERIFY(s::format<uint>(256) == "256");
	QVERIFY(s::format<uint>(1000) == "1000");
	QVERIFY(s::format<uint>(4294967295) == "4294967295");

	QVERIFY(s::format<uint>(-1) == "4294967295");
	QVERIFY(s::format<uint>(-9) == "4294967287");
	QVERIFY(s::format<uint>(-10) == "4294967286");

	QVERIFY(s::format<int>(0) == "0");
	QVERIFY(s::format<int>(9) == "9");
	QVERIFY(s::format<int>(10) == "10");
	QVERIFY(s::format<int>(99) == "99");
	QVERIFY(s::format<int>(100) == "100");
	QVERIFY(s::format<int>(255) == "255");
	QVERIFY(s::format<int>(256) == "256");
	QVERIFY(s::format<int>(1000) == "1000");
	QVERIFY(s::format<int>(2147483647) == "2147483647");
	QVERIFY(s::format<int>(4294967295) == "-1");

	QVERIFY(s::format<int>(-1) == "-1");
	QVERIFY(s::format<int>(-9) == "-9");
	QVERIFY(s::format<int>(-10) == "-10");
	QVERIFY(s::format<int>(-99) == "-99");
	QVERIFY(s::format<int>(-100) == "-100");
	QVERIFY(s::format<int>(-255) == "-255");
	QVERIFY(s::format<int>(-256) == "-256");
	QVERIFY(s::format<int>(-1000) == "-1000");
	QVERIFY(s::format<int>(-2147483647) == "-2147483647");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecIntLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<uint>(0) == "0000000000");
	QVERIFY(s::format<uint>(9) == "0000000009");
	QVERIFY(s::format<uint>(10) == "0000000010");
	QVERIFY(s::format<uint>(99) == "0000000099");
	QVERIFY(s::format<uint>(100) == "0000000100");
	QVERIFY(s::format<uint>(255) == "0000000255");
	QVERIFY(s::format<uint>(256) == "0000000256");
	QVERIFY(s::format<uint>(1000) == "0000001000");
	QVERIFY(s::format<uint>(4294967295) == "4294967295");

	QVERIFY(s::format<uint>(-1) == "4294967295");
	QVERIFY(s::format<uint>(-9) == "4294967287");
	QVERIFY(s::format<uint>(-10) == "4294967286");

	QVERIFY(s::format<int>(0) == "0000000000");
	QVERIFY(s::format<int>(9) == "0000000009");
	QVERIFY(s::format<int>(10) == "0000000010");
	QVERIFY(s::format<int>(99) == "0000000099");
	QVERIFY(s::format<int>(100) == "0000000100");
	QVERIFY(s::format<int>(255) == "0000000255");
	QVERIFY(s::format<int>(256) == "0000000256");
	QVERIFY(s::format<int>(1000) == "0000001000");
	QVERIFY(s::format<int>(2147483647) == "2147483647");
	QVERIFY(s::format<int>(4294967295) == "-0000000001");

	QVERIFY(s::format<int>(-1) == "-0000000001");
	QVERIFY(s::format<int>(-9) == "-0000000009");
	QVERIFY(s::format<int>(-10) == "-0000000010");
	QVERIFY(s::format<int>(-99) == "-0000000099");
	QVERIFY(s::format<int>(-100) == "-0000000100");
	QVERIFY(s::format<int>(-255) == "-0000000255");
	QVERIFY(s::format<int>(-256) == "-0000000256");
	QVERIFY(s::format<int>(-1000) == "-0000001000");
	QVERIFY(s::format<int>(-2147483647) == "-2147483647");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format<ulong>(0) == "0");
	QVERIFY(s::format<ulong>(9) == "9");
	QVERIFY(s::format<ulong>(10) == "10");
	QVERIFY(s::format<ulong>(99) == "99");
	QVERIFY(s::format<ulong>(100) == "100");
	QVERIFY(s::format<ulong>(255) == "255");
	QVERIFY(s::format<ulong>(256) == "256");
	QVERIFY(s::format<ulong>(1000) == "1000");
	QVERIFY(s::format<ulong>(4294967295) == "4294967295");

	QVERIFY(s::format<ulong>(-1) == "4294967295");
	QVERIFY(s::format<ulong>(-9) == "4294967287");
	QVERIFY(s::format<ulong>(-10) == "4294967286");

	QVERIFY(s::format<long>(0) == "0");
	QVERIFY(s::format<long>(9) == "9");
	QVERIFY(s::format<long>(10) == "10");
	QVERIFY(s::format<long>(99) == "99");
	QVERIFY(s::format<long>(100) == "100");
	QVERIFY(s::format<long>(255) == "255");
	QVERIFY(s::format<long>(256) == "256");
	QVERIFY(s::format<long>(1000) == "1000");
	QVERIFY(s::format<long>(2147483647) == "2147483647");
	QVERIFY(s::format<long>(4294967295) == "-1");

	QVERIFY(s::format<long>(-1) == "-1");
	QVERIFY(s::format<long>(-9) == "-9");
	QVERIFY(s::format<long>(-10) == "-10");
	QVERIFY(s::format<long>(-99) == "-99");
	QVERIFY(s::format<long>(-100) == "-100");
	QVERIFY(s::format<long>(-255) == "-255");
	QVERIFY(s::format<long>(-256) == "-256");
	QVERIFY(s::format<long>(-1000) == "-1000");
	QVERIFY(s::format<long>(-2147483647) == "-2147483647");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecLongLz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<ulong>(0) == "0000000000");
	QVERIFY(s::format<ulong>(9) == "0000000009");
	QVERIFY(s::format<ulong>(10) == "0000000010");
	QVERIFY(s::format<ulong>(99) == "0000000099");
	QVERIFY(s::format<ulong>(100) == "0000000100");
	QVERIFY(s::format<ulong>(255) == "0000000255");
	QVERIFY(s::format<ulong>(256) == "0000000256");
	QVERIFY(s::format<ulong>(1000) == "0000001000");
	QVERIFY(s::format<ulong>(4294967295) == "4294967295");

	QVERIFY(s::format<ulong>(-1) == "4294967295");
	QVERIFY(s::format<ulong>(-9) == "4294967287");
	QVERIFY(s::format<ulong>(-10) == "4294967286");

	QVERIFY(s::format<long>(0) == "0000000000");
	QVERIFY(s::format<long>(9) == "0000000009");
	QVERIFY(s::format<long>(10) == "0000000010");
	QVERIFY(s::format<long>(99) == "0000000099");
	QVERIFY(s::format<long>(100) == "0000000100");
	QVERIFY(s::format<long>(255) == "0000000255");
	QVERIFY(s::format<long>(256) == "0000000256");
	QVERIFY(s::format<long>(1000) == "0000001000");
	QVERIFY(s::format<long>(2147483647) == "2147483647");
	QVERIFY(s::format<long>(4294967295) == "-0000000001");

	QVERIFY(s::format<long>(-1) == "-0000000001");
	QVERIFY(s::format<long>(-9) == "-0000000009");
	QVERIFY(s::format<long>(-10) == "-0000000010");
	QVERIFY(s::format<long>(-99) == "-0000000099");
	QVERIFY(s::format<long>(-100) == "-0000000100");
	QVERIFY(s::format<long>(-255) == "-0000000255");
	QVERIFY(s::format<long>(-256) == "-0000000256");
	QVERIFY(s::format<long>(-1000) == "-0000001000");
	QVERIFY(s::format<long>(-2147483647) == "-2147483647");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format<quint64>(0) == "0");
	QVERIFY(s::format<quint64>(9) == "9");
	QVERIFY(s::format<quint64>(10) == "10");
	QVERIFY(s::format<quint64>(99) == "99");
	QVERIFY(s::format<quint64>(100) == "100");
	QVERIFY(s::format<quint64>(255) == "255");
	QVERIFY(s::format<quint64>(256) == "256");
	QVERIFY(s::format<quint64>(1000) == "1000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "18446744073709551615");

	QVERIFY(s::format<quint64>(-1) == "18446744073709551615");
	QVERIFY(s::format<quint64>(-9) == "18446744073709551607");
	QVERIFY(s::format<quint64>(-10) == "18446744073709551606");

	QVERIFY(s::format<qint64>(0) == "0");
	QVERIFY(s::format<qint64>(9) == "9");
	QVERIFY(s::format<qint64>(10) == "10");
	QVERIFY(s::format<qint64>(99) == "99");
	QVERIFY(s::format<qint64>(100) == "100");
	QVERIFY(s::format<qint64>(255) == "255");
	QVERIFY(s::format<qint64>(256) == "256");
	QVERIFY(s::format<qint64>(1000) == "1000");
	QVERIFY(s::format<qint64>(9223372036854775807) == "9223372036854775807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "-1");

	QVERIFY(s::format<qint64>(-1) == "-1");
	QVERIFY(s::format<qint64>(-9) == "-9");
	QVERIFY(s::format<qint64>(-10) == "-10");
	QVERIFY(s::format<qint64>(-99) == "-99");
	QVERIFY(s::format<qint64>(-100) == "-100");
	QVERIFY(s::format<qint64>(-255) == "-255");
	QVERIFY(s::format<qint64>(-256) == "-256");
	QVERIFY(s::format<qint64>(-1000) == "-1000");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "-9223372036854775807");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatDecInt64Lz()
{
	// ---- with leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<quint64>(0) == "00000000000000000000");
	QVERIFY(s::format<quint64>(9) == "00000000000000000009");
	QVERIFY(s::format<quint64>(10) == "00000000000000000010");
	QVERIFY(s::format<quint64>(99) == "00000000000000000099");
	QVERIFY(s::format<quint64>(100) == "00000000000000000100");
	QVERIFY(s::format<quint64>(255) == "00000000000000000255");
	QVERIFY(s::format<quint64>(256) == "00000000000000000256");
	QVERIFY(s::format<quint64>(1000) == "00000000000000001000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "18446744073709551615");

	QVERIFY(s::format<quint64>(-1) == "18446744073709551615");
	QVERIFY(s::format<quint64>(-9) == "18446744073709551607");
	QVERIFY(s::format<quint64>(-10) == "18446744073709551606");

	QVERIFY(s::format<qint64>(0) == "0000000000000000000");
	QVERIFY(s::format<qint64>(9) == "0000000000000000009");
	QVERIFY(s::format<qint64>(10) == "0000000000000000010");
	QVERIFY(s::format<qint64>(99) == "0000000000000000099");
	QVERIFY(s::format<qint64>(100) == "0000000000000000100");
	QVERIFY(s::format<qint64>(255) == "0000000000000000255");
	QVERIFY(s::format<qint64>(256) == "0000000000000000256");
	QVERIFY(s::format<qint64>(1000) == "0000000000000001000");
	QVERIFY(s::format<qint64>(9223372036854775807) == "9223372036854775807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "-0000000000000000001");

	QVERIFY(s::format<qint64>(-1) == "-0000000000000000001");
	QVERIFY(s::format<qint64>(-9) == "-0000000000000000009");
	QVERIFY(s::format<qint64>(-10) == "-0000000000000000010");
	QVERIFY(s::format<qint64>(-99) == "-0000000000000000099");
	QVERIFY(s::format<qint64>(-100) == "-0000000000000000100");
	QVERIFY(s::format<qint64>(-255) == "-0000000000000000255");
	QVERIFY(s::format<qint64>(-256) == "-0000000000000000256");
	QVERIFY(s::format<qint64>(-1000) == "-0000000000000001000");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "-9223372036854775807");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0000000000000000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec2DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format<uchar>(0) == "00");
	QVERIFY(s::format<uchar>(9) == "09");
	QVERIFY(s::format<uchar>(10) == "10");
	QVERIFY(s::format<uchar>(99) == "99");
	QVERIFY(s::format<uchar>(100) == "00");
	QVERIFY(s::format<uchar>(255) == "55");

	QVERIFY(s::format<uchar>(-1) == "55");
	QVERIFY(s::format<uchar>(-9) == "47");
	QVERIFY(s::format<uchar>(-10) == "46");

	QVERIFY(s::format<char>(0) == "00");
	QVERIFY(s::format<char>(9) == "09");
	QVERIFY(s::format<char>(10) == "10");
	QVERIFY(s::format<char>(99) == "99");
	QVERIFY(s::format<char>(100) == "00");
	QVERIFY(s::format<char>(127) == "27");

	QVERIFY(s::format<char>(-1) == "55");
	QVERIFY(s::format<char>(-9) == "47");
	QVERIFY(s::format<char>(-10) == "46");
	QVERIFY(s::format<char>(-99) == "57");
	QVERIFY(s::format<char>(-100) == "56");

	QVERIFY(s::format<signed char>(0) == "00");
	QVERIFY(s::format<signed char>(9) == "09");
	QVERIFY(s::format<signed char>(10) == "10");
	QVERIFY(s::format<signed char>(99) == "99");
	QVERIFY(s::format<signed char>(100) == "00");
	QVERIFY(s::format<signed char>(127) == "27");

	QVERIFY(s::format<signed char>(-1) == "55");
	QVERIFY(s::format<signed char>(-9) == "47");
	QVERIFY(s::format<signed char>(-10) == "46");
	QVERIFY(s::format<signed char>(-99) == "57");
	QVERIFY(s::format<signed char>(-100) == "56");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec2DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format<ushort>(0) == "00");
	QVERIFY(s::format<ushort>(9) == "09");
	QVERIFY(s::format<ushort>(10) == "10");
	QVERIFY(s::format<ushort>(99) == "99");
	QVERIFY(s::format<ushort>(100) == "00");
	QVERIFY(s::format<ushort>(255) == "55");
	QVERIFY(s::format<ushort>(256) == "56");
	QVERIFY(s::format<ushort>(1000) == "00");
	QVERIFY(s::format<ushort>(65535) == "35");

	QVERIFY(s::format<ushort>(-1) == "35");
	QVERIFY(s::format<ushort>(-9) == "27");
	QVERIFY(s::format<ushort>(-10) == "26");

	QVERIFY(s::format<short>(0) == "00");
	QVERIFY(s::format<short>(9) == "09");
	QVERIFY(s::format<short>(10) == "10");
	QVERIFY(s::format<short>(99) == "99");
	QVERIFY(s::format<short>(100) == "00");
	QVERIFY(s::format<short>(255) == "55");
	QVERIFY(s::format<short>(256) == "56");
	QVERIFY(s::format<short>(1000) == "00");
	QVERIFY(s::format<short>(32767) == "67");

	QVERIFY(s::format<short>(-1) == "35");
	QVERIFY(s::format<short>(-9) == "27");
	QVERIFY(s::format<short>(-10) == "26");
	QVERIFY(s::format<short>(-99) == "37");
	QVERIFY(s::format<short>(-100) == "36");
	QVERIFY(s::format<short>(-255) == "81");
	QVERIFY(s::format<short>(-256) == "80");
	QVERIFY(s::format<short>(-1000) == "36");
	QVERIFY(s::format<short>(-32767) == "69");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec2DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format<uint>(0) == "00");
	QVERIFY(s::format<uint>(9) == "09");
	QVERIFY(s::format<uint>(10) == "10");
	QVERIFY(s::format<uint>(99) == "99");
	QVERIFY(s::format<uint>(100) == "00");
	QVERIFY(s::format<uint>(255) == "55");
	QVERIFY(s::format<uint>(256) == "56");
	QVERIFY(s::format<uint>(1000) == "00");
	QVERIFY(s::format<uint>(4294967295) == "95");

	QVERIFY(s::format<uint>(-1) == "95");
	QVERIFY(s::format<uint>(-9) == "87");
	QVERIFY(s::format<uint>(-10) == "86");

	QVERIFY(s::format<int>(0) == "00");
	QVERIFY(s::format<int>(9) == "09");
	QVERIFY(s::format<int>(10) == "10");
	QVERIFY(s::format<int>(99) == "99");
	QVERIFY(s::format<int>(100) == "00");
	QVERIFY(s::format<int>(255) == "55");
	QVERIFY(s::format<int>(256) == "56");
	QVERIFY(s::format<int>(1000) == "00");
	QVERIFY(s::format<int>(2147483647) == "47");
	QVERIFY(s::format<int>(4294967295) == "95");

	QVERIFY(s::format<int>(-1) == "95");
	QVERIFY(s::format<int>(-9) == "87");
	QVERIFY(s::format<int>(-10) == "86");
	QVERIFY(s::format<int>(-99) == "97");
	QVERIFY(s::format<int>(-100) == "96");
	QVERIFY(s::format<int>(-255) == "41");
	QVERIFY(s::format<int>(-256) == "40");
	QVERIFY(s::format<int>(-1000) == "96");
	QVERIFY(s::format<int>(-2147483647) == "49");
	QVERIFY(s::format<int>(0-4294967295UL) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec2DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format<ulong>(0) == "00");
	QVERIFY(s::format<ulong>(9) == "09");
	QVERIFY(s::format<ulong>(10) == "10");
	QVERIFY(s::format<ulong>(99) == "99");
	QVERIFY(s::format<ulong>(100) == "00");
	QVERIFY(s::format<ulong>(255) == "55");
	QVERIFY(s::format<ulong>(256) == "56");
	QVERIFY(s::format<ulong>(1000) == "00");
	QVERIFY(s::format<ulong>(4294967295) == "95");

	QVERIFY(s::format<ulong>(-1) == "95");
	QVERIFY(s::format<ulong>(-9) == "87");
	QVERIFY(s::format<ulong>(-10) == "86");

	QVERIFY(s::format<long>(0) == "00");
	QVERIFY(s::format<long>(9) == "09");
	QVERIFY(s::format<long>(10) == "10");
	QVERIFY(s::format<long>(99) == "99");
	QVERIFY(s::format<long>(100) == "00");
	QVERIFY(s::format<long>(255) == "55");
	QVERIFY(s::format<long>(256) == "56");
	QVERIFY(s::format<long>(1000) == "00");
	QVERIFY(s::format<long>(2147483647) == "47");
	QVERIFY(s::format<long>(4294967295) == "95");

	QVERIFY(s::format<long>(-1) == "95");
	QVERIFY(s::format<long>(-9) == "87");
	QVERIFY(s::format<long>(-10) == "86");
	QVERIFY(s::format<long>(-99) == "97");
	QVERIFY(s::format<long>(-100) == "96");
	QVERIFY(s::format<long>(-255) == "41");
	QVERIFY(s::format<long>(-256) == "40");
	QVERIFY(s::format<long>(-1000) == "96");
	QVERIFY(s::format<long>(-2147483647) == "49");
	QVERIFY(s::format<long>(0-4294967295UL) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec2DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format<quint64>(0) == "00");
	QVERIFY(s::format<quint64>(9) == "09");
	QVERIFY(s::format<quint64>(10) == "10");
	QVERIFY(s::format<quint64>(99) == "99");
	QVERIFY(s::format<quint64>(100) == "00");
	QVERIFY(s::format<quint64>(255) == "55");
	QVERIFY(s::format<quint64>(256) == "56");
	QVERIFY(s::format<quint64>(1000) == "00");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "15");

	QVERIFY(s::format<quint64>(-1) == "15");
	QVERIFY(s::format<quint64>(-9) == "07");
	QVERIFY(s::format<quint64>(-10) == "06");

	QVERIFY(s::format<qint64>(0) == "00");
	QVERIFY(s::format<qint64>(9) == "09");
	QVERIFY(s::format<qint64>(10) == "10");
	QVERIFY(s::format<qint64>(99) == "99");
	QVERIFY(s::format<qint64>(100) == "00");
	QVERIFY(s::format<qint64>(255) == "55");
	QVERIFY(s::format<qint64>(256) == "56");
	QVERIFY(s::format<qint64>(1000) == "00");
	QVERIFY(s::format<qint64>(9223372036854775807) == "07");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "15");

	QVERIFY(s::format<qint64>(-1) == "15");
	QVERIFY(s::format<qint64>(-9) == "07");
	QVERIFY(s::format<qint64>(-10) == "06");
	QVERIFY(s::format<qint64>(-99) == "17");
	QVERIFY(s::format<qint64>(-100) == "16");
	QVERIFY(s::format<qint64>(-255) == "61");
	QVERIFY(s::format<qint64>(-256) == "60");
	QVERIFY(s::format<qint64>(-1000) == "16");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "09");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec3DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format<uchar>(0) == "000");
	QVERIFY(s::format<uchar>(9) == "009");
	QVERIFY(s::format<uchar>(10) == "010");
	QVERIFY(s::format<uchar>(99) == "099");
	QVERIFY(s::format<uchar>(100) == "100");
	QVERIFY(s::format<uchar>(255) == "255");

	QVERIFY(s::format<uchar>(-1) == "255");
	QVERIFY(s::format<uchar>(-9) == "247");
	QVERIFY(s::format<uchar>(-10) == "246");

	QVERIFY(s::format<char>(0) == "000");
	QVERIFY(s::format<char>(9) == "009");
	QVERIFY(s::format<char>(10) == "010");
	QVERIFY(s::format<char>(99) == "099");
	QVERIFY(s::format<char>(100) == "100");
	QVERIFY(s::format<char>(127) == "127");

	QVERIFY(s::format<char>(-1) == "255");
	QVERIFY(s::format<char>(-9) == "247");
	QVERIFY(s::format<char>(-10) == "246");
	QVERIFY(s::format<char>(-99) == "157");
	QVERIFY(s::format<char>(-100) == "156");
	QVERIFY(s::format<char>(-255 & 0xff) == "001");

	QVERIFY(s::format<signed char>(0) == "000");
	QVERIFY(s::format<signed char>(9) == "009");
	QVERIFY(s::format<signed char>(10) == "010");
	QVERIFY(s::format<signed char>(99) == "099");
	QVERIFY(s::format<signed char>(100) == "100");
	QVERIFY(s::format<signed char>(127) == "127");

	QVERIFY(s::format<signed char>(-1) == "255");
	QVERIFY(s::format<signed char>(-9) == "247");
	QVERIFY(s::format<signed char>(-10) == "246");
	QVERIFY(s::format<signed char>(-99) == "157");
	QVERIFY(s::format<signed char>(-100) == "156");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec3DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format<ushort>(0) == "000");
	QVERIFY(s::format<ushort>(9) == "009");
	QVERIFY(s::format<ushort>(10) == "010");
	QVERIFY(s::format<ushort>(99) == "099");
	QVERIFY(s::format<ushort>(100) == "100");
	QVERIFY(s::format<ushort>(255) == "255");
	QVERIFY(s::format<ushort>(256) == "256");
	QVERIFY(s::format<ushort>(1000) == "000");
	QVERIFY(s::format<ushort>(65535) == "535");

	QVERIFY(s::format<ushort>(-1) == "535");
	QVERIFY(s::format<ushort>(-9) == "527");
	QVERIFY(s::format<ushort>(-10) == "526");

	QVERIFY(s::format<short>(0) == "000");
	QVERIFY(s::format<short>(9) == "009");
	QVERIFY(s::format<short>(10) == "010");
	QVERIFY(s::format<short>(99) == "099");
	QVERIFY(s::format<short>(100) == "100");
	QVERIFY(s::format<short>(255) == "255");
	QVERIFY(s::format<short>(256) == "256");
	QVERIFY(s::format<short>(1000) == "000");
	QVERIFY(s::format<short>(32767) == "767");

	QVERIFY(s::format<short>(-1) == "535");
	QVERIFY(s::format<short>(-9) == "527");
	QVERIFY(s::format<short>(-10) == "526");
	QVERIFY(s::format<short>(-99) == "437");
	QVERIFY(s::format<short>(-100) == "436");
	QVERIFY(s::format<short>(-255) == "281");
	QVERIFY(s::format<short>(-256) == "280");
	QVERIFY(s::format<short>(-1000) == "536");
	QVERIFY(s::format<short>(-32767) == "769");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec3DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format<uint>(0) == "000");
	QVERIFY(s::format<uint>(9) == "009");
	QVERIFY(s::format<uint>(10) == "010");
	QVERIFY(s::format<uint>(99) == "099");
	QVERIFY(s::format<uint>(100) == "100");
	QVERIFY(s::format<uint>(255) == "255");
	QVERIFY(s::format<uint>(256) == "256");
	QVERIFY(s::format<uint>(1000) == "000");
	QVERIFY(s::format<uint>(4294967295) == "295");

	QVERIFY(s::format<uint>(-1) == "295");
	QVERIFY(s::format<uint>(-9) == "287");
	QVERIFY(s::format<uint>(-10) == "286");

	QVERIFY(s::format<int>(0) == "000");
	QVERIFY(s::format<int>(9) == "009");
	QVERIFY(s::format<int>(10) == "010");
	QVERIFY(s::format<int>(99) == "099");
	QVERIFY(s::format<int>(100) == "100");
	QVERIFY(s::format<int>(255) == "255");
	QVERIFY(s::format<int>(256) == "256");
	QVERIFY(s::format<int>(1000) == "000");
	QVERIFY(s::format<int>(2147483647) == "647");
	QVERIFY(s::format<int>(4294967295) == "295");

	QVERIFY(s::format<int>(-1) == "295");
	QVERIFY(s::format<int>(-9) == "287");
	QVERIFY(s::format<int>(-10) == "286");
	QVERIFY(s::format<int>(-99) == "197");
	QVERIFY(s::format<int>(-100) == "196");
	QVERIFY(s::format<int>(-255) == "041");
	QVERIFY(s::format<int>(-256) == "040");
	QVERIFY(s::format<int>(-1000) == "296");
	QVERIFY(s::format<int>(-2147483647) == "649");
	QVERIFY(s::format<int>(0-4294967295UL) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec3DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format<ulong>(0) == "000");
	QVERIFY(s::format<ulong>(9) == "009");
	QVERIFY(s::format<ulong>(10) == "010");
	QVERIFY(s::format<ulong>(99) == "099");
	QVERIFY(s::format<ulong>(100) == "100");
	QVERIFY(s::format<ulong>(255) == "255");
	QVERIFY(s::format<ulong>(256) == "256");
	QVERIFY(s::format<ulong>(1000) == "000");
	QVERIFY(s::format<ulong>(4294967295) == "295");

	QVERIFY(s::format<ulong>(-1) == "295");
	QVERIFY(s::format<ulong>(-9) == "287");
	QVERIFY(s::format<ulong>(-10) == "286");

	QVERIFY(s::format<long>(0) == "000");
	QVERIFY(s::format<long>(9) == "009");
	QVERIFY(s::format<long>(10) == "010");
	QVERIFY(s::format<long>(99) == "099");
	QVERIFY(s::format<long>(100) == "100");
	QVERIFY(s::format<long>(255) == "255");
	QVERIFY(s::format<long>(256) == "256");
	QVERIFY(s::format<long>(1000) == "000");
	QVERIFY(s::format<long>(2147483647) == "647");
	QVERIFY(s::format<long>(4294967295) == "295");

	QVERIFY(s::format<long>(-1) == "295");
	QVERIFY(s::format<long>(-9) == "287");
	QVERIFY(s::format<long>(-10) == "286");
	QVERIFY(s::format<long>(-99) == "197");
	QVERIFY(s::format<long>(-100) == "196");
	QVERIFY(s::format<long>(-255) == "041");
	QVERIFY(s::format<long>(-256) == "040");
	QVERIFY(s::format<long>(-1000) == "296");
	QVERIFY(s::format<long>(-2147483647) == "649");
	QVERIFY(s::format<long>(0-4294967295UL) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec3DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format<quint64>(0) == "000");
	QVERIFY(s::format<quint64>(9) == "009");
	QVERIFY(s::format<quint64>(10) == "010");
	QVERIFY(s::format<quint64>(99) == "099");
	QVERIFY(s::format<quint64>(100) == "100");
	QVERIFY(s::format<quint64>(255) == "255");
	QVERIFY(s::format<quint64>(256) == "256");
	QVERIFY(s::format<quint64>(1000) == "000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "615");

	QVERIFY(s::format<quint64>(-1) == "615");
	QVERIFY(s::format<quint64>(-9) == "607");
	QVERIFY(s::format<quint64>(-10) == "606");

	QVERIFY(s::format<qint64>(0) == "000");
	QVERIFY(s::format<qint64>(9) == "009");
	QVERIFY(s::format<qint64>(10) == "010");
	QVERIFY(s::format<qint64>(99) == "099");
	QVERIFY(s::format<qint64>(100) == "100");
	QVERIFY(s::format<qint64>(255) == "255");
	QVERIFY(s::format<qint64>(256) == "256");
	QVERIFY(s::format<qint64>(1000) == "000");
	QVERIFY(s::format<qint64>(9223372036854775807) == "807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "615");

	QVERIFY(s::format<qint64>(-1) == "615");
	QVERIFY(s::format<qint64>(-9) == "607");
	QVERIFY(s::format<qint64>(-10) == "606");
	QVERIFY(s::format<qint64>(-99) == "517");
	QVERIFY(s::format<qint64>(-100) == "516");
	QVERIFY(s::format<qint64>(-255) == "361");
	QVERIFY(s::format<qint64>(-256) == "360");
	QVERIFY(s::format<qint64>(-1000) == "616");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "809");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec4DigitsChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format<uchar>(0) == "0000");
	QVERIFY(s::format<uchar>(9) == "0009");
	QVERIFY(s::format<uchar>(10) == "0010");
	QVERIFY(s::format<uchar>(99) == "0099");
	QVERIFY(s::format<uchar>(100) == "0100");
	QVERIFY(s::format<uchar>(255) == "0255");

	QVERIFY(s::format<uchar>(-1) == "0255");
	QVERIFY(s::format<uchar>(-9) == "0247");
	QVERIFY(s::format<uchar>(-10) == "0246");

	QVERIFY(s::format<char>(0) == "0000");
	QVERIFY(s::format<char>(9) == "0009");
	QVERIFY(s::format<char>(10) == "0010");
	QVERIFY(s::format<char>(99) == "0099");
	QVERIFY(s::format<char>(100) == "0100");
	QVERIFY(s::format<char>(127) == "0127");

	QVERIFY(s::format<char>(-1) == "0255");
	QVERIFY(s::format<char>(-9) == "0247");
	QVERIFY(s::format<char>(-10) == "0246");
	QVERIFY(s::format<char>(-99) == "0157");
	QVERIFY(s::format<char>(-100) == "0156");
	QVERIFY(s::format<char>(-255 & 0xff) == "0001");

	QVERIFY(s::format<signed char>(0) == "0000");
	QVERIFY(s::format<signed char>(9) == "0009");
	QVERIFY(s::format<signed char>(10) == "0010");
	QVERIFY(s::format<signed char>(99) == "0099");
	QVERIFY(s::format<signed char>(100) == "0100");
	QVERIFY(s::format<signed char>(127) == "0127");

	QVERIFY(s::format<signed char>(-1) == "0255");
	QVERIFY(s::format<signed char>(-9) == "0247");
	QVERIFY(s::format<signed char>(-10) == "0246");
	QVERIFY(s::format<signed char>(-99) == "0157");
	QVERIFY(s::format<signed char>(-100) == "0156");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec4DigitsShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format<ushort>(0) == "0000");
	QVERIFY(s::format<ushort>(9) == "0009");
	QVERIFY(s::format<ushort>(10) == "0010");
	QVERIFY(s::format<ushort>(99) == "0099");
	QVERIFY(s::format<ushort>(100) == "0100");
	QVERIFY(s::format<ushort>(255) == "0255");
	QVERIFY(s::format<ushort>(256) == "0256");
	QVERIFY(s::format<ushort>(1000) == "1000");
	QVERIFY(s::format<ushort>(65535) == "5535");

	QVERIFY(s::format<ushort>(-1) == "5535");
	QVERIFY(s::format<ushort>(-9) == "5527");
	QVERIFY(s::format<ushort>(-10) == "5526");

	QVERIFY(s::format<short>(0) == "0000");
	QVERIFY(s::format<short>(9) == "0009");
	QVERIFY(s::format<short>(10) == "0010");
	QVERIFY(s::format<short>(99) == "0099");
	QVERIFY(s::format<short>(100) == "0100");
	QVERIFY(s::format<short>(255) == "0255");
	QVERIFY(s::format<short>(256) == "0256");
	QVERIFY(s::format<short>(1000) == "1000");
	QVERIFY(s::format<short>(32767) == "2767");

	QVERIFY(s::format<short>(-1) == "5535");
	QVERIFY(s::format<short>(-9) == "5527");
	QVERIFY(s::format<short>(-10) == "5526");
	QVERIFY(s::format<short>(-99) == "5437");
	QVERIFY(s::format<short>(-100) == "5436");
	QVERIFY(s::format<short>(-255) == "5281");
	QVERIFY(s::format<short>(-256) == "5280");
	QVERIFY(s::format<short>(-1000) == "4536");
	QVERIFY(s::format<short>(-32767) == "2769");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec4DigitsInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format<uint>(0) == "0000");
	QVERIFY(s::format<uint>(9) == "0009");
	QVERIFY(s::format<uint>(10) == "0010");
	QVERIFY(s::format<uint>(99) == "0099");
	QVERIFY(s::format<uint>(100) == "0100");
	QVERIFY(s::format<uint>(255) == "0255");
	QVERIFY(s::format<uint>(256) == "0256");
	QVERIFY(s::format<uint>(1000) == "1000");
	QVERIFY(s::format<uint>(4294967295) == "7295");

	QVERIFY(s::format<uint>(-1) == "7295");
	QVERIFY(s::format<uint>(-9) == "7287");
	QVERIFY(s::format<uint>(-10) == "7286");

	QVERIFY(s::format<int>(0) == "0000");
	QVERIFY(s::format<int>(9) == "0009");
	QVERIFY(s::format<int>(10) == "0010");
	QVERIFY(s::format<int>(99) == "0099");
	QVERIFY(s::format<int>(100) == "0100");
	QVERIFY(s::format<int>(255) == "0255");
	QVERIFY(s::format<int>(256) == "0256");
	QVERIFY(s::format<int>(1000) == "1000");
	QVERIFY(s::format<int>(2147483647) == "3647");
	QVERIFY(s::format<int>(4294967295) == "7295");

	QVERIFY(s::format<int>(-1) == "7295");
	QVERIFY(s::format<int>(-9) == "7287");
	QVERIFY(s::format<int>(-10) == "7286");
	QVERIFY(s::format<int>(-99) == "7197");
	QVERIFY(s::format<int>(-100) == "7196");
	QVERIFY(s::format<int>(-255) == "7041");
	QVERIFY(s::format<int>(-256) == "7040");
	QVERIFY(s::format<int>(-1000) == "6296");
	QVERIFY(s::format<int>(-2147483647) == "3649");
	QVERIFY(s::format<int>(0-4294967295UL) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec4DigitsLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format<ulong>(0) == "0000");
	QVERIFY(s::format<ulong>(9) == "0009");
	QVERIFY(s::format<ulong>(10) == "0010");
	QVERIFY(s::format<ulong>(99) == "0099");
	QVERIFY(s::format<ulong>(100) == "0100");
	QVERIFY(s::format<ulong>(255) == "0255");
	QVERIFY(s::format<ulong>(256) == "0256");
	QVERIFY(s::format<ulong>(1000) == "1000");
	QVERIFY(s::format<ulong>(4294967295) == "7295");

	QVERIFY(s::format<ulong>(-1) == "7295");
	QVERIFY(s::format<ulong>(-9) == "7287");
	QVERIFY(s::format<ulong>(-10) == "7286");

	QVERIFY(s::format<long>(0) == "0000");
	QVERIFY(s::format<long>(9) == "0009");
	QVERIFY(s::format<long>(10) == "0010");
	QVERIFY(s::format<long>(99) == "0099");
	QVERIFY(s::format<long>(100) == "0100");
	QVERIFY(s::format<long>(255) == "0255");
	QVERIFY(s::format<long>(256) == "0256");
	QVERIFY(s::format<long>(1000) == "1000");
	QVERIFY(s::format<long>(2147483647) == "3647");
	QVERIFY(s::format<long>(4294967295) == "7295");

	QVERIFY(s::format<long>(-1) == "7295");
	QVERIFY(s::format<long>(-9) == "7287");
	QVERIFY(s::format<long>(-10) == "7286");
	QVERIFY(s::format<long>(-99) == "7197");
	QVERIFY(s::format<long>(-100) == "7196");
	QVERIFY(s::format<long>(-255) == "7041");
	QVERIFY(s::format<long>(-256) == "7040");
	QVERIFY(s::format<long>(-1000) == "6296");
	QVERIFY(s::format<long>(-2147483647) == "3649");
	QVERIFY(s::format<long>(0-4294967295UL) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatDec4DigitsInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format<quint64>(0) == "0000");
	QVERIFY(s::format<quint64>(9) == "0009");
	QVERIFY(s::format<quint64>(10) == "0010");
	QVERIFY(s::format<quint64>(99) == "0099");
	QVERIFY(s::format<quint64>(100) == "0100");
	QVERIFY(s::format<quint64>(255) == "0255");
	QVERIFY(s::format<quint64>(256) == "0256");
	QVERIFY(s::format<quint64>(1000) == "1000");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "1615");

	QVERIFY(s::format<quint64>(-1) == "1615");
	QVERIFY(s::format<quint64>(-9) == "1607");
	QVERIFY(s::format<quint64>(-10) == "1606");

	QVERIFY(s::format<qint64>(0) == "0000");
	QVERIFY(s::format<qint64>(9) == "0009");
	QVERIFY(s::format<qint64>(10) == "0010");
	QVERIFY(s::format<qint64>(99) == "0099");
	QVERIFY(s::format<qint64>(100) == "0100");
	QVERIFY(s::format<qint64>(255) == "0255");
	QVERIFY(s::format<qint64>(256) == "0256");
	QVERIFY(s::format<qint64>(1000) == "1000");
	QVERIFY(s::format<qint64>(9223372036854775807) == "5807");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "1615");

	QVERIFY(s::format<qint64>(-1) == "1615");
	QVERIFY(s::format<qint64>(-9) == "1607");
	QVERIFY(s::format<qint64>(-10) == "1606");
	QVERIFY(s::format<qint64>(-99) == "1517");
	QVERIFY(s::format<qint64>(-100) == "1516");
	QVERIFY(s::format<qint64>(-255) == "1361");
	QVERIFY(s::format<qint64>(-256) == "1360");
	QVERIFY(s::format<qint64>(-1000) == "0616");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "5809");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexChar()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format<uchar>(0) == "0");
	QVERIFY(s::format<uchar>(9) == "9");
	QVERIFY(s::format<uchar>(10) == "a");
	QVERIFY(s::format<uchar>(99) == "63");
	QVERIFY(s::format<uchar>(100) == "64");
	QVERIFY(s::format<uchar>(255) == "ff");

	QVERIFY(s::format<uchar>(-1) == "ff");
	QVERIFY(s::format<uchar>(-9) == "f7");
	QVERIFY(s::format<uchar>(-10) == "f6");

	QVERIFY(s::format<char>(0) == "0");
	QVERIFY(s::format<char>(9) == "9");
	QVERIFY(s::format<char>(10) == "a");
	QVERIFY(s::format<char>(99) == "63");
	QVERIFY(s::format<char>(100) == "64");
	QVERIFY(s::format<char>(127) == "7f");

	QVERIFY(s::format<char>(-1) == "ff");
	QVERIFY(s::format<char>(-9) == "f7");
	QVERIFY(s::format<char>(-10) == "f6");
	QVERIFY(s::format<char>(-99) == "9d");
	QVERIFY(s::format<char>(-100) == "9c");
	QVERIFY(s::format<char>(-255 & 0xff) == "1");

	QVERIFY(s::format<signed char>(0) == "0");
	QVERIFY(s::format<signed char>(9) == "9");
	QVERIFY(s::format<signed char>(10) == "a");
	QVERIFY(s::format<signed char>(99) == "63");
	QVERIFY(s::format<signed char>(100) == "64");
	QVERIFY(s::format<signed char>(127) == "7f");

	QVERIFY(s::format<signed char>(-1) == "ff");
	QVERIFY(s::format<signed char>(-9) == "f7");
	QVERIFY(s::format<signed char>(-10) == "f6");
	QVERIFY(s::format<signed char>(-99) == "9d");
	QVERIFY(s::format<signed char>(-100) == "9c");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format<uchar>(0) == "0");
	QVERIFY(s::format<uchar>(9) == "9");
	QVERIFY(s::format<uchar>(10) == "A");
	QVERIFY(s::format<uchar>(99) == "63");
	QVERIFY(s::format<uchar>(100) == "64");
	QVERIFY(s::format<uchar>(255) == "FF");

	QVERIFY(s::format<uchar>(-1) == "FF");
	QVERIFY(s::format<uchar>(-9) == "F7");
	QVERIFY(s::format<uchar>(-10) == "F6");

	QVERIFY(s::format<char>(0) == "0");
	QVERIFY(s::format<char>(9) == "9");
	QVERIFY(s::format<char>(10) == "A");
	QVERIFY(s::format<char>(99) == "63");
	QVERIFY(s::format<char>(100) == "64");
	QVERIFY(s::format<char>(127) == "7F");

	QVERIFY(s::format<char>(-1) == "FF");
	QVERIFY(s::format<char>(-9) == "F7");
	QVERIFY(s::format<char>(-10) == "F6");
	QVERIFY(s::format<char>(-99) == "9D");
	QVERIFY(s::format<char>(-100) == "9C");
	QVERIFY(s::format<char>(-255 & 0xff) == "1");

	QVERIFY(s::format<signed char>(0) == "0");
	QVERIFY(s::format<signed char>(9) == "9");
	QVERIFY(s::format<signed char>(10) == "A");
	QVERIFY(s::format<signed char>(99) == "63");
	QVERIFY(s::format<signed char>(100) == "64");
	QVERIFY(s::format<signed char>(127) == "7F");

	QVERIFY(s::format<signed char>(-1) == "FF");
	QVERIFY(s::format<signed char>(-9) == "F7");
	QVERIFY(s::format<signed char>(-10) == "F6");
	QVERIFY(s::format<signed char>(-99) == "9D");
	QVERIFY(s::format<signed char>(-100) == "9C");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<uchar>(0) == "00");
	QVERIFY(s::format<uchar>(9) == "09");
	QVERIFY(s::format<uchar>(10) == "0a");
	QVERIFY(s::format<uchar>(99) == "63");
	QVERIFY(s::format<uchar>(100) == "64");
	QVERIFY(s::format<uchar>(255) == "ff");

	QVERIFY(s::format<uchar>(-1) == "ff");
	QVERIFY(s::format<uchar>(-9) == "f7");
	QVERIFY(s::format<uchar>(-10) == "f6");

	QVERIFY(s::format<char>(0) == "00");
	QVERIFY(s::format<char>(9) == "09");
	QVERIFY(s::format<char>(10) == "0a");
	QVERIFY(s::format<char>(99) == "63");
	QVERIFY(s::format<char>(100) == "64");
	QVERIFY(s::format<char>(127) == "7f");

	QVERIFY(s::format<char>(-1) == "ff");
	QVERIFY(s::format<char>(-9) == "f7");
	QVERIFY(s::format<char>(-10) == "f6");
	QVERIFY(s::format<char>(-99) == "9d");
	QVERIFY(s::format<char>(-100) == "9c");
	QVERIFY(s::format<char>(-255 & 0xff) == "01");

	QVERIFY(s::format<signed char>(0) == "00");
	QVERIFY(s::format<signed char>(9) == "09");
	QVERIFY(s::format<signed char>(10) == "0a");
	QVERIFY(s::format<signed char>(99) == "63");
	QVERIFY(s::format<signed char>(100) == "64");
	QVERIFY(s::format<signed char>(127) == "7f");

	QVERIFY(s::format<signed char>(-1) == "ff");
	QVERIFY(s::format<signed char>(-9) == "f7");
	QVERIFY(s::format<signed char>(-10) == "f6");
	QVERIFY(s::format<signed char>(-99) == "9d");
	QVERIFY(s::format<signed char>(-100) == "9c");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uchar>(0) == "00");
	QVERIFY(s::format<uchar>(9) == "09");
	QVERIFY(s::format<uchar>(10) == "0A");
	QVERIFY(s::format<uchar>(99) == "63");
	QVERIFY(s::format<uchar>(100) == "64");
	QVERIFY(s::format<uchar>(255) == "FF");

	QVERIFY(s::format<uchar>(-1) == "FF");
	QVERIFY(s::format<uchar>(-9) == "F7");
	QVERIFY(s::format<uchar>(-10) == "F6");

	QVERIFY(s::format<char>(0) == "00");
	QVERIFY(s::format<char>(9) == "09");
	QVERIFY(s::format<char>(10) == "0A");
	QVERIFY(s::format<char>(99) == "63");
	QVERIFY(s::format<char>(100) == "64");
	QVERIFY(s::format<char>(127) == "7F");

	QVERIFY(s::format<char>(-1) == "FF");
	QVERIFY(s::format<char>(-9) == "F7");
	QVERIFY(s::format<char>(-10) == "F6");
	QVERIFY(s::format<char>(-99) == "9D");
	QVERIFY(s::format<char>(-100) == "9C");
	QVERIFY(s::format<char>(-255 & 0xff) == "01");

	QVERIFY(s::format<signed char>(0) == "00");
	QVERIFY(s::format<signed char>(9) == "09");
	QVERIFY(s::format<signed char>(10) == "0A");
	QVERIFY(s::format<signed char>(99) == "63");
	QVERIFY(s::format<signed char>(100) == "64");
	QVERIFY(s::format<signed char>(127) == "7F");

	QVERIFY(s::format<signed char>(-1) == "FF");
	QVERIFY(s::format<signed char>(-9) == "F7");
	QVERIFY(s::format<signed char>(-10) == "F6");
	QVERIFY(s::format<signed char>(-99) == "9D");
	QVERIFY(s::format<signed char>(-100) == "9C");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "01");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShort()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format<ushort>(0) == "0");
	QVERIFY(s::format<ushort>(9) == "9");
	QVERIFY(s::format<ushort>(10) == "a");
	QVERIFY(s::format<ushort>(99) == "63");
	QVERIFY(s::format<ushort>(100) == "64");
	QVERIFY(s::format<ushort>(255) == "ff");
	QVERIFY(s::format<ushort>(256) == "100");
	QVERIFY(s::format<ushort>(1000) == "3e8");
	QVERIFY(s::format<ushort>(65535) == "ffff");

	QVERIFY(s::format<ushort>(-1) == "ffff");
	QVERIFY(s::format<ushort>(-9) == "fff7");
	QVERIFY(s::format<ushort>(-10) == "fff6");

	QVERIFY(s::format<short>(0) == "0");
	QVERIFY(s::format<short>(9) == "9");
	QVERIFY(s::format<short>(10) == "a");
	QVERIFY(s::format<short>(99) == "63");
	QVERIFY(s::format<short>(100) == "64");
	QVERIFY(s::format<short>(255) == "ff");
	QVERIFY(s::format<short>(256) == "100");
	QVERIFY(s::format<short>(1000) == "3e8");
	QVERIFY(s::format<short>(32767) == "7fff");

	QVERIFY(s::format<short>(-1) == "ffff");
	QVERIFY(s::format<short>(-9) == "fff7");
	QVERIFY(s::format<short>(-10) == "fff6");
	QVERIFY(s::format<short>(-99) == "ff9d");
	QVERIFY(s::format<short>(-100) == "ff9c");
	QVERIFY(s::format<short>(-255) == "ff01");
	QVERIFY(s::format<short>(-256) == "ff00");
	QVERIFY(s::format<short>(-1000) == "fc18");
	QVERIFY(s::format<short>(-32767) == "8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ushort>(0) == "0");
	QVERIFY(s::format<ushort>(9) == "9");
	QVERIFY(s::format<ushort>(10) == "A");
	QVERIFY(s::format<ushort>(99) == "63");
	QVERIFY(s::format<ushort>(100) == "64");
	QVERIFY(s::format<ushort>(255) == "FF");
	QVERIFY(s::format<ushort>(256) == "100");
	QVERIFY(s::format<ushort>(1000) == "3E8");
	QVERIFY(s::format<ushort>(65535) == "FFFF");

	QVERIFY(s::format<ushort>(-1) == "FFFF");
	QVERIFY(s::format<ushort>(-9) == "FFF7");
	QVERIFY(s::format<ushort>(-10) == "FFF6");

	QVERIFY(s::format<short>(0) == "0");
	QVERIFY(s::format<short>(9) == "9");
	QVERIFY(s::format<short>(10) == "A");
	QVERIFY(s::format<short>(99) == "63");
	QVERIFY(s::format<short>(100) == "64");
	QVERIFY(s::format<short>(255) == "FF");
	QVERIFY(s::format<short>(256) == "100");
	QVERIFY(s::format<short>(1000) == "3E8");
	QVERIFY(s::format<short>(32767) == "7FFF");

	QVERIFY(s::format<short>(-1) == "FFFF");
	QVERIFY(s::format<short>(-9) == "FFF7");
	QVERIFY(s::format<short>(-10) == "FFF6");
	QVERIFY(s::format<short>(-99) == "FF9D");
	QVERIFY(s::format<short>(-100) == "FF9C");
	QVERIFY(s::format<short>(-255) == "FF01");
	QVERIFY(s::format<short>(-256) == "FF00");
	QVERIFY(s::format<short>(-1000) == "FC18");
	QVERIFY(s::format<short>(-32767) == "8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<ushort>(0) == "0000");
	QVERIFY(s::format<ushort>(9) == "0009");
	QVERIFY(s::format<ushort>(10) == "000a");
	QVERIFY(s::format<ushort>(99) == "0063");
	QVERIFY(s::format<ushort>(100) == "0064");
	QVERIFY(s::format<ushort>(255) == "00ff");
	QVERIFY(s::format<ushort>(256) == "0100");
	QVERIFY(s::format<ushort>(1000) == "03e8");
	QVERIFY(s::format<ushort>(65535) == "ffff");

	QVERIFY(s::format<ushort>(-1) == "ffff");
	QVERIFY(s::format<ushort>(-9) == "fff7");
	QVERIFY(s::format<ushort>(-10) == "fff6");

	QVERIFY(s::format<short>(0) == "0000");
	QVERIFY(s::format<short>(9) == "0009");
	QVERIFY(s::format<short>(10) == "000a");
	QVERIFY(s::format<short>(99) == "0063");
	QVERIFY(s::format<short>(100) == "0064");
	QVERIFY(s::format<short>(255) == "00ff");
	QVERIFY(s::format<short>(256) == "0100");
	QVERIFY(s::format<short>(1000) == "03e8");
	QVERIFY(s::format<short>(32767) == "7fff");

	QVERIFY(s::format<short>(-1) == "ffff");
	QVERIFY(s::format<short>(-9) == "fff7");
	QVERIFY(s::format<short>(-10) == "fff6");
	QVERIFY(s::format<short>(-99) == "ff9d");
	QVERIFY(s::format<short>(-100) == "ff9c");
	QVERIFY(s::format<short>(-255) == "ff01");
	QVERIFY(s::format<short>(-256) == "ff00");
	QVERIFY(s::format<short>(-1000) == "fc18");
	QVERIFY(s::format<short>(-32767) == "8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ushort>(0) == "0000");
	QVERIFY(s::format<ushort>(9) == "0009");
	QVERIFY(s::format<ushort>(10) == "000A");
	QVERIFY(s::format<ushort>(99) == "0063");
	QVERIFY(s::format<ushort>(100) == "0064");
	QVERIFY(s::format<ushort>(255) == "00FF");
	QVERIFY(s::format<ushort>(256) == "0100");
	QVERIFY(s::format<ushort>(1000) == "03E8");
	QVERIFY(s::format<ushort>(65535) == "FFFF");

	QVERIFY(s::format<ushort>(-1) == "FFFF");
	QVERIFY(s::format<ushort>(-9) == "FFF7");
	QVERIFY(s::format<ushort>(-10) == "FFF6");

	QVERIFY(s::format<short>(0) == "0000");
	QVERIFY(s::format<short>(9) == "0009");
	QVERIFY(s::format<short>(10) == "000A");
	QVERIFY(s::format<short>(99) == "0063");
	QVERIFY(s::format<short>(100) == "0064");
	QVERIFY(s::format<short>(255) == "00FF");
	QVERIFY(s::format<short>(256) == "0100");
	QVERIFY(s::format<short>(1000) == "03E8");
	QVERIFY(s::format<short>(32767) == "7FFF");

	QVERIFY(s::format<short>(-1) == "FFFF");
	QVERIFY(s::format<short>(-9) == "FFF7");
	QVERIFY(s::format<short>(-10) == "FFF6");
	QVERIFY(s::format<short>(-99) == "FF9D");
	QVERIFY(s::format<short>(-100) == "FF9C");
	QVERIFY(s::format<short>(-255) == "FF01");
	QVERIFY(s::format<short>(-256) == "FF00");
	QVERIFY(s::format<short>(-1000) == "FC18");
	QVERIFY(s::format<short>(-32767) == "8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format<uint>(0) == "0");
	QVERIFY(s::format<uint>(9) == "9");
	QVERIFY(s::format<uint>(10) == "a");
	QVERIFY(s::format<uint>(99) == "63");
	QVERIFY(s::format<uint>(100) == "64");
	QVERIFY(s::format<uint>(255) == "ff");
	QVERIFY(s::format<uint>(256) == "100");
	QVERIFY(s::format<uint>(1000) == "3e8");
	QVERIFY(s::format<uint>(4294967295) == "ffffffff");

	QVERIFY(s::format<uint>(-1) == "ffffffff");
	QVERIFY(s::format<uint>(-9) == "fffffff7");
	QVERIFY(s::format<uint>(-10) == "fffffff6");

	QVERIFY(s::format<int>(0) == "0");
	QVERIFY(s::format<int>(9) == "9");
	QVERIFY(s::format<int>(10) == "a");
	QVERIFY(s::format<int>(99) == "63");
	QVERIFY(s::format<int>(100) == "64");
	QVERIFY(s::format<int>(255) == "ff");
	QVERIFY(s::format<int>(256) == "100");
	QVERIFY(s::format<int>(1000) == "3e8");
	QVERIFY(s::format<int>(2147483647) == "7fffffff");
	QVERIFY(s::format<int>(4294967295) == "ffffffff");

	QVERIFY(s::format<int>(-1) == "ffffffff");
	QVERIFY(s::format<int>(-9) == "fffffff7");
	QVERIFY(s::format<int>(-10) == "fffffff6");
	QVERIFY(s::format<int>(-99) == "ffffff9d");
	QVERIFY(s::format<int>(-100) == "ffffff9c");
	QVERIFY(s::format<int>(-255) == "ffffff01");
	QVERIFY(s::format<int>(-256) == "ffffff00");
	QVERIFY(s::format<int>(-1000) == "fffffc18");
	QVERIFY(s::format<int>(-2147483647) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uint>(0) == "0");
	QVERIFY(s::format<uint>(9) == "9");
	QVERIFY(s::format<uint>(10) == "A");
	QVERIFY(s::format<uint>(99) == "63");
	QVERIFY(s::format<uint>(100) == "64");
	QVERIFY(s::format<uint>(255) == "FF");
	QVERIFY(s::format<uint>(256) == "100");
	QVERIFY(s::format<uint>(1000) == "3E8");
	QVERIFY(s::format<uint>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<uint>(-1) == "FFFFFFFF");
	QVERIFY(s::format<uint>(-9) == "FFFFFFF7");
	QVERIFY(s::format<uint>(-10) == "FFFFFFF6");

	QVERIFY(s::format<int>(0) == "0");
	QVERIFY(s::format<int>(9) == "9");
	QVERIFY(s::format<int>(10) == "A");
	QVERIFY(s::format<int>(99) == "63");
	QVERIFY(s::format<int>(100) == "64");
	QVERIFY(s::format<int>(255) == "FF");
	QVERIFY(s::format<int>(256) == "100");
	QVERIFY(s::format<int>(1000) == "3E8");
	QVERIFY(s::format<int>(2147483647) == "7FFFFFFF");
	QVERIFY(s::format<int>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<int>(-1) == "FFFFFFFF");
	QVERIFY(s::format<int>(-9) == "FFFFFFF7");
	QVERIFY(s::format<int>(-10) == "FFFFFFF6");
	QVERIFY(s::format<int>(-99) == "FFFFFF9D");
	QVERIFY(s::format<int>(-100) == "FFFFFF9C");
	QVERIFY(s::format<int>(-255) == "FFFFFF01");
	QVERIFY(s::format<int>(-256) == "FFFFFF00");
	QVERIFY(s::format<int>(-1000) == "FFFFFC18");
	QVERIFY(s::format<int>(-2147483647) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<uint>(0) == "00000000");
	QVERIFY(s::format<uint>(9) == "00000009");
	QVERIFY(s::format<uint>(10) == "0000000a");
	QVERIFY(s::format<uint>(99) == "00000063");
	QVERIFY(s::format<uint>(100) == "00000064");
	QVERIFY(s::format<uint>(255) == "000000ff");
	QVERIFY(s::format<uint>(256) == "00000100");
	QVERIFY(s::format<uint>(1000) == "000003e8");
	QVERIFY(s::format<uint>(4294967295) == "ffffffff");

	QVERIFY(s::format<uint>(-1) == "ffffffff");
	QVERIFY(s::format<uint>(-9) == "fffffff7");
	QVERIFY(s::format<uint>(-10) == "fffffff6");

	QVERIFY(s::format<int>(0) == "00000000");
	QVERIFY(s::format<int>(9) == "00000009");
	QVERIFY(s::format<int>(10) == "0000000a");
	QVERIFY(s::format<int>(99) == "00000063");
	QVERIFY(s::format<int>(100) == "00000064");
	QVERIFY(s::format<int>(255) == "000000ff");
	QVERIFY(s::format<int>(256) == "00000100");
	QVERIFY(s::format<int>(1000) == "000003e8");
	QVERIFY(s::format<int>(2147483647) == "7fffffff");
	QVERIFY(s::format<int>(4294967295) == "ffffffff");

	QVERIFY(s::format<int>(-1) == "ffffffff");
	QVERIFY(s::format<int>(-9) == "fffffff7");
	QVERIFY(s::format<int>(-10) == "fffffff6");
	QVERIFY(s::format<int>(-99) == "ffffff9d");
	QVERIFY(s::format<int>(-100) == "ffffff9c");
	QVERIFY(s::format<int>(-255) == "ffffff01");
	QVERIFY(s::format<int>(-256) == "ffffff00");
	QVERIFY(s::format<int>(-1000) == "fffffc18");
	QVERIFY(s::format<int>(-2147483647) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uint>(0) == "00000000");
	QVERIFY(s::format<uint>(9) == "00000009");
	QVERIFY(s::format<uint>(10) == "0000000A");
	QVERIFY(s::format<uint>(99) == "00000063");
	QVERIFY(s::format<uint>(100) == "00000064");
	QVERIFY(s::format<uint>(255) == "000000FF");
	QVERIFY(s::format<uint>(256) == "00000100");
	QVERIFY(s::format<uint>(1000) == "000003E8");
	QVERIFY(s::format<uint>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<uint>(-1) == "FFFFFFFF");
	QVERIFY(s::format<uint>(-9) == "FFFFFFF7");
	QVERIFY(s::format<uint>(-10) == "FFFFFFF6");

	QVERIFY(s::format<int>(0) == "00000000");
	QVERIFY(s::format<int>(9) == "00000009");
	QVERIFY(s::format<int>(10) == "0000000A");
	QVERIFY(s::format<int>(99) == "00000063");
	QVERIFY(s::format<int>(100) == "00000064");
	QVERIFY(s::format<int>(255) == "000000FF");
	QVERIFY(s::format<int>(256) == "00000100");
	QVERIFY(s::format<int>(1000) == "000003E8");
	QVERIFY(s::format<int>(2147483647) == "7FFFFFFF");
	QVERIFY(s::format<int>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<int>(-1) == "FFFFFFFF");
	QVERIFY(s::format<int>(-9) == "FFFFFFF7");
	QVERIFY(s::format<int>(-10) == "FFFFFFF6");
	QVERIFY(s::format<int>(-99) == "FFFFFF9D");
	QVERIFY(s::format<int>(-100) == "FFFFFF9C");
	QVERIFY(s::format<int>(-255) == "FFFFFF01");
	QVERIFY(s::format<int>(-256) == "FFFFFF00");
	QVERIFY(s::format<int>(-1000) == "FFFFFC18");
	QVERIFY(s::format<int>(-2147483647) == "80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLong()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format<ulong>(0) == "0");
	QVERIFY(s::format<ulong>(9) == "9");
	QVERIFY(s::format<ulong>(10) == "a");
	QVERIFY(s::format<ulong>(99) == "63");
	QVERIFY(s::format<ulong>(100) == "64");
	QVERIFY(s::format<ulong>(255) == "ff");
	QVERIFY(s::format<ulong>(256) == "100");
	QVERIFY(s::format<ulong>(1000) == "3e8");
	QVERIFY(s::format<ulong>(4294967295) == "ffffffff");

	QVERIFY(s::format<ulong>(-1) == "ffffffff");
	QVERIFY(s::format<ulong>(-9) == "fffffff7");
	QVERIFY(s::format<ulong>(-10) == "fffffff6");

	QVERIFY(s::format<long>(0) == "0");
	QVERIFY(s::format<long>(9) == "9");
	QVERIFY(s::format<long>(10) == "a");
	QVERIFY(s::format<long>(99) == "63");
	QVERIFY(s::format<long>(100) == "64");
	QVERIFY(s::format<long>(255) == "ff");
	QVERIFY(s::format<long>(256) == "100");
	QVERIFY(s::format<long>(1000) == "3e8");
	QVERIFY(s::format<long>(2147483647) == "7fffffff");
	QVERIFY(s::format<long>(4294967295) == "ffffffff");

	QVERIFY(s::format<long>(-1) == "ffffffff");
	QVERIFY(s::format<long>(-9) == "fffffff7");
	QVERIFY(s::format<long>(-10) == "fffffff6");
	QVERIFY(s::format<long>(-99) == "ffffff9d");
	QVERIFY(s::format<long>(-100) == "ffffff9c");
	QVERIFY(s::format<long>(-255) == "ffffff01");
	QVERIFY(s::format<long>(-256) == "ffffff00");
	QVERIFY(s::format<long>(-1000) == "fffffc18");
	QVERIFY(s::format<long>(-2147483647) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ulong>(0) == "0");
	QVERIFY(s::format<ulong>(9) == "9");
	QVERIFY(s::format<ulong>(10) == "A");
	QVERIFY(s::format<ulong>(99) == "63");
	QVERIFY(s::format<ulong>(100) == "64");
	QVERIFY(s::format<ulong>(255) == "FF");
	QVERIFY(s::format<ulong>(256) == "100");
	QVERIFY(s::format<ulong>(1000) == "3E8");
	QVERIFY(s::format<ulong>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<ulong>(-1) == "FFFFFFFF");
	QVERIFY(s::format<ulong>(-9) == "FFFFFFF7");
	QVERIFY(s::format<ulong>(-10) == "FFFFFFF6");

	QVERIFY(s::format<long>(0) == "0");
	QVERIFY(s::format<long>(9) == "9");
	QVERIFY(s::format<long>(10) == "A");
	QVERIFY(s::format<long>(99) == "63");
	QVERIFY(s::format<long>(100) == "64");
	QVERIFY(s::format<long>(255) == "FF");
	QVERIFY(s::format<long>(256) == "100");
	QVERIFY(s::format<long>(1000) == "3E8");
	QVERIFY(s::format<long>(2147483647) == "7FFFFFFF");
	QVERIFY(s::format<long>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<long>(-1) == "FFFFFFFF");
	QVERIFY(s::format<long>(-9) == "FFFFFFF7");
	QVERIFY(s::format<long>(-10) == "FFFFFFF6");
	QVERIFY(s::format<long>(-99) == "FFFFFF9D");
	QVERIFY(s::format<long>(-100) == "FFFFFF9C");
	QVERIFY(s::format<long>(-255) == "FFFFFF01");
	QVERIFY(s::format<long>(-256) == "FFFFFF00");
	QVERIFY(s::format<long>(-1000) == "FFFFFC18");
	QVERIFY(s::format<long>(-2147483647) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongLz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<ulong>(0) == "00000000");
	QVERIFY(s::format<ulong>(9) == "00000009");
	QVERIFY(s::format<ulong>(10) == "0000000a");
	QVERIFY(s::format<ulong>(99) == "00000063");
	QVERIFY(s::format<ulong>(100) == "00000064");
	QVERIFY(s::format<ulong>(255) == "000000ff");
	QVERIFY(s::format<ulong>(256) == "00000100");
	QVERIFY(s::format<ulong>(1000) == "000003e8");
	QVERIFY(s::format<ulong>(4294967295) == "ffffffff");

	QVERIFY(s::format<ulong>(-1) == "ffffffff");
	QVERIFY(s::format<ulong>(-9) == "fffffff7");
	QVERIFY(s::format<ulong>(-10) == "fffffff6");

	QVERIFY(s::format<long>(0) == "00000000");
	QVERIFY(s::format<long>(9) == "00000009");
	QVERIFY(s::format<long>(10) == "0000000a");
	QVERIFY(s::format<long>(99) == "00000063");
	QVERIFY(s::format<long>(100) == "00000064");
	QVERIFY(s::format<long>(255) == "000000ff");
	QVERIFY(s::format<long>(256) == "00000100");
	QVERIFY(s::format<long>(1000) == "000003e8");
	QVERIFY(s::format<long>(2147483647) == "7fffffff");
	QVERIFY(s::format<long>(4294967295) == "ffffffff");

	QVERIFY(s::format<long>(-1) == "ffffffff");
	QVERIFY(s::format<long>(-9) == "fffffff7");
	QVERIFY(s::format<long>(-10) == "fffffff6");
	QVERIFY(s::format<long>(-99) == "ffffff9d");
	QVERIFY(s::format<long>(-100) == "ffffff9c");
	QVERIFY(s::format<long>(-255) == "ffffff01");
	QVERIFY(s::format<long>(-256) == "ffffff00");
	QVERIFY(s::format<long>(-1000) == "fffffc18");
	QVERIFY(s::format<long>(-2147483647) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongLzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ulong>(0) == "00000000");
	QVERIFY(s::format<ulong>(9) == "00000009");
	QVERIFY(s::format<ulong>(10) == "0000000A");
	QVERIFY(s::format<ulong>(99) == "00000063");
	QVERIFY(s::format<ulong>(100) == "00000064");
	QVERIFY(s::format<ulong>(255) == "000000FF");
	QVERIFY(s::format<ulong>(256) == "00000100");
	QVERIFY(s::format<ulong>(1000) == "000003E8");
	QVERIFY(s::format<ulong>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<ulong>(-1) == "FFFFFFFF");
	QVERIFY(s::format<ulong>(-9) == "FFFFFFF7");
	QVERIFY(s::format<ulong>(-10) == "FFFFFFF6");

	QVERIFY(s::format<long>(0) == "00000000");
	QVERIFY(s::format<long>(9) == "00000009");
	QVERIFY(s::format<long>(10) == "0000000A");
	QVERIFY(s::format<long>(99) == "00000063");
	QVERIFY(s::format<long>(100) == "00000064");
	QVERIFY(s::format<long>(255) == "000000FF");
	QVERIFY(s::format<long>(256) == "00000100");
	QVERIFY(s::format<long>(1000) == "000003E8");
	QVERIFY(s::format<long>(2147483647) == "7FFFFFFF");
	QVERIFY(s::format<long>(4294967295) == "FFFFFFFF");

	QVERIFY(s::format<long>(-1) == "FFFFFFFF");
	QVERIFY(s::format<long>(-9) == "FFFFFFF7");
	QVERIFY(s::format<long>(-10) == "FFFFFFF6");
	QVERIFY(s::format<long>(-99) == "FFFFFF9D");
	QVERIFY(s::format<long>(-100) == "FFFFFF9C");
	QVERIFY(s::format<long>(-255) == "FFFFFF01");
	QVERIFY(s::format<long>(-256) == "FFFFFF00");
	QVERIFY(s::format<long>(-1000) == "FFFFFC18");
	QVERIFY(s::format<long>(-2147483647) == "80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format<quint64>(0) == "0");
	QVERIFY(s::format<quint64>(9) == "9");
	QVERIFY(s::format<quint64>(10) == "a");
	QVERIFY(s::format<quint64>(99) == "63");
	QVERIFY(s::format<quint64>(100) == "64");
	QVERIFY(s::format<quint64>(255) == "ff");
	QVERIFY(s::format<quint64>(256) == "100");
	QVERIFY(s::format<quint64>(1000) == "3e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "ffffffffffffffff");

	QVERIFY(s::format<quint64>(-1) == "ffffffffffffffff");
	QVERIFY(s::format<quint64>(-9) == "fffffffffffffff7");
	QVERIFY(s::format<quint64>(-10) == "fffffffffffffff6");

	QVERIFY(s::format<qint64>(0) == "0");
	QVERIFY(s::format<qint64>(9) == "9");
	QVERIFY(s::format<qint64>(10) == "a");
	QVERIFY(s::format<qint64>(99) == "63");
	QVERIFY(s::format<qint64>(100) == "64");
	QVERIFY(s::format<qint64>(255) == "ff");
	QVERIFY(s::format<qint64>(256) == "100");
	QVERIFY(s::format<qint64>(1000) == "3e8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "ffffffffffffffff");

	QVERIFY(s::format<qint64>(-1) == "ffffffffffffffff");
	QVERIFY(s::format<qint64>(-9) == "fffffffffffffff7");
	QVERIFY(s::format<qint64>(-10) == "fffffffffffffff6");
	QVERIFY(s::format<qint64>(-99) == "ffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100) == "ffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255) == "ffffffffffffff01");
	QVERIFY(s::format<qint64>(-256) == "ffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000) == "fffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64Upper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<quint64>(0) == "0");
	QVERIFY(s::format<quint64>(9) == "9");
	QVERIFY(s::format<quint64>(10) == "A");
	QVERIFY(s::format<quint64>(99) == "63");
	QVERIFY(s::format<quint64>(100) == "64");
	QVERIFY(s::format<quint64>(255) == "FF");
	QVERIFY(s::format<quint64>(256) == "100");
	QVERIFY(s::format<quint64>(1000) == "3E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0) == "0");
	QVERIFY(s::format<qint64>(9) == "9");
	QVERIFY(s::format<qint64>(10) == "A");
	QVERIFY(s::format<qint64>(99) == "63");
	QVERIFY(s::format<qint64>(100) == "64");
	QVERIFY(s::format<qint64>(255) == "FF");
	QVERIFY(s::format<qint64>(256) == "100");
	QVERIFY(s::format<qint64>(1000) == "3E8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64Lz()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format<quint64>(0) == "0000000000000000");
	QVERIFY(s::format<quint64>(9) == "0000000000000009");
	QVERIFY(s::format<quint64>(10) == "000000000000000a");
	QVERIFY(s::format<quint64>(99) == "0000000000000063");
	QVERIFY(s::format<quint64>(100) == "0000000000000064");
	QVERIFY(s::format<quint64>(255) == "00000000000000ff");
	QVERIFY(s::format<quint64>(256) == "0000000000000100");
	QVERIFY(s::format<quint64>(1000) == "00000000000003e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "ffffffffffffffff");

	QVERIFY(s::format<quint64>(-1) == "ffffffffffffffff");
	QVERIFY(s::format<quint64>(-9) == "fffffffffffffff7");
	QVERIFY(s::format<quint64>(-10) == "fffffffffffffff6");

	QVERIFY(s::format<qint64>(0) == "0000000000000000");
	QVERIFY(s::format<qint64>(9) == "0000000000000009");
	QVERIFY(s::format<qint64>(10) == "000000000000000a");
	QVERIFY(s::format<qint64>(99) == "0000000000000063");
	QVERIFY(s::format<qint64>(100) == "0000000000000064");
	QVERIFY(s::format<qint64>(255) == "00000000000000ff");
	QVERIFY(s::format<qint64>(256) == "0000000000000100");
	QVERIFY(s::format<qint64>(1000) == "00000000000003e8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "ffffffffffffffff");

	QVERIFY(s::format<qint64>(-1) == "ffffffffffffffff");
	QVERIFY(s::format<qint64>(-9) == "fffffffffffffff7");
	QVERIFY(s::format<qint64>(-10) == "fffffffffffffff6");
	QVERIFY(s::format<qint64>(-99) == "ffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100) == "ffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255) == "ffffffffffffff01");
	QVERIFY(s::format<qint64>(-256) == "ffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000) == "fffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0000000000000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64LzUpper()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<quint64>(0) == "0000000000000000");
	QVERIFY(s::format<quint64>(9) == "0000000000000009");
	QVERIFY(s::format<quint64>(10) == "000000000000000A");
	QVERIFY(s::format<quint64>(99) == "0000000000000063");
	QVERIFY(s::format<quint64>(100) == "0000000000000064");
	QVERIFY(s::format<quint64>(255) == "00000000000000FF");
	QVERIFY(s::format<quint64>(256) == "0000000000000100");
	QVERIFY(s::format<quint64>(1000) == "00000000000003E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10) == "FFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0) == "0000000000000000");
	QVERIFY(s::format<qint64>(9) == "0000000000000009");
	QVERIFY(s::format<qint64>(10) == "000000000000000A");
	QVERIFY(s::format<qint64>(99) == "0000000000000063");
	QVERIFY(s::format<qint64>(100) == "0000000000000064");
	QVERIFY(s::format<qint64>(255) == "00000000000000FF");
	QVERIFY(s::format<qint64>(256) == "0000000000000100");
	QVERIFY(s::format<qint64>(1000) == "00000000000003E8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0000000000000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<uchar>(0) == "0x0");
	QVERIFY(s::format<uchar>(9) == "0x9");
	QVERIFY(s::format<uchar>(10) == "0xa");
	QVERIFY(s::format<uchar>(99) == "0x63");
	QVERIFY(s::format<uchar>(100) == "0x64");
	QVERIFY(s::format<uchar>(255) == "0xff");

	QVERIFY(s::format<uchar>(-1) == "0xff");
	QVERIFY(s::format<uchar>(-9) == "0xf7");
	QVERIFY(s::format<uchar>(-10) == "0xf6");

	QVERIFY(s::format<char>(0) == "0x0");
	QVERIFY(s::format<char>(9) == "0x9");
	QVERIFY(s::format<char>(10) == "0xa");
	QVERIFY(s::format<char>(99) == "0x63");
	QVERIFY(s::format<char>(100) == "0x64");
	QVERIFY(s::format<char>(127) == "0x7f");

	QVERIFY(s::format<char>(-1) == "0xff");
	QVERIFY(s::format<char>(-9) == "0xf7");
	QVERIFY(s::format<char>(-10) == "0xf6");
	QVERIFY(s::format<char>(-99) == "0x9d");
	QVERIFY(s::format<char>(-100) == "0x9c");
	QVERIFY(s::format<char>(-255 & 0xff) == "0x1");

	QVERIFY(s::format<signed char>(0) == "0x0");
	QVERIFY(s::format<signed char>(9) == "0x9");
	QVERIFY(s::format<signed char>(10) == "0xa");
	QVERIFY(s::format<signed char>(99) == "0x63");
	QVERIFY(s::format<signed char>(100) == "0x64");
	QVERIFY(s::format<signed char>(127) == "0x7f");

	QVERIFY(s::format<signed char>(-1) == "0xff");
	QVERIFY(s::format<signed char>(-9) == "0xf7");
	QVERIFY(s::format<signed char>(-10) == "0xf6");
	QVERIFY(s::format<signed char>(-99) == "0x9d");
	QVERIFY(s::format<signed char>(-100) == "0x9c");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uchar>(0) == "0x0");
	QVERIFY(s::format<uchar>(9) == "0x9");
	QVERIFY(s::format<uchar>(10) == "0xA");
	QVERIFY(s::format<uchar>(99) == "0x63");
	QVERIFY(s::format<uchar>(100) == "0x64");
	QVERIFY(s::format<uchar>(255) == "0xFF");

	QVERIFY(s::format<uchar>(-1) == "0xFF");
	QVERIFY(s::format<uchar>(-9) == "0xF7");
	QVERIFY(s::format<uchar>(-10) == "0xF6");

	QVERIFY(s::format<char>(0) == "0x0");
	QVERIFY(s::format<char>(9) == "0x9");
	QVERIFY(s::format<char>(10) == "0xA");
	QVERIFY(s::format<char>(99) == "0x63");
	QVERIFY(s::format<char>(100) == "0x64");
	QVERIFY(s::format<char>(127) == "0x7F");

	QVERIFY(s::format<char>(-1) == "0xFF");
	QVERIFY(s::format<char>(-9) == "0xF7");
	QVERIFY(s::format<char>(-10) == "0xF6");
	QVERIFY(s::format<char>(-99) == "0x9D");
	QVERIFY(s::format<char>(-100) == "0x9C");
	QVERIFY(s::format<char>(-255 & 0xff) == "0x1");

	QVERIFY(s::format<signed char>(0) == "0x0");
	QVERIFY(s::format<signed char>(9) == "0x9");
	QVERIFY(s::format<signed char>(10) == "0xA");
	QVERIFY(s::format<signed char>(99) == "0x63");
	QVERIFY(s::format<signed char>(100) == "0x64");
	QVERIFY(s::format<signed char>(127) == "0x7F");

	QVERIFY(s::format<signed char>(-1) == "0xFF");
	QVERIFY(s::format<signed char>(-9) == "0xF7");
	QVERIFY(s::format<signed char>(-10) == "0xF6");
	QVERIFY(s::format<signed char>(-99) == "0x9D");
	QVERIFY(s::format<signed char>(-100) == "0x9C");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<uchar>(0) == "0x00");
	QVERIFY(s::format<uchar>(9) == "0x09");
	QVERIFY(s::format<uchar>(10) == "0x0a");
	QVERIFY(s::format<uchar>(99) == "0x63");
	QVERIFY(s::format<uchar>(100) == "0x64");
	QVERIFY(s::format<uchar>(255) == "0xff");

	QVERIFY(s::format<uchar>(-1) == "0xff");
	QVERIFY(s::format<uchar>(-9) == "0xf7");
	QVERIFY(s::format<uchar>(-10) == "0xf6");

	QVERIFY(s::format<char>(0) == "0x00");
	QVERIFY(s::format<char>(9) == "0x09");
	QVERIFY(s::format<char>(10) == "0x0a");
	QVERIFY(s::format<char>(99) == "0x63");
	QVERIFY(s::format<char>(100) == "0x64");
	QVERIFY(s::format<char>(127) == "0x7f");

	QVERIFY(s::format<char>(-1) == "0xff");
	QVERIFY(s::format<char>(-9) == "0xf7");
	QVERIFY(s::format<char>(-10) == "0xf6");
	QVERIFY(s::format<char>(-99) == "0x9d");
	QVERIFY(s::format<char>(-100) == "0x9c");
	QVERIFY(s::format<char>(-255 & 0xff) == "0x01");

	QVERIFY(s::format<signed char>(0) == "0x00");
	QVERIFY(s::format<signed char>(9) == "0x09");
	QVERIFY(s::format<signed char>(10) == "0x0a");
	QVERIFY(s::format<signed char>(99) == "0x63");
	QVERIFY(s::format<signed char>(100) == "0x64");
	QVERIFY(s::format<signed char>(127) == "0x7f");

	QVERIFY(s::format<signed char>(-1) == "0xff");
	QVERIFY(s::format<signed char>(-9) == "0xf7");
	QVERIFY(s::format<signed char>(-10) == "0xf6");
	QVERIFY(s::format<signed char>(-99) == "0x9d");
	QVERIFY(s::format<signed char>(-100) == "0x9c");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "0x01");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexCharLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uchar>(0) == "0x00");
	QVERIFY(s::format<uchar>(9) == "0x09");
	QVERIFY(s::format<uchar>(10) == "0x0A");
	QVERIFY(s::format<uchar>(99) == "0x63");
	QVERIFY(s::format<uchar>(100) == "0x64");
	QVERIFY(s::format<uchar>(255) == "0xFF");

	QVERIFY(s::format<uchar>(-1) == "0xFF");
	QVERIFY(s::format<uchar>(-9) == "0xF7");
	QVERIFY(s::format<uchar>(-10) == "0xF6");

	QVERIFY(s::format<char>(0) == "0x00");
	QVERIFY(s::format<char>(9) == "0x09");
	QVERIFY(s::format<char>(10) == "0x0A");
	QVERIFY(s::format<char>(99) == "0x63");
	QVERIFY(s::format<char>(100) == "0x64");
	QVERIFY(s::format<char>(127) == "0x7F");

	QVERIFY(s::format<char>(-1) == "0xFF");
	QVERIFY(s::format<char>(-9) == "0xF7");
	QVERIFY(s::format<char>(-10) == "0xF6");
	QVERIFY(s::format<char>(-99) == "0x9D");
	QVERIFY(s::format<char>(-100) == "0x9C");
	QVERIFY(s::format<char>(-255 & 0xff) == "0x01");

	QVERIFY(s::format<signed char>(0) == "0x00");
	QVERIFY(s::format<signed char>(9) == "0x09");
	QVERIFY(s::format<signed char>(10) == "0x0A");
	QVERIFY(s::format<signed char>(99) == "0x63");
	QVERIFY(s::format<signed char>(100) == "0x64");
	QVERIFY(s::format<signed char>(127) == "0x7F");

	QVERIFY(s::format<signed char>(-1) == "0xFF");
	QVERIFY(s::format<signed char>(-9) == "0xF7");
	QVERIFY(s::format<signed char>(-10) == "0xF6");
	QVERIFY(s::format<signed char>(-99) == "0x9D");
	QVERIFY(s::format<signed char>(-100) == "0x9C");
	QVERIFY(s::format<signed char>(-255 & 0xff) == "0x01");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<ushort>(0) == "0x0");
	QVERIFY(s::format<ushort>(9) == "0x9");
	QVERIFY(s::format<ushort>(10) == "0xa");
	QVERIFY(s::format<ushort>(99) == "0x63");
	QVERIFY(s::format<ushort>(100) == "0x64");
	QVERIFY(s::format<ushort>(255) == "0xff");
	QVERIFY(s::format<ushort>(256) == "0x100");
	QVERIFY(s::format<ushort>(1000) == "0x3e8");
	QVERIFY(s::format<ushort>(65535) == "0xffff");

	QVERIFY(s::format<ushort>(-1) == "0xffff");
	QVERIFY(s::format<ushort>(-9) == "0xfff7");
	QVERIFY(s::format<ushort>(-10) == "0xfff6");

	QVERIFY(s::format<short>(0) == "0x0");
	QVERIFY(s::format<short>(9) == "0x9");
	QVERIFY(s::format<short>(10) == "0xa");
	QVERIFY(s::format<short>(99) == "0x63");
	QVERIFY(s::format<short>(100) == "0x64");
	QVERIFY(s::format<short>(255) == "0xff");
	QVERIFY(s::format<short>(256) == "0x100");
	QVERIFY(s::format<short>(1000) == "0x3e8");
	QVERIFY(s::format<short>(32767) == "0x7fff");

	QVERIFY(s::format<short>(-1) == "0xffff");
	QVERIFY(s::format<short>(-9) == "0xfff7");
	QVERIFY(s::format<short>(-10) == "0xfff6");
	QVERIFY(s::format<short>(-99) == "0xff9d");
	QVERIFY(s::format<short>(-100) == "0xff9c");
	QVERIFY(s::format<short>(-255) == "0xff01");
	QVERIFY(s::format<short>(-256) == "0xff00");
	QVERIFY(s::format<short>(-1000) == "0xfc18");
	QVERIFY(s::format<short>(-32767) == "0x8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ushort>(0) == "0x0");
	QVERIFY(s::format<ushort>(9) == "0x9");
	QVERIFY(s::format<ushort>(10) == "0xA");
	QVERIFY(s::format<ushort>(99) == "0x63");
	QVERIFY(s::format<ushort>(100) == "0x64");
	QVERIFY(s::format<ushort>(255) == "0xFF");
	QVERIFY(s::format<ushort>(256) == "0x100");
	QVERIFY(s::format<ushort>(1000) == "0x3E8");
	QVERIFY(s::format<ushort>(65535) == "0xFFFF");

	QVERIFY(s::format<ushort>(-1) == "0xFFFF");
	QVERIFY(s::format<ushort>(-9) == "0xFFF7");
	QVERIFY(s::format<ushort>(-10) == "0xFFF6");

	QVERIFY(s::format<short>(0) == "0x0");
	QVERIFY(s::format<short>(9) == "0x9");
	QVERIFY(s::format<short>(10) == "0xA");
	QVERIFY(s::format<short>(99) == "0x63");
	QVERIFY(s::format<short>(100) == "0x64");
	QVERIFY(s::format<short>(255) == "0xFF");
	QVERIFY(s::format<short>(256) == "0x100");
	QVERIFY(s::format<short>(1000) == "0x3E8");
	QVERIFY(s::format<short>(32767) == "0x7FFF");

	QVERIFY(s::format<short>(-1) == "0xFFFF");
	QVERIFY(s::format<short>(-9) == "0xFFF7");
	QVERIFY(s::format<short>(-10) == "0xFFF6");
	QVERIFY(s::format<short>(-99) == "0xFF9D");
	QVERIFY(s::format<short>(-100) == "0xFF9C");
	QVERIFY(s::format<short>(-255) == "0xFF01");
	QVERIFY(s::format<short>(-256) == "0xFF00");
	QVERIFY(s::format<short>(-1000) == "0xFC18");
	QVERIFY(s::format<short>(-32767) == "0x8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<ushort>(0) == "0x0000");
	QVERIFY(s::format<ushort>(9) == "0x0009");
	QVERIFY(s::format<ushort>(10) == "0x000a");
	QVERIFY(s::format<ushort>(99) == "0x0063");
	QVERIFY(s::format<ushort>(100) == "0x0064");
	QVERIFY(s::format<ushort>(255) == "0x00ff");
	QVERIFY(s::format<ushort>(256) == "0x0100");
	QVERIFY(s::format<ushort>(1000) == "0x03e8");
	QVERIFY(s::format<ushort>(65535) == "0xffff");

	QVERIFY(s::format<ushort>(-1) == "0xffff");
	QVERIFY(s::format<ushort>(-9) == "0xfff7");
	QVERIFY(s::format<ushort>(-10) == "0xfff6");

	QVERIFY(s::format<short>(0) == "0x0000");
	QVERIFY(s::format<short>(9) == "0x0009");
	QVERIFY(s::format<short>(10) == "0x000a");
	QVERIFY(s::format<short>(99) == "0x0063");
	QVERIFY(s::format<short>(100) == "0x0064");
	QVERIFY(s::format<short>(255) == "0x00ff");
	QVERIFY(s::format<short>(256) == "0x0100");
	QVERIFY(s::format<short>(1000) == "0x03e8");
	QVERIFY(s::format<short>(32767) == "0x7fff");

	QVERIFY(s::format<short>(-1) == "0xffff");
	QVERIFY(s::format<short>(-9) == "0xfff7");
	QVERIFY(s::format<short>(-10) == "0xfff6");
	QVERIFY(s::format<short>(-99) == "0xff9d");
	QVERIFY(s::format<short>(-100) == "0xff9c");
	QVERIFY(s::format<short>(-255) == "0xff01");
	QVERIFY(s::format<short>(-256) == "0xff00");
	QVERIFY(s::format<short>(-1000) == "0xfc18");
	QVERIFY(s::format<short>(-32767) == "0x8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0x0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShortLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ushort>(0) == "0x0000");
	QVERIFY(s::format<ushort>(9) == "0x0009");
	QVERIFY(s::format<ushort>(10) == "0x000A");
	QVERIFY(s::format<ushort>(99) == "0x0063");
	QVERIFY(s::format<ushort>(100) == "0x0064");
	QVERIFY(s::format<ushort>(255) == "0x00FF");
	QVERIFY(s::format<ushort>(256) == "0x0100");
	QVERIFY(s::format<ushort>(1000) == "0x03E8");
	QVERIFY(s::format<ushort>(65535) == "0xFFFF");

	QVERIFY(s::format<ushort>(-1) == "0xFFFF");
	QVERIFY(s::format<ushort>(-9) == "0xFFF7");
	QVERIFY(s::format<ushort>(-10) == "0xFFF6");

	QVERIFY(s::format<short>(0) == "0x0000");
	QVERIFY(s::format<short>(9) == "0x0009");
	QVERIFY(s::format<short>(10) == "0x000A");
	QVERIFY(s::format<short>(99) == "0x0063");
	QVERIFY(s::format<short>(100) == "0x0064");
	QVERIFY(s::format<short>(255) == "0x00FF");
	QVERIFY(s::format<short>(256) == "0x0100");
	QVERIFY(s::format<short>(1000) == "0x03E8");
	QVERIFY(s::format<short>(32767) == "0x7FFF");

	QVERIFY(s::format<short>(-1) == "0xFFFF");
	QVERIFY(s::format<short>(-9) == "0xFFF7");
	QVERIFY(s::format<short>(-10) == "0xFFF6");
	QVERIFY(s::format<short>(-99) == "0xFF9D");
	QVERIFY(s::format<short>(-100) == "0xFF9C");
	QVERIFY(s::format<short>(-255) == "0xFF01");
	QVERIFY(s::format<short>(-256) == "0xFF00");
	QVERIFY(s::format<short>(-1000) == "0xFC18");
	QVERIFY(s::format<short>(-32767) == "0x8001");
	QVERIFY(s::format<short>(-65535 & 0xffff) == "0x0001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<uint>(0) == "0x0");
	QVERIFY(s::format<uint>(9) == "0x9");
	QVERIFY(s::format<uint>(10) == "0xa");
	QVERIFY(s::format<uint>(99) == "0x63");
	QVERIFY(s::format<uint>(100) == "0x64");
	QVERIFY(s::format<uint>(255) == "0xff");
	QVERIFY(s::format<uint>(256) == "0x100");
	QVERIFY(s::format<uint>(1000) == "0x3e8");
	QVERIFY(s::format<uint>(4294967295) == "0xffffffff");

	QVERIFY(s::format<uint>(-1) == "0xffffffff");
	QVERIFY(s::format<uint>(-9) == "0xfffffff7");
	QVERIFY(s::format<uint>(-10) == "0xfffffff6");

	QVERIFY(s::format<int>(0) == "0x0");
	QVERIFY(s::format<int>(9) == "0x9");
	QVERIFY(s::format<int>(10) == "0xa");
	QVERIFY(s::format<int>(99) == "0x63");
	QVERIFY(s::format<int>(100) == "0x64");
	QVERIFY(s::format<int>(255) == "0xff");
	QVERIFY(s::format<int>(256) == "0x100");
	QVERIFY(s::format<int>(1000) == "0x3e8");
	QVERIFY(s::format<int>(2147483647) == "0x7fffffff");
	QVERIFY(s::format<int>(4294967295) == "0xffffffff");

	QVERIFY(s::format<int>(-1) == "0xffffffff");
	QVERIFY(s::format<int>(-9) == "0xfffffff7");
	QVERIFY(s::format<int>(-10) == "0xfffffff6");
	QVERIFY(s::format<int>(-99) == "0xffffff9d");
	QVERIFY(s::format<int>(-100) == "0xffffff9c");
	QVERIFY(s::format<int>(-255) == "0xffffff01");
	QVERIFY(s::format<int>(-256) == "0xffffff00");
	QVERIFY(s::format<int>(-1000) == "0xfffffc18");
	QVERIFY(s::format<int>(-2147483647) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uint>(0) == "0x0");
	QVERIFY(s::format<uint>(9) == "0x9");
	QVERIFY(s::format<uint>(10) == "0xA");
	QVERIFY(s::format<uint>(99) == "0x63");
	QVERIFY(s::format<uint>(100) == "0x64");
	QVERIFY(s::format<uint>(255) == "0xFF");
	QVERIFY(s::format<uint>(256) == "0x100");
	QVERIFY(s::format<uint>(1000) == "0x3E8");
	QVERIFY(s::format<uint>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<uint>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<uint>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<uint>(-10) == "0xFFFFFFF6");

	QVERIFY(s::format<int>(0) == "0x0");
	QVERIFY(s::format<int>(9) == "0x9");
	QVERIFY(s::format<int>(10) == "0xA");
	QVERIFY(s::format<int>(99) == "0x63");
	QVERIFY(s::format<int>(100) == "0x64");
	QVERIFY(s::format<int>(255) == "0xFF");
	QVERIFY(s::format<int>(256) == "0x100");
	QVERIFY(s::format<int>(1000) == "0x3E8");
	QVERIFY(s::format<int>(2147483647) == "0x7FFFFFFF");
	QVERIFY(s::format<int>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<int>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<int>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<int>(-10) == "0xFFFFFFF6");
	QVERIFY(s::format<int>(-99) == "0xFFFFFF9D");
	QVERIFY(s::format<int>(-100) == "0xFFFFFF9C");
	QVERIFY(s::format<int>(-255) == "0xFFFFFF01");
	QVERIFY(s::format<int>(-256) == "0xFFFFFF00");
	QVERIFY(s::format<int>(-1000) == "0xFFFFFC18");
	QVERIFY(s::format<int>(-2147483647) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<uint>(0) == "0x00000000");
	QVERIFY(s::format<uint>(9) == "0x00000009");
	QVERIFY(s::format<uint>(10) == "0x0000000a");
	QVERIFY(s::format<uint>(99) == "0x00000063");
	QVERIFY(s::format<uint>(100) == "0x00000064");
	QVERIFY(s::format<uint>(255) == "0x000000ff");
	QVERIFY(s::format<uint>(256) == "0x00000100");
	QVERIFY(s::format<uint>(1000) == "0x000003e8");
	QVERIFY(s::format<uint>(4294967295) == "0xffffffff");

	QVERIFY(s::format<uint>(-1) == "0xffffffff");
	QVERIFY(s::format<uint>(-9) == "0xfffffff7");
	QVERIFY(s::format<uint>(-10) == "0xfffffff6");

	QVERIFY(s::format<int>(0) == "0x00000000");
	QVERIFY(s::format<int>(9) == "0x00000009");
	QVERIFY(s::format<int>(10) == "0x0000000a");
	QVERIFY(s::format<int>(99) == "0x00000063");
	QVERIFY(s::format<int>(100) == "0x00000064");
	QVERIFY(s::format<int>(255) == "0x000000ff");
	QVERIFY(s::format<int>(256) == "0x00000100");
	QVERIFY(s::format<int>(1000) == "0x000003e8");
	QVERIFY(s::format<int>(2147483647) == "0x7fffffff");
	QVERIFY(s::format<int>(4294967295) == "0xffffffff");

	QVERIFY(s::format<int>(-1) == "0xffffffff");
	QVERIFY(s::format<int>(-9) == "0xfffffff7");
	QVERIFY(s::format<int>(-10) == "0xfffffff6");
	QVERIFY(s::format<int>(-99) == "0xffffff9d");
	QVERIFY(s::format<int>(-100) == "0xffffff9c");
	QVERIFY(s::format<int>(-255) == "0xffffff01");
	QVERIFY(s::format<int>(-256) == "0xffffff00");
	QVERIFY(s::format<int>(-1000) == "0xfffffc18");
	QVERIFY(s::format<int>(-2147483647) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "0x00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexIntLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<uint>(0) == "0x00000000");
	QVERIFY(s::format<uint>(9) == "0x00000009");
	QVERIFY(s::format<uint>(10) == "0x0000000A");
	QVERIFY(s::format<uint>(99) == "0x00000063");
	QVERIFY(s::format<uint>(100) == "0x00000064");
	QVERIFY(s::format<uint>(255) == "0x000000FF");
	QVERIFY(s::format<uint>(256) == "0x00000100");
	QVERIFY(s::format<uint>(1000) == "0x000003E8");
	QVERIFY(s::format<uint>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<uint>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<uint>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<uint>(-10) == "0xFFFFFFF6");

	QVERIFY(s::format<int>(0) == "0x00000000");
	QVERIFY(s::format<int>(9) == "0x00000009");
	QVERIFY(s::format<int>(10) == "0x0000000A");
	QVERIFY(s::format<int>(99) == "0x00000063");
	QVERIFY(s::format<int>(100) == "0x00000064");
	QVERIFY(s::format<int>(255) == "0x000000FF");
	QVERIFY(s::format<int>(256) == "0x00000100");
	QVERIFY(s::format<int>(1000) == "0x000003E8");
	QVERIFY(s::format<int>(2147483647) == "0x7FFFFFFF");
	QVERIFY(s::format<int>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<int>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<int>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<int>(-10) == "0xFFFFFFF6");
	QVERIFY(s::format<int>(-99) == "0xFFFFFF9D");
	QVERIFY(s::format<int>(-100) == "0xFFFFFF9C");
	QVERIFY(s::format<int>(-255) == "0xFFFFFF01");
	QVERIFY(s::format<int>(-256) == "0xFFFFFF00");
	QVERIFY(s::format<int>(-1000) == "0xFFFFFC18");
	QVERIFY(s::format<int>(-2147483647) == "0x80000001");
	QVERIFY(s::format<int>(0-4294967295UL) == "0x00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<ulong>(0) == "0x0");
	QVERIFY(s::format<ulong>(9) == "0x9");
	QVERIFY(s::format<ulong>(10) == "0xa");
	QVERIFY(s::format<ulong>(99) == "0x63");
	QVERIFY(s::format<ulong>(100) == "0x64");
	QVERIFY(s::format<ulong>(255) == "0xff");
	QVERIFY(s::format<ulong>(256) == "0x100");
	QVERIFY(s::format<ulong>(1000) == "0x3e8");
	QVERIFY(s::format<ulong>(4294967295) == "0xffffffff");

	QVERIFY(s::format<ulong>(-1) == "0xffffffff");
	QVERIFY(s::format<ulong>(-9) == "0xfffffff7");
	QVERIFY(s::format<ulong>(-10) == "0xfffffff6");

	QVERIFY(s::format<long>(0) == "0x0");
	QVERIFY(s::format<long>(9) == "0x9");
	QVERIFY(s::format<long>(10) == "0xa");
	QVERIFY(s::format<long>(99) == "0x63");
	QVERIFY(s::format<long>(100) == "0x64");
	QVERIFY(s::format<long>(255) == "0xff");
	QVERIFY(s::format<long>(256) == "0x100");
	QVERIFY(s::format<long>(1000) == "0x3e8");
	QVERIFY(s::format<long>(2147483647) == "0x7fffffff");
	QVERIFY(s::format<long>(4294967295) == "0xffffffff");

	QVERIFY(s::format<long>(-1) == "0xffffffff");
	QVERIFY(s::format<long>(-9) == "0xfffffff7");
	QVERIFY(s::format<long>(-10) == "0xfffffff6");
	QVERIFY(s::format<long>(-99) == "0xffffff9d");
	QVERIFY(s::format<long>(-100) == "0xffffff9c");
	QVERIFY(s::format<long>(-255) == "0xffffff01");
	QVERIFY(s::format<long>(-256) == "0xffffff00");
	QVERIFY(s::format<long>(-1000) == "0xfffffc18");
	QVERIFY(s::format<long>(-2147483647) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ulong>(0) == "0x0");
	QVERIFY(s::format<ulong>(9) == "0x9");
	QVERIFY(s::format<ulong>(10) == "0xA");
	QVERIFY(s::format<ulong>(99) == "0x63");
	QVERIFY(s::format<ulong>(100) == "0x64");
	QVERIFY(s::format<ulong>(255) == "0xFF");
	QVERIFY(s::format<ulong>(256) == "0x100");
	QVERIFY(s::format<ulong>(1000) == "0x3E8");
	QVERIFY(s::format<ulong>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<ulong>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<ulong>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<ulong>(-10) == "0xFFFFFFF6");

	QVERIFY(s::format<long>(0) == "0x0");
	QVERIFY(s::format<long>(9) == "0x9");
	QVERIFY(s::format<long>(10) == "0xA");
	QVERIFY(s::format<long>(99) == "0x63");
	QVERIFY(s::format<long>(100) == "0x64");
	QVERIFY(s::format<long>(255) == "0xFF");
	QVERIFY(s::format<long>(256) == "0x100");
	QVERIFY(s::format<long>(1000) == "0x3E8");
	QVERIFY(s::format<long>(2147483647) == "0x7FFFFFFF");
	QVERIFY(s::format<long>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<long>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<long>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<long>(-10) == "0xFFFFFFF6");
	QVERIFY(s::format<long>(-99) == "0xFFFFFF9D");
	QVERIFY(s::format<long>(-100) == "0xFFFFFF9C");
	QVERIFY(s::format<long>(-255) == "0xFFFFFF01");
	QVERIFY(s::format<long>(-256) == "0xFFFFFF00");
	QVERIFY(s::format<long>(-1000) == "0xFFFFFC18");
	QVERIFY(s::format<long>(-2147483647) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongLzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<ulong>(0) == "0x00000000");
	QVERIFY(s::format<ulong>(9) == "0x00000009");
	QVERIFY(s::format<ulong>(10) == "0x0000000a");
	QVERIFY(s::format<ulong>(99) == "0x00000063");
	QVERIFY(s::format<ulong>(100) == "0x00000064");
	QVERIFY(s::format<ulong>(255) == "0x000000ff");
	QVERIFY(s::format<ulong>(256) == "0x00000100");
	QVERIFY(s::format<ulong>(1000) == "0x000003e8");
	QVERIFY(s::format<ulong>(4294967295) == "0xffffffff");

	QVERIFY(s::format<ulong>(-1) == "0xffffffff");
	QVERIFY(s::format<ulong>(-9) == "0xfffffff7");
	QVERIFY(s::format<ulong>(-10) == "0xfffffff6");

	QVERIFY(s::format<long>(0) == "0x00000000");
	QVERIFY(s::format<long>(9) == "0x00000009");
	QVERIFY(s::format<long>(10) == "0x0000000a");
	QVERIFY(s::format<long>(99) == "0x00000063");
	QVERIFY(s::format<long>(100) == "0x00000064");
	QVERIFY(s::format<long>(255) == "0x000000ff");
	QVERIFY(s::format<long>(256) == "0x00000100");
	QVERIFY(s::format<long>(1000) == "0x000003e8");
	QVERIFY(s::format<long>(2147483647) == "0x7fffffff");
	QVERIFY(s::format<long>(4294967295) == "0xffffffff");

	QVERIFY(s::format<long>(-1) == "0xffffffff");
	QVERIFY(s::format<long>(-9) == "0xfffffff7");
	QVERIFY(s::format<long>(-10) == "0xfffffff6");
	QVERIFY(s::format<long>(-99) == "0xffffff9d");
	QVERIFY(s::format<long>(-100) == "0xffffff9c");
	QVERIFY(s::format<long>(-255) == "0xffffff01");
	QVERIFY(s::format<long>(-256) == "0xffffff00");
	QVERIFY(s::format<long>(-1000) == "0xfffffc18");
	QVERIFY(s::format<long>(-2147483647) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "0x00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLongLzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<ulong>(0) == "0x00000000");
	QVERIFY(s::format<ulong>(9) == "0x00000009");
	QVERIFY(s::format<ulong>(10) == "0x0000000A");
	QVERIFY(s::format<ulong>(99) == "0x00000063");
	QVERIFY(s::format<ulong>(100) == "0x00000064");
	QVERIFY(s::format<ulong>(255) == "0x000000FF");
	QVERIFY(s::format<ulong>(256) == "0x00000100");
	QVERIFY(s::format<ulong>(1000) == "0x000003E8");
	QVERIFY(s::format<ulong>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<ulong>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<ulong>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<ulong>(-10) == "0xFFFFFFF6");

	QVERIFY(s::format<long>(0) == "0x00000000");
	QVERIFY(s::format<long>(9) == "0x00000009");
	QVERIFY(s::format<long>(10) == "0x0000000A");
	QVERIFY(s::format<long>(99) == "0x00000063");
	QVERIFY(s::format<long>(100) == "0x00000064");
	QVERIFY(s::format<long>(255) == "0x000000FF");
	QVERIFY(s::format<long>(256) == "0x00000100");
	QVERIFY(s::format<long>(1000) == "0x000003E8");
	QVERIFY(s::format<long>(2147483647) == "0x7FFFFFFF");
	QVERIFY(s::format<long>(4294967295) == "0xFFFFFFFF");

	QVERIFY(s::format<long>(-1) == "0xFFFFFFFF");
	QVERIFY(s::format<long>(-9) == "0xFFFFFFF7");
	QVERIFY(s::format<long>(-10) == "0xFFFFFFF6");
	QVERIFY(s::format<long>(-99) == "0xFFFFFF9D");
	QVERIFY(s::format<long>(-100) == "0xFFFFFF9C");
	QVERIFY(s::format<long>(-255) == "0xFFFFFF01");
	QVERIFY(s::format<long>(-256) == "0xFFFFFF00");
	QVERIFY(s::format<long>(-1000) == "0xFFFFFC18");
	QVERIFY(s::format<long>(-2147483647) == "0x80000001");
	QVERIFY(s::format<long>(0-4294967295UL) == "0x00000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64Prefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<quint64>(0) == "0x0");
	QVERIFY(s::format<quint64>(9) == "0x9");
	QVERIFY(s::format<quint64>(10) == "0xa");
	QVERIFY(s::format<quint64>(99) == "0x63");
	QVERIFY(s::format<quint64>(100) == "0x64");
	QVERIFY(s::format<quint64>(255) == "0xff");
	QVERIFY(s::format<quint64>(256) == "0x100");
	QVERIFY(s::format<quint64>(1000) == "0x3e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "0xffffffffffffffff");

	QVERIFY(s::format<quint64>(-1) == "0xffffffffffffffff");
	QVERIFY(s::format<quint64>(-9) == "0xfffffffffffffff7");
	QVERIFY(s::format<quint64>(-10) == "0xfffffffffffffff6");

	QVERIFY(s::format<qint64>(0) == "0x0");
	QVERIFY(s::format<qint64>(9) == "0x9");
	QVERIFY(s::format<qint64>(10) == "0xa");
	QVERIFY(s::format<qint64>(99) == "0x63");
	QVERIFY(s::format<qint64>(100) == "0x64");
	QVERIFY(s::format<qint64>(255) == "0xff");
	QVERIFY(s::format<qint64>(256) == "0x100");
	QVERIFY(s::format<qint64>(1000) == "0x3e8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "0x7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "0xffffffffffffffff");

	QVERIFY(s::format<qint64>(-1) == "0xffffffffffffffff");
	QVERIFY(s::format<qint64>(-9) == "0xfffffffffffffff7");
	QVERIFY(s::format<qint64>(-10) == "0xfffffffffffffff6");
	QVERIFY(s::format<qint64>(-99) == "0xffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100) == "0xffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255) == "0xffffffffffffff01");
	QVERIFY(s::format<qint64>(-256) == "0xffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000) == "0xfffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64UpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<quint64>(0) == "0x0");
	QVERIFY(s::format<quint64>(9) == "0x9");
	QVERIFY(s::format<quint64>(10) == "0xA");
	QVERIFY(s::format<quint64>(99) == "0x63");
	QVERIFY(s::format<quint64>(100) == "0x64");
	QVERIFY(s::format<quint64>(255) == "0xFF");
	QVERIFY(s::format<quint64>(256) == "0x100");
	QVERIFY(s::format<quint64>(1000) == "0x3E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0) == "0x0");
	QVERIFY(s::format<qint64>(9) == "0x9");
	QVERIFY(s::format<qint64>(10) == "0xA");
	QVERIFY(s::format<qint64>(99) == "0x63");
	QVERIFY(s::format<qint64>(100) == "0x64");
	QVERIFY(s::format<qint64>(255) == "0xFF");
	QVERIFY(s::format<qint64>(256) == "0x100");
	QVERIFY(s::format<qint64>(1000) == "0x3E8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0x1");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64LzPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format<quint64>(0) == "0x0000000000000000");
	QVERIFY(s::format<quint64>(9) == "0x0000000000000009");
	QVERIFY(s::format<quint64>(10) == "0x000000000000000a");
	QVERIFY(s::format<quint64>(99) == "0x0000000000000063");
	QVERIFY(s::format<quint64>(100) == "0x0000000000000064");
	QVERIFY(s::format<quint64>(255) == "0x00000000000000ff");
	QVERIFY(s::format<quint64>(256) == "0x0000000000000100");
	QVERIFY(s::format<quint64>(1000) == "0x00000000000003e8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "0xffffffffffffffff");

	QVERIFY(s::format<quint64>(-1) == "0xffffffffffffffff");
	QVERIFY(s::format<quint64>(-9) == "0xfffffffffffffff7");
	QVERIFY(s::format<quint64>(-10) == "0xfffffffffffffff6");

	QVERIFY(s::format<qint64>(0) == "0x0000000000000000");
	QVERIFY(s::format<qint64>(9) == "0x0000000000000009");
	QVERIFY(s::format<qint64>(10) == "0x000000000000000a");
	QVERIFY(s::format<qint64>(99) == "0x0000000000000063");
	QVERIFY(s::format<qint64>(100) == "0x0000000000000064");
	QVERIFY(s::format<qint64>(255) == "0x00000000000000ff");
	QVERIFY(s::format<qint64>(256) == "0x0000000000000100");
	QVERIFY(s::format<qint64>(1000) == "0x00000000000003e8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "0x7fffffffffffffff");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "0xffffffffffffffff");

	QVERIFY(s::format<qint64>(-1) == "0xffffffffffffffff");
	QVERIFY(s::format<qint64>(-9) == "0xfffffffffffffff7");
	QVERIFY(s::format<qint64>(-10) == "0xfffffffffffffff6");
	QVERIFY(s::format<qint64>(-99) == "0xffffffffffffff9d");
	QVERIFY(s::format<qint64>(-100) == "0xffffffffffffff9c");
	QVERIFY(s::format<qint64>(-255) == "0xffffffffffffff01");
	QVERIFY(s::format<qint64>(-256) == "0xffffffffffffff00");
	QVERIFY(s::format<qint64>(-1000) == "0xfffffffffffffc18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0x0000000000000001");
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64LzUpperPrefix()
{
	// ---- without leading zero
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format<quint64>(0) == "0x0000000000000000");
	QVERIFY(s::format<quint64>(9) == "0x0000000000000009");
	QVERIFY(s::format<quint64>(10) == "0x000000000000000A");
	QVERIFY(s::format<quint64>(99) == "0x0000000000000063");
	QVERIFY(s::format<quint64>(100) == "0x0000000000000064");
	QVERIFY(s::format<quint64>(255) == "0x00000000000000FF");
	QVERIFY(s::format<quint64>(256) == "0x0000000000000100");
	QVERIFY(s::format<quint64>(1000) == "0x00000000000003E8");
	QVERIFY(s::format<quint64>(18446744073709551615ULL) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<quint64>(-1) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<quint64>(-9) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<quint64>(-10) == "0xFFFFFFFFFFFFFFF6");

	QVERIFY(s::format<qint64>(0) == "0x0000000000000000");
	QVERIFY(s::format<qint64>(9) == "0x0000000000000009");
	QVERIFY(s::format<qint64>(10) == "0x000000000000000A");
	QVERIFY(s::format<qint64>(99) == "0x0000000000000063");
	QVERIFY(s::format<qint64>(100) == "0x0000000000000064");
	QVERIFY(s::format<qint64>(255) == "0x00000000000000FF");
	QVERIFY(s::format<qint64>(256) == "0x0000000000000100");
	QVERIFY(s::format<qint64>(1000) == "0x00000000000003E8");
	QVERIFY(s::format<qint64>(9223372036854775807) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(18446744073709551615ULL) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format<qint64>(-1) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format<qint64>(-9) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format<qint64>(-10) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format<qint64>(-99) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format<qint64>(-100) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format<qint64>(-255) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format<qint64>(-256) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format<qint64>(-1000) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format<qint64>(-9223372036854775807) == "0x8000000000000001");
	QVERIFY(s::format<qint64>(0-18446744073709551615ULL) == "0x0000000000000001");
}

QTEST_MAIN(TestNumberStringifier2ByteArray)
#include "test_numberstringifier2bytearray.moc"

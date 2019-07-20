#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

struct Signed { };
struct Unsigned { };

namespace _____decimal_digits_count_tests_____ { }

template <
	typename T,
	typename Signed =
		typename std::conditional<
			std::is_signed<T>::value,
			Signed, Unsigned
		>::type,
	size_t size = sizeof(T)>
struct TestDecDigitCount;

template <typename T>
struct TestDecDigitCount<T, Signed, 1> { static void test(); };
template <typename T>
struct TestDecDigitCount<T, Unsigned, 1> { static void test(); };

template <typename T>
struct TestDecDigitCount<T, Signed, 2> { static void test(); };
template <typename T>
struct TestDecDigitCount<T, Unsigned, 2> { static void test(); };

template <typename T>
struct TestDecDigitCount<T, Signed, 4> { static void test(); };
template <typename T>
struct TestDecDigitCount<T, Unsigned, 4> { static void test(); };

template <typename T>
struct TestDecDigitCount<T, Signed, 8> { static void test(); };
template <typename T>
struct TestDecDigitCount<T, Unsigned, 8> { static void test(); };

namespace _____hexadecimal_digits_count_tests_____ { }

template <
	typename T,
	typename Signed =
		typename std::conditional<
			std::is_signed<T>::value,
			Signed, Unsigned
		>::type,
	size_t size = sizeof(T)>
struct TestHexDigitCount;

template <typename T>
struct TestHexDigitCount<T, Signed, 1> { static void test(); };
template <typename T>
struct TestHexDigitCount<T, Unsigned, 1> { static void test(); };

template <typename T>
struct TestHexDigitCount<T, Signed, 2> { static void test(); };
template <typename T>
struct TestHexDigitCount<T, Unsigned, 2> { static void test(); };

template <typename T>
struct TestHexDigitCount<T, Signed, 4> { static void test(); };
template <typename T>
struct TestHexDigitCount<T, Unsigned, 4> { static void test(); };

template <typename T>
struct TestHexDigitCount<T, Signed, 8> { static void test(); };
template <typename T>
struct TestHexDigitCount<T, Unsigned, 8> { static void test(); };

namespace _____decimal_tester_____ { }

template <
	typename T,
	typename Signed =
		typename std::conditional<
			std::is_signed<T>::value,
			Signed, Unsigned
		>::type,
	size_t size = sizeof(T)>
struct TesterDec;

template <typename T>
struct TesterDec<T, Signed, 1>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Unsigned, 1>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Signed, 2>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Unsigned, 2>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Signed, 4>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Unsigned, 4>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Signed, 8>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

template <typename T>
struct TesterDec<T, Unsigned, 8>
{
	static void test();
	static void test_lz();
	static void test_2d();
	static void test_3d();
	static void test_4d();
};

namespace _____hexadecimal_tester_____ { }

template <
	typename T,
	typename Signed =
		typename std::conditional<
			std::is_signed<T>::value,
			Signed, Unsigned
		>::type,
	size_t size = sizeof(T)>
struct TesterHex;

template <typename T>
struct TesterHex<T, Signed, 1>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Unsigned, 1>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Signed, 2>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Unsigned, 2>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Signed, 4>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Unsigned, 4>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Signed, 8>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

template <typename T>
struct TesterHex<T, Unsigned, 8>
{
	static void test();
	static void test_up();
	static void test_lz();
	static void test_lz_up();

	static void test_p();
	static void test_p_up();
	static void test_p_lz();
	static void test_p_lz_up();
};

namespace _____main_test_class_____ { }

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
	void testStaticFormatDecShort();
	void testStaticFormatDecInt();
	void testStaticFormatDecLong();
	void testStaticFormatDecInt64();

	void testStaticFormatHexChar();
	void testStaticFormatHexShort();
	void testStaticFormatHexInt();
	void testStaticFormatHexLong();
	void testStaticFormatHexInt64();
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
	TestDecDigitCount<uchar>::test();
	TestDecDigitCount<char>::test();
	TestDecDigitCount<signed char>::test();

	TestDecDigitCount<ushort>::test();
	TestDecDigitCount<short>::test();

	TestDecDigitCount<uint>::test();
	TestDecDigitCount<int>::test();

	TestDecDigitCount<ulong>::test();
	TestDecDigitCount<long>::test();

	TestDecDigitCount<quint64>::test();
	TestDecDigitCount<qint64>::test();
}

void TestNumberStringifier2ByteArray::testHexadecimalDigitsCount()
{
	TestHexDigitCount<uchar>::test();
	TestHexDigitCount<ushort>::test();
	TestHexDigitCount<uint>::test();
	TestHexDigitCount<ulong>::test();
	TestHexDigitCount<quint64>::test();
}

void TestNumberStringifier2ByteArray::testStaticFormatDecChar()
{
	TesterDec<signed char>::test();
	TesterDec<signed char>::test_lz();
	TesterDec<signed char>::test_2d();
	TesterDec<signed char>::test_3d();
	TesterDec<signed char>::test_4d();
	TesterDec<char>::test();
	TesterDec<char>::test_lz();
	TesterDec<char>::test_2d();
	TesterDec<char>::test_3d();
	TesterDec<char>::test_4d();
	TesterDec<uchar>::test();
	TesterDec<uchar>::test_lz();
	TesterDec<uchar>::test_2d();
	TesterDec<uchar>::test_3d();
	TesterDec<uchar>::test_4d();
}

void TestNumberStringifier2ByteArray::testStaticFormatDecShort()
{
	TesterDec<short>::test();
	TesterDec<short>::test_lz();
	TesterDec<short>::test_2d();
	TesterDec<short>::test_3d();
	TesterDec<short>::test_4d();
	TesterDec<ushort>::test();
	TesterDec<ushort>::test_lz();
	TesterDec<ushort>::test_2d();
	TesterDec<ushort>::test_3d();
	TesterDec<ushort>::test_4d();
}

void TestNumberStringifier2ByteArray::testStaticFormatDecInt()
{
	TesterDec<int>::test();
	TesterDec<int>::test_lz();
	TesterDec<int>::test_2d();
	TesterDec<int>::test_3d();
	TesterDec<int>::test_4d();
	TesterDec<uint>::test();
	TesterDec<uint>::test_lz();
	TesterDec<uint>::test_2d();
	TesterDec<uint>::test_3d();
	TesterDec<uint>::test_4d();
}

void TestNumberStringifier2ByteArray::testStaticFormatDecLong()
{
	TesterDec<long>::test();
	TesterDec<long>::test_lz();
	TesterDec<uint>::test_2d();
	TesterDec<uint>::test_3d();
	TesterDec<uint>::test_4d();
	TesterDec<ulong>::test();
	TesterDec<ulong>::test_lz();
	TesterDec<ulong>::test_2d();
	TesterDec<ulong>::test_3d();
	TesterDec<ulong>::test_4d();
}

void TestNumberStringifier2ByteArray::testStaticFormatDecInt64()
{
	TesterDec<qint64>::test();
	TesterDec<qint64>::test_lz();
	TesterDec<qint64>::test_2d();
	TesterDec<qint64>::test_3d();
	TesterDec<qint64>::test_4d();
	TesterDec<quint64>::test();
	TesterDec<quint64>::test_lz();
	TesterDec<quint64>::test_2d();
	TesterDec<quint64>::test_3d();
	TesterDec<quint64>::test_4d();
}

void TestNumberStringifier2ByteArray::testStaticFormatHexChar()
{
	TesterHex<signed char>::test();
	TesterHex<signed char>::test_up();
	TesterHex<signed char>::test_lz();
	TesterHex<signed char>::test_lz_up();

	TesterHex<char>::test();
	TesterHex<char>::test_up();
	TesterHex<char>::test_lz();
	TesterHex<char>::test_lz_up();

	TesterHex<uchar>::test();
	TesterHex<uchar>::test_up();
	TesterHex<uchar>::test_lz();
	TesterHex<uchar>::test_lz_up();

	TesterHex<signed char>::test_p();
	TesterHex<signed char>::test_p_up();
	TesterHex<signed char>::test_p_lz();
	TesterHex<signed char>::test_p_lz_up();

	TesterHex<char>::test_p();
	TesterHex<char>::test_p_up();
	TesterHex<char>::test_p_lz();
	TesterHex<char>::test_p_lz_up();

	TesterHex<uchar>::test_p();
	TesterHex<uchar>::test_p_up();
	TesterHex<uchar>::test_p_lz();
	TesterHex<uchar>::test_p_lz_up();
}

void TestNumberStringifier2ByteArray::testStaticFormatHexShort()
{
	TesterHex<short>::test();
	TesterHex<short>::test_up();
	TesterHex<short>::test_lz();
	TesterHex<short>::test_lz_up();

	TesterHex<ushort>::test();
	TesterHex<ushort>::test_up();
	TesterHex<ushort>::test_lz();
	TesterHex<ushort>::test_lz_up();

	TesterHex<short>::test_p();
	TesterHex<short>::test_p_up();
	TesterHex<short>::test_p_lz();
	TesterHex<short>::test_p_lz_up();

	TesterHex<ushort>::test_p();
	TesterHex<ushort>::test_p_up();
	TesterHex<ushort>::test_p_lz();
	TesterHex<ushort>::test_p_lz_up();
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt()
{
	TesterHex<int>::test();
	TesterHex<int>::test_up();
	TesterHex<int>::test_lz();
	TesterHex<int>::test_lz_up();

	TesterHex<uint>::test();
	TesterHex<uint>::test_up();
	TesterHex<uint>::test_lz();
	TesterHex<uint>::test_lz_up();

	TesterHex<int>::test_p();
	TesterHex<int>::test_p_up();
	TesterHex<int>::test_p_lz();
	TesterHex<int>::test_p_lz_up();

	TesterHex<uint>::test_p();
	TesterHex<uint>::test_p_up();
	TesterHex<uint>::test_p_lz();
	TesterHex<uint>::test_p_lz_up();
}

void TestNumberStringifier2ByteArray::testStaticFormatHexLong()
{
	TesterHex<long>::test();
	TesterHex<long>::test_up();
	TesterHex<long>::test_lz();
	TesterHex<long>::test_lz_up();

	TesterHex<ulong>::test();
	TesterHex<ulong>::test_up();
	TesterHex<ulong>::test_lz();
	TesterHex<ulong>::test_lz_up();

	TesterHex<long>::test_p();
	TesterHex<long>::test_p_up();
	TesterHex<long>::test_p_lz();
	TesterHex<long>::test_p_lz_up();

	TesterHex<ulong>::test_p();
	TesterHex<ulong>::test_p_up();
	TesterHex<ulong>::test_p_lz();
	TesterHex<ulong>::test_p_lz_up();
}

void TestNumberStringifier2ByteArray::testStaticFormatHexInt64()
{
	TesterHex<qint64>::test();
	TesterHex<qint64>::test_up();
	TesterHex<qint64>::test_lz();
	TesterHex<qint64>::test_lz_up();

	TesterHex<quint64>::test();
	TesterHex<quint64>::test_up();
	TesterHex<quint64>::test_lz();
	TesterHex<quint64>::test_lz_up();

	TesterHex<qint64>::test_p();
	TesterHex<qint64>::test_p_up();
	TesterHex<qint64>::test_p_lz();
	TesterHex<qint64>::test_p_lz_up();

	TesterHex<quint64>::test_p();
	TesterHex<quint64>::test_p_up();
	TesterHex<quint64>::test_p_lz();
	TesterHex<quint64>::test_p_lz_up();
}

namespace _____decimal_digits_count_tests_____ { }

template<typename T>
void TestDecDigitCount<T, Signed, 1>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(127) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-128) == 3);
}

template<typename T>
void TestDecDigitCount<T, Unsigned, 1>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(255) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
}

template<typename T>
void TestDecDigitCount<T, Signed, 2>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(32767) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(-32768) == 5);
}

template<typename T>
void TestDecDigitCount<T, Unsigned, 2>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(65535) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
}

template<typename T>
void TestDecDigitCount<T, Signed, 4>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(2147483647) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>((-2147483647L - 1)) == 10);
}

template<typename T>
void TestDecDigitCount<T, Unsigned, 4>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(4294967295) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
}

template<typename T>
void TestDecDigitCount<T, Signed, 8>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(9223372036854775807LL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999999999ULL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(-10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(-99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(-100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(-999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(-1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(-9223372036854775807LL - 1) == 19);
}

template<typename T>
void TestDecDigitCount<T, Unsigned, 8>::test()
{
	QVERIFY(Qpe::decimalDigitsCount<T>(0xffffffffffffffffULL) == 20);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000000000000ULL) == 20);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999999999ULL) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000000000) == 19);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999999999) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000000000) == 18);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999999999) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000000000) == 17);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999999) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000000) == 16);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999999) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000000) == 15);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999999) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000000) == 14);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999999) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000000) == 13);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999999) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000000) == 12);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999999) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000000) == 11);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999999) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000000) == 10);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999999) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000000) == 9);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999999) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000000) == 8);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999999) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000000) == 7);
	QVERIFY(Qpe::decimalDigitsCount<T>(999999) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(100000) == 6);
	QVERIFY(Qpe::decimalDigitsCount<T>(99999) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(10000) == 5);
	QVERIFY(Qpe::decimalDigitsCount<T>(9999) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(1000) == 4);
	QVERIFY(Qpe::decimalDigitsCount<T>(999) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(100) == 3);
	QVERIFY(Qpe::decimalDigitsCount<T>(99) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(10) == 2);
	QVERIFY(Qpe::decimalDigitsCount<T>(9) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(1) == 1);
	QVERIFY(Qpe::decimalDigitsCount<T>(0) == 1);
}

namespace _____hexadecimal_digits_count_tests_____ { }

template<typename T>
void TestHexDigitCount<T, Signed, 1>::test()
{
	QVERIFY(false);
}

template<typename T>
void TestHexDigitCount<T, Unsigned, 1>::test()
{
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0xff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x10) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x0f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x01) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<uchar>(0x00) == 1);
}

template<typename T>
void TestHexDigitCount<T, Signed, 2>::test()
{
	QVERIFY(false);
}

template<typename T>
void TestHexDigitCount<T, Unsigned, 2>::test()
{
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0xffff) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x1000) == 4);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0fff) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0100) == 3);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x00ff) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0010) == 2);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x000f) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0001) == 1);
	QVERIFY(Qpe::hexadecimalDigitsCount<ushort>(0x0000) == 1);
}

template<typename T>
void TestHexDigitCount<T, Signed, 4>::test()
{
	QVERIFY(false);
}

template<typename T>
void TestHexDigitCount<T, Unsigned, 4>::test()
{
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
}

template<typename T>
void TestHexDigitCount<T, Signed, 8>::test()
{
	QVERIFY(false);
}

template<typename T>
void TestHexDigitCount<T, Unsigned, 8>::test()
{
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

namespace _____decimal_tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(127)) == "127");

	QVERIFY(s::format(static_cast<T>(-1)) == "-1");
	QVERIFY(s::format(static_cast<T>(-9)) == "-9");
	QVERIFY(s::format(static_cast<T>(-10)) == "-10");
	QVERIFY(s::format(static_cast<T>(-99)) == "-99");
	QVERIFY(s::format(static_cast<T>(-100)) == "-100");
//	QVERIFY(s::format(static_cast<T>(-128)) == "-128");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");

	QVERIFY(s::format(static_cast<T>(-1)) == "255");
	QVERIFY(s::format(static_cast<T>(-9)) == "247");
	QVERIFY(s::format(static_cast<T>(-10)) == "246");
}

template<typename T>
void TesterDec<T, Signed, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(127)) == "127");

	QVERIFY(s::format(static_cast<T>(-1)) == "-001");
	QVERIFY(s::format(static_cast<T>(-9)) == "-009");
	QVERIFY(s::format(static_cast<T>(-10)) == "-010");
	QVERIFY(s::format(static_cast<T>(-99)) == "-099");
	QVERIFY(s::format(static_cast<T>(-100)) == "-100");
//	QVERIFY(s::format(static_cast<T>(-128)) == "-128");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");

	QVERIFY(s::format(static_cast<T>(-1)) == "255");
	QVERIFY(s::format(static_cast<T>(-9)) == "247");
	QVERIFY(s::format(static_cast<T>(-10)) == "246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(32767)) == "32767");

	QVERIFY(s::format(static_cast<T>(-1)) == "-1");
	QVERIFY(s::format(static_cast<T>(-9)) == "-9");
	QVERIFY(s::format(static_cast<T>(-10)) == "-10");
	QVERIFY(s::format(static_cast<T>(-99)) == "-99");
	QVERIFY(s::format(static_cast<T>(-100)) == "-100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-1000");
	QVERIFY(s::format(static_cast<T>(-32767)) == "-32767");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(65535)) == "65535");

	QVERIFY(s::format(static_cast<T>(-1)) == "65535");
	QVERIFY(s::format(static_cast<T>(-9)) == "65527");
	QVERIFY(s::format(static_cast<T>(-10)) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000");
	QVERIFY(s::format(static_cast<T>(9)) == "00009");
	QVERIFY(s::format(static_cast<T>(10)) == "00010");
	QVERIFY(s::format(static_cast<T>(99)) == "00099");
	QVERIFY(s::format(static_cast<T>(100)) == "00100");
	QVERIFY(s::format(static_cast<T>(255)) == "00255");
	QVERIFY(s::format(static_cast<T>(256)) == "00256");
	QVERIFY(s::format(static_cast<T>(1000)) == "01000");
	QVERIFY(s::format(static_cast<T>(32767)) == "32767");

	QVERIFY(s::format(static_cast<T>(-1)) == "-00001");
	QVERIFY(s::format(static_cast<T>(-9)) == "-00009");
	QVERIFY(s::format(static_cast<T>(-10)) == "-00010");
	QVERIFY(s::format(static_cast<T>(-99)) == "-00099");
	QVERIFY(s::format(static_cast<T>(-100)) == "-00100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-00255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-00256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-01000");
	QVERIFY(s::format(static_cast<T>(-32767)) == "-32767");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "00001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000");
	QVERIFY(s::format(static_cast<T>(9)) == "00009");
	QVERIFY(s::format(static_cast<T>(10)) == "00010");
	QVERIFY(s::format(static_cast<T>(99)) == "00099");
	QVERIFY(s::format(static_cast<T>(100)) == "00100");
	QVERIFY(s::format(static_cast<T>(255)) == "00255");
	QVERIFY(s::format(static_cast<T>(256)) == "00256");
	QVERIFY(s::format(static_cast<T>(1000)) == "01000");
	QVERIFY(s::format(static_cast<T>(65535)) == "65535");

	QVERIFY(s::format(static_cast<T>(-1)) == "65535");
	QVERIFY(s::format(static_cast<T>(-9)) == "65527");
	QVERIFY(s::format(static_cast<T>(-10)) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "2147483647");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "-1");

	QVERIFY(s::format(static_cast<T>(-1)) == "-1");
	QVERIFY(s::format(static_cast<T>(-9)) == "-9");
	QVERIFY(s::format(static_cast<T>(-10)) == "-10");
	QVERIFY(s::format(static_cast<T>(-99)) == "-99");
	QVERIFY(s::format(static_cast<T>(-100)) == "-100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-1000");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "-2147483647");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "4294967295");

	QVERIFY(s::format(static_cast<T>(-1)) == "4294967295");
	QVERIFY(s::format(static_cast<T>(-9)) == "4294967287");
	QVERIFY(s::format(static_cast<T>(-10)) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000010");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000099");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000100");
	QVERIFY(s::format(static_cast<T>(255)) == "0000000255");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000256");
	QVERIFY(s::format(static_cast<T>(1000)) == "0000001000");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "2147483647");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "-0000000001");

	QVERIFY(s::format(static_cast<T>(-1)) == "-0000000001");
	QVERIFY(s::format(static_cast<T>(-9)) == "-0000000009");
	QVERIFY(s::format(static_cast<T>(-10)) == "-0000000010");
	QVERIFY(s::format(static_cast<T>(-99)) == "-0000000099");
	QVERIFY(s::format(static_cast<T>(-100)) == "-0000000100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-0000000255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-0000000256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-0000001000");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "-2147483647");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000010");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000099");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000100");
	QVERIFY(s::format(static_cast<T>(255)) == "0000000255");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000256");
	QVERIFY(s::format(static_cast<T>(1000)) == "0000001000");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "4294967295");

	QVERIFY(s::format(static_cast<T>(-1)) == "4294967295");
	QVERIFY(s::format(static_cast<T>(-9)) == "4294967287");
	QVERIFY(s::format(static_cast<T>(-10)) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "9223372036854775807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "-1");

	QVERIFY(s::format(static_cast<T>(-1)) == "-1");
	QVERIFY(s::format(static_cast<T>(-9)) == "-9");
	QVERIFY(s::format(static_cast<T>(-10)) == "-10");
	QVERIFY(s::format(static_cast<T>(-99)) == "-99");
	QVERIFY(s::format(static_cast<T>(-100)) == "-100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-1000");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "-9223372036854775807");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "18446744073709551615");

	QVERIFY(s::format(static_cast<T>(-1)) == "18446744073709551615");
	QVERIFY(s::format(static_cast<T>(-9)) == "18446744073709551607");
	QVERIFY(s::format(static_cast<T>(-10)) == "18446744073709551606");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000000000000010");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000000000000099");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000000000000100");
	QVERIFY(s::format(static_cast<T>(255)) == "0000000000000000255");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000000000000256");
	QVERIFY(s::format(static_cast<T>(1000)) == "0000000000000001000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "9223372036854775807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "-0000000000000000001");

	QVERIFY(s::format(static_cast<T>(-1)) == "-0000000000000000001");
	QVERIFY(s::format(static_cast<T>(-9)) == "-0000000000000000009");
	QVERIFY(s::format(static_cast<T>(-10)) == "-0000000000000000010");
	QVERIFY(s::format(static_cast<T>(-99)) == "-0000000000000000099");
	QVERIFY(s::format(static_cast<T>(-100)) == "-0000000000000000100");
	QVERIFY(s::format(static_cast<T>(-255)) == "-0000000000000000255");
	QVERIFY(s::format(static_cast<T>(-256)) == "-0000000000000000256");
	QVERIFY(s::format(static_cast<T>(-1000)) == "-0000000000000001000");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "-9223372036854775807");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0000000000000000001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "00000000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "00000000000000000010");
	QVERIFY(s::format(static_cast<T>(99)) == "00000000000000000099");
	QVERIFY(s::format(static_cast<T>(100)) == "00000000000000000100");
	QVERIFY(s::format(static_cast<T>(255)) == "00000000000000000255");
	QVERIFY(s::format(static_cast<T>(256)) == "00000000000000000256");
	QVERIFY(s::format(static_cast<T>(1000)) == "00000000000000001000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "18446744073709551615");

	QVERIFY(s::format(static_cast<T>(-1)) == "18446744073709551615");
	QVERIFY(s::format(static_cast<T>(-9)) == "18446744073709551607");
	QVERIFY(s::format(static_cast<T>(-10)) == "18446744073709551606");
}

namespace _____decimal__2digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(127)) == "27");

	QVERIFY(s::format(static_cast<T>(-1)) == "55");
	QVERIFY(s::format(static_cast<T>(-9)) == "47");
	QVERIFY(s::format(static_cast<T>(-10)) == "46");
	QVERIFY(s::format(static_cast<T>(-99)) == "57");
	QVERIFY(s::format(static_cast<T>(-100)) == "56");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");

	QVERIFY(s::format(static_cast<T>(-1)) == "55");
	QVERIFY(s::format(static_cast<T>(-9)) == "47");
	QVERIFY(s::format(static_cast<T>(-10)) == "46");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(32767)) == "67");

	QVERIFY(s::format(static_cast<T>(-1)) == "35");
	QVERIFY(s::format(static_cast<T>(-9)) == "27");
	QVERIFY(s::format(static_cast<T>(-10)) == "26");
	QVERIFY(s::format(static_cast<T>(-99)) == "37");
	QVERIFY(s::format(static_cast<T>(-100)) == "36");
	QVERIFY(s::format(static_cast<T>(-255)) == "81");
	QVERIFY(s::format(static_cast<T>(-256)) == "80");
	QVERIFY(s::format(static_cast<T>(-1000)) == "36");
	QVERIFY(s::format(static_cast<T>(-32767)) == "69");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(65535)) == "35");

	QVERIFY(s::format(static_cast<T>(-1)) == "35");
	QVERIFY(s::format(static_cast<T>(-9)) == "27");
	QVERIFY(s::format(static_cast<T>(-10)) == "26");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "47");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "95");

	QVERIFY(s::format(static_cast<T>(-1)) == "95");
	QVERIFY(s::format(static_cast<T>(-9)) == "87");
	QVERIFY(s::format(static_cast<T>(-10)) == "86");
	QVERIFY(s::format(static_cast<T>(-99)) == "97");
	QVERIFY(s::format(static_cast<T>(-100)) == "96");
	QVERIFY(s::format(static_cast<T>(-255)) == "41");
	QVERIFY(s::format(static_cast<T>(-256)) == "40");
	QVERIFY(s::format(static_cast<T>(-1000)) == "96");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "49");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "95");

	QVERIFY(s::format(static_cast<T>(-1)) == "95");
	QVERIFY(s::format(static_cast<T>(-9)) == "87");
	QVERIFY(s::format(static_cast<T>(-10)) == "86");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "07");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "15");

	QVERIFY(s::format(static_cast<T>(-1)) == "15");
	QVERIFY(s::format(static_cast<T>(-9)) == "07");
	QVERIFY(s::format(static_cast<T>(-10)) == "06");
	QVERIFY(s::format(static_cast<T>(-99)) == "17");
	QVERIFY(s::format(static_cast<T>(-100)) == "16");
	QVERIFY(s::format(static_cast<T>(-255)) == "61");
	QVERIFY(s::format(static_cast<T>(-256)) == "60");
	QVERIFY(s::format(static_cast<T>(-1000)) == "16");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "09");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "10");
	QVERIFY(s::format(static_cast<T>(99)) == "99");
	QVERIFY(s::format(static_cast<T>(100)) == "00");
	QVERIFY(s::format(static_cast<T>(255)) == "55");
	QVERIFY(s::format(static_cast<T>(256)) == "56");
	QVERIFY(s::format(static_cast<T>(1000)) == "00");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "15");

	QVERIFY(s::format(static_cast<T>(-1)) == "15");
	QVERIFY(s::format(static_cast<T>(-9)) == "07");
	QVERIFY(s::format(static_cast<T>(-10)) == "06");
}

namespace _____decimal__3digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(127)) == "127");

	QVERIFY(s::format(static_cast<T>(-1)) == "255");
	QVERIFY(s::format(static_cast<T>(-9)) == "247");
	QVERIFY(s::format(static_cast<T>(-10)) == "246");
	QVERIFY(s::format(static_cast<T>(-99)) == "157");
	QVERIFY(s::format(static_cast<T>(-100)) == "156");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");

	QVERIFY(s::format(static_cast<T>(-1)) == "255");
	QVERIFY(s::format(static_cast<T>(-9)) == "247");
	QVERIFY(s::format(static_cast<T>(-10)) == "246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(32767)) == "767");

	QVERIFY(s::format(static_cast<T>(-1)) == "535");
	QVERIFY(s::format(static_cast<T>(-9)) == "527");
	QVERIFY(s::format(static_cast<T>(-10)) == "526");
	QVERIFY(s::format(static_cast<T>(-99)) == "437");
	QVERIFY(s::format(static_cast<T>(-100)) == "436");
	QVERIFY(s::format(static_cast<T>(-255)) == "281");
	QVERIFY(s::format(static_cast<T>(-256)) == "280");
	QVERIFY(s::format(static_cast<T>(-1000)) == "536");
	QVERIFY(s::format(static_cast<T>(-32767)) == "769");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(65535)) == "535");

	QVERIFY(s::format(static_cast<T>(-1)) == "535");
	QVERIFY(s::format(static_cast<T>(-9)) == "527");
	QVERIFY(s::format(static_cast<T>(-10)) == "526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "647");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "295");

	QVERIFY(s::format(static_cast<T>(-1)) == "295");
	QVERIFY(s::format(static_cast<T>(-9)) == "287");
	QVERIFY(s::format(static_cast<T>(-10)) == "286");
	QVERIFY(s::format(static_cast<T>(-99)) == "197");
	QVERIFY(s::format(static_cast<T>(-100)) == "196");
	QVERIFY(s::format(static_cast<T>(-255)) == "041");
	QVERIFY(s::format(static_cast<T>(-256)) == "040");
	QVERIFY(s::format(static_cast<T>(-1000)) == "296");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "649");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "295");

	QVERIFY(s::format(static_cast<T>(-1)) == "295");
	QVERIFY(s::format(static_cast<T>(-9)) == "287");
	QVERIFY(s::format(static_cast<T>(-10)) == "286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "615");

	QVERIFY(s::format(static_cast<T>(-1)) == "615");
	QVERIFY(s::format(static_cast<T>(-9)) == "607");
	QVERIFY(s::format(static_cast<T>(-10)) == "606");
	QVERIFY(s::format(static_cast<T>(-99)) == "517");
	QVERIFY(s::format(static_cast<T>(-100)) == "516");
	QVERIFY(s::format(static_cast<T>(-255)) == "361");
	QVERIFY(s::format(static_cast<T>(-256)) == "360");
	QVERIFY(s::format(static_cast<T>(-1000)) == "616");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "809");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "000");
	QVERIFY(s::format(static_cast<T>(9)) == "009");
	QVERIFY(s::format(static_cast<T>(10)) == "010");
	QVERIFY(s::format(static_cast<T>(99)) == "099");
	QVERIFY(s::format(static_cast<T>(100)) == "100");
	QVERIFY(s::format(static_cast<T>(255)) == "255");
	QVERIFY(s::format(static_cast<T>(256)) == "256");
	QVERIFY(s::format(static_cast<T>(1000)) == "000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "615");

	QVERIFY(s::format(static_cast<T>(-1)) == "615");
	QVERIFY(s::format(static_cast<T>(-9)) == "607");
	QVERIFY(s::format(static_cast<T>(-10)) == "606");
}

namespace _____decimal__4digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(127)) == "0127");

	QVERIFY(s::format(static_cast<T>(-1)) == "0255");
	QVERIFY(s::format(static_cast<T>(-9)) == "0247");
	QVERIFY(s::format(static_cast<T>(-10)) == "0246");
	QVERIFY(s::format(static_cast<T>(-99)) == "0157");
	QVERIFY(s::format(static_cast<T>(-100)) == "0156");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");

	QVERIFY(s::format(static_cast<T>(-1)) == "0255");
	QVERIFY(s::format(static_cast<T>(-9)) == "0247");
	QVERIFY(s::format(static_cast<T>(-10)) == "0246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(32767)) == "2767");

	QVERIFY(s::format(static_cast<T>(-1)) == "5535");
	QVERIFY(s::format(static_cast<T>(-9)) == "5527");
	QVERIFY(s::format(static_cast<T>(-10)) == "5526");
	QVERIFY(s::format(static_cast<T>(-99)) == "5437");
	QVERIFY(s::format(static_cast<T>(-100)) == "5436");
	QVERIFY(s::format(static_cast<T>(-255)) == "5281");
	QVERIFY(s::format(static_cast<T>(-256)) == "5280");
	QVERIFY(s::format(static_cast<T>(-1000)) == "4536");
	QVERIFY(s::format(static_cast<T>(-32767)) == "2769");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(65535)) == "5535");

	QVERIFY(s::format(static_cast<T>(-1)) == "5535");
	QVERIFY(s::format(static_cast<T>(-9)) == "5527");
	QVERIFY(s::format(static_cast<T>(-10)) == "5526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "3647");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "7295");

	QVERIFY(s::format(static_cast<T>(-1)) == "7295");
	QVERIFY(s::format(static_cast<T>(-9)) == "7287");
	QVERIFY(s::format(static_cast<T>(-10)) == "7286");
	QVERIFY(s::format(static_cast<T>(-99)) == "7197");
	QVERIFY(s::format(static_cast<T>(-100)) == "7196");
	QVERIFY(s::format(static_cast<T>(-255)) == "7041");
	QVERIFY(s::format(static_cast<T>(-256)) == "7040");
	QVERIFY(s::format(static_cast<T>(-1000)) == "6296");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "3649");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "7295");

	QVERIFY(s::format(static_cast<T>(-1)) == "7295");
	QVERIFY(s::format(static_cast<T>(-9)) == "7287");
	QVERIFY(s::format(static_cast<T>(-10)) == "7286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "5807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "1615");

	QVERIFY(s::format(static_cast<T>(-1)) == "1615");
	QVERIFY(s::format(static_cast<T>(-9)) == "1607");
	QVERIFY(s::format(static_cast<T>(-10)) == "1606");
	QVERIFY(s::format(static_cast<T>(-99)) == "1517");
	QVERIFY(s::format(static_cast<T>(-100)) == "1516");
	QVERIFY(s::format(static_cast<T>(-255)) == "1361");
	QVERIFY(s::format(static_cast<T>(-256)) == "1360");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0616");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "5809");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0010");
	QVERIFY(s::format(static_cast<T>(99)) == "0099");
	QVERIFY(s::format(static_cast<T>(100)) == "0100");
	QVERIFY(s::format(static_cast<T>(255)) == "0255");
	QVERIFY(s::format(static_cast<T>(256)) == "0256");
	QVERIFY(s::format(static_cast<T>(1000)) == "1000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "1615");

	QVERIFY(s::format(static_cast<T>(-1)) == "1615");
	QVERIFY(s::format(static_cast<T>(-9)) == "1607");
	QVERIFY(s::format(static_cast<T>(-10)) == "1606");
}

namespace _____hexadecimal_tester_____ { }
namespace _____hex_1_____ { }

template<typename T>
void TesterHex<T, Signed, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(127)) == "7f");

	QVERIFY(s::format(static_cast<T>(-1)) == "ff");
	QVERIFY(s::format(static_cast<T>(-9)) == "f7");
	QVERIFY(s::format(static_cast<T>(-10)) == "f6");
	QVERIFY(s::format(static_cast<T>(-99)) == "9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ff");
	QVERIFY(s::format(static_cast<T>(-9)) == "f7");
	QVERIFY(s::format(static_cast<T>(-10)) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(127)) == "7F");

	QVERIFY(s::format(static_cast<T>(-1)) == "FF");
	QVERIFY(s::format(static_cast<T>(-9)) == "F7");
	QVERIFY(s::format(static_cast<T>(-10)) == "F6");
	QVERIFY(s::format(static_cast<T>(-99)) == "9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FF");
	QVERIFY(s::format(static_cast<T>(-9)) == "F7");
	QVERIFY(s::format(static_cast<T>(-10)) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "0a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(127)) == "7f");

	QVERIFY(s::format(static_cast<T>(-1)) == "ff");
	QVERIFY(s::format(static_cast<T>(-9)) == "f7");
	QVERIFY(s::format(static_cast<T>(-10)) == "f6");
	QVERIFY(s::format(static_cast<T>(-99)) == "9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "0a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ff");
	QVERIFY(s::format(static_cast<T>(-9)) == "f7");
	QVERIFY(s::format(static_cast<T>(-10)) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "0A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(127)) == "7F");

	QVERIFY(s::format(static_cast<T>(-1)) == "FF");
	QVERIFY(s::format(static_cast<T>(-9)) == "F7");
	QVERIFY(s::format(static_cast<T>(-10)) == "F6");
	QVERIFY(s::format(static_cast<T>(-99)) == "9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00");
	QVERIFY(s::format(static_cast<T>(9)) == "09");
	QVERIFY(s::format(static_cast<T>(10)) == "0A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FF");
	QVERIFY(s::format(static_cast<T>(-9)) == "F7");
	QVERIFY(s::format(static_cast<T>(-10)) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(127)) == "0x7f");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xf6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0x9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0x9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(127)) == "0x7F");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0x9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0x9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xF6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00");
	QVERIFY(s::format(static_cast<T>(9)) == "0x09");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(127)) == "0x7f");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xf6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0x9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0x9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "0x01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00");
	QVERIFY(s::format(static_cast<T>(9)) == "0x09");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00");
	QVERIFY(s::format(static_cast<T>(9)) == "0x09");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(127)) == "0x7F");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0x9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0x9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff)) == "0x01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00");
	QVERIFY(s::format(static_cast<T>(9)) == "0x09");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xF6");
}

namespace _____hex_2_____ { }

template<typename T>
void TesterHex<T, Signed, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(32767)) == "7fff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fc18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(65535)) == "ffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(32767)) == "7FFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FC18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(65535)) == "FFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0064");
	QVERIFY(s::format(static_cast<T>(255)) == "00ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "03e8");
	QVERIFY(s::format(static_cast<T>(32767)) == "7fff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fc18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0064");
	QVERIFY(s::format(static_cast<T>(255)) == "00ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "03e8");
	QVERIFY(s::format(static_cast<T>(65535)) == "ffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0064");
	QVERIFY(s::format(static_cast<T>(255)) == "00FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "03E8");
	QVERIFY(s::format(static_cast<T>(32767)) == "7FFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FC18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0009");
	QVERIFY(s::format(static_cast<T>(10)) == "000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0064");
	QVERIFY(s::format(static_cast<T>(255)) == "00FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "03E8");
	QVERIFY(s::format(static_cast<T>(65535)) == "FFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(32767)) == "0x7fff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfc18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(65535)) == "0xffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(32767)) == "0x7FFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFC18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(65535)) == "0xFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x03e8");
	QVERIFY(s::format(static_cast<T>(32767)) == "0x7fff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfc18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0x0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x03e8");
	QVERIFY(s::format(static_cast<T>(65535)) == "0xffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x03E8");
	QVERIFY(s::format(static_cast<T>(32767)) == "0x7FFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFC18");
	QVERIFY(s::format(static_cast<T>(-32767)) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff)) == "0x0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x03E8");
	QVERIFY(s::format(static_cast<T>(65535)) == "0xFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFF6");
}

namespace _____hex_4_____ { }

template<typename T>
void TesterHex<T, Signed, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;

	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "000003e8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "000003e8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "000003E8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "000003E8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "0x7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "0x7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x000003e8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "0x7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x000003e8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x000003E8");
	QVERIFY(s::format(static_cast<T>(2147483647)) == "0x7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647)) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL)) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x0000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x000003E8");
	QVERIFY(s::format(static_cast<T>(4294967295)) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFF6");
}

namespace _____hex_8_____ { }

template<typename T>
void TesterHex<T, Signed, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "a");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "ff");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0");
	QVERIFY(s::format(static_cast<T>(9)) == "9");
	QVERIFY(s::format(static_cast<T>(10)) == "A");
	QVERIFY(s::format(static_cast<T>(99)) == "63");
	QVERIFY(s::format(static_cast<T>(100)) == "64");
	QVERIFY(s::format(static_cast<T>(255)) == "FF");
	QVERIFY(s::format(static_cast<T>(256)) == "100");
	QVERIFY(s::format(static_cast<T>(1000)) == "3E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "000000000000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "00000000000003e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "ffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "ffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "ffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "ffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "fffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "000000000000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "00000000000003e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "000000000000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "00000000000003E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "000000000000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "00000000000003E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "0x7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xa");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0");
	QVERIFY(s::format(static_cast<T>(9)) == "0x9");
	QVERIFY(s::format(static_cast<T>(10)) == "0xA");
	QVERIFY(s::format(static_cast<T>(99)) == "0x63");
	QVERIFY(s::format(static_cast<T>(100)) == "0x64");
	QVERIFY(s::format(static_cast<T>(255)) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000000000000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x00000000000003e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "0x7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xfffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000000000000000a");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x00000000000003e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000000000000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x00000000000003E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807)) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99)) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100)) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255)) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256)) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000)) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807)) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL)) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QVERIFY(s::format(static_cast<T>(0)) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9)) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10)) == "0x000000000000000A");
	QVERIFY(s::format(static_cast<T>(99)) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100)) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255)) == "0x00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256)) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000)) == "0x00000000000003E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL)) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1)) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9)) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10)) == "0xFFFFFFFFFFFFFFF6");
}


QTEST_MAIN(TestNumberStringifier2ByteArray)
#include "test_numberstringifier2bytearray.moc"

#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

struct Signed { };
struct Unsigned { };

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

class TestNumberStringifier2String : public QObject
{
	Q_OBJECT
private slots:
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

void TestNumberStringifier2String::testStaticFormatDecShort()
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

void TestNumberStringifier2String::testStaticFormatDecInt()
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

void TestNumberStringifier2String::testStaticFormatDecLong()
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

void TestNumberStringifier2String::testStaticFormatDecInt64()
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

void TestNumberStringifier2String::testStaticFormatHexChar()
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

void TestNumberStringifier2String::testStaticFormatHexShort()
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

void TestNumberStringifier2String::testStaticFormatHexInt()
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

void TestNumberStringifier2String::testStaticFormatHexLong()
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

void TestNumberStringifier2String::testStaticFormatHexInt64()
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

namespace _____decimal_tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(127), result) == "127");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-100");
//	QVERIFY(s::format(static_cast<T>(-128), result) == "-128");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");

	QVERIFY(s::format(static_cast<T>(-1), result) == "255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "246");
}

template<typename T>
void TesterDec<T, Signed, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(127), result) == "127");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-001");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-009");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-010");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-099");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-100");
//	QVERIFY(s::format(static_cast<T>(-128), result) == "-128");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");

	QVERIFY(s::format(static_cast<T>(-1), result) == "255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(32767), result) == "32767");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "-32767");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(65535), result) == "65535");

	QVERIFY(s::format(static_cast<T>(-1), result) == "65535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "65527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00009");
	QVERIFY(s::format(static_cast<T>(10), result) == "00010");
	QVERIFY(s::format(static_cast<T>(99), result) == "00099");
	QVERIFY(s::format(static_cast<T>(100), result) == "00100");
	QVERIFY(s::format(static_cast<T>(255), result) == "00255");
	QVERIFY(s::format(static_cast<T>(256), result) == "00256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "01000");
	QVERIFY(s::format(static_cast<T>(32767), result) == "32767");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-00001");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-00009");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-00010");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-00099");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-00100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-00255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-00256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-01000");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "-32767");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "00001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00009");
	QVERIFY(s::format(static_cast<T>(10), result) == "00010");
	QVERIFY(s::format(static_cast<T>(99), result) == "00099");
	QVERIFY(s::format(static_cast<T>(100), result) == "00100");
	QVERIFY(s::format(static_cast<T>(255), result) == "00255");
	QVERIFY(s::format(static_cast<T>(256), result) == "00256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "01000");
	QVERIFY(s::format(static_cast<T>(65535), result) == "65535");

	QVERIFY(s::format(static_cast<T>(-1), result) == "65535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "65527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "2147483647");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "-1");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "-2147483647");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "4294967295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "4294967295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "4294967287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0000000255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0000001000");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "2147483647");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "-0000000001");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-0000000001");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-0000000009");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-0000000010");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-0000000099");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-0000000100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-0000000255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-0000000256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-0000001000");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "-2147483647");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0000000255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0000001000");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "4294967295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "4294967295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "4294967287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "-1");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "18446744073709551615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "18446744073709551607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "18446744073709551606");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000000000000010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000000000000099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000000000000100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0000000000000000255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000000000000256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0000000000000001000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "-0000000000000000001");

	QVERIFY(s::format(static_cast<T>(-1), result) == "-0000000000000000001");
	QVERIFY(s::format(static_cast<T>(-9), result) == "-0000000000000000009");
	QVERIFY(s::format(static_cast<T>(-10), result) == "-0000000000000000010");
	QVERIFY(s::format(static_cast<T>(-99), result) == "-0000000000000000099");
	QVERIFY(s::format(static_cast<T>(-100), result) == "-0000000000000000100");
	QVERIFY(s::format(static_cast<T>(-255), result) == "-0000000000000000255");
	QVERIFY(s::format(static_cast<T>(-256), result) == "-0000000000000000256");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "-0000000000000001000");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000000001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00000000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "00000000000000000010");
	QVERIFY(s::format(static_cast<T>(99), result) == "00000000000000000099");
	QVERIFY(s::format(static_cast<T>(100), result) == "00000000000000000100");
	QVERIFY(s::format(static_cast<T>(255), result) == "00000000000000000255");
	QVERIFY(s::format(static_cast<T>(256), result) == "00000000000000000256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00000000000000001000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "18446744073709551615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "18446744073709551607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "18446744073709551606");
}

namespace _____decimal__2digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(127), result) == "27");

	QVERIFY(s::format(static_cast<T>(-1), result) == "55");
	QVERIFY(s::format(static_cast<T>(-9), result) == "47");
	QVERIFY(s::format(static_cast<T>(-10), result) == "46");
	QVERIFY(s::format(static_cast<T>(-99), result) == "57");
	QVERIFY(s::format(static_cast<T>(-100), result) == "56");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");

	QVERIFY(s::format(static_cast<T>(-1), result) == "55");
	QVERIFY(s::format(static_cast<T>(-9), result) == "47");
	QVERIFY(s::format(static_cast<T>(-10), result) == "46");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(32767), result) == "67");

	QVERIFY(s::format(static_cast<T>(-1), result) == "35");
	QVERIFY(s::format(static_cast<T>(-9), result) == "27");
	QVERIFY(s::format(static_cast<T>(-10), result) == "26");
	QVERIFY(s::format(static_cast<T>(-99), result) == "37");
	QVERIFY(s::format(static_cast<T>(-100), result) == "36");
	QVERIFY(s::format(static_cast<T>(-255), result) == "81");
	QVERIFY(s::format(static_cast<T>(-256), result) == "80");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "36");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "69");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(65535), result) == "35");

	QVERIFY(s::format(static_cast<T>(-1), result) == "35");
	QVERIFY(s::format(static_cast<T>(-9), result) == "27");
	QVERIFY(s::format(static_cast<T>(-10), result) == "26");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "47");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "95");

	QVERIFY(s::format(static_cast<T>(-1), result) == "95");
	QVERIFY(s::format(static_cast<T>(-9), result) == "87");
	QVERIFY(s::format(static_cast<T>(-10), result) == "86");
	QVERIFY(s::format(static_cast<T>(-99), result) == "97");
	QVERIFY(s::format(static_cast<T>(-100), result) == "96");
	QVERIFY(s::format(static_cast<T>(-255), result) == "41");
	QVERIFY(s::format(static_cast<T>(-256), result) == "40");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "96");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "49");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "95");

	QVERIFY(s::format(static_cast<T>(-1), result) == "95");
	QVERIFY(s::format(static_cast<T>(-9), result) == "87");
	QVERIFY(s::format(static_cast<T>(-10), result) == "86");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "07");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "15");

	QVERIFY(s::format(static_cast<T>(-1), result) == "15");
	QVERIFY(s::format(static_cast<T>(-9), result) == "07");
	QVERIFY(s::format(static_cast<T>(-10), result) == "06");
	QVERIFY(s::format(static_cast<T>(-99), result) == "17");
	QVERIFY(s::format(static_cast<T>(-100), result) == "16");
	QVERIFY(s::format(static_cast<T>(-255), result) == "61");
	QVERIFY(s::format(static_cast<T>(-256), result) == "60");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "16");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "09");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "01");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_2d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase2Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "10");
	QVERIFY(s::format(static_cast<T>(99), result) == "99");
	QVERIFY(s::format(static_cast<T>(100), result) == "00");
	QVERIFY(s::format(static_cast<T>(255), result) == "55");
	QVERIFY(s::format(static_cast<T>(256), result) == "56");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "15");

	QVERIFY(s::format(static_cast<T>(-1), result) == "15");
	QVERIFY(s::format(static_cast<T>(-9), result) == "07");
	QVERIFY(s::format(static_cast<T>(-10), result) == "06");
}

namespace _____decimal__3digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(127), result) == "127");

	QVERIFY(s::format(static_cast<T>(-1), result) == "255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "246");
	QVERIFY(s::format(static_cast<T>(-99), result) == "157");
	QVERIFY(s::format(static_cast<T>(-100), result) == "156");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");

	QVERIFY(s::format(static_cast<T>(-1), result) == "255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(32767), result) == "767");

	QVERIFY(s::format(static_cast<T>(-1), result) == "535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "526");
	QVERIFY(s::format(static_cast<T>(-99), result) == "437");
	QVERIFY(s::format(static_cast<T>(-100), result) == "436");
	QVERIFY(s::format(static_cast<T>(-255), result) == "281");
	QVERIFY(s::format(static_cast<T>(-256), result) == "280");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "536");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "769");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(65535), result) == "535");

	QVERIFY(s::format(static_cast<T>(-1), result) == "535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "647");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "286");
	QVERIFY(s::format(static_cast<T>(-99), result) == "197");
	QVERIFY(s::format(static_cast<T>(-100), result) == "196");
	QVERIFY(s::format(static_cast<T>(-255), result) == "041");
	QVERIFY(s::format(static_cast<T>(-256), result) == "040");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "296");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "649");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "606");
	QVERIFY(s::format(static_cast<T>(-99), result) == "517");
	QVERIFY(s::format(static_cast<T>(-100), result) == "516");
	QVERIFY(s::format(static_cast<T>(-255), result) == "361");
	QVERIFY(s::format(static_cast<T>(-256), result) == "360");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "616");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "809");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_3d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase3Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "000");
	QVERIFY(s::format(static_cast<T>(9), result) == "009");
	QVERIFY(s::format(static_cast<T>(10), result) == "010");
	QVERIFY(s::format(static_cast<T>(99), result) == "099");
	QVERIFY(s::format(static_cast<T>(100), result) == "100");
	QVERIFY(s::format(static_cast<T>(255), result) == "255");
	QVERIFY(s::format(static_cast<T>(256), result) == "256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "606");
}

namespace _____decimal__4digits__tester_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(127), result) == "0127");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0246");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0157");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0156");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0255");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0247");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(32767), result) == "2767");

	QVERIFY(s::format(static_cast<T>(-1), result) == "5535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "5527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "5526");
	QVERIFY(s::format(static_cast<T>(-99), result) == "5437");
	QVERIFY(s::format(static_cast<T>(-100), result) == "5436");
	QVERIFY(s::format(static_cast<T>(-255), result) == "5281");
	QVERIFY(s::format(static_cast<T>(-256), result) == "5280");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "4536");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "2769");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(65535), result) == "5535");

	QVERIFY(s::format(static_cast<T>(-1), result) == "5535");
	QVERIFY(s::format(static_cast<T>(-9), result) == "5527");
	QVERIFY(s::format(static_cast<T>(-10), result) == "5526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "3647");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "7295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "7295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "7287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "7286");
	QVERIFY(s::format(static_cast<T>(-99), result) == "7197");
	QVERIFY(s::format(static_cast<T>(-100), result) == "7196");
	QVERIFY(s::format(static_cast<T>(-255), result) == "7041");
	QVERIFY(s::format(static_cast<T>(-256), result) == "7040");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "6296");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "3649");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "7295");

	QVERIFY(s::format(static_cast<T>(-1), result) == "7295");
	QVERIFY(s::format(static_cast<T>(-9), result) == "7287");
	QVERIFY(s::format(static_cast<T>(-10), result) == "7286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "5807");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "1615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "1615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "1607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "1606");
	QVERIFY(s::format(static_cast<T>(-99), result) == "1517");
	QVERIFY(s::format(static_cast<T>(-100), result) == "1516");
	QVERIFY(s::format(static_cast<T>(-255), result) == "1361");
	QVERIFY(s::format(static_cast<T>(-256), result) == "1360");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0616");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "5809");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_4d()
{
	typedef Qpe::Static::Stringifier<Qpe::DecBase4Digits> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0010");
	QVERIFY(s::format(static_cast<T>(99), result) == "0099");
	QVERIFY(s::format(static_cast<T>(100), result) == "0100");
	QVERIFY(s::format(static_cast<T>(255), result) == "0255");
	QVERIFY(s::format(static_cast<T>(256), result) == "0256");
	QVERIFY(s::format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "1615");

	QVERIFY(s::format(static_cast<T>(-1), result) == "1615");
	QVERIFY(s::format(static_cast<T>(-9), result) == "1607");
	QVERIFY(s::format(static_cast<T>(-10), result) == "1606");
}

namespace _____hexadecimal_tester_____ { }
namespace _____hex_1_____ { }

template<typename T>
void TesterHex<T, Signed, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(127), result) == "7f");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "f6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(127), result) == "7F");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "F6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(127), result) == "7f");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "f6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(127), result) == "7F");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "F6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00");
	QVERIFY(s::format(static_cast<T>(9), result) == "09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(127), result) == "0x7f");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xf6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0x9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0x9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(127), result) == "0x7F");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0x9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0x9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xF6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(127), result) == "0x7f");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xf6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0x9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0x9c");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "0x01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(127), result) == "0x7F");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0x9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0x9C");
	QVERIFY(s::format(static_cast<T>(-255 & 0xff), result) == "0x01");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xF6");
}

namespace _____hex_2_____ { }

template<typename T>
void TesterHex<T, Signed, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "7fff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fc18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "ffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "7FFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FC18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "FFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "03e8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "7fff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fc18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "03e8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "ffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "03E8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "7FFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FC18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "03E8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "FFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "0x7fff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfc18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "0xffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "0x7FFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFC18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "0xFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x03e8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "0x7fff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfc18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0x0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x03e8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "0xffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x03E8");
	QVERIFY(s::format(static_cast<T>(32767), result) == "0x7FFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFC18");
	QVERIFY(s::format(static_cast<T>(-32767), result) == "0x8001");
	QVERIFY(s::format(static_cast<T>(-65535 & 0xffff), result) == "0x0001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x03E8");
	QVERIFY(s::format(static_cast<T>(65535), result) == "0xFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFF6");
}

namespace _____hex_4_____ { }

template<typename T>
void TesterHex<T, Signed, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;

	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000003e8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000003e8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000003E8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "000003E8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "0x7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x000003e8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "0x7fffffff");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfffffc18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x000003e8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x000003E8");
	QVERIFY(s::format(static_cast<T>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s::format(static_cast<T>(0-4294967295UL), result) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x0000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x000003E8");
	QVERIFY(s::format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFF6");
}

namespace _____hex_8_____ { }

template<typename T>
void TesterHex<T, Signed, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "a");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithoutPrefix,Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0");
	QVERIFY(s::format(static_cast<T>(9), result) == "9");
	QVERIFY(s::format(static_cast<T>(10), result) == "A");
	QVERIFY(s::format(static_cast<T>(99), result) == "63");
	QVERIFY(s::format(static_cast<T>(100), result) == "64");
	QVERIFY(s::format(static_cast<T>(255), result) == "FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000000000000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00000000000003e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "ffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "ffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz()
{
	typedef Qpe::Static::Stringifier<Qpe::HexBase, Qpe::WithLeadingZero> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000000000000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00000000000003e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000000000000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00000000000003E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithoutPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "000000000000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "00000000000003E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithoutLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s::format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s::format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000000000000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x00000000000003e8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000000000000000a");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00000000000000ff");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x00000000000003e8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000000000000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x00000000000003E8");
	QVERIFY(s::format(static_cast<T>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s::format(static_cast<T>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s::format(static_cast<T>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s::format(static_cast<T>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s::format(static_cast<T>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s::format(static_cast<T>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s::format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s::format(static_cast<T>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz_up()
{
	typedef Qpe::Static::Stringifier<
		Qpe::HexBase, Qpe::WithLeadingZero,
		Qpe::WithPrefix, Qpe::UpperCase> s;
	QString result;
	QVERIFY(s::format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s::format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s::format(static_cast<T>(10), result) == "0x000000000000000A");
	QVERIFY(s::format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s::format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s::format(static_cast<T>(255), result) == "0x00000000000000FF");
	QVERIFY(s::format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s::format(static_cast<T>(1000), result) == "0x00000000000003E8");
	QVERIFY(s::format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s::format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s::format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s::format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
}

QTEST_MAIN(TestNumberStringifier2String)
#include "test_numberstringifier2string.moc"

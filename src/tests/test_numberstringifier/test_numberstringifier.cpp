#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/Stringifier>
#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

struct Signed { };
struct Unsigned { };

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
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Unsigned, 1>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Signed, 2>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Unsigned, 2>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Signed, 4>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Unsigned, 4>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Signed, 8>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterDec<T, Unsigned, 8>
{
	static void test(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
};

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
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Unsigned, 1>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Signed, 2>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Unsigned, 2>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Signed, 4>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Unsigned, 4>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Signed, 8>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};

template <typename T>
struct TesterHex<T, Unsigned, 8>
{
	static void test(const Qpe::Stringifier& s);
	static void test_up(const Qpe::Stringifier& s);
	static void test_lz(const Qpe::Stringifier& s);
	static void test_lz_up(const Qpe::Stringifier& s);

	static void test_p(const Qpe::Stringifier& s);
	static void test_p_up(const Qpe::Stringifier& s);
	static void test_p_lz(const Qpe::Stringifier& s);
	static void test_p_lz_up(const Qpe::Stringifier& s);
};


class TestNumberStringifier : public QObject
{
	Q_OBJECT
private slots:
	void test();

	void benchIntStringifierValue();
	void benchIntStaticStringifierValue();
	void benchIntStaticStringifierRef();
	void benchIntDataByteStatic();
	void benchIntDataByteMember();
	void benchIntStdString();

	void testFormatDecChar();
	void testFormatDecShort();
	void testFormatDecInt();
	void testFormatDecLong();
	void testFormatDecInt64();

	void testFormatHexChar();
	void testFormatHexShort();
	void testFormatHexInt();
	void testFormatHexLong();
	void testFormatHexInt64();

	void testFormatDecChar_str();
	void testFormatDecShort_str();
	void testFormatDecInt_str();
	void testFormatDecLong_str();
	void testFormatDecInt64_str();

	void testFormatHexChar_str();
	void testFormatHexShort_str();
	void testFormatHexInt_str();
	void testFormatHexLong_str();
	void testFormatHexInt64_str();
};

void TestNumberStringifier::test()
{
}

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
typedef Qpe::Stringifier SS;
void TestNumberStringifier::testFormatDecChar()
{
	TesterDec<signed char>::test(SS(10));
	TesterDec<signed char>::test_lz(SS(10, true));
	TesterDec<char>::test(SS(10));
	TesterDec<char>::test_lz(SS(10, true));
	TesterDec<uchar>::test(SS(10));
	TesterDec<uchar>::test_lz(SS(10, true));
}

void TestNumberStringifier::testFormatDecShort()
{
	TesterDec<short>::test(SS(10));
	TesterDec<short>::test_lz(SS(10, true));
	TesterDec<ushort>::test(SS(10));
	TesterDec<ushort>::test_lz(SS(10, true));
}

void TestNumberStringifier::testFormatDecInt()
{
	TesterDec<int>::test(SS(10));
	TesterDec<int>::test_lz(SS(10, true));
	TesterDec<uint>::test(SS(10));
	TesterDec<uint>::test_lz(SS(10, true));
}

void TestNumberStringifier::testFormatDecLong()
{
	TesterDec<long>::test(SS(10));
	TesterDec<long>::test_lz(SS(10, true));
	TesterDec<ulong>::test(SS(10));
	TesterDec<ulong>::test_lz(SS(10, true));
}

void TestNumberStringifier::testFormatDecInt64()
{
	TesterDec<qint64>::test(SS(10));
	TesterDec<qint64>::test_lz(SS(10, true));
	TesterDec<quint64>::test(SS(10));
	TesterDec<quint64>::test_lz(SS(10, true));
}

void TestNumberStringifier::testFormatHexChar()
{
	TesterHex<signed char>::test(SS(16));
	TesterHex<signed char>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<signed char>::test_lz(SS(16, true));
	TesterHex<signed char>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<char>::test(SS(16));
	TesterHex<char>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<char>::test_lz(SS(16, true));
	TesterHex<char>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<uchar>::test(SS(16));
	TesterHex<uchar>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<uchar>::test_lz(SS(16, true));
	TesterHex<uchar>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<signed char>::test_p(SS(16, false, true));
	TesterHex<signed char>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<signed char>::test_p_lz(SS(16, true, true));
	TesterHex<signed char>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<char>::test_p(SS(16, false, true));
	TesterHex<char>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<char>::test_p_lz(SS(16, true, true));
	TesterHex<char>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<uchar>::test_p(SS(16, false, true));
	TesterHex<uchar>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<uchar>::test_p_lz(SS(16, true, true));
	TesterHex<uchar>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));
}

void TestNumberStringifier::testFormatHexShort()
{
	TesterHex<short>::test(SS(16));
	TesterHex<short>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<short>::test_lz(SS(16, true));
	TesterHex<short>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<ushort>::test(SS(16));
	TesterHex<ushort>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<ushort>::test_lz(SS(16, true));
	TesterHex<ushort>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<short>::test_p(SS(16, false, true));
	TesterHex<short>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<short>::test_p_lz(SS(16, true, true));
	TesterHex<short>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<ushort>::test_p(SS(16, false, true));
	TesterHex<ushort>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<ushort>::test_p_lz(SS(16, true, true));
	TesterHex<ushort>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));
}

void TestNumberStringifier::testFormatHexInt()
{
	TesterHex<int>::test(SS(16));
	TesterHex<int>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<int>::test_lz(SS(16, true));
	TesterHex<int>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<uint>::test(SS(16));
	TesterHex<uint>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<uint>::test_lz(SS(16, true));
	TesterHex<uint>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<int>::test_p(SS(16, false, true));
	TesterHex<int>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<int>::test_p_lz(SS(16, true, true));
	TesterHex<int>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<uint>::test_p(SS(16, false, true));
	TesterHex<uint>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<uint>::test_p_lz(SS(16, true, true));
	TesterHex<uint>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));
}

void TestNumberStringifier::testFormatHexLong()
{
	TesterHex<long>::test(SS(16));
	TesterHex<long>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<long>::test_lz(SS(16, true));
	TesterHex<long>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<ulong>::test(SS(16));
	TesterHex<ulong>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<ulong>::test_lz(SS(16, true));
	TesterHex<ulong>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<long>::test_p(SS(16, false, true));
	TesterHex<long>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<long>::test_p_lz(SS(16, true, true));
	TesterHex<long>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<ulong>::test_p(SS(16, false, true));
	TesterHex<ulong>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<ulong>::test_p_lz(SS(16, true, true));
	TesterHex<ulong>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));
}

void TestNumberStringifier::testFormatHexInt64()
{
	TesterHex<qint64>::test(SS(16));
	TesterHex<qint64>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<qint64>::test_lz(SS(16, true));
	TesterHex<qint64>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<quint64>::test(SS(16));
	TesterHex<quint64>::test_up(SS(16, false, false, Qpe::Stringifier::UpperCase));
	TesterHex<quint64>::test_lz(SS(16, true));
	TesterHex<quint64>::test_lz_up(SS(16, true, false, Qpe::Stringifier::UpperCase));

	TesterHex<qint64>::test_p(SS(16, false, true));
	TesterHex<qint64>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<qint64>::test_p_lz(SS(16, true, true));
	TesterHex<qint64>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));

	TesterHex<quint64>::test_p(SS(16, false, true));
	TesterHex<quint64>::test_p_up(SS(16, false, true, Qpe::Stringifier::UpperCase));
	TesterHex<quint64>::test_p_lz(SS(16, true, true));
	TesterHex<quint64>::test_p_lz_up(SS(16, true, true, Qpe::Stringifier::UpperCase));
}

void TestNumberStringifier::testFormatDecChar_str()
{
	TesterDec<signed char>::test(SS("10"));
	TesterDec<signed char>::test_lz(SS("10l"));
	TesterDec<char>::test(SS("10"));
	TesterDec<char>::test_lz(SS("10l"));
	TesterDec<uchar>::test(SS("10"));
	TesterDec<uchar>::test_lz(SS("10l"));
}

void TestNumberStringifier::testFormatDecShort_str()
{
	TesterDec<short>::test(SS("10"));
	TesterDec<short>::test_lz(SS("10l"));
	TesterDec<ushort>::test(SS("10"));
	TesterDec<ushort>::test_lz(SS("10l"));
}

void TestNumberStringifier::testFormatDecInt_str()
{
	TesterDec<int>::test(SS("10"));
	TesterDec<int>::test_lz(SS("10l"));
	TesterDec<uint>::test(SS("10"));
	TesterDec<uint>::test_lz(SS("10l"));
}

void TestNumberStringifier::testFormatDecLong_str()
{
	TesterDec<long>::test(SS("10"));
	TesterDec<long>::test_lz(SS("10l"));
	TesterDec<ulong>::test(SS("10"));
	TesterDec<ulong>::test_lz(SS("10l"));
}

void TestNumberStringifier::testFormatDecInt64_str()
{
	TesterDec<qint64>::test(SS("10"));
	TesterDec<qint64>::test_lz(SS("10l"));
	TesterDec<quint64>::test(SS("10"));
	TesterDec<quint64>::test_lz(SS("10l"));
}

void TestNumberStringifier::testFormatHexChar_str()
{
	TesterHex<signed char>::test(SS("16"));
	TesterHex<signed char>::test_up(SS("16u"));
	TesterHex<signed char>::test_lz(SS("16l"));
	TesterHex<signed char>::test_lz_up(SS("16lu"));

	TesterHex<char>::test(SS("16"));
	TesterHex<char>::test_up(SS("16u"));
	TesterHex<char>::test_lz(SS("16l"));
	TesterHex<char>::test_lz_up(SS("16ul"));

	TesterHex<uchar>::test(SS("16"));
	TesterHex<uchar>::test_up(SS("16u"));
	TesterHex<uchar>::test_lz(SS("16l"));
	TesterHex<uchar>::test_lz_up(SS("16ul"));

	TesterHex<signed char>::test_p(SS("16p"));
	TesterHex<signed char>::test_p_up(SS("16pu"));
	TesterHex<signed char>::test_p_lz(SS("16lp"));
	TesterHex<signed char>::test_p_lz_up(SS("16lup"));

	TesterHex<char>::test_p(SS("16p"));
	TesterHex<char>::test_p_up(SS("16up"));
	TesterHex<char>::test_p_lz(SS("16pl"));
	TesterHex<char>::test_p_lz_up(SS("16pul"));

	TesterHex<uchar>::test_p(SS("16p"));
	TesterHex<uchar>::test_p_up(SS("16pu"));
	TesterHex<uchar>::test_p_lz(SS("16lp"));
	TesterHex<uchar>::test_p_lz_up(SS("16ulp"));
}

void TestNumberStringifier::testFormatHexShort_str()
{
	TesterHex<short>::test(SS("16"));
	TesterHex<short>::test_up(SS("16u"));
	TesterHex<short>::test_lz(SS("16l"));
	TesterHex<short>::test_lz_up(SS("16ul"));

	TesterHex<ushort>::test(SS("16"));
	TesterHex<ushort>::test_up(SS("16u"));
	TesterHex<ushort>::test_lz(SS("16l"));
	TesterHex<ushort>::test_lz_up(SS("16ul"));

	TesterHex<short>::test_p(SS("16p"));
	TesterHex<short>::test_p_up(SS("16up"));
	TesterHex<short>::test_p_lz(SS("16pl"));
	TesterHex<short>::test_p_lz_up(SS("16pul"));

	TesterHex<ushort>::test_p(SS("16p"));
	TesterHex<ushort>::test_p_up(SS("16pu"));
	TesterHex<ushort>::test_p_lz(SS("16lp"));
	TesterHex<ushort>::test_p_lz_up(SS("16ulp"));
}

void TestNumberStringifier::testFormatHexInt_str()
{
	TesterHex<int>::test(SS("16"));
	TesterHex<int>::test_up(SS("16u"));
	TesterHex<int>::test_lz(SS("16l"));
	TesterHex<int>::test_lz_up(SS("16ul"));

	TesterHex<uint>::test(SS("16"));
	TesterHex<uint>::test_up(SS("16u"));
	TesterHex<uint>::test_lz(SS("16l"));
	TesterHex<uint>::test_lz_up(SS("16ul"));

	TesterHex<int>::test_p(SS("16p"));
	TesterHex<int>::test_p_up(SS("16up"));
	TesterHex<int>::test_p_lz(SS("16pl"));
	TesterHex<int>::test_p_lz_up(SS("16pul"));

	TesterHex<uint>::test_p(SS("16p"));
	TesterHex<uint>::test_p_up(SS("16pu"));
	TesterHex<uint>::test_p_lz(SS("16lp"));
	TesterHex<uint>::test_p_lz_up(SS("16ulp"));
}

void TestNumberStringifier::testFormatHexLong_str()
{
	TesterHex<long>::test(SS("16"));
	TesterHex<long>::test_up(SS("16u"));
	TesterHex<long>::test_lz(SS("16l"));
	TesterHex<long>::test_lz_up(SS("16ul"));

	TesterHex<ulong>::test(SS("16"));
	TesterHex<ulong>::test_up(SS("16u"));
	TesterHex<ulong>::test_lz(SS("16l"));
	TesterHex<ulong>::test_lz_up(SS("16ul"));

	TesterHex<long>::test_p(SS("16p"));
	TesterHex<long>::test_p_up(SS("16up"));
	TesterHex<long>::test_p_lz(SS("16pl"));
	TesterHex<long>::test_p_lz_up(SS("16pul"));

	TesterHex<ulong>::test_p(SS("16p"));
	TesterHex<ulong>::test_p_up(SS("16pu"));
	TesterHex<ulong>::test_p_lz(SS("16lp"));
	TesterHex<ulong>::test_p_lz_up(SS("16ulp"));
}

void TestNumberStringifier::testFormatHexInt64_str()
{
	TesterHex<qint64>::test(SS("16"));
	TesterHex<qint64>::test_up(SS("16u"));
	TesterHex<qint64>::test_lz(SS("16l"));
	TesterHex<qint64>::test_lz_up(SS("16ul"));

	TesterHex<quint64>::test(SS("16"));
	TesterHex<quint64>::test_up(SS("16u"));
	TesterHex<quint64>::test_lz(SS("16l"));
	TesterHex<quint64>::test_lz_up(SS("16ul"));

	TesterHex<qint64>::test_p(SS("16p"));
	TesterHex<qint64>::test_p_up(SS("16up"));
	TesterHex<qint64>::test_p_lz(SS("16pl"));
	TesterHex<qint64>::test_p_lz_up(SS("16pul"));

	TesterHex<quint64>::test_p(SS("16p"));
	TesterHex<quint64>::test_p_up(SS("16pu"));
	TesterHex<quint64>::test_p_lz(SS("16lp"));
	TesterHex<quint64>::test_p_lz_up(SS("16ulp"));
}

namespace _____dec_____ { }

template<typename T>
void TesterDec<T, Signed, 1>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(127), result) == "127");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<T>(-128), result) == "-128");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");

	QVERIFY(s.format(static_cast<T>(-1), result) == "255");
	QVERIFY(s.format(static_cast<T>(-9), result) == "247");
	QVERIFY(s.format(static_cast<T>(-10), result) == "246");
}

template<typename T>
void TesterDec<T, Signed, 1>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "000");
	QVERIFY(s.format(static_cast<T>(9), result) == "009");
	QVERIFY(s.format(static_cast<T>(10), result) == "010");
	QVERIFY(s.format(static_cast<T>(99), result) == "099");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(127), result) == "127");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-001");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-009");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-010");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-099");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-100");
//	QVERIFY(s.format(static_cast<T>(-128), result) == "-128");
}

template<typename T>
void TesterDec<T, Unsigned, 1>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "000");
	QVERIFY(s.format(static_cast<T>(9), result) == "009");
	QVERIFY(s.format(static_cast<T>(10), result) == "010");
	QVERIFY(s.format(static_cast<T>(99), result) == "099");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");

	QVERIFY(s.format(static_cast<T>(-1), result) == "255");
	QVERIFY(s.format(static_cast<T>(-9), result) == "247");
	QVERIFY(s.format(static_cast<T>(-10), result) == "246");
}

template<typename T>
void TesterDec<T, Signed, 2>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "-32767");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<T>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<T>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<T>(-10), result) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 2>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00009");
	QVERIFY(s.format(static_cast<T>(10), result) == "00010");
	QVERIFY(s.format(static_cast<T>(99), result) == "00099");
	QVERIFY(s.format(static_cast<T>(100), result) == "00100");
	QVERIFY(s.format(static_cast<T>(255), result) == "00255");
	QVERIFY(s.format(static_cast<T>(256), result) == "00256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<T>(32767), result) == "32767");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-00001");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-00009");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-00010");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-00099");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-00100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-00255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-00256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-01000");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "-32767");
}

template<typename T>
void TesterDec<T, Unsigned, 2>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00009");
	QVERIFY(s.format(static_cast<T>(10), result) == "00010");
	QVERIFY(s.format(static_cast<T>(99), result) == "00099");
	QVERIFY(s.format(static_cast<T>(100), result) == "00100");
	QVERIFY(s.format(static_cast<T>(255), result) == "00255");
	QVERIFY(s.format(static_cast<T>(256), result) == "00256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "01000");
	QVERIFY(s.format(static_cast<T>(65535), result) == "65535");

	QVERIFY(s.format(static_cast<T>(-1), result) == "65535");
	QVERIFY(s.format(static_cast<T>(-9), result) == "65527");
	QVERIFY(s.format(static_cast<T>(-10), result) == "65526");
}

template<typename T>
void TesterDec<T, Signed, 4>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "-1");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<T>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<T>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<T>(-10), result) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 4>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<T>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "2147483647");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "-0000000001");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-0000000001");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-0000000009");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-0000000010");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-0000000099");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-0000000100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-0000000255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-0000000256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-0000001000");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "-2147483647");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "0000000001");
}

template<typename T>
void TesterDec<T, Unsigned, 4>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000010");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000099");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000100");
	QVERIFY(s.format(static_cast<T>(255), result) == "0000000255");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0000001000");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "4294967295");

	QVERIFY(s.format(static_cast<T>(-1), result) == "4294967295");
	QVERIFY(s.format(static_cast<T>(-9), result) == "4294967287");
	QVERIFY(s.format(static_cast<T>(-10), result) == "4294967286");
}

template<typename T>
void TesterDec<T, Signed, 8>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "-1");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-1");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-9");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-10");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-99");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-1000");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(!s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "10");
	QVERIFY(s.format(static_cast<T>(99), result) == "99");
	QVERIFY(s.format(static_cast<T>(100), result) == "100");
	QVERIFY(s.format(static_cast<T>(255), result) == "255");
	QVERIFY(s.format(static_cast<T>(256), result) == "256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "1000");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<T>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<T>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<T>(-10), result) == "18446744073709551606");
}

template<typename T>
void TesterDec<T, Signed, 8>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000000000000010");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000000000000099");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000000000000100");
	QVERIFY(s.format(static_cast<T>(255), result) == "0000000000000000255");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000000000000256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0000000000000001000");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "9223372036854775807");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "-0000000000000000001");

	QVERIFY(s.format(static_cast<T>(-1), result) == "-0000000000000000001");
	QVERIFY(s.format(static_cast<T>(-9), result) == "-0000000000000000009");
	QVERIFY(s.format(static_cast<T>(-10), result) == "-0000000000000000010");
	QVERIFY(s.format(static_cast<T>(-99), result) == "-0000000000000000099");
	QVERIFY(s.format(static_cast<T>(-100), result) == "-0000000000000000100");
	QVERIFY(s.format(static_cast<T>(-255), result) == "-0000000000000000255");
	QVERIFY(s.format(static_cast<T>(-256), result) == "-0000000000000000256");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "-0000000000000001000");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "-9223372036854775807");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000000001");
}

template<typename T>
void TesterDec<T, Unsigned, 8>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 10);
	QVERIFY(s.isLeadingZero());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00000000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "00000000000000000010");
	QVERIFY(s.format(static_cast<T>(99), result) == "00000000000000000099");
	QVERIFY(s.format(static_cast<T>(100), result) == "00000000000000000100");
	QVERIFY(s.format(static_cast<T>(255), result) == "00000000000000000255");
	QVERIFY(s.format(static_cast<T>(256), result) == "00000000000000000256");
	QVERIFY(s.format(static_cast<T>(1000), result) == "00000000000000001000");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "18446744073709551615");

	QVERIFY(s.format(static_cast<T>(-1), result) == "18446744073709551615");
	QVERIFY(s.format(static_cast<T>(-9), result) == "18446744073709551607");
	QVERIFY(s.format(static_cast<T>(-10), result) == "18446744073709551606");
}

namespace _____hex_1_____ { }

template<typename T>
void TesterHex<T, Signed, 1>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(127), result) == "7f");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "9c");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(127), result) == "7F");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "9C");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00");
	QVERIFY(s.format(static_cast<T>(9), result) == "09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(127), result) == "7f");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "f6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "9c");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00");
	QVERIFY(s.format(static_cast<T>(9), result) == "09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "f7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "f6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00");
	QVERIFY(s.format(static_cast<T>(9), result) == "09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(127), result) == "7F");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "F6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "9C");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00");
	QVERIFY(s.format(static_cast<T>(9), result) == "09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "F7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "F6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0x9c");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0x9C");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xF6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(127), result) == "0x7f");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xf6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0x9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0x9c");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xf7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xf6");
}

template<typename T>
void TesterHex<T, Signed, 1>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(127), result) == "0x7F");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0x9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0x9C");
}

template<typename T>
void TesterHex<T, Unsigned, 1>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x09");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xF6");
}

namespace _____hex_2_____ { }

template<typename T>
void TesterHex<T, Signed, 2>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "7fff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fc18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "03e8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "ffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "7FFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FC18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "03E8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "FFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "0x8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "0x8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFF6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "0x7fff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfc18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "0x8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x03e8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "0xffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfff6");
}

template<typename T>
void TesterHex<T, Signed, 2>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<T>(32767), result) == "0x7FFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFC18");
	QVERIFY(s.format(static_cast<T>(-32767), result) == "0x8001");
}

template<typename T>
void TesterHex<T, Unsigned, 2>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x03E8");
	QVERIFY(s.format(static_cast<T>(65535), result) == "0xFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFF6");
}


namespace _____hex_4_____ { }

template<typename T>
void TesterHex<T, Signed, 4>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "7fffffff");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fffffc18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "000003e8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "ffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "7FFFFFFF");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FFFFFC18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "000003E8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "FFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "0x7fffffff");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfffffc18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x000003e8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffff6");
}

template<typename T>
void TesterHex<T, Signed, 4>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<T>(2147483647), result) == "0x7FFFFFFF");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-2147483647), result) == "0x80000001");
	QVERIFY(s.format(static_cast<T>(0-4294967295UL), result) == "0x00000001");
}

template<typename T>
void TesterHex<T, Unsigned, 4>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x00000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x00000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x0000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x00000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x00000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x00000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x000003E8");
	QVERIFY(s.format(static_cast<T>(4294967295), result) == "0xFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFF6");
}

namespace _____hex_8_____ { }

template<typename T>
void TesterHex<T, Signed, 8>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "a");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3e8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0");
	QVERIFY(s.format(static_cast<T>(9), result) == "9");
	QVERIFY(s.format(static_cast<T>(10), result) == "A");
	QVERIFY(s.format(static_cast<T>(99), result) == "63");
	QVERIFY(s.format(static_cast<T>(100), result) == "64");
	QVERIFY(s.format(static_cast<T>(255), result) == "FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "3E8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "7fffffffffffffff");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffffffffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "ffffffffffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "ffffffffffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "ffffffffffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "ffffffffffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "fffffffffffffc18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000000000000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00000000000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "00000000000003e8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "ffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "ffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "fffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "fffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "FFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "FFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "FFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "FFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "FFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(!s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "000000000000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "00000000000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "00000000000003E8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "FFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "FFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "FFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "FFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xa");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3e8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0x1");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_up(const Qpe::Stringifier& s)
{
	// ---- without leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(!s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x9");
	QVERIFY(s.format(static_cast<T>(10), result) == "0xA");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x63");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x64");
	QVERIFY(s.format(static_cast<T>(255), result) == "0xFF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x3E8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "0x7fffffffffffffff");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xffffffffffffff9d");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xffffffffffffff9c");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xffffffffffffff01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xffffffffffffff00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xfffffffffffffc18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(!s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000000000000000a");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00000000000000ff");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x00000000000003e8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xffffffffffffffff");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xffffffffffffffff");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xfffffffffffffff7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xfffffffffffffff6");
}

template<typename T>
void TesterHex<T, Signed, 8>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<T>(9223372036854775807), result) == "0x7FFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
	QVERIFY(s.format(static_cast<T>(-99), result) == "0xFFFFFFFFFFFFFF9D");
	QVERIFY(s.format(static_cast<T>(-100), result) == "0xFFFFFFFFFFFFFF9C");
	QVERIFY(s.format(static_cast<T>(-255), result) == "0xFFFFFFFFFFFFFF01");
	QVERIFY(s.format(static_cast<T>(-256), result) == "0xFFFFFFFFFFFFFF00");
	QVERIFY(s.format(static_cast<T>(-1000), result) == "0xFFFFFFFFFFFFFC18");
	QVERIFY(s.format(static_cast<T>(-9223372036854775807), result) == "0x8000000000000001");
	QVERIFY(s.format(static_cast<T>(0-18446744073709551615ULL), result) == "0x0000000000000001");
}

template<typename T>
void TesterHex<T, Unsigned, 8>::test_p_lz_up(const Qpe::Stringifier& s)
{
	// ---- with leading zero
	QVERIFY(s.base() == 16);
	QVERIFY(s.isLeadingZero());
	QVERIFY(s.isPrefixRequired());
	QVERIFY(s.isUpperCase());
	QString result;
	QVERIFY(s.format(static_cast<T>(0), result) == "0x0000000000000000");
	QVERIFY(s.format(static_cast<T>(9), result) == "0x0000000000000009");
	QVERIFY(s.format(static_cast<T>(10), result) == "0x000000000000000A");
	QVERIFY(s.format(static_cast<T>(99), result) == "0x0000000000000063");
	QVERIFY(s.format(static_cast<T>(100), result) == "0x0000000000000064");
	QVERIFY(s.format(static_cast<T>(255), result) == "0x00000000000000FF");
	QVERIFY(s.format(static_cast<T>(256), result) == "0x0000000000000100");
	QVERIFY(s.format(static_cast<T>(1000), result) == "0x00000000000003E8");
	QVERIFY(s.format(static_cast<T>(18446744073709551615ULL), result) == "0xFFFFFFFFFFFFFFFF");

	QVERIFY(s.format(static_cast<T>(-1), result) == "0xFFFFFFFFFFFFFFFF");
	QVERIFY(s.format(static_cast<T>(-9), result) == "0xFFFFFFFFFFFFFFF7");
	QVERIFY(s.format(static_cast<T>(-10), result) == "0xFFFFFFFFFFFFFFF6");
}

QTEST_MAIN(TestNumberStringifier)
#include "test_numberstringifier.moc"

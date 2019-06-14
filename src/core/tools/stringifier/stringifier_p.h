#ifndef TOOLS_STRINGIFIER_STRINGIFIER_P_H
#define TOOLS_STRINGIFIER_STRINGIFIER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <boost/fusion/include/map.hpp>
#include <boost/fusion/include/at_key.hpp>

#include <QSharedPointer>
#include <QHash>

#include <Qpe/Global>

#include <Qpe/Core/StaticStringifierDec>
#include <Qpe/Core/StaticStringifierHex>

namespace Qpe
{

class Stringifier;
class StringifierPrivate
{
	QPE_DECLARE_PUBLIC(Stringifier)
protected:
	Stringifier* q_ptr;
public:
	template <typename T>
	using Sign1 = QByteArray(*)(T);
	template <typename T>
	using Sign2 = QByteArray&(*)(T, QByteArray&);
	template <typename T>
	using Sign3 = QString&(*)(T, QString&);

	template <template <typename> class Sign>
	using mt =
		boost::fusion::map<
			boost::fusion::pair<char, Sign<char> >,
			boost::fusion::pair<uchar, Sign<uchar> >,
			boost::fusion::pair<signed char, Sign<signed char> >,
			boost::fusion::pair<short, Sign<short> >,
			boost::fusion::pair<ushort, Sign<ushort> >,
			boost::fusion::pair<int, Sign<int> >,
			boost::fusion::pair<uint, Sign<uint> >,
			boost::fusion::pair<long, Sign<long> >,
			boost::fusion::pair<ulong, Sign<ulong> >,
			boost::fusion::pair<qint64, Sign<qint64> >,
			boost::fusion::pair<quint64, Sign<quint64> >,
			boost::fusion::pair<void*, Sign<void*> >
		>;

	typedef mt<Sign1> map_signature1;
	typedef mt<Sign2> map_signature2;
	typedef mt<Sign3> map_signature3;

	struct BaseCreator
	{
		virtual ~BaseCreator() { }

		virtual map_signature1 sign1() const = 0;
		virtual map_signature2 sign2() const = 0;
		virtual map_signature3 sign3() const = 0;
	};

	template <
		int Base,
		typename TLeadingZero,
		typename TPrefix,
		typename TCase>
	struct Creator : public BaseCreator
	{
		virtual ~Creator() Q_DECL_OVERRIDE { }

		typedef Static::Stringifier<Base, TLeadingZero, TPrefix, TCase> Stringifier;

		virtual map_signature1 sign1() const Q_DECL_OVERRIDE
		{
			return map_signature1
			(
				boost::fusion::make_pair<char>(static_cast<Sign1<char> >(&Stringifier::format)),
				boost::fusion::make_pair<uchar>(static_cast<Sign1<uchar> >(&Stringifier::format)),
				boost::fusion::make_pair<signed char>(static_cast<Sign1<signed char> >(&Stringifier::format)),
				boost::fusion::make_pair<short>(static_cast<Sign1<short> >(&Stringifier::format)),
				boost::fusion::make_pair<ushort>(static_cast<Sign1<ushort> >(&Stringifier::format)),
				boost::fusion::make_pair<int>(static_cast<Sign1<int> >(&Stringifier::format)),
				boost::fusion::make_pair<uint>(static_cast<Sign1<uint> >(&Stringifier::format)),
				boost::fusion::make_pair<long>(static_cast<Sign1<long> >(&Stringifier::format)),
				boost::fusion::make_pair<ulong>(static_cast<Sign1<ulong> >(&Stringifier::format)),
				boost::fusion::make_pair<qint64>(static_cast<Sign1<qint64> >(&Stringifier::format)),
				boost::fusion::make_pair<quint64>(static_cast<Sign1<quint64> >(&Stringifier::format)),
				boost::fusion::make_pair<void*>(static_cast<Sign1<void*> >(&Stringifier::format))
			);
		}
		virtual map_signature2 sign2() const Q_DECL_OVERRIDE
		{
			return map_signature2
			(
				boost::fusion::make_pair<char>(static_cast<Sign2<char> >(&Stringifier::format)),
				boost::fusion::make_pair<uchar>(static_cast<Sign2<uchar> >(&Stringifier::format)),
				boost::fusion::make_pair<signed char>(static_cast<Sign2<signed char> >(&Stringifier::format)),
				boost::fusion::make_pair<short>(static_cast<Sign2<short> >(&Stringifier::format)),
				boost::fusion::make_pair<ushort>(static_cast<Sign2<ushort> >(&Stringifier::format)),
				boost::fusion::make_pair<int>(static_cast<Sign2<int> >(&Stringifier::format)),
				boost::fusion::make_pair<uint>(static_cast<Sign2<uint> >(&Stringifier::format)),
				boost::fusion::make_pair<long>(static_cast<Sign2<long> >(&Stringifier::format)),
				boost::fusion::make_pair<ulong>(static_cast<Sign2<ulong> >(&Stringifier::format)),
				boost::fusion::make_pair<qint64>(static_cast<Sign2<qint64> >(&Stringifier::format)),
				boost::fusion::make_pair<quint64>(static_cast<Sign2<quint64> >(&Stringifier::format)),
				boost::fusion::make_pair<void*>(static_cast<Sign2<void*> >(&Stringifier::format))
			);
		}
		virtual map_signature3 sign3() const Q_DECL_OVERRIDE
		{
			return map_signature3
			(
				boost::fusion::make_pair<char>(static_cast<Sign3<char> >(&Stringifier::format)),
				boost::fusion::make_pair<uchar>(static_cast<Sign3<uchar> >(&Stringifier::format)),
				boost::fusion::make_pair<signed char>(static_cast<Sign3<signed char> >(&Stringifier::format)),
				boost::fusion::make_pair<short>(static_cast<Sign3<short> >(&Stringifier::format)),
				boost::fusion::make_pair<ushort>(static_cast<Sign3<ushort> >(&Stringifier::format)),
				boost::fusion::make_pair<int>(static_cast<Sign3<int> >(&Stringifier::format)),
				boost::fusion::make_pair<uint>(static_cast<Sign3<uint> >(&Stringifier::format)),
				boost::fusion::make_pair<long>(static_cast<Sign3<long> >(&Stringifier::format)),
				boost::fusion::make_pair<ulong>(static_cast<Sign3<ulong> >(&Stringifier::format)),
				boost::fusion::make_pair<qint64>(static_cast<Sign3<qint64> >(&Stringifier::format)),
				boost::fusion::make_pair<quint64>(static_cast<Sign3<quint64> >(&Stringifier::format)),
				boost::fusion::make_pair<void*>(static_cast<Sign3<void*> >(&Stringifier::format))
			);
		}
	};

	StringifierPrivate(int b, bool lz, bool pr, bool uc);
	~StringifierPrivate();

	void initialize();

	template <
		int Base,
		typename TLeadingZero,
		typename TPrefix,
		typename TCase>
	void insertCreator();

	bool setFormatString(const QString& formatString);
	void update();

	template <typename T>
	QByteArray format(T n) const;

	template <typename T>
	QByteArray& format(T n, QByteArray& result) const;

	template <typename T>
	QString& format(T n, QString& result) const;

	int base;
	bool leadingZero;
	bool prefixRequired;
	bool upperCase;

	map_signature1 m1;
	map_signature2 m2;
	map_signature3 m3;

	QHash<QList<int>, QSharedPointer<BaseCreator> > creators;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_STRINGIFIER_STRINGIFIER_P_H

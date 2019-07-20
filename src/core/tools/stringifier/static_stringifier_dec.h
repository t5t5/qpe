#ifndef TOOLS_STRINGIFIER_STATIC_STRINGIFIER_DEC_H
#define TOOLS_STRINGIFIER_STATIC_STRINGIFIER_DEC_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QByteArray>
#include <QString>

#include <Qpe/Core/Private/static_stringifier.h>
#include <Qpe/Core/Private/digitscount_dec.h>

#include <Qpe/Core/mpl/math_power>

namespace Qpe
{

#ifndef Q_QDOC

namespace PrivateDec
{

struct Negative { };
struct Positive { };

template <typename>
struct Sign;

template <>
struct Sign<Positive>
{
	inline static int size() { return 0; }
	template <typename value_type>
	inline static void write(value_type*&) { }
};

template <>
struct Sign<Negative>
{
	inline static int size() { return 1; }
	template <typename value_type>
	inline static void write(value_type*& buffer) { *buffer++ = '-'; }
};

template <
	typename T,
	typename TLeadingZero,
	int TDigits = 0>
struct LeadingZero;

template <
	typename T,
	int TDigits>
struct LeadingZero<T, WithLeadingZero, TDigits>
{
	static const int Digits =
		(TDigits > 0) ? TDigits : integer_traits<T>::Digits10;

	int zeros;
	inline int size(int digits) { return zeros = Digits - digits; }

	template <typename value_type>
	inline void write(value_type*& buffer) const
	{
		if (zeros == 0) { return; }
		std::fill_n(buffer, zeros, static_cast<value_type>('0'));
		buffer += zeros;
	}
};

template <
	typename T,
	typename R,
	typename TSign,
	typename TLeadingZero,
	int TDigits = 0>
struct Algorithm;

template <typename T, typename R, typename TSign, int TDigits>
struct Algorithm<T, R, TSign, WithLeadingZero, TDigits>
{
	typedef PrivateDec::Sign<TSign> Sign;
	typedef PrivateDec::LeadingZero<T, WithLeadingZero, TDigits> LeadingZero;
	typedef typename std::make_unsigned<T>::type unsigned_T;

	typedef typename R::value_type value_type;
	inline static void format(T n, R& result)
	{
		const int digits = DecimalDigitsCount<unsigned_T>::count(n);
		LeadingZero lz;
		int chars = digits + Sign::size() + lz.size(digits);
		result.resize(chars);
		value_type* buffer = result.data();
		Sign::write(buffer);
		lz.write(buffer);
		value_type* b = buffer + digits - 1;
		while (n >= 10) {
			int m = n % 10;
			n /= 10;
			*b-- = m + '0';
		};
		*b = static_cast<int>(n + '0');
	}
};

template <typename T, typename R, typename TSign, int TDigits>
struct Algorithm<T, R, TSign, WithoutLeadingZero, TDigits>
{
	typedef PrivateDec::Sign<TSign> Sign;
	typedef typename std::make_unsigned<T>::type unsigned_T;

	typedef typename R::value_type value_type;
	inline static void format(T n, R& result)
	{
		const int digits = DecimalDigitsCount<unsigned_T>::count(n);
		int chars = digits + Sign::size();
		result.resize(chars);
		value_type* buffer = result.data();
		Sign::write(buffer);
		value_type* b = buffer + digits - 1;
		while (n >= 10) {
			int m = n % 10;
			n /= 10;
			*b-- = m + '0';
		};
		*b = static_cast<int>(n + '0');
	}
};

template <
	typename R,
	typename TLeadingZero>
struct Stringifier
{
	template <typename T>
	inline static R format(T n,
		enable_if_t<std::is_unsigned<T>::value>* = nullptr)
	{
		R result;
		Algorithm<T, R, Positive, TLeadingZero>::format(n, result);
		return result;
	}

	template <typename T>
	inline static R& format(T n, R& result,
		enable_if_t<std::is_unsigned<T>::value>* = nullptr)
	{
		Algorithm<T, R, Positive, TLeadingZero>::format(n, result);
		return result;
	}

	template <typename T>
	inline static R format(T n,
		enable_if_t<std::is_signed<T>::value>* = nullptr)
	{
		R result;
		(n >= 0)
			? Algorithm<T, R, Positive, TLeadingZero>::format(n, result)
			: Algorithm<T, R, Negative, TLeadingZero>::format(-n, result);
		return result;
	}

	template <typename T>
	inline static R& format(T n, R& result,
		enable_if_t<std::is_signed<T>::value>* = nullptr)
	{
		(n >= 0)
			? Algorithm<T, R, Positive, TLeadingZero>::format(n, result)
			: Algorithm<T, R, Negative, TLeadingZero>::format(-n, result);
		return result;
	}

	template <typename T>
	inline static R format(T* n)
	{
		R result;
		Algorithm<quintptr, R, Positive, TLeadingZero>
			::format(reinterpret_cast<quintptr>(n), result);
		return result;
	}

	template <typename T>
	inline static R& format(T* n, R& result)
	{
		Algorithm<quintptr, R, Positive, TLeadingZero>
			::format(reinterpret_cast<quintptr>(n), result);
		return result;
	}
};

template <typename unsigned_T, typename R, int TDigits, class Enable = void>
struct Digits
{
	static const unsigned_T limit = mpl::math::power<10, TDigits, unsigned_T>::value;

	inline static R& format(unsigned_T n, R& result)
	{
		if (n >= limit) { n %= limit; }
		Algorithm<unsigned_T, R, Positive, WithLeadingZero, TDigits>
			::format(n, result);
		return result;
	}
};

template <typename R, int TDigits>
struct Digits<uchar, R, TDigits, enable_if_t<(TDigits > 2)> >
{
	inline static R& format(uchar n, R& result)
	{
		Algorithm<uchar, R, Positive, WithLeadingZero, TDigits>
			::format(n, result);
		return result;
	}
};

template <typename T, typename R, int TDigits>
struct Digits<T, R, TDigits, enable_if_t<TDigits == 2> >
{
	typedef typename R::value_type value_type;
	inline static R& format(T n, R& result)
	{
		result.resize(2);
		value_type* buffer = result.data();
		if (n >= 100) { n %= 100; }
		*buffer++ = static_cast<int>((n / 10) + '0');
		*buffer = static_cast<int>((n % 10)+ '0');
		return result;
	}
};

template <int TDigits>
struct DigitsBase
{
	template <typename T>
	static inline QByteArray format(T n)
	{
		typedef typename std::make_unsigned<T>::type unsigned_T;

		QByteArray result;
		return Digits<unsigned_T, QByteArray, TDigits>::format(n, result);
	}

	template <typename T>
	static inline QByteArray& format(T n, QByteArray& result)
	{
		typedef typename std::make_unsigned<T>::type unsigned_T;

		return Digits<unsigned_T, QByteArray, TDigits>::format(n, result);
	}

	template <typename T>
	static inline QString& format(T n, QString& result)
	{
		typedef typename std::make_unsigned<T>::type unsigned_T;

		return Digits<unsigned_T, QString, TDigits>::format(n, result);
	}
};

} // namespace PrivateDec

#endif // Q_QDOC

namespace Static
{

template <
	typename LeadingZero /* = WithoutLeadingZero */,
	typename PrefixType /* = WithoutPrefix */,
	typename Case /* = LowerCase */>
struct Stringifier<DecBase, LeadingZero, PrefixType, Case>
{
	template <typename T>
	static inline QByteArray format(T n)
	{
		return PrivateDec::Stringifier<QByteArray, LeadingZero>::format(n);
	}

	template <typename T>
	static inline QByteArray& format(T n, QByteArray& result)
	{
		return PrivateDec::Stringifier<QByteArray, LeadingZero>::format(n, result);
	}

	template <typename T>
	static inline QString& format(T n, QString& result)
	{
		return PrivateDec::Stringifier<QString, LeadingZero>::format(n, result);
	}
};

template <>
struct Stringifier<DecBase2Digits> : public PrivateDec::DigitsBase<2>
{
};

template <>
struct Stringifier<DecBase3Digits> : public PrivateDec::DigitsBase<3>
{
};

template <>
struct Stringifier<DecBase4Digits> : public PrivateDec::DigitsBase<4>
{
};

typedef Stringifier<DecBase> DecStringifier;

} // namespace Static

} // namespace Qpe

#endif // TOOLS_STRINGIFIER_STATIC_STRINGIFIER_DEC_H

#ifndef TOOLS_STRINGIFIER_STATIC_STRINGIFIER_HEX_H
#define TOOLS_STRINGIFIER_STATIC_STRINGIFIER_HEX_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QByteArray>
#include <QString>

#include <Qpe/Core/Private/static_stringifier.h>
#include <Qpe/Core/Private/digitscount_hex.h>

namespace Qpe
{

#ifndef Q_QDOC

namespace PrivateHex
{

template <typename>
struct Prefix;

template <>
struct Prefix<WithoutPrefix>
{
	inline static int size() { return 0; }
	template <typename value_type>
	inline static void write(value_type*&) { }
};

template <>
struct Prefix<WithPrefix>
{
	inline static int size() { return 2; }
	template <typename value_type>
	inline static void write(value_type*& buffer)
	{
		*buffer++ = '0';
		*buffer++ = 'x';
	}
};

template <
	typename T,
	typename TLeadingZero>
struct LeadingZero;

template <typename T>
struct LeadingZero<T, WithLeadingZero>
{
	int zeros;
	inline int size(int digits)
	{
		return zeros = (integer_traits<T>::SizeInBytes * 2) - digits;
	}

	template <typename value_type>
	inline void write(value_type*& buffer) const
	{
		if (zeros == 0) { return; }
		std::fill_n(buffer, zeros, static_cast<value_type>('0'));
		buffer += zeros;
	}
};

template <typename>
struct Case;

template <> struct Case<UpperCase> { static const char value = 'A'; };
template <> struct Case<LowerCase> { static const char value = 'a'; };

template <
	typename unsigned_T,
	typename R,
	typename TPrefix,
	typename TLeadingZero,
	char C>
struct StringifierImpl;

template <typename unsigned_T, typename R, typename TPrefix, char C>
struct StringifierImpl<unsigned_T, R, TPrefix, WithLeadingZero, C>
{
	typedef PrivateHex::LeadingZero<unsigned_T, WithLeadingZero> LeadingZero;
	typedef PrivateHex::Prefix<TPrefix> Prefix;

	typedef typename R::value_type value_type;
	static inline void format(unsigned_T n, R& result)
	{
		int digits = hexadecimalDigitsCount(n);
		LeadingZero lz;
		int chars = digits + Prefix::size() + lz.size(digits);
		result.resize(chars);
		value_type* buffer = result.data();
		Prefix::write(buffer);
		lz.write(buffer);
		value_type* b = buffer + digits - 1;
		while (n >= 0x10) {
			int m = n & 0x0f;
			n >>= 4;
			*b-- = m + (m >= 10 ? (C - 10) : '0');
		};
		*b = static_cast<int>(n + (n >= 10 ? (C - 10) : '0'));
	}
};

template <typename unsigned_T, typename R, typename TPrefix, char C>
struct StringifierImpl<unsigned_T, R, TPrefix, WithoutLeadingZero, C>
{
	typedef PrivateHex::Prefix<TPrefix> Prefix;

	typedef typename R::value_type value_type;
	static inline void format(unsigned_T n, R& result)
	{
		int digits = hexadecimalDigitsCount(n);
		int chars = digits + Prefix::size();
		result.resize(chars);
		value_type* buffer = result.data();
		Prefix::write(buffer);
		value_type* b = buffer + digits - 1;
		while (n >= 0x10) {
			int m = n & 0x0f;
			n >>= 4;
			*b-- = m + (m >= 10 ? (C - 10) : '0');
		};
		*b = static_cast<int>(n + (n >= 10 ? (C - 10) : '0'));
	}
};

template <
	typename R,
	typename TPrefix,
	typename TLeadingZero,
	typename TCase>
struct Stringifier
{
	typedef PrivateHex::Case<TCase> Case;

	template <typename T>
	static inline R format(T n)
	{
		typedef typename std::make_unsigned<T>::type unsigned_T;
		R result;
		StringifierImpl<unsigned_T, R, TPrefix, TLeadingZero, Case::value>
			::format(n, result);
		return result;
	}

	template <typename T>
	inline static R& format(T n, R& result)
	{
		typedef typename std::make_unsigned<T>::type unsigned_T;
		StringifierImpl<unsigned_T, R, TPrefix, TLeadingZero, Case::value>
			::format(n, result);
		return result;
	}

	template <typename T>
	static inline R format(T* n)
	{
		R result;
		StringifierImpl<quintptr, R, TPrefix, TLeadingZero, Case::value>
			::format(reinterpret_cast<quintptr>(n), result);
		return result;
	}

	template <typename T>
	inline static R& format(T* n, R& result)
	{
		StringifierImpl<quintptr, R, TPrefix, TLeadingZero, Case::value>
			::format(reinterpret_cast<quintptr>(n), result);
		return result;
	}
};

} // namespace PrivateHex

#endif // Q_QDOC

namespace Static
{

template <
	typename LeadingZero /* = WithoutLeadingZero */,
	typename PrefixType /* = WithoutPrefix */,
	typename Case /* = LowerCase */>
struct Stringifier<HexBase, LeadingZero, PrefixType, Case>
{
	template <typename T>
	static inline QByteArray format(T n)
	{
		return PrivateHex::Stringifier<
			QByteArray, PrefixType, LeadingZero, Case>::format(n);
	}

	template <typename T>
	static inline QByteArray& format(T n, QByteArray& result)
	{
		return PrivateHex::Stringifier<
			QByteArray, PrefixType, LeadingZero, Case>::format(n, result);
	}

	template <typename T>
	static inline QString& format(T n, QString& result)
	{
		return PrivateHex::Stringifier<
			QString, PrefixType, LeadingZero, Case>::format(n, result);
	}
};

typedef Stringifier<
		HexBase,
		WithLeadingZero,
		WithPrefix,
		LowerCase> AddressStringifier;

} // namespace Static

} // namespace Qpe

#endif // TOOLS_STRINGIFIER_STATIC_STRINGIFIER_HEX_H

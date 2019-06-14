#ifndef TOOLS_STRINGIFIER_DIGITSCOUNT_DEC_H
#define TOOLS_STRINGIFIER_DIGITSCOUNT_DEC_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QtGlobal>

#include <Qpe/Core/TypeTraits>

namespace Qpe
{

#ifndef Q_QDOC

namespace PrivateDec
{

struct signed_t { };
struct unsigned_t { };

template <typename, int> struct DecDigitsCount;

template <>
struct DecDigitsCount<unsigned_t, 3>
{
	template <typename N>
	static inline int count(N n)
	{
		return
			n >= 100
				? 3
				: (n >= 10 ? 2 : 1);
	}
};

template <>
struct DecDigitsCount<unsigned_t, 5>
{
	template <typename N>
	static inline int count(N n)
	{
		return
			n < 1000
				? (n < 100
					? (n < 10 ? 1 : 2) : 3)
				: (n < 10000 ? 4 : 5);
	}
};

template <>
struct DecDigitsCount<unsigned_t, 10>
{
	template <typename N>
	static inline int count(N n)
	{
		return
			n < 100000
				? (n < 100
					? (n < 10 ? 1 : 2)
					: (n < 1000 ? 3 : (n < 10000 ? 4 : 5)))
				: (n < 10000000
					? (n < 1000000 ? 6 : 7)
					: (n < 100000000 ? 8 : (n < 1000000000 ? 9 : 10)));
	}
};

template <>
struct DecDigitsCount<unsigned_t, 19>
{
	template <typename N>
	static inline int count(N n)
	{
		return
			n < 10000000000
				? (n < 100000
					? (n < 100
						? (n < 10 ? 1 : 2)
						: (n < 1000 ? 3 : (n < 10000 ? 4 : 5)))
					: (n < 10000000
						? (n < 1000000 ? 6 : 7)
						: (n < 100000000 ? 8 : (n < 1000000000 ? 9 : 10))))
				: (n < 1000000000000000
					? (n < 1000000000000
						? (n < 100000000000 ? 11 : 12)
						: (n < 10000000000000 ? 13 : (n < 100000000000000 ? 14 : 15)))
					: (n < 100000000000000000
						? (n < 10000000000000000 ? 16 : 17)
						: (n < 1000000000000000000 ? 18 : 19)));
	}
};

template <>
struct DecDigitsCount<unsigned_t, 20>
{
	template <typename N>
	static inline int count(N n)
	{
		const N i_1e19 = 1e19;
		return
			n < 10000000000
				? (n < 100000
					? (n < 100
						? (n < 10 ? 1 : 2)
						: (n < 1000 ? 3 : (n < 10000 ? 4 : 5)))
					: (n < 10000000
						? (n < 1000000 ? 6 : 7)
						: (n < 100000000 ? 8 : (n < 1000000000 ? 9 : 10))))
				: (n < 1000000000000000
					? (n < 1000000000000
						? (n < 100000000000 ? 11 : 12)
						: (n < 10000000000000 ? 13 : (n < 100000000000000 ? 14 : 15)))
					: (n < 100000000000000000
						? (n < 10000000000000000 ? 16 : 17)
						: (n < 1000000000000000000 ? 18 : (n < i_1e19 ? 19 : 20))));
	}
};

template <int D>
struct DecDigitsCount<signed_t, D>
{
	template <typename T>
	static inline int count(T x)
	{
		typedef typename std::make_unsigned<T>::type unsigned_type;
		return DecDigitsCount<unsigned_t, D>
			::count(static_cast<unsigned_type>(x < 0 ? -x : x));
	}
};

template <typename T>
struct DecimalDigitsCount
{
	typedef integer_traits<T> traits_T;
	typedef
		typename std::conditional<
			std::is_unsigned<T>::value,
			unsigned_t,
			signed_t
		>::type signed_or_unsigned_type;
	inline static int count(T n)
	{
		return DecDigitsCount<signed_or_unsigned_type, traits_T::Digits10>::count(n);
	}
};

} // namespace PrivateDec

#endif // Q_QDOC

template <typename T>
static inline int decimalDigitsCount(T n)
{
	return PrivateDec::DecimalDigitsCount<T>::count(n);
}

} //  namespace Qpe

#endif // TOOLS_STRINGIFIER_DIGITSCOUNT_DEC_H

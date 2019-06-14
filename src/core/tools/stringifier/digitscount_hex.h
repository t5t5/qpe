#ifndef TOOLS_STRINGIFIER_DIGITSCOUNT_HEX_H
#define TOOLS_STRINGIFIER_DIGITSCOUNT_HEX_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <type_traits>

#include <QtGlobal>

namespace Qpe
{

#ifndef Q_QDOC

namespace PrivateHex
{

template <int> struct HexDigitsCount;

template <>
struct HexDigitsCount<1>
{
	template <typename N>
	static inline int count(N x)
	{
		return x < 0x10 ? 1 : 2;
	}
};

template <>
struct HexDigitsCount<2>
{
	template <typename N>
	static inline int count(N x)
	{
		return
			x < 0x100
				? (x < 0x10 ? 1 : 2)
				: (x < 0x1000 ? 3 : 4);
	}
};

template <>
struct HexDigitsCount<4>
{
	template <typename N>
	static inline int count(N x)
	{
		return
			x < 0x10000
				? (x < 0x100
					? (x < 0x10 ? 1 : 2)
					: (x < 0x1000 ? 3 : 4))
				: (x < 0x1000000
					? (x < 0x100000 ? 5 : 6)
					: (x < 0x10000000 ? 7 : 8));
	}
};

template <>
struct HexDigitsCount<8>
{
	template <typename N>
	static inline int count(N x)
	{
		return
			x < 0x100000000
				? (x < 0x10000
					? (x < 0x100
						? (x < 0x10 ? 1 : 2)
						: (x < 0x1000 ? 3 : 4))
					: (x < 0x1000000
						? (x < 0x100000 ? 5 : 6)
						: (x < 0x10000000 ? 7 : 8)))
				: (x < 0x1000000000000
					? (x < 0x10000000000
						? (x < 0x1000000000 ? 9 : 10)
						: (x < 0x100000000000 ? 11 : 12))
					: (x < 0x100000000000000
						? (x < 0x10000000000000 ? 13 : 14)
						: (x < 0x1000000000000000 ? 15 : 16)));
	}
};

} // namespace PrivateHex

#endif // Q_QDOC

template <typename T>
int hexadecimalDigitsCount(T x)
{
	typedef typename std::make_unsigned<T>::type unsigned_type;
	return PrivateHex::HexDigitsCount<sizeof(T)>::count(static_cast<unsigned_type>(x));
}

} //  namespace Qpe

#endif // TOOLS_STRINGIFIER_DIGITSCOUNT_HEX_H

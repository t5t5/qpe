#ifndef GLOBAL_QPETYPETRAITS_H
#define GLOBAL_QPETYPETRAITS_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <type_traits>
#include <utility>
#include <limits.h>

#include <Qpe/Core/mpl/math_power>
#include <Qpe/Core/Math>

namespace Qpe
{

template <bool B, class T = void>
using enable_if_t = typename std::enable_if<B, T>::type;

template <bool B, class T, class F>
using conditional_t = typename std::conditional<B, T, F>::type;

template <typename T, T V>
struct integral_identity { typedef integral_identity<T, V> type; };

template <typename T, T V>
using integral_identity_t = typename integral_identity<T, V>::type;

template <typename... TArgs>
struct function_identity
{
	template <typename TReturn>
	struct ret
	{
		template <TReturn (*TPtr)(TArgs...)>
		struct ptr
		{
			typedef ptr<TPtr> type;

			static constexpr bool is_nullptr =
				std::is_same<ptr<TPtr>, ptr<nullptr>>::value;

			static inline TReturn call(TArgs&&... args)
			{
				static_assert(!is_nullptr, "Function pointer is null.");
				return (*TPtr)(std::forward<TArgs>(args)...);
			}
		};
	};

	template <void (*TPtr)(TArgs...)>
	struct ptr : ret<void>::template ptr<TPtr> { };
};

template <typename T>
struct integer_traits
{
	typedef T type;

	typedef typename std::make_signed<T>::type signed_type;
	typedef typename std::make_unsigned<T>::type unsigned_type;

	static const bool IsSigned = std::is_signed<T>::value;

	static const int SizeInBytes = sizeof(T);
	static const int SizeInBits = SizeInBytes * CHAR_BIT;

	static const int Digits2 = SizeInBits - IsSigned;
	static const int Digits10 = math::ceil(Digits2 / math::Log10Base2);
	static const T MaxDecimal = mpl::math::power<10, Digits10 - 1, T>::value;
};

} // namespace Qpe

#endif // GLOBAL_QPETYPETRAITS_H

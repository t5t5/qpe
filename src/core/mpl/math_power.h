#ifndef MPL_MATH_POWER_H
#define MPL_MATH_POWER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace Qpe
{

namespace mpl
{

namespace math
{

template <int Base, int Exp, typename RT = unsigned int>
struct power
{
	static constexpr RT value = Base * power<Base, Exp - 1, RT>::value;
};

template <int Base, typename RT>
struct power<Base, 0, RT>
{
	static constexpr RT value = 1;
};

} // namespace math

} // namespace mpl

} // namespace Qpe

#endif // MPL_MATH_POWER_H

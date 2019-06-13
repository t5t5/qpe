#ifndef MATH_MATH_H
#define MATH_MATH_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace Qpe
{

namespace math
{

static const constexpr double Log10Base2 = 3.32192809488736;

template <typename RT = int, typename T>
constexpr RT ceil(T num)
{
	return  ((num - static_cast<RT>(num)) > 0)
		? static_cast<RT>(num) + 1
		: static_cast<RT>(num);
}

} // namespace math

} // namespace Qpe

#endif // MATH_MATH_H

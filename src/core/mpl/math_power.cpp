
/*!
 * \namespace Qpe::mpl
 * \inmodule core
 * \inheaderfile Qpe/mpl/math_power
 * \brief Пространство имен Qpe::mpl.
 *
 * \ingroup mpl
 */

/*!
 * \namespace Qpe::mpl::math
 * \inmodule core
 * \inheaderfile Qpe/mpl/math_power
 * \brief Пространство имен Qpe::mpl::math.
 *
 * \ingroup mpl
 */

/*!
  \class Qpe::mpl::math::power
  \inmodule core
  \brief Вычислить степень числа
  \inheaderfile Qpe/mpl/math_power
  \ingroup mpl

  Обзор:
  \code
  template <
       int Base
      ,int Exp
      ,typename RT = unsigned int>
  struct power
  {
      static constexpr RT value;
  };
  \endcode
  Пример:
  \code
  std::cout << Qpe::mpl::math::power<2, 10>::value; // 1024
  \endcode
 */

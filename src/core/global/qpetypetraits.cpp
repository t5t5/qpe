
/*!
 * \headerfile <Qpe/Core/TypeTraits>
 * \inmodule core
 * \title <Qpe/Core/TypeTraits>
 *
 * \brief Type traits.
 */

/*!
 * \class Qpe::integral_identity
 * \inmodule core
 * \brief Вспомогательный класс для целочисленных типов.
 * \inheaderfile Qpe/Core/TypeTraits
 * \ingroup core
 */

/*!
 * \typedef Qpe::integral_identity::type
 *
 * Синоним для Qpe::integral_identity<typename T, T V>.
 */

/*!
  \class Qpe::function_identity
  \inmodule core
  \brief Вспомогательный класс для описания функции как шаблона.
  \inheaderfile Qpe/Core/TypeTraits
  \ingroup core

  Пример 1:
  \code
  int foo(int a, float* b) { ...; return 1; }

  Qpe::function_identity<int, float*>::ret<int>::ptr<&foo> FooPtr;
  bool is_not_null = !FooPtr::is_nullptr;	// true

  float z = 1;
  int result = FooPtr::call(1, &z); // Ok, result = 1
  \endcode

  Пример 2:
  \code
  Qpe::function_identity<int, float*>::ret<int>::ptr<nullptr> FooPtr;
  bool is_not_null = !FooPtr::is_nullptr;	// false

  float z = 1;
  //FooPtr::call(1, &z); // Compile time error
  \endcode

  Пример 3:
  \code
  void foo(int a, float* b) { ...; return 1; }

  Qpe::function_identity<int, float*>::ptr<&foo> FooPtr;
  bool is_not_null = !FooPtr::is_nullptr;	// true

  float z = 1;
  FooPtr::call(1, &z); // Ok
  \endcode

  Пример 4:
  \code
  void foo(int a, float* b) { ... }
  {
    // неправильное сравнение типов
    typedef Qpe::function_identity<int, float*>::ptr<&foo> F1;
    typedef Qpe::function_identity<int, float*>::ret<void>::ptr<&foo> F2;
    bool b = std::is_same<F1, F2>::value; // false
  }
  {
    // правильное сравнение типов
    typedef Qpe::function_identity<int, float*>::ptr<&foo>::type F1;
    typedef Qpe::function_identity<int, float*>::ret<void>::ptr<&foo>::type F2;
    bool b = std::is_same<F1, F2>::value; // true
  }
  \endcode
 */

/*!
  \class Qpe::integer_traits
  \inmodule core
  \brief Класс для получения дополнительной информации о целочисленных типах.
  \inheaderfile Qpe/Core/TypeTraits
  \ingroup core

  Обзор:
  \code
  template <typename T>
  struct integer_traits
  {
      typedef T type;

      typedef ... signed_type;
      typedef ... unsigned_type;

      static constexpr bool IsSigned;

      static constexpr int SizeInBytes;
      static constexpr int SizeInBits;

      static constexpr int Digits2;
      static constexpr int Digits10;
      static constexpr T MaxDecimal;
  };
  \endcode
 */

/*!
 * \typedef Qpe::integer_traits::type
 *
 * Синоним для входного типа T
 */


/*!
 * \typedef Qpe::integer_traits::signed_type
 *
 * Синоним для std::make_signed<T>::type
 */

/*!
 * \typedef Qpe::integer_traits::unsigned_type
 *
 * Синоним для std::make_unsigned<T>::type
 */

/*!
 * \variable Qpe::integer_traits::IsSigned
 * \brief true - знаковый тип, false - беззнаковый.
 */

/*!
 * \variable Qpe::integer_traits::SizeInBytes
 * \brief Размер числа в байтах.
 */

/*!
 * \variable Qpe::integer_traits::SizeInBits
 * \brief Размер числа в битах.
 */

/*!
 * \variable Qpe::integer_traits::Digits2
 * \brief Количество битовых разрядов числа, исключая знаковый разряд.
 */

/*!
 * \variable Qpe::integer_traits::Digits10
 * \brief Количество десятичных цифр в числе (без знака).
 */

/*!
 * \variable Qpe::integer_traits::MaxDecimal
 * \brief Максимальное число 10^n которое можно вписать в тип T.
 */

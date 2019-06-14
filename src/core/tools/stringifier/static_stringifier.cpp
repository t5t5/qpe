
/*!
 * \namespace Qpe::Static
 * \inmodule core
 * \inheaderfile Qpe/Core/StaticStringifier
 * \brief Пространство имен Qpe::Static
 *
 * \ingroup core
 */

/*!
 * \variable Qpe::DecBase
 * \brief Вспомогательная константа для Qpe::Static::Stringifier.
 */

/*!
 * \variable Qpe::DecBase2Digits
 * \brief Вспомогательная константа для Qpe::Static::Stringifier.
 */

/*!
 * \variable Qpe::DecBase3Digits
 * \brief Вспомогательная константа для Qpe::Static::Stringifier.
 */


/*!
 * \variable Qpe::DecBase4Digits
 * \brief Вспомогательная константа для Qpe::Static::Stringifier.
 */


/*!
 * \variable Qpe::HexBase
 * \brief Вспомогательная константа для Qpe::Static::Stringifier.
 */

/*!
 * \class Qpe::WithLeadingZero
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
 * \class Qpe::WithoutLeadingZero
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
 * \class Qpe::WithPrefix
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
 * \class Qpe::WithoutPrefix
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
 * \class Qpe::UpperCase
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
 * \class Qpe::LowerCase
 * \inmodule core
 * \brief Вспомогательный класс для Qpe::Static::Stringifier.
 * \inheaderfile Qpe/Core/StaticStringifier
 * \ingroup core
 */

/*!
  \class Qpe::Static::Stringifier
  \inmodule core
  \brief Статический класс для преобразования числа в строку.
  \inheaderfile Qpe/Core/StaticStringifier
  \ingroup core

  Обзор:
  \code
  template <
       int Base
      ,typename LeadingZero = WithoutLeadingZero
      ,typename Prefix = WithoutPrefix
      ,typename Case = LowerCase>
  struct Stringifier
  {
      template <typename T>
      static inline QByteArray format(T n) { }

      template <typename T>
      static inline QByteArray& format(T n, QByteArray& result) { }

      template <typename T>
      static inline QString& format(T n, QString& result) { }
  };
  \endcode
  где:
  \list
    \li \b Base - база системы счисления, может принимать следующие значения:
      \list
        \li DecBase - преобразовать в десятичную систему счисления (СС);
        \li DecBase2Digits - преобразовать в десятичную СС и оставить последние 2 цифры (\b LeadingZero - игнорируется);
        \li DecBase3Digits - преобразовать в десятичную СС и оставить последние 3 цифры (\b LeadingZero - игнорируется);
        \li DecBase4Digits - преобразовать в десятичную СС и оставить последние 4 цифры (\b LeadingZero - игнорируется);
        \li HexBase - преобразовать в шестнадцатeричную СС;
      \endlist
    \li \b LeadingZero - ведущие нули, может принимать следующие значение:
      \list
        \li WithLeadingZero - добавить ведущие нули;
        \li WithoutLeadingZero - не добавлять ведущие нули;
      \endlist
    \li \b Prefix - префикс, может принимать следующие значения:
      \list
        \li WithPrefix - добавить префикс (для HexBase - 0x);
        \li WithoutPrefix - не добавлять префикс;
      \endlist
    \li \b Case - регистр цифр (для HexBase), может принимать следующие значения:
	  \list
        \li UpperCase - цифры в верхнем регистре;
        \li LowerCase - цифры в нижнем регистре.
      \endlist
  \endlist

  Пример:
  \code
  Static::Stringifier<HexBase, WithLeadingZero, WithPrefix, UpperCase> s;

  int number = 123456;
  qDebug() << s.format(number); // 0x0001e240
  \endcode
 */

/*!
 * \fn QByteArray Qpe::Static::Stringifier::format(T n)
 * Преобразовать число \a n в строку.
 */

/*!
 * \fn QByteArray& Qpe::Static::Stringifier::format(T n, QByteArray& result)
 * Преобразовать число \a n в строку. Результат сохранить в \a result.
 */

/*!
 * \fn QString& Qpe::Static::Stringifier::format(T n, QString& result)
 * Преобразовать число \a n в строку. Результат сохранить в \a result.
 */

/*!
 * \typedef Qpe::Static::AddressStringifier
 *
 * Синоним для Qpe::Static::Stringifier<HexBase, WithLeadingZero, WithPrefix, LowerCase>.
 */

/*!
 * \typedef Qpe::Static::DecStringifier
 *
 * Синоним для Qpe::Static::Stringifier<DecBase>.
 */


/*!
  \class Qpe::Enum
  \inmodule core
  \brief Обертка для \c enum
  \inheaderfile Qpe/Core/Enum
  \ingroup core
 
  \sa Qpe::Flag

  Обзор:
  \code
  template <typename TValue, TKey>
  class Enum
  {
      ...
  };
  \endcode
  где:
  \list
     \li TValue - enum
	 \li TKey - строковой тип (QByteArray или QString)
  \endlist
 */

/*!
 * \fn Qpe::Enum::Enum(TValue e)
 * Конструктор. \a e - значения перечисления для инициализации.
 */

/*!
 * \fn Qpe::Enum::Enum(int e)
 * Конструктор. \a e - значение для инициализации, будет сконвертировано в
 * TValue и проверено на принадлежность перечислению.
 */

/*!
 * \fn Qpe::Enum::Enum(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue и проверено на принадлежность перечислению.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn Qpe::Enum::Enum(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue и проверено на принадлежность перечислению.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 * Если \a key не будет распознано, в качестве значения будет использовано
 * \a defaultValue.
 */

/*!
 * \fn TKey Qpe::Enum::key() const
 * Получить строковое представления значения хранящегося в Enum.
 */

/*!
 * \fn TKey Qpe::Enum::value() const
 * Получить значение хранящееся в Enum.
 */

/*!
  \fn void Qpe::Enum::setValue()
  Шаблонная функция установки значения.

  Обзор:
  \code
  template <TValue e>
  void Enum::setValue();
  \endcode
 */

/*!
 * \fn void Qpe::Enum::setValue(TValue e)
 * Установить значение в \a e.
 */

/*!
 * \fn bool Qpe::Enum::isValid() const
 * Вернуть \c true, если значение пренадлежит перечислению.
 */

/*!
 * \fn bool Qpe::Enum::isEmpty() const
 * Вернуть \c true, если значение не пренадлежит перечислению.
 */

/*!
 * \fn TKey Qpe::Enum::valueToKey(TValue e)
 * Вернуть строковое предсталение для значения \a e.
 */

/*!
 * \fn QVector<TValue> Qpe::Enum::values()
 * Вернуть все возможные значения перечисления.
 */

/*!
 * \fn QVector<TKey> Qpe::Enum::keys()
 * Вернуть все возможные строковые значения перечисления.
 */

/*!
  \fn bool Qpe::Enum::in(T e) const
  Проверить принадлежит ли значение перечисления значению \a e.
  Тип T должен соответствовать TValue.

  Обзор:
  \code
  template <typename T>
  bool Qpe::Enum::in(T e) const;
  \endcode
 */

/*!
  \fn bool Qpe::Enum::in(T e, TN... en) const
  Проверить принадлежит ли значение перечисления значениям \a e и остальным \a en.
  Типы T и TN... должны соответствовать TValue.

  Обзор:
  \code
  template <typename T, typename... TN>
  bool Qpe::Enum::in(T e, TN... en) const
  \endcode
 */

/*!
 * \fn Enum& Qpe::Enum::operator=(TValue e)
 * Присвоить текущему перечислению значениче \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn bool Qpe::Enum::operator==(const Enum& e) const
 * Сравнить значение текущего перечисления с другим \a e.
 * Вернуть \c true если равны.
 */

/*!
 * \fn bool Qpe::Enum::operator==(TValue e) const
 * Сравнить значение текущего перечисления со значением \a e.
 * Вернуть \c true если равны.
 */

/*!
 * \fn bool Qpe::Enum::operator!=(const Enum& e) const
 * Сравнить значение текущего перечисления с другим \a e.
 * Вернуть \c true если не равны.
 */

/*!
 * \fn bool Qpe::Enum::operator!=(TValue e) const
 * Сравнить значение текущего перечисления со значением \a e.
 * Вернуть \c true если не равны.
 */

// ------------------------------------------------------------------------

/*!
  \class Qpe::Flag
  \inmodule core
  \brief Обертка для \c enum, который содержит флаговые значения.
  \inheaderfile Qpe/Core/Enum
  \ingroup core

  \sa Qpe::Enum

  Обзор:
  \code
  template <typename TValue, TKey>
  class Flag
  {
      ...
  };
  \endcode
  где:
  \list
     \li TValue - enum
	 \li TKey - строковой тип (QByteArray или QString)
  \endlist
 */

/*!
 * \typedef Qpe::Flag::mask_type
 *
 * Тип лежащий в основе enum. Тип, которые может вместить все значения флага.
 */

/*!
 * \fn Qpe::Flag::Flag(TValue e)
 * Конструктор. \a e - значения перечисления для инициализации.
 */

/*!
 * \fn Qpe::Flag::Flag(mask_type e)
 * Конструктор. \a e - значения нескольких флагов для инициализации.
 */

/*!
 * \fn Qpe::Flag::Flag(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn Qpe::Flag::Flag(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 * Если \a key не будет распознано, в качестве значения будет использовано
 * \a defaultValue.
 */

/*!
 * \fn Qpe::Flag::Flag(const QVector<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a keys - список строковых значений для инициализации,
 * каждое значение будет сконвертировано в TValue и объеденено в одно.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn Qpe::Flag::Flag(const QList<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a keys - список строковых значений для инициализации,
 * каждое значение будет сконвертировано в TValue и объеденено в одно.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn mask_type Qpe::Flag::mask()
 * Маска объеденяющая все возможные значения флагов.
 */

/*!
 * \fn mask_type Qpe::Flag::value() const
 * Значения флагов.
 */

/*!
  \fn void Qpe::Flag::setValue()
  Шаблонная функция установки значения.

  Обзор:
  \code
  template <TValue e>
  void Qpe::Flag::setValue()
  \endcode
 */

/*!
 * \fn void Qpe::Flag::setValue(TValue e)
 * Установить значение в \a e.
 */

/*!
 * \fn void Qpe::Flag::setValue(mask_type e)
 * Установить значение в \a e.
 */

/*!
 * \fn bool Qpe::Flag::isValid() const
 * Вернуть \c true, если значение пренадлежит одному или нескольким флагам.
 *
 * Сравнивает по "and" значение с маской.
 */

/*!
 * \fn bool Qpe::Flag::isEmpty() const
 * Вернуть \c true, если значение = 0.
 */

/*!
 * \fn QVector<TKey> Qpe::Flag::keys() const
 * Вернуть все строковые значения соответствующие текущему значению.
 */

/*!
 * \fn TKey Qpe::Flag::valueToKey(TValue e)
 * Вернуть строковое предсталение для значения \a e.
 */

/*!
 * \fn QVector<TKey> Qpe::Flag::valueToKeys(mask_type e)
 * Вернуть строковые предсталения для значений \a e.
 */

/*!
 * \fn QVector<TValue> Qpe::Flag::values()
 * Вернуть все возможные значения перечисления.
 */

/*!
 * \fn QVector<TKey> Qpe::Flag::allKeys()
 * Вернуть все возможные строковые значения перечисления.
 */

/*!
 * \fn bool Qpe::Flag::test(TValue e) const
 * Вернуть \c true, если флаг \a e в текущем перечислении включен.
 */

/*!
 * \fn bool Qpe::Flag::test(const Flag& e) const
 * Вернуть \c true, если флаги \e в текущем перечислении включены.
 */

/*!
 * \fn Qpe::Flag::operator mask_type() const
 * Вернуть текущее значение всех флагов.
 */

/*!
 * \fn Flag& Qpe::Flag::operator=(TValue e)
 * Присвоить текущему перечислению значениче \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator=(mask_type e)
 * Присвоить текущему перечислению значениче \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator&=(const Flag& e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator&=(TValue e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator&=(mask_type e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator|=(const Flag& e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator|=(TValue e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator|=(mask_type e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator^=(const Flag& e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator^=(TValue e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag& Qpe::Flag::operator^=(mask_type e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator|(const Flag& e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator|(TValue e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator|(mask_type e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator^(const Flag& e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator^(TValue e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator^(mask_type e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator&(const Flag& e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator&(TValue e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator&(mask_type e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn Flag Qpe::Flag::operator~() const
 * "NOT" для значений перечисления и вернуть новое перечисление.
 */


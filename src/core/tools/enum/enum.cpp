
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
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum()
 * Конструктор. Конструируется объект с невалидным значение.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(TValue e)
 * Конструктор. \a e - значения перечисления для инициализации.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(int e)
 * Конструктор. \a e - значение для инициализации, будет сконвертировано в
 * TValue и проверено на принадлежность перечислению.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue и проверено на принадлежность перечислению.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue и проверено на принадлежность перечислению.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 * Если \a key не будет распознано, в качестве значения будет использовано
 * \a defaultValue.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(const Enum& o)
 * Сконструировать объект из \a o.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Enum<TValue, TKey>::Enum(Enum&& o)
 * Конструктор перемещения из \a o.
 */

/*!
 * \fn template <typename TValue, typename TKey> TKey Qpe::Enum<TValue, TKey>::key() const
 * Получить строковое представления значения хранящегося в Enum.
 */

/*!
 * \fn template <typename TValue, typename TKey> TKey Qpe::Enum<TValue, TKey>::value() const
 * Получить значение хранящееся в Enum.
 */

/*!
  \fn template <typename TValue, typename TKey> void Qpe::Enum<TValue, TKey>::setValue()
  Шаблонная функция установки значения.

  Обзор:
  \code
  template <TValue e>
  void Enum::setValue();
  \endcode
 */

/*!
 * \fn template <typename TValue, typename TKey> void Qpe::Enum<TValue, TKey>::setValue(TValue e)
 * Установить значение в \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Enum<TValue, TKey>::isValid() const
 * Вернуть \c true, если значение пренадлежит перечислению.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Enum<TValue, TKey>::isEmpty() const
 * Вернуть \c true, если значение не пренадлежит перечислению.
 */

/*!
 * \fn template <typename TValue, typename TKey> TKey Qpe::Enum<TValue, TKey>::valueToKey(TValue e)
 * Вернуть строковое предсталение для значения \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TValue> Qpe::Enum<TValue, TKey>::values()
 * Вернуть все возможные значения перечисления.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TKey> Qpe::Enum<TValue, TKey>::keys()
 * Вернуть все возможные строковые значения перечисления.
 */

/*!
  \fn template <typename TValue, typename TKey> template <typename T> bool Qpe::Enum<TValue, TKey>::in(T e) const
  Проверить принадлежит ли значение перечисления значению \a e.
  Тип T должен соответствовать TValue.

  Обзор:
  \code
  template <typename T>
  bool Qpe::Enum::in(T e) const;
  \endcode
 */

/*!
  \fn template <typename TValue, typename TKey> template <typename T, typename... TN> bool Qpe::Enum<TValue, TKey>::in(T e, TN... en) const
  Проверить принадлежит ли значение перечисления значениям \a e и остальным \a en.
  Типы T и TN... должны соответствовать TValue.

  Обзор:
  \code
  template <typename T, typename... TN>
  bool Qpe::Enum::in(T e, TN... en) const
  \endcode
 */

/*!
 * \fn template <typename TValue, typename TKey> Enum& Qpe::Enum<TValue, TKey>::operator=(TValue e)
 * Присвоить текущему перечислению значениче \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Enum& Qpe::Enum<TValue, TKey>::operator=(const Enum& e)
 * Присвоить текущему перечислению значение \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> Enum& Qpe::Enum<TValue, TKey>::operator=(Enum&& e)
 * Конструктор перемещения Enum из \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Enum<TValue, TKey>::operator==(const Enum& e) const
 * Сравнить значение текущего перечисления с другим \a e.
 * Вернуть \c true если равны.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Enum<TValue, TKey>::operator==(TValue e) const
 * Сравнить значение текущего перечисления со значением \a e.
 * Вернуть \c true если равны.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Enum<TValue, TKey>::operator!=(const Enum& e) const
 * Сравнить значение текущего перечисления с другим \a e.
 * Вернуть \c true если не равны.
 */

/*!
 * \fn template <typename TValue, typename TKey>bool Qpe::Enum<TValue, TKey>::operator!=(TValue e) const
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
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag()
 * Сконструировать пустой объект.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(TValue e)
 * Конструктор. \a e - значения перечисления для инициализации.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(mask_type e)
 * Конструктор. \a e - значения нескольких флагов для инициализации.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a key - строковое значение для инициализации,
 * будет сконвертировано в TValue.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 * Если \a key не будет распознано, в качестве значения будет использовано
 * \a defaultValue.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(const QVector<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a keys - список строковых значений для инициализации,
 * каждое значение будет сконвертировано в TValue и объеденено в одно.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(const QList<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
 * Конструктор. \a keys - список строковых значений для инициализации,
 * каждое значение будет сконвертировано в TValue и объеденено в одно.
 * Если \a cs - Qt::CaseSensitive, будет использоваться регистрозависимое сравнение,
 * иначе будет использоваться регистронезависимое сравнение.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(const Flag& o)
 * Сконструировать объект из \a o.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::Flag(Flag&& o)
 * Конструктор перемещения из \a o.
 */

/*!
 * \fn template <typename TValue, typename TKey> mask_type Qpe::Flag<TValue, TKey>::mask()
 * Маска объеденяющая все возможные значения флагов.
 */

/*!
 * \fn template <typename TValue, typename TKey> mask_type Qpe::Flag<TValue, TKey>::value() const
 * Значения флагов.
 */

/*!
  \fn template <typename TValue, typename TKey> template <TValue e> void Qpe::Flag<TValue, TKey>::setValue()
  Шаблонная функция установки значения.

  Обзор:
  \code
  template <TValue e>
  void Qpe::Flag::setValue()
  \endcode
 */

/*!
 * \fn template <typename TValue, typename TKey> void Qpe::Flag<TValue, TKey>::setValue(TValue e)
 * Установить значение в \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> void Qpe::Flag<TValue, TKey>::setValue(mask_type e)
 * Установить значение в \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Flag<TValue, TKey>::isValid() const
 * Вернуть \c true, если значение пренадлежит одному или нескольким флагам.
 *
 * Сравнивает по "and" значение с маской.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Flag<TValue, TKey>::isEmpty() const
 * Вернуть \c true, если значение = 0.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TKey> Qpe::Flag<TValue, TKey>::keys() const
 * Вернуть все строковые значения соответствующие текущему значению.
 */

/*!
 * \fn template <typename TValue, typename TKey> TKey Qpe::Flag<TValue, TKey>::valueToKey(TValue e)
 * Вернуть строковое предсталение для значения \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TKey> Qpe::Flag<TValue, TKey>::valueToKeys(mask_type e)
 * Вернуть строковые предсталения для значений \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TValue> Qpe::Flag<TValue, TKey>::values()
 * Вернуть все возможные значения перечисления.
 */

/*!
 * \fn template <typename TValue, typename TKey> QVector<TKey> Qpe::Flag<TValue, TKey>::allKeys()
 * Вернуть все возможные строковые значения перечисления.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Flag<TValue, TKey>::test(TValue e) const
 * Вернуть \c true, если флаг \a e в текущем перечислении включен.
 */

/*!
 * \fn template <typename TValue, typename TKey> bool Qpe::Flag<TValue, TKey>::test(const Flag& e) const
 * Вернуть \c true, если флаги \e в текущем перечислении включены.
 */

/*!
 * \fn template <typename TValue, typename TKey> Qpe::Flag<TValue, TKey>::operator mask_type() const
 * Вернуть текущее значение всех флагов.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator=(const Flag& e)
 * Присвоить текущему Flag значение \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator=(Flag&& e)
 * Конструктор перемещения Flag из \a e.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator=(TValue e)
 * Присвоить текущему перечислению значение \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator=(mask_type e)
 * Присвоить текущему перечислению значениче \a e, и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator&=(const Flag& e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator&=(TValue e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator&=(mask_type e)
 * Объеденить по "AND" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator|=(const Flag& e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator|=(TValue e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator|=(mask_type e)
 * Объеденить по "OR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator^=(const Flag& e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator^=(TValue e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag& Qpe::Flag<TValue, TKey>::operator^=(mask_type e)
 * Объеденить по "XOR" текущее значение со значением \a e и вернуть ссылку на
 * текущее перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator|(const Flag& e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator|(TValue e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator|(mask_type e) const
 * Объеденить по "OR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator^(const Flag& e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator^(TValue e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator^(mask_type e) const
 * Объеденить о "XOR" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator&(const Flag& e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator&(TValue e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator&(mask_type e) const
 * Объеденить о "AND" текущее значение со значением \a e и вернуть
 * новое перечисление.
 */

/*!
 * \fn template <typename TValue, typename TKey> Flag Qpe::Flag<TValue, TKey>::operator~() const
 * "NOT" для значений перечисления и вернуть новое перечисление.
 */


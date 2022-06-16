
/*!
 * \headerfile <Qpe/Core/Algorithm>
 * \inmodule core
 * \title <Qpe/Core/Algorithm>
 *
 * \brief
 */

/*!
 * \namespace Qpe::Map
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Пространство имен Map.
 *
 * \ingroup core
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Map::find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в map'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TMap> bool Qpe::Map::find_result<TMap>::operator!() const
 * Возвращает \c true, если ключ не найден.
 */

/*!
 * \fn template <typename TMap> Qpe::Map::find_result<TMap>::operator bool() const
 * Возвращает \c true, если ключ найден.
 */

/*!
 * \fn template <typename TMap> template <typename T> T& Qpe::Map::find_result<TMap>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T> T* Qpe::Map::find_result<TMap>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T, typename... Args> T& Qpe::Map::find_result<TMap>::create(Args&&... args)
 * Если ключ не был найден, создать элемент. \a args - данные для вызова конструктора
 * элемента. Вернуть ссылку на вставленный элемент.
 */

/*!
 * \fn template <typename TMap> template <typename T> bool Qpe::Map::find_result<TMap>::insert(T&& value)
 * Если ключ не был найден, вставить элемент \a value.
 */

/*!
 * \fn template <typename TMap> template <typename T, typename K> bool Qpe::Map::find_result<TMap>::insert(K&& key, T&& value)
 * Если ключ не был найден, вставить элемент \a value, с ключом \a key.
 */

/*!
 * \fn template <typename TMap> void Qpe::Map::find_result<TMap>::erase()
 * Удалить найденный элемент. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Map::find_if_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска по предикату в map'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TMap> bool Qpe::Map::find_if_result<TMap>::operator!() const
 * Возвращает \c true, если ключ не найден.
 */

/*!
 * \fn template <typename TMap> Qpe::Map::find_if_result<TMap>::operator bool() const
 * Возвращает \c true, если ключ найден.
 */

/*!
 * \fn template <typename TMap> template <typename T> T& Qpe::Map::find_if_result<TMap>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T> T* Qpe::Map::find_if_result<TMap>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T, typename K> bool Qpe::Map::find_if_result<TMap>::insert(K&& key, T&& value)
 * Если ключ не был найден, вставить элемент \a value, с ключом \a key.
 */

/*!
 * \fn template <typename TMap> void Qpe::Map::find_if_result<TMap>::erase()
 * Удалить найденный элемент. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Map::const_find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в map'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TMap> bool Qpe::Map::const_find_result<TMap>::operator!() const
 * Возвращает \c true, если ключ не найден.
 */

/*!
 * \fn template <typename TMap> Qpe::Map::const_find_result<TMap>::operator bool() const
 * Возвращает \c true, если ключ найден.
 */

/*!
 * \fn template <typename TMap> template <typename T> const T& Qpe::Map::const_find_result<TMap>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T> const T* Qpe::Map::const_find_result<TMap>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Map::const_find_if_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска по предикату в map'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TMap> bool Qpe::Map::const_find_if_result<TMap>::operator!() const
 * Возвращает \c true, если ключ не найден.
 */

/*!
 * \fn template <typename TMap> Qpe::Map::const_find_if_result<TMap>::operator bool() const
 * Возвращает \c true, если ключ найден.
 */

/*!
 * \fn template <typename TMap> template <typename T> const T& Qpe::Map::const_find_if_result<TMap>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TMap> template <typename T> const T* Qpe::Map::const_find_if_result<TMap>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \fn template <typename TMap, typename K> Qpe::Map::find_result<TMap> Qpe::Map::find(TMap& map, const K& key)
 * Найти ключ \a key в \a map. Вернуть результат поиска \c Qpe::Map::find_result<TMap>.
 */

/*!
 * \fn template <typename TMap, typename K> Qpe::Map::const_find_result<TMap> Qpe::Map::find(const TMap& map, const K& key)
 * \overload
 * Найти ключ \a key в \a map. Вернуть результат поиска \c Qpe::Map::const_find_result<TMap>.
 */

/*!
 * \fn template <typename TMap, typename K> Qpe::Map::const_find_result<TMap> Qpe::Map::const_find(const TMap& map, const K& key)
 * Найти ключ \a key в \a map. Вернуть результат поиска \c Qpe::Map::const_find_result<TMap>.
 */

// ------------------------------------------------------------------------

/*!
 * \fn template <typename TMap, typename Function> Qpe::Map::find_if_result<TMap> Qpe::Map::find_if(TMap& map, Function&& function)
 * Найти в \a map для которого предикат \a function возвращает \c true.
 * Вернуть результат поиска \c Qpe::Map::find_result<TMap>.
 */

/*!
 * \fn template <typename TMap, typename Function> Qpe::Map::const_find_if_result<TMap> Qpe::Map::find_if(const TMap& map, Function&& function)
 * \overload
 * Найти в \a map для которого предикат \a function возвращает \c true.
 * Вернуть результат поиска \c Qpe::Map::const_find_result<TMap>.
 */

/*!
 * \fn template <typename TMap, typename Function> Qpe::Map::const_find_if_result<TMap> Qpe::Map::const_find_if(const TMap& map, Function&& function)
 * Найти в \a map для которого предикат \a function возвращает \c true.
 * Вернуть результат поиска \c Qpe::Map::const_find_result<TMap>.
 */

// ------------------------------------------------------------------------

/*!
 * \fn template <typename TMap, typename K> bool Qpe::Map::contains(const TMap& map, const K& key)
 * Проверить наличие ключа \a key в \a map. Вернуть \c true, если ключ существует.
 */

/*!
 * \fn template <typename TMap, typename Function> bool Qpe::Map::contains_if(const TMap& map, Function&& function)
 * Проверить наличие в \a map объекта, для которого предикат \a function возвращает \c true.
 */

// ========================================================================

/*!
 * \fn template <typename TMap, typename Function> Function Qpe::Map::for_each(TMap& map, Function f)
 * Аналог std::for_each для \a map.
 *
 * Для всех пар \a map вызвать функцию \a f.
 *
 * Пример кода:
 * \code
 * 		QMap<int, QString> map;
 * 		Qpe::Map::for_each(map, [] (const int& k, int& t) { ++t; });
 * \endcode
 */

/*!
 * \fn template <typename TMap, typename Function> Function Qpe::Map::for_each(const TMap& map, Function f)
 * \overload
 * Аналог std::for_each для \a map.
 *
 * Для всех пар \a map вызвать функцию \a f.
 *
 * Пример кода:
 * \code
 * 		QMap<int, QString> map;
 * 		Qpe::Map::for_each(map, [] (const int& k, const int& t) { qDebug() << t; });
 * \endcode
 */
/*!
 * \fn template <typename TMap, typename Function> Function Qpe::Map::const_for_each(const TMap& map, Function f)
 * Аналог std::for_each для \a map.
 *
 * Для всех пар \a map вызвать функцию \a f.
 *
 * Пример кода:
 * \code
 * 		QMap<int, QString> map;
 * 		Qpe::Map::const_for_each(map, [] (const int& k, const int& t) { qDebug() << t; });
 * \endcode
 */

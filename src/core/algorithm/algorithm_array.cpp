
/*
 * \headerfile <Qpe/Core/Algorithm>
 * \inmodule core
 * \title <Qpe/Core/Algorithm>
 *
 * \brief
 */

/*!
 * \namespace Qpe::Array
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Пространство имен Array.
 *
 * \ingroup core
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Array::find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в array'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TArray> bool Qpe::Array::find_result<TArray>::operator!() const
 * Возвращает \c true, если значение не найдено.
 */

/*!
 * \fn template <typename TArray> Qpe::Array::find_result<TArray>::operator bool() const
 * Возвращает \c true, если значение найдено.
 */

/*!
 * \fn template <typename TArray> template <typename T> T& Qpe::Array::find_result<TArray>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> template <typename T> T* Qpe::Array::find_result<TArray>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> template <typename T, typename... Args> T& Qpe::Array::find_result<TArray>::create(Args&&... args)
 * Если значение не было найдено, создать элемент. \a args - данные для
 * вызова конструктора элемента. Вернуть ссылку на вставленный элемент.
 */

/*!
 * \fn template <typename TArray> template <typename T> bool Qpe::Array::find_result<TArray>::insert(const T& value)
 * Если значение не было найдено, вставить элемент \a value.
 */

/*!
 * \fn template <typename TArray> template <typename T> bool Qpe::Array::find_result<TArray>::insert(T&& value)
 * \overload
 * Если значение не было найдено, вставить элемент \a value.
 */

/*!
 * \fn template <typename TArray> void Qpe::Array::find_result<TArray>::erase()
 * Удалить найденный элемент. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Array::const_find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в array'ах.
 * \ingroup core
 */

/*!
 * \fn template <typename TArray> bool Qpe::Array::const_find_result<TArray>::operator!() const
 * Возвращает \c true, если значение не найдено.
 */

/*!
 * \fn template <typename TArray> Qpe::Array::const_find_result<TArray>::operator bool() const
 * Возвращает \c true, если значение найдено.
 */

/*!
 * \fn template <typename TArray> template <typename T> const T& Qpe::Array::const_find_result<TArray>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> template <typename T> const T* Qpe::Array::const_find_result<TArray>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \fn template <typename TArray, typename K> Qpe::Array::find_result<TArray> Qpe::Array::find(TArray& array, const K& value)
 * Найти значение \a value в \a array.
 *
 * Вернуть результат поиска Qpe::Array::find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename K> Qpe::Array::const_find_result<TArray> Qpe::Array::find(const TArray& array, const K& value)
 * \overload
 * Найти значение \a value в \a array.
 *
 * Вернуть результат поиска Qpe::Array::const_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename K> Qpe::Array::const_find_result<TArray> Qpe::Array::const_find(const TArray& array, const K& value)
 * Найти значени \a value в \a array.
 *
 * Вернуть результат поиска Qpe::Array::const_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Func> Qpe::Array::find_result<TArray> Qpe::Array::find_if(TArray& array, Func f)
 * Найти значение с помощью функции \a f в \a array.
 *
 * Вернуть результат поиска Qpe::Array::find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Func> Qpe::Array::const_find_result<TArray> Qpe::Array::find_if(const TArray& array, Func f)
 * \overload
 * Найти значение с помощью функции \a f в \a array.
 * Вернуть результат поиска Qpe::Array::const_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Func> Qpe::Array::const_find_result<TArray> Qpe::Array::const_find_if(const TArray& array, Func f)
 * Найти значение с помощью функции \a f в \a array.
 * Вернуть результат поиска Qpe::Array::const_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename K> bool Qpe::Array::contains(const TArray& array, const K& value)
 * Проверить наличие значения \a value в \a array. Вернуть \c true, если значение существует.
 */

/*!
 * \fn template <typename TArray, typename Func> bool Qpe::Array::contains_if(const TArray& array, Func f)
 * Проверить наличие значения с помощью функции \a f в \a array. Вернуть \c true, если значение существует.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Array::ordered_find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в array'ах отсортированных по возрастанию.
 * \ingroup core
 */

/*!
 * \fn template <typename TArray> bool Qpe::Array::ordered_find_result<TArray>::operator!() const
 * Возвращает \c true, если значение не найдено.
 */

/*!
 * \fn template <typename TArray> Qpe::Array::ordered_find_result<TArray>::operator bool() const
 * Возвращает \c true, если значение найдено.
 */

/*!
 * \fn template <typename TArray> T& Qpe::Array::ordered_find_result<TArray>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> T* Qpe::Array::ordered_find_result<TArray>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> template <typename T, typename... Args> T& Qpe::Array::ordered_find_result<TArray>::create(Args&&... args)
 * Создать элемент. \a args - данные для вызова конструктора. Вернуть ссылку на созданный элемент.
 */

/*!
 * \fn template <typename TArray> template <typename T> bool Qpe::Array::ordered_find_result<TArray>::insert(const T& value)
 * Вставить элемент \a value.
 */

/*!
 * \fn template <typename TArray> template <typename T> bool Qpe::Array::ordered_find_result<TArray>::insert(T&& value)
 * \overload
 * Вставить элемент \a value.
 */

/*!
 * \fn template <typename TArray> void Qpe::Array::ordered_find_result<TArray>::erase()
 * Удалить найденный элемент. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \class Qpe::Array::const_ordered_find_result
 * \inmodule core
 * \inheaderfile Qpe/Core/Algorithm
 * \brief Результат для функций поиска в array'ах отсортированных по возрастанию.
 * \ingroup core
 */

/*!
 * \fn template <typename TArray> bool Qpe::Array::const_ordered_find_result<TArray>::operator!() const
 * Возвращает \c true, если значение не найдено.
 */

/*!
 * \fn template <typename TArray> Qpe::Array::const_ordered_find_result<TArray>::operator bool() const
 * Возвращает \c true, если значение найдено.
 */

/*!
 * \fn template <typename TArray> template <typename T> const T& Qpe::Array::const_ordered_find_result<TArray>::operator*() const
 * Вернуть ссылку на найденное значение. Если значения нет, сработает assert.
 */

/*!
 * \fn template <typename TArray> template <typename T> const T* Qpe::Array::const_ordered_find_result<TArray>::operator->() const
 * Вернуть указатель на найденное значение. Если значения нет, сработает assert.
 */

// ------------------------------------------------------------------------

/*!
 * \fn template <typename TArray, typename Value, typename Compare> Qpe::Array::ordered_find_result<TArray> ordered_find(TArray& array, const Value& value, Compare&& compare)
 * Поиск в упорядоченном по возрастанию массиве \a array значения \a value,
 * используя функцию сравнения \a compare.
 *
 * Вернуть результат поиска Qpe::Array::ordered_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Value> Qpe::Array::ordered_find_result<TArray> ordered_find(TArray& array, const Value& value)
 * \overload
 * Поиск в упорядоченном по возрастанию массиве \a array значения \a value.
 *
 * Вернуть результат поиска Qpe::Array::ordered_find_result<TArray>.
 *
 * \note Для \c Value должен быть определен оператор сравнения меньше "<".
 */

/*!
 * \fn template <typename TArray, typename Value, typename Compare> Qpe::Array::const_ordered_find_result<TArray> const_ordered_find(const TArray& array, const Value& value, Compare&& compare)
 * Поиск в упорядоченном по возрастанию неизменном массиве \a array значения \a value,
 * используя функцию сравнения \a compare.
 *
 * Вернуть результат поиска Qpe::Array::const_ordered_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Value> Qpe::Array::const_ordered_find_result<TArray> const_ordered_find(const TArray& array, const Value& value)
 * \overload
 * Поиск в упорядоченном по возрастанию неизменном массиве \a array значения \a value.
 *
 * Вернуть результат поиска Qpe::Array::const_ordered_find_result<TArray>.
 *
 * \note Для \c Value должен быть определен оператор сравнения меньше "<".
 */

/*!
 * \fn template <typename TArray, typename Value, typename Compare> Qpe::Array::const_ordered_find_result<TArray> ordered_find(const TArray& array, const Value& value, Compare&& compare)
 * \overload
 * Поиск в упорядоченном по возрастанию неизменном массиве \a array значения \a value,
 * используя функцию сравнения \a compare.
 *
 * Вернуть результат поиска Qpe::Array::const_ordered_find_result<TArray>.
 */

/*!
 * \fn template <typename TArray, typename Value> Qpe::Array::const_ordered_find_result<TArray> ordered_find(const TArray& array, const Value& value)
 * \overload
 * Поиск в упорядоченном по возрастанию неизменном массиве \a array значения \a value.
 *
 * Вернуть результат поиска Qpe::Array::const_ordered_find_result<TArray>.
 *
 * \note Для \c Value должен быть определен оператор сравнения меньше "<".
 */

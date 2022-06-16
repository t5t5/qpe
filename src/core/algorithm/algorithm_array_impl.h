#ifndef ALGORITHM_ALGORITHM_ARRAY_IMPL_H
#define ALGORITHM_ALGORITHM_ARRAY_IMPL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <algorithm>

#include <Qpe/Qpe>
#include <Qpe/Core/TypeTraits>

namespace Qpe
{

namespace Array
{

namespace Private
{

template <typename T, template <typename> class TResult>
TResult<T> find(T& data, typename T::iterator);

template <typename Array>
struct find_result;

template <
	typename T,
	template <typename, typename...> class Container,
	typename... D>
struct find_result<Container<T, D...> >
{
	typedef Container<T, D...> data_type;
	typedef find_result<data_type> type;
	typedef T value_type;

	friend type find<>(data_type&, typename data_type::iterator);
protected:
	data_type& data;
	typename data_type::iterator iterator;

	find_result(data_type& d) : data(d) { }
public:
	inline bool operator!() const
	{
		return iterator == data.end();
	}

	inline explicit operator bool() const
	{
		return iterator != data.end();
	}

	value_type& operator*() const
	{
		Q_ASSERT(iterator != data.end());
		return *iterator;
	}

	value_type* operator->() const
	{
		Q_ASSERT(iterator != data.end());
		return &(*iterator);
	}

	template <
		typename... Args,
		enable_if_t<std::is_constructible<T, Args&...>::value> * = nullptr>
	value_type& create(Args&&... args)
	{
		iterator = data.insert(iterator, T(std::forward<Args>(args)...));
		return *iterator;
	}

	bool insert(const T& value)
	{
		iterator = data.insert(iterator, value);
		return iterator != data.end();
	}

	bool insert(T&& value)
	{
		iterator = data.insert(iterator, std::forward<T>(value));
		return iterator != data.end();
	}

	void erase()
	{
		Q_ASSERT(iterator != data.end());
		iterator = data.erase(iterator);
	}
};

template <typename T, template <typename> class TResult>
TResult<T> find(T& data, typename T::iterator iterator)
{
	TResult<T> r(data);
	r.iterator = iterator;
	return r;
}

// ------------------------------------------------------------------------

template <typename T, template <typename> class TResult>
TResult<T> const_find(const T& data, typename T::const_iterator);

template <typename Array>
struct const_find_result;

template <
	typename T,
	template <typename, typename...> class Container,
	typename... D>
struct const_find_result<Container<T, D...> >
{
	typedef Container<T, D...> data_type;
	typedef const_find_result<data_type> type;
	typedef T value_type;

	friend type const_find<>(const data_type&, typename data_type::const_iterator);
protected:
	const data_type& data;
	typename data_type::const_iterator iterator;

	const_find_result(const data_type& d) : data(d) { }
public:
	inline bool operator!() const
	{
		return iterator == data.end();
	}

	inline explicit operator bool() const
	{
		return iterator != data.end();
	}

	const value_type& operator*() const
	{
		Q_ASSERT(iterator != data.end());
		return *iterator;
	}

	const value_type* operator->() const
	{
		Q_ASSERT(iterator != data.end());
		return &(*iterator);
	}
};

template <typename T, template <typename> class TResult>
TResult<T> const_find(const T& data, typename T::const_iterator iterator)
{
	TResult<T> r(data);
	r.iterator = iterator;
	return r;
}

// ------------------------------------------------------------------------

template <typename T, template <typename> class TResult>
TResult<T> ordered_find(T& data, typename T::iterator, bool);

template <typename Array>
struct ordered_find_result;

template <
	typename T,
	template <typename, typename...> class Container,
	typename... D>
struct ordered_find_result<Container<T, D...> >
{
	typedef Container<T, D...> data_type;
	typedef ordered_find_result<data_type> type;
	typedef T value_type;

	friend type ordered_find<>(data_type&, typename data_type::iterator, bool);
protected:
	data_type& data;
	typename data_type::iterator iterator;
	bool found;

	ordered_find_result(data_type& d) : data(d) { }
public:
	inline bool operator!() const { return !found; }

	inline explicit operator bool() const { return found; }

	value_type& operator*() const
	{
		Q_ASSERT(found);
		return *iterator;
	}

	value_type* operator->() const
	{
		Q_ASSERT(found);
		return &(*iterator);
	}

	template <
		typename... Args,
		Qpe::enable_if_t<std::is_constructible<T, Args&...>::value> * = nullptr>
	value_type& create(Args&&... args)
	{
		iterator = data.insert(iterator, T(std::forward<Args>(args)...));
		return *iterator;
	}

	bool insert(const T& value)
	{
		iterator = data.insert(iterator, value);
		return iterator != data.end();
	}

	bool insert(T&& value)
	{
		iterator = data.insert(iterator, std::forward<T>(value));
		return iterator != data.end();
	}

	void erase()
	{
		Q_ASSERT(iterator != data.end());
		iterator = data.erase(iterator);
	}
};

template <typename T, template <typename> class TResult>
TResult<T> ordered_find(T& data, typename T::iterator iterator, bool found)
{
	TResult<T> r(data);
	r.iterator = iterator;
	r.found = found;
	return r;
}

// ------------------------------------------------------------------------

template <typename T, template <typename> class TResult>
TResult<T> const_ordered_find(const T& data, typename T::const_iterator, bool);

template <typename Array>
struct const_ordered_find_result;

template <
	typename T,
	template <typename, typename...> class Container,
	typename... D>
struct const_ordered_find_result<Container<T, D...> >
{
	typedef Container<T, D...> data_type;
	typedef const_ordered_find_result<data_type> type;
	typedef T value_type;

	friend type const_ordered_find<>(
		const data_type&, typename data_type::const_iterator, bool);
protected:
	const data_type& data;
	typename data_type::const_iterator iterator;
	bool found;

	const_ordered_find_result(const data_type& d) : data(d) { }
public:
	inline bool operator!() const { return !found; }

	inline explicit operator bool() const { return found; }

	const value_type& operator*() const
	{
		Q_ASSERT(found);
		return *iterator;
	}

	const value_type* operator->() const
	{
		Q_ASSERT(found);
		return &(*iterator);
	}
};

template <typename T, template <typename> class TResult>
TResult<T> const_ordered_find(
	const T& data, typename T::const_iterator iterator, bool found)
{
	TResult<T> r(data);
	r.iterator = iterator;
	r.found = found;
	return r;
}

// ------------------------------------------------------------------------

template <typename Array, typename V>
struct is_same_array_type : public std::false_type
{
};

template <
	typename T,
	typename V,
	template <typename, typename...> class Container,
	typename... D>
struct is_same_array_type<Container<T, D...>, V>
	: public std::is_same<typename Container<T, D...>::value_type, V>
{
};

} // namespace Private

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::find_result<T> find(T& data, const V& v)
{
	return Private::find<T, Private::find_result>(
		data, std::find(data.begin(), data.end(), v));
}

template <typename T, typename Function>
Private::find_result<T> find_if(T& data, Function&& f)
{
	return Private::find<T, Private::find_result>(
		data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_find_result<T> find(const T& data, const V& v)
{
	return Private::const_find<T, Private::const_find_result>(
		data, std::find(data.begin(), data.end(), v));
}

template <typename T, typename Function>
Private::const_find_result<T> find_if(const T& data, Function&& f)
{
	return Private::const_find<T, Private::const_find_result>(
		data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_find_result<T> const_find(const T& data, const V& v)
{
	return Private::const_find<T, Private::const_find_result>(
		data, std::find(data.begin(), data.end(), v));
}

template <typename T, typename Function>
Private::const_find_result<T> const_find_if(const T& data, Function&& f)
{
	return Private::const_find<T, Private::const_find_result>(
		data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
inline bool contains(const T& data, const V& v)
{
	auto iterator = std::find(data.begin(), data.end(), v);
	return iterator != data.end();
}

template<typename T, typename Function>
inline bool contains_if(const T& data, Function&& f)
{
	auto iterator = std::find_if(data.begin(), data.end(), f);
	return iterator != data.end();
}

// ------------------------------------------------------------------------

template <
	typename T, typename V, typename Compare,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::ordered_find_result<T> ordered_find(
	T& data, const V& v, Compare&& compare)
{
	auto iterator = std::lower_bound(data.begin(), data.end(), v, compare);
	bool found = (iterator != data.end()) && !compare(v, *iterator);
	return Private::ordered_find<T, Private::ordered_find_result>
		(data, iterator, found);
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::ordered_find_result<T> ordered_find(T& data, const V& v)
{
	return ordered_find(data, v, std::less<V>());
}

template <
	typename T, typename V, typename Compare,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_ordered_find_result<T> const_ordered_find(
	const T& data, const V& v, Compare&& compare)
{
	auto iterator = std::lower_bound(data.begin(), data.end(), v, compare);
	bool found = (iterator != data.end()) && !compare(v, *iterator);
	return Private::const_ordered_find<T, Private::const_ordered_find_result>
		(data, iterator, found);
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_ordered_find_result<T> const_ordered_find(const T& data, const V& v)
{
	return const_ordered_find(data, v, std::less<V>());
}

template <
	typename T, typename V, typename Compare,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_ordered_find_result<T> ordered_find(
	const T& data, const V& v, Compare&& compare)
{
	return const_ordered_find(data, v, compare);
}

template <
	typename T, typename V,
	enable_if_t<Private::is_same_array_type<T, V>::value> * = nullptr>
Private::const_ordered_find_result<T> ordered_find(const T& data, const V& v)
{
	return const_ordered_find(data, v, std::less<V>());
}

} // namespace Array

} // namespace Qpe

#endif // Q_QDOC

#endif // ALGORITHM_ALGORITHM_ARRAY_IMPL_H

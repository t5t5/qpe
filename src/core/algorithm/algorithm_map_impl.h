#ifndef ALGORITHM_ALGORITHM_MAP_IMPL_H
#define ALGORITHM_ALGORITHM_MAP_IMPL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <algorithm>

#include <Qpe/Qpe>
#include <Qpe/Core/TypeTraits>

#include <map>
#include <unordered_map>

template <class Key, class T> class QMap;
template <class Key, class T> class QHash;

namespace Qpe
{

namespace Map
{

namespace Private
{

// ------------------------------------------------------------------------
namespace __________find_result_________ { }

template <typename V, typename M>
struct find_result_base;

template <
	typename V,
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct find_result_base<V, Container<K, T, D...> >
{
	typedef Container<K, T, D...> data_type;
	typedef find_result_base<V, data_type> type;
	typedef V value_type;

protected:
	data_type& data;
	typename data_type::iterator iterator;

	find_result_base(data_type& d) : data(d) { }
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
		return iterator.operator->();
	}

	void erase()
	{
		Q_ASSERT(iterator != data.end());
		iterator = data.erase(iterator);
	}
};

template <typename TMap, typename TKey, template <typename> class TResult>
TResult<TMap> find(TMap& data, const TKey& key);

template <typename M>
struct find_result_qt;

template <
	typename K, typename T,
	template <typename, typename> class Container>
struct find_result_qt<Container<K, T> >
	: public find_result_base<T, Container<K, T> >
{
	typedef Container<K, T> data_type;
	typedef find_result_qt<data_type> type;
	typedef find_result_base<T, data_type> super;
	typedef T value_type;

	friend type find<>(data_type& data, const K& key);
protected:
	K key;
public:
	find_result_qt(data_type& d, const K& k) : super(d), key(k) { }

	template <
		typename... Args,
		enable_if_t<std::is_constructible<T, Args&&...>::value> * = nullptr>
	value_type& create(Args&&... args)
	{
		super::iterator = super::data.insert(key, T(std::forward<Args>(args)...));
		return *super::iterator;
	}

	bool insert(T&& value)
	{
		super::iterator = super::data.insert(key, std::forward<T>(value));
		return super::iterator != super::data.end();
	}

	bool insert(K&& k, T&& value)
	{
		super::iterator =
			super::data.insert(std::forward<K>(k), std::forward<T>(value));
		key = k;
		return super::iterator != super::data.end();
	}
};

template <typename M>
struct find_result_std;

template <
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct find_result_std<Container<K, T, D...> >
	: public find_result_base<
		typename Container<K, T, D...>::value_type, Container<K, T, D...> >
{
	typedef Container<K, T, D...> data_type;
	typedef find_result_std<data_type> type;
	typedef find_result_base<typename data_type::value_type, data_type> super;
	typedef typename data_type::value_type value_type;

	friend type find<>(data_type& data, const K& key);
protected:
	K key;
public:
	find_result_std(data_type& d, const K& k) : super(d), key(k) { }

	template <
		typename... Args,
		enable_if_t<std::is_constructible<T, Args&&...>::value> * = nullptr>
	value_type& create(Args&&... args)
	{
		super::iterator = super::data.insert(
			super::iterator, std::make_pair(key, T(std::forward<Args>(args)...)));
		return *super::iterator;
	}

	bool insert(T&& value)
	{
		auto r = super::data.insert(std::make_pair(key, std::forward<T>(value)));
		super::iterator = r.first;
		return r.second;
	}

	bool insert(K&& k, T&& value)
	{
		auto r = super::data.insert(
			std::make_pair(std::forward<K>(k), std::forward<T>(value)));
		super::iterator = r.first;
		key = k;
		return r.second;
	}
};

template <typename TMap, typename TKey, template <typename> class TResult>
TResult<TMap> find(TMap& data, const TKey& key)
{
	typedef TResult<TMap> result_type;
	result_type result(data, key);
	result.iterator = data.find(key);
	return result;
}

// ------------------------------------------------------------------------
namespace __________find_if_result__________ { }

template <
	typename TMap,
	template <typename> class TResult>
TResult<TMap> find_if(TMap& data, typename TMap::iterator iterator);

template <typename M>
struct find_if_result_qt;

template <
	typename K, typename T,
	template <typename, typename> class Container>
struct find_if_result_qt<Container<K, T>>
	: public find_result_base<T, Container<K, T> >
{
	typedef Container<K, T> data_type;
	typedef find_if_result_qt<data_type> type;
	typedef find_result_base<T, data_type> super;
	typedef T value_type;

	friend type find_if<>(data_type& data, typename data_type::iterator it);

	find_if_result_qt(data_type& d) : super(d) { }

	bool insert(K&& k, T&& value)
	{
		super::iterator =
			super::data.insert(std::forward<K>(k), std::forward<T>(value));
		return super::iterator != super::data.end();
	}
};

template <typename M>
struct find_if_result_std;

template <
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct find_if_result_std<Container<K, T, D...>>
	: public
		find_result_base<
			typename Container<K, T, D...>::value_type,
			Container<K, T, D...>
		>
{
	typedef Container<K, T, D...> data_type;
	typedef find_if_result_std<data_type> type;
	typedef find_result_base<typename data_type::value_type, data_type> super;
	typedef typename data_type::value_type value_type;

	friend type find_if<>(data_type& data, typename data_type::iterator it);

	find_if_result_std(data_type& d) : super(d) { }

	bool insert(K&& k, T&& value)
	{
		auto r = super::data.insert(
			std::make_pair(std::forward<K>(k), std::forward<T>(value)));
		super::iterator = r.first;
		return r.second;
	}
};

template <
	typename TMap, template <typename> class TResult>
TResult<TMap> find_if(TMap& data, typename TMap::iterator it)
{
	typedef TResult<TMap> result_type;
	result_type result(data);
	result.iterator = it;
	return result;
}

// ------------------------------------------------------------------------
namespace __________const_find_result__________ { }

template <typename TMap, typename TKey, template <typename> class TResult>
TResult<TMap> const_find(const TMap& data, const TKey& key);

template <typename V, typename M>
struct const_find_result_base;

template <
	typename V,
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct const_find_result_base<V, Container<K, T, D...> >
{
	typedef Container<K, T, D...> data_type;
	typedef V value_type;
protected:
	const data_type& data;
	typename data_type::const_iterator iterator;

	const_find_result_base(const data_type& d) : data(d) { }
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
		return iterator.operator->();
	}
};

template <typename M>
struct const_find_result_qt;

template <
	typename K, typename T,
	template <typename, typename> class Container>
struct const_find_result_qt<Container<K, T> >
	: public const_find_result_base<T, Container<K, T> >
{
	typedef Container<K, T> data_type;
	typedef const_find_result_qt<data_type> type;
	typedef const_find_result_base<T, data_type> super;

	friend type const_find<>(const data_type&, const K&);

	const_find_result_qt(const data_type& d) : super(d) { }
};

template <typename M>
struct const_find_result_std;

template <
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct const_find_result_std<Container<K, T, D...> >
	: public const_find_result_base<
		typename Container<K, T, D...>::value_type, Container<K, T, D...> >
{
	typedef Container<K, T, D...> data_type;
	typedef const_find_result_std<data_type> type;
	typedef const_find_result_base<typename data_type::value_type, data_type> super;

	friend type const_find<>(const data_type&, const K&);

	const_find_result_std(const data_type& d) : super(d) { }
};

template <typename TMap, typename TKey, template <typename> class TResult>
TResult<TMap> const_find(const TMap& data, const TKey& key)
{
	typedef TResult<TMap> result_type;
	result_type result(data);
	result.iterator = data.find(key);
	return result;
}

// ------------------------------------------------------------------------
namespace __________const_find_if_result__________ { }

template <typename TMap, template <typename> class TResult>
TResult<TMap> const_find_if(const TMap& data, typename TMap::const_iterator iterator);

template <typename M>
struct const_find_if_result_qt;

template <
	typename K, typename T,
	template <typename, typename> class Container>
struct const_find_if_result_qt<Container<K, T>>
	: public const_find_result_base<T, Container<K, T> >
{
	typedef Container<K, T> data_type;
	typedef const_find_if_result_qt<data_type> type;
	typedef const_find_result_base<T, data_type> super;

	friend type const_find_if<>(const data_type& data, typename data_type::const_iterator iterator);

	const_find_if_result_qt(const data_type& d) : super(d) { }
};


template <typename M>
struct const_find_if_result_std;

template <
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct const_find_if_result_std<Container<K, T, D...>>
	: public
		const_find_result_base<
			typename Container<K, T, D...>::value_type,
			Container<K, T, D...>
		>
{
	typedef Container<K, T, D...> data_type;
	typedef const_find_if_result_std<data_type> type;
	typedef const_find_result_base<typename data_type::value_type, data_type> super;

	friend type const_find_if<>(const data_type& data, typename data_type::const_iterator iterator);

	const_find_if_result_std(const data_type& d) : super(d) { }
};

template <typename TMap, template <typename> class TResult>
TResult<TMap> const_find_if(const TMap& data, typename TMap::const_iterator it)
{
	typedef TResult<TMap> result_type;
	result_type result(data);
	result.iterator = it;
	return result;
}

} // namespace Private

// ------------------------------------------------------------------------

template <typename T>
struct is_std_map : public std::false_type { };

template <typename K, typename T, typename... Args>
struct is_std_map<std::map<K, T, Args...> > : public std::true_type { };

template <typename K, typename T, typename... Args>
struct is_std_map<std::unordered_map<K, T, Args...> > : public std::true_type { };

template <typename T>
struct is_qt_map : public std::false_type { };

template <typename K, typename T>
struct is_qt_map<QMap<K, T> > : public std::true_type { };

template <typename K, typename T>
struct is_qt_map<QHash<K, T> > : public std::true_type { };

namespace __________find_functions__________ { }

template <
	typename T,
	typename K,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::find_result_std<T> find(T& data, const K& key)
{
	return Private::find<T, K, Private::find_result_std>(data, key);
}

template <
	typename T,
	typename K,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::find_result_qt<T> find(T& data, const K& key)
{
	return Private::find<T, K, Private::find_result_qt>(data, key);
}

namespace __________const_find_functions__________ { }

template <
	typename T,
	typename K,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::const_find_result_std<T> find(const T& data, const K& key)
{
	return Private::const_find<T, K, Private::const_find_result_std>(data, key);
}

template <
	typename T,
	typename K,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::const_find_result_qt<T> find(const T& data, const K& key)
{
	return Private::const_find<T, K, Private::const_find_result_qt>(data, key);
}

template <
	typename T,
	typename K,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::const_find_result_std<T> const_find(const T& data, const K& key)
{
	return Private::const_find<T, K, Private::const_find_result_std>(data, key);
}

template <
	typename T,
	typename K,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::const_find_result_qt<T> const_find(const T& data, const K& key)
{
	return Private::const_find<T, K, Private::const_find_result_qt>(data, key);
}

namespace __________find_if_functions__________ { }

template <
	typename T,
	typename Function,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::find_if_result_std<T> find_if(T& data, Function&& function)
{
	auto f = [function] (typename T::value_type& v)
	{
		return function(v.first, v.second);
	};
	return Private::find_if<T, Private::find_if_result_std>
		(data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T,
	typename Function,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::find_if_result_qt<T> find_if(T& data, Function&& function)
{
	auto it = data.begin();
	for (; it != data.end(); ++it) { if (function(it.key(), it.value())) { break; } }
	return Private::find_if<T, Private::find_if_result_qt>(data, it);
}

namespace __________const_find_if_functions__________ { }

template <
	typename T,
	typename Function,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::const_find_if_result_std<T> find_if(const T& data, Function&& function)
{
	auto f = [function] (const typename T::value_type& v)
	{
		return function(v.first, v.second);
	};
	return Private::const_find_if<T, Private::const_find_if_result_std>
		(data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T,
	typename Function,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::const_find_if_result_qt<T> find_if(const T& data, Function&& function)
{
	auto it = data.begin();
	for (; it != data.end(); ++it) { if (function(it.key(), it.value())) { break; } }
	return Private::const_find_if<T, Private::const_find_if_result_qt>(data, it);
}

template <
	typename T,
	typename Function,
	enable_if_t<is_std_map<T>::value> * = nullptr>
Private::const_find_if_result_std<T> const_find_if(const T& data, Function&& function)
{
	auto f = [function] (const typename T::value_type& v)
	{
		return function(v.first, v.second);
	};
	return Private::const_find_if<T, Private::const_find_if_result_std>
		(data, std::find_if(data.begin(), data.end(), f));
}

template <
	typename T,
	typename Function,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
Private::const_find_if_result_qt<T> const_find_if(const T& data, Function&& function)
{
	auto it = data.begin();
	for (; it != data.end(); ++it) { if (function(it.key(), it.value())) { break; } }
	return Private::const_find_if<T, Private::const_find_if_result_qt>(data, it);
}

namespace __________contains_functions__________ { }

template <typename T, typename K>
inline bool contains(const T& data, const K& key)
{
	auto iterator = data.find(key);
	return iterator != data.end();
}

template <
	typename T, typename Function,
	enable_if_t<is_std_map<T>::value> * = nullptr>
inline bool contains_if(const T& data, Function&& function)
{
	auto f = [function] (const typename T::value_type& v)
	{
		return function(v.first, v.second);
	};
	auto iterator = std::find_if(data.begin(), data.end(), f);
	return iterator != data.end();
}

template <
	typename T, typename Function,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
inline bool contains_if(const T& data, Function&& function)
{
	auto it = data.begin();
	for (; it != data.end(); ++it) { if (function(it.key(), it.value())) { break; } }
	return it != data.end();

}

// ========================================================================
namespace __________for_each___________ { }

namespace Private
{

template <typename F, typename M>
struct for_each_qt;

template <
	typename Func,
	typename K, typename T,
	template <typename, typename> class Container>
struct for_each_qt<Func, Container<K, T> >
{
	typedef Container<K, T> data_type;
	typedef for_each_qt<Func, data_type> type;
	typedef K key_type;
	typedef T mapper_type;

	inline static Func for_each(data_type& map, Func f)
	{
		auto it = map.begin();
		while (it != map.end()) {
			f(it.key(), it.value());
			++it;
		}
		return std::move(f);
	}

	inline static Func const_for_each(const data_type& map, Func f)
	{
		auto it = map.begin();
		while (it != map.end()) {
			f(it.key(), it.value());
			++it;
		}
		return std::move(f);
	}
};

template <typename F, typename M>
struct for_each_std;

template <
	typename Func,
	typename K, typename T,
	template <typename, typename, typename...> class Container,
	typename... D>
struct for_each_std<Func, Container<K, T, D...> >
{
	typedef Container<K, T, D...> data_type;
	typedef typename data_type::value_type value_type;

	inline static Func for_each(data_type& map, Func f)
	{
		auto it = map.begin();
		while (it != map.end()) {
			value_type& v = *it;
			f(v.first, v.second);
			++it;
		}
		return std::move(f);
	}

	inline static Func const_for_each(const data_type& map, Func f)
	{
		auto it = map.begin();
		while (it != map.end()) {
			const value_type& v = *it;
			f(v.first, v.second);
			++it;
		}
		return std::move(f);
	}
};

} // namespace Private

namespace __________for_each_functions___________ { }

template <
	typename T, typename Func,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
inline Func for_each(T& map, Func f)
{
	return Private::for_each_qt<Func, T>::for_each(map, f);
}

template <
	typename T, typename Func,
	enable_if_t<is_std_map<T>::value> * = nullptr>
inline Func for_each(T& map, Func f)
{
	return Private::for_each_std<Func, T>::for_each(map, f);
}

namespace __________const_for_each_functions___________ { }

template <
	typename T, typename Func,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
inline Func for_each(const T& map, Func f)
{
	return Private::for_each_qt<Func, T>::const_for_each(map, f);
}

template <
	typename T, typename Func,
	enable_if_t<is_std_map<T>::value> * = nullptr>
inline Func for_each(const T& map, Func f)
{
	return Private::for_each_std<Func, T>::const_for_each(map, f);
}

template <
	typename T, typename Func,
	enable_if_t<is_qt_map<T>::value> * = nullptr>
inline Func const_for_each(const T& map, Func f)
{
	return Private::for_each_qt<Func, T>::const_for_each(map, f);
}

template <
	typename T, typename Func,
	enable_if_t<is_std_map<T>::value> * = nullptr>
inline Func const_for_each(const T& map, Func f)
{
	return Private::for_each_std<Func, T>::const_for_each(map, f);
}

} // namespace Map

} // namespace Qpe

#endif // Q_QDOC

#endif // ALGORITHM_ALGORITHM_MAP_IMPL_H

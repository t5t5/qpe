#ifndef ALGORITHM_ALGORITHM_MAP_H
#define ALGORITHM_ALGORITHM_MAP_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC
#include "algorithm_map_impl.h"
#else

namespace Qpe
{

namespace Map
{

template <typename TMap>
class find_result
{
public:
	bool operator!() const;
	operator bool() const;

	template <typename T>
	T& operator*() const;
	template <typename T>
	T* operator->() const;

	template <typename T, typename... Args>
	T& create(Args&&... args);

	template <typename T>
	bool insert(T&& value);

	template <typename T, typename K>
	bool insert(K&& key, T&& value);

	void erase();
};

template <typename TMap>
class find_if_result
{
public:
	bool operator!() const;
	operator bool() const;

	template <typename T>
	T& operator*() const;
	template <typename T>
	T* operator->() const;

	template <typename T, typename K>
	bool insert(K&& key, T&& value);

	void erase();
};

template <typename TMap>
class const_find_result
{
public:
	bool operator!() const;
	operator bool() const;

	template <typename T>
	const T& operator*() const;
	template <typename T>
	const T* operator->() const;
};

template <typename TMap>
class const_find_if_result
{
public:
	bool operator!() const;
	operator bool() const;

	template <typename T>
	const T& operator*() const;
	template <typename T>
	const T* operator->() const;
};

template <typename TMap, typename K>
Map::find_result<TMap> find(TMap& map, const K& key);

template <typename TMap, typename K>
Map::const_find_result<TMap> find(const TMap& map, const K& key);

template <typename TMap, typename K>
Map::const_find_result<TMap> const_find(const TMap& map, const K& key);

template <typename TMap, typename Function>
Map::find_if_result<TMap> find_if(TMap& map, Function&& function);

template <typename TMap, typename Function>
Map::const_find_if_result<TMap> find_if(const TMap& map, Function&& function);

template <typename TMap, typename Function>
Map::const_find_if_result<TMap> const_find_if(const TMap& map, Function&& function);

template <typename TMap, typename K>
bool contains(const TMap& map, const K& key);

template <typename TMap, typename Function>
bool contains_if(const TMap& map, Function&& function);

// ========================================================================

template <typename TMap, typename Function>
Function for_each(TMap& map, Function f);

template <typename TMap, typename Function>
Function for_each(const TMap& map, Function f);

template <typename TMap, typename Function>
Function const_for_each(const TMap& map, Function f);

} // namespace Map

} // namespace Qpe

#endif // Q_Q_DOC

#endif // ALGORITHM_ALGORITHM_MAP_H

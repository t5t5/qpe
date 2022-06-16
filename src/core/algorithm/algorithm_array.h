#ifndef ALGORITHM_ALGORITHM_ARRAY_H
#define ALGORITHM_ALGORITHM_ARRAY_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC
#include "algorithm_array_impl.h"
#else

namespace Qpe
{

namespace Array
{

template <typename TArray>
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
	bool insert(const T& value);

	template <typename T>
	bool insert(T&& value);

	void erase();
};

template <typename TArray>
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

template <typename TArray, typename K>
Array::find_result<TArray> find(TArray& array, const K& key);

template <typename TArray, typename K>
Array::const_find_result<TArray> find(const TArray& array, const K& key);

template <typename TArray, typename K>
Array::const_find_result<TArray> const_find(const TArray& array, const K& key);

template <typename TArray, typename Func>
Array::find_result<TArray> find_if(TArray& array, Func f);

template <typename TArray, typename Func>
Array::const_find_result<TArray> find_if(const TArray& array, Func f);

template <typename TArray, typename Func>
Array::const_find_result<TArray> const_find_if(const TArray& array, Func f);

template <typename TArray, typename K>
bool contains(const TArray& array, const K& key);

template <typename TArray, typename Func>
bool contains_if(const TArray& array, Func f);

// ------------------------------------------------------------------------

template <typename TArray>
class ordered_find_result
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
	bool insert(const T& value);

	template <typename T>
	bool insert(T&& value);

	void erase();
};

template <typename TArray>
class const_ordered_find_result
{
public:
	bool operator!() const;
	operator bool() const;

	template <typename T>
	T& operator*() const;
	template <typename T>
	T* operator->() const;
};

template <typename TArray, typename Value, typename Compare>
Array::ordered_find_result<TArray>
ordered_find(TArray& array, const Value& value, Compare&& compare);

template <typename TArray, typename Value>
Array::ordered_find_result<TArray>
ordered_find(TArray& array, const Value& value);

template <typename TArray, typename Value, typename Compare>
Array::const_ordered_find_result<TArray>
const_ordered_find(const TArray& array, const Value& value, Compare&& compare);

template <typename TArray, typename Value>
Array::const_ordered_find_result<TArray>
const_ordered_find(const TArray& array, const Value& value);

template <typename TArray, typename Value, typename Compare>
Array::const_ordered_find_result<TArray>
ordered_find(const TArray& array, const Value& value, Compare&& compare);

template <typename TArray, typename Value>
Array::const_ordered_find_result<TArray>
ordered_find(const TArray& array, const Value& value);

} // namespace Array

} // namespace Qpe

#endif

#endif // ALGORITHM_ALGORITHM_ARRAY_H

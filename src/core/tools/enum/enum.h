#ifndef TOOLS_ENUM_ENUM_H
#define TOOLS_ENUM_ENUM_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QVector>
#include <QHash>
#include <QMetaEnum>

#include <Qpe/Core/TypeTraits>

namespace Qpe
{

#ifndef Q_QDOC

namespace Private
{

struct qt_enum_t { explicit qt_enum_t() = default; };
static constexpr qt_enum_t qt_enum{};


template<typename T, typename... Rest>
struct is_same_all : std::true_type {};

template<typename T, typename T1>
struct is_same_all<T, T1> : std::is_same<T, T1> { };

template<typename T, typename T1, typename... TN>
struct is_same_all<T, T1, TN...>
    : std::integral_constant<bool, std::is_same<T, T1>::value && is_same_all<T, TN...>::value> { };

} // namespace Private

// ------------------------------------------------------------------------
#ifndef Q_QDOC
namespace _____enum_____ { }
#endif // Q_QDOC
// ------------------------------------------------------------------------

namespace Private
{

template <
	typename TValue,
	typename TKey>
struct EnumStaticBase
{
	struct Item
	{
		TValue value;
		TKey key;
	};
	typedef QVector<Item> Data;
	typedef QVector<TValue> ValueVector;
	typedef QVector<TKey> KeyVector;

	typedef
		typename std::conditional<
			is_enum_scoped<TValue>::value,
			typename std::underlying_type<TValue>::type,
			TValue
		>::type underlying_value_type;

	typedef QHash<underlying_value_type, int> ValueHash;
	typedef QHash<TKey, int> KeyHash;
};

template <
	typename TValue,
	typename TKey>
struct EnumStatic : public EnumStaticBase<TValue, TKey>
{
	typedef EnumStaticBase<TValue, TKey> super;
	typedef typename super::Item Item;
	typedef typename super::underlying_value_type underlying_value_type;

	typedef typename super::Data Data;
	typedef typename super::ValueVector ValueVector;
	typedef typename super::KeyVector KeyVector;
	typedef typename super::ValueHash ValueHash;
	typedef typename super::KeyHash KeyHash;

	Data m_data;
	ValueVector m_values;
	KeyVector m_keys;
	ValueHash m_value_hash;
	KeyHash m_key_hash;

	EnumStatic() = default;

	EnumStatic(qt_enum_t)
	{
		QMetaEnum me = QMetaEnum::fromType<TValue>();
		int size = me.keyCount();
		reserve(size);
		for (int i = 0; i < size; ++i) {
			TValue value = static_cast<TValue>(me.value(i));
			TKey key = me.key(i);
			initItem(i, value, key);
		}
	}

	EnumStatic(std::initializer_list<std::pair<TValue, const char*> > d)
	{
		reserve(d.size());
		int i = 0;
		for (const std::pair<TValue, const char*>& item : d) {
			TValue value = static_cast<TValue>(item.first);
			TKey key = item.second;
			initItem(i++, value, key);
			++i;
		}
	}

	inline void reserve(int size)
	{
		m_data.reserve(size);
		m_values.reserve(size);
		m_keys.reserve(size);
		m_value_hash.reserve(size);
		m_key_hash.reserve(size * 2);
	}
	inline void initItem(int index, TValue value, const TKey& key)
	{
		m_data.append(Item{value, key});
		m_keys.append(key);
		m_values.append(value);

		m_key_hash.insert(key, index);
		TKey keyLower = key.toLower();
		if (key != keyLower) {
			m_key_hash.insert(keyLower, index);
		}
		m_value_hash.insert(static_cast<underlying_value_type>(value), index);
	}

	inline TKey valueToKey(TValue value) const
	{
		auto it = m_value_hash.find(value);
		return (it == m_value_hash.end()) ? TKey() : m_data.at(*it).key;
	}

	inline TValue keyToValue(
		const TKey& key, Qt::CaseSensitivity cs, bool* ok) const
	{
		auto it = m_key_hash.find(cs == Qt::CaseInsensitive ? key.toLower() : key);
		*ok = it != m_key_hash.end();
		return (it == m_key_hash.end()) ? TValue() : m_data.at(*it).value;
	}

	inline TValue keyToValue(
		const TKey& key, Qt::CaseSensitivity cs, bool* ok, TValue defaultValue) const
	{
		auto it = m_key_hash.find(cs == Qt::CaseInsensitive ? key.toLower() : key);
		*ok = (it != m_key_hash.end()) ||
				m_value_hash.contains(static_cast<underlying_value_type>(defaultValue));
		return (it == m_key_hash.end()) ? defaultValue : m_data.at(*it).value;
	}


	inline bool containsValue(TValue value) const
	{
		return m_value_hash.contains(value);
	}

	inline bool containsKey(const TKey& key, Qt::CaseSensitivity cs) const
	{
		return m_key_hash.contains(cs == Qt::CaseInsensitive ? key.toLower() : key);
	}
};

} // namespace Private

#endif // Q_QDOC

// ------------------------------------------------------------------------

template <
	typename TValue,
	typename TKey = QByteArray>
class Enum
{
protected:
	TValue m_value;
	bool m_valid;

#ifndef Q_QDOC
	typedef Private::EnumStatic<TValue, TKey> EnumStatic;
	static EnumStatic& es()
	{
		static EnumStatic e(Private::qt_enum);
		return e;
	}
#endif // Q_QDOC
public:
	Enum() : m_value(TValue()), m_valid(false) { }
	Enum(TValue e) : m_value(e), m_valid(es().containsValue(e)) { }
	Enum(int e)
		: m_value(static_cast<TValue>(e))
		, m_valid(es().containsValue(static_cast<TValue>(e))) { }
	Enum(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keyToValue(key, cs, &m_valid)) { }
	Enum(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keyToValue(key, cs, &m_valid, defaultValue)) { }

	Enum(const Enum& o) = default;
	Enum(Enum&& o) = default;

	inline TKey key() const { return es().valueToKey(m_value); }
	inline TValue value() const { return m_value; }

	template <TValue e>
	inline void setValue() { m_value = e; m_valid = es().containsValue(e); }
	inline void setValue(TValue e) { m_value = e; m_valid = es().containsValue(e); }

	inline bool isValid() const { return m_valid; }
	inline bool isEmpty() const { return !m_valid; }

	static TKey valueToKey(TValue e) { return es().valueToKey(e); }
	static QVector<TValue> values() { return es().m_values; }
	static QVector<TKey> keys() { return es().m_keys; }

	template <typename T>
	bool in(T e) const
	{
		static_assert(std::is_same<TValue, T>::value, "T is not same as TValue");
		return m_value == e;
	}

	template <typename T, typename... TN>
	bool in(T e, TN... en) const
	{
		static_assert(Private::is_same_all<TValue, T, TN...>::value, "T or TN... is not same as TValue");
		bool s = (m_value == e);
		return s ? s : (s | in(en...));
	}

	inline Enum& operator=(const Enum& e) = default;
	inline Enum& operator=(Enum&& e) = default;
	inline Enum& operator=(TValue e) { setValue(e); return *this; }

	inline bool operator==(const Enum& e) const { return m_valid && (m_value == e.m_value); }
	inline bool operator==(TValue e) const { return m_valid && (m_value == e); }
	inline bool operator!=(const Enum& e) const { return !m_valid || (m_value != e.m_value); }
	inline bool operator!=(TValue e) const { return !m_valid || (m_value != e); }
};

#ifndef Q_QDOC

// ------------------------------------------------------------------------
#ifndef Q_QDOC
namespace _____flag_____ { }
#endif // Q_QDOC
// ------------------------------------------------------------------------

namespace Private
{

template <
	typename TValue,
	typename TKey>
struct FlagStatic : public EnumStatic<TValue, TKey>
{
	typedef EnumStatic<TValue, TKey> super;
	typedef typename super::Item Item;
	typedef typename super::underlying_value_type underlying_value_type;

	typedef typename super::Data Data;
	typedef typename super::ValueVector ValueVector;
	typedef typename super::KeyVector KeyVector;
	typedef typename super::ValueHash ValueHash;
	typedef typename super::KeyHash KeyHash;

	typedef typename std::make_unsigned<underlying_value_type>::type mask_type;
	mask_type mask;

	FlagStatic() = default;

	FlagStatic(qt_enum_t)
	{
		QMetaEnum me = QMetaEnum::fromType<TValue>();
		int size = me.keyCount();
		super::reserve(size);
		for (int i = 0, count = me.keyCount(); i < count; ++i) {
			TValue value = static_cast<TValue>(me.value(i));
			TKey key = me.key(i);
			super::initItem(i, value, key);
			mask |= static_cast<mask_type>(value);
		}
	}

	FlagStatic(std::initializer_list<std::pair<TValue, const char*> > d)
	{
		super::reserve(d.size());
		int i = 0;
		for (std::pair<TValue, const char*> item : d) {
			TValue value = static_cast<TValue>(item.first);
			TKey key = item.second;
			super::initItem(i++, value, key);
			mask |= static_cast<mask_type>(value);
		}
	}

	inline KeyVector valueToKeys(mask_type value) const
	{
		typename super::KeyVector r;
		for (const typename super::Item& item : super::m_data) {
			mask_type v = static_cast<mask_type>(item.value);
			mask_type t = value & v;
			if ((t != 0) && (t == v)) {
				r.append(item.key);
			}
		}
		return r;
	}

	inline mask_type keyToValue(const TKey& key, Qt::CaseSensitivity cs) const
	{
		auto it = super::m_key_hash.find(cs == Qt::CaseInsensitive ? key.toLower() : key);
		return (it == super::m_key_hash.end()) ? TValue() : super::m_data.at(*it).value;
	}

	template <template <typename> class TContainer>
	inline mask_type keysToValue(
		const TContainer<TKey>& keys, Qt::CaseSensitivity cs) const
	{
		mask_type r = 0;
		for (const TKey& key : keys) {
			auto it = super::m_key_hash.find(cs == Qt::CaseInsensitive ? key.toLower() : key);
			if (it != super::m_key_hash.end()) {
				r |= static_cast<mask_type>(super::m_data.at(*it).value);
			}
		}
		return r;
	}
};

} // namespace Private

#endif // Q_QDOC

// ------------------------------------------------------------------------

template <
	typename TValue,
	typename TKey = QByteArray>
class Flag
{
protected:
#ifndef Q_QDOC
	typedef Private::FlagStatic<TValue, TKey> FlagStatic;
	static FlagStatic& es()
	{
		static FlagStatic e(Private::qt_enum);
		return e;
	}
#endif // Q_QDOC
public:
	typedef typename FlagStatic::mask_type mask_type;
protected:
	mask_type m_value;
public:
	inline Flag() : m_value(TValue()) { }
	inline Flag(TValue e) : m_value(e) { }
	Flag(mask_type e) : m_value(static_cast<TValue>(e)) { }

	Flag(const TKey& key, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keyToValue(key, cs)) { }
	Flag(const TKey& key, TValue defaultValue, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keyToValue(key, cs, defaultValue)) { }
	Flag(const QVector<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keysToValue(keys, cs)) { }
	Flag(const QList<TKey>& keys, Qt::CaseSensitivity cs = Qt::CaseSensitive)
		: m_value(es().keysToValue(keys, cs)) { }

	Flag(const Flag& o) = default;
	Flag(Flag&& o) = default;

	inline static mask_type mask() { return es().mask; }
	inline mask_type value() const { return m_value; }

	template <TValue e>
	inline void setValue() { m_value = e; }
	inline void setValue(TValue e) { m_value = e; }
	inline void setValue(mask_type e) { m_value = e; }

	inline bool isValid() const
	{
		mask_type m = es().mask;
		return ((m & m_value) == m_value) && ((m_value != 0) || (m == m_value));
	}
	inline bool isEmpty() const { return m_value == 0; }

	QVector<TKey> keys() const { return es().valueToKeys(m_value); }

	static TKey valueToKey(TValue e) { return es().valueToKey(e); }
	static QVector<TKey> valueToKeys(mask_type e) { return es().valueToKeys(e); }
	static QVector<TValue> values() { return es().m_values; }
	static QVector<TKey> allKeys() { return es().m_keys; }

	inline bool test(TValue e) const
	{
		mask_type v = static_cast<mask_type>(e);
		return ((m_value & v) == v) && (e != 0 || m_value == v);
	}
	inline bool test(const Flag& e) const
	{
		return ((m_value & e.m_value) == e.m_value) &&
				(e.m_value != 0 || m_value == e.m_value);
	}

	inline operator mask_type() const { return m_value; }

	inline Flag& operator=(const Flag& e) = default;
	inline Flag& operator=(Flag&& e) = default;

	inline Flag& operator=(TValue e) { m_value = e; return *this; }
	inline Flag& operator=(mask_type e) { m_value = e; return *this; }

	inline Flag& operator&=(const Flag& e) { m_value &= e.m_value; return *this; }
	inline Flag& operator&=(TValue e) { m_value &= static_cast<mask_type>(e); return *this; }
	inline Flag& operator&=(mask_type e) { m_value &= e; return *this; }
	inline Flag& operator|=(const Flag& e) { m_value |= e.m_value; return *this; }
	inline Flag& operator|=(TValue e) { m_value |= static_cast<mask_type>(e); return *this; }
	inline Flag& operator|=(mask_type e) { m_value |= e; return *this; }
	inline Flag& operator^=(const Flag& e) { m_value ^= e.m_value; return *this; }
	inline Flag& operator^=(TValue e) { m_value ^= static_cast<mask_type>(e); return *this; }
	inline Flag& operator^=(mask_type e) { m_value ^= e; return *this; }
	inline Flag operator|(const Flag& e) const { return Flag(m_value | e.m_value); }
	inline Flag operator|(TValue e) const { return Flag(m_value | static_cast<mask_type>(e)); }
	inline Flag operator|(mask_type e) const { return Flag(m_value | e); }
	inline Flag operator^(const Flag& e) const { return Flag(m_value ^ e.m_value); }
	inline Flag operator^(TValue e) const { return Flag(m_value ^ static_cast<mask_type>(e)); }
	inline Flag operator^(mask_type e) const { return Flag(m_value ^ e); }
	inline Flag operator&(const Flag& e) const { return Flag(m_value & e.m_value); }
	inline Flag operator&(TValue e) const { return Flag(m_value & static_cast<mask_type>(e)); }
	inline Flag operator&(mask_type e) const { return Flag(m_value & e); }
	inline Flag operator~() const { return Flag(~m_value); }
};

} // namespace Qpe

#endif // TOOLS_ENUM_ENUM_H

#ifndef TOOLS_STRINGIFIER_STATIC_STRINGIFIER_H
#define TOOLS_STRINGIFIER_STATIC_STRINGIFIER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QtGlobal>
#include <QChar>
#include <Qpe/Qpe>
#include <Qpe/Core/TypeTraits>

namespace Qpe
{

static const constexpr int DecBase = 10;
static const constexpr int DecBase2Digits = -2;
static const constexpr int DecBase3Digits = -3;
static const constexpr int DecBase4Digits = -4;
static const constexpr int HexBase = 16;

struct WithLeadingZero { };
struct WithoutLeadingZero { };

struct WithPrefix { };
struct WithoutPrefix { };

struct UpperCase { };
struct LowerCase { };

namespace Static
{

template <
	int Base,
	typename LeadingZero = WithoutLeadingZero,
	typename Prefix = WithoutPrefix,
	typename Case = LowerCase>
struct Stringifier
#ifdef Q_QDOC
{
	template <typename T>
	static inline QByteArray format(T n) { }

	template <typename T>
	static inline QByteArray& format(T n, QByteArray& result) { }

	template <typename T>
	static inline QString& format(T n, QString& result) { }
}
#endif // Q_QDOC
;

} // namespace Static

} // namespace Qpe

#endif // TOOLS_STRINGIFIER_STATIC_STRINGIFIER_H

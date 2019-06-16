#ifndef TOOLS_CONVERSION_CONVERSIONPATTERN_IMPL_H
#define TOOLS_CONVERSION_CONVERSIONPATTERN_IMPL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <Qpe/Core/Private/conversionpattern_defines.h>

namespace Qpe
{

namespace Private
{

template <typename TData, int CacheSize>
class ConversionPattern
{
public:
	typedef std::function<QString(const TData&)> ExpressionFunctor;
	typedef std::function<ExpressionFunctor(const QString&, const QVariantMap&)> ExpressionFactory;
protected:
	void initialize(
		const QString& pattern, ExpressionFactory&& factory);
	void initialize(
		const QString& pattern, const QStringList& names, ExpressionFactory&& factory);

	QString createString(const TData& data) const;
private:
	struct Expression
	{
		QString text;
		ExpressionFunctor expressionFunctor;
	};

	typedef QVector<Expression> ExpressionVector;

	static inline ExpressionFunctor createFormatter(
		int min, int max, bool leftJustified, QChar padding, ExpressionFunctor&& e);
	void addExpressionText(const QString& pattern, int startPosition);
	void addExpressionText(const QString& pattern, int startPosition, int lastPosition);

	mutable QString cachedResult;
	ExpressionVector expressions;
};

template<typename TData, int CacheSize>
void ConversionPattern<TData, CacheSize>::initialize(
	const QString& pattern,
	ExpressionFactory&& factory)
{
	using namespace PrivateConversionPattern;

	initialize(
		pattern,
		QStringList() << PATTERN_DEFAULT_EXPRESSION_NAME,
		std::forward<ExpressionFactory>(factory));
}

template<typename TData, int CacheSize>
void ConversionPattern<TData, CacheSize>::initialize(
	const QString& pattern, const QStringList& names,
	ExpressionFactory&& factory)
{
	using namespace PrivateConversionPattern;

	expressions.clear();

	QRegularExpression expressionRegexp(
		QString(PATTERN_EXPRESSION).arg(names.join(CHAR_PIPE)));
	int startPos = 0;
	QRegularExpressionMatch m;
	int textPos = 0;
	while ((m = expressionRegexp.match(pattern, startPos)).hasMatch()) {
		int pos = m.capturedStart();
		int len = m.capturedLength();
		QString expressionName = m.captured(4);
		QVariantMap properties = parseProperties(m.captured(5));

		ExpressionFunctor f = factory(expressionName, properties);
		if (f) {
			addExpressionText(pattern, startPos, pos);

			bool leftJustified = m.captured(1) == CHAR_MINUS;
			int min = m.captured(2).toInt();
			int max = m.captured(3).toInt();
			QChar padding = paddingChar(properties);
			Expression e;
			e.expressionFunctor =
				createFormatter(min, max, leftJustified, padding, std::forward<ExpressionFunctor>(f));
			expressions.append(e);
			textPos = pos + len;
		}
		startPos = pos + len;
	}
	addExpressionText(pattern, textPos);
}

template<typename TData, int CacheSize>
QString ConversionPattern<TData, CacheSize>::createString(const TData& data) const
{
	{	// if isDetached() is unreachable then comment this block
		if (cachedResult.isDetached()) {
			cachedResult.resize(0);
		} else {
			cachedResult.clear();
		}
		cachedResult.reserve(CacheSize);
	}
//	{	// if isDetached() is unreachable then uncomment this block
//		cachedResult.reserve(CacheSize);
//		cachedResult.resize(0);
//	}
	if (!expressions.isEmpty()) {
		for (const Expression& e : expressions) {
			cachedResult.append(
				e.expressionFunctor ? e.expressionFunctor(data) : e.text);
		}
	}
	return cachedResult;
}

template<typename TData, int CacheSize>
typename ConversionPattern<TData, CacheSize>::ExpressionFunctor
	ConversionPattern<TData, CacheSize>::createFormatter(
		int min, int max, bool leftJustified, QChar padding,
		typename ConversionPattern<TData, CacheSize>::ExpressionFunctor&& e)
{
	ExpressionFunctor formatter;
	if ((min == 0) && (max == 0)) {
		// as is: without justify and truncate
		formatter = e;
	} else
	if ((max == 0) && leftJustified) {
		// min > 0
		// with left justify but without truncate
		formatter = [e, padding, min] (const TData& d) -> QString
		{
			QString v = e(d);
			return v.leftJustified(qMax(min, v.length()), padding);
		};
	} else
	if (max == 0) {
		// min > 0
		// with right justify and without truncate
		formatter = [e, padding, min] (const TData& d) -> QString
		{
			QString v = e(d);
			return v.rightJustified(qMax(min, v.length()), padding);
		};
	} else
	if (leftJustified) {
		// min > 0; max > 0
		// left justify and may be truncate
		formatter = [e, padding, min, max] (const TData& d) -> QString
		{
			QString v = e(d);
			int length = v.length();
			int width = length > max ? max : qMax(min, length);
			return v.leftJustified(width, padding, length > max);
		};
	} else {
		// min > 0; max > 0
		// right justify and may be truncate
		formatter = [e, padding, min, max] (const TData& d) -> QString
		{
			QString v = e(d);
			int length = v.length();
			int width = length > max ? max : qMax(min, length);
			return v.rightJustified(width, padding, length > max);
		};
	}
	return formatter;
}

template<typename TData, int CacheSize>
void ConversionPattern<TData, CacheSize>::addExpressionText(
	const QString& pattern, int startPosition)
{
	Q_ASSERT(startPosition >= 0);
	int length = pattern.length() - startPosition;
	if (length <= 0) { return; }
	Expression e;
	e.text = pattern.mid(startPosition, length);
	expressions.append(e);
}

template<typename TData, int CacheSize>
void ConversionPattern<TData, CacheSize>::addExpressionText(
	const QString& pattern, int startPosition, int lastPosition)
{
	Q_ASSERT((startPosition >= 0) && (lastPosition >= startPosition));
	int length = lastPosition - startPosition;
	if (length == 0) { return; }
	Expression e;
	e.text = pattern.mid(startPosition, length);
	expressions.append(e);
}

} // namespace Private

// ------------------------------------------------------------------------

namespace Private
{

class SimpleConversionPatternPrivate
{
public:
	typedef std::function<QString(const QString&, const QVariantMap&)> ExpressionFactory;
protected:

	void initialize(
		const QString& pattern,
		ExpressionFactory&& factory);
	void initialize(
		const QString& pattern,
		const QStringList& names,
		ExpressionFactory&& factory);

	inline QString createString() const;
private:
	static inline QString format(
		int min, int max, bool leftJustified, QChar padding, const QString& in);
	QString expression;
};

void SimpleConversionPatternPrivate::initialize(
	const QString& pattern, ExpressionFactory&& factory)
{
	using namespace PrivateConversionPattern;

	initialize(
		pattern,
		QStringList() << PATTERN_DEFAULT_EXPRESSION_NAME,
		std::forward<ExpressionFactory>(factory));
}

void SimpleConversionPatternPrivate::initialize(
	const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
{
	using namespace PrivateConversionPattern;

	expression.clear();

	QRegularExpression expressionRegexp(
		QString(PATTERN_EXPRESSION).arg(names.join(CHAR_PIPE)));
	int startPos = 0;
	QRegularExpressionMatch m;
	int textPos = 0;
	while ((m = expressionRegexp.match(pattern, startPos)).hasMatch()) {
		int pos = m.capturedStart();
		int len = m.capturedLength();
		QString expressionName = m.captured(4);
		QVariantMap properties = parseProperties(m.captured(5));

		QString f = factory(expressionName, properties);
		if (!f.isEmpty()) {
			expression.append(pattern.mid(startPos, pos - startPos));

			bool leftJustified = m.captured(1) == CHAR_MINUS;
			int min = m.captured(2).toInt();
			int max = m.captured(3).toInt();
			QChar padding = paddingChar(properties);

			expression.append(format(min, max, leftJustified, padding, f));
			textPos = pos + len;
		}
		startPos = pos + len;
	}
	expression.append(pattern.mid(textPos));
}

QString SimpleConversionPatternPrivate::createString() const
{
	return expression;
}

QString SimpleConversionPatternPrivate::format(
	int min, int max, bool leftJustified, QChar padding, const QString& in)
{
	if ((min == 0) && (max == 0)) {
		// as is: without justify and truncate
		return in;
	} else
	if ((max == 0) && leftJustified) {
		// min > 0
		// with left justify but without truncate
		return in.leftJustified(qMax(min, in.length()), padding);
	} else
	if (max == 0) {
		// min > 0
		// with right justify and without truncate
		return in.rightJustified(qMax(min, in.length()), padding);
	} else
	if (leftJustified) {
		// min > 0; max > 0
		// left justify and may be truncate
		int length = in.length();
		int width = length > max ? max : qMax(min, length);
		return in.leftJustified(width, padding, length > max);
	} else {
		// min > 0; max > 0
		// right justify and may be truncate
		int length = in.length();
		int width = length > max ? max : qMax(min, length);
		return in.rightJustified(width, padding, length > max);
	}
}

} // namespace Private

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_CONVERSION_CONVERSIONPATTERN_IMPL_H

#ifndef TOOLS_CONVERSION_CONVERSIONPATTERN_H
#define TOOLS_CONVERSION_CONVERSIONPATTERN_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <functional>

#include <QVector>

#include <Qpe/Core/Private/conversionpattern_impl.h>

namespace Qpe
{

template <typename TData, int CacheSize = 1024>
class ConversionPattern : public Private::ConversionPattern<TData, CacheSize>
{
public:
#ifndef Q_QDOC
	typedef Private::ConversionPattern<TData, CacheSize> super;
#endif // Q_QDOC
#ifdef Q_QDOC
	typedef typename super::ExpressionFunctor ExpressionFunctor;
#endif // Q_QDOC
	typedef typename super::ExpressionFactory ExpressionFactory;

	ConversionPattern() = default;

	ConversionPattern(const QString& pattern, ExpressionFactory&& factory)
	{
		super::initialize(pattern, std::forward<ExpressionFactory>(factory));
	}

	ConversionPattern(
		const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
	{
		super::initialize(pattern, names, std::forward<ExpressionFactory>(factory));
	}

	inline void initialize(
		const QString& pattern, ExpressionFactory&& factory)
	{
		super::initialize(pattern, std::forward<ExpressionFactory>(factory));
	}

	inline void initialize(
		const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
	{
		super::initialize(pattern, names, std::forward<ExpressionFactory>(factory));
	}

	inline bool containsExpressions() const { return super::containsExpressions(); }

	QString createString(const TData& data) const
	{
		return super::createString(data);
	}
};

// ------------------------------------------------------------------------

class SimpleConversionPatternFactory
{
public:
	using ElementFunctor = std::function<QString(const QVariantMap&)>;
	SimpleConversionPatternFactory() = default;

	void registerElement(const QString& elementName, ElementFunctor&& elementFunctor)
	{
		elements.insert(elementName, elementFunctor);
	}

	QStringList elementNames() const
	{
		return elements.keys();
	}

	QString operator()(const QString& elementName, const QVariantMap& properties) const
	{
		auto it = elements.find(elementName);
		return (it == elements.end()) ? QString() : (*it)(properties);
	}
private:
	QMap<QString, ElementFunctor> elements;
};

class SimpleConversionPattern : public Private::SimpleConversionPatternPrivate
{
public:
#ifndef Q_QDOC
	typedef Private::SimpleConversionPatternPrivate super;
#endif // Q_QDOC
	typedef typename super::ExpressionFactory ExpressionFactory;

	SimpleConversionPattern() = default;

	SimpleConversionPattern(const QString& pattern, ExpressionFactory&& factory)
	{
		super::initialize(pattern, std::forward<ExpressionFactory>(factory));
	}

	SimpleConversionPattern(
		const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
	{
		super::initialize(pattern, names, std::forward<ExpressionFactory>(factory));
	}

	inline void initialize(
		const QString& pattern, ExpressionFactory&& factory)
	{
		super::initialize(pattern, std::forward<ExpressionFactory>(factory));
	}

	inline void initialize(
		const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
	{
		super::initialize(pattern, names, std::forward<ExpressionFactory>(factory));
	}

	QString createString() const
	{
		return super::createString();
	}
};

} // namespace Qpe

#endif // TOOLS_CONVERSION_CONVERSIONPATTERN_H

#ifndef UTILS_APPPATHCONVERSION_H
#define UTILS_APPPATHCONVERSION_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Qpe/Core/ConversionPattern>

namespace Qpe
{

namespace LoggerPrivate
{

typedef ConversionPattern<QVariantMap> AppPathConversionPattern;

struct AppPathConversionFactory
{
	static AppPathConversionPattern::ExpressionFunctor
		createExpression(const QString& expressionName, const QVariantMap&);

	static QStringList expressionNames();
};

} // namespace LoggerPrivate

} // namespace Qpe

#endif // UTILS_APPPATHCONVERSION_H

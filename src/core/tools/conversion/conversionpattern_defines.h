#ifndef TOOLS_CONVERSION_CONVERSIONPATTERN_DEFINES_H
#define TOOLS_CONVERSION_CONVERSIONPATTERN_DEFINES_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <QLatin1String>
#include <QRegularExpression>
#include <QVariant>

#include <Qpe/Qpe>

namespace Qpe
{

namespace PrivateConversionPattern
{

extern QPE_CORE_EXPORT const QLatin1String PATTERN_EXPRESSION;
extern QPE_CORE_EXPORT const QRegularExpression REGEXP_PROPERTY;
extern QPE_CORE_EXPORT const QRegularExpression REGEXP_REPLACE_1;
extern QPE_CORE_EXPORT const QRegularExpression REGEXP_REPLACE_2;

extern QPE_CORE_EXPORT const QLatin1String PATTERN_DEFAULT_EXPRESSION_NAME;
extern QPE_CORE_EXPORT const QLatin1String PROPERTY_PADDING;
extern QPE_CORE_EXPORT const QLatin1String CAPTURE_GROUP_1;

extern QPE_CORE_EXPORT const QLatin1Char CHAR_EQUAL;
extern QPE_CORE_EXPORT const QLatin1Char CHAR_MINUS;
extern QPE_CORE_EXPORT const QLatin1Char CHAR_SPACE;
extern QPE_CORE_EXPORT const QLatin1Char CHAR_PIPE;

QPE_CORE_EXPORT QVariantMap parseProperties(const QString& propertyString);
QPE_CORE_EXPORT QChar paddingChar(const QVariantMap& properties);

} // namespace PrivateConversionPattern

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_CONVERSION_CONVERSIONPATTERN_DEFINES_H

#include "conversionpattern_defines.h"

namespace Qpe
{

namespace PrivateConversionPattern
{

const QLatin1String PATTERN_EXPRESSION(
	"%(?:(-?)(\\d{1,3}))?(?:\\.(\\d{1,3}))?(%1)(?:\\{((?:\\\\\\}|\\\\\\{|[^{}])*)\\})?");
const QRegularExpression REGEXP_PROPERTY(QLatin1String(
	"([a-zA-Z_]{1}[a-zA-Z0-9-_]*)(?:(=)((?:\\\\;|[^;])*))?;?"));
const QRegularExpression REGEXP_REPLACE_1(QLatin1String("\\\\(\\{|\\})"));
const QRegularExpression REGEXP_REPLACE_2(QLatin1String("\\\\(;)"));

const QLatin1String PATTERN_DEFAULT_EXPRESSION_NAME("\\w+");
const QLatin1String PROPERTY_PADDING("padding");
const QLatin1String CAPTURE_GROUP_1("\\1");

const QLatin1Char CHAR_EQUAL('=');
const QLatin1Char CHAR_MINUS('-');
const QLatin1Char CHAR_SPACE(' ');
const QLatin1Char CHAR_PIPE('|');

QVariantMap parseProperties(const QString& propertyString)
{
	QVariantMap properties;
	QString p = propertyString;
	p.replace(REGEXP_REPLACE_1, CAPTURE_GROUP_1);
	int pos = 0;
	QRegularExpressionMatch m;
	while ((m = REGEXP_PROPERTY.match(p, pos)).hasMatch()) {
		QString name = m.captured(1);
		QVariant value = (m.captured(2) == CHAR_EQUAL)
			? QVariant(m.captured(3).replace(REGEXP_REPLACE_2, CAPTURE_GROUP_1))
			: QVariant(true);
		properties.insert(name, value);
		pos += m.capturedLength();
	}
	return properties;
}

QChar paddingChar(const QVariantMap& properties)
{
	auto it = properties.constFind(PROPERTY_PADDING);
	if (it == properties.constEnd()) { return CHAR_SPACE; }
	QString padding = (*it).toString();
	return padding.isEmpty() ? CHAR_SPACE : padding.at(0);
}

} // namespace PrivateConversionPattern

} // namespace Qpe

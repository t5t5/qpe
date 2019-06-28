#include "apppathconversion.h"

namespace Qpe
{

namespace LoggerPrivate
{

static const QLatin1String VALUE_APP_DATA_PATH	("applicationDataPath");
static const QLatin1String VALUE_APP_LOCAL_PATH	("applicationLocalPath");
static const QLatin1String VALUE_APP_DIR_PATH	("applicationDirPath");

static const QLatin1String APP_DATA_PATH	("AppData");
static const QLatin1String APP_LOCAL_PATH	("AppLocal");
static const QLatin1String APP_DIR_PATH		("AppDir");

AppPathConversionPattern::ExpressionFunctor
	AppPathConversionFactory::createExpression(const QString& en, const QVariantMap&)
{
	if (en == APP_DATA_PATH) {
		return [] (const QVariantMap& s) { return s.value(VALUE_APP_DATA_PATH).toString(); };
	} else
	if (en == APP_LOCAL_PATH) {
		return [] (const QVariantMap& s) { return s.value(VALUE_APP_LOCAL_PATH).toString(); };
	} else
	if (en == APP_DIR_PATH) {
		return [] (const QVariantMap& s) { return s.value(VALUE_APP_DIR_PATH).toString(); };
	}
	Q_UNREACHABLE();
}

QStringList AppPathConversionFactory::expressionNames()
{
	return QStringList() << APP_DATA_PATH << APP_LOCAL_PATH << APP_DIR_PATH;
}

} // namespace LoggerPrivate

} // namespace Qpe

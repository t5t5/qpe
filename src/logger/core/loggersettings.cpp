#include "loggersettings.h"

#include <QFile>
#include <QSettings>

namespace Qpe
{

namespace Settings
{

static const QLatin1String Appender	("appender");
static const QLatin1String Filter	("filter");
static const QLatin1String Logger	("logger");

} // namespace Settings

bool parseKeyProperty(
	const QString& key, char separator, const QVariant& value,
	QMap<QString, QVariantMap>& settings)
{
	QStringList ns = key.split(separator);
	if (ns.size() < 3) { return false; }

	QString propertyName = ns.at(1);
	QString propertyKey = QStringList(ns.mid(2)).join('.');
	settings[propertyName].insert(propertyKey, value);
	return true;
}

bool parseProperty(
	const QString& key, const QVariant& value, char separator, LoggerSettings& out)
{
	if (key.startsWith(Settings::Appender + separator)) {
		return parseKeyProperty(key, separator, value, out.appenders);
	} else
	if (key.startsWith(Settings::Filter + separator)) {
		return parseKeyProperty(key, separator, value, out.filters);
	} else
	if (key.startsWith(Settings::Logger + separator)) {
		return parseKeyProperty(key, separator, value, out.loggers);
	}
	return false;
}

LoggerSettings LoggerSettings::fromSettings(
	const QString& fileName, const char* codecName)
{
	if (!QFile::exists(fileName)) { return LoggerSettings(); }

	QSettings settings(fileName, QSettings::IniFormat);
	if (codecName != nullptr) {
		settings.setIniCodec(codecName);
	}
	QStringList keys = settings.allKeys();

	LoggerSettings s;
	bool result = true;
	for (const QString& key : keys) {
		QVariant value = settings.value(key);
		result &= parseProperty(key, value, '/', s);
	}
	if (result) { s.name = settings.fileName(); }
	return result ? s : LoggerSettings();
}

LoggerSettings LoggerSettings::fromProperties(
	const QString& name, const QVariantMap& properties)
{
	LoggerSettings s;
	s.name = name;
	bool result = true;
	auto it = properties.begin();
	while (it != properties.end()) {
		const QString& key = it.key();
		const QVariant& value = it.value();
		++it;

		result &= parseProperty(key, value, '.', s);
	}
	if (result) { s.name = name; }
	return result ? s : LoggerSettings();
}

} // namespace Qpe

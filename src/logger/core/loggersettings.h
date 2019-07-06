#ifndef CORE_LOGGERSETTINGS_H
#define CORE_LOGGERSETTINGS_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QVariant>
#include <QStringList>

namespace Qpe
{

struct LoggerSettings
{
	QString name;

	QMap<QString /*logger name*/, QVariantMap /*properties*/> loggers;
	QMap<QString /*appender name*/, QVariantMap /*properties*/> appenders;
	QMap<QString /*filter name*/, QVariantMap /*properties*/> filters;

	static LoggerSettings fromSettings(const QString& fileName, const char* codecName);
	static LoggerSettings fromProperties(const QString& name, const QVariantMap& properties);
};

} // namespace Qpe

#endif // CORE_LOGGERSETTINGS_H

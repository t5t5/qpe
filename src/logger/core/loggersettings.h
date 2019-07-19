#ifndef CORE_LOGGERSETTINGS_H
#define CORE_LOGGERSETTINGS_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <QVariant>
#include <QStringList>

namespace Qpe
{

namespace PrivateLogger
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

} // namespace PrivateLogger

} // namespace Qpe

#endif // Q_QDOC

#endif // CORE_LOGGERSETTINGS_H

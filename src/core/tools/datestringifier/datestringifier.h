#ifndef TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_H
#define TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <QDateTime>

#include <Qpe/Qpe>

namespace Qpe
{

class DateStringifierPrivate;
class QPE_CORE_EXPORT DateStringifier
{
	QPE_DECLARE_PRIVATE(DateStringifier)
protected:
	QScopedPointer<DateStringifierPrivate> d_ptr;
public:
	DateStringifier(const QString& format = QString());
	DateStringifier(const DateStringifier& other);
	~DateStringifier();

	DateStringifier& operator=(const DateStringifier& other);

	void setFormatString(const QString& format);

	QString format(const QDateTime& dateTime) const;
	QString format(const QDate& date) const;
	QString format(const QTime& time) const;

	static QString format(const QString& format, const QDateTime& dateTime);
	static QString format(const QString& format, const QDate& date);
	static QString format(const QString& format, const QTime& time);
};

} // namespace Qpe

#endif // TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_H

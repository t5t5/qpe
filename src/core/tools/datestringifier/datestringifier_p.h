#ifndef TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_P_H
#define TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <functional>

#include <QDateTime>
#include <QString>
#include <QList>

#include <Qpe/Qpe>

namespace Qpe
{

class DateStringifier;
class DateStringifierPrivate
{
	QPE_DECLARE_PUBLIC(DateStringifier)
protected:
	DateStringifier* q_ptr;
public:
	DateStringifierPrivate();
	~DateStringifierPrivate();

	void setFormatString(const QString& format);
	QString createString(
		const QDateTime& dateTime, const QDate& date, const QTime& time) const;

private:
	enum Token
	{
		UndefinedToken,
		ExpressionToken,
		QuoutedTextToken,
		TextToken,
	};

	typedef std::function<void(const QDateTime&, const QDate&, const QTime&, QString&)> Handler;
	struct Expression
	{
		Handler handler;
		QString text;
		bool isText;
		Expression() : isText(false) { }
	};
	typedef QList<Expression> Expressions;

	bool isAmPmMode() const;
	void addExpression(Token token, int startPosition, int lastPosition = -1);
	Handler createExpression(const QString& name);

	bool am_pm;
	QString format;
	mutable Expressions expressions;

	int maxLength;
	mutable QString cacheResult;

	QList<QString> shortMonthNames;
	int shortMonthNameMaxLength;
	QList<QString> longMonthNames;
	int longMonthNameMaxLength;
	QList<QString> shortDayNames;
	int shortDayNameMaxLength;
	QList<QString> longDayNames;
	int longDayNameMaxLength;
	QList<QString> am_pm_lower;
	QList<QString> am_pm_upper;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // TOOLS_DATESTRINGIFIER_DATESTRINGIFIER_P_H

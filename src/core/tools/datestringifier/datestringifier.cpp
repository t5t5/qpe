#include "datestringifier.h"
#include "datestringifier_p.h"

#include <QTimeZone>

#include <Qpe/Core/StaticStringifierDec>

/*!
  \class Qpe::DateStringifier
  \inmodule core
  \brief Класс для преобразование даты и времени в строку.
  \inheaderfile Qpe/Core/DateStringifier
  \ingroup core
 
  Главное отличие Qpe::DateStringifier от QDateTime::toString() состоит в том,
  что формат строки разбирается только один раз, а потом может быть применен
  много раз для преоразование дат и времени.

  \section1 Строка форматирования.
 
  Параметры строк форматирования для даты:
  \table
    \row \li d    \li номер дня в месяце без ведущих нулей (1 - 31)
	\row \li dd   \li номер для в месяце с ведущим нулем (01 - 31)
	\row \li ddd  \li краткое локализованное имя дня недели
	\row \li dddd \li полное локализованное имя дня недели
	\row \li M    \li номер месяца без ведущих нулей (1 - 12)
	\row \li MM   \li номер месяца с ведущим нулем (01 - 12)
	\row \li MMM  \li краткое локализованное имя месяца
	\row \li MMMM \li полное локализованное имя месяца
	\row \li yy   \li год в виде двух цифр (00 - 99)
	\row \li yyyy \li год в виде четырех цифр
  \endtable

  Параметры строк форматирования для времени:
  \table
    \row \li h    \li час без ведущих нулей (0 - 23, или если включен AM/PM 1 - 12)
	\row \li hh   \li час с ведущим нулем (00 - 23, или если включен AM/PM 01 - 12)
	\row \li H    \li час без ведущих нулей (0 - 23, невзирая на AM/PM)
	\row \li HH   \li час с ведущим нулем (00 - 23, невзирая на AM/PM)
	\row \li m    \li минута без ведущих нулей (0 - 59)
	\row \li mm   \li минута с ведущим нулем (00 - 59)
	\row \li s    \li секунда без ведущих нулей (0 - 59)
	\row \li ss   \li секунда с ведущим нулем (00 - 59)
	\row \li z    \li тысячная доля секунда без ведущих нулей (0 - 999)
	\row \li zzz  \li тысячная доля секунда с ведущими нулями (000 - 999)
	\row \li AP   \li режим отображения AM/PM, отображается как "AM" или "PM"
	\row \li ap   \li режим отображения AM/PM, отображается как "am" или "pm"
	\row \li t    \li абревиатура временной зоны
	\row \li tt   \li смещение часового пояса, отображается как +HH:mm или -HH:mm
  \endtable

  Строка форматировани может содержать текстовые блоки заключенные в одиночные
  кавычки ('). Текст не распознанный как параметр форматирования, будет тоже
  вставлен как текст.

  Пример:
  \code
    QDateTime d = QDateTime(QDate(2016,02,12), QTime(14,10,00), Qt::LocalTime, 18000);
    QString s = Qpe::DateStringifier::format("yyyy-MM-ddTHH:mm:sstt", d);
                // 2016-02-12T14:10:00+05:00
  \endcode
 */


namespace Qpe
{

typedef Static::Stringifier<DecBase2Digits> Stringifier2Digits;

DateStringifierPrivate::DateStringifierPrivate()
	: shortMonthNameMaxLength(0)
	, longMonthNameMaxLength(0)
	, shortDayNameMaxLength(0)
	, longDayNameMaxLength(0)
{
	QLocale locale = QLocale::system();
	for (int i = 1; i <= 12; ++i) {
		QString shortMonthName = locale.monthName(i, QLocale::ShortFormat);
		shortMonthNames.append(shortMonthName);
		shortMonthNameMaxLength = qMax(shortMonthNameMaxLength, shortMonthName.length());
		QString longMonthName = locale.monthName(i, QLocale::LongFormat);
		longMonthNames.append(longMonthName);
		longMonthNameMaxLength = qMax(longMonthNameMaxLength, longMonthName.length());

	}
	for (int i = 1; i <= 7; ++i) {
		QString shortDayName = locale.dayName(i, QLocale::ShortFormat);
		shortDayNames.append(shortDayName);
		shortDayNameMaxLength = qMax(shortDayNameMaxLength, shortDayName.length());
		QString longDayName = locale.dayName(i, QLocale::LongFormat);
		longDayNames.append(longDayName);
		longDayNameMaxLength = qMax(longDayNameMaxLength, longDayName.length());
	}

	am_pm_lower << QLatin1String("am") << QLatin1String("pm");
	am_pm_upper << QLatin1String("AM") << QLatin1String("PM");
}

DateStringifierPrivate::~DateStringifierPrivate()
{
}

void DateStringifierPrivate::setFormatString(const QString& f)
{
	format = f;
	am_pm = false;
	expressions.clear();
	maxLength = 0;

	Token token = UndefinedToken;

	const QLatin1Char quote('\'');
	const QLatin1Char empty('\0');

	int pos = -1;
	QChar status(empty);
	for (int i = 0, len = format.length(); i < len; ++i) {
		QChar current = format.at(i);
		if (current == quote) {
			if (status == quote) {				// close quote
				status = empty;
			} else {							// open quote
				addExpression(token, pos, i);
				status = quote;
				token = QuoutedTextToken;
				pos = i;
			}
		} else
		if ((status == quote) || (status == current)) {
			// nothing
		} else {
			addExpression(token, pos, i);
			pos = i;
			if ((current == QLatin1Char('h')) ||
				(current == QLatin1Char('H')) ||
				(current == QLatin1Char('m')) ||
				(current == QLatin1Char('s')) ||
				(current == QLatin1Char('z')) ||
				(current == QLatin1Char('d')) ||
				(current == QLatin1Char('M')) ||
				(current == QLatin1Char('y')) ||
				(current == QLatin1Char('t')))
			{
				status = current;
				token = ExpressionToken;
			} else
			if ((current == QLatin1Char('A'))) {
				status = QLatin1Char('P');
				token = ExpressionToken;
			} else
			if ((current == QLatin1Char('a'))) {
				status = QLatin1Char('p');
				token = ExpressionToken;
			} else {
				status = empty;
				token = TextToken;
			}
		}
	}
	addExpression(token, pos);
	cacheResult.reserve(maxLength);
}

QString DateStringifierPrivate::createString(
	const QDateTime& dt, const QDate& d, const QTime& t) const
{
	if (expressions.isEmpty()) { return QString(); }

	cacheResult.resize(0);
	auto it = expressions.begin();
	while (it != expressions.end()) {
		Expression& data = *it++;
		data.handler(dt, d, t, data.text);
		cacheResult.append(data.text);
	}
	return cacheResult;
}

bool DateStringifierPrivate::isAmPmMode() const
{
	return am_pm;
}

void DateStringifierPrivate::addExpression(
	Token token, int startPosition, int lastPosition)
{
	if ((token == UndefinedToken) || (startPosition < 0)) { return; }

	if (lastPosition == -1) { lastPosition = format.length(); }

	int length = lastPosition - startPosition;
	QString text = format.mid(startPosition, length);

	switch (token) {
	case ExpressionToken: {
		Expression d;
		Handler handler = createExpression(text);
		if (handler) {
			d.handler = handler;
			expressions.append(d);
			return;
		}
		break;
	}
	case QuoutedTextToken: {
		const QLatin1Char quote('\'');
		if (text == QLatin1String("''")) {
			text = quote;
		} else
		if (text == QString(quote.toLatin1())) {
			break;
		} else
		if (text.startsWith(quote) && text.endsWith(quote)) {
			text = text.mid(1, length - 2);
		}
		break;
	}
	case TextToken:
	default:
		break;
	}
	// text handler
	maxLength += text.length();
	if (!expressions.isEmpty() && expressions.last().isText) {
		expressions.last().text.append(text);
	} else {
		Expression d;
		d.isText = true;
		d.text = text;
		d.handler = [] (const QDateTime&, const QDate&, const QTime&, QString&) { };
		expressions.append(d);
	}
}

DateStringifierPrivate::Handler DateStringifierPrivate::createExpression(
	const QString& name)
{
	Handler result;

	if (name == QLatin1String("h")) {
		result = [this] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			int h = t.hour();
			h = !isAmPmMode()
				? h
				: ((h > 12) ? (h - 12) : (h == 0 ? 12 : h));
			Static::Stringifier<DecBase>::format(h, cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("hh")) {
		result = [this] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			int h = t.hour();
			h = !isAmPmMode()
				? h
				: ((h > 12) ? (h - 12) : (h == 0 ? 12 : h));
			Stringifier2Digits::format(h, cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("H")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Static::Stringifier<DecBase>::format(t.hour(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("HH")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Stringifier2Digits::format(t.hour(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("m")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Static::Stringifier<DecBase>::format(t.minute(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("mm")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Stringifier2Digits::format(t.minute(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("s")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Static::Stringifier<DecBase>::format(t.second(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("ss")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Stringifier2Digits::format(t.second(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("z")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Static::Stringifier<DecBase>::format(t.msec(), cache);
		};
		maxLength += 3;
	} else
	if (name == QLatin1String("zzz")) {
		result = [] (const QDateTime&, const QDate&, const QTime& t, QString& cache)
		{
			Static::Stringifier<DecBase3Digits>::format(t.msec(), cache);
		};
		maxLength += 3;
	} else
	if (name == QLatin1String("ap")) {
		am_pm = true;
		result = [this] (const QDateTime&, const QDate&, const QTime& t, QString& r)
		{
			r = am_pm_lower[t.hour() >= 12];
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("AP")) {
		am_pm = true;
		result = [this] (const QDateTime&, const QDate&, const QTime& t, QString& r)
		{
			r = am_pm_upper[t.hour() >= 12];
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("yy")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Stringifier2Digits::format(d.year(), cache);
		};
	} else
	if (name == QLatin1String("yyyy")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Static::Stringifier<DecBase4Digits>::format(d.year(), cache);
		};
		maxLength += 4;
	} else
	if (name == QLatin1String("M")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Static::Stringifier<DecBase>::format(d.month(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("MM")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Stringifier2Digits::format(d.month(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("MMM")) {
		result = [this] (const QDateTime&, const QDate& d, const QTime&, QString& r)
		{
			r = shortMonthNames[d.month() - 1];
		};
		maxLength += shortMonthNameMaxLength;
	} else
	if (name == QLatin1String("MMMM")) {
		result = [this] (const QDateTime&, const QDate& d, const QTime&, QString& r)
		{
			r = longMonthNames[d.month() - 1];
		};
		maxLength += longMonthNameMaxLength;
	} else
	if (name == QLatin1String("d")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Static::Stringifier<DecBase>::format(d.day(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("dd")) {
		result = [] (const QDateTime&, const QDate& d, const QTime&, QString& cache)
		{
			Stringifier2Digits::format(d.day(), cache);
		};
		maxLength += 2;
	} else
	if (name == QLatin1String("ddd")) {
		result = [this] (const QDateTime&, const QDate& d, const QTime&, QString& r)
		{
			r = shortDayNames[d.dayOfWeek() - 1];
		};
		maxLength += shortDayNameMaxLength;
	} else
	if (name == QLatin1String("dddd")) {
		result = [this] (const QDateTime&, const QDate& d, const QTime&, QString& r)
		{
			r = longDayNames[d.dayOfWeek() - 1];
		};
		maxLength += longDayNameMaxLength;
	} else
	if (name == QLatin1String("t")) {
		result = [] (const QDateTime& dt, const QDate&, const QTime&, QString& r)
		{
			r = dt.timeZoneAbbreviation();
		};
		maxLength += 32;
	} else
	if (name == QLatin1String("tt")) {
		result = [] (const QDateTime& dt, const QDate&, const QTime&, QString& r)
		{
			if (r.capacity() < 6) { r.reserve(6); }
			r.resize(0);
			int offset = dt.offsetFromUtc();
			char sign;
			if (offset >= 0) {
				sign = '+';
			} else {
				sign = '-';
				offset = -offset;
			}
			uchar h = static_cast<uchar>(offset / 3600);
			uchar m = static_cast<uchar>((offset % 3600) / 60);
			r.append(sign)
			 .append(Stringifier2Digits::format(h))
			 .append(':')
			 .append(Stringifier2Digits::format(m));
		};
		maxLength += 6;
	}
	return result;
}

// ---------------------------------------------------------------------------

/*!
 * \fn DateStringifier::DateStringifier(const QString& format = QString())
 * Конструктор. \a format - формат вывода даты.
 */
DateStringifier::DateStringifier(const QString& format /* = QString() */)
	: d_ptr(new DateStringifierPrivate())
{
	QA_D();
	d->q_ptr = this;
	d->setFormatString(format);
}

DateStringifier::DateStringifier(const DateStringifier& other)
	: d_ptr(new DateStringifierPrivate())
{
	QA_D();
	d->q_ptr = this;
	d->setFormatString(other.d_ptr->format);
}

DateStringifier::~DateStringifier()
{
}

DateStringifier& DateStringifier::operator=(const DateStringifier& other)
{
	if (this != &other) {
		QA_D();
		d->setFormatString(other.d_ptr->format);
	}
	return *this;
}

/*!
 * \fn void DateStringifier::setFormatString(const QString& format)
 * Установить формат \a format.
 */
void DateStringifier::setFormatString(const QString& format)
{
	QA_D();
	d->setFormatString(format);
}

/*!
 * \fn QString DateStringifier::format(const QDateTime& dateTime) const
 * Вернуть строковое представление даты \a dateTime.
 */
QString DateStringifier::format(const QDateTime& dateTime) const
{
	QA_D();
	return d->createString(dateTime, dateTime.date(), dateTime.time());
}

/*!
 * \fn QString DateStringifier::format(const QDate& date) const
 * Вернуть строковое представление даты \a date.
 */
QString DateStringifier::format(const QDate& date) const
{
	QA_D();
	return d->createString(QDateTime(), date, QTime());
}

/*!
 * \fn QString DateStringifier::format(const QTime& time) const
 * Вернуть строковое представление времени \a time.
 */
QString DateStringifier::format(const QTime& time) const
{
	QA_D();
	return d->createString(QDateTime(), QDate(), time);
}

/*!
 * \fn QString DateStringifier::format(const QString& format, const QDateTime& dateTime)
 * Вернуть строковое представление даты \a dateTime в соответствии с форматом \a format.
 *
 * Аналогично QDateTime::toString
 */
QString DateStringifier::format(const QString& format, const QDateTime& dateTime)
{
	DateStringifierPrivate f;
	f.setFormatString(format);
	return f.createString(dateTime, dateTime.date(), dateTime.time());
}

/*!
 * \fn QString DateStringifier::format(const QString& format, const QDate& date)
 * Вернуть строковое представление даты \a date в соответствии с форматом \a format.
 *
 * Аналогично QDate::toString
 */
QString DateStringifier::format(const QString& format, const QDate& date)
{
	DateStringifierPrivate f;
	f.setFormatString(format);
	return f.createString(QDateTime(), date, QTime());
}

/*!
 * \fn QString DateStringifier::format(const QString& format, const QTime& time)
 * Вернуть строковое представление времени \a time в соответствии с форматом \a format.
 *
 * Аналогично QTime::toString
 */
QString DateStringifier::format(const QString& format, const QTime& time)
{
	DateStringifierPrivate f;
	f.setFormatString(format);
	return f.createString(QDateTime(), QDate(), time);
}

} // namespace Qpe

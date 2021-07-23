#include "stringifier.h"
#include "stringifier_p.h"

#include <QString>
#include <QRegularExpression>

/*!
 * \class Qpe::Stringifier
 * \inmodule core
 * \brief Класс для преобразования числа в строку.
 * \inheaderfile Qpe/Core/Stringifier
 * \ingroup core
 */

/*!
 * \enum Qpe::Stringifier::DigitCase
 *
 * Регистр цифр.
 *
 * \value UpperCase
 *        Верхний регистр.
 * \value LowerCase
 *        Нижний регистр.
 */

namespace Qpe
{

namespace Private
{
	template <typename>
	struct LeadingZero;

	template <>
	struct LeadingZero<WithoutLeadingZero> { static const int value = 0; };

	template <>
	struct LeadingZero<WithLeadingZero> { static const int value = 1; };

	template <typename>
	struct Prefix;

	template <>
	struct Prefix<WithoutPrefix> { static const int value = 0; };

	template <>
	struct Prefix<WithPrefix> { static const int value = 1; };

	template <typename>
	struct Case;

	template <>
	struct Case<LowerCase> { static const int value = 0; };

	template <>
	struct Case<UpperCase> { static const int value = 1; };

} // namespace Private


StringifierPrivate::StringifierPrivate(int b, bool lz, bool pr, bool uc)
	: base(b)
	, leadingZero(lz)
	, prefixRequired(pr)
	, upperCase(uc)
{
}

StringifierPrivate::~StringifierPrivate()
{
}

void StringifierPrivate::initialize()
{
	insertCreator<DecBase, WithoutLeadingZero, WithoutPrefix, UpperCase>();
	insertCreator<DecBase, WithoutLeadingZero, WithoutPrefix, LowerCase>();
	insertCreator<DecBase, WithoutLeadingZero, WithPrefix,    UpperCase>();
	insertCreator<DecBase, WithoutLeadingZero, WithPrefix,    LowerCase>();
	insertCreator<DecBase, WithLeadingZero,    WithoutPrefix, UpperCase>();
	insertCreator<DecBase, WithLeadingZero,    WithoutPrefix, LowerCase>();
	insertCreator<DecBase, WithLeadingZero,    WithPrefix,    UpperCase>();
	insertCreator<DecBase, WithLeadingZero,    WithPrefix,    LowerCase>();

	insertCreator<HexBase, WithoutLeadingZero, WithoutPrefix, UpperCase>();
	insertCreator<HexBase, WithoutLeadingZero, WithoutPrefix, LowerCase>();
	insertCreator<HexBase, WithoutLeadingZero, WithPrefix,    UpperCase>();
	insertCreator<HexBase, WithoutLeadingZero, WithPrefix,    LowerCase>();
	insertCreator<HexBase, WithLeadingZero,    WithoutPrefix, UpperCase>();
	insertCreator<HexBase, WithLeadingZero,    WithoutPrefix, LowerCase>();
	insertCreator<HexBase, WithLeadingZero,    WithPrefix,    UpperCase>();
	insertCreator<HexBase, WithLeadingZero,    WithPrefix,    LowerCase>();
}

template <int Base, typename TLeadingZero, typename TPrefix, typename TCase>
void StringifierPrivate::insertCreator()
{
	using namespace Private;
	QList<int> key({
		Base,
		LeadingZero<TLeadingZero>::value,
		Prefix<TPrefix>::value,
		Case<TCase>::value });

	creators.insert(key,
		QSharedPointer<BaseCreator>(new Creator<Base, TLeadingZero, TPrefix, TCase>()));
}

#define CAPTURE_BASE 1
#define CAPTURE_PARAM_START 2
#define CAPTURE_PARAM_END 4

bool StringifierPrivate::setFormatString(const QString& formatString)
{
	if (formatString.isEmpty()) { return false; }
	int _base = 10;
	bool _leadingZero = false;
	bool _prefixRequired = false;
	bool _upperCase = false;
	QRegularExpression re("^(10|16)(p|l|u)?(p|l|u)?(p|l|u)?");
	QRegularExpressionMatch match = re.match(formatString);
	if (!match.hasMatch()) { return false; }
	_base = match.captured(CAPTURE_BASE).toInt();
	int max = qMin(match.lastCapturedIndex(), CAPTURE_PARAM_END);
	for (int i = CAPTURE_PARAM_START; i <= max; ++i) {
		char param = match.captured(i)[0].toLatin1();
		if (param == '\0') break;
		switch (param) {
		case 'p':
			_prefixRequired = true;
			break;
		case 'l':
			_leadingZero = true;
			break;
		case 'u':
			_upperCase = true;
			break;
		}
	}
	bool changed = false;
	if (base != _base) {
		base = _base;
		changed = true;
	}
	if (leadingZero != _leadingZero) {
		leadingZero = _leadingZero;
		changed = true;
	}
	if (prefixRequired != _prefixRequired) {
		prefixRequired = _prefixRequired;
		changed = true;
	}
	if (upperCase != _upperCase) {
		upperCase = _upperCase;
		changed = true;
	}
	if (changed) { update(); }
	return true;
}

void StringifierPrivate::update()
{
	QList<int> key({ base, leadingZero, prefixRequired, upperCase });

	auto it = creators.find(key);
	if (it == creators.end()) { return; }

	m1 = (*it)->sign1();
	m2 = (*it)->sign2();
	m3 = (*it)->sign3();
}

template<typename T>
QByteArray StringifierPrivate::format(T n) const
{
	return boost::fusion::at_key<T>(m1)(n);
}

template<typename T>
QByteArray& StringifierPrivate::format(T n, QByteArray& result) const
{
	return boost::fusion::at_key<T>(m2)(n, result);
}

template<typename T>
QString& StringifierPrivate::format(T n, QString& result) const
{
	return boost::fusion::at_key<T>(m3)(n, result);
}

// ---------------------------------------------------------------------------

/*!
 * \fn Stringifier::Stringifier(int base = 10, bool lz = false,
 *         bool prefix = false, DigitCase digitCase = LowerCase)
 * Конструктор. \a base - система счисления (досупны 10 и 16),
 * \a lz - \c true - ведущие нули включены, \a prefix - \c true - префикс включен
 * (для шестнадцатеричной 0x), \a digitCase - регистр цифр.
 */
Stringifier::Stringifier(
		int base /* = 10*/, bool lz /* = false*/,
		bool prefix /* = false */, DigitCase digitCase /* = LowerCase */)
	: d_ptr(new StringifierPrivate(base, lz, prefix, digitCase == UpperCase))
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
	d->update();
}

/*!
 * \fn Stringifier::Stringifier(const QString& formatString)
 * Конструктор. \a formatString - строка формата,
 * смотрите Stringifier::setFormatString
 */
Stringifier::Stringifier(const QString& formatString)
	: d_ptr(new StringifierPrivate(0, false, false, false))
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
	d->setFormatString(formatString);
}

/*!
 * \fn Stringifier::Stringifier(const Stringifier& other)
 * Конструктор копировщик из \a other.
 */
Stringifier::Stringifier(const Stringifier& other)
	: d_ptr(new StringifierPrivate(
		other.d_ptr->base, other.d_ptr->leadingZero,
		other.d_ptr->prefixRequired, other.d_ptr->upperCase))
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
	d->update();
}

/*!
 * \fn Stringifier::~Stringifier()
 * Деструктор.
 */
Stringifier::~Stringifier()
{
}

/*!
 * \fn Stringifier& Stringifier::operator=(const Stringifier& other)
 * Присвоить текущему объекту значение из \a other.
 */
Stringifier& Stringifier::operator=(const Stringifier& other)
{
	if (this != &other) {
		QA_D();
		d->base = other.d_ptr->base;
		d->leadingZero = other.d_ptr->leadingZero;
		d->prefixRequired = other.d_ptr->prefixRequired;
		d->upperCase = other.d_ptr->upperCase;
		d->initialize();
		d->update();
	}
	return *this;
}

/*!
 * \fn bool Stringifier::setBase(int base)
 * Выбрать систему счисления \a base.
 * Если база отличается от 10 или 16 возвращается \c false, иначе \c true.
 */
bool Stringifier::setBase(int base)
{
	if ((base != DecBase) && (base != HexBase)) { return false; }

	QA_D();
	bool changed = d->base != base;
	if (changed) {
		d->base = base;
		d->update();
	}
	return true;
}

/*!
 * \fn int Stringifier::base() const
 * Получить систему счисления.
 */
int Stringifier::base() const
{
	QA_D();
	return d->base;
}

/*!
 * \fn void Stringifier::setLeadingZero(bool leadingZero)
 * \a leadingZero - \c true, для включения ведущих нулей.
 */
void Stringifier::setLeadingZero(bool leadingZero)
{
	QA_D();
	bool changed = d->leadingZero != leadingZero;
	if (changed) {
		d->leadingZero = leadingZero;
		d->update();
	}
}

/*!
 * \fn void Stringifier::enableLeadingZero()
 * Включить ведущие нули, аналогично Stringifier::setLeadingZero(true).
 */
void Stringifier::enableLeadingZero()
{
	QA_D();
	if (!d->leadingZero) {
		d->leadingZero = true;
		d->update();
	}
}

/*!
 * \fn void Stringifier::disableLeadingZero()
 * Выключить ведущие нули, аналогично Stringifier::setLeadingZero(false).
 */
void Stringifier::disableLeadingZero()
{
	QA_D();
	if (d->leadingZero) {
		d->leadingZero = false;
		d->update();
	}
}

/*!
 * \fn bool Stringifier::isLeadingZero() const
 * Проверить включены ли ведущие нули, \c true - включены.
 */
bool Stringifier::isLeadingZero() const
{
	QA_D();
	return d->leadingZero;
}

/*!
 * \fn void Stringifier::setPrefixRequired(bool prefixRequired)
 * \a prefixRequired - \c true, для включения префикса. "0x" для \c base = 16.
 */
void Stringifier::setPrefixRequired(bool prefixRequired)
{
	QA_D();
	bool changed = d->prefixRequired != prefixRequired;
	if (changed) {
		d->prefixRequired = prefixRequired;
		d->update();
	}
}

/*!
 * \fn void Stringifier::enablePrefixRequired()
 * Включить префикс, аналогичо Stringifier::setPrefixRequired(true).
 */
void Stringifier::enablePrefixRequired()
{
	QA_D();
	if (!d->prefixRequired) {
		d->prefixRequired = true;
		d->update();
	}
}

/*!
 * \fn void Stringifier::disablePrefixRequired()
 * Выключить префикс, аналогичо Stringifier::setPrefixRequired(false).
 */
void Stringifier::disablePrefixRequired()
{
	QA_D();
	if (d->prefixRequired) {
		d->prefixRequired = false;
		d->update();
	}
}

/*!
 * \fn bool Stringifier::isPrefixRequired() const
 * Проверить включен ли префикс, \c true - включен.
 */
bool Stringifier::isPrefixRequired() const
{
	QA_D();
	return d->prefixRequired;
}

/*!
 * \fn void Stringifier::setDigitCase(DigitCase digitCase)
 * Установить регистр цифр \a digitCase.
 */
void Stringifier::setDigitCase(DigitCase digitCase)
{
	QA_D();
	bool upperCase = digitCase == UpperCase;
	bool changed = d->upperCase != upperCase;
	if (changed) {
		d->upperCase = upperCase;
		d->update();
	}
}

/*!
 * \fn void Stringifier::setUpperCase()
 * Установить верхний регистр цифр,
 * аналогично Stringifier::setDigitCase(Stringifier::UpperCase).
 */
void Stringifier::setUpperCase()
{
	QA_D();
	if (!d->upperCase) {
		d->upperCase = true;
		d->update();
	}
}

/*!
 * \fn void Stringifier::setLowwerCase()
 * Установить нижний регистр цифр,
 * аналогично Stringifier::setDigitCase(Stringifier::LowerCase).
 */
void Stringifier::setLowwerCase()
{
	QA_D();
	if (d->upperCase) {
		d->upperCase = false;
		d->update();
	}
}

/*!
 * \fn Stringifier::DigitCase Stringifier::digitCase() const
 * Получить регист цифр.
 */
Stringifier::DigitCase Stringifier::digitCase() const
{
	QA_D();
	return d->upperCase ? UpperCase : LowerCase;
}

/*!
 * \fn bool Stringifier::isUpperCase() const
 * Возвращает \c true, если регистр цифр Stringifier::UpperCase.
 */
bool Stringifier::isUpperCase() const
{
	QA_D();
	return d->upperCase;
}

/*!
 * \fn bool Stringifier::isLowwerCase() const
 * Возвращает \c true, если регистр цифр Stringifier::LowerCase.
 */
bool Stringifier::isLowwerCase() const
{
	QA_D();
	return !d->upperCase;
}

/*!
  \fn bool Stringifier::setFormatString(const QString& formatString)
  Настроить преобразователь в соответствии со строкой форматирования
  \a formatString.

  Формат:
  \b DDplu

  где:
  \list
    \li \b DD - база системы счисления (10 или 16);
    \li \b p - если присутствует, префикс включен (для base = 16);
    \li \b l - если присутствует, ведущие нули включены;
    \li \b u - если присутствует, верхний регист для цифр включен.
  \endlist
  Параметры \b p, \b l, \b u могут стоять в любом порядке.

  Параметр \b DD может быть только в начале строки.

  Примеры:
  \code
  Qpe::Stringifier s;
  s.setFormatString("10l");   // десятиричная система счисления, ведушие нули включены.
  qDebug() << s.format(100);  // "0000000100"

  s.setFormatString("16");    // шестнадцатеричная система счисления
  qDebug() << s.format(127);  // 7f

  s.setFormatString("16plu"); // шестнадцатеричная, ведущие нули, префикс, верхний регистр
  qDebug() << s.format(127);  // 0x0000007F
  \endcode
 */
bool Stringifier::setFormatString(const QString& formatString)
{
	QA_D();
	return d->setFormatString(formatString);
}

/*!
 * \fn QByteArray Stringifier::format(char n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(char n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(uchar n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(uchar n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(signed char n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(signed char n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(short n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(short n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(ushort n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(ushort n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(int n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(int n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(uint n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(uint n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(long n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(long n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(ulong n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(ulong n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(qint64 n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(qint64 n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(quint64 n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(quint64 n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray Stringifier::format(void* n) const
 * Преобразовать число \a n в строку.
 */
QByteArray Stringifier::format(void* n) const
{
	QA_D();
	return d->format(n);
}

/*!
 * \fn QByteArray& Stringifier::format(char n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(char n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(uchar n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(uchar n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(signed char n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(signed char n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(short n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(short n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(ushort n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(ushort n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(int n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(int n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(uint n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(uint n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(long n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(long n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(ulong n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(ulong n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(qint64 n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(qint64 n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(quint64 n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(quint64 n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QByteArray& Stringifier::format(void* n, QByteArray& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QByteArray& Stringifier::format(void* n, QByteArray& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(char n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(char n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(uchar n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(uchar n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(signed char n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(signed char n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(short n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(short n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(ushort n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(ushort n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(int n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(int n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(uint n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(uint n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(long n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(long n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(ulong n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(ulong n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(qint64 n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(qint64 n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(quint64 n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(quint64 n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

/*!
 * \fn QString& Stringifier::format(void* n, QString& result) const
 * Преобразовать число \a n в строку, результат занести в \a result.
 */
QString& Stringifier::format(void* n, QString& result) const
{
	QA_D();
	return d->format(n, result);
}

} // namespace Qpe

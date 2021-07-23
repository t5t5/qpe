
/*!
  \class Qpe::ConversionPattern
  \inmodule core
  \brief Класс форматирования строк.
  \inheaderfile Qpe/Core/ConversionPattern
  \ingroup core

  \section1 Expressions - Управляющие выражения.

  Представляют собой строки следующей стуктуры:
  \code
  %[[-][min]][.max]name[{properties}]
  \endcode
  где:
  \table
    \row \li \b %          \li признак начала выражения;
    \row \li \b -(минус)   \li выравнивание строк, если есть минус используется выравнивание по левому краю;
    \row \li \b min        \li минимальный размер поля, если размер поля меньше
                               чем \b min, строка будет дозаполнена символом
                               заполнителя (см. свойство \b padding)
    \row \li \b max        \li максимальный размер поля
    \row \li \b name       \li имя поля
    \row \li \b properties \li дополнительные свойства
  \endtable
  Необязательные поля указаны в квадратных скобках.

  \section1 Properties - Дополнительные свойства.

  Свойства представляют собой строки вида:
  \code
  {name1[=value1][;name2[=value2[...]]}
  \endcode
  где:
  \table
    \row \li \b name  \li имя свойства
    \row \li \b value \li значение свойства, если отсутствует,
                          то свойство используется как флаг и значение становится в \b true
  \endtable
  В значениях свойств также могут быть использованы символы "{", "}" и ";",
  с предварительным экранированием символом: "\\", например:
  \code
  {delim=\;;open=\{;close=\}}
  \endcode
  значения свойств будут следующими:
  \table
    \row \li delim \li ;
    \row \li open  \li \{
    \row \li close \li }
  \endtable

  У всех полей есть скрытое свойство \b padding установленное по умолчанию
  в символ пробела. Его тоже можно переопределить:
  \code
  {padding=.}
  \endcode
  будет переопределен в символ ".".

  \section1 Pattern - Шаблон строки.

  Шаблон представляет собой строку с включенными в нее управляющими выражениями:
  \code
  log_%d{format=yyyy-MM-dd}_%N__%c.log.txt
  \endcode
  где:

  \b{%d{format=yyyy-MM-dd}}, \b{%N} и \b{%c} управляющие выражения.

  \section1 Expression factory - Фабрика выражений.

  Для каждого найденного в строке выражения запускается метод
  ExpressionFactory \c factory переданный в конструкторах Qpe::ConversionPattern.

  ExpressionFactory в соответствии со своей логикой, для кажого элемента должен
  вернуть ExpressionFunctor, который вызывается в момент создания строки методом:
  Qpe::ConversionPattern::createString().

  \section1 Пример.
  \code
    QString pattern = "some %s1{upper;delim=\\;;format=yyyy;} other %-10s2{padding==;char=\\{} text";

    typedef Qpe::ConversionPattern<QVariantMap>    Conversion;

    auto factory = [] (const QString& el, const QVariantMap& prop)
        -> Conversion::ExpressionFunctor
    {
        if (el == "s1") {
            return [el, prop] (const QVariantMap& data)
            {
                QString value = data.value(el).toString();
                if (prop.value("upper").toBool()) {
                    value = value.toUpper();
                }
                return value;
            };
        } else
        if (el == "s2") {
            return [el, prop] (const QVariantMap& data)
            {
                QString value = data.value(el).toString();
                if (prop.value("upper").toBool()) {
                    value = value.toUpper();
                }
                return value;
            };
        };
        return [el, prop] (const QVariantMap& ) { return QString(); };
    };

    Conversion c(pattern, factory);
    QString s = c.createString(
            QVariantMap({ { "s1", "s1_value"}, { "s2", "s2_value" } }));
    qDebug() << s;    // some S1_VALUE other s2_value== text
  \endcode
 */

/*!
 * \typedef Qpe::ConversionPattern::ExpressionFunctor
 *
 * Синоним для std::function<QString(const TData& data)>
 *
 * \a data - данные.
 */

/*!
 * \typedef Qpe::ConversionPattern::ExpressionFactory
 *
 * Синоним для std::function<ExpressionFunctor(const QString& name, const QVariantMap& properties>
 *
 * \a name - имя выражения, \a properties - свойства выражения.
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> Qpe::ConversionPattern<TData, CacheSize>::ConversionPattern(
 *         const QString& pattern, ExpressionFactory&& factory)
 * Конструктор. \a pattern - шаблон строки. \a factory - фабрика элементов.
 * Элементы будут выбраны с помощью регулярного выражения:
 * \code
 * \w+
 * \endcode
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> Qpe::ConversionPattern<TData, CacheSize>::ConversionPattern(
 *         const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
 * Конструктор. \a pattern - шаблон строки.
 * \a names - список элементов в шаблоне строки. \a factory - фабрика элементов.
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> void Qpe::ConversionPattern<TData, CacheSize>::initialize(
 *         const QString& pattern, ExpressionFactory&& factory)
 * Инициализация. \a pattern - шаблон строки. \a factory - фабрика элементов.
 * Элементы будут выбраны с помощью регулярного выражения:
 * \code
 * \w+
 * \endcode
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> void Qpe::ConversionPattern<TData, CacheSize>::initialize(
 *         const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
 * Инициализация. \a pattern - шаблон строки.
 * \a names - список элементов в шаблоне строки. \a factory - фабрика элементов.
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> bool Qpe::ConversionPattern<TData, CacheSize>::containsExpressions() const
 * Возвращает \c true, если после инициализации в сроке шаблона нашлись управляющие
 * выражения.
 */

/*!
 * \fn template <typename TData, int CacheSize = 1024> QString Qpe::ConversionPattern<TData, CacheSize>::createString(
 *         const TData& data) const
 * Возвращает преобразованную строку. \a data - значение которое будет передано в
 * ExpressionFunctor для элементов.
 */

// ------------------------------------------------------------------------

/*!
  \class Qpe::SimpleConversionPattern
  \inmodule core
  \brief Упрощенный класс форматирования строк.
  \inheaderfile Qpe/Core/ConversionPattern
  \ingroup core
 
  В отличие от Qpe::ConversionPattern формирование окончательной строки
  происходит сразу в конструкторе, сделано за счет того что
  Qpe::SimpleConversionPattern::ExpressionFactory возвращает сразу строку.
 
  Пример:
  \code
    QString pattern = "some %s1{upper;delim=\\;;format=yyyy;} other %-10s2{padding==;char=\\{} text";

    QVariantMap data({ { "s1", "s1_value"}, { "s2", "s2_value" } });

    auto factory = [data]
        (const QString& el, const QVariantMap& prop)
    {
        if (el == "s1") {
            QString value = data.value(el).toString();
            if (prop.value("upper").toBool()) {
                value = value.toUpper();
            }
            return value;
        } else
        if (el == "s2") {
            QString value = data.value(el).toString();
            if (prop.value("upper").toBool()) {
                value = value.toUpper();
            }
            return value;
        }
        return QString();
    };

    Qpe::SimpleConversionPattern c(pattern, factory);

    QString s = c.createString();
    qDebug() << s;   // "some S1_VALUE other s2_value== text"
  \endcode
 */

/*!
 * \typedef Qpe::SimpleConversionPattern::ExpressionFactory
 *
 * Синоним для std::function<QString(const QString& name, const QVariantMap& properties>
 * \a name - имя элемента, \a properties - свойства элемента.
 */


/*!
 * \fn Qpe::SimpleConversionPattern::SimpleConversionPattern(const QString& pattern, ExpressionFactory&& factory)
 * Конструктор. \a pattern - шаблон строки. \a factory - фабрика элементов.
 * Элементы будут выбраны с помощью регулярного выражения:
 * \code
 * \w+
 * \endcode
 */

/*!
 * \fn Qpe::SimpleConversionPattern::SimpleConversionPattern(
 *     const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
 * Конструктор. \a pattern - шаблон строки.
 * \a names - список элементов в шаблоне строки. \a factory - фабрика элементов.
 */

/*!
 * \fn void Qpe::SimpleConversionPattern::initialize(
 *          const QString& pattern, ExpressionFactory&& factory)
 * Инициализация. \a pattern - шаблон строки. \a factory - фабрика элементов.
 * Элементы будут выбраны с помощью регулярного выражения:
 * \code
 * \w+
 * \endcode
 */

/*!
 * \fn void Qpe::SimpleConversionPattern::initialize(
 *          const QString& pattern, const QStringList& names, ExpressionFactory&& factory)
 * Инициализация. \a pattern - шаблон строки.
 * \a names - список элементов в шаблоне строки. \a factory - фабрика элементов.
 */

/*!
 * \fn QString Qpe::SimpleConversionPattern::createString() const
 * Возвращает преобразованную строку.
 */

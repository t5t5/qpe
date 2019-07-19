
/*!
 * \class Qpe::LoggerFilter
 * \inmodule logger
 * \brief Абстрактный фильтр событий для logger'а.
 * \inheaderfile Qpe/Logger/LoggerFilter
 * \ingroup logger
 */

/*!
 * \typedef Qpe::LoggerFilterPointer
 *
 * Синоним для QSharedPointer<LoggerFilter>.
 */

/*!
 * \typedef Qpe::LoggerFilterList
 *
 * Синоним для QList<LoggerFilterPointer>.
 */

/*!
 * \typedef LoggerFilterCreator
 *
 * Синоним для std::function<LoggerFilterPointer (const QVariantMap&)>.
 */


/*!
 * \fn bool Qpe::LoggerFilter::initialize(const QVariantMap& properties);
 * Виртуальный метод инициализации фильтра. \a properties - настройки.
 * Метод должен вернуть \c true, если фильтр нормально настроен, иначе \c false.
 */

/*!
 * \fn bool Qpe::LoggerFilter::testEvent(const LoggerEvent* loggerEvent) const;
 * Проверить событие \a loggerEvent удовлетворяет ли фильтру, вернуть \c true,
 * если событие прошло.
 */

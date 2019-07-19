
/*!
 * \class Qpe::LoggerAppender
 * \inmodule logger
 * \brief Абстрактный appender для logger'а.
 * \inheaderfile Qpe/Logger/LoggerAppender
 * \ingroup logger
 */

/*!
 * \typedef Qpe::LoggerAppenderPointer
 *
 * Синоним для QSharedPointer<LoggerAppender>.
 */

/*!
 * \typedef Qpe::LoggerAppenderList
 *
 * Синоним для QList<LoggerAppenderPointer>.
 */

/*!
 * \typedef LoggerAppenderCreator
 *
 * Синоним для std::function<LoggerAppenderPointer (const QVariantMap&)>.
 */


/*!
 * \fn bool Qpe::LoggerAppender::initialize(const QVariantMap& properties);
 * Виртуальный метод инициализации appender'а. \a properties - настройки.
 * Метод должен вернуть \c true, если appender нормально настроен, иначе \c false.
 */

/*!
 * \fn void Qpe::LoggerAppender::append(const LoggerEvent* loggerEvent);
 * Метод вывода события \a loggerEvent в лог.
 */

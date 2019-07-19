#ifndef APPENDERS_APPENDER_ABSTRACTPATTERN_P_H
#define APPENDERS_APPENDER_ABSTRACTPATTERN_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef Q_QDOC

#include <Qpe/Core/ConversionPattern>

#include <Qpe/Logger/EventType>

namespace Qpe
{

class LoggerEvent;

namespace PrivateLogger
{

class LineAdapter;
typedef QSharedPointer<LineAdapter> LineAdapterPointer;

struct EventWrapper
{
	EventWrapper(
		const LoggerEvent* loggerEvent, const LineAdapterPointer& lineAdapter);
	EventWrapper(
		const LoggerEvent* loggerEvent);
	~EventWrapper();

	inline uint loggerId() const;
	inline uint eventId() const;
	inline QString componentName() const;
	inline QObject* object() const;
	inline QString objectName() const;
	inline QString className() const;
	inline EventType eventType() const;
	inline QString eventTypeName() const;
	inline QThread* thread() const;
	inline QString threadName() const;
	inline QDateTime dateTime() const;

	inline bool hasMessage() const;
	inline QString message() const;
private:
	const LoggerEvent* loggerEvent;
	LineAdapterPointer lineAdapter;
};

typedef Qpe::ConversionPattern<EventWrapper> Pattern;

struct Factory
{
	static Pattern::ExpressionFunctor createExpression(
		const QString& expressionName, const QVariantMap& properties);
	static QStringList expressionNames();
};

} // namespace PrivateLogger

// ------------------------------------------------------------------------

class AbstractPatternLoggerAppender;
class AbstractPatternLoggerAppenderPrivate
{
	QPE_DECLARE_PUBLIC(AbstractPatternLoggerAppender)
protected:
	AbstractPatternLoggerAppender* q_ptr;
public:
	AbstractPatternLoggerAppenderPrivate();
	virtual ~AbstractPatternLoggerAppenderPrivate();

	bool initializePatterns(const QVariantMap& properties);

	QString createMessage(const LoggerEvent* loggerEvent);
private:
	QList<PrivateLogger::Pattern> patterns;

	PrivateLogger::LineAdapterPointer lineAdapter;
};

} // namespace Qpe

#endif // Q_QDOC

#endif // APPENDERS_APPENDER_ABSTRACTPATTERN_P_H

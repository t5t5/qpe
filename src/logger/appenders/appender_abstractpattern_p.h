#ifndef QPE_APPENDERS_APPENDER_ABSTRACTPATTERN_P_H
#define QPE_APPENDERS_APPENDER_ABSTRACTPATTERN_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Qpe/Core/ConversionPattern>

#include <Qpe/Logger/EventType>

namespace Qpe
{

class LoggerEvent;

namespace LoggerPrivate
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
	inline QString pluginName() const;
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

} // namespace LoggerPrivate

// ------------------------------------------------------------------------

class AbstractPatternLoggerAppender;
class AbstractPatternLoggerAppenderPrivate
{
	Q_DECLARE_PUBLIC(AbstractPatternLoggerAppender)
protected:
	AbstractPatternLoggerAppender* q_ptr;
public:
	AbstractPatternLoggerAppenderPrivate();
	virtual ~AbstractPatternLoggerAppenderPrivate();

	void initializePattern(
		const QString& firstLinePattern,
		const QString& otherLinePattern);

	QString createMessage(const LoggerEvent* loggerEvent);
private:
	LoggerPrivate::Pattern pattern1;
	LoggerPrivate::Pattern pattern2;

	LoggerPrivate::LineAdapterPointer lineAdapter;
};

} // namespace Qpe

#endif // QPE_APPENDERS_APPENDER_ABSTRACTPATTERN_P_H
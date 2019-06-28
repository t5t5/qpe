#ifndef QPE_FILTERS_FILTER_CLASSNAME_H
#define QPE_FILTERS_FILTER_CLASSNAME_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>
#include <Qpe/Logger/LoggerFilter>

namespace Qpe
{

class ClassNameLoggerFilterPrivate;
class ClassNameLoggerFilter : public LoggerFilter
{
	Q_DECLARE_PRIVATE(ClassNameLoggerFilter)
protected:
	QScopedPointer<ClassNameLoggerFilterPrivate> d_ptr;
	ClassNameLoggerFilter(ClassNameLoggerFilterPrivate* dd);
public:
	ClassNameLoggerFilter();
	virtual ~ClassNameLoggerFilter();

	// LoggerFilter interface
	virtual bool initialize(const QVariantMap& properties);
	virtual bool testEvent(const LoggerEvent* loggerEvent) const;
};

} // namespace Qpe

#endif // QPE_FILTERS_FILTER_CLASSNAME_H

#ifndef FILTERS_FILTER_CLASSNAME_H
#define FILTERS_FILTER_CLASSNAME_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>

#include <Qpe/Qpe>
#include <Qpe/Logger/LoggerFilter>

namespace Qpe
{

class ClassNameLoggerFilterPrivate;
class ClassNameLoggerFilter : public LoggerFilter
{
	QPE_DECLARE_PRIVATE(ClassNameLoggerFilter)
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

#endif // FILTERS_FILTER_CLASSNAME_H

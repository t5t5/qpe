#ifndef QPE_FILTERS_FILTER_CLASSNAME_P_H
#define QPE_FILTERS_FILTER_CLASSNAME_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QSet>

namespace Qpe
{

class ClassNameLoggerFilter;
class ClassNameLoggerFilterPrivate
{
	Q_DECLARE_PUBLIC(ClassNameLoggerFilter)
protected:
	ClassNameLoggerFilter* q_ptr;
public:
	ClassNameLoggerFilterPrivate();
	~ClassNameLoggerFilterPrivate();

	QSet<QString> includedClasses;
	QSet<QString> excludedClasses;
};

} // namespace Qpe

#endif // QPE_FILTERS_FILTER_CLASSNAME_P_H

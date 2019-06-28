#ifndef QPE_CLEANERS_CLEANER_DATE_P_ENUM_H
#define QPE_CLEANERS_CLEANER_DATE_P_ENUM_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QDir>

namespace Qpe
{

#ifndef Q_QDOC
inline namespace qpe_keepintervaltype
{
/* EXPORT */Q_NAMESPACE
#endif // Q_QDOC

enum KeepIntervalType
{
	Day,
	Month,
	Year,
	Week,
};
Q_ENUM_NS(KeepIntervalType)

#ifndef Q_QDOC
} // namespace qpe_keepintervaltype
#endif // Q_QDOC

#ifndef Q_QDOC
inline namespace qpe_filtertype
{
/* EXPORT */Q_NAMESPACE
#endif // Q_QDOC

enum FilterType
{
	Dirs	= QDir::Dirs,
	Files	= QDir::Files,
};
Q_ENUM_NS(FilterType)

#ifndef Q_QDOC
} // namespace qpe_filtertype
#endif // Q_QDOC
//QPE_FLAG_WRAP(Filter, QDir, Filter, (Files) (Dirs))


} // namespace Qpe

#endif // QPE_CLEANERS_CLEANER_DATE_P_ENUM_H

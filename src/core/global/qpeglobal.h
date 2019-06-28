#ifndef GLOBAL_QPEGLOBAL_H
#define GLOBAL_QPEGLOBAL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QtGlobal>

// ----- Qpe core export
#if defined(QPE_CORE_LIB_STATIC)
#  define QPE_CORE_EXPORT
#else
#  if defined(QPE_CORE_LIB)
#    define QPE_CORE_EXPORT Q_DECL_EXPORT
#  else
#    define QPE_CORE_EXPORT Q_DECL_IMPORT
#  endif
#endif


// ----- Qpe logger export
#if defined(QPE_LOGGER_LIB_STATIC)
#  define QPE_LOGGER_EXPORT
#else
#  if defined(QPE_LOGGER_LIB)
#    define QPE_LOGGER_EXPORT Q_DECL_EXPORT
#  else
#    define QPE_LOGGER_EXPORT Q_DECL_IMPORT
#  endif
#endif

// ------------------------------------------------------------------------

namespace Qpe_private
{

#ifndef Q_QDOC
template <typename T> inline T* getPtrHelper(T* ptr) { return ptr; }
template <typename Ptr> inline auto getPtrHelper(const Ptr& ptr) -> decltype(ptr.operator->()) { return ptr.operator->(); }
#endif

} // namespace Qpe_private

#define QPE_DECLARE_PRIVATE(Class) \
	inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(Qpe_private::getPtrHelper(d_ptr)); } \
	inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(Qpe_private::getPtrHelper(d_ptr)); } \
	friend class Class##Private;

#define QPE_DECLARE_PUBLIC(Class) \
	inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
	inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
	friend class Class;

#ifndef QA_D
#  define QA_D() auto d = d_func()
#endif

#ifndef QA_Q
#  define QA_Q() auto q = q_func()
#endif

#endif // GLOBAL_QPEGLOBAL_H

#ifndef TOOLS_STRINGIFIER_STRINGIFIER_H
#define TOOLS_STRINGIFIER_STRINGIFIER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QScopedPointer>

#include <Qpe/Global>

namespace Qpe
{

class StringifierPrivate;
class QPE_CORE_EXPORT Stringifier
{
	QPE_DECLARE_PRIVATE(Stringifier)
protected:
	QScopedPointer<StringifierPrivate> d_ptr;
public:
	enum DigitCase { UpperCase = true, LowerCase = false };

	Stringifier(
		int base = 10, bool lz = false,
		bool prefix = false, DigitCase digitCase = LowerCase);
	Stringifier(const QString& formatString);
	Stringifier(const Stringifier& other);
	~Stringifier();

	Stringifier& operator=(const Stringifier& other);

	bool setBase(int base);
	int base() const;

	void setLeadingZero(bool leadingZero);
	void enableLeadingZero();
	void disableLeadingZero();
	bool isLeadingZero() const;

	void setPrefixRequired(bool prefixRequired);
	void enablePrefixRequired();
	void disablePrefixRequired();
	bool isPrefixRequired() const;

	void setDigitCase(DigitCase digitCase);
	void setUpperCase();
	void setLowwerCase();
	DigitCase digitCase() const;
	bool isUpperCase() const;
	bool isLowwerCase() const;

	bool setFormatString(const QString& formatString);

	QByteArray format(char n) const;
	QByteArray format(uchar n) const;
	QByteArray format(signed char n) const;
	QByteArray format(short n) const;
	QByteArray format(ushort n) const;
	QByteArray format(int n) const;
	QByteArray format(uint n) const;
	QByteArray format(long n) const;
	QByteArray format(ulong n) const;
	QByteArray format(qint64 n) const;
	QByteArray format(quint64 n) const;
	QByteArray format(void* n) const;

	QByteArray& format(char n, QByteArray& result) const;
	QByteArray& format(uchar n, QByteArray& result) const;
	QByteArray& format(signed char n, QByteArray& result) const;
	QByteArray& format(short n, QByteArray& result) const;
	QByteArray& format(ushort n, QByteArray& result) const;
	QByteArray& format(int n, QByteArray& result) const;
	QByteArray& format(uint n, QByteArray& result) const;
	QByteArray& format(long n, QByteArray& result) const;
	QByteArray& format(ulong n, QByteArray& result) const;
	QByteArray& format(qint64 n, QByteArray& result) const;
	QByteArray& format(quint64 n, QByteArray& result) const;
	QByteArray& format(void* n, QByteArray& result) const;

	QString& format(char n, QString& result) const;
	QString& format(uchar n, QString& result) const;
	QString& format(signed char n, QString& result) const;
	QString& format(short n, QString& result) const;
	QString& format(ushort n, QString& result) const;
	QString& format(int n, QString& result) const;
	QString& format(uint n, QString& result) const;
	QString& format(long n, QString& result) const;
	QString& format(ulong n, QString& result) const;
	QString& format(qint64 n, QString& result) const;
	QString& format(quint64 n, QString& result) const;
	QString& format(void* n, QString& result) const;
};

} // namespace Qpe

#endif // TOOLS_STRINGIFIER_STRINGIFIER_H

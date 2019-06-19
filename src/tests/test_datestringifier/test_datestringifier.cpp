#include <QtTest/QTest>
#include <QDebug>

#include <Qpe/Core/DateStringifier>

#include <QTimeZone>

class TestDateStringifier : public QObject
{
	Q_OBJECT

private slots:
	void test0();
private:
	void testVerifyQt_Qpe__Date(const QString& format);
	void testVerifyQt_Qpe__Time(const QString& format);
	void testVerifyQt_Qpe__DateTime(const QString& format);
private slots:
	void testVerify__dd_MM_yyyy();
	void testVerify__dd_MMM_yyyy();
	void testVerify__dd_MMMM_yyyy();
	void testVerify__ddd_MM_yyyy();
	void testVerify__dddd_MM_yyyy();
	void testVerify__ddd_MMM_yyyy();
	void testVerify__dddd_MMMM_yyyy();
	void testVerify__HH_mm_ss();
	void testVerify__dd_MM_yyyy_HH_mm_ss_zzz();
	void testVerify__dd_MM_yyyy_HH_mm_ss_t();

	void benchDate_toString__dd_MM_yyyy();
	void benchDateStringifier_format__dd_MM_yyyy();

	void benchDate_toString__dddd_MMMM_yyyy();
	void benchDateStringifier_format__dddd_MMMM_yyyy();

	void benchDate_toString__dd_MM_yyyy_HH_mm_ss();
	void benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss();

	void benchDate_toString__dd_MM_yyyy_HH_mm_ss_t();
	void benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss_t();
	void benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss_tt();

	void testStaticDateFormat__d_M_y();
	void testStaticTimeFormat__H();
	void testStaticTimeFormat__h();
	void testStaticTimeFormat__H_Pm();
	void testStaticTimeFormat__H_Am();
	void testStaticTimeFormat__h_Pm();
	void testStaticTimeFormat__h_Am();
	void testStaticTimeFormat__h_12_Pm();
	void testStaticTimeFormat__h_00_Am();
	void testStaticTimeFormat__h_app();
};

void TestDateStringifier::test0()
{
	QDateTime d = QDateTime(QDate(2016,02,12), QTime(14,10,00), Qt::LocalTime, 18000);
	QString s = Qpe::DateStringifier::format("yyyy-MM-ddTHH:mm:sstt", QDateTime::currentDateTimeUtc());
	s = Qpe::DateStringifier::format("yyyy-MM-ddTHH:mm:sstt", d);
	qDebug() << s;
//	QList<QByteArray> zones = QTimeZone::availableTimeZoneIds();
//	int maxSize = 0;
//	std::for_each(zones.constBegin(), zones.constEnd(),
//	[&maxSize] (const QByteArray& id) {
//		QTimeZone zone(id);
//		QString zoneComment = zone.comment();
//		qDebug() << zoneComment;
//		maxSize = qMax(maxSize, zoneComment.length());
//	});

//	QDateTime d = QDateTime::currentDateTime();
//	QString s = d.toString("HH:mm:ss t");
//	s = QString::number(d.offsetFromUtc());
//	Qpe::DateStringifier ds("dd.MM.yyyy t");
//	s = ds.format(QDateTime::currentDateTime());
//	QString s = ds.format(QDate::currentDate());
////	qDebug() << s;

//	QTime d(13, 11, 17, 56);
//	s = Qpe::DateStringifier::format("h:m:ss.zzz ap", d);
//	// test format with APP app App APp
//	s = "1";
}

void TestDateStringifier::testVerifyQt_Qpe__Date(const QString& format)
{
	Qpe::DateStringifier ds(format);
	QDate baseDate(1970, 1, 1);

	for (int i = 0; i < 50000; ++i) {
		QDate d = baseDate.addDays(i);
		QString qt = d.toString(format);
		QString qpe = ds.format(d);

		QVERIFY2(qt == qpe, qPrintable(QString::number(i).append(": ").append(qt)));
	}

}

void TestDateStringifier::testVerifyQt_Qpe__Time(const QString& format)
{
	Qpe::DateStringifier ds(format);
	QTime baseTime(0, 0, 0);

	for (int i = 0; i < 50000; ++i) {
		QTime d = baseTime.addSecs(i * 2);
		QString qt = d.toString(format);
		QString qpe = ds.format(d);

		QVERIFY2(qt == qpe, qPrintable(QString::number(i).append(": ").append(qt)));
	}
}

void TestDateStringifier::testVerifyQt_Qpe__DateTime(const QString& format)
{

	Qpe::DateStringifier ds(format);
	QDate baseDate(1970, 1, 1);
	QTime baseTime(0, 0, 0);

	for (int i = 0; i < 50000; ++i) {
		QDateTime d(baseDate.addDays(i), baseTime.addSecs(i * 2));
		QString qt = d.toString(format);
		QString qpe = ds.format(d);

		QVERIFY2(qt == qpe, qPrintable(QString::number(i).append(": ").append(qt)));
	}
}

void TestDateStringifier::testVerify__dd_MM_yyyy()
{
	testVerifyQt_Qpe__Date("dd.MM.yyyy");
}

void TestDateStringifier::testVerify__dd_MMM_yyyy()
{
	testVerifyQt_Qpe__Date("dd MMM yyyy");
}

void TestDateStringifier::testVerify__dd_MMMM_yyyy()
{
	testVerifyQt_Qpe__Date("dd MMMM yyyy");
}

void TestDateStringifier::testVerify__ddd_MM_yyyy()
{
	testVerifyQt_Qpe__Date("ddd MM yyyy");
}

void TestDateStringifier::testVerify__dddd_MM_yyyy()
{
	testVerifyQt_Qpe__Date("dddd MM yyyy");
}

void TestDateStringifier::testVerify__ddd_MMM_yyyy()
{
	testVerifyQt_Qpe__Date("ddd MMM yyyy");
}

void TestDateStringifier::testVerify__dddd_MMMM_yyyy()
{
	testVerifyQt_Qpe__Date("dddd MMMM yyyy");
}

void TestDateStringifier::testVerify__HH_mm_ss()
{
	testVerifyQt_Qpe__Time("HH:mm:ss");
}

void TestDateStringifier::testVerify__dd_MM_yyyy_HH_mm_ss_zzz()
{
	testVerifyQt_Qpe__DateTime("dd.MM.yyyy HH:mm:ss.zzz");
}

void TestDateStringifier::testVerify__dd_MM_yyyy_HH_mm_ss_t()
{
	testVerifyQt_Qpe__DateTime("dd.MM.yyyy HH:mm:ss t");
}


void TestDateStringifier::benchDate_toString__dd_MM_yyyy()
{
	QDate b(1970, 1, 1);
	int n = 0;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = b.addDays(i);
			QString s = d.toString("dd.MM.yyyy");
			n += s.size();
		}
	}
	qDebug() << n;
}

void TestDateStringifier::benchDateStringifier_format__dd_MM_yyyy()
{
	Qpe::DateStringifier ds("dd.MM.yyyy");
	QDate b(1970, 1, 1);
	int n = 0;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = b.addDays(i);
			QString s = ds.format(d);
			n += s.size();
		}
	}
	qDebug() << n;
}

void TestDateStringifier::benchDate_toString__dddd_MMMM_yyyy()
{
	QDate b(1970, 1, 1);
	int n = 0;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = b.addDays(i);
			QString s = d.toString("dddd MMMM yyyy");
			n += s.size();
		}
	}
	qDebug() << n;
}

void TestDateStringifier::benchDateStringifier_format__dddd_MMMM_yyyy()
{
	Qpe::DateStringifier ds("dddd MMMM yyyy");
	QDate b(1970, 1, 1);
	int n = 0;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = b.addDays(i);
			QString s = ds.format(d);
			n += s.size();
		}
	}
	qDebug() << n;
}

void TestDateStringifier::benchDate_toString__dd_MM_yyyy_HH_mm_ss()
{
	QTime bt(0, 0, 0);
	QDate bd(1970, 1, 1);
	int n = 0;
	QDateTime dt;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = bd.addDays(i);
			QTime t = bt.addSecs(i * 2);
			dt = QDateTime(d, t);
			QString s = dt.toString("dd.MM.yyyy HH:mm:ss");
			n += s.size();
		}
	}
	qDebug() << n << dt;
}

void TestDateStringifier::benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss()
{
	Qpe::DateStringifier ds("dd.MM.yyyy HH:mm:ss");
	QTime bt(0, 0, 0);
	QDate bd(1970, 1, 1);
	int n = 0;
	QDateTime dt;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = bd.addDays(i);
			QTime t = bt.addSecs(i * 2);
			dt = QDateTime(d, t);
			QString s = ds.format(dt);
			n += s.size();
		}
	}
	qDebug() << n << dt;
}

void TestDateStringifier::benchDate_toString__dd_MM_yyyy_HH_mm_ss_t()
{
	QTime bt(0, 0, 0);
	QDate bd(1970, 1, 1);
	int n = 0;
	QDateTime dt;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = bd.addDays(i);
			QTime t = bt.addSecs(i * 2);
			dt = QDateTime(d, t);
			QString s = dt.toString("dd.MM.yyyy HH:mm:ss t");
			n += s.size();
		}
	}
	qDebug() << n << dt;
}

void TestDateStringifier::benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss_t()
{
	Qpe::DateStringifier ds("dd.MM.yyyy HH:mm:ss t");
	QTime bt(0, 0, 0);
	QDate bd(1970, 1, 1);
	int n = 0;
	QDateTime dt;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = bd.addDays(i);
			QTime t = bt.addSecs(i * 2);
			dt = QDateTime(d, t);
			QString s = ds.format(dt);
			n += s.size();
		}
	}
	qDebug() << n << dt;
}

void TestDateStringifier::benchDateStringifier_format__dd_MM_yyyy_HH_mm_ss_tt()
{
	Qpe::DateStringifier ds("dd.MM.yyyy HH:mm:ss tt");
	QTime bt(0, 0, 0);
	QDate bd(1970, 1, 1);
	int n = 0;
	QDateTime dt;
	QBENCHMARK {
		for (int i = 0; i <= 50000; ++i) {
			QDate d = bd.addDays(i);
			QTime t = bt.addSecs(i * 2);
			dt = QDateTime(d, t);
			QString s = ds.format(dt);
			n += s.size();
		}
	}
	qDebug() << n << dt;
}

void TestDateStringifier::testStaticDateFormat__d_M_y()
{
	QDate d(2016, 2, 5);
	QVERIFY(Qpe::DateStringifier::format("d.M.yy", d) == "5.2.16");
	QVERIFY(Qpe::DateStringifier::format("d.M.yyyy", d) == "5.2.2016");
	QVERIFY(Qpe::DateStringifier::format("d.MM.yy", d) == "5.02.16");
	QVERIFY(Qpe::DateStringifier::format("d.MM.yyyy", d) == "5.02.2016");
	QVERIFY(Qpe::DateStringifier::format("dd.M.yy", d) == "05.2.16");
	QVERIFY(Qpe::DateStringifier::format("dd.M.yyyy", d) == "05.2.2016");
	QVERIFY(Qpe::DateStringifier::format("dd.MM.yy", d) == "05.02.16");
	QVERIFY(Qpe::DateStringifier::format("dd.MM.yyyy", d) == "05.02.2016");

	QVERIFY(Qpe::DateStringifier::format("M.d.yy", d) == "2.5.16");
	QVERIFY(Qpe::DateStringifier::format("M.d.yyyy", d) == "2.5.2016");
	QVERIFY(Qpe::DateStringifier::format("MM.d.yy", d) == "02.5.16");
	QVERIFY(Qpe::DateStringifier::format("MM.d.yyyy", d) == "02.5.2016");
	QVERIFY(Qpe::DateStringifier::format("M.dd.yy", d) == "2.05.16");
	QVERIFY(Qpe::DateStringifier::format("M.dd.yyyy", d) == "2.05.2016");
	QVERIFY(Qpe::DateStringifier::format("MM.dd.yy", d) == "02.05.16");
	QVERIFY(Qpe::DateStringifier::format("MM.dd.yyyy", d) == "02.05.2016");

	QVERIFY(Qpe::DateStringifier::format("d.yy.M", d) == "5.16.2");
	QVERIFY(Qpe::DateStringifier::format("d.yyyy.M", d) == "5.2016.2");
	QVERIFY(Qpe::DateStringifier::format("d.yy.MM", d) == "5.16.02");
	QVERIFY(Qpe::DateStringifier::format("d.yyyy.MM", d) == "5.2016.02");
	QVERIFY(Qpe::DateStringifier::format("dd.yy.M", d) == "05.16.2");
	QVERIFY(Qpe::DateStringifier::format("dd.yyyy.M", d) == "05.2016.2");
	QVERIFY(Qpe::DateStringifier::format("dd.yy.MM", d) == "05.16.02");
	QVERIFY(Qpe::DateStringifier::format("dd.yyyy.MM", d) == "05.2016.02");

	QVERIFY(Qpe::DateStringifier::format("yy.M.d", d) == "16.2.5");
	QVERIFY(Qpe::DateStringifier::format("yyyy.M.d", d) == "2016.2.5");
	QVERIFY(Qpe::DateStringifier::format("yy.MM.d", d) == "16.02.5");
	QVERIFY(Qpe::DateStringifier::format("yyyy.MM.d", d) == "2016.02.5");
	QVERIFY(Qpe::DateStringifier::format("yy.M.dd", d) == "16.2.05");
	QVERIFY(Qpe::DateStringifier::format("yyyy.M.dd", d) == "2016.2.05");
	QVERIFY(Qpe::DateStringifier::format("yy.MM.dd", d) == "16.02.05");
	QVERIFY(Qpe::DateStringifier::format("yyyy.MM.dd", d) == "2016.02.05");

	QVERIFY(Qpe::DateStringifier::format("M.yy.d", d) == "2.16.5");
	QVERIFY(Qpe::DateStringifier::format("M.yyyy.d", d) == "2.2016.5");
	QVERIFY(Qpe::DateStringifier::format("MM.yy.d", d) == "02.16.5");
	QVERIFY(Qpe::DateStringifier::format("MM.yyyy.d", d) == "02.2016.5");
	QVERIFY(Qpe::DateStringifier::format("M.yy.dd", d) == "2.16.05");
	QVERIFY(Qpe::DateStringifier::format("M.yyyy.dd", d) == "2.2016.05");
	QVERIFY(Qpe::DateStringifier::format("MM.yy.dd", d) == "02.16.05");
	QVERIFY(Qpe::DateStringifier::format("MM.yyyy.dd", d) == "02.2016.05");

	QVERIFY(Qpe::DateStringifier::format("yy.d.M", d) == "16.5.2");
	QVERIFY(Qpe::DateStringifier::format("yyyy.d.M", d) == "2016.5.2");
	QVERIFY(Qpe::DateStringifier::format("yy.d.MM", d) == "16.5.02");
	QVERIFY(Qpe::DateStringifier::format("yyyy.d.MM", d) == "2016.5.02");
	QVERIFY(Qpe::DateStringifier::format("yy.dd.M", d) == "16.05.2");
	QVERIFY(Qpe::DateStringifier::format("yyyy.dd.M", d) == "2016.05.2");
	QVERIFY(Qpe::DateStringifier::format("yy.dd.MM", d) == "16.05.02");
	QVERIFY(Qpe::DateStringifier::format("yyyy.dd.MM", d) == "2016.05.02");


	QVERIFY(Qpe::DateStringifier::format("dMyy", d) == "5216");
	QVERIFY(Qpe::DateStringifier::format("dMyyyy", d) == "522016");
	QVERIFY(Qpe::DateStringifier::format("dMMyy", d) == "50216");
	QVERIFY(Qpe::DateStringifier::format("dMMyyyy", d) == "5022016");
	QVERIFY(Qpe::DateStringifier::format("ddMyy", d) == "05216");
	QVERIFY(Qpe::DateStringifier::format("ddMyyyy", d) == "0522016");
	QVERIFY(Qpe::DateStringifier::format("ddMMyy", d) == "050216");
	QVERIFY(Qpe::DateStringifier::format("ddMMyyyy", d) == "05022016");

	QVERIFY(Qpe::DateStringifier::format("Mdyy", d) == "2516");
	QVERIFY(Qpe::DateStringifier::format("Mdyyyy", d) == "252016");
	QVERIFY(Qpe::DateStringifier::format("MMdyy", d) == "02516");
	QVERIFY(Qpe::DateStringifier::format("MMdyyyy", d) == "0252016");
	QVERIFY(Qpe::DateStringifier::format("Mddyy", d) == "20516");
	QVERIFY(Qpe::DateStringifier::format("Mddyyyy", d) == "2052016");
	QVERIFY(Qpe::DateStringifier::format("MMddyy", d) == "020516");
	QVERIFY(Qpe::DateStringifier::format("MMddyyyy", d) == "02052016");

	QVERIFY(Qpe::DateStringifier::format("dyyM", d) == "5162");
	QVERIFY(Qpe::DateStringifier::format("dyyyyM", d) == "520162");
	QVERIFY(Qpe::DateStringifier::format("dyyMM", d) == "51602");
	QVERIFY(Qpe::DateStringifier::format("dyyyyMM", d) == "5201602");
	QVERIFY(Qpe::DateStringifier::format("ddyyM", d) == "05162");
	QVERIFY(Qpe::DateStringifier::format("ddyyyyM", d) == "0520162");
	QVERIFY(Qpe::DateStringifier::format("ddyyMM", d) == "051602");
	QVERIFY(Qpe::DateStringifier::format("ddyyyyMM", d) == "05201602");

	QVERIFY(Qpe::DateStringifier::format("yyMd", d) == "1625");
	QVERIFY(Qpe::DateStringifier::format("yyyyMd", d) == "201625");
	QVERIFY(Qpe::DateStringifier::format("yyMMd", d) == "16025");
	QVERIFY(Qpe::DateStringifier::format("yyyyMMd", d) == "2016025");
	QVERIFY(Qpe::DateStringifier::format("yyMdd", d) == "16205");
	QVERIFY(Qpe::DateStringifier::format("yyyyMdd", d) == "2016205");
	QVERIFY(Qpe::DateStringifier::format("yyMMdd", d) == "160205");
	QVERIFY(Qpe::DateStringifier::format("yyyyMMdd", d) == "20160205");

	QVERIFY(Qpe::DateStringifier::format("Myyd", d) == "2165");
	QVERIFY(Qpe::DateStringifier::format("Myyyyd", d) == "220165");
	QVERIFY(Qpe::DateStringifier::format("MMyyd", d) == "02165");
	QVERIFY(Qpe::DateStringifier::format("MMyyyyd", d) == "0220165");
	QVERIFY(Qpe::DateStringifier::format("Myydd", d) == "21605");
	QVERIFY(Qpe::DateStringifier::format("Myyyydd", d) == "2201605");
	QVERIFY(Qpe::DateStringifier::format("MMyydd", d) == "021605");
	QVERIFY(Qpe::DateStringifier::format("MMyyyydd", d) == "02201605");

	QVERIFY(Qpe::DateStringifier::format("yydM", d) == "1652");
	QVERIFY(Qpe::DateStringifier::format("yyyydM", d) == "201652");
	QVERIFY(Qpe::DateStringifier::format("yydMM", d) == "16502");
	QVERIFY(Qpe::DateStringifier::format("yyyydMM", d) == "2016502");
	QVERIFY(Qpe::DateStringifier::format("yyddM", d) == "16052");
	QVERIFY(Qpe::DateStringifier::format("yyyyddM", d) == "2016052");
	QVERIFY(Qpe::DateStringifier::format("yyddMM", d) == "160502");
	QVERIFY(Qpe::DateStringifier::format("yyyyddMM", d) == "20160502");
}

void TestDateStringifier::testStaticTimeFormat__H()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("H:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss", d) == "14:11:17");

	QVERIFY(Qpe::DateStringifier::format("m:H:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss", d) == "11:14:17");

	QVERIFY(Qpe::DateStringifier::format("H:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm", d) == "14:17:11");

	QVERIFY(Qpe::DateStringifier::format("s:m:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH", d) == "17:11:14");

	QVERIFY(Qpe::DateStringifier::format("m:s:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH", d) == "11:17:14");

	QVERIFY(Qpe::DateStringifier::format("s:H:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm", d) == "17:14:11");


	QVERIFY(Qpe::DateStringifier::format("H:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss.zzz", d) == "14:11:17.056");

	QVERIFY(Qpe::DateStringifier::format("m:H:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss.zzz", d) == "11:14:17.056");

	QVERIFY(Qpe::DateStringifier::format("H:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm.zzz", d) == "14:17:11.056");

	QVERIFY(Qpe::DateStringifier::format("s:m:H.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH.zzz", d) == "17:11:14.056");

	QVERIFY(Qpe::DateStringifier::format("m:s:H.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH.zzz", d) == "11:17:14.056");

	QVERIFY(Qpe::DateStringifier::format("s:H:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm.zzz", d) == "17:14:11.056");




	QVERIFY(Qpe::DateStringifier::format("Hms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmmss", d) == "141117");

	QVERIFY(Qpe::DateStringifier::format("mHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHHss", d) == "111417");

	QVERIFY(Qpe::DateStringifier::format("Hsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hssmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHssmm", d) == "141711");

	QVERIFY(Qpe::DateStringifier::format("smH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmHH", d) == "171114");

	QVERIFY(Qpe::DateStringifier::format("msH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mssH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmssH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("msHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mssHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmssHH", d) == "111714");

	QVERIFY(Qpe::DateStringifier::format("sHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHHmm", d) == "171411");


	QVERIFY(Qpe::DateStringifier::format("Hmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("Hmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("Hmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("Hmmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("HHmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("HHmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("HHmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("HHmmsszzz", d) == "141117056");

	QVERIFY(Qpe::DateStringifier::format("mHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mHHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mHHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmHHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmHHsszzz", d) == "111417056");

	QVERIFY(Qpe::DateStringifier::format("Hsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("Hssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("Hsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("Hssmmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("HHsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("HHssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("HHsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("HHssmmzzz", d) == "141711056");

	QVERIFY(Qpe::DateStringifier::format("smHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smHHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmHHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmHHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmHHzzz", d) == "171114056");

	QVERIFY(Qpe::DateStringifier::format("msHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mssHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmsHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmssHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("msHHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mssHHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmsHHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmssHHzzz", d) == "111714056");

	QVERIFY(Qpe::DateStringifier::format("sHmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHmmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHHmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHHmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHHmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHHmmzzz", d) == "171411056");
}

void TestDateStringifier::testStaticTimeFormat__h()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss", d) == "14:11:17");

	QVERIFY(Qpe::DateStringifier::format("m:h:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss", d) == "11:14:17");

	QVERIFY(Qpe::DateStringifier::format("h:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm", d) == "14:17:11");

	QVERIFY(Qpe::DateStringifier::format("s:m:h", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh", d) == "17:11:14");

	QVERIFY(Qpe::DateStringifier::format("m:s:h", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh", d) == "11:17:14");

	QVERIFY(Qpe::DateStringifier::format("s:h:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm", d) == "17:14:11");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz", d) == "14:11:17.056");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz", d) == "11:14:17.056");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz", d) == "14:17:11.056");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz", d) == "17:11:14.056");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz", d) == "11:17:14.056");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz", d) == "17:14:11.056");




	QVERIFY(Qpe::DateStringifier::format("hms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hmmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hhms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hhmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hhmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("hhmmss", d) == "141117");

	QVERIFY(Qpe::DateStringifier::format("mhs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mhss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmhs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmhss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mhhs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mhhss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmhhs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmhhss", d) == "111417");

	QVERIFY(Qpe::DateStringifier::format("hsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hssmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hhsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hhssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hhsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("hhssmm", d) == "141711");

	QVERIFY(Qpe::DateStringifier::format("smh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smhh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmhh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmhh", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh", d) == "171114");

	QVERIFY(Qpe::DateStringifier::format("msh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mssh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmssh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mshh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("msshh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmshh", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsshh", d) == "111714");

	QVERIFY(Qpe::DateStringifier::format("shm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sshm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("shmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sshmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("shhm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sshhm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("shhmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sshhmm", d) == "171411");


	QVERIFY(Qpe::DateStringifier::format("hmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("hmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("hhmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz", d) == "141117056");

	QVERIFY(Qpe::DateStringifier::format("mhsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmhsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mhhsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz", d) == "111417056");

	QVERIFY(Qpe::DateStringifier::format("hsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("hsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("hhsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz", d) == "141711056");

	QVERIFY(Qpe::DateStringifier::format("smhz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmhz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smhhz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmhhz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz", d) == "171114056");

	QVERIFY(Qpe::DateStringifier::format("mshz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("msshzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmshz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mshhz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmshhz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz", d) == "111714056");

	QVERIFY(Qpe::DateStringifier::format("shmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("shmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("shhmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("shhmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz", d) == "171411056");
}

void TestDateStringifier::testStaticTimeFormat__H_Pm()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("H:m:s ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s ap", d) == "14:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss ap", d) == "14:11:17 pm");

	QVERIFY(Qpe::DateStringifier::format("m:H:s ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s ap", d) == "11:14:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss ap", d) == "11:14:17 pm");

	QVERIFY(Qpe::DateStringifier::format("H:s:m ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm ap", d) == "14:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm ap", d) == "14:17:11 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:H ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH ap", d) == "17:11:14 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH ap", d) == "17:11:14 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:H ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH ap", d) == "11:17:14 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH ap", d) == "11:17:14 pm");

	QVERIFY(Qpe::DateStringifier::format("s:H:m ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm ap", d) == "17:14:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm ap", d) == "17:14:11 pm");


	QVERIFY(Qpe::DateStringifier::format("H:m:s.z ap", d) == "14:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss.zzz ap", d) == "14:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s.z ap", d) == "14:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss.zzz ap", d) == "14:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s.z ap", d) == "14:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss.zzz ap", d) == "14:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s.z ap", d) == "14:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss.zzz ap", d) == "14:11:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:H:s.z ap", d) == "11:14:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss.zzz ap", d) == "11:14:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s.z ap", d) == "11:14:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss.zzz ap", d) == "11:14:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s.z ap", d) == "11:14:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss.zzz ap", d) == "11:14:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s.z ap", d) == "11:14:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss.zzz ap", d) == "11:14:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("H:s:m.z ap", d) == "14:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m.zzz ap", d) == "14:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm.z ap", d) == "14:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm.zzz ap", d) == "14:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m.z ap", d) == "14:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m.zzz ap", d) == "14:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm.z ap", d) == "14:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm.zzz ap", d) == "14:17:11.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:H.z ap", d) == "17:11:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H.zzz ap", d) == "17:11:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H.z ap", d) == "17:11:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H.zzz ap", d) == "17:11:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH.z ap", d) == "17:11:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH.zzz ap", d) == "17:11:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH.z ap", d) == "17:11:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH.zzz ap", d) == "17:11:14.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:H.z ap", d) == "11:17:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H.zzz ap", d) == "11:17:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H.z ap", d) == "11:17:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H.zzz ap", d) == "11:17:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH.z ap", d) == "11:17:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH.zzz ap", d) == "11:17:14.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH.z ap", d) == "11:17:14.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH.zzz ap", d) == "11:17:14.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:H:m.z ap", d) == "17:14:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m.zzz ap", d) == "17:14:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm.z ap", d) == "17:14:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm.zzz ap", d) == "17:14:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m.z ap", d) == "17:14:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m.zzz ap", d) == "17:14:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm.z ap", d) == "17:14:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm.zzz ap", d) == "17:14:11.056 pm");




	QVERIFY(Qpe::DateStringifier::format("Hms ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmss ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmms ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmmss ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("HHms ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmss ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmms ap", d) == "141117 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmmss ap", d) == "141117 pm");

	QVERIFY(Qpe::DateStringifier::format("mHs ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mHss ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHs ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHss ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mHHs ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mHHss ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHHs ap", d) == "111417 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHHss ap", d) == "111417 pm");

	QVERIFY(Qpe::DateStringifier::format("Hsm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("Hssm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("Hsmm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("Hssmm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("HHsm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("HHssm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("HHsmm ap", d) == "141711 pm");
	QVERIFY(Qpe::DateStringifier::format("HHssmm ap", d) == "141711 pm");

	QVERIFY(Qpe::DateStringifier::format("smH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("smmH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("smHH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmHH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("smmHH ap", d) == "171114 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmHH ap", d) == "171114 pm");

	QVERIFY(Qpe::DateStringifier::format("msH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mssH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("msHH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mssHH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsHH ap", d) == "111714 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssHH ap", d) == "111714 pm");

	QVERIFY(Qpe::DateStringifier::format("sHm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("sHmm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHmm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("sHHm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHHm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("sHHmm ap", d) == "171411 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHHmm ap", d) == "171411 pm");


	QVERIFY(Qpe::DateStringifier::format("Hmsz ap", d) == "14111756 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmsszzz ap", d) == "141117056 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmmsz ap", d) == "14111756 pm");
	QVERIFY(Qpe::DateStringifier::format("Hmmsszzz ap", d) == "141117056 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmsz ap", d) == "14111756 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmsszzz ap", d) == "141117056 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmmsz ap", d) == "14111756 pm");
	QVERIFY(Qpe::DateStringifier::format("HHmmsszzz ap", d) == "141117056 pm");

	QVERIFY(Qpe::DateStringifier::format("mHsz ap", d) == "11141756 pm");
	QVERIFY(Qpe::DateStringifier::format("mHsszzz ap", d) == "111417056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHsz ap", d) == "11141756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHsszzz ap", d) == "111417056 pm");
	QVERIFY(Qpe::DateStringifier::format("mHHsz ap", d) == "11141756 pm");
	QVERIFY(Qpe::DateStringifier::format("mHHsszzz ap", d) == "111417056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHHsz ap", d) == "11141756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmHHsszzz ap", d) == "111417056 pm");

	QVERIFY(Qpe::DateStringifier::format("Hsmz ap", d) == "14171156 pm");
	QVERIFY(Qpe::DateStringifier::format("Hssmzzz ap", d) == "141711056 pm");
	QVERIFY(Qpe::DateStringifier::format("Hsmmz ap", d) == "14171156 pm");
	QVERIFY(Qpe::DateStringifier::format("Hssmmzzz ap", d) == "141711056 pm");
	QVERIFY(Qpe::DateStringifier::format("HHsmz ap", d) == "14171156 pm");
	QVERIFY(Qpe::DateStringifier::format("HHssmzzz ap", d) == "141711056 pm");
	QVERIFY(Qpe::DateStringifier::format("HHsmmz ap", d) == "14171156 pm");
	QVERIFY(Qpe::DateStringifier::format("HHssmmzzz ap", d) == "141711056 pm");

	QVERIFY(Qpe::DateStringifier::format("smHz ap", d) == "17111456 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmHzzz ap", d) == "171114056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmHz ap", d) == "17111456 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmHzzz ap", d) == "171114056 pm");
	QVERIFY(Qpe::DateStringifier::format("smHHz ap", d) == "17111456 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmHHzzz ap", d) == "171114056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmHHz ap", d) == "17111456 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmHHzzz ap", d) == "171114056 pm");

	QVERIFY(Qpe::DateStringifier::format("msHz ap", d) == "11171456 pm");
	QVERIFY(Qpe::DateStringifier::format("mssHzzz ap", d) == "111714056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsHz ap", d) == "11171456 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssHzzz ap", d) == "111714056 pm");
	QVERIFY(Qpe::DateStringifier::format("msHHz ap", d) == "11171456 pm");
	QVERIFY(Qpe::DateStringifier::format("mssHHzzz ap", d) == "111714056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsHHz ap", d) == "11171456 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssHHzzz ap", d) == "111714056 pm");

	QVERIFY(Qpe::DateStringifier::format("sHmz ap", d) == "17141156 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHmzzz ap", d) == "171411056 pm");
	QVERIFY(Qpe::DateStringifier::format("sHmmz ap", d) == "17141156 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHmmzzz ap", d) == "171411056 pm");
	QVERIFY(Qpe::DateStringifier::format("sHHmz ap", d) == "17141156 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHHmzzz ap", d) == "171411056 pm");
	QVERIFY(Qpe::DateStringifier::format("sHHmmz ap", d) == "17141156 pm");
	QVERIFY(Qpe::DateStringifier::format("ssHHmmzzz ap", d) == "171411056 pm");
}

void TestDateStringifier::testStaticTimeFormat__H_Am()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("H:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s", d) == "14:11:17");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss", d) == "14:11:17");

	QVERIFY(Qpe::DateStringifier::format("m:H:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s", d) == "11:14:17");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss", d) == "11:14:17");

	QVERIFY(Qpe::DateStringifier::format("H:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm", d) == "14:17:11");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm", d) == "14:17:11");

	QVERIFY(Qpe::DateStringifier::format("s:m:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH", d) == "17:11:14");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH", d) == "17:11:14");

	QVERIFY(Qpe::DateStringifier::format("m:s:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH", d) == "11:17:14");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH", d) == "11:17:14");

	QVERIFY(Qpe::DateStringifier::format("s:H:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm", d) == "17:14:11");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm", d) == "17:14:11");


	QVERIFY(Qpe::DateStringifier::format("H:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("H:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("H:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("H:mm:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("HH:m:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("HH:m:ss.zzz", d) == "14:11:17.056");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:s.z", d) == "14:11:17.56");
	QVERIFY(Qpe::DateStringifier::format("HH:mm:ss.zzz", d) == "14:11:17.056");

	QVERIFY(Qpe::DateStringifier::format("m:H:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:H:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:H:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:H:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("m:HH:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("m:HH:ss.zzz", d) == "11:14:17.056");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:s.z", d) == "11:14:17.56");
	QVERIFY(Qpe::DateStringifier::format("mm:HH:ss.zzz", d) == "11:14:17.056");

	QVERIFY(Qpe::DateStringifier::format("H:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("H:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("H:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("H:ss:mm.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("HH:s:m.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:m.zzz", d) == "14:17:11.056");
	QVERIFY(Qpe::DateStringifier::format("HH:s:mm.z", d) == "14:17:11.56");
	QVERIFY(Qpe::DateStringifier::format("HH:ss:mm.zzz", d) == "14:17:11.056");

	QVERIFY(Qpe::DateStringifier::format("s:m:H.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:H.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:H.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:H.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:m:HH.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:m:HH.zzz", d) == "17:11:14.056");
	QVERIFY(Qpe::DateStringifier::format("s:mm:HH.z", d) == "17:11:14.56");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:HH.zzz", d) == "17:11:14.056");

	QVERIFY(Qpe::DateStringifier::format("m:s:H.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:H.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:H.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:H.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("m:s:HH.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("m:ss:HH.zzz", d) == "11:17:14.056");
	QVERIFY(Qpe::DateStringifier::format("mm:s:HH.z", d) == "11:17:14.56");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:HH.zzz", d) == "11:17:14.056");

	QVERIFY(Qpe::DateStringifier::format("s:H:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:H:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:H:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:H:mm.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:HH:m.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:m.zzz", d) == "17:14:11.056");
	QVERIFY(Qpe::DateStringifier::format("s:HH:mm.z", d) == "17:14:11.56");
	QVERIFY(Qpe::DateStringifier::format("ss:HH:mm.zzz", d) == "17:14:11.056");




	QVERIFY(Qpe::DateStringifier::format("Hms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("Hmmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmss", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmms", d) == "141117");
	QVERIFY(Qpe::DateStringifier::format("HHmmss", d) == "141117");

	QVERIFY(Qpe::DateStringifier::format("mHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mHHss", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHHs", d) == "111417");
	QVERIFY(Qpe::DateStringifier::format("mmHHss", d) == "111417");

	QVERIFY(Qpe::DateStringifier::format("Hsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("Hssmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHsm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHssm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHsmm", d) == "141711");
	QVERIFY(Qpe::DateStringifier::format("HHssmm", d) == "141711");

	QVERIFY(Qpe::DateStringifier::format("smH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("smmHH", d) == "171114");
	QVERIFY(Qpe::DateStringifier::format("ssmmHH", d) == "171114");

	QVERIFY(Qpe::DateStringifier::format("msH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mssH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmssH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("msHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mssHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmsHH", d) == "111714");
	QVERIFY(Qpe::DateStringifier::format("mmssHH", d) == "111714");

	QVERIFY(Qpe::DateStringifier::format("sHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHHm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("sHHmm", d) == "171411");
	QVERIFY(Qpe::DateStringifier::format("ssHHmm", d) == "171411");


	QVERIFY(Qpe::DateStringifier::format("Hmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("Hmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("Hmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("Hmmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("HHmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("HHmsszzz", d) == "141117056");
	QVERIFY(Qpe::DateStringifier::format("HHmmsz", d) == "14111756");
	QVERIFY(Qpe::DateStringifier::format("HHmmsszzz", d) == "141117056");

	QVERIFY(Qpe::DateStringifier::format("mHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mHHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mHHsszzz", d) == "111417056");
	QVERIFY(Qpe::DateStringifier::format("mmHHsz", d) == "11141756");
	QVERIFY(Qpe::DateStringifier::format("mmHHsszzz", d) == "111417056");

	QVERIFY(Qpe::DateStringifier::format("Hsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("Hssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("Hsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("Hssmmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("HHsmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("HHssmzzz", d) == "141711056");
	QVERIFY(Qpe::DateStringifier::format("HHsmmz", d) == "14171156");
	QVERIFY(Qpe::DateStringifier::format("HHssmmzzz", d) == "141711056");

	QVERIFY(Qpe::DateStringifier::format("smHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smHHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmHHzzz", d) == "171114056");
	QVERIFY(Qpe::DateStringifier::format("smmHHz", d) == "17111456");
	QVERIFY(Qpe::DateStringifier::format("ssmmHHzzz", d) == "171114056");

	QVERIFY(Qpe::DateStringifier::format("msHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mssHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmsHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmssHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("msHHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mssHHzzz", d) == "111714056");
	QVERIFY(Qpe::DateStringifier::format("mmsHHz", d) == "11171456");
	QVERIFY(Qpe::DateStringifier::format("mmssHHzzz", d) == "111714056");

	QVERIFY(Qpe::DateStringifier::format("sHmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHmmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHHmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHHmzzz", d) == "171411056");
	QVERIFY(Qpe::DateStringifier::format("sHHmmz", d) == "17141156");
	QVERIFY(Qpe::DateStringifier::format("ssHHmmzzz", d) == "171411056");
}

void TestDateStringifier::testStaticTimeFormat__h_Pm()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s ap", d) == "2:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss ap", d) == "2:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s ap", d) == "2:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss ap", d) == "2:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s ap", d) == "02:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss ap", d) == "02:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s ap", d) == "02:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss ap", d) == "02:11:17 pm");

	QVERIFY(Qpe::DateStringifier::format("m:h:s ap", d) == "11:2:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss ap", d) == "11:2:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s ap", d) == "11:2:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss ap", d) == "11:2:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s ap", d) == "11:02:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss ap", d) == "11:02:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s ap", d) == "11:02:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss ap", d) == "11:02:17 pm");

	QVERIFY(Qpe::DateStringifier::format("h:s:m ap", d) == "2:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m ap", d) == "2:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm ap", d) == "2:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm ap", d) == "2:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m ap", d) == "02:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m ap", d) == "02:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm ap", d) == "02:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm ap", d) == "02:17:11 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:h ap", d) == "17:11:2 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h ap", d) == "17:11:2 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h ap", d) == "17:11:2 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h ap", d) == "17:11:2 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh ap", d) == "17:11:02 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh ap", d) == "17:11:02 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh ap", d) == "17:11:02 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh ap", d) == "17:11:02 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:h ap", d) == "11:17:2 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h ap", d) == "11:17:2 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h ap", d) == "11:17:2 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h ap", d) == "11:17:2 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh ap", d) == "11:17:02 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh ap", d) == "11:17:02 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh ap", d) == "11:17:02 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh ap", d) == "11:17:02 pm");

	QVERIFY(Qpe::DateStringifier::format("s:h:m ap", d) == "17:2:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m ap", d) == "17:2:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm ap", d) == "17:2:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm ap", d) == "17:2:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m ap", d) == "17:02:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m ap", d) == "17:02:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm ap", d) == "17:02:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm ap", d) == "17:02:11 pm");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z ap", d) == "2:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz ap", d) == "2:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z ap", d) == "2:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz ap", d) == "2:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z ap", d) == "02:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz ap", d) == "02:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z ap", d) == "02:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz ap", d) == "02:11:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z ap", d) == "11:2:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz ap", d) == "11:2:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z ap", d) == "11:2:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz ap", d) == "11:2:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z ap", d) == "11:02:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz ap", d) == "11:02:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z ap", d) == "11:02:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz ap", d) == "11:02:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z ap", d) == "2:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz ap", d) == "2:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z ap", d) == "2:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz ap", d) == "2:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z ap", d) == "02:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz ap", d) == "02:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z ap", d) == "02:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz ap", d) == "02:17:11.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z ap", d) == "17:11:2.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz ap", d) == "17:11:2.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z ap", d) == "17:11:2.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz ap", d) == "17:11:2.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z ap", d) == "17:11:02.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz ap", d) == "17:11:02.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z ap", d) == "17:11:02.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz ap", d) == "17:11:02.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z ap", d) == "11:17:2.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz ap", d) == "11:17:2.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z ap", d) == "11:17:2.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz ap", d) == "11:17:2.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z ap", d) == "11:17:02.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz ap", d) == "11:17:02.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z ap", d) == "11:17:02.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz ap", d) == "11:17:02.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z ap", d) == "17:2:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz ap", d) == "17:2:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z ap", d) == "17:2:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz ap", d) == "17:2:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z ap", d) == "17:02:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz ap", d) == "17:02:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z ap", d) == "17:02:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz ap", d) == "17:02:11.056 pm");




	QVERIFY(Qpe::DateStringifier::format("hms ap", d) == "21117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmss ap", d) == "21117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmms ap", d) == "21117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmss ap", d) == "21117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhms ap", d) == "021117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmss ap", d) == "021117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmms ap", d) == "021117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmss ap", d) == "021117 pm");

	QVERIFY(Qpe::DateStringifier::format("mhs ap", d) == "11217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhss ap", d) == "11217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhs ap", d) == "11217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhss ap", d) == "11217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhs ap", d) == "110217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhss ap", d) == "110217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhs ap", d) == "110217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhss ap", d) == "110217 pm");

	QVERIFY(Qpe::DateStringifier::format("hsm ap", d) == "21711 pm");
	QVERIFY(Qpe::DateStringifier::format("hssm ap", d) == "21711 pm");
	QVERIFY(Qpe::DateStringifier::format("hsmm ap", d) == "21711 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmm ap", d) == "21711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsm ap", d) == "021711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssm ap", d) == "021711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmm ap", d) == "021711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmm ap", d) == "021711 pm");

	QVERIFY(Qpe::DateStringifier::format("smh ap", d) == "17112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmh ap", d) == "17112 pm");
	QVERIFY(Qpe::DateStringifier::format("smmh ap", d) == "17112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmh ap", d) == "17112 pm");
	QVERIFY(Qpe::DateStringifier::format("smhh ap", d) == "171102 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhh ap", d) == "171102 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhh ap", d) == "171102 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh ap", d) == "171102 pm");

	QVERIFY(Qpe::DateStringifier::format("msh ap", d) == "11172 pm");
	QVERIFY(Qpe::DateStringifier::format("mssh ap", d) == "11172 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsh ap", d) == "11172 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssh ap", d) == "11172 pm");
	QVERIFY(Qpe::DateStringifier::format("mshh ap", d) == "111702 pm");
	QVERIFY(Qpe::DateStringifier::format("msshh ap", d) == "111702 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshh ap", d) == "111702 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshh ap", d) == "111702 pm");

	QVERIFY(Qpe::DateStringifier::format("shm ap", d) == "17211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshm ap", d) == "17211 pm");
	QVERIFY(Qpe::DateStringifier::format("shmm ap", d) == "17211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmm ap", d) == "17211 pm");
	QVERIFY(Qpe::DateStringifier::format("shhm ap", d) == "170211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhm ap", d) == "170211 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmm ap", d) == "170211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmm ap", d) == "170211 pm");


	QVERIFY(Qpe::DateStringifier::format("hmsz ap", d) == "2111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz ap", d) == "21117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmsz ap", d) == "2111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz ap", d) == "21117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmsz ap", d) == "02111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz ap", d) == "021117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz ap", d) == "02111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz ap", d) == "021117056 pm");

	QVERIFY(Qpe::DateStringifier::format("mhsz ap", d) == "1121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz ap", d) == "11217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhsz ap", d) == "1121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz ap", d) == "11217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhsz ap", d) == "11021756 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz ap", d) == "110217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz ap", d) == "11021756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz ap", d) == "110217056 pm");

	QVERIFY(Qpe::DateStringifier::format("hsmz ap", d) == "2171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz ap", d) == "21711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hsmmz ap", d) == "2171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz ap", d) == "21711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmz ap", d) == "02171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz ap", d) == "021711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz ap", d) == "02171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz ap", d) == "021711056 pm");

	QVERIFY(Qpe::DateStringifier::format("smhz ap", d) == "1711256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz ap", d) == "17112056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhz ap", d) == "1711256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz ap", d) == "17112056 pm");
	QVERIFY(Qpe::DateStringifier::format("smhhz ap", d) == "17110256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz ap", d) == "171102056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhhz ap", d) == "17110256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz ap", d) == "171102056 pm");

	QVERIFY(Qpe::DateStringifier::format("mshz ap", d) == "1117256 pm");
	QVERIFY(Qpe::DateStringifier::format("msshzzz ap", d) == "11172056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshz ap", d) == "1117256 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz ap", d) == "11172056 pm");
	QVERIFY(Qpe::DateStringifier::format("mshhz ap", d) == "11170256 pm");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz ap", d) == "111702056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshhz ap", d) == "11170256 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz ap", d) == "111702056 pm");

	QVERIFY(Qpe::DateStringifier::format("shmz ap", d) == "1721156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz ap", d) == "17211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shmmz ap", d) == "1721156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz ap", d) == "17211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmz ap", d) == "17021156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz ap", d) == "170211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmmz ap", d) == "17021156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz ap", d) == "170211056 pm");
}

void TestDateStringifier::testStaticTimeFormat__h_Am()
{
	QTime d(2, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s ap", d) == "2:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss ap", d) == "2:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s ap", d) == "2:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss ap", d) == "2:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s ap", d) == "02:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss ap", d) == "02:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s ap", d) == "02:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss ap", d) == "02:11:17 am");

	QVERIFY(Qpe::DateStringifier::format("m:h:s ap", d) == "11:2:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss ap", d) == "11:2:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s ap", d) == "11:2:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss ap", d) == "11:2:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s ap", d) == "11:02:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss ap", d) == "11:02:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s ap", d) == "11:02:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss ap", d) == "11:02:17 am");

	QVERIFY(Qpe::DateStringifier::format("h:s:m ap", d) == "2:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m ap", d) == "2:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm ap", d) == "2:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm ap", d) == "2:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m ap", d) == "02:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m ap", d) == "02:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm ap", d) == "02:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm ap", d) == "02:17:11 am");

	QVERIFY(Qpe::DateStringifier::format("s:m:h ap", d) == "17:11:2 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h ap", d) == "17:11:2 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h ap", d) == "17:11:2 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h ap", d) == "17:11:2 am");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh ap", d) == "17:11:02 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh ap", d) == "17:11:02 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh ap", d) == "17:11:02 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh ap", d) == "17:11:02 am");

	QVERIFY(Qpe::DateStringifier::format("m:s:h ap", d) == "11:17:2 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h ap", d) == "11:17:2 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h ap", d) == "11:17:2 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h ap", d) == "11:17:2 am");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh ap", d) == "11:17:02 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh ap", d) == "11:17:02 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh ap", d) == "11:17:02 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh ap", d) == "11:17:02 am");

	QVERIFY(Qpe::DateStringifier::format("s:h:m ap", d) == "17:2:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m ap", d) == "17:2:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm ap", d) == "17:2:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm ap", d) == "17:2:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m ap", d) == "17:02:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m ap", d) == "17:02:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm ap", d) == "17:02:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm ap", d) == "17:02:11 am");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z ap", d) == "2:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz ap", d) == "2:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z ap", d) == "2:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz ap", d) == "2:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z ap", d) == "02:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz ap", d) == "02:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z ap", d) == "02:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz ap", d) == "02:11:17.056 am");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z ap", d) == "11:2:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz ap", d) == "11:2:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z ap", d) == "11:2:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz ap", d) == "11:2:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z ap", d) == "11:02:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz ap", d) == "11:02:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z ap", d) == "11:02:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz ap", d) == "11:02:17.056 am");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z ap", d) == "2:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz ap", d) == "2:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z ap", d) == "2:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz ap", d) == "2:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z ap", d) == "02:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz ap", d) == "02:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z ap", d) == "02:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz ap", d) == "02:17:11.056 am");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z ap", d) == "17:11:2.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz ap", d) == "17:11:2.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z ap", d) == "17:11:2.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz ap", d) == "17:11:2.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z ap", d) == "17:11:02.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz ap", d) == "17:11:02.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z ap", d) == "17:11:02.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz ap", d) == "17:11:02.056 am");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z ap", d) == "11:17:2.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz ap", d) == "11:17:2.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z ap", d) == "11:17:2.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz ap", d) == "11:17:2.056 am");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z ap", d) == "11:17:02.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz ap", d) == "11:17:02.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z ap", d) == "11:17:02.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz ap", d) == "11:17:02.056 am");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z ap", d) == "17:2:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz ap", d) == "17:2:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z ap", d) == "17:2:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz ap", d) == "17:2:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z ap", d) == "17:02:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz ap", d) == "17:02:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z ap", d) == "17:02:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz ap", d) == "17:02:11.056 am");




	QVERIFY(Qpe::DateStringifier::format("hms ap", d) == "21117 am");
	QVERIFY(Qpe::DateStringifier::format("hmss ap", d) == "21117 am");
	QVERIFY(Qpe::DateStringifier::format("hmms ap", d) == "21117 am");
	QVERIFY(Qpe::DateStringifier::format("hmmss ap", d) == "21117 am");
	QVERIFY(Qpe::DateStringifier::format("hhms ap", d) == "021117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmss ap", d) == "021117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmms ap", d) == "021117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmss ap", d) == "021117 am");

	QVERIFY(Qpe::DateStringifier::format("mhs ap", d) == "11217 am");
	QVERIFY(Qpe::DateStringifier::format("mhss ap", d) == "11217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhs ap", d) == "11217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhss ap", d) == "11217 am");
	QVERIFY(Qpe::DateStringifier::format("mhhs ap", d) == "110217 am");
	QVERIFY(Qpe::DateStringifier::format("mhhss ap", d) == "110217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhs ap", d) == "110217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhss ap", d) == "110217 am");

	QVERIFY(Qpe::DateStringifier::format("hsm ap", d) == "21711 am");
	QVERIFY(Qpe::DateStringifier::format("hssm ap", d) == "21711 am");
	QVERIFY(Qpe::DateStringifier::format("hsmm ap", d) == "21711 am");
	QVERIFY(Qpe::DateStringifier::format("hssmm ap", d) == "21711 am");
	QVERIFY(Qpe::DateStringifier::format("hhsm ap", d) == "021711 am");
	QVERIFY(Qpe::DateStringifier::format("hhssm ap", d) == "021711 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmm ap", d) == "021711 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmm ap", d) == "021711 am");

	QVERIFY(Qpe::DateStringifier::format("smh ap", d) == "17112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmh ap", d) == "17112 am");
	QVERIFY(Qpe::DateStringifier::format("smmh ap", d) == "17112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmh ap", d) == "17112 am");
	QVERIFY(Qpe::DateStringifier::format("smhh ap", d) == "171102 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhh ap", d) == "171102 am");
	QVERIFY(Qpe::DateStringifier::format("smmhh ap", d) == "171102 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh ap", d) == "171102 am");

	QVERIFY(Qpe::DateStringifier::format("msh ap", d) == "11172 am");
	QVERIFY(Qpe::DateStringifier::format("mssh ap", d) == "11172 am");
	QVERIFY(Qpe::DateStringifier::format("mmsh ap", d) == "11172 am");
	QVERIFY(Qpe::DateStringifier::format("mmssh ap", d) == "11172 am");
	QVERIFY(Qpe::DateStringifier::format("mshh ap", d) == "111702 am");
	QVERIFY(Qpe::DateStringifier::format("msshh ap", d) == "111702 am");
	QVERIFY(Qpe::DateStringifier::format("mmshh ap", d) == "111702 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshh ap", d) == "111702 am");

	QVERIFY(Qpe::DateStringifier::format("shm ap", d) == "17211 am");
	QVERIFY(Qpe::DateStringifier::format("sshm ap", d) == "17211 am");
	QVERIFY(Qpe::DateStringifier::format("shmm ap", d) == "17211 am");
	QVERIFY(Qpe::DateStringifier::format("sshmm ap", d) == "17211 am");
	QVERIFY(Qpe::DateStringifier::format("shhm ap", d) == "170211 am");
	QVERIFY(Qpe::DateStringifier::format("sshhm ap", d) == "170211 am");
	QVERIFY(Qpe::DateStringifier::format("shhmm ap", d) == "170211 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmm ap", d) == "170211 am");


	QVERIFY(Qpe::DateStringifier::format("hmsz ap", d) == "2111756 am");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz ap", d) == "21117056 am");
	QVERIFY(Qpe::DateStringifier::format("hmmsz ap", d) == "2111756 am");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz ap", d) == "21117056 am");
	QVERIFY(Qpe::DateStringifier::format("hhmsz ap", d) == "02111756 am");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz ap", d) == "021117056 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz ap", d) == "02111756 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz ap", d) == "021117056 am");

	QVERIFY(Qpe::DateStringifier::format("mhsz ap", d) == "1121756 am");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz ap", d) == "11217056 am");
	QVERIFY(Qpe::DateStringifier::format("mmhsz ap", d) == "1121756 am");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz ap", d) == "11217056 am");
	QVERIFY(Qpe::DateStringifier::format("mhhsz ap", d) == "11021756 am");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz ap", d) == "110217056 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz ap", d) == "11021756 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz ap", d) == "110217056 am");

	QVERIFY(Qpe::DateStringifier::format("hsmz ap", d) == "2171156 am");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz ap", d) == "21711056 am");
	QVERIFY(Qpe::DateStringifier::format("hsmmz ap", d) == "2171156 am");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz ap", d) == "21711056 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmz ap", d) == "02171156 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz ap", d) == "021711056 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz ap", d) == "02171156 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz ap", d) == "021711056 am");

	QVERIFY(Qpe::DateStringifier::format("smhz ap", d) == "1711256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz ap", d) == "17112056 am");
	QVERIFY(Qpe::DateStringifier::format("smmhz ap", d) == "1711256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz ap", d) == "17112056 am");
	QVERIFY(Qpe::DateStringifier::format("smhhz ap", d) == "17110256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz ap", d) == "171102056 am");
	QVERIFY(Qpe::DateStringifier::format("smmhhz ap", d) == "17110256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz ap", d) == "171102056 am");

	QVERIFY(Qpe::DateStringifier::format("mshz ap", d) == "1117256 am");
	QVERIFY(Qpe::DateStringifier::format("msshzzz ap", d) == "11172056 am");
	QVERIFY(Qpe::DateStringifier::format("mmshz ap", d) == "1117256 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz ap", d) == "11172056 am");
	QVERIFY(Qpe::DateStringifier::format("mshhz ap", d) == "11170256 am");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz ap", d) == "111702056 am");
	QVERIFY(Qpe::DateStringifier::format("mmshhz ap", d) == "11170256 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz ap", d) == "111702056 am");

	QVERIFY(Qpe::DateStringifier::format("shmz ap", d) == "1721156 am");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz ap", d) == "17211056 am");
	QVERIFY(Qpe::DateStringifier::format("shmmz ap", d) == "1721156 am");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz ap", d) == "17211056 am");
	QVERIFY(Qpe::DateStringifier::format("shhmz ap", d) == "17021156 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz ap", d) == "170211056 am");
	QVERIFY(Qpe::DateStringifier::format("shhmmz ap", d) == "17021156 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz ap", d) == "170211056 am");
}

void TestDateStringifier::testStaticTimeFormat__h_12_Pm()
{
	QTime d(12, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s ap", d) == "12:11:17 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss ap", d) == "12:11:17 pm");

	QVERIFY(Qpe::DateStringifier::format("m:h:s ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s ap", d) == "11:12:17 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss ap", d) == "11:12:17 pm");

	QVERIFY(Qpe::DateStringifier::format("h:s:m ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm ap", d) == "12:17:11 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm ap", d) == "12:17:11 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:h ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh ap", d) == "17:11:12 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh ap", d) == "17:11:12 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:h ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh ap", d) == "11:17:12 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh ap", d) == "11:17:12 pm");

	QVERIFY(Qpe::DateStringifier::format("s:h:m ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm ap", d) == "17:12:11 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm ap", d) == "17:12:11 pm");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z ap", d) == "12:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz ap", d) == "12:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z ap", d) == "12:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz ap", d) == "12:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z ap", d) == "12:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz ap", d) == "12:11:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z ap", d) == "12:11:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz ap", d) == "12:11:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z ap", d) == "11:12:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz ap", d) == "11:12:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z ap", d) == "11:12:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz ap", d) == "11:12:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z ap", d) == "11:12:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz ap", d) == "11:12:17.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z ap", d) == "11:12:17.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz ap", d) == "11:12:17.056 pm");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z ap", d) == "12:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz ap", d) == "12:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z ap", d) == "12:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz ap", d) == "12:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z ap", d) == "12:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz ap", d) == "12:17:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z ap", d) == "12:17:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz ap", d) == "12:17:11.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z ap", d) == "17:11:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz ap", d) == "17:11:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z ap", d) == "17:11:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz ap", d) == "17:11:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z ap", d) == "17:11:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz ap", d) == "17:11:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z ap", d) == "17:11:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz ap", d) == "17:11:12.056 pm");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z ap", d) == "11:17:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz ap", d) == "11:17:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z ap", d) == "11:17:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz ap", d) == "11:17:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z ap", d) == "11:17:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz ap", d) == "11:17:12.056 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z ap", d) == "11:17:12.56 pm");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz ap", d) == "11:17:12.056 pm");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z ap", d) == "17:12:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz ap", d) == "17:12:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z ap", d) == "17:12:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz ap", d) == "17:12:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z ap", d) == "17:12:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz ap", d) == "17:12:11.056 pm");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z ap", d) == "17:12:11.56 pm");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz ap", d) == "17:12:11.056 pm");




	QVERIFY(Qpe::DateStringifier::format("hms ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmss ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmms ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmss ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhms ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmss ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmms ap", d) == "121117 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmss ap", d) == "121117 pm");

	QVERIFY(Qpe::DateStringifier::format("mhs ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhss ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhs ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhss ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhs ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhss ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhs ap", d) == "111217 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhss ap", d) == "111217 pm");

	QVERIFY(Qpe::DateStringifier::format("hsm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hssm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hsmm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmm ap", d) == "121711 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmm ap", d) == "121711 pm");

	QVERIFY(Qpe::DateStringifier::format("smh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("smmh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("smhh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhh ap", d) == "171112 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh ap", d) == "171112 pm");

	QVERIFY(Qpe::DateStringifier::format("msh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mssh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mmssh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mshh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("msshh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshh ap", d) == "111712 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshh ap", d) == "111712 pm");

	QVERIFY(Qpe::DateStringifier::format("shm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("shmm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("shhm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmm ap", d) == "171211 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmm ap", d) == "171211 pm");


	QVERIFY(Qpe::DateStringifier::format("hmsz ap", d) == "12111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz ap", d) == "121117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmsz ap", d) == "12111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz ap", d) == "121117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmsz ap", d) == "12111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz ap", d) == "121117056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz ap", d) == "12111756 pm");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz ap", d) == "121117056 pm");

	QVERIFY(Qpe::DateStringifier::format("mhsz ap", d) == "11121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz ap", d) == "111217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhsz ap", d) == "11121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz ap", d) == "111217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhsz ap", d) == "11121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz ap", d) == "111217056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz ap", d) == "11121756 pm");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz ap", d) == "111217056 pm");

	QVERIFY(Qpe::DateStringifier::format("hsmz ap", d) == "12171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz ap", d) == "121711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hsmmz ap", d) == "12171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz ap", d) == "121711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmz ap", d) == "12171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz ap", d) == "121711056 pm");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz ap", d) == "12171156 pm");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz ap", d) == "121711056 pm");

	QVERIFY(Qpe::DateStringifier::format("smhz ap", d) == "17111256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz ap", d) == "171112056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhz ap", d) == "17111256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz ap", d) == "171112056 pm");
	QVERIFY(Qpe::DateStringifier::format("smhhz ap", d) == "17111256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz ap", d) == "171112056 pm");
	QVERIFY(Qpe::DateStringifier::format("smmhhz ap", d) == "17111256 pm");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz ap", d) == "171112056 pm");

	QVERIFY(Qpe::DateStringifier::format("mshz ap", d) == "11171256 pm");
	QVERIFY(Qpe::DateStringifier::format("msshzzz ap", d) == "111712056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshz ap", d) == "11171256 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz ap", d) == "111712056 pm");
	QVERIFY(Qpe::DateStringifier::format("mshhz ap", d) == "11171256 pm");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz ap", d) == "111712056 pm");
	QVERIFY(Qpe::DateStringifier::format("mmshhz ap", d) == "11171256 pm");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz ap", d) == "111712056 pm");

	QVERIFY(Qpe::DateStringifier::format("shmz ap", d) == "17121156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz ap", d) == "171211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shmmz ap", d) == "17121156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz ap", d) == "171211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmz ap", d) == "17121156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz ap", d) == "171211056 pm");
	QVERIFY(Qpe::DateStringifier::format("shhmmz ap", d) == "17121156 pm");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz ap", d) == "171211056 pm");
}

void TestDateStringifier::testStaticTimeFormat__h_00_Am()
{
	QTime d(0, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s ap", d) == "12:11:17 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss ap", d) == "12:11:17 am");

	QVERIFY(Qpe::DateStringifier::format("m:h:s ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s ap", d) == "11:12:17 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss ap", d) == "11:12:17 am");

	QVERIFY(Qpe::DateStringifier::format("h:s:m ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm ap", d) == "12:17:11 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm ap", d) == "12:17:11 am");

	QVERIFY(Qpe::DateStringifier::format("s:m:h ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh ap", d) == "17:11:12 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh ap", d) == "17:11:12 am");

	QVERIFY(Qpe::DateStringifier::format("m:s:h ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh ap", d) == "11:17:12 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh ap", d) == "11:17:12 am");

	QVERIFY(Qpe::DateStringifier::format("s:h:m ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm ap", d) == "17:12:11 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm ap", d) == "17:12:11 am");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z ap", d) == "12:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz ap", d) == "12:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z ap", d) == "12:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz ap", d) == "12:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z ap", d) == "12:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz ap", d) == "12:11:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z ap", d) == "12:11:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz ap", d) == "12:11:17.056 am");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z ap", d) == "11:12:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz ap", d) == "11:12:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z ap", d) == "11:12:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz ap", d) == "11:12:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z ap", d) == "11:12:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz ap", d) == "11:12:17.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z ap", d) == "11:12:17.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz ap", d) == "11:12:17.056 am");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z ap", d) == "12:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz ap", d) == "12:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z ap", d) == "12:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz ap", d) == "12:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z ap", d) == "12:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz ap", d) == "12:17:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z ap", d) == "12:17:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz ap", d) == "12:17:11.056 am");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z ap", d) == "17:11:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz ap", d) == "17:11:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z ap", d) == "17:11:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz ap", d) == "17:11:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z ap", d) == "17:11:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz ap", d) == "17:11:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z ap", d) == "17:11:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz ap", d) == "17:11:12.056 am");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z ap", d) == "11:17:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz ap", d) == "11:17:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z ap", d) == "11:17:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz ap", d) == "11:17:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z ap", d) == "11:17:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz ap", d) == "11:17:12.056 am");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z ap", d) == "11:17:12.56 am");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz ap", d) == "11:17:12.056 am");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z ap", d) == "17:12:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz ap", d) == "17:12:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z ap", d) == "17:12:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz ap", d) == "17:12:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z ap", d) == "17:12:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz ap", d) == "17:12:11.056 am");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z ap", d) == "17:12:11.56 am");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz ap", d) == "17:12:11.056 am");




	QVERIFY(Qpe::DateStringifier::format("hms ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hmss ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hmms ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hmmss ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hhms ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmss ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmms ap", d) == "121117 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmss ap", d) == "121117 am");

	QVERIFY(Qpe::DateStringifier::format("mhs ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mhss ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhs ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhss ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mhhs ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mhhss ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhs ap", d) == "111217 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhss ap", d) == "111217 am");

	QVERIFY(Qpe::DateStringifier::format("hsm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hssm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hsmm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hssmm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hhsm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hhssm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmm ap", d) == "121711 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmm ap", d) == "121711 am");

	QVERIFY(Qpe::DateStringifier::format("smh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("smmh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("smhh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("smmhh ap", d) == "171112 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh ap", d) == "171112 am");

	QVERIFY(Qpe::DateStringifier::format("msh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mssh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mmsh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mmssh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mshh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("msshh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mmshh ap", d) == "111712 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshh ap", d) == "111712 am");

	QVERIFY(Qpe::DateStringifier::format("shm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("sshm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("shmm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("sshmm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("shhm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("sshhm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("shhmm ap", d) == "171211 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmm ap", d) == "171211 am");


	QVERIFY(Qpe::DateStringifier::format("hmsz ap", d) == "12111756 am");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz ap", d) == "121117056 am");
	QVERIFY(Qpe::DateStringifier::format("hmmsz ap", d) == "12111756 am");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz ap", d) == "121117056 am");
	QVERIFY(Qpe::DateStringifier::format("hhmsz ap", d) == "12111756 am");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz ap", d) == "121117056 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz ap", d) == "12111756 am");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz ap", d) == "121117056 am");

	QVERIFY(Qpe::DateStringifier::format("mhsz ap", d) == "11121756 am");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz ap", d) == "111217056 am");
	QVERIFY(Qpe::DateStringifier::format("mmhsz ap", d) == "11121756 am");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz ap", d) == "111217056 am");
	QVERIFY(Qpe::DateStringifier::format("mhhsz ap", d) == "11121756 am");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz ap", d) == "111217056 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz ap", d) == "11121756 am");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz ap", d) == "111217056 am");

	QVERIFY(Qpe::DateStringifier::format("hsmz ap", d) == "12171156 am");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz ap", d) == "121711056 am");
	QVERIFY(Qpe::DateStringifier::format("hsmmz ap", d) == "12171156 am");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz ap", d) == "121711056 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmz ap", d) == "12171156 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz ap", d) == "121711056 am");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz ap", d) == "12171156 am");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz ap", d) == "121711056 am");

	QVERIFY(Qpe::DateStringifier::format("smhz ap", d) == "17111256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz ap", d) == "171112056 am");
	QVERIFY(Qpe::DateStringifier::format("smmhz ap", d) == "17111256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz ap", d) == "171112056 am");
	QVERIFY(Qpe::DateStringifier::format("smhhz ap", d) == "17111256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz ap", d) == "171112056 am");
	QVERIFY(Qpe::DateStringifier::format("smmhhz ap", d) == "17111256 am");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz ap", d) == "171112056 am");

	QVERIFY(Qpe::DateStringifier::format("mshz ap", d) == "11171256 am");
	QVERIFY(Qpe::DateStringifier::format("msshzzz ap", d) == "111712056 am");
	QVERIFY(Qpe::DateStringifier::format("mmshz ap", d) == "11171256 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz ap", d) == "111712056 am");
	QVERIFY(Qpe::DateStringifier::format("mshhz ap", d) == "11171256 am");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz ap", d) == "111712056 am");
	QVERIFY(Qpe::DateStringifier::format("mmshhz ap", d) == "11171256 am");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz ap", d) == "111712056 am");

	QVERIFY(Qpe::DateStringifier::format("shmz ap", d) == "17121156 am");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz ap", d) == "171211056 am");
	QVERIFY(Qpe::DateStringifier::format("shmmz ap", d) == "17121156 am");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz ap", d) == "171211056 am");
	QVERIFY(Qpe::DateStringifier::format("shhmz ap", d) == "17121156 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz ap", d) == "171211056 am");
	QVERIFY(Qpe::DateStringifier::format("shhmmz ap", d) == "17121156 am");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz ap", d) == "171211056 am");
}

void TestDateStringifier::testStaticTimeFormat__h_app()
{
	QTime d(14, 11, 17, 56);
	QVERIFY(Qpe::DateStringifier::format("h:m:s app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s app", d) == "14:11:17 app");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss app", d) == "14:11:17 app");

	QVERIFY(Qpe::DateStringifier::format("m:h:s app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s app", d) == "11:14:17 app");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss app", d) == "11:14:17 app");

	QVERIFY(Qpe::DateStringifier::format("h:s:m app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm app", d) == "14:17:11 app");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm app", d) == "14:17:11 app");

	QVERIFY(Qpe::DateStringifier::format("s:m:h app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh app", d) == "17:11:14 app");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh app", d) == "17:11:14 app");

	QVERIFY(Qpe::DateStringifier::format("m:s:h app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh app", d) == "11:17:14 app");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh app", d) == "11:17:14 app");

	QVERIFY(Qpe::DateStringifier::format("s:h:m app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm app", d) == "17:14:11 app");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm app", d) == "17:14:11 app");


	QVERIFY(Qpe::DateStringifier::format("h:m:s.z app", d) == "14:11:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("h:m:ss.zzz app", d) == "14:11:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("h:mm:s.z app", d) == "14:11:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("h:mm:ss.zzz app", d) == "14:11:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("hh:m:s.z app", d) == "14:11:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("hh:m:ss.zzz app", d) == "14:11:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:s.z app", d) == "14:11:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("hh:mm:ss.zzz app", d) == "14:11:17.056 app");

	QVERIFY(Qpe::DateStringifier::format("m:h:s.z app", d) == "11:14:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("m:h:ss.zzz app", d) == "11:14:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("mm:h:s.z app", d) == "11:14:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("mm:h:ss.zzz app", d) == "11:14:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("m:hh:s.z app", d) == "11:14:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("m:hh:ss.zzz app", d) == "11:14:17.056 app");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:s.z app", d) == "11:14:17.56 app");
	QVERIFY(Qpe::DateStringifier::format("mm:hh:ss.zzz app", d) == "11:14:17.056 app");

	QVERIFY(Qpe::DateStringifier::format("h:s:m.z app", d) == "14:17:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("h:ss:m.zzz app", d) == "14:17:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("h:s:mm.z app", d) == "14:17:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("h:ss:mm.zzz app", d) == "14:17:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("hh:s:m.z app", d) == "14:17:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:m.zzz app", d) == "14:17:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("hh:s:mm.z app", d) == "14:17:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("hh:ss:mm.zzz app", d) == "14:17:11.056 app");

	QVERIFY(Qpe::DateStringifier::format("s:m:h.z app", d) == "17:11:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:m:h.zzz app", d) == "17:11:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:mm:h.z app", d) == "17:11:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:h.zzz app", d) == "17:11:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:m:hh.z app", d) == "17:11:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:m:hh.zzz app", d) == "17:11:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:mm:hh.z app", d) == "17:11:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:mm:hh.zzz app", d) == "17:11:14.056 app");

	QVERIFY(Qpe::DateStringifier::format("m:s:h.z app", d) == "11:17:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("m:ss:h.zzz app", d) == "11:17:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("mm:s:h.z app", d) == "11:17:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:h.zzz app", d) == "11:17:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("m:s:hh.z app", d) == "11:17:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("m:ss:hh.zzz app", d) == "11:17:14.056 app");
	QVERIFY(Qpe::DateStringifier::format("mm:s:hh.z app", d) == "11:17:14.56 app");
	QVERIFY(Qpe::DateStringifier::format("mm:ss:hh.zzz app", d) == "11:17:14.056 app");

	QVERIFY(Qpe::DateStringifier::format("s:h:m.z app", d) == "17:14:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:h:m.zzz app", d) == "17:14:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:h:mm.z app", d) == "17:14:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:h:mm.zzz app", d) == "17:14:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:hh:m.z app", d) == "17:14:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:m.zzz app", d) == "17:14:11.056 app");
	QVERIFY(Qpe::DateStringifier::format("s:hh:mm.z app", d) == "17:14:11.56 app");
	QVERIFY(Qpe::DateStringifier::format("ss:hh:mm.zzz app", d) == "17:14:11.056 app");




	QVERIFY(Qpe::DateStringifier::format("hms app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hmss app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hmms app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hmmss app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hhms app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hhmss app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hhmms app", d) == "141117 app");
	QVERIFY(Qpe::DateStringifier::format("hhmmss app", d) == "141117 app");

	QVERIFY(Qpe::DateStringifier::format("mhs app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mhss app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mmhs app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mmhss app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mhhs app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mhhss app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mmhhs app", d) == "111417 app");
	QVERIFY(Qpe::DateStringifier::format("mmhhss app", d) == "111417 app");

	QVERIFY(Qpe::DateStringifier::format("hsm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hssm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hsmm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hssmm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hhsm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hhssm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hhsmm app", d) == "141711 app");
	QVERIFY(Qpe::DateStringifier::format("hhssmm app", d) == "141711 app");

	QVERIFY(Qpe::DateStringifier::format("smh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("ssmh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("smmh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("ssmmh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("smhh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("ssmhh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("smmhh app", d) == "171114 app");
	QVERIFY(Qpe::DateStringifier::format("ssmmhh app", d) == "171114 app");

	QVERIFY(Qpe::DateStringifier::format("msh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mssh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mmsh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mmssh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mshh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("msshh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mmshh app", d) == "111714 app");
	QVERIFY(Qpe::DateStringifier::format("mmsshh app", d) == "111714 app");

	QVERIFY(Qpe::DateStringifier::format("shm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("sshm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("shmm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("sshmm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("shhm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("sshhm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("shhmm app", d) == "171411 app");
	QVERIFY(Qpe::DateStringifier::format("sshhmm app", d) == "171411 app");


	QVERIFY(Qpe::DateStringifier::format("hmsz app", d) == "14111756 app");
	QVERIFY(Qpe::DateStringifier::format("hmsszzz app", d) == "141117056 app");
	QVERIFY(Qpe::DateStringifier::format("hmmsz app", d) == "14111756 app");
	QVERIFY(Qpe::DateStringifier::format("hmmsszzz app", d) == "141117056 app");
	QVERIFY(Qpe::DateStringifier::format("hhmsz app", d) == "14111756 app");
	QVERIFY(Qpe::DateStringifier::format("hhmsszzz app", d) == "141117056 app");
	QVERIFY(Qpe::DateStringifier::format("hhmmsz app", d) == "14111756 app");
	QVERIFY(Qpe::DateStringifier::format("hhmmsszzz app", d) == "141117056 app");

	QVERIFY(Qpe::DateStringifier::format("mhsz app", d) == "11141756 app");
	QVERIFY(Qpe::DateStringifier::format("mhsszzz app", d) == "111417056 app");
	QVERIFY(Qpe::DateStringifier::format("mmhsz app", d) == "11141756 app");
	QVERIFY(Qpe::DateStringifier::format("mmhsszzz app", d) == "111417056 app");
	QVERIFY(Qpe::DateStringifier::format("mhhsz app", d) == "11141756 app");
	QVERIFY(Qpe::DateStringifier::format("mhhsszzz app", d) == "111417056 app");
	QVERIFY(Qpe::DateStringifier::format("mmhhsz app", d) == "11141756 app");
	QVERIFY(Qpe::DateStringifier::format("mmhhsszzz app", d) == "111417056 app");

	QVERIFY(Qpe::DateStringifier::format("hsmz app", d) == "14171156 app");
	QVERIFY(Qpe::DateStringifier::format("hssmzzz app", d) == "141711056 app");
	QVERIFY(Qpe::DateStringifier::format("hsmmz app", d) == "14171156 app");
	QVERIFY(Qpe::DateStringifier::format("hssmmzzz app", d) == "141711056 app");
	QVERIFY(Qpe::DateStringifier::format("hhsmz app", d) == "14171156 app");
	QVERIFY(Qpe::DateStringifier::format("hhssmzzz app", d) == "141711056 app");
	QVERIFY(Qpe::DateStringifier::format("hhsmmz app", d) == "14171156 app");
	QVERIFY(Qpe::DateStringifier::format("hhssmmzzz app", d) == "141711056 app");

	QVERIFY(Qpe::DateStringifier::format("smhz app", d) == "17111456 app");
	QVERIFY(Qpe::DateStringifier::format("ssmhzzz app", d) == "171114056 app");
	QVERIFY(Qpe::DateStringifier::format("smmhz app", d) == "17111456 app");
	QVERIFY(Qpe::DateStringifier::format("ssmmhzzz app", d) == "171114056 app");
	QVERIFY(Qpe::DateStringifier::format("smhhz app", d) == "17111456 app");
	QVERIFY(Qpe::DateStringifier::format("ssmhhzzz app", d) == "171114056 app");
	QVERIFY(Qpe::DateStringifier::format("smmhhz app", d) == "17111456 app");
	QVERIFY(Qpe::DateStringifier::format("ssmmhhzzz app", d) == "171114056 app");

	QVERIFY(Qpe::DateStringifier::format("mshz app", d) == "11171456 app");
	QVERIFY(Qpe::DateStringifier::format("msshzzz app", d) == "111714056 app");
	QVERIFY(Qpe::DateStringifier::format("mmshz app", d) == "11171456 app");
	QVERIFY(Qpe::DateStringifier::format("mmsshzzz app", d) == "111714056 app");
	QVERIFY(Qpe::DateStringifier::format("mshhz app", d) == "11171456 app");
	QVERIFY(Qpe::DateStringifier::format("msshhzzz app", d) == "111714056 app");
	QVERIFY(Qpe::DateStringifier::format("mmshhz app", d) == "11171456 app");
	QVERIFY(Qpe::DateStringifier::format("mmsshhzzz app", d) == "111714056 app");

	QVERIFY(Qpe::DateStringifier::format("shmz app", d) == "17141156 app");
	QVERIFY(Qpe::DateStringifier::format("sshmzzz app", d) == "171411056 app");
	QVERIFY(Qpe::DateStringifier::format("shmmz app", d) == "17141156 app");
	QVERIFY(Qpe::DateStringifier::format("sshmmzzz app", d) == "171411056 app");
	QVERIFY(Qpe::DateStringifier::format("shhmz app", d) == "17141156 app");
	QVERIFY(Qpe::DateStringifier::format("sshhmzzz app", d) == "171411056 app");
	QVERIFY(Qpe::DateStringifier::format("shhmmz app", d) == "17141156 app");
	QVERIFY(Qpe::DateStringifier::format("sshhmmzzz app", d) == "171411056 app");
}

QTEST_MAIN(TestDateStringifier)

#include "test_datestringifier.moc"

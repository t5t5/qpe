#include <QtTest/QTest>
#include <QDebug>
#include <QVariant>
#include <QVector>
#include <QByteArray>
#include <QRandomGenerator>

#include <Qpe/Core/Enum>

#define QPE_TEST_ITERATIONS 500000

namespace Qpe
{

#ifndef Q_QDOC
inline namespace qpe_metas
{
Q_NAMESPACE
#endif // Q_QDOC

enum class Metas : int
//enum Metas
{
	UnknownType,
	Bool,
	Int,
	UInt,
	LongLong,
	ULongLong,
	Double,
	QChar,
	QVariantMap,
	QVariantList,
	QString,
	QStringList,
	QByteArray,
	QBitArray,
	QDate,
	QTime,
	QDateTime,
	QUrl,
	QLocale,
	QRect,
	QRectF,
	QSize,
	QSizeF,
	QLine,
	QLineF,
	QPoint,
	QPointF,
	QRegExp,
	QVariantHash,
	QEasingCurve,
	QUuid,
	VoidStar,
	Long,
	Short,
	Char,
	ULong,
	UShort,
	UChar,
	Float,
	QObjectStar,
	SChar,
	QVariant,
	QModelIndex,
	Void,
	QRegularExpression,
	QJsonValue,
	QJsonObject,
	QJsonArray,
	QJsonDocument,
	QByteArrayList,
	QPersistentModelIndex,
	QFont,
	QPixmap,
	QBrush,
	QColor,
	QPalette,
	QIcon,
	QImage,
	QPolygon,
	QRegion,
	QBitmap,
	QCursor,
	QKeySequence,
	QPen,
	QTextLength,
	QTextFormat,
	QMatrix,
	QTransform,
	QMatrix4x4,
	QVector2D,
	QVector3D,
	QVector4D,
	QQuaternion,
	QPolygonF,
	QSizePolicy,
	User,
	_metas_end
};
Q_ENUM_NS(Metas)

#ifndef Q_QDOC
} // namespace qpe_metas
#endif // Q_QDOC

// ------------------------------------------------------------------------

#ifndef Q_QDOC
inline namespace qpe_enumtest1
{
Q_NAMESPACE
#endif // Q_QDOC

enum EnumTest1
{
	v1, v2, v3
};
Q_ENUM_NS(EnumTest1)

#ifndef Q_QDOC
} // namespace qpe_enumtest1
#endif // Q_QDOC

typedef Enum<EnumTest1> EnumForTest1;

// ------------------------------------------------------------------------

#ifndef Q_QDOC
inline namespace qpe_flagtest2
{
Q_NAMESPACE
#endif // Q_QDOC

enum FlagTest2
{
	f1 = 1, f2 = 2, f3 = 4
};
Q_FLAG_NS(FlagTest2)

#ifndef Q_QDOC
} // namespace qpe_flagtest2
#endif // Q_QDOC

typedef Flag<FlagTest2> FlagForTest2;

} // namespace Qpe

class TestEnum : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void test();

	void bench_Qt_Enum();
	void bench_Qpe_Enum();

	void test_enum();
	void test_flag();
private:
	QVector<QByteArray> values;
};

void TestEnum::initTestCase()
{
	using namespace Qpe;
	QVector<QByteArray> keys = Enum<Metas>::keys();
	values.reserve(QPE_TEST_ITERATIONS);
	for (int i = 0; i < QPE_TEST_ITERATIONS; ++i) {
		int pos = QRandomGenerator::global()->bounded(keys.size());
		values.append(keys.at(pos));
	}
}

void TestEnum::test()
{
	using namespace Qpe;

	Enum<Metas> e;
	qDebug() << e.keys();
}

void TestEnum::bench_Qt_Enum()
{
	QMetaEnum me = QMetaEnum::fromType<Qpe::Metas>();
//	me.keyToValue()

	quint64 n = 0;
	QBENCHMARK {
		for (int i = 0; i < QPE_TEST_ITERATIONS; ++i) {
//			const QByteArray& key = values.at(i).toUtf8();
//			uint s = static_cast<uint>(me.keyToValue(key.data()));
			uint s = static_cast<uint>(me.keyToValue(values.at(i).data()));
			n += s;
		}
	}
	qDebug() << n;
}

void TestEnum::bench_Qpe_Enum()
{
	using namespace Qpe;

	typedef Enum<Metas> MetasEnum;

	quint64 n = 0;
	QBENCHMARK {
		for (int i = 0; i < QPE_TEST_ITERATIONS; ++i) {
			uint s = static_cast<uint>(MetasEnum(values.at(i)).value());
			n += s;
		}
	}
	qDebug() << n;
}

void TestEnum::test_enum()
{
	using namespace Qpe;
	{
		EnumForTest1 t;
		QVERIFY(!t.isValid());
		QVERIFY(t.isEmpty());

		QVERIFY(EnumForTest1::valueToKey(EnumTest1::v1) == "v1");
		QVERIFY(EnumForTest1::valueToKey(EnumTest1::v2) == "v2");
		QVERIFY(EnumForTest1::valueToKey(EnumTest1::v3) == "v3");

		QVector<EnumTest1> values = EnumForTest1::values();
		QVERIFY((values.size() == 3)
			&& (values.contains(EnumTest1::v1))
			&& (values.contains(EnumTest1::v2))
			&& (values.contains(EnumTest1::v3)));

		auto keyNames = EnumForTest1::keys();
		QVERIFY((keyNames.size() == 3)
			&& (keyNames.contains("v1"))
			&& (keyNames.contains("v2"))
			&& (keyNames.contains("v3")));
	}
	{
		EnumForTest1 t(EnumTest1::v1);
		QVERIFY(t.isValid());
		QVERIFY(!t.isEmpty());
		QVERIFY(t.value() == EnumTest1::v1);
		QVERIFY(t.in(EnumTest1::v1));
		QVERIFY(!t.in(EnumTest1::v2));
		QVERIFY(t.in(EnumTest1::v1, EnumTest1::v2));
		QVERIFY(!t.in(EnumTest1::v2, EnumTest1::v3));
		QVERIFY(t == EnumTest1::v1);
		QVERIFY(t != EnumTest1::v2);
	}
	{
		EnumForTest1 t1(EnumTest1::v2);
		QVERIFY(t1 == EnumTest1::v2);
		EnumForTest1 t2(t1);
		QVERIFY(t1 == EnumTest1::v2);
		QVERIFY(t2 == EnumTest1::v2);
		QVERIFY(t2 == t1);
		QVERIFY(t2 != EnumForTest1(EnumTest1::v3));
	}
	{
		EnumForTest1 t(1);
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v2);
	}
	{
		EnumForTest1 t(3);
		QVERIFY(!t.isValid());
	}
	{
		EnumForTest1 t("v1");
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v1);
	}
	{
		EnumForTest1 t("v");
		QVERIFY(!t.isValid());
	}
	{
		EnumForTest1 t("V1");
		QVERIFY(!t.isValid());
	}
	{
		EnumForTest1 t("V1", Qt::CaseInsensitive);
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v1);
	}
	{
		EnumForTest1 t("v", EnumTest1::v3);
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v3);
	}
	{
		EnumForTest1 t("v", static_cast<EnumTest1>(3));
		QVERIFY(!t.isValid());
	}
	{
		EnumForTest1 t(EnumTest1::v3);
		QVERIFY(t.key() == "v3");
	}
	{
		EnumForTest1 t;
		QVERIFY(!t.isValid());
		t.setValue(EnumTest1::v3);
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v3);
	}
	{
		EnumForTest1 t;
		QVERIFY(!t.isValid());
		t.setValue<EnumTest1::v2>();
		QVERIFY(t.isValid());
		QVERIFY(t == EnumTest1::v2);
	}
	{
		EnumForTest1 t1;
		QVERIFY(!t1.isValid());
		EnumForTest1 t2(EnumTest1::v2);
		QVERIFY(t2 == EnumTest1::v2);
		t1 = t2;
		QVERIFY(t2 == t1);
		QVERIFY(t1 == EnumTest1::v2);
	}
	{
		EnumForTest1 t1;
		QVERIFY(!t1.isValid());
		EnumForTest1 t2(EnumTest1::v2);
		QVERIFY(t2 == EnumTest1::v2);
		t2 = t1;
		QVERIFY(t2 != t1);
		QVERIFY(!t2.isValid());
	}
	{
		EnumForTest1 t1;
		QVERIFY(!t1.isValid());
		t1 = EnumTest1::v3;
		QVERIFY(t1 == EnumTest1::v3);
	}
}

void TestEnum::test_flag()
{
	using namespace Qpe;
	{
		QVERIFY(FlagForTest2::mask() == 7);

		QVERIFY(FlagForTest2::values() ==
			(QVector<FlagTest2>()
				<< f1 << f2 << f3));
		QVERIFY(FlagForTest2::allKeys() == (QVector<QByteArray>() << "f1" << "f2" << "f3"));

		QVERIFY(FlagForTest2::valueToKey(f1) == "f1");
		QVERIFY(FlagForTest2::valueToKeys(0).toList().toSet() == QSet<QByteArray>());
		QVERIFY(FlagForTest2::valueToKeys(1).toList().toSet() == QSet<QByteArray>({"f1"}));
		QVERIFY(FlagForTest2::valueToKeys(2).toList().toSet() == QSet<QByteArray>({"f2"}));
		QVERIFY(FlagForTest2::valueToKeys(3).toList().toSet() == QSet<QByteArray>({"f1", "f2"}));
		QVERIFY(FlagForTest2::valueToKeys(4).toList().toSet() == QSet<QByteArray>({"f3"}));
		QVERIFY(FlagForTest2::valueToKeys(5).toList().toSet() == QSet<QByteArray>({"f1", "f3"}));
		QVERIFY(FlagForTest2::valueToKeys(6).toList().toSet() == QSet<QByteArray>({"f2", "f3"}));
		QVERIFY(FlagForTest2::valueToKeys(7).toList().toSet() == QSet<QByteArray>({"f1", "f2", "f3"}));
	}
	{
		FlagForTest2 f;
		QVERIFY(f.value() == 0);
	}
	{
		FlagForTest2 f(f1);
		QVERIFY(f.value() == f1);
	}
	{
		FlagForTest2 ff1(f1);
		QVERIFY(ff1.value() == f1);

		FlagForTest2 ff2(f1);
		QVERIFY(ff2.value() == f1);
	}
	{
		FlagForTest2 ff1(1);
		QVERIFY(ff1.value() == 1);
		QVERIFY(ff1.keys().toList().toSet() == QSet<QByteArray>({"f1"}));
		FlagForTest2 ff2(2);
		QVERIFY(ff2.value() == 2);
		QVERIFY(ff2.keys().toList().toSet() == QSet<QByteArray>({"f2"}));
		FlagForTest2 ff3(3);
		QVERIFY(ff3.value() == 3);
		QVERIFY(ff3.keys().toList().toSet() == QSet<QByteArray>({"f1", "f2"}));
		FlagForTest2 ff4(4);
		QVERIFY(ff4.value() == 4);
		QVERIFY(ff4.keys().toList().toSet() == QSet<QByteArray>({"f3"}));
		FlagForTest2 ff5(5);
		QVERIFY(ff5.value() == 5);
		QVERIFY(ff5.keys().toList().toSet() == QSet<QByteArray>({"f1", "f3"}));
		FlagForTest2 ff6(6);
		QVERIFY(ff6.value() == 6);
		QVERIFY(ff6.keys().toList().toSet() == QSet<QByteArray>({"f2", "f3"}));
		FlagForTest2 ff7(7);
		QVERIFY(ff7.value() == 7);
		QVERIFY(ff7.keys().toList().toSet() == QSet<QByteArray>({"f1", "f2", "f3"}));
	}
	{
		FlagForTest2 ff1("f1");
		QVERIFY(ff1.value() == f1);
		FlagForTest2 ff2("f2");
		QVERIFY(ff2.value() == f2);
		FlagForTest2 ff3("f3");
		QVERIFY(ff3.value() == f3);
	}
	{
		FlagForTest2 ff1("F1", Qt::CaseInsensitive);
		QVERIFY(ff1.value() == f1);
		FlagForTest2 ff2("F2", Qt::CaseInsensitive);
		QVERIFY(ff2.value() == f2);
		FlagForTest2 ff3("F3", Qt::CaseInsensitive);
		QVERIFY(ff3.value() == f3);
	}
	{
		FlagForTest2 ff1("F1");
		QVERIFY(ff1.value() == 0);
		FlagForTest2 ff2("F2");
		QVERIFY(ff2.value() == 0);
		FlagForTest2 ff3("F3");
		QVERIFY(ff3.value() == 0);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f1"}));
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f2"}));
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f1", "f2"}));
		QVERIFY(f.value() == 3);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f3"}));
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f3", "f1"}));
		QVERIFY(f.value() == 5);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f3", "f2"}));
		QVERIFY(f.value() == 6);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"f3", "f2", "f1"}));
		QVERIFY(f.value() == 7);
	}

	{
		FlagForTest2 f(QVector<QByteArray>({"F1"}));
		QVERIFY(f.value() == 0);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F2"}));
		QVERIFY(f.value() == 0);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F1", "f2"}));
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3"}));
		QVERIFY(f.value() == 0);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f1"}));
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f2"}));
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f2", "f1"}));
		QVERIFY(f.value() == 3);
	}

	{
		FlagForTest2 f(QVector<QByteArray>({"F1"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F2"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F1", "f2"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 3);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f1"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 5);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f2"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 6);
	}
	{
		FlagForTest2 f(QVector<QByteArray>({"F3", "f2", "f1"}), Qt::CaseInsensitive);
		QVERIFY(f.value() == 7);
	}

	{
		FlagForTest2 f(QList<QByteArray>({"f1"}));
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f2"}));
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f1", "f2"}));
		QVERIFY(f.value() == 3);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f3"}));
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f3", "f1"}));
		QVERIFY(f.value() == 5);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f3", "f2"}));
		QVERIFY(f.value() == 6);
	}
	{
		FlagForTest2 f(QList<QByteArray>({"f3", "f2", "f1"}));
		QVERIFY(f.value() == 7);
	}

	{
		FlagForTest2 f;
		QVERIFY(f.value() == 0);
		f.setValue(f2);
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f;
		QVERIFY(f.value() == 0);
		f.setValue(FlagForTest2(f2));
		QVERIFY(f.value() == 2);
	}
	{
		FlagForTest2 f;
		QVERIFY(f.value() == 0);
		f.setValue(4);
		QVERIFY(f.value() == f3);
	}
	{
		FlagForTest2 f;
		QVERIFY(f.value() == 0);
		f.setValue<f2>();
		QVERIFY(f.value() == f2);
	}

	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		QVERIFY((f & 4u).value() == 4);
		QVERIFY((f & f1).value() == 1);
		QVERIFY((f & FlagForTest2(f2)).value() == 2);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f &= 4u;
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f &= f1;
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f &= FlagForTest2(f2);
		QVERIFY(f.value() == 2);
	}

	{
		FlagForTest2 f(0);
		QVERIFY(f.value() == 0);
		QVERIFY((f | 4u).value() == 4);
		QVERIFY((f | f1).value() == 1);
		QVERIFY((f | FlagForTest2(f2)).value() == 2);
	}
	{
		FlagForTest2 f(4);
		QVERIFY(f.value() == 4);
		QVERIFY((f | 4u).value() == 4);
		QVERIFY((f | f1).value() == 5);
		QVERIFY((f | FlagForTest2(f2)).value() == 6);
	}
	{
		FlagForTest2 f(0);
		QVERIFY(f.value() == 0);
		f |= 4u;
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(4);
		QVERIFY(f.value() == 4);
		f |= 4u;
		QVERIFY(f.value() == 4);
	}
	{
		FlagForTest2 f(0);
		QVERIFY(f.value() == 0);
		f |= f1;
		QVERIFY(f.value() == 1);
	}
	{
		FlagForTest2 f(0);
		QVERIFY(f.value() == 0);
		f |= FlagForTest2(f2);
		QVERIFY(f.value() == 2);
	}

	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		QVERIFY((f ^ 4u).value() == 3);
		QVERIFY((f ^ f1).value() == 6);
		QVERIFY((f ^ FlagForTest2(f2)).value() == 5);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f ^= 4u;
		QVERIFY(f.value() == 3);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f ^= f1;
		QVERIFY(f.value() == 6);
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.value() == 7);
		f ^= FlagForTest2(f2);
		QVERIFY(f.value() == 5);
	}
//	{
//		QVERIFY((f1 | f2).value() == 3);
//		QVERIFY((f1 | FlagForTest2(2)).value() == 3);
//	}

	{
		FlagForTest2 f = f1 | f3;
		QVERIFY(f.test(f1));
		QVERIFY(f.test(f3));
		QVERIFY(!f.test(f2));
	}

	{
		FlagForTest2 f = f1 | f3;
		QVERIFY(f.test(FlagForTest2(1)));
		QVERIFY(f.test(FlagForTest2(4)));
		QVERIFY(!f.test(FlagForTest2(2)));
	}

	{
		FlagForTest2 f;
		QVERIFY(!f.isValid());
	}
	{
		FlagForTest2 f(1);
		QVERIFY(f.isValid());
	}
	{
		FlagForTest2 f(7);
		QVERIFY(f.isValid());
	}
	{
		FlagForTest2 f(15);
		QVERIFY(!f.isValid());
	}
}

QTEST_MAIN(TestEnum)

#include "test_enum.moc"

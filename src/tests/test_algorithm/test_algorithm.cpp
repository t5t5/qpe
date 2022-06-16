#include <QtTest/QTest>
#include <QDebug>
#include <QSet>

#include <map>
#include <unordered_map>

#include <Qpe/Core/Algorithm>

struct Foo
{
	int id = 0;
	QString name;

	Foo(int i, const QString& n) : id(i), name(n) { }

	bool operator==(const Foo& o) const
	{
		return (id == o.id) && (name == o.name);
	}

	bool operator<(const Foo& o) const
	{
		return (id != o.id)
			? (id < o.id)
			: (name < o.name);
	}
};

class TestAlgorithm : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void test__map_find();
	void test__map_const_find_1();
	void test__map_const_find_2();
	void test__map_find_id();
	void test__map_const_find_if_1();
	void test__map_const_find_if_2();
	void test__map_find_id__erase();
	void test__map_find_id__insert();
	void test__map_erase();
	void test__map_create();
	void test__map_insert_value();
	void test__map_insert_key_value();
	void test__map_for_each();
	void test__map_const_for_each_1();
	void test__map_const_for_each_2();
	void test__map_contains();
	void test__map_contains_if();

	void test__array_find();
	void test__array_const_find_1();
	void test__array_const_find_2();
	void test__array_find_if();
	void test__array_const_find_if_1();
	void test__array_const_find_if_2();
	void test__array_erase();
	void test__array_create();
	void test__array_insert();
	void test__array_contains();
	void test__array_contains_if();
	void test__array_ordered_find();
	void test__array_ordered_find_compare();
	void test__array_const_ordered_find_1();
	void test__array_const_ordered_find_compare_1();
	void test__array_const_ordered_find_2();
	void test__array_const_ordered_find_compare_2();
	void test__array_ordered_find__erase();
	void test__array_ordered_find__create();
	void test__array_ordered_find__insert();
private:
	QHash<QString, int> h1;
	QMap<QString, int> m1;

	std::unordered_map<QString, int> h2;
	std::map<QString, int> m2;

	QHash<int, Foo> fh1;
	QMap<int, Foo> fm1;

	std::unordered_map<int, Foo> fh2;
	std::map<int, Foo> fm2;


	QList<int> li1;
	QVector<int> li2;
	std::vector<int> li3;

	QList<QString> ls1;
	QVector<QString> ls2;
	std::vector<QString> ls3;

	QList<Foo> lf1;
	QVector<Foo> lf2;
	std::vector<Foo> lf3;
};

void TestAlgorithm::initTestCase()
{
	h1 =
	{
		{ "aaa", 111 },
		{ "nnn", 222 },
		{ "zzz", 333 }
	};
	h2 =
	{
		{ "aaa", 111 },
		{ "nnn", 222 },
		{ "zzz", 333 }
	};

	m1 =
	{
		{ "aaa", 111 },
		{ "nnn", 222 },
		{ "zzz", 333 }
	};
	m2 =
	{
		{ "aaa", 111 },
		{ "nnn", 222 },
		{ "zzz", 333 }
	};

	fh1 =
	{
		{ 100, { 1000, "aaa" } },
		{ 200, { 2000, "nnn" } },
		{ 300, { 3000, "zzz" } },
	};
	fh2 =
	{
		{ 100, { 1000, "aaa" } },
		{ 200, { 2000, "nnn" } },
		{ 300, { 3000, "zzz" } },
	};
	fm1 =
	{
		{ 100, { 1000, "aaa" } },
		{ 200, { 2000, "nnn" } },
		{ 300, { 3000, "zzz" } },
	};
	fm2 =
	{
		{ 100, { 1000, "aaa" } },
		{ 200, { 2000, "nnn" } },
		{ 300, { 3000, "zzz" } },
	};

	li1 = { 111, 222, 333 };
	li2 = { 111, 222, 333 };
	li3 = { 111, 222, 333 };

	ls1 = { "aaa", "nnn", "zzz" };
	ls2 = { "aaa", "nnn", "zzz" };
	ls3 = { "aaa", "nnn", "zzz" };

	lf1 = { Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo { 3000, "zzz" } };
	lf2 = { Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo { 3000, "zzz" } };
	lf3 = { Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo { 3000, "zzz" } };
}

void TestAlgorithm::test__map_find()
{
	{
		auto h = h1;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		auto h = h2;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
	{
		auto h = m1;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		auto h = m2;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
}

void TestAlgorithm::test__map_const_find_1()
{
	{
		const auto h = h1;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		const auto h = h2;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
	{
		const auto h = m1;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		const auto h = m2;
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
}

void TestAlgorithm::test__map_const_find_2()
{
	{
		auto h = h1;
		auto r = Qpe::Map::const_find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		auto h = h2;
		auto r = Qpe::Map::const_find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
	{
		auto h = m1;
		auto r = Qpe::Map::const_find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
	}
	{
		auto h = m2;
		auto r = Qpe::Map::const_find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
	}
}

void TestAlgorithm::test__map_find_id()
{
	{
		auto h = fh1;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fh2;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fm1;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fm2;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
}

void TestAlgorithm::test__map_const_find_if_1()
{
	{
		const auto h = fh1;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		const auto h = fh2;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		const auto h = fm1;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		const auto h = fm2;
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
}

void TestAlgorithm::test__map_const_find_if_2()
{
	{
		auto h = fh1;
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fh2;
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fm1;
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->id == 2000);
			QVERIFY(r->name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
	{
		auto h = fm2;
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 200; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int, const Foo& v) { return v.id == 2000; });
			QVERIFY(bool(r));
			QVERIFY(r->second.id == 2000);
			QVERIFY(r->second.name == "nnn");
		}
		{
			auto r = Qpe::Map::const_find_if(h, [] (int key, const Foo&) { return key == 150; });
			QVERIFY(!r);
		}
	}
}

void TestAlgorithm::test__map_find_id__erase()
{
	{
		auto h = fh1;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(bool(r));
		QVERIFY(r->id == 2000);
		QVERIFY(r->name == "nnn");
		r.erase();
		QVERIFY(h.size() == 2);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(!r1);
	}
	{
		auto h = fh2;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(bool(r));
		QVERIFY(r->second.id == 2000);
		QVERIFY(r->second.name == "nnn");
		r.erase();
		QVERIFY(h.size() == 2);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(!r1);
	}
	{
		auto h = fm1;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(bool(r));
		QVERIFY(r->id == 2000);
		QVERIFY(r->name == "nnn");
		r.erase();
		QVERIFY(h.size() == 2);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(!r1);
	}
	{
		auto h = fm2;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(bool(r));
		QVERIFY(r->second.id == 2000);
		QVERIFY(r->second.name == "nnn");
		r.erase();
		QVERIFY(h.size() == 2);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 200; });
		QVERIFY(!r1);
	}
}

void TestAlgorithm::test__map_find_id__insert()
{
	{
		auto h = fh1;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(!r);
		r.insert(150, Foo(1500, "hhh"));
		QVERIFY(h.size() == 4);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1500);
		QVERIFY(r1->name == "hhh");
	}
	{
		auto h = fh2;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(!r);
		r.insert(150, Foo(1500, "hhh"));
		QVERIFY(h.size() == 4);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(bool(r1));
		QVERIFY(r1->second.id == 1500);
		QVERIFY(r1->second.name == "hhh");
	}
	{
		auto h = fm1;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(!r);
		r.insert(150, Foo(1500, "hhh"));
		QVERIFY(h.size() == 4);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1500);
		QVERIFY(r1->name == "hhh");
	}
	{
		auto h = fm2;
		auto r = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(!r);
		r.insert(150, Foo(1500, "hhh"));
		QVERIFY(h.size() == 4);
		auto r1 = Qpe::Map::find_if(h, [] (int key, const Foo&) { return key == 150; });
		QVERIFY(bool(r1));
		QVERIFY(r1->second.id == 1500);
		QVERIFY(r1->second.name == "hhh");
	}
}

void TestAlgorithm::test__map_erase()
{
	{
		auto h = h1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = h2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = m1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = m2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->second == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
}

void TestAlgorithm::test__map_create()
{
	{
		auto h = fh1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, 400);
		QVERIFY(!bool(r));
		r.create(Foo(4000, "---"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, 400);
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 4000);
		QVERIFY(r1->name == "---");
	}
	{
		auto h = fh2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, 400);
		QVERIFY(!bool(r));
		r.create(Foo(4000, "---"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, 400);
		QVERIFY(bool(r1));
		QVERIFY(r1->second.id == 4000);
		QVERIFY(r1->second.name == "---");
	}
	{
		auto h = fh1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, 400);
		QVERIFY(!bool(r));
		r.create(Foo(4000, "---"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, 400);
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 4000);
		QVERIFY(r1->name == "---");
	}
	{
		auto h = fh2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, 400);
		QVERIFY(!bool(r));
		r.create(Foo(4000, "---"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, 400);
		QVERIFY(bool(r1));
		QVERIFY(r1->second.id == 4000);
		QVERIFY(r1->second.name == "---");
	}
}

void TestAlgorithm::test__map_insert_value()
{
	{
		auto h = h1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = h2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 200);
	}
	{
		auto h = m1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = m2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 200);
	}
}

void TestAlgorithm::test__map_insert_key_value()
{
	{
		auto h = h1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert("bbb", 200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = h2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert("bbb", 200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 200);
	}
	{
		auto h = m1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert("bbb", 200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = m2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(!bool(r));
		r.insert("bbb", 200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Map::find(h, QString("bbb"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 200);
	}
}

void TestAlgorithm::test__map_for_each()
{
	{
		auto h = h1;
		int sum = 0;
		Qpe::Map::for_each(h, [&sum] (const QString&, int& i)
		{
			sum += i;
			i += 10;
		});
		QVERIFY(sum == 666);
		auto r1 = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 121);

		auto r2 = Qpe::Map::find(h, QString("nnn"));
		QVERIFY(bool(r2));
		QVERIFY(*r2 == 232);

		auto r3 = Qpe::Map::find(h, QString("zzz"));
		QVERIFY(bool(r3));
		QVERIFY(*r3 == 343);
	}

	{
		auto h = m1;
		int sum = 0;
		Qpe::Map::for_each(h, [&sum] (const QString&, int& i)
		{
			sum += i;
			i += 10;
		});
		QVERIFY(sum == 666);
		auto r1 = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 121);

		auto r2 = Qpe::Map::find(h, QString("nnn"));
		QVERIFY(bool(r2));
		QVERIFY(*r2 == 232);

		auto r3 = Qpe::Map::find(h, QString("zzz"));
		QVERIFY(bool(r3));
		QVERIFY(*r3 == 343);
	}

	{
		auto h = h2;
		int sum = 0;
		Qpe::Map::for_each(h, [&sum] (const QString&, int& i)
		{
			sum += i;
			i += 10;
		});
		QVERIFY(sum == 666);
		auto r1 = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 121);

		auto r2 = Qpe::Map::find(h, QString("nnn"));
		QVERIFY(bool(r2));
		QVERIFY(r2->second == 232);

		auto r3 = Qpe::Map::find(h, QString("zzz"));
		QVERIFY(bool(r3));
		QVERIFY(r3->second == 343);
	}

	{
		auto h = m2;
		int sum = 0;
		Qpe::Map::for_each(h, [&sum] (const QString&, int& i)
		{
			sum += i;
			i += 10;
		});
		QVERIFY(sum == 666);
		auto r1 = Qpe::Map::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->second == 121);

		auto r2 = Qpe::Map::find(h, QString("nnn"));
		QVERIFY(bool(r2));
		QVERIFY(r2->second == 232);

		auto r3 = Qpe::Map::find(h, QString("zzz"));
		QVERIFY(bool(r3));
		QVERIFY(r3->second == 343);
	}
}

void TestAlgorithm::test__map_const_for_each_1()
{
	struct Sum
	{
		void operator()(const QString& k, int i) { sum += i; keys.insert(k); }
		int sum = 0;
		QSet<QString> keys;
	};
	{
		const auto h = h1;
		Sum s = Qpe::Map::for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		const auto h = h2;
		Sum s = Qpe::Map::for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		const auto h = m1;
		Sum s = Qpe::Map::for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		const auto h = m2;
		Sum s = Qpe::Map::for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
}

void TestAlgorithm::test__map_const_for_each_2()
{
	struct Sum
	{
		void operator()(const QString& k, int i) { sum += i; keys.insert(k); }
		int sum = 0;
		QSet<QString> keys;
	};
	{
		auto h = h1;
		Sum s = Qpe::Map::const_for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		auto h = h2;
		Sum s = Qpe::Map::const_for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		auto h = m1;
		Sum s = Qpe::Map::const_for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
	{
		auto h = m2;
		Sum s = Qpe::Map::const_for_each(h, Sum());
		QVERIFY(s.sum == 666);
		QVERIFY(s.keys == QSet<QString>({"aaa", "nnn", "zzz"}));
	}
}

void TestAlgorithm::test__map_contains()
{
	{
		auto h = h1;
		QVERIFY(Qpe::Map::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Map::contains(h, QString("bbb")));
	}
	{
		auto h = h2;
		QVERIFY(Qpe::Map::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Map::contains(h, QString("bbb")));
	}
	{
		auto h = m1;
		QVERIFY(Qpe::Map::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Map::contains(h, QString("bbb")));
	}
	{
		auto h = m2;
		QVERIFY(Qpe::Map::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Map::contains(h, QString("bbb")));
	}

	{
		auto h = fh1;
		QVERIFY(Qpe::Map::contains(h, 100));
		QVERIFY(!Qpe::Map::contains(h, 150));
	}
	{
		auto h = fh2;
		QVERIFY(Qpe::Map::contains(h, 100));
		QVERIFY(!Qpe::Map::contains(h, 150));
	}
	{
		auto h = fm1;
		QVERIFY(Qpe::Map::contains(h, 100));
		QVERIFY(!Qpe::Map::contains(h, 150));
	}
	{
		auto h = fm2;
		QVERIFY(Qpe::Map::contains(h, 100));
		QVERIFY(!Qpe::Map::contains(h, 150));
	}
}

void TestAlgorithm::test__map_contains_if()
{
	{
		auto h = h1;
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "aaa"; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 111; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "bbb"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 200; }));
	}
	{
		auto h = h2;
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "aaa"; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 111; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "bbb"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 200; }));
	}
	{
		auto h = m1;
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "aaa"; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 111; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "bbb"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 200; }));
	}
	{
		auto h = m2;
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "aaa"; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 111; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString& k, int) { return k == "bbb"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (const QString&, int d) { return d == 200; }));
	}

	{
		auto h = fh1;
		QVERIFY(Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 100; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 1000; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "aaa"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 150; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 500; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "bbb"; }));
	}
	{
		auto h = fh2;
		QVERIFY(Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 100; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 1000; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "aaa"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 150; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 500; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "bbb"; }));
	}
	{
		auto h = fm1;
		QVERIFY(Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 100; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 1000; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "aaa"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 150; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 500; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "bbb"; }));
	}
	{
		auto h = fm2;
		QVERIFY(Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 100; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 1000; }));
		QVERIFY(Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "aaa"; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int k, const Foo&) { return k == 150; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.id == 500; }));
		QVERIFY(!Qpe::Map::contains_if(h, [] (int, const Foo& v) { return v.name == "bbb"; }));
	}
}

void TestAlgorithm::test__array_find()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}
	{
		auto h = li3;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls3;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_find_1()
{
	{
		const auto h = li1;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}
	{
		const auto h = li2;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}
	{
		const auto h = li3;
		auto r1 = Qpe::Array::find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::find(h, 200);
		QVERIFY(!r2);
	}

	{
		const auto h = ls1;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		const auto h = ls2;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		const auto h = ls3;
		auto r1 = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		const auto h = lf1;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		const auto h = lf2;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		const auto h = lf3;
		auto r1 = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_find_2()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::const_find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::const_find(h, 200);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::const_find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::const_find(h, 200);
		QVERIFY(!r2);
	}
	{
		auto h = li3;
		auto r1 = Qpe::Array::const_find(h, 111);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 111);

		auto r2 = Qpe::Array::const_find(h, 200);
		QVERIFY(!r2);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::const_find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::const_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::const_find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::const_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls3;
		auto r1 = Qpe::Array::const_find(h, QString("aaa"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "aaa");

		auto r2 = Qpe::Array::const_find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::const_find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::const_find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::const_find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find(h, Foo(555, "aaa"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_find_if()
{
	{
		auto h = lf1;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_find_if_1()
{
	{
		const auto h = lf1;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		const auto h = lf2;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		const auto h = lf3;
		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_find_if_2()
{
	{
		auto h = lf1;
		auto r1 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 1000);
		QVERIFY(r1->name == "aaa");

		auto r2 = Qpe::Array::const_find_if(h, [] (const Foo& f) { return f.id == 555; });
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_erase()
{
	{
		auto h = li1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 111);
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = li2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 111);
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = li3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 111);
		QVERIFY(bool(r));
		QVERIFY(*r == 111);
		r.erase();
		QVERIFY(h.size() == 2);
	}

	{
		auto h = ls1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = ls2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = ls3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("aaa"));
		QVERIFY(bool(r));
		QVERIFY(*r == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(1000, "aaa"));
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 1000; });
		QVERIFY(bool(r));
		QVERIFY(r->id == 1000);
		QVERIFY(r->name == "aaa");
		r.erase();
		QVERIFY(h.size() == 2);
	}
}

void TestAlgorithm::test__array_create()
{
	{
		auto h = li1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.create(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = li2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.create(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = li3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.create(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}

	{
		auto h = ls1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.create("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}
	{
		auto h = ls2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.create("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}
	{
		auto h = ls3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.create("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.create(222, "ggg");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
}

void TestAlgorithm::test__array_insert()
{
	{
		auto h = li1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = li2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}
	{
		auto h = li3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, 200);
		QVERIFY(!bool(r));
		r.insert(200);
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, 200);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 200);
	}

	{
		auto h = ls1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.insert("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}
	{
		auto h = ls2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.insert("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}
	{
		auto h = ls3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(!bool(r));
		r.insert("ccc");
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, QString("ccc"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "ccc");
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find(h, Foo(222, "ggg"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}

	{
		auto h = lf1;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf2;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
	{
		auto h = lf3;
		QVERIFY(h.size() == 3);
		auto r = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(!bool(r));
		r.insert(Foo(222, "ggg"));
		QVERIFY(h.size() == 4);

		auto r1 = Qpe::Array::find_if(h, [] (const Foo& f) { return f.id == 222; });
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 222);
		QVERIFY(r1->name == "ggg");
	}
}

void TestAlgorithm::test__array_contains()
{
	{
		auto h = li1;
		QVERIFY(Qpe::Array::contains(h, 111));
		QVERIFY(!Qpe::Array::contains(h, 100));
	}
	{
		auto h = li2;
		QVERIFY(Qpe::Array::contains(h, 111));
		QVERIFY(!Qpe::Array::contains(h, 100));
	}
	{
		auto h = li3;
		QVERIFY(Qpe::Array::contains(h, 111));
		QVERIFY(!Qpe::Array::contains(h, 100));
	}

	{
		auto h = ls1;
		QVERIFY(Qpe::Array::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Array::contains(h, QString("bbb")));
	}
	{
		auto h = ls2;
		QVERIFY(Qpe::Array::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Array::contains(h, QString("bbb")));
	}
	{
		auto h = ls3;
		QVERIFY(Qpe::Array::contains(h, QString("aaa")));
		QVERIFY(!Qpe::Array::contains(h, QString("bbb")));
	}

	{
		auto h = lf1;
		QVERIFY(Qpe::Array::contains(h, Foo(1000, "aaa")));
		QVERIFY(!Qpe::Array::contains(h, Foo(500, "aaa")));
	}
	{
		auto h = lf2;
		QVERIFY(Qpe::Array::contains(h, Foo(1000, "aaa")));
		QVERIFY(!Qpe::Array::contains(h, Foo(500, "aaa")));
	}
	{
		auto h = lf3;
		QVERIFY(Qpe::Array::contains(h, Foo(1000, "aaa")));
		QVERIFY(!Qpe::Array::contains(h, Foo(500, "aaa")));
	}
}

void TestAlgorithm::test__array_contains_if()
{
	{
		auto h = lf1;
		QVERIFY(Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 1000; }));
		QVERIFY(!Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 100; }));
	}
	{
		auto h = lf2;
		QVERIFY(Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 1000; }));
		QVERIFY(!Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 100; }));
	}
	{
		auto h = lf2;
		QVERIFY(Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 1000; }));
		QVERIFY(!Qpe::Array::contains_if(h, [] (const Foo& f) { return f.id == 100; }));
	}
}

void TestAlgorithm::test__array_ordered_find()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		auto h = li3;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls3;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_ordered_find_compare()
{
	struct Bar { int i = 0; QString s; };
	auto less = [] (const Bar& array_v, const Bar& v) { return array_v.i < v.i; };
	{
		QList<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		QVector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		std::vector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_ordered_find_1()
{
	{
		const auto h = li1;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		const auto h = li2;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		const auto h = li2;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r2);
	}

	{
		const auto h = ls1;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		const auto h = ls2;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		const auto h = ls2;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		const auto h = lf1;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		const auto h = lf2;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		const auto h = lf3;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_ordered_find_compare_1()
{
	struct Bar { int i = 0; QString s; };
	auto less = [] (const Bar& array_v, const Bar& v) { return array_v.i < v.i; };
	{
		const QList<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		const QVector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		const std::vector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_ordered_find_2()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::const_ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::const_ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::const_ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::const_ordered_find(h, 150);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::const_ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);

		auto r2 = Qpe::Array::const_ordered_find(h, 150);
		QVERIFY(!r2);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::const_ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::const_ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::const_ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, QString("bbb"));
		QVERIFY(!r2);
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::const_ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::const_ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::const_ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");

		auto r2 = Qpe::Array::const_ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_const_ordered_find_compare_2()
{
	struct Bar { int i = 0; QString s; };
	auto less = [] (const Bar& array_v, const Bar& v) { return array_v.i < v.i; };
	{
		QList<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::const_ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::const_ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		QVector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::const_ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::const_ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
	{
		std::vector<Bar> h = { Bar{ 1000, "zzz" }, Bar{ 2000, "nnn" }, Bar{ 3000, "aaa" } };
		auto r1 = Qpe::Array::const_ordered_find(h, Bar{ 1000, "" }, less);

		QVERIFY(bool(r1));
		QVERIFY(r1->i == 1000);
		QVERIFY(r1->s == "zzz");

		auto r2 = Qpe::Array::const_ordered_find(h, Bar{ 1500, "nnn" }, less);
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_ordered_find__erase()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ 111, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(!r2);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ 111, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(!r2);
	}
	{
		auto h = li3;
		auto r1 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(bool(r1));
		QVERIFY(*r1 == 222);
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ 111, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 222);
		QVERIFY(!r2);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ "aaa", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ "aaa", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = ls3;
		auto r1 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(bool(r1));
		QVERIFY(*r1 == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ "aaa", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("nnn"));
		QVERIFY(!r2);
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(!r2);
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(bool(r1));
		QVERIFY(r1->id == 2000);
		QVERIFY(r1->name == "nnn");
		r1.erase();
		QVERIFY(h.size() == 2);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2000, "nnn"));
		QVERIFY(!r2);
	}
}

void TestAlgorithm::test__array_ordered_find__create()
{
	{
		auto h = lf1;
		auto r1 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r1);
		r1.create(1500, "nnn");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 1500, "nnn"}, Foo{ 2000, "nnn" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 1500);
		QVERIFY(r2->name == "nnn");
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r1);
		r1.create(1500, "nnn");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 1500, "nnn"}, Foo{ 2000, "nnn" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 1500);
		QVERIFY(r2->name == "nnn");
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(!r1);
		r1.create(1500, "nnn");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 1500, "nnn"}, Foo{ 2000, "nnn" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(1500, "nnn"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 1500);
		QVERIFY(r2->name == "nnn");
	}
}

void TestAlgorithm::test__array_ordered_find__insert()
{
	{
		auto h = li1;
		auto r1 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r1);
		r1.insert(150);
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ 111, 150, 222, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(bool(r2));
		QVERIFY(*r2 == 150);
	}
	{
		auto h = li2;
		auto r1 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r1);
		r1.insert(150);
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ 111, 150, 222, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(bool(r2));
		QVERIFY(*r2 == 150);
	}
	{
		auto h = li3;
		auto r1 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(!r1);
		r1.insert(150);
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ 111, 150, 222, 333 }));

		auto r2 = Qpe::Array::ordered_find(h, 150);
		QVERIFY(bool(r2));
		QVERIFY(*r2 == 150);
	}

	{
		auto h = ls1;
		auto r1 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(!r1);
		r1.insert("kkk");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ "aaa", "kkk", "nnn", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(bool(r2));
		QVERIFY(*r2 == "kkk");
	}
	{
		auto h = ls2;
		auto r1 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(!r1);
		r1.insert("kkk");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ "aaa", "kkk", "nnn", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(bool(r2));
		QVERIFY(*r2 == "kkk");
	}
	{
		auto h = ls3;
		auto r1 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(!r1);
		r1.insert("kkk");
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ "aaa", "kkk", "nnn", "zzz" }));

		auto r2 = Qpe::Array::ordered_find(h, QString("kkk"));
		QVERIFY(bool(r2));
		QVERIFY(*r2 == "kkk");
	}

	{
		auto h = lf1;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(!r1);
		r1.insert(Foo(2500, "kkk"));
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo{ 2500, "kkk" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 2500);
		QVERIFY(r2->name == "kkk");
	}
	{
		auto h = lf2;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(!r1);
		r1.insert(Foo(2500, "kkk"));
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo{ 2500, "kkk" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 2500);
		QVERIFY(r2->name == "kkk");
	}
	{
		auto h = lf3;
		auto r1 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(!r1);
		r1.insert(Foo(2500, "kkk"));
		QVERIFY(h.size() == 4);
		QVERIFY(h == decltype(h)({ Foo{ 1000, "aaa" }, Foo{ 2000, "nnn"}, Foo{ 2500, "kkk" }, Foo { 3000, "zzz" } }));

		auto r2 = Qpe::Array::ordered_find(h, Foo(2500, "kkk"));
		QVERIFY(bool(r2));
		QVERIFY(r2->id == 2500);
		QVERIFY(r2->name == "kkk");
	}
}

QTEST_MAIN(TestAlgorithm)

#include "test_algorithm.moc"

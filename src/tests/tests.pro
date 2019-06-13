TEMPLATE = subdirs

contains(DEFINES, QPE_CORE_MAKE_TESTS) {
	SUBDIRS += test_typetraits
}

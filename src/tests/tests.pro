TEMPLATE = subdirs

contains(DEFINES, QPE_CORE_MAKE_TESTS) {
    SUBDIRS += test_conversion
    SUBDIRS += test_datestringifier
    SUBDIRS += test_numberstringifier
    SUBDIRS += test_numberstringifier2bytearray
    SUBDIRS += test_numberstringifier2string
	SUBDIRS += test_typetraits
}

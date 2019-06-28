TEMPLATE = subdirs

contains(DEFINES, QPE_CORE_MAKE_TESTS) {
    SUBDIRS += test_conversion
    SUBDIRS += test_crontimer
    SUBDIRS += test_datestringifier
    SUBDIRS += test_enum
    SUBDIRS += test_numberstringifier
    SUBDIRS += test_numberstringifier2bytearray
    SUBDIRS += test_numberstringifier2string
	SUBDIRS += test_typetraits
}
contains(DEFINES, QPE_LOGGER_MAKE_TESTS) {
    SUBDIRS += test_logger
}

TEMPLATE = subdirs

SUBDIRS += core
SUBDIRS += logger
SUBDIRS += tests

logger.depends = core
tests.depends = core logger

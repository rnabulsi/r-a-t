TEMPLATE = subdirs

SUBDIRS += \
    common \
    test_common \
    sql

include(config/config.pri)

test_common.depends = common

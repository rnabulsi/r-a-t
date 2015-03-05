TEMPLATE = subdirs

SUBDIRS += \
    common \
    test_common

include(config/config.pri)

test_common.depends = common

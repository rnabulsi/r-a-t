TEMPLATE = subdirs

SUBDIRS += \
    common \
    model \
    sql \
    case \
    test_model \
    test_sql

include(config/config.pri)

test_common.depends = common
test_model.depends = model

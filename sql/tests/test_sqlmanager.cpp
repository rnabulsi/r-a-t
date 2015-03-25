#include "test_sqlmanager.h"
#include <sqlmanager.h>
#include <emptyprogress.h>

void TestSqlManager::initTestCase() {}

void TestSqlManager::cleanupTestCase() { SqlManager::shutdown(); }

void TestSqlManager::testStart() {
    ATMProgress *progress = new EmptyProgress;
    QVERIFY(SqlManager::instance().start(progress));
    delete progress;
}

void TestSqlManager::testCategoryName() {
    QVERIFY2(SqlManager::instance().categoryName(1l) == "Pref-0", "Category with id 1 should be 'Pref-0'.");
    QVERIFY2(SqlManager::instance().categoryName(10l) == "IVPref-hm-yu",
             "Category with id 10 should be 'IVPref-hm-yu'.");
    QVERIFY2(SqlManager::instance().categoryName(100l) == "IVSuff-ny-nA",
             "Category with id 100 should be 'IVSuff-ny-nA'.");
    QVERIFY2(SqlManager::instance().categoryName(200l) == "PV_C_intr", "Category with id 200 should be 'PV_C_intr'.");
    QVERIFY2(SqlManager::instance().categoryName(400l) == "IVSuff-|k", "Category with id 400 should be 'IVSuff-|k'.");
    QVERIFY2(SqlManager::instance().categoryName(-1l) == QString::null, "Category with id -1 should not exist.");
}

void TestSqlManager::testSourceIds() {
    QVector<int> source_ids;
    QVERIFY2(SqlManager::instance().loadSourceIds(source_ids), "Loading source ids has failed.");
    QVERIFY2(source_ids.size() == 11, "There should be 11 sources.");
}

void TestSqlManager::testAbstractCategoryIds() {
    QVector<int> abstract_category_ids;
    QVERIFY2(SqlManager::instance().loadAbstractCategoryIds(abstract_category_ids),
             "Loading abstract category ids has failed.");
    QVERIFY2(abstract_category_ids.size() == 149, "There should be 149 abstract categories.");
}

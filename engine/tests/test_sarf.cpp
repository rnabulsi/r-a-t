#include "test_sarf.h"
#include <sarf.h>
#include <sqlmanager.h>

void TestSarf::cleanupTestCase() {
    SqlManager::shutdown();
}

void TestSarf::testStart() {
    Sarf *sarf = new Sarf();
    QString output_string;
    QString errors_string;

    QVERIFY2(sarf->start(&output_string, &errors_string),
             "Starting sarf engine with strings should not fail.");
    QVERIFY2(
        output_string.contains("Engine started."),
        "After start of the sarf engine with strings, the output string should "
        "contain \"Engine started\" message.");
    QVERIFY2(errors_string.isEmpty(), "After successful start of the  sarf engine "
                                   "with strings, the error string should be "
                                   "empty.");

    delete sarf;
}

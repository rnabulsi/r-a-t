#include <QtTest>
#include <QtDebug>

#include <test_sqlmanager.h>

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    qWarning("SQL TESTS DEPEND ON DATABASE DATA. IN CASE OF FAILURE CHECK BOTH THE CODE AND THE DATA.");
    int result = 0;
    TestSqlManager *testSqlManager = new TestSqlManager;
    result |= QTest::qExec(testSqlManager, argc, argv);
    delete testSqlManager;
    qWarning("SQL TESTS DEPEND ON DATABASE DATA. IN CASE OF FAILURE CHECK BOTH THE CODE AND THE DATA.");
    return result;
}

#include <QtTest>

#include <test_sqlmanager.h>

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    int result = 0;
    TestSqlManager *testSqlManager = new TestSqlManager;
    result |= QTest::qExec(testSqlManager, argc, argv);
    delete testSqlManager;

    return result;
}

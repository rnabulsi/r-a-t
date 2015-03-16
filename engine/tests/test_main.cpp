#include <QtTest>
#include <QtDebug>

#include "test_sarf.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    qWarning("ENGINE TESTS DEPEND ON DATABASE DATA. IN CASE OF FAILURE CHECK BOTH THE CODE AND THE DATA.");
    int result = 0;
    QSharedPointer<TestSarf> testSarf = QSharedPointer<TestSarf>::create();
    result |= QTest::qExec(testSarf.data(), argc, argv);
    qWarning("ENGINE TESTS DEPEND ON DATABASE DATA. IN CASE OF FAILURE CHECK BOTH THE CODE AND THE DATA.");
    return result;
}

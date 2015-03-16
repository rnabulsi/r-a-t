#include <QtTest>
#include <QtDebug>

#include "test_letters.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    int result = 0;
    TestLetters testLetters;
    result |= QTest::qExec(&testLetters, argc, argv);
    return result;
}


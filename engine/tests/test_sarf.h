#ifndef TESTSARF_H
#define TESTSARF_H

#include <QtTest>

class TestSarf : public QObject {
    Q_OBJECT
public:
    TestSarf() : QObject() {}
    virtual ~TestSarf() {}

private slots:
    void cleanupTestCase();
    virtual void testStart();
};

#endif // TESTSARF_H

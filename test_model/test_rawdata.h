#ifndef TESTRAWDATA_H
#define TESTRAWDATA_H

#include <QtTest>

class TestRawData : public QObject {
    Q_OBJECT
public:
    TestRawData() : QObject() {}
    virtual ~TestRawData() {}

private slots:
    virtual void testConstruction();
    virtual void testEqualsOperator();
    virtual void testActual();
};

#endif // TESTRAWDATA_H

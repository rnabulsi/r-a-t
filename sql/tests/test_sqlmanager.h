#ifndef TESTSQLMANAGER_H
#define TESTSQLMANAGER_H

#include <QtTest>

class TestSqlManager : public QObject {
    Q_OBJECT
public:
    explicit TestSqlManager() : QObject() {}
    virtual ~TestSqlManager() {}

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testStart();
    void testCategoryName();
    void testSourceIds();
    void testAbstractCategoryIds();
};

#endif // TESTSQLMANAGER_H

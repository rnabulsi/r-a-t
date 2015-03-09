#ifndef TESTRESULTNODE_H
#define TESTRESULTNODE_H

#include <QtTest>
#include <QObject>

class TestResultNode : public QObject {
    Q_OBJECT
public:
    TestResultNode() : QObject() {
        qWarning("THIS TEST DEPENDS ON DATABASE DATA. IN CASE OF FAILURE CHECK "
                 "BOTH THE CODE AND THE DATA.");
    }
    virtual ~TestResultNode() {
        qWarning("THIS TEST DEPENDS ON DATABASE DATA. IN CASE OF FAILURE CHECK "
                 "BOTH THE CODE AND THE DATA.");
    }

private:
    virtual void testConstruction() = 0;
    virtual void testCopy() = 0;
    virtual void testAssignment() = 0;

private slots:
    void cleanUpTestCase();
    virtual void testToString();
    virtual void testPreviousResultNode();
};

#endif // TESTRESULTNODE_H

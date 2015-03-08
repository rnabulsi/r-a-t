#ifndef TEST_NODE_H
#define TEST_NODE_H

#include <QtTest>

class TestNode : public QObject {
    Q_OBJECT
public:
    TestNode() : QObject() {}
    virtual ~TestNode() {}

private:
    virtual void testConstruction() = 0;
    virtual void testHasChildren() = 0;
    virtual void testAddRawChild() = 0;
    virtual void testAddSharedPointerChild() = 0;
    virtual void testRemoveChildren() = 0;

private slots:
    virtual void testCopy();
    virtual void testAssignment();
    virtual void testToString();
    virtual void testLetterChild();
    virtual void testLetterChildren();
    virtual void testResultChildren();
};

#endif // TEST_NODE_H

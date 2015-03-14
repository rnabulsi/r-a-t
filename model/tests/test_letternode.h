#ifndef TEST_LETTERNODE_H
#define TEST_LETTERNODE_H

#include <QtTest>

class TestLetterNode : public QObject
{
    Q_OBJECT
public:
    TestLetterNode() : QObject() {}
    virtual ~TestLetterNode() {}

private slots:
    virtual void testConstruction();
    virtual void testCopy();
    virtual void testAssignent();
    virtual void testToString();
    virtual void testSetLetter();
    virtual void testOperators();
};

#endif // TEST_LETTERNODE_H

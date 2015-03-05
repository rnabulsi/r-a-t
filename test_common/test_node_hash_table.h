#ifdef HASH_TABLE
#ifndef TEST_NODE_HASH_TABLE_H
#define TEST_NODE_HASH_TABLE_H

#include <test_node.h>

class TestNodeHashTable : public TestNode {
    Q_OBJECT
public:
    TestNodeHashTable() {}
    virtual ~TestNodeHashTable() {}

private slots:
    virtual void testConstruction() override;
    virtual void testHasChildren() override;
    virtual void testAddRawChild() override;
    virtual void testAddSharedPointerChild() override;
    virtual void testRemoveChildren() override;
};

#endif // TEST_NODE_HASH_TABLE_H
#else // HASH_TABLE
#include <QObject>
// We are declaring dummy class here to keep moc quiet.
class TestNodeHashTable : public QObject { Q_OBJECT };
#endif // HASH_TABLE

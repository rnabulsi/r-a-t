#ifdef EXTENSIVE_TREE
#ifndef TEST_NODE_EXTENSIVE_TREE_H
#define TEST_NODE_EXTENSIVE_TREE_H

#include <test_node.h>

class TestNodeExtensiveTree : public TestNode {
    Q_OBJECT
public:
    TestNodeExtensiveTree() {}
    virtual ~TestNodeExtensiveTree() {}

private slots:
    virtual void testConstruction() override;
    virtual void testHasChildren() override;
    virtual void testAddRawChild() override;
    virtual void testAddSharedPointerChild() override;
    virtual void testRemoveChildren() override;
};

#endif // TEST_NODE_EXTENSIVE_TREE_H
#else // EXTENSIVE_TREE
#include <QObject>
// We are declaring dummy class here to keep moc quiet.
class TestNodeExtensiveTree : public QObject { Q_OBJECT };
#endif // EXTENSIVE_TREE

#ifdef BINARY_SEARCH
#ifndef TEST_NODE_BINARY_SEARCH_H
#define TEST_NODE_BINARY_SEARCH_H

#include <test_node.h>

class TestNodeBinarySearch : public TestNode {
    Q_OBJECT
public:
    TestNodeBinarySearch() : TestNode() {}
    virtual ~TestNodeBinarySearch() {}

private slots:
    virtual void testConstruction() override;
    virtual void testHasChildren() override;
    virtual void testAddRawChild() override;
    virtual void testAddSharedPointerChild() override;
    virtual void testRemoveChildren() override;
};

#endif // TEST_NODE_BINARY_SEARCH_H
#else // BINARY_SEARCH
#include <QObject>
// We are declaring dummy class here to keep moc quiet.
class TestNodeBinarySearch : public QObject { Q_OBJECT };
#endif // BINARY_SEARCH

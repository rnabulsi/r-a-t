#ifdef HASH_TABLE
#include <test_node_hash_table.h>
#include <node.h>
#include <letternode.h>
#include <resultnode.h>

void TestNodeHashTable::testConstruction() {
    Node *parentlessNode = new Node();
    QVERIFY2(parentlessNode->parent() == nullptr,
             "This node should not have a parent.");
    QVERIFY2(!parentlessNode->hasChildren(),
             "This node should not have children.");
    Node *childNode = new Node(parentlessNode);
    QVERIFY2(dynamic_cast<Node *>(childNode->parent()) == parentlessNode,
             "Parent of the node differs from expected.");
    delete childNode;
    delete parentlessNode;
}

void TestNodeHashTable::testHasChildren() {
    Node *parent = new Node();
    QVERIFY2(!parent->hasChildren(),
             "After construction node should not have any children.");

    Node *child = new LetterNode();
    parent->addChild(child);
    QVERIFY2(
        parent->hasChildren(),
        "After adding a child letter node, the node should have children.");
    delete parent;

    parent = new Node();
    child = new ResultNode();
    parent->addChild(child);
    QVERIFY2(
        parent->hasChildren(),
        "After adding a child result node, the node should have children.");
    delete parent;

    parent = new Node();
    child = new Node();
    parent->addChild(child);
    QVERIFY2(!parent->hasChildren(), "After adding a plain child node, the "
                                     "node should not have children, as plain "
                                     "nodes cannot be added as children.");
    delete child;
    delete parent;
}

void TestNodeHashTable::testAddRawChild() {
    Node *root = new LetterNode();
    int resultChildrenSize = root->resultChildren().size();
    int letterChildrenSize = root->letterChildren().size();
    QVERIFY2(!root->hasChildren(),
             "After construction node should not have any children.");

    Node *child = new LetterNode();
    root->addChild(child);
    QVERIFY2(child->parent() == root, "After adding a letter node child, the "
                                      "childs parent should be set to a node "
                                      "to which it has been added.");
    QVERIFY2(root->resultChildren().size() == resultChildrenSize,
             "After adding a letter child node the number of result children "
             "should remain unchanged.");
    QVERIFY2(root->letterChildren().size() == letterChildrenSize + 1,
             "After adding a letter child node the number of letter children "
             "should increase by one.");
    letterChildrenSize = root->letterChildren().size();

    root->addChild(child);
    QVERIFY2(root->letterChildren().size() == letterChildrenSize,
             "After adding the same letter child twice the number of letter "
             "children should not increase.");
    QVERIFY2(root->resultChildren().size() == resultChildrenSize,
             "After adding the same letter child twice the number of result "
             "children should remain unchanged.");

    child = new ResultNode();
    root->addChild(child);
    QVERIFY2(child->parent() == root, "After adding a result node child, the "
                                      "childs parent should be set to a node "
                                      "to which it has been added.");
    QVERIFY2(root->resultChildren().size() == resultChildrenSize + 1,
             "After adding a result child node the number of result children "
             "should increase by one.");
    resultChildrenSize = root->resultChildren().size();

    child = new Node();
    Node *childParent = child->parent();
    root->addChild(child);
    QVERIFY2(child->parent() == childParent,
             "After atempt to add a plain child node, the childs node parent "
             "should remain the same, as plain nodes cannot be added as "
             "children.");
    QVERIFY2(root->letterChildren().size() == letterChildrenSize,
             "After atempt to add a plain child, the number of letter children "
             "should remain unchanged, as plain nodes cannot be added as "
             "children.");
    QVERIFY2(root->resultChildren().size() == resultChildrenSize,
             "After atempt to add a plain child, the number of result children "
             "should remain unchanged, as plain nodes cannot be added as "
             "children.");
    delete child;
    delete root;
}

void TestNodeHashTable::testAddSharedPointerChild() {
    QSharedPointer<Node> parent = QSharedPointer<Node>::create();
    int letterChildrenSize = parent->letterChildren().size();
    int resultChildrenSize = parent->resultChildren().size();

    QVERIFY2(!parent->hasChildren(),
             "After construction node should not have any children.");
    QSharedPointer<Node> child = QSharedPointer<LetterNode>::create();
    parent->addChild(child);
    QVERIFY2(child->parent() == parent, "After adding a letter node child, the "
                                        "childs parent should be set to a node "
                                        "to which it has been added.");

    QVERIFY2(parent->letterChildren().size() == letterChildrenSize + 1,
             "After adding a letter child node the number of letter children "
             "should increase by one.");
    QVERIFY2(parent->resultChildren().size() == resultChildrenSize,
             "After adding a letter child node the number of result children "
             "should remain unchanged.");
    letterChildrenSize = parent->letterChildren().size();

    parent->addChild(child);
    QVERIFY2(parent->letterChildren().size() == letterChildrenSize,
             "After adding the same letter child twice the number of letter "
             "children should not increase.");
    QVERIFY2(parent->resultChildren().size() == resultChildrenSize,
             "After adding the same letter child twice the number of result "
             "children should remain unchanged.");

    child = QSharedPointer<ResultNode>::create();
    parent->addChild(child);
    QVERIFY2(child->parent() == parent, "After adding a result node child, the "
                                        "childs parent should be set to a node "
                                        "to which it has been added.");
    QVERIFY2(parent->resultChildren().size() == resultChildrenSize + 1,
             "After adding a result child node the number of result children "
             "should increase by one.");
    resultChildrenSize = parent->resultChildren().size();
    QVERIFY2(parent->letterChildren().size() == letterChildrenSize,
             "After adding a letter child node the number of result children "
             "should remain unchanged.");

    child = QSharedPointer<Node>::create();
    Node *childParent = child->parent();
    parent->addChild(child);
    QVERIFY2(child->parent() == childParent,
             "After atempt to add a plain child node, the childs node parent "
             "should remain the same, as plain nodes cannot be added as "
             "children.");
    QVERIFY2(parent->letterChildren().size() == letterChildrenSize,
             "After atempt to add a plain child, the number of letter children "
             "should remain unchanged, as plain nodes cannot be added as "
             "children.");
    QVERIFY2(parent->resultChildren().size() == resultChildrenSize,
             "After atempt to add a plain child, the number of result children "
             "should remain unchanged, as plain nodes cannot be added as "
             "children.");
}


void TestNodeHashTable::testRemoveChildren() {
    Node *parent = new Node();
    parent->addChild(new LetterNode('A'));
    parent->addChild(new ResultNode());
    parent->removeChildren();
    QVERIFY2(!parent->hasChildren(), "After removing children from the node, "
                                     "that node should not have any children.");
    delete parent;
}

#endif // HASH_TABLE

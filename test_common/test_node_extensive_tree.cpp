#ifdef EXTENSIVE_TREE
#include <test_node_extensive_tree.h>
#include <node.h>
#include <letternode.h>
#include <resultnode.h>

#if defined(EXTENSIVE_TREE)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif

void TestNodeExtensiveTree::testConstruction() {
    Node *parentlessNode = new Node();
    QVERIFY2(parentlessNode->parent() == nullptr,
             "This node should not have a parent.");

    QVERIFY2(parentlessNode->letterChildren().size() ==
                 Node::LETTER_CHILDREN_COUNT,
             "When using extensive tree for storing letter children, all newly "
             "created nodes must have exectly " STR(
                 Node::LETTER_CHILDREN_COUNT) " children. They may be \ref "
                                              "nullptr but they must exist.");
    Node *childNode = new Node(parentlessNode);
    QVERIFY2(dynamic_cast<Node *>(childNode->parent()) == parentlessNode,
             "Parent of the node differs from expected.");
    delete childNode;
    delete parentlessNode;
}

void TestNodeExtensiveTree::testHasChildren() {
    Node *parent = new Node();
    QVERIFY2(parent->hasChildren(),
             "When using extensive tree for storing letter children, all newly "
             "created nodes always have children as there is always " STR(
                 Node::LETTER_CHILDREN_COUNT) " letter children present. Some "
                                              "may be nullptr but they exist.");
    Node *child = new LetterNode();
    parent->addChild(child);
    QVERIFY2(
        parent->hasChildren(),
        "When using extensive tree for storing letter children, and add "
        "one letter node child, the parent node should always have "
        "children as there is always " STR(
            Node::LETTER_CHILDREN_COUNT) " letter children present. Some of "
                                         "them may be nullptr but they must "
                                         "exist.");
    delete parent;

    parent = new Node();
    child = new ResultNode();
    parent->addChild(child);
    QVERIFY2(
        parent->hasChildren(),
        "When using extensive tree for storing letter children, and add "
        "one result node child, the parent node should always have "
        "children as there is always " STR(
            Node::LETTER_CHILDREN_COUNT) " letter children present. Some of "
                                         "them may be nullptr but they must "
                                         "exist.");
    delete parent;

    parent = new Node();
    child = new Node();
    parent->addChild(child);
    QVERIFY2(
        parent->hasChildren(),
        "When using extensive tree for storing letter children, after "
        "adding a plain child node, the parent node should always have "
        "children, regardless of the fact that plain nodes are ignored for "
        "adding, as there is always " STR(
            Node::LETTER_CHILDREN_COUNT) " letter children.");
    delete child;
    delete parent;
}

void TestNodeExtensiveTree::testAddRawChild() {
    Node *root = new LetterNode();
    int resultChildrenSize = root->resultChildren().size();

    Node *child = new LetterNode();
    root->addChild(child);
    QVERIFY2(child->parent() == root, "After adding a letter node child, the "
                                      "childs parent should be set to a node "
                                      "to which it has been added.");
    QVERIFY2(root->resultChildren().size() == resultChildrenSize,
             "After adding a letter child node the number of result children "
             "should remain unchanged.");

    QVERIFY2(root->letterChildren().size() == Node::LETTER_CHILDREN_COUNT,
             "When using extensive tree for storing letter children, after "
             "adding a letter child node the number of letter children must "
             "remain " STR(Node::LETTER_CHILDREN_COUNT) ".");

    root->addChild(child);
    QVERIFY2(root->letterChildren().size() == Node::LETTER_CHILDREN_COUNT,
             "When using extensive tree for storing letter children, after "
             "adding the same letter child node twice the, number of letter "
             "children must remain " STR(Node::LETTER_CHILDREN_COUNT) ".");

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
    QVERIFY2(root->resultChildren().size() == resultChildrenSize,
             "After atempt to add a plain child, the number of result children "
             "should remain unchanged, as plain nodes cannot be added as "
             "children.");
    delete root;
}

void TestNodeExtensiveTree::testAddSharedPointerChild() {
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

void TestNodeExtensiveTree::testRemoveChildren() {
    Node *parent = new Node();
    parent->addChild(new LetterNode('A'));
    parent->addChild(new ResultNode());
    parent->removeChildren();
    QVERIFY2(!parent->hasChildren(), "After removing children from the node, "
                                     "that node should not have any children.");
    delete parent;
}
#endif // EXTENSIVE_TREE

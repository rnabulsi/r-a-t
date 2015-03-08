#include <test_node.h>
#include <node.h>
#include <letternode.h>
#include <resultnode.h>

void TestNode::testCopy() {
    QSharedPointer<Node> parent = QSharedPointer<Node>::create();
    LetterNode *child = new LetterNode(parent.data());
    ResultNode *anotherChild = new ResultNode(parent.data());
    parent->addChild(child);
    parent->addChild(anotherChild);
    Node parentCopy(*parent);
    QVERIFY2(parentCopy.hasChildren(),
             "During the copy the children should be copyed too.");
    QVERIFY2(parentCopy.letterChildren().size() ==
                 parent->letterChildren().size(),
             "The copy should not have different number of letter children.");
    QVERIFY2(parentCopy.letterChildren().at(0) ==
                 parent->letterChildren().at(0),
             "The copied letter children should be the same.");
    QVERIFY2(parentCopy.resultChildren().size() ==
                 parent->resultChildren().size(),
             "The copy should not have different number of result children.");
    QVERIFY2(parentCopy.resultChildren().at(0) ==
                 parent->resultChildren().at(0),
             "The copied result children should be the same.");
}

void TestNode::testAssignment() {
    Node *parent = new Node();
    LetterNode *child = new LetterNode(parent);
    ResultNode *anotherChild = new ResultNode(parent);
    parent->addChild(child);
    parent->addChild(anotherChild);
    Node childCopy;
    childCopy = *child;
    QVERIFY2(childCopy.parent() == parent,
             "After node assignment the parent should be the same.");
    QVERIFY2(childCopy.parent() == child->parent(),
             "After node assignment the parent should be the same.");
    Node parentCopy;
    parentCopy = *parent;
    QVERIFY2(parentCopy.hasChildren(),
             "During the assignment the children should be copyed.");
    QVERIFY2(parentCopy.letterChildren().size() ==
                 parent->letterChildren().size(),
             "The copy should not have different number of letter children.");
    QVERIFY2(parentCopy.letterChildren().at(0) ==
                 parent->letterChildren().at(0),
             "The copied letter children should be the same.");
    QVERIFY2(parentCopy.resultChildren().size() ==
                 parent->resultChildren().size(),
             "The copy should not have different number of result children.");
    QVERIFY2(parentCopy.resultChildren().at(0) ==
                 parent->resultChildren().at(0),
             "The copied result children should be the same.");
    delete parent;
}

void TestNode::testToString() {
    Node *parent = new Node();
    // Node::toString() should always return empty string.
    QCOMPARE(parent->toString(), QString());
    Node *child = new LetterNode(parent);
    parent->addChild(child);
    // Node::toString() should always return empty string.
    QCOMPARE(parent->toString(), QString());
    child = new ResultNode();
    parent->addChild(child);
    // Node::toString() should always return empty string.
    QCOMPARE(parent->toString(), QString());
    delete parent;
}

void TestNode::testLetterChild() {
    Node *parent = new Node();
    parent->addChild(new LetterNode('D'));
    parent->addChild(new LetterNode('F'));
    parent->addChild(new LetterNode('H'));
    parent->addChild(new LetterNode('J'));
    parent->addChild(new LetterNode('L'));
    parent->addChild(new LetterNode('N'));

    auto child = parent->letterChild('G');
    QVERIFY2(child.isNull(), "The letter node 'G' should not be found.");
    child = parent->letterChild('B');
    QVERIFY2(child.isNull(), "The letter node 'B' should not be found.");
    child = parent->letterChild('X');
    QVERIFY2(child.isNull(), "The letter node 'X' should not be found.");
    child = parent->letterChild('D');
    QVERIFY2(!child.isNull(), "The letter node 'D' should be found.");
    QVERIFY2(child->letter() == 'D',
             "The returned letter node should contain letter 'D'.");
    child = parent->letterChild('N');
    QVERIFY2(!child.isNull(), "The letter node 'N' should be found.");
    QVERIFY2(child->letter() == 'N',
             "The returned letter node should contain letter 'N'.");
    child = parent->letterChild('J');
    QVERIFY2(!child.isNull(), "The letter node 'J' should be found.");
    QVERIFY2(child->letter() == 'J',
             "The returned letter node should contain letter 'J'.");

    delete parent;
}

void TestNode::testLetterChildren() {
    Node *parent = new Node();
    QSharedPointer<LetterNode> nodeA = QSharedPointer<LetterNode>::create('A');
    QSharedPointer<LetterNode> nodeB = QSharedPointer<LetterNode>::create('B');
    QSharedPointer<LetterNode> nodeC = QSharedPointer<LetterNode>::create('C');
    parent->addChild(nodeA);
    parent->addChild(nodeB);
    parent->addChild(nodeC);
    bool hasA = false;
    bool hasB = false;
    bool hasC = false;
    for (auto child : parent->letterChildren()) {
        if (child == nodeA) {
            hasA = true;
            continue;
        }
        if (child == nodeB) {
            hasB = true;
            continue;
        }
        if (child == nodeC) {
            hasC = true;
        }
    }
    QVERIFY2(hasA && hasB && hasC, "After adding letter nodes to a node, the "
                                   "returned vector of letter children should "
                                   "contain all of them.");
    delete parent;
}

void TestNode::testResultChildren() {
    Node *parent = new Node();
    QSharedPointer<ResultNode> nodeA = QSharedPointer<ResultNode>::create();
    QSharedPointer<ResultNode> nodeB = QSharedPointer<ResultNode>::create();
    QSharedPointer<ResultNode> nodeC = QSharedPointer<ResultNode>::create();
    parent->addChild(nodeA);
    parent->addChild(nodeB);
    parent->addChild(nodeC);
    bool hasA = false;
    bool hasB = false;
    bool hasC = false;
    for (auto child : parent->resultChildren()) {
        if (child == nodeA) {
            hasA = true;
            continue;
        }
        if (child == nodeB) {
            hasB = true;
            continue;
        }
        if (child == nodeC) {
            hasC = true;
        }
    }
    QVERIFY2(hasA && hasB && hasC, "After adding result nodes to a node, the "
                                   "returned list of result children should "
                                   "contain all of them.");
    delete parent;
}

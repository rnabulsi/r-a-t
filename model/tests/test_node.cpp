#include "test_node.h"
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
    // Six letters ب ج د ر ش ط
    // Preceeding letter ظ
    // Succeeding letter ض
    // Letter that fits in the 'hole' ث
    Node *parent = new Node();
    parent->addChild(new LetterNode(QString("ب").at(0))); //D
    parent->addChild(new LetterNode(QString("ج").at(0))); //F
    parent->addChild(new LetterNode(QString("د").at(0))); //H
    parent->addChild(new LetterNode(QString("ر").at(0))); //J
    parent->addChild(new LetterNode(QString("ش").at(0))); //L
    parent->addChild(new LetterNode(QString("ط").at(0))); //N

    auto child = parent->letterChild(QString("ث").at(0));
    QVERIFY2(child.isNull(), "The letter node 'ث' should not be found.");
    child = parent->letterChild(QString("ظ").at(0));
    QVERIFY2(child.isNull(), "The letter node 'ظ' should not be found.");
    child = parent->letterChild(QString("ض").at(0));
    QVERIFY2(child.isNull(), "The letter node 'ض' should not be found.");
    child = parent->letterChild(QString("ب").at(0));
    QVERIFY2(!child.isNull(), "The letter node 'ب' should be found.");
    QVERIFY2(child->letter() == QString("ب").at(0),
             "The returned letter node should contain letter 'ب'.");
    child = parent->letterChild(QString("ط").at(0));
    QVERIFY2(!child.isNull(), "The letter node 'ط' should be found.");
    QVERIFY2(child->letter() == QString("ط").at(0),
             "The returned letter node should contain letter 'ط'.");
    child = parent->letterChild(QString("ر").at(0));
    QVERIFY2(!child.isNull(), "The letter node 'ر' should be found.");
    QVERIFY2(child->letter() == QString("ر").at(0),
             "The returned letter node should contain letter 'ر'.");

    delete parent;
}

void TestNode::testLetterChildren() {
    Node *parent = new Node();
    QSharedPointer<LetterNode> nodeA = QSharedPointer<LetterNode>::create(QString("ا").at(0));
    QSharedPointer<LetterNode> nodeB = QSharedPointer<LetterNode>::create(QString("ب").at(0));
    QSharedPointer<LetterNode> nodeC = QSharedPointer<LetterNode>::create(QString("ج").at(0));
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

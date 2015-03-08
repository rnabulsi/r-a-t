#include <test_letternode.h>
#include <letternode.h>
#include <resultnode.h>
#include <QChar>

void TestLetterNode::testConstruction() {
    LetterNode *parentlessNode = new LetterNode();
    QVERIFY2(parentlessNode->parent() == nullptr,
             "This node should not have a parent.");
    QVERIFY2(!parentlessNode->hasChildren(),
             "This node should not have children.");
    QVERIFY2(parentlessNode->letter() == QChar('\0'),
             "When constructed without a letter the letter node should contain "
             "value '\0'");
    LetterNode *childNode = new LetterNode(parentlessNode);
    QVERIFY2(dynamic_cast<LetterNode *>(childNode->parent()) == parentlessNode,
             "Parent of the node differs from expected.");
    delete childNode;
    delete parentlessNode;

    QChar letter('T');
    parentlessNode = new LetterNode(letter);
    QVERIFY2(parentlessNode->parent() == nullptr,
             "When letter node is constructed with letter then it should "
             "not have parent set.");
    QVERIFY2(parentlessNode->letter() == letter,
             "When letter node is constructed with letter then it should have "
             "that letter set.");
    delete parentlessNode;
}

void TestLetterNode::testCopy() {
    QSharedPointer<LetterNode> parent =
        QSharedPointer<LetterNode>::create(QChar('T'));
    LetterNode *child = new LetterNode(parent.data());
    ResultNode *anotherChild = new ResultNode(parent.data());
    parent->addChild(child);
    parent->addChild(anotherChild);
    LetterNode parentCopy(*parent);
    QVERIFY2(parentCopy.letter() == QChar('T'),
             "During the copy the letter should be copyied too.");
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

void TestLetterNode::testAssignent() {
    LetterNode *parent = new LetterNode(QChar('T'));
    LetterNode *child = new LetterNode(parent);
    ResultNode *anotherChild = new ResultNode(parent);
    parent->addChild(child);
    parent->addChild(anotherChild);
    LetterNode childCopy;
    childCopy = *child;
    QVERIFY2(childCopy.parent() == parent,
             "After node assignment the parent should be the same.");
    QVERIFY2(childCopy.parent() == child->parent(),
             "After node assignment the parent should be the same.");
    LetterNode parentCopy;
    parentCopy = *parent;
    QVERIFY2(parentCopy.letter() == parent->letter(),
             "During letter node assignment the letter itself should be "
             "assigned to.");
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

void TestLetterNode::testToString() {
    QSharedPointer<LetterNode> node = QSharedPointer<LetterNode>::create();
    QString emptyNodeToString("--->($)");
    QString nonEmptyNodeToString("--->(T)");

    QVERIFY2(node->toString() == emptyNodeToString,
             "Empty letter node string representation should be '--->($)'");
    node->setLetter('T');
    QVERIFY2(node->toString() == nonEmptyNodeToString,
             "When letter is set in letter node the string representation "
             "should have that letter between parenthesis.");
}

void TestLetterNode::testSetLetter() {
    QSharedPointer<LetterNode> node = QSharedPointer<LetterNode>::create();
    node->setLetter('T');
    QVERIFY2(node->letter() == QChar('T'), "After setting a letter to a letter "
                                           "node, it should have a letter "
                                           "value that has been set.");
}

void TestLetterNode::testOperators() {
    LetterNode aNode('A');
    LetterNode a1Node('A');
    LetterNode bNode('B');
    LetterNode b1Node('B');
    LetterNode cNode('C');

    // Testing operator ==
    QVERIFY2(aNode == a1Node,
             "Letter nodes should be equal when their letters are equal.");
    QVERIFY2(
        !(aNode == bNode),
        "When letters are not equal the letter nodes should not be equal.");
    // Testing operator !=
    QVERIFY2(
        aNode != cNode,
        "Letter nodes should not be equal when their letters are not equal.");
    QVERIFY2(!(aNode != a1Node),
             "When letters are equal the letter nodes should not be unequal.");
    // Testing opereator <
    QVERIFY2(aNode < bNode, "When one letter is 'less' than other, its letter "
                            "node should be less than other node too.");
    // Testing operator >
    QVERIFY2(cNode > aNode, "When one letter is 'greater' than other, its "
                            "letter node should be greater then other node "
                            "too.");
    // Testing operator <=
    QVERIFY2(aNode <= bNode, "When one letter is 'less or equal' to other, its "
                             "letter node should be less or equal to other "
                             "node.");
    QVERIFY2(bNode <= b1Node,
             "When one letter is 'less or equal' to other, its "
             "letter node should be less or equal to other "
             "node.");
    // Testing operator >=
    QVERIFY2(cNode >= bNode,
             "When one letter is 'greater or equal' to other, its "
             "letter node should be greater or equal to other "
             "node.");
    QVERIFY2(aNode >= a1Node,
             "When one letter is 'less or equal' to other, its "
             "letter node should be less or equal to other "
             "node.");
    // Testing operator consistency
    QVERIFY2((aNode == a1Node) && !(aNode != a1Node),
             "If letter nodes are equal, they cannot be unequal at the same "
             "time and vice versa.");
    QVERIFY2((bNode != cNode) && !(bNode == cNode),
             "If letter nodes are unequal, they cannot be equal at the same "
             "time and vice versa.");
    QVERIFY2(
        (bNode > aNode) && !(bNode <= aNode),
        "If letter node is greater than another, than it should not be less "
        "or equal at the same time and vice versa.");
    QVERIFY2(
        (bNode < cNode) && !(bNode >= cNode),
        "If letter node is lesser than another, than it should not be greater "
        "or equal at the same time and vice versa.");
    QVERIFY2((aNode <= bNode) && !(aNode > bNode),
             "If letter node is lesser or equal to another, then it should not "
             "be greater at the same time and vice versa");
    QVERIFY2((aNode <= a1Node) && !(aNode > a1Node),
             "If letter node is lesser or equal to another, then it should not "
             "be greater at the same time and vice versa");
    QVERIFY2((cNode >= bNode) && !(cNode < bNode),
             "If letter node is greater or equal to another, then it should not "
             "be lesser at the same time and vice versa");
    QVERIFY2((bNode <= b1Node) && !(bNode > b1Node),
             "If letter node is greater or equal to another, then it should not "
             "be lesser at the same time and vice versa");
}

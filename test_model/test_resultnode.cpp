#include "test_resultnode.h"
#include <sqlmanager.h>
#include <resultnode.h>
#include <letternode.h>

void TestResultNode::cleanUpTestCase() { SqlManager::shutdown(); }

void TestResultNode::testToString() {
    QSharedPointer<ResultNode> node = QSharedPointer<ResultNode>::create();
    node->setPreviousCategoryId(1);
    node->setResultingCategoryId(2);
    QString affixToString("-Pref-0>[FWPref-Aa-]");
    QString nonAffixToString("-1>[2]");
    QCOMPARE(node->toString(true), affixToString);
    QCOMPARE(node->toString(false), nonAffixToString);
}

void TestResultNode::testPreviousResultNode() {
    Node *root = new LetterNode();
    Node *child = new LetterNode();
    root->addChild(child);
    Node *grandChild = new ResultNode();
    child->addChild(grandChild);
    QVERIFY2(dynamic_cast<ResultNode *>(grandChild)->previousResultNode() ==
                 nullptr,
             "When none of the ancestor nodes in a tree are instances of a "
             "ResultNode the previousResultNode() should return nullptr.");
    delete root;

    root = new LetterNode();
    child = new ResultNode();
    root->addChild(child);
    grandChild = new ResultNode();
    child->addChild(grandChild);
    QVERIFY2(dynamic_cast<ResultNode *>(grandChild)->previousResultNode() ==
                 child,
             "The previousResultNode() should return the closest ancestor that "
             "is instance of ResultNode class.");
    delete root;

    root = new ResultNode();
    child = new LetterNode();
    root->addChild(child);
    grandChild = new ResultNode();
    child->addChild(grandChild);
    QVERIFY2(dynamic_cast<ResultNode *>(grandChild)->previousResultNode() ==
                 child,
             "The previousResultNode() should return the closest ancestor that "
             "is instance of ResultNode class.");
    delete root;

    root = new ResultNode();
    QVERIFY2(dynamic_cast<ResultNode *>(grandChild)->previousResultNode() ==
                 nullptr,
             "When node has no parent the previousResultNode() should return "
             "nullptr.");
    delete root;
}

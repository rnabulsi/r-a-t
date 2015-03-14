#ifndef REDUCE_THRU_DIACRITICS
#include "test_resultnode_default.h"
#include <resultnode.h>

// Helper macros
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

void TestResultNodeDefault::testConstruction() {
    ResultNode *resultNode = new ResultNode();
    QVERIFY2(resultNode->previousCategoryId() == 0,
             "When result node is constructed without parameters the previous "
             "category id should be set to 0.");
    QVERIFY2(resultNode->affixId() == 0, "When result node is constructed "
                                         "without parameters the affix id "
                                         "should be set to 0.");
    QVERIFY2(resultNode->resultingCategoryId() ==
                 ResultNode::DEFAULT_RESULTING_CATEGORY_ID,
             "When result node is constructed without parameters the resulting "
             "category id should be set to the default value " STR(
                 ResultNode::DEFAULT_RESULTING_CATEGORY_ID) ".");
    QVERIFY2(resultNode->acceptState(), "When result node is constructed "
                                        "without parameters the accept state "
                                        "should be set to true.");
    QVERIFY2(resultNode->inflectionRule() == QString::null,
             "When result node is constructed without parameters the "
             "inflection rule should be set to null string.");
    delete resultNode;

    resultNode = new ResultNode(1, 2, 3, false);
    QVERIFY2(resultNode->previousCategoryId() == 2,
             "When result node is constructed with parameters the previous "
             "category id should be set to the value given as paramter.");
    QVERIFY2(resultNode->affixId() == 1, "When result node is constructed "
                                         "with parameters the affix id "
                                         "should be set to 0");
    QVERIFY2(resultNode->resultingCategoryId() == 3,
             "When result node is constructed with parameters the resulting "
             "category id should be set to the default value " STR(
                 ResultNode::DEFAULT_RESULTING_CATEGORY_ID));
    QVERIFY2(!resultNode->acceptState(),
             "When result node is constructed with parameters the accept "
             "state should be set to the value given as paramater.");
    QVERIFY2(resultNode->inflectionRule() == QString::null,
             "The inflection rule should be set to null string regardless of "
             "the parameters passed during construction.");
    delete resultNode;
}

void TestResultNodeDefault::testCopy() {
    ResultNode original(1, 2, 3, false);
    original.setInflectionRule("DummyRule");
    ResultNode copy(original);

    QVERIFY2(
        copy.previousCategoryId() == original.previousCategoryId(),
        "During result node copy the previous category id should be copied.");
    QVERIFY2(copy.affixId() == original.affixId(),
             "During result node copy the affix id should be copied.");
    QVERIFY2(
        copy.resultingCategoryId() == original.resultingCategoryId(),
        "During result node copy the resulting category id should be copied.");
    QVERIFY2(copy.acceptState() == original.acceptState(),
             "During result node copy the accept state should be copied.");
    QVERIFY2(copy.inflectionRule() == original.inflectionRule(),
             "During result node copy the inflection rules should be copied.");
}

void TestResultNodeDefault::testAssignment() {
    ResultNode original(1, 2, 3, false);
    original.setInflectionRule("DummyRule");
    ResultNode copy;
    copy = original;

    QVERIFY2(copy.previousCategoryId() == original.previousCategoryId(),
             "After result node assignment the previous category ids should be "
             "equal.");
    QVERIFY2(copy.affixId() == original.affixId(),
             "After result node assignment the affix ids should be equal.");
    QVERIFY2(copy.resultingCategoryId() == original.resultingCategoryId(),
             "After result node assignment the resulting category ids should "
             "be equal.");
    QVERIFY2(copy.acceptState() == original.acceptState(),
             "After result node assignment the accept states should be equal.");
    QVERIFY2(
        copy.inflectionRule() == original.inflectionRule(),
        "After result node assignment the inflection rules should be equal.");
}

// Remove helper macros
#undef STR
#undef STR_HELPER

#endif // REDUCE_THRU_DIACRITICS

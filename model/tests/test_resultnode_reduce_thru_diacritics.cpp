#ifdef REDUCE_THRU_DIACRITICS

#include "test_resultnode_reduce_thru_diacritics.h"
#include <resultnode.h>

// Helper macros
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

void TestResultNodeReduceThruDiacritics::testConstruction() {
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
    QVERIFY2(resultNode->rawData().empty(), "When result node is constructed "
                                            "without parameters the raw data "
                                            "list should be empty.");
    delete resultNode;

    resultNode = new ResultNode(1, 2, 3, false, "original", "inflected");
    QVERIFY2(resultNode->previousCategoryId() == 2,
             "When result node is constructed with parameters the previous "
             "category id should be set to the value given as paramter.");
    QVERIFY2(resultNode->affixId() == 1, "When result node is constructed "
                                         "without parameters the affix id "
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
    QVERIFY2(resultNode->rawData().size() == 1,
             "When result node is constructed with parameters the raw data "
             "list should contain exactly one element.");
    RawData rawData("original", "inflected");
    QVERIFY2(resultNode->rawData().contains(rawData),
             "Result node is constructed with parameters the raw data list "
             "should contain raw data element with given original and "
             "inflected strings.");
    delete resultNode;
}

void TestResultNodeReduceThruDiacritics::testCopy() {
    ResultNode original(1, 2, 3, false, "original", "inflected");
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
    for (auto &rawData : original.rawData()) {
        QVERIFY2(copy.rawData().contains(rawData),
                 "During result node copy all raw data items should be copied.");
    }
}

void TestResultNodeReduceThruDiacritics::testAssignment() {
    ResultNode original(1, 2, 3, false, "original", "inflected");
    original.setInflectionRule("DummyRule");
    ResultNode copy;
    copy = original;

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
    for (auto &rawData : original.rawData()) {
        QVERIFY2(copy.rawData().contains(rawData),
                 "During result node copy all raw data items should be copied.");
    }
}

void TestResultNodeReduceThruDiacritics::testAddRawData() {
    ResultNode resultNode;
    int rawDataSize = resultNode.rawData().size();
    resultNode.addRawData("original", "inflected");
    QVERIFY2(resultNode.rawData().size() == rawDataSize + 1, "After adding raw data item the number of items in raw data list should increase by 1.");
    RawData rawData("original", "inflected");
    QVERIFY2(resultNode.rawData().contains(rawData), "After adding raw data item that item should be in raw data list.");
    rawDataSize = resultNode.rawData().size();
    resultNode.addRawData("original", "inflected");
    QVERIFY2(resultNode.rawData().size() == rawDataSize, "Trying to add the same raw data twice should have no effect as raw data items should be unique.");
}

// Remove helper macros
#undef STR
#undef STR_HELPER

#endif // REDUCE_THRU_DIACRITICS

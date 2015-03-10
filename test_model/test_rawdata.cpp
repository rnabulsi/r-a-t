#include "test_rawdata.h"
#include <rawdata.hpp>

void TestRawData::testConstruction() {
    RawData d1("ABC");
    QVERIFY2(d1.original() == "ABC", "During construction the original "
                                     "string should be set to the passed "
                                     "value.");
    QVERIFY2(d1.inflected() == "*", "If inflected string is not given during "
                                    "construction it should be set to *");
    RawData d2("ABC", "ABC");
    QVERIFY2(d2.original() == "ABC", "During construction the original "
                                     "string should be set to the passed "
                                     "value.");
    QVERIFY2(d2.inflected() == "*", "If given inflected string is equal to "
                                    "original string, during the construction "
                                    "the infected string should be set to *");
    RawData d3("ABC", "abc");
    QVERIFY2(d3.original() == "ABC", "During construction the original "
                                     "string should be set to the passed "
                                     "value.");
    QVERIFY2(d3.inflected() == "abc", "During construction the inflected "
                                      "string should be set to the passed "
                                      "value.");
}

void TestRawData::testEqualsOperator() {
    RawData d1("ABC", "abc");
    RawData d2("ABC", "abc");
    RawData d3("ABC");
    QVERIFY2(d1 == d2, "Two RawData instances should be equal if their "
                       "original and inflected strings are equal.");
    QVERIFY2(!(d2 == d3), "Two RawData instances must not be equal if their "
                          "original and inflacted strings are not equal.");
}

void TestRawData::testActual() {
    RawData d1("ABC");
    QVERIFY2(d1.actual() == "ABC", "If no inflected string is given, the "
                                   "actual string should be equal to original "
                                   "one.");
    RawData d2("ABC", "ABC");
    QVERIFY2(d2.actual() == "ABC",
             "If inflected and orignal strings are equal "
             "the actual string should be equal to them.");
    RawData d3("ABC", "abc");
    QVERIFY2(d3.actual() == "abc", "If inflected string is given and it is not "
                                   "equal to original one, the actual should "
                                   "be equal to the inflected string.");
}

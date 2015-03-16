#include "test_letters.h"
#include "letters.h"

void TestLetters::testIsDelimiter() {
    QVERIFY(isDelimiter(QChar(0x0001)));
    QVERIFY(isDelimiter(QChar(0x0010)));
    QVERIFY(isDelimiter(QChar('!')));
    QVERIFY(isDelimiter(QChar('.')));
    QVERIFY(isDelimiter(QChar('\n')));
    QVERIFY(isDelimiter(QChar(' ')));
    QVERIFY(isDelimiter(QUESTION_MARK));
    QVERIFY(isDelimiter(DOUBLE_QUOTATION3));
    QVERIFY(isDelimiter(PARAGRAPH_SEPERATOR));
    QVERIFY(isDelimiter(ZERO_WIDTH_SPACE));
    QVERIFY(!isDelimiter(ALEF));
    QVERIFY(!isDelimiter(DAMMA));
    QVERIFY(!isDelimiter(QAF));
    QVERIFY(!isDelimiter(SHADDE));
    QVERIFY(!isDelimiter(WAW_HAMZA_ABOVE));
}

void TestLetters::testIsPunctuationMark() {
    QVERIFY(isPunctuationMark(FASILA));
    QVERIFY(isPunctuationMark(QUESTION_MARK));
    QVERIFY(isPunctuationMark(FULL_STOP3));
    QVERIFY(isPunctuationMark(QChar('!')));
    QVERIFY(isPunctuationMark(QChar('.')));
    QVERIFY(isPunctuationMark(QChar('\r')));
    QVERIFY(isPunctuationMark(QChar('\"')));
    QVERIFY(!isPunctuationMark(SINGLE_QUOTATION1));
    QVERIFY(!isPunctuationMark(COLON_RAISED));
    QVERIFY(!isPunctuationMark(ALEF));
    QVERIFY(!isPunctuationMark(SHADDE));
    QVERIFY(!isPunctuationMark(_3YN));
    QVERIFY(!isPunctuationMark(THA2));
}

void TestLetters::testIsNonConnectingLetter() {
    QVERIFY(isNonConnectingLetter(ALEF));
    QVERIFY(isNonConnectingLetter(ALEF_HAMZA_ABOVE));
    QVERIFY(isNonConnectingLetter(ALEF_HAMZA_BELOW));
    QVERIFY(!isNonConnectingLetter(DOUBLE_QUOTATION6));
    QVERIFY(!isNonConnectingLetter(BA2));
    QVERIFY(!isNonConnectingLetter(DAMMA));
    QVERIFY(!isNonConnectingLetter(QChar('!')));
    QVERIFY(!isNonConnectingLetter(QChar(0x0010)));
}

void TestLetters::testIsNumber() {
    QVERIFY(isNumber('4'));
    QVERIFY(isNumber('2'));
    QVERIFY(!isNumber(PARAGRAPH_SEPERATOR));
    QVERIFY(!isNumber(THAL));
}

void TestLetters::testIsDelimiterOrNumber() {
    QVERIFY(isDelimiterOrNumber(QChar(0x0001)));
    QVERIFY(isDelimiterOrNumber(QChar(0x0010)));
    QVERIFY(isDelimiterOrNumber(QChar('!')));
    QVERIFY(isDelimiterOrNumber(QChar('.')));
    QVERIFY(isDelimiterOrNumber(QChar('\n')));
    QVERIFY(isDelimiterOrNumber(QChar(' ')));
    QVERIFY(isDelimiterOrNumber(QUESTION_MARK));
    QVERIFY(isDelimiterOrNumber(DOUBLE_QUOTATION3));
    QVERIFY(isDelimiterOrNumber(PARAGRAPH_SEPERATOR));
    QVERIFY(isDelimiterOrNumber(ZERO_WIDTH_SPACE));
    QVERIFY(!isDelimiterOrNumber(ALEF));
    QVERIFY(!isDelimiterOrNumber(DAMMA));
    QVERIFY(!isDelimiterOrNumber(QAF));
    QVERIFY(!isDelimiterOrNumber(SHADDE));
    QVERIFY(!isDelimiterOrNumber(WAW_HAMZA_ABOVE));
    QVERIFY(isDelimiterOrNumber('4'));
    QVERIFY(isDelimiterOrNumber('2'));
    QVERIFY(!isDelimiterOrNumber(THAL));
}

void TestLetters::testIsLongVowel() {
    QVERIFY(isLongVowel(YA2));
    QVERIFY(isLongVowel(WAW));
    QVERIFY(isLongVowel(ALEF));
    QVERIFY(isLongVowel(ALEF_MADDA_ABOVE));
    QVERIFY(!isLongVowel(QAF));
    QVERIFY(!isLongVowel(QUESTION_MARK));
    QVERIFY(!isLongVowel(THA2));
    QVERIFY(!isLongVowel(DAD));
}

void TestLetters::testIsShamsi() {
    QVERIFY(isShamsi(TA2));
    QVERIFY(isShamsi(THA2));
    QVERIFY(isShamsi(DAL));
    QVERIFY(isShamsi(THAL));
    QVERIFY(isShamsi(RA2));
    QVERIFY(isShamsi(ZAIN));
    QVERIFY(isShamsi(SHEEN));
    QVERIFY(isShamsi(SEEN));
    QVERIFY(isShamsi(SAD));
    QVERIFY(isShamsi(DAD));
    QVERIFY(isShamsi(TAH));
    QVERIFY(isShamsi(ZAH));
    QVERIFY(isShamsi(LAM));
    QVERIFY(isShamsi(NOON));
    QVERIFY(!isShamsi(ALEF));
    QVERIFY(!isShamsi(SEMICOLON_AR));
    QVERIFY(!isShamsi(YA2));
    QVERIFY(!isShamsi(ALEF));
    QVERIFY(!isShamsi(_3YN));
    QVERIFY(!isShamsi(_7A2));
    QVERIFY(!isShamsi(VEH));
}

#ifndef TEST_LETTERS_H
#define TEST_LETTERS_H

#include <QtTest>

class TestLetters : public QObject {
    Q_OBJECT
public:
    TestLetters() : QObject() {}
    virtual ~TestLetters() {}

private slots:
    virtual void testIsDelimiter();
    virtual void testIsPunctuationMark();
    virtual void testIsNonConnectingLetter();
    virtual void testIsNumber();
    virtual void testIsDelimiterOrNumber();
    virtual void testIsLongVowel();
    virtual void testIsShamsi();
};

#endif // TEST_LETTERS_H

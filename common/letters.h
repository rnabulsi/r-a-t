#ifndef LETTERS_H
#define LETTERS_H

#include <QChar>
#include <QString>

static const QChar HAMZA = QChar(0x0621);
static const QChar YA2 = QChar(0x064A);
static const QChar YA2_HAMZA_ABOVE = QChar(0x0626);
static const QChar ALEF = QChar(0x0627);
static const QChar ALEF_MADDA_ABOVE = QChar(0x0622);
static const QChar ALEF_HAMZA_ABOVE = QChar(0x0623);
static const QChar ALEF_HAMZA_BELOW = QChar(0x0625);
static const QChar ALEF_WASLA = QChar(0x0671);
static const QChar TA2_MARBOUTA = QChar(0x0629);
static const QChar WAW = QChar(0x0648);
static const QChar WAW_HAMZA_ABOVE = QChar(0x0624);
static const QChar SHADDE = QChar(0x0651);
static const QChar SHADDE_ALEF_ABOVE = QChar(0xFC63);
static const QChar FATHA = QChar(0x064E);
static const QChar DAMMA = QChar(0x064F);
static const QChar KASRA = QChar(0x0650);
static const QChar SUKUN = QChar(0x0652);
static const QChar LAM = QChar(0x0644);
static const QChar KASRATAYN = QChar(0x064D);
static const QChar DAMMATAYN = QChar(0x064C);
static const QChar FATHATAYN = QChar(0x064B);
static const QChar KHA2 = QChar(0x062E);
static const QChar BA2 = QChar(0x0628);
static const QChar RA2 = QChar(0x0631);
static const QChar NOON = QChar(0x0646);
static const QChar SEEN = QChar(0x0633);
static const QChar SHEEN = QChar(0x0634);
static const QChar MEEM = QChar(0x0645);
static const QChar _3YN = QChar(0x0639);
static const QChar TA2 = QChar(0x062A);
static const QChar QAF = QChar(0x0642);
static const QChar _7A2 = QChar(0x062D);
static const QChar DAL = QChar(0x062F);
static const QChar THA2 = QChar(0x062B);
static const QChar ALEFT_SUPERSCRIPT = QChar(0x0670);
static const QChar HA2 = QChar(0x0647);
static const QChar VEH = QChar(0x06A4);
static const QChar FEH = QChar(0x0641);
static const QChar MADDA = QChar(0x0653);
static const QChar ZAIN = QChar(0x0632);
static const QChar THAL = QChar(0x0630);
static const QChar SAD = QChar(0x0635);
static const QChar DAD = QChar(0x0636);
static const QChar TAH = QChar(0x0637);
static const QChar ZAH = QChar(0x0638);
static const QChar ALEF_MAKSOURA = QChar(0x0649);

static const QChar QUESTION_MARK = QChar(0x061F);
static const QChar SEMICOLON_AR = QChar(0x061B);
static const QChar COLON_RAISED = QChar(0x02F8);
static const QChar COLON_MODIFIER = QChar(0xA789);
static const QChar FASILA = QChar(0x060C);
static const QChar FULL_STOP1 = QChar(0x06D4);
static const QChar FULL_STOP2 = QChar(0x200F);
static const QChar FULL_STOP3 = QChar(0x002E);
static const QChar DOUBLE_QUOTATION1 = QChar(0x00BB); // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
static const QChar DOUBLE_QUOTATION2 = QChar(0x00AB); // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
static const QChar DOUBLE_QUOTATION3 = QChar(0x02DD); // DOUBLE ACUTE ACCENT
static const QChar DOUBLE_QUOTATION4 = QChar(0x02EE); // MODIFIER LETTER DOUBLE APOSTROPHE
static const QChar DOUBLE_QUOTATION5 = QChar(0x02F5); // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
static const QChar DOUBLE_QUOTATION6 = QChar(0x02F6); // MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
static const QChar SINGLE_QUOTATION1 = QChar(0x02BB); // MODIFIER LETTER TURNED COMMA
static const QChar SINGLE_QUOTATION2 = QChar(0x02BC); // MODIFIER LETTER APOSTROPHE
static const QChar SINGLE_QUOTATION3 = QChar(0x02BD); // MODIFIER LETTER REVERSED COMMA
static const QChar SINGLE_QUOTATION4 = QChar(0x02CA); // MODIFIER LETTER ACUTE ACCENT
static const QChar SINGLE_QUOTATION5 = QChar(0x02CB); // MODIFIER LETTER GRAVE ACCENT

static const QChar PARAGRAPH_SEPERATOR = QChar(0x2029); // PARAGRAPH SEPARATOR
static const QChar ZERO_WIDTH_SPACE = QChar(0xFEFF);    // ZERO WIDTH NO-BREAK
                                                        // SPACE
static const QChar KASHIDA = QChar(0x0640);

static const QString DELIMITERS = QString("[!_ :\\.,()-><{}=*+\\/|'\"\n\t\r") + FASILA + QUESTION_MARK + SEMICOLON_AR +
                                  FULL_STOP1 + FULL_STOP2 + FULL_STOP3 + DOUBLE_QUOTATION1 + DOUBLE_QUOTATION2 +
                                  DOUBLE_QUOTATION3 + DOUBLE_QUOTATION4 + DOUBLE_QUOTATION5 + DOUBLE_QUOTATION6 +
                                  SINGLE_QUOTATION1 + SINGLE_QUOTATION2 + SINGLE_QUOTATION3 + SINGLE_QUOTATION4 +
                                  SINGLE_QUOTATION5 + PARAGRAPH_SEPERATOR + ZERO_WIDTH_SPACE + "\\[\\]]";

static const QString PUNCTUATION = QString(":!_\\.,=-'\n\r\"") + FASILA + QUESTION_MARK + SEMICOLON_AR + FULL_STOP1 +
                                   FULL_STOP2 + FULL_STOP3 + PARAGRAPH_SEPERATOR;

static const QString ALEFS = QString("") + ALEF + ALEF_HAMZA_ABOVE + ALEF_HAMZA_BELOW + ALEF_MADDA_ABOVE + ALEF_WASLA;

static const QString NON_CONNECTING_LETTERS = QString("") + ALEF + ALEF_HAMZA_ABOVE + ALEF_HAMZA_BELOW +
                                              ALEF_MADDA_ABOVE + ALEF_WASLA + ALEFT_SUPERSCRIPT + WAW_HAMZA_ABOVE +
                                              WAW + HAMZA + ZAIN + RA2 + THAL + DAL + TA2_MARBOUTA + ALEF_MAKSOURA;

static const QString NON_PUNCTUATION_DELIMITERS =
    QString(DELIMITERS).remove(QRegExp("[" + PUNCTUATION + "]")).remove('-').remove('[').remove(']').remove(':');

inline bool isDelimiter(const QChar &letter) {
    int uni = letter.unicode();
    if (uni == 0)
        return false;
    if (uni < 0x0020)
        return true;
    return DELIMITERS.contains(letter);
}

inline bool isPunctuationMark(const QChar &letter) { return PUNCTUATION.contains(letter); }

inline bool isNonConnectingLetter(const QChar &letter) { return NON_CONNECTING_LETTERS.contains(letter); }

inline bool isNumber(const QChar &letter) { return letter <= '9' && letter >= '0'; }

inline bool isDelimiterOrNumber(const QChar &letter) { return isNumber(letter) || isDelimiter(letter); }

inline bool isLongVowel(const QChar &letter) { return (letter == YA2 || letter == WAW || ALEFS.contains(letter)); }

inline bool isShamsi(const QChar &letter) {
    // ت، ث، د ،ذ ،ر، ز، ش، س، ص، ض، ط، ظ، ل، ن
    return (letter == TA2 || letter == THA2 || letter == DAL || letter == THAL || letter == RA2 || letter == ZAIN ||
            letter == SHEEN || letter == SEEN || letter == SAD || letter == DAD || letter == TAH || letter == ZAH ||
            letter == LAM || letter == NOON);
}

#endif // LETTERS_H

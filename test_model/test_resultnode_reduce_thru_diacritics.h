#ifdef REDUCE_THRU_DIACRITICS
#ifndef TESTRESULTNODEREDUCETHRUDIACRITICS_H
#define TESTRESULTNODEREDUCETHRUDIACRITICS_H

#include <test_resultnode.h>

class TestResultNodeReduceThruDiacritics : public TestResultNode {
    Q_OBJECT
public:
    TestResultNodeReduceThruDiacritics() : TestResultNode() {}
    virtual ~TestResultNodeReduceThruDiacritics() {}

private slots:
    virtual void testConstruction() override;
    virtual void testCopy() override;
    virtual void testAssignment() override;
    void testAddRawData();
};

#endif // TESTRESULTNODEREDUCETHRUDIACRITICS_H
#else  // REDUCE_THRU_DIACRITICS
#include <QObject>
// We are declaring dummy class here to keep moc quiet.
class TestResultNodeReduceThruDiacritics : public QObject {
    Q_OBJECT
};
#endif // REDUCE_THRU_DIACRITICS

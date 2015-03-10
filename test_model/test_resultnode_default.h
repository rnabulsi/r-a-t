#ifndef REDUCE_THRU_DIACRITICS
#ifndef TESTRESULTNODEDEFAULT_H
#define TESTRESULTNODEDEFAULT_H

#include <test_resultnode.h>

class TestResultNodeDefault : public TestResultNode {
    Q_OBJECT
public:
    TestResultNodeDefault() : TestResultNode() {}
    virtual ~TestResultNodeDefault() {}

private slots:
    virtual void testConstruction() override;
    virtual void testCopy() override;
    virtual void testAssignment() override;
};

#endif // TESTRESULTNODEDEFAULT_H
#else  // REDUCE_THRU_DIACRITICS
#include <QObject>
// We are declaring dummy class here to keep moc quiet.
class TestResultNodeDefault : public QObject {
    Q_OBJECT
};
#endif // REDUCE_THRU_DIACRITICS

#ifndef EMPTYPROGRESS_H
#define EMPTYPROGRESS_H

#include <atmprogress.h>

#warning Review class purpose

/*!
 * \brief The EmptyProgress class an empty progress implementation. It does
 * absolutely nothing.
 */
class EmptyProgress : public ATMProgress {
public:
    explicit EmptyProgress() {}
    virtual ~EmptyProgress() {}

    virtual void report(int /*value*/) override {}
    virtual void startTaggingText(const QString & /*text*/) override {}
    virtual void tag(int /*start*/, int /*lenght*/, const QColor & /*color*/, bool /*textColor = true*/) override {}
    virtual void finishTaggingText() override {}
    virtual void setCurrentAction(const QString & /*action*/) override {}
    virtual void resetActionDisplay() override {}
    virtual void displayGraph(AbstractGraph * /*graph*/) override {}
    virtual QString fileName() override { return QString::null; }
};

#endif // EMPTYPROGRESS_H

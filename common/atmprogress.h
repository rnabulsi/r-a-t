#ifndef ATMPROGRESS
#define ATMPROGRESS

#warning Review class purpose

// Forward declarations
class QColor;
class QString;
class AbstractGraph;

/*!
 * \brief The ATMProgress class is an abstract base for all progress reporters.
 */
class ATMProgress {
public:
    virtual ~ATMProgress() {}
    virtual void report(int value) = 0;
    virtual void startTaggingText(const QString & text) = 0;
    virtual void tag(int start, int lenght, const QColor & color, bool textColor = true) = 0;
    virtual void finishTaggingText() = 0;
    virtual void setCurrentAction(const QString & action) = 0;
    virtual void resetActionDisplay() = 0;
    virtual void displayGraph(AbstractGraph * graph) = 0;
    virtual QString fileName() = 0;
};

#endif // ATMPROGRESS


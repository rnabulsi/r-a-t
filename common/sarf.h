#ifndef SARF_H
#define SARF_H

#include <QObject>
#include <QTextStream>

#warning Review class purpose

// Forward declarations
class QFile;
class SQLManager;
class ATMProgress;

/*!
 * \brief The Sarf class Initializes and starts the engine.
 */
class Sarf : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief Sarf The constructor.
     * \param parent parent object.
     */
    explicit Sarf(QObject *parent = 0);
    /*!
     * \brief ~Sarf the destructor.
     */
    virtual ~Sarf();

    /*!
     * \brief start Starts the engine. If output file and/or errors file are not
     * given the \code stdout and \code stderr are used. If progress reporter is
     * not given, the default empty implementation that does nothing will be
     * used.
     * \param output_file output file.
     * \param errors_file errors file.
     * \param progres_reporter progress reporter.
     * \return \code true on successfull start of the engine.
     */
    bool start(QFile *output_file = nullptr, QFile *errors_file = nullptr,
               ATMProgress *progres_reporter = nullptr);

    /*!
     * \brief start Starts the engine. Same as \ref Sarf::start(QFile*, QFile*,
     * ATMProgressReporter*) just uses in memory strings instead of files.
     * \param output_string output string.
     * \param errors_string errors string.
     * \param progress_reporter progress reporter.
     * \return \code true on successfull start of the engine.
     */
    bool start(QString *output_string, QString *errors_string,
               ATMProgress *progress_reporter);

    /*!
     * \brief stop Stops the engine.
     * \return \code true upon successfull stop of the engine.
     */
    bool stop();

private:
    /*!
     * \brief m_errors_stream errors text stream.
     */
    QTextStream m_errors_stream;
    /*!
     * \brief m_input_stream input text stream.
     */
    QTextStream m_input_stream;
    /*!
     * \brief m_output_stream output text stream.
     */
    QTextStream m_output_stream;
    /*!
     * \brief m_sql_manager the \ref SQLManager currently in use.
     */
    SQLManager *m_sql_manager;
};

#endif // SARF_H

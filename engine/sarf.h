#ifndef SARF_H
#define SARF_H

#include <QBitArray>
#include <QObject>
#include <QTextStream>
#include <vector>
#include <QVector>

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
    const QString TRIE_PATH = "stem_trie_bama.dat";
    const QString TRIE_LIST_PATH = "stem_list_bama.dat";
    const QString COMPATIBILITY_RULES_PATH = "compatibility_rules_bama.dat";
    const QString PREFIX_TREE_PATH = "prefix_tree_bama.dat";
    const QString SUFFIX_TREE_PATH = "suffix_tree_bama.dat";
    const QString DESCRIPTION_PATH = "descriptions_bama.dat";
    const QString PREFIX_INFO_PATH = "prefix_info_bama.dat";
    const QString SUFFIX_INFO_PATH = "suffix_info_bama.dat";
    const QString STEM_INFO_PATH = "stem_info_bama.dat";

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
     * \brief start Starts and initializes the engine. If output file and/or
     * errors file are not given the \code stdout and \code stderr are used. If
     * progress reporter is not given, the default empty implementation that
     * does nothing will be used.
     * \param output_file output file.
     * \param errors_file errors file.
     * \param progress_reporter progress reporter.
     * \return \code true on successfull start of the engine.
     */
    bool start(QFile *output_file = nullptr, QFile *errors_file = nullptr, ATMProgress *progress_reporter = nullptr);

    /*!
     * \brief start Starts and initializes the engine. Same as \ref
     * Sarf::start(QFile*, QFile*, ATMProgressReporter*) just uses in memory
     * strings instead of files.
     * \param output_string output string.
     * \param errors_string errors string.
     * \param progress_reporter progress reporter.
     * \return \code true on successfull start of the engine.
     */
    bool start(QString *output_string, QString *errors_string, ATMProgress *progress_reporter = nullptr);

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
     * \brief m_invalid_bitset an invalid bitset
     */
    QBitArray m_invalid_bitset;
    /*!
     * \brief m_source_ids a vector containing source ids.
     */
    QVector<int> m_source_ids;
    /*!
     * \brief m_abstract_category_ids a vector containing abstract category ids.
     */
    QVector<int> m_abstract_category_ids;

    /*!
      * \brief Initializes all neccessary variables.
      */
    void initializeVariables();
};

#endif // SARF_H

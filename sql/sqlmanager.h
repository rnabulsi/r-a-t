#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <memory>
#include <vector>

#warning Still unimplemented
#warning Review class functionalities

// Forward declarations
class ATMProgress;

/*!
 * \brief The SqlManager class is responsible for all SQL operations. MySQL
 * database is used by default. This can be configured.
 */
class SqlManager {
public:
    /*!
     * \brief instance returns \ref SqlManager singleton instance.
     * \return the singleton instance.
     */
    static SqlManager &instance();

    /*!
     * \brief shutdown shuts down SQL subsystem. After this call the SQL system
     * can no longer be used. Must be called before exiting application.
     */
    static void shutdown();

    /*!
     * \brief ~SqlManager the destructor. Closes and removes all active
     * connections.
     */
    virtual ~SqlManager();

    /*!
     * \brief connect opens connection to database and initalizes everything if
     * needed. If connections is already active, then it is closed before
     * openning a new one.
     * \param progress_reporter progress reporter.
     * \return \code false in case of any error.
     */
    virtual bool start(ATMProgress *progress_reporter) = 0;

    /*!
     * \brief categoryName returns category name for given id.
     * \param categoryId category id.
     * \return category name or \ref QString::null if category does not exist.
     */
    virtual QString categoryName(long categoryId) = 0;

    /*!
     * \brief loadSourceIds loads source ids into given vector.
     * \param source_ids a vector to load ids into.
     * \return \code false on any failure.
     */
    virtual bool loadSourceIds(std::vector<int> &source_ids) = 0;

    /*!
     * \brief loadAbstractCategoryIds loads abstract category ids into given vector.
     * \param abstract_category_ids a vector to load ids into.
     * \return \code false on any failure.
     */
    virtual bool loadAbstractCategoryIds(std::vector<int> &abstract_category_ids) = 0;
protected:
    /*!
     * \brief SqlManager The one and only constructor.
     */
    explicit SqlManager();

    /*!
     * \brief openConnection opens connection to database server. If connection
     * is already established then it does nothing.
     * \return \code false in case of any error.
     */
    virtual bool openConnection() = 0;

    /*!
     * \brief m_database An active database connection.
     */
    QSqlDatabase m_database;

    /*!
     * \brief m_connectionName A database connection name.
     */
    const QString m_connectionName;

private:
    /*!
     * \brief m_instance The pointer to the \ref SqlManager singleton instance.
     */
    static std::unique_ptr<SqlManager> m_instance;

    /*!
     * \brief Explicitly disabled copy constructor.
     * \param manager instance to copy from.
     */
    SqlManager(const SqlManager &manager) = delete;

    /*!
     * \brief Explicitly disabled assignment operator.
     * \param manager instance to assign from.
     * \return updated self instance.
     */
    SqlManager &operator=(const SqlManager &manager) = delete;

    /*!
     * \brief closeAndRemoveConnection closes and removes current connection.
     */
    void closeAndRemoveConnection();
};

#endif // SQLMANAGER_H

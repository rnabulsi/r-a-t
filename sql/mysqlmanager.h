#ifndef MYSQLMANAGER_H
#define MYSQLMANAGER_H

#include "sqlmanager.h"

#warning Still unimplemented
#warning Review class functionalities

// Forward declarations
class ATMProgress;

/*!
 * \brief The MySqlManager class is responsible for all SQL operations using
 * MySQL database.
 */
class MySqlManager : public SqlManager {
    friend class SqlManager;
public:
    /*!
     * \brief ~MySqlManager The destructor. Closes and removes all active
     * connections.
     */
    virtual ~MySqlManager();

    /// \copydoc SqlManager::start
    virtual bool start(ATMProgress *progress_reporter) override;

    /// \copydoc SqlManager::categoryName
    virtual QString categoryName(long categoryId) override;

protected:
    /*!
     * \brief MySqlManager The one and only constructor.
     */
    explicit MySqlManager();

    /// \copydoc SqlManager::openConnection
    virtual bool openConnection() override;
private:
    /*!
     * \brief Explicitly disabled copy constructor.
     * \param manager instance to copy from.
     */
    MySqlManager(const MySqlManager &manager) = delete;

    /*!
     * \brief Explicitly disabled assignment operator.
     * \param manager instance to assign from.
     * \return updated self instance.
     */
    MySqlManager &operator=(const MySqlManager &manager) = delete;
};

#endif // MYSQLMANAGER_H

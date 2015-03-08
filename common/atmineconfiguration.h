#ifndef ATMINECONFIGURATION_H
#define ATMINECONFIGURATION_H

#include <memory>
#include <QObject>
#include <QSqlDriver>

/*!
 * \brief The ATMineConfiguration class A signleton class used for retrieving
 * configuration values.
 */
class ATMineConfiguration : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief instance returns \ref ATMineConfiguration singleton instance.
     * \return the singleton instance.
     */
    static ATMineConfiguration &instance();

    /*!
     * \brief ~ATMineConfiguration The destructor.
     */
    virtual ~ATMineConfiguration();

    /*!
     * \brief databaseType returns database type to use.
     * \return database type to use.
     */
    QSqlDriver::DbmsType databaseType();

    /*!
     * \brief databaseSchema returns database schema to use.
     * \return schema to use.
     */
    const QString databaseSchema();

    /*!
     * \brief databaseUser returns database connection username.
     * \return username to use.
     */
    const QString databaseUser();

    /*!
     * \brief databasePassword returns database connection passwrod.
     * \return password to use.
     */
    const QString databasePassword();

private:
    /*!
     * \brief m_instance The unique pointer to the \ref ATMineConfiguration
     * singleton instance.
     */
    static std::unique_ptr<ATMineConfiguration> m_instance;

    /*!
     * \brief ATMineConfiguration The one and only constructor.
     */
    explicit ATMineConfiguration();

    /*!
     * \brief Explicitly disabled copy constructor.
     * \param configuration instance to copy from.
     */
    ATMineConfiguration(const ATMineConfiguration &configuration) = delete;

    /*!
     * \brief Explicitly disabled assignment operator.
     * \param configuration instance to assign from.
     * \return updated self instance.
     */
    ATMineConfiguration &
    operator=(const ATMineConfiguration &configuration) = delete;
};

#endif // ATMINECONFIGURATION_H

#include "sqlmanager.h"
#include <mutex>
#include <atmprogress.h>
#include <QDebug>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <atmineconfiguration.h>

#include "mysqlmanager.h"

std::unique_ptr<SqlManager> SqlManager::m_instance;

SqlManager &SqlManager::instance() {
    static std::once_flag once;
    std::call_once(once, [] {
        switch (ATMineConfiguration::instance().databaseType()) {
        case QSqlDriver::MySqlServer:
            m_instance.reset(new MySqlManager);
            break;
        default:
            m_instance.reset(new MySqlManager);
            break;
        }
    });
    return *m_instance.get();
}

void SqlManager::shutdown() {
    SqlManager *tmp = m_instance.release();
    delete tmp;
}

SqlManager::SqlManager() : m_database(), m_connectionName("SarfConnection") {}

SqlManager::~SqlManager() {
}

void SqlManager::closeAndRemoveConnection() {
    if (m_database.isValid() && m_database.isOpen()) {
        m_database.close();
    }
    QSqlDatabase::removeDatabase(m_connectionName);
}

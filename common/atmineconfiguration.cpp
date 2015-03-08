#include "atmineconfiguration.h"

#include <mutex>

std::unique_ptr<ATMineConfiguration> ATMineConfiguration::m_instance;

ATMineConfiguration &ATMineConfiguration::instance() {
    static std::once_flag once;
    std::call_once(once, [] { m_instance.reset(new ATMineConfiguration); });
    return *m_instance.get();
}

ATMineConfiguration::ATMineConfiguration() : QObject() {}

ATMineConfiguration::~ATMineConfiguration() {}

QSqlDriver::DbmsType ATMineConfiguration::databaseType() {
    return QSqlDriver::MySqlServer;
}

const QString ATMineConfiguration::databaseSchema() {
    return QString("atm");
}

const QString ATMineConfiguration::databaseUser() {
    return QString("root");
}

const QString ATMineConfiguration::databasePassword() {
    return QString("root");
}

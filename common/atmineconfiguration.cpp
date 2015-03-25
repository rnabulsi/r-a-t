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

const QString ATMineConfiguration::databaseType() const {
    return "QMYSQL";
}

const QString ATMineConfiguration::databaseSchema() const {
    return "atm";
}

const QString ATMineConfiguration::databaseUser() const {
    return "root";
}

const QString ATMineConfiguration::databasePassword() const {
    return "root";
}

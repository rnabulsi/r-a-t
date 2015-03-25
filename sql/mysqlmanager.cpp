#include "mysqlmanager.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <atmineconfiguration.h>

MySqlManager::MySqlManager() {
}

MySqlManager::~MySqlManager() {}

bool MySqlManager::start(ATMProgress *progress_reporter) {
#warning Still unimplemented
    if (m_database.isValid() && m_database.isOpen()) {
        return true;
    }
    bool connectionOpened = openConnection();
    return connectionOpened;
}

bool MySqlManager::openConnection() {
    if (!m_database.isValid()) {
        m_database = QSqlDatabase::addDatabase("QMYSQL", m_connectionName);
    }
    if (m_database.isOpen()) {
        return true;
    }
    m_database.setDatabaseName(ATMineConfiguration::instance().databaseSchema());
    m_database.setUserName(ATMineConfiguration::instance().databaseUser());
    m_database.setPassword(ATMineConfiguration::instance().databasePassword());
    bool connectionOpened = m_database.open();
    if (!connectionOpened) {
        qCritical("Cannot open database connecton: %s", m_database.lastError().text().toStdString().c_str());
    }
    return connectionOpened;
}

QString MySqlManager::categoryName(long categoryId) {
    QString name = QString::null;
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        query.exec(QString("SELECT name FROM category WHERE id = %1").arg(categoryId));
        if (query.size() == 0) {
            name = QString::null;
        } else {
            query.next();
            name = query.value(0).toString();
        }
    }
    return name;
}

bool MySqlManager::loadSourceIds(QVector<int> &source_ids) {
    if (!m_database.isOpen()) {
        return false;
    }

    QSqlQuery query(m_database);
    query.exec("SELECT id FROM source");
    qDebug() << "QUERY SIZE: " << query.size();
    if (query.size() == 0) {
        return false;
    } else {
        while (query.next()) {
            source_ids.push_back(query.value(0).toInt());
        }
    }
    qDebug() << "SOURCE IDS SIZE: " << source_ids.size();
    return true;
}

bool MySqlManager::loadAbstractCategoryIds(QVector<int> &abstract_category_ids) {
    if (!m_database.isOpen()) {
        return false;
    }

    QSqlQuery query(m_database);
    query.exec("SELECT id FROM category WHERE abstract = 1");
    if (query.size() == 0) {
        return false;
    } else {
        while (query.next()) {
            abstract_category_ids.push_back(query.value(0).toInt());
        }
    }

    return true;
}


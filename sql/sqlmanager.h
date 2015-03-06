#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QObject>

class SqlManager : public QObject {
public:
    explicit SqlManager(){};
    virtual ~SqlManager(){};

    QString getColumn(QString &table, QString &columnName, long long id,
                      QString additional_condition = "", bool has_id = true) {
        return QString::null;
    };
};

#endif // SQLMANAGER_H

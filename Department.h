#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

class Department : public QObject {
    Q_OBJECT

public:
    explicit Department(QObject *parent = nullptr);
    bool addDepartment(const QString &name);

signals:
    void departmentAdded();
    void errorOccurred(const QString &error);

private:
    QSqlDatabase db;
};

#endif // DEPARTMENT_H

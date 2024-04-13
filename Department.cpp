#include "Department.h"

Department::Department(QObject *parent) : QObject(parent) {
    db = QSqlDatabase::database(); // Assuming a database connection is already setup
}

bool Department::addDepartment(const QString &name) {
    if (name.trimmed().isEmpty()) {
        emit errorOccurred("Department name cannot be empty.");
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO departments (dept_name) VALUES (:dept_name)");
    query.bindValue(":dept_name", name);
    if (!query.exec()) {
        emit errorOccurred("Database error: " + query.lastError().text());
        return false;
    }

    emit departmentAdded();
    return true;
}

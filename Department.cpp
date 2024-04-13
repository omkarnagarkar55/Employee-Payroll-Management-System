#include "Department.h"

Department::Department(QObject *parent) : QObject(parent) {
    db = QSqlDatabase::database(); // Assuming a database connection is already setup
    // db = QSqlDatabase::database("MainDB");

}

bool Department::addDepartment(const QString &name) {
    if (name.trimmed().isEmpty()) {
        emit errorOccurred("Department name cannot be empty.");
        return false;
    }

    // if (!db.isOpen()) {
    //     qDebug() << "Database not open:" << db.lastError().text();
    //     emit errorOccurred("Database connection is not open.");
    //     return false;
    // }

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

// #include "Department.h"

// Department::Department(QObject *parent) : QObject(parent) {
//     // Ensure that db is set to the active database connection
//     db = QSqlDatabase::database();
// }

// bool Department::addDepartment(const QString &name) {
//     if (name.trimmed().isEmpty()) {
//         emit errorOccurred("Department name cannot be empty.");
//         return false;
//     }

//     // Create a QSqlQuery object without passing the database object explicitly
//     QSqlQuery query;
//     query.prepare("INSERT INTO departments (dept_name) VALUES (:dept_name)");
//     query.bindValue(":dept_name", name);
//     if (!query.exec()) {
//         emit errorOccurred("Database error: " + query.lastError().text());
//         return false;
//     }

//     emit departmentAdded();
//     return true;
// }


// #include "Department.h"
// #include <QDebug> // Include for debugging output

// Department::Department(QObject *parent) : QObject(parent) {
//     db = QSqlDatabase::database(); // Assuming a database connection is already setup
// }

// bool Department::addDepartment(const QString &name) {
//     if (name.trimmed().isEmpty()) {
//         emit errorOccurred("Department name cannot be empty.");
//         return false;
//     }

//     QSqlQuery query(db);
//     query.clear();
//     query.prepare("INSERT INTO departments (dept_name) VALUES (:dept_name)");
//     query.bindValue(":dept_name", name);

//     if (!query.exec()) {
//         // Detailed debug output
//         qDebug() << "Query failed to execute.";
//         qDebug() << "Error:" << query.lastError().text();
//         qDebug() << "Executed Query:" << query.executedQuery();
//         qDebug() << "Bound values:" << query.boundValues();

//         emit errorOccurred("Database error: " + query.lastError().text());
//         return false;
//     }

//     emit departmentAdded();
//     return true;
// }

#include "mainwindow.h"
// #include "WelcomeWidget.h"
#include "DashboardWidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set up the UI components
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    loginButton = new QPushButton("Login", this);

    // Set placeholder texts
    usernameLineEdit->setPlaceholderText("Enter your username");
    passwordLineEdit->setPlaceholderText("Enter your password");
    passwordLineEdit->setEchoMode(QLineEdit::Password); // Hide password input

    // Position the UI elements
    usernameLineEdit->setGeometry(50, 50, 200, 30);
    passwordLineEdit->setGeometry(50, 100, 200, 30);
    loginButton->setGeometry(50, 150, 200, 30);

    // Connect the button click signal to the slot
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);

    // Initialize database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("authentication.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    // Create the users table if it does not exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT UNIQUE, password TEXT)");

    // Optionally, pre-load some users (you can remove this part after the first run)
    if (!query.exec("INSERT OR IGNORE INTO users (username, password) VALUES ('admin', 'adminpass'), ('user', 'userpass')")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void MainWindow::on_loginButton_clicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();

    if (query.next()) {
        // Close the current window or hide elements
        this->hide();

        // Create and show welcome widget
        // WelcomeWidget *welcomeWidget = new WelcomeWidget();
        // welcomeWidget->show();
        // welcomeWidget->findChild<QLabel*>()->setText(QString("Welcome, %1. Click below to see your recent payroll.").arg(username));
        DashboardWidget *dashboardWidget = new DashboardWidget();
        dashboardWidget->show();

    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

MainWindow::~MainWindow()
{
    // Destructor content, if needed
}

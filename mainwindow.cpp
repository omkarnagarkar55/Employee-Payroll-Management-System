#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include "WelcomeWidget.h"
#include "DashboardWidget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button click signal to the slot
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);

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
    if (!query.exec("INSERT OR IGNORE INTO users (username, password) VALUES ('admin', 'admin'), ('user', 'user')")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

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

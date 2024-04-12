#include "mainwindow.h"
#include "WelcomeWidget.h"

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
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_loginButton_clicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    // Simple authentication: check if the credentials match
    if (username == "admin" && password == "password") {
        // Close the current window or hide elements
        this->hide();

        // Create and show welcome widget
        WelcomeWidget *welcomeWidget = new WelcomeWidget();
        welcomeWidget->show();
        welcomeWidget->findChild<QLabel*>()->setText(QString("Welcome, %1. Click below to see your recent payroll.").arg(username));
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

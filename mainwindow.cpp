#include "mainwindow.h"

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
        QMessageBox::information(this, "Login Success", "You are authenticated!");
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

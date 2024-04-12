#include "WelcomeWidget.h"
#include <QVBoxLayout>
#include <QMessageBox>  // Include for QMessageBox

WelcomeWidget::WelcomeWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    welcomeLabel = new QLabel("Welcome, <username>. Click below to see your recent payroll.", this);
    viewPayrollButton = new QPushButton("View Payroll", this);

    layout->addWidget(welcomeLabel);
    layout->addWidget(viewPayrollButton);

    setLayout(layout);

    // Connect the button to the slot that will handle viewing payroll
    connect(viewPayrollButton, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Payroll", "Showing recent payroll...");
    });
}

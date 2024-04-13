#include "WelcomeWidget.h"
#include "EmployeeForm.h" // Ensure this include is correct if EmployeeForm is used
#include <QDateTime>      // For displaying time if needed
#include <QTimer>         // For handling periodic updates, if used

WelcomeWidget::WelcomeWidget(QWidget *parent) : QWidget(parent) {
    setupUI();
    connectSignalsAndSlots();
}

void WelcomeWidget::setupUI() {
    // Set up user interface components
    // For example:
    timeLabel = new QLabel(this);
    QFont font = timeLabel->font();
    font.setPointSize(16);
    timeLabel->setFont(font);

    // Layout setup, etc.
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(timeLabel);

    // Set the layout on the widget
    this->setLayout(layout);

    // Timer to update time, if needed
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WelcomeWidget::updateTime);
    timer->start(1000); // Update every second
}

void WelcomeWidget::connectSignalsAndSlots() {
    // Example connecting a signal to a slot
    // If you have buttons or other interactive elements, connect them here
}

void WelcomeWidget::updateTime() {
    QDateTime currentTime = QDateTime::currentDateTime();
    timeLabel->setText(currentTime.toString("hh:mm:ss dd-MM-yyyy"));
}

void WelcomeWidget::onAddEmployee() {
    EmployeeForm *form = new EmployeeForm(this);
    form->setModal(true);
    form->exec();
}

// If there are additional methods or signals, define them here

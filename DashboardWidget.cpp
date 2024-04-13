#include "DashboardWidget.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QMessageBox>
#include "EmployeeForm.h" // Include the Employee form dialog header

DashboardWidget::DashboardWidget(QWidget *parent) : QWidget(parent)
{
    // Main layout
    QGridLayout *gridLayout = new QGridLayout(this);
    QVBoxLayout *buttonLayout = new QVBoxLayout();

    // Welcome label
    QLabel *welcomeLabel = new QLabel("Welcome Admin", this);
    QFont welcomeFont = welcomeLabel->font();
    welcomeFont.setPointSize(30); // Set the font size
    welcomeLabel->setFont(welcomeFont);
    gridLayout->addWidget(welcomeLabel, 0, 0, 1, -1, Qt::AlignCenter); // Span across all columns

    // Buttons
    QStringList buttons = {"Add New Employee", "Add New Department", "Add New Grade",
                           "Employee Grade Details", "Prepare Monthly Salary", "Generate Report"};

    foreach(const QString &buttonText, buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        button->setMinimumHeight(40); // Minimum button height
        buttonLayout->addWidget(button);
        if (buttonText == "Add New Employee") {
            connect(button, &QPushButton::clicked, this, &DashboardWidget::onAddEmployee);
        }
    }

    gridLayout->addLayout(buttonLayout, 1, 0, 1, 1); // Add button layout to the grid

    // Spacer item to push everything to the top
    QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

    // Time label setup
    timeLabel = new QLabel(this);
    QFont timeFont = timeLabel->font();
    timeFont.setPointSize(16); // Set the font size
    timeLabel->setFont(timeFont);
    gridLayout->addWidget(timeLabel, 0, 1, Qt::AlignTop | Qt::AlignRight);

    // Start the timer to update the clock
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DashboardWidget::updateTime);
    timer->start(1000); // Update the time every second

    updateTime(); // Initial time update
}

void DashboardWidget::updateTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    timeLabel->setText(currentTime.toString("hh:mm:ss dd-MM-yyyy"));
}

void DashboardWidget::onAddEmployee()
{
    EmployeeForm *form = new EmployeeForm(this); // Assuming EmployeeForm is a QDialog derived class
    form->setModal(true);
    form->exec(); // This blocks until the form is closed
}

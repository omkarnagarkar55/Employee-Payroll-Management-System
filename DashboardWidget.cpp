#include "DashboardWidget.h"
#include <QVBoxLayout>
#include <QDir>
#include <QDateTime>
#include <QTimer>
#include <QPalette>
#include <QBrush>
#include <QLinearGradient>
#include <QGridLayout>
#include <QSpacerItem>
#include "Department.h"
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>

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
    QStringList buttonTitles = {"Add New Employee", "Add New Department", "Add New Grade",
                                "Employee Grade Details", "Prepare Monthly Salary", "Generate Report"};
    QList<QPushButton*> buttons;

    foreach(const QString &buttonText, buttonTitles) {
        QPushButton *button = new QPushButton(buttonText, this);
        button->setMinimumHeight(40); // Minimum button height
        buttonLayout->addWidget(button);
        buttons.append(button);
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

    // Department manager
    Department *deptManager = new Department(this);
    connect(deptManager, &Department::departmentAdded, this, []() {
        QMessageBox::information(nullptr, "Success", "Department added successfully.");
    });
    connect(deptManager, &Department::errorOccurred, this, [](const QString &error) {
        QMessageBox::critical(nullptr, "Error", error);
    });

    // Connect button signals
    foreach(QPushButton *button, buttons) {
        connect(button, &QPushButton::clicked, this, [this, button, deptManager]() {
            if(button->text() == "Add New Department") {
                bool ok;
                QString deptName = QInputDialog::getText(this, tr("Add New Department"),
                                                        tr("Department Name:"), QLineEdit::Normal,
                                                        QDir::home().dirName(), &ok);
                if (ok && !deptName.isEmpty()) {
                    deptManager->addDepartment(deptName);
                }
            }
        });
    }
}

void DashboardWidget::updateTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    timeLabel->setText(currentTime.toString("hh:mm:ss dd-MM-yyyy"));
}

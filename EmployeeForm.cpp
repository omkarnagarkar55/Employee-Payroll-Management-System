#include "EmployeeForm.h"
#include <QMessageBox>

EmployeeForm::EmployeeForm(QWidget *parent) :
    QDialog(parent),
    nameLineEdit(new QLineEdit(this)),
    departmentLineEdit(new QLineEdit(this)),
    saveButton(new QPushButton("Save", this)),
    cancelButton(new QPushButton("Cancel", this))
{
    QLabel *nameLabel = new QLabel("Name:", this);
    QLabel *departmentLabel = new QLabel("Department:", this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(nameLabel, nameLineEdit);
    formLayout->addRow(departmentLabel, departmentLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle("Add New Employee");

    connect(saveButton, &QPushButton::clicked, this, &EmployeeForm::saveEmployee);
    connect(cancelButton, &QPushButton::clicked, this, &EmployeeForm::cancelEmployee);
}

void EmployeeForm::saveEmployee()
{
    // Placeholder for saving logic
    QMessageBox::information(this, "Employee Added", "Employee has been added successfully!");
    accept(); // Close the dialog
}

void EmployeeForm::cancelEmployee()
{
    reject(); // Close the dialog without doing anything
}

#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeForm(QWidget *parent = nullptr);

private slots:
    void saveEmployee();
    void cancelEmployee();

private:
    QLineEdit *nameLineEdit;
    QLineEdit *departmentLineEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // EMPLOYEEFORM_H

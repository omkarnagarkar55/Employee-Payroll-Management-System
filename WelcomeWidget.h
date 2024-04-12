#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = nullptr);

private:
    QLabel *welcomeLabel;
    QPushButton *viewPayrollButton;
};

#endif // WELCOMEWIDGET_H

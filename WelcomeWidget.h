#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTimer>

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = nullptr);

private:
    void setupUI();  // Declare setupUI method
    void connectSignalsAndSlots();  // Declare connectSignalsAndSlots method

signals:
    void addEmployeeRequested(); // Signal to be emitted for adding a new employee

private slots:
    void updateTime();
    void onAddEmployee(); // Slot to handle the addition of a new employee

private:
    QLabel *timeLabel;
    QTimer *timer;
    QVBoxLayout *mainLayout;
};

#endif // WELCOMEWIDGET_H

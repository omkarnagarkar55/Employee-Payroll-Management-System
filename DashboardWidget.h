#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTimer>

class DashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWidget(QWidget *parent = nullptr);

private slots:
    void updateTime();
    void onAddEmployee(); // Slot to handle the addition of a new employee

private:
    QLabel *timeLabel;
    QTimer *timer;
};

#endif // DASHBOARDWIDGET_H

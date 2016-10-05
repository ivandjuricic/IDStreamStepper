#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "motor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Motor *motor;

private slots:
    void on_applyButton_clicked();
    void on_cancelButton_clicked();
    void on_forwardsFast_clicked();
    void on_forwardsMedium_clicked();
    void on_forwardsSlow_clicked();
    void on_backwardsSlow_clicked();
    void on_backwardsMedium_clicked();
    void on_backwardsFast_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

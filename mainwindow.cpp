#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "motor.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_applyButton_clicked()
{
    delete motor;
    this->close();
}

void MainWindow::on_cancelButton_clicked()
{
    delete motor;
    this->close();
}


void MainWindow::on_forwardsFast_clicked()
{
    motor->Forwards(100);
}

void MainWindow::on_forwardsMedium_clicked()
{
    motor->Forwards(50);
}

void MainWindow::on_forwardsSlow_clicked()
{
    motor->Forwards(10);
}


void MainWindow::on_backwardsSlow_clicked()
{
    motor->Backwards(10);
}

void MainWindow::on_backwardsMedium_clicked()
{
    motor->Backwards(50);
}

void MainWindow::on_backwardsFast_clicked()
{
    motor->Backwards(100);
}

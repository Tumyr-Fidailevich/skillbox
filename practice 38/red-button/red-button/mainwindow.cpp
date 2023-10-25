#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_pressed()
{
    ui->pushButton->setDown();
    ui->pushButton->playSound();
}

void MainWindow::button_released()
{
    ui->pushButton->setDown();
}

void MainWindow::button_clicked()
{
    ui->pushButton->setUp();
    ui->pushButton->playSound();
}


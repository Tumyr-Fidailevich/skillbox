#include "mainwindow.h"
#include "ui_mainwindow.h"
//
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
//
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>
//
#include <QDir>
#include <QFileDialog>

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

QImage MainWindow::_blurImage(QImage source, int blurRadius)
{
    if(source.isNull()) return {};
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    delete blur;
    return result;
}

void MainWindow::_processSinlgeImage(QString filePath)
{
    QImage bluredImage = _blurImage(QImage(filePath), ui->blurSlider->value());
    ui->imageLabel->setPixmap(QPixmap::fromImage(bluredImage.scaled(
        ui->imageLabel->width(),
        ui->imageLabel->height(), Qt::KeepAspectRatio)));
}

void MainWindow::createFileDialog()
{
    _filePath = QFileDialog::getOpenFileName(nullptr, "Open image", QDir::current().absolutePath() + "/source" ,"jpg files (*.jpg)");
    if(!_filePath.isNull())
    {
        _processSinlgeImage(_filePath);
    }
}

void MainWindow::setBlurEffectOnImage()
{
    _processSinlgeImage(_filePath);
}


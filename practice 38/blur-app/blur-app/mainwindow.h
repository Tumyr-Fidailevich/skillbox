#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDir>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString _filePath;
    QImage _blurImage(QImage source, int blurRadius);
    void _processSinlgeImage(QString filePath);
public slots:
    void createFileDialog();
    void setBlurEffectOnImage();
};
#endif // MAINWINDOW_H

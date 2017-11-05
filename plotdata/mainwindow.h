#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include "socket.h"
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void runServer(int);

private slots:
    void makePlot(QVector<double> x, QVector<double> y);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    socket *mys;
};

#endif // MAINWINDOW_H

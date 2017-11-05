#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "socket.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mys = new socket();
    ui->setupUi(this);
    ui->pushButton->setText("GO");
    connect(mys, SIGNAL(sendData(QVector<double>, QVector<double>)), this, SLOT(makePlot(QVector <double>, QVector <double>)));
    connect(this,SIGNAL(runServer(int)),mys, SLOT(GO(int)));
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(QVector<double> x, QVector<double> y){
    ui->widget->graph(0)->setData(x, y);

    // Get max and min boundaries of x and y:

    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(x[0], x[x.size()-1]);
    ui->widget->yAxis->setRange(y[0], y[y.size()-1]);
    ui->widget->replot();
}

void MainWindow::on_pushButton_clicked()
{
    QString port = ui->textEdit->toPlainText();
    emit runServer(port.toInt());
}

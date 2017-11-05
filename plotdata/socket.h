#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QTcpServer>
#include <QtCore>
#include <QtNetwork>
#include <QString>
#include <QVector>
class socket : public QObject
{
    Q_OBJECT
public:
    explicit socket(QObject *parent = 0);
//        void Connect();

signals:
//        void dataReceived(QByteArray);
        void sendData(QVector<double>, QVector<double>);

public slots:
        void GO(int portNum);
        void newConnection();
        void disconnected();
        void readyRead();
private:
//        QTcpSocket *mysocket;
        QTcpServer *server;
        QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
        QHash<QTcpSocket*, qint32*> sizes; //We
        QString str;
//        QVector<double> *x;
//        QVector<double>* y;
};

#endif // SOCKET_H

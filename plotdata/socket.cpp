#include "socket.h"
#include <QTcpSocket>
#include <QDebug>
socket::socket(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}
void socket::GO(int portNum){
    if(!server->listen(QHostAddress::Any, portNum)){
        qDebug() << "server couldn't start";
    }
    else{
        qDebug() << "server started";
    }
}
void socket::newConnection(){
//    qDebug() << server->hasPendingConnections();
    while (server->hasPendingConnections())
    {
        QTcpSocket *socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    }
}

void socket::disconnected()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    socket->deleteLater();
}

void socket::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QVector<double> x, y;

    char* temp;
    while (socket->bytesAvailable() > 0)
    {
        int size = socket->bytesAvailable();
        temp = new char[size];
        int realsize = socket->read(temp, size);
        temp[realsize] = 0;
        str.append(temp);

    }
    QStringList fifi = str.split(',', QString::SkipEmptyParts);
    for(int i=0; i<fifi.size();i=i+2){
    x.append(fifi[i].toDouble() );
    }
    for(int i=1;i<fifi.size();i=i+2){
        y.append(fifi[i].toDouble() );

    }
//    qDebug() << y.size();
//    qDebug() << x.size();

    emit sendData(x,y);
}



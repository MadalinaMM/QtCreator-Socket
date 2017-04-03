#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{

    socket = new QTcpSocket(this);
    socket->connectToHost("www.google.com", 80);

    if(socket->waitForConnected(3000))
    {

        qDebug() << "COnnected";

        //send
        socket->write("hello server\r\r\r\r\n\r");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() <<socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not Connected";

    }


    //sent

    //got

    //closed


}

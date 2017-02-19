#include "client.h"
#include <iostream>
#include <QDateTime>
#include <cstring>
#include <iomanip>


SimpleClient::SimpleClient(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    connect(m_socket, SIGNAL(connected()),          this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(disconnected()),       this, SLOT(onDisconnected()));
    connect(m_socket, SIGNAL(readyRead()),          this, SLOT(onReadyRead()));
    connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
}

SimpleClient::~SimpleClient()
{
    delete m_socket;
}

void SimpleClient::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
    m_socket->abort();
}

void SimpleClient::setValue(int newValue)
{
    m_value = newValue;
    emit valueSet(m_value);
}

void SimpleClient::writeSocketPackage()
{
    const int size = 20;
    char m_package[size]="PACKAGE";
    std::string m_stime = std::to_string(QDateTime::currentMSecsSinceEpoch());
    char m_strToChar[m_stime.length()];
    for(unsigned int i=0; i<m_stime.length(); ++i)
    {
        m_strToChar[i] = m_stime[i];
    }
    const int sizeInf = strlen(m_package)+m_stime.length();
    std::strcat(m_package, m_strToChar);
    const int m_size = 4096;
    char str[m_size];
    memset(str,'f',m_size);
    for(int i=0; i<sizeInf; ++i)
    {
        str[i]=m_package[i];
    }
    str[m_size]='\0';
    m_socket->write(str);
}

void SimpleClient::parameterThroughputAndLtency(QByteArray byte)
{
    std::string DataOld = "";
    for(int i = atoll(std::strstr(byte,"PACKAGE"))+1; i < byte.length(); ++i)
    {
        if(!std::isalpha(byte[i]))
            DataOld += byte[i];
    }

    m_latency += QDateTime::currentMSecsSinceEpoch() - std::atoll(DataOld.c_str());
    m_nByte += byte.size();
    if(m_latency > 1000)
    {
        m_throughput = m_nByte / m_latency;
        qDebug() << "Throughput: " << m_throughput/8000 << "Mbit/s" << " | " << "Latency "<< m_latency << "m";
        m_latency = 0;
        m_nByte = 0;
    }
}
void SimpleClient::onConnected()
{
    //    qDebug() << "Connected (client)!";
    writeSocketPackage();
    //    qDebug() << "Written!";
}

void SimpleClient::onDisconnected()
{
    //    qDebug() << "Disconnected!";
}

void SimpleClient::onBytesWritten(qint64 bytes)
{
//        qDebug() << "We wrote: " << bytes << " bytes";
}

void SimpleClient::onReadyRead()
{
    QByteArray byte = m_socket->readAll();
    parameterThroughputAndLtency(byte);
    onConnected();

}

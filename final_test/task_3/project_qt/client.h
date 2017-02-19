#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class SimpleClient : public QObject
{
    Q_OBJECT
public:
    explicit SimpleClient(QObject *parent = 0);
    ~SimpleClient();

    void Connect();

    void setValue(int newValue);
    void writeSocketPackage();
    void parameterThroughputAndLtency(QByteArray byte);
signals:

    void valueSet(int);

public slots:

    void onConnected();
    void onDisconnected();
    void onBytesWritten(qint64 bytes);
    void onReadyRead();

private:

    int m_value;
    long long m_latency;
    int m_throughput;
    double m_nByte;
    QTcpSocket* m_socket;
};

#endif // CLIENT_H

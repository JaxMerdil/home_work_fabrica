#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

    void Connect();

    void SetValue(int newValue);
    void WriteSocketPackage();
    void ParameterThroughputAndLtency(QByteArray byte);
signals:

    void ValueSet(int);

public slots:

    void OnConnected();
    void OnDisconnected();
    void OnBytesWritten(qint64 bytes);
    void OnReadyRead();

private:

    int m_value;
    long long m_latency;
    int m_throughput;
    double m_nByte;
    QTcpSocket* m_socket;
};

#endif // CLIENT_H

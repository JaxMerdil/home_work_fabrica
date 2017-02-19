#include <iostream>
#include <QCoreApplication>
#include <QTimer>
#include <QThread>
#include <QDateTime>

#include "client.h"
#include "a.h"

// Links:
// - http://doc.qt.io/qt-5.6/signalsandslots.html#signals-and-slots
// - http://wiki.qt.io/Threads_Events_QObjects

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SimpleClient c;
    c.Connect();

    return app.exec();
}

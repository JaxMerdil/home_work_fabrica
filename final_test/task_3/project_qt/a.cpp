#include "a.h"
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QDateTime>
#include "worker.h"


A::A(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(aaaa()),    this, SLOT(bbbb()));

    connect(this, SIGNAL(signal()),  this, SLOT(onSignal()));
    connect(this, SIGNAL(signal2()), this, SLOT(onSignal2()));
}

A::~A()
{
}

void A::start()
{
    emit signal();
}

void A::startTimer()
{
    auto timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start();
}

void A::onValueSet(int newValue)
{
    qDebug() << "value set: " << newValue;
}

void A::onSignal()
{
    qDebug() << __PRETTY_FUNCTION__;

    //    QThread* th = new QThread();
    //    Worker* worker = new Worker();
    //    worker->moveToThread(th);
    //    connect(th, SIGNAL(started()), worker, SLOT(doWork()));
    //    th->start();

    QThread::msleep(5000);

    //emit signal2();
}

void A::onSignal2()
{
    qDebug() << __PRETTY_FUNCTION__;
    emit signal();
}

void A::onTimer()
{
    qDebug() << __PRETTY_FUNCTION__ << QDateTime::currentMSecsSinceEpoch();
    emit currentTS(QDateTime::currentMSecsSinceEpoch());
}



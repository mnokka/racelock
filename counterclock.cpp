

#include <QtWidgets>

#include "counterclock.h"
#include <QDebug>

CounterClock::CounterClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setDigitCount(8);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CounterClock::showTime);
    timer->start(1000);

    showTime();

//    setWindowTitle(tr("Digital Clock"));
//    resize(250, 150);
}







void CounterClock::showTime()
{
    //QTime time = QTime::currentTime();
   // qDebug() << "time:" << time;
    //QString text = time.toString("hh:mm:ss");
    qDebug() << "counter:" << counter;
    //if ((time.second() % 2) == 0)
    //    text[2] = ' ';
    display(counter);
   //display("11:22:33:88");
    counter=counter+1;
    if (counter>=31) {
        counter=0;
    }
}



#include <QtWidgets>

#include "raceclock.h"
#include <QDebug>

RaceClock::RaceClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setDigitCount(8);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RaceClock::showTime);
    timer->start(1000);

    showTime();

}





void RaceClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    display(text);

}

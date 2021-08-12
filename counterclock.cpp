

#include <QtWidgets>

#include "counterclock.h"
#include <QDebug>
#include "parameters.h"

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
    display(counter);
    counter=counter+1;

    if (counter>=steptime+1) {
        counter=0;
    }
}

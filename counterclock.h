#ifndef COUNTERCLOCK_H
#define COUNTERCLOCK_H


#include <QLCDNumber>

class CounterClock : public QLCDNumber
{
    Q_OBJECT

public:
    CounterClock(QWidget *parent = 0);
    int counter=0;

private slots:
    void showTime();
};


#endif // COUNTERCLOCK_H
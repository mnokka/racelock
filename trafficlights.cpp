#include "trafficlights.h"
#include <QtWidgets>

#include "trafficlights.h"
#include <QDebug>

TrafficLights::TrafficLights(QWidget *parent)
    : QDialog(parent)
{
    //setSegmentStyle(Filled);
    //setDigitCount(8);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TrafficLights::showTime);
    timer->start(1000);

    LightsButton = new QPushButton("&Nappula",this);
    LightsButton->setDefault(true);

   // LightsButton->setText("Example");




    showTime();
}


void TrafficLights::showTime()
{

   // QString text = "***";
    qDebug() << "trafficlits";
    //if ((time.second() % 2) == 0)
    //    text[2] = ' ';
    //display(text);
   //display("11:22:33:88");
    //counter=counter+1;
    //if (counter>=31) {
     //   counter=0;
    //}
}


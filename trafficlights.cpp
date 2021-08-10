#include "trafficlights.h"
#include <QtWidgets>

#include "trafficlights.h"
#include <QDebug>

TrafficLights::TrafficLights(QWidget *parent)
    : QDialog(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TrafficLights::showTime);
    timer->start(1000);

    LightsButton = new QPushButton("     xxxxx   ",this);
    LightsButton->setDefault(true);
    LightsButton->setStyleSheet("background-color:red;");
    LightsButton->setText("     WAIT     ");
    showTime();
}


void TrafficLights::showTime()
{
   static int stateflag=2;
   // QString text = "***";
    //qDebug() << "trafficlits";
    //if ((time.second() % 2) == 0)
    //    text[2] = ' ';
    //display(text);
   //display("11:22:33:88");
    counter=counter+1;
    if (counter>=31) {
        counter=0;
        LightsButton->setStyleSheet("background-color:green;");
        LightsButton->setText("     GO     ");
        stateflag=1;
    }
    if (counter>=2 and counter <20 and stateflag==1) {

        LightsButton->setStyleSheet("background-color:red;");
        LightsButton->setText("     WAIT    ");
        stateflag=2;
    }

    if (counter>20 and counter <31 and stateflag==2) {

        LightsButton->setStyleSheet("background-color:yellow;");
        LightsButton->setText("     READY     ");
        stateflag=0;
    }


}


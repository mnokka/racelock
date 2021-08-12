#include "trafficlights.h"
#include <QtWidgets>
#include <QSizePolicy>
#include <QResizeEvent>
#include "parameters.h"

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
    //LightsButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //LightsButton->setHorizontalStretch(2);
    LightsButton->setText("     WAIT     ");

    //LightsButton->setStyleSheet("text-align:middle;");
   //LightsButton->setMaximumSize(100);

    //const QSize BUTTON_SIZE = QSize(100, 100);
    //LightsButton->resize(BUTTON_SIZE);
    showTime();
}


void TrafficLights::resizeEvent(QResizeEvent*)

{
 qDebug() << "trafficlights resize event";
 QSize size=this->size();
 qDebug() << "size:" << size ;
 const QSize BUTTON_SIZE = QSize(100, 100);
 LightsButton->resize(size);
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

    qDebug() << "steptime" << steptime;
    if (counter>=steptime+1) {
        counter=0;
        LightsButton->setStyleSheet("background-color:green;");
        LightsButton->setText("     GO     ");
        stateflag=1;
    }
    if (counter>=2 and counter <steptime-10 and stateflag==1) {

        LightsButton->setStyleSheet("background-color:red;");
        LightsButton->setText("     WAIT    ");
        stateflag=2;
    }

    if (counter>steptime-10 and counter <steptime+1 and stateflag==2) {

        LightsButton->setStyleSheet("background-color:yellow;");
        LightsButton->setText("     READY     ");
        stateflag=0;
    }


}


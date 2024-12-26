#include "trafficlights.h"
#include <QtWidgets>
#include <QSizePolicy>
#include <QResizeEvent>
#include "editwindow.h"
#include "parameters.h"

#include "trafficlights.h"
#include <QDebug>
#include "mainwindow.h"

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


void TrafficLights::resizeEvent(QResizeEvent* event)

{
 qDebug() << "trafficlights resize event";
 QSize size=this->size();
 qDebug() << "size:" << size ;
 const QSize BUTTON_SIZE = QSize(100, 100);
 LightsButton->resize(size);

 EditWindow *editWindow = mainWindowPtr->getEditWindow();

 if (editWindow) {
      qDebug() << "editwindow eesizing";
     int newWidth = size.width() * 0.5;
     int newHeight = size.height() * 0.3;
     editWindow->resize(newWidth, newHeight); // Muuta kokoa
 }

QWidget::resizeEvent(event); // Ku

}

void TrafficLights::showTime()
{
   static int stateflag=2;

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
void TrafficLights::setMainWindow(MainWindow *mainWindowPtr)
{
    this->mainWindowPtr = mainWindowPtr;
}

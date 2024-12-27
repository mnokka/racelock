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
 //const QSize BUTTON_SIZE = QSize(100, 100);

 QString h=CalcFont();

 if ( stateflag==2) {
     LightsButton->setStyleSheet("background-color: red;font-size: "+h+"px;height: 48px;width: 120px;");
     LightsButton->setText("     WAIT    ");
 }

 if ( stateflag==1) {
     LightsButton->setStyleSheet("background-color: green;font-size: "+h+"px;height: 48px;width: 120px;");
     LightsButton->setText("     GO     ");
 }

 if ( stateflag==0) {
     LightsButton->setStyleSheet("background-color: yellow;font-size: "+h+"px;height: 48px;width: 120px;");
     LightsButton->setText("     READY     ");
 }

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
   //static int stateflag=2;

    counter=counter+1;
    QString h=CalcFont();
   QString bibNumber;

    if (mainWindowPtr) {
        bibNumber = mainWindowPtr->GetBib();
        qDebug() << "Retrieved bib number:" << bibNumber;
    } else {
        qDebug() << "mainWindowPtr is null. Cannot call getBib.";
    }

    QString message="Lights, Bib: "+bibNumber+" -->";

    qDebug() << "steptime" << steptime;
    if (counter>=steptime+1) {
        counter=0;
        LightsButton->setStyleSheet("background-color: green;font-size: "+h+"px;height: 48px;width: 120px;");
        LightsButton->setText("     GO     ");
        stateflag=1;
        message=message+"GO";
        qDebug() << "GO event: "<< message;
        emit TrafficLightChanged(message);
    }
    if (counter>=2 and counter <steptime-10 and stateflag==1) {

        LightsButton->setStyleSheet("background-color: red;font-size: "+h+"px;height: 48px;width: 120px;");
        LightsButton->setText("     WAIT    ");
        stateflag=2;
        message=message+"WAIT";
        //qDebug() << "WAIT event: "<< message;
        emit TrafficLightChanged(message);
    }

    if (counter>steptime-10 and counter <steptime+1 and stateflag==2) {

        LightsButton->setStyleSheet("background-color: yellow;font-size: "+h+"px;height: 48px;width: 120px;");
        LightsButton->setText("     READY     ");
        stateflag=0;
        message=message+"READY";
        //qDebug() << "READY event: "<< message;
        emit TrafficLightChanged(message);
    }
}
void TrafficLights::setMainWindow(MainWindow *mainWindowPtr)
{
    this->mainWindowPtr = mainWindowPtr;

    bool connected = connect(this, SIGNAL(TrafficLightChanged(QString)),
                             mainWindowPtr, SLOT(logger(QString)));
    if (connected) {
        qDebug() << "Signal TrafficLightChanged successfully connected to MainWindow::logger.";
    } else {
        qDebug() << "Failed to connect TrafficLightChanged to MainWindow::logger.";
    }
}


QString TrafficLights::CalcFont() {
    QSize size=this->size();
    int height= size.height() ;
    // int weight =size.width()/2 ;
    height=height*coeff;
    QString h;
    h.setNum(height);
    return h;
}

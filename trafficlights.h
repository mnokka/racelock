#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H


#include <QLCDNumber>
#include <QDialog>
#include "parameters.h"

class TrafficLights : public QDialog
{
    Q_OBJECT

public:
    TrafficLights(QWidget *parent = 0);
    int counter=0;
    QPushButton *LightsButton;
    int steptime=STEPTIME;


private slots:
    void showTime();
    void resizeEvent(QResizeEvent*);


};
#endif // TRAFFICLIGHTS_H

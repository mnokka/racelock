#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H


#include <QLCDNumber>
#include <QDialog>

class TrafficLights : public QDialog
{
    Q_OBJECT

public:
    TrafficLights(QWidget *parent = 0);
    int counter=0;
    QPushButton *LightsButton;

private slots:
    void showTime();

};
#endif // TRAFFICLIGHTS_H

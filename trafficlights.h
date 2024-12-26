#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H


#include <QLCDNumber>
#include <QDialog>
#include "parameters.h"
//#include "mainwindow.h"

class MainWindow;

class TrafficLights : public QDialog
{
    Q_OBJECT

public:
    TrafficLights(QWidget *parent = 0);
    int counter=0;
    QPushButton *LightsButton;
    int steptime=STEPTIME;

    void setMainWindow(MainWindow *mainWindowPtr);

private slots:
    void showTime();

private:
   MainWindow *mainWindowPtr = nullptr;


protected:
    void resizeEvent(QResizeEvent *event) override;

};
#endif // TRAFFICLIGHTS_H

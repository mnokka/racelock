// Racelock inspired by Algae timing equipmwnt
// by mika.nokka1@gmail.com
//



#include <QApplication>
#include <QPushButton>

#include <QApplication>
#include <QtWidgets>
#include "raceclock.h"
#include "counterclock.h"
#include "trafficlights.h"
#include "parameters.h"
#include "mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;

    RaceClock clock;
    CounterClock CounterClock;
    TrafficLights TrafficLights;


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(&clock);
    layout->addWidget(&CounterClock);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(&TrafficLights);

    QWidget *centralWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(layout2);

    window.setCentralWidget(centralWidget);
    int steptime=STEPTIME;
    QString title;
    QTextStream(&title) << "Raceclock by MNokka2021       ** SENDING INTERVAL:"  << steptime <<" SECONDS **";
    window.setWindowTitle(title);
    window.show();
    window.SetLog();

    clock.show();



    return a.exec();
}

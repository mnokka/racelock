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




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //QPushButton hello( "Hello world!", 0 );
    //hello.resize( 100, 30
    //hello.show();

    QWidget window;
    RaceClock clock;
    CounterClock CounterClock;
    TrafficLights TrafficLights;

    QVBoxLayout *layout = new QVBoxLayout();
    //QLineEdit *lineEdit = new QLineEdit();
    //layout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(&clock);
    layout->addWidget(&CounterClock);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(&TrafficLights);
    //layout2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(layout2);

    window.setLayout(mainLayout);
    int steptime=STEPTIME;
    QString title;
    QTextStream(&title) << "Raceclock by MNokka2021       ** SENDING INTERVAL:"  << steptime <<" SECONDS **";
    window.setWindowTitle(title);
    window.show();



    clock.show();
    return a.exec();
}

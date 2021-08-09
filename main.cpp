
#include <QApplication>
#include <QPushButton>

#include <QApplication>
#include <QtWidgets>
#include "raceclock.h"
#include "counterclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //QPushButton hello( "Hello world!", 0 );
    //hello.resize( 100, 30
    //hello.show();

    QWidget window;
    RaceClock clock;
    CounterClock CounterClock;

    QHBoxLayout *layout = new QHBoxLayout(&window);
    QLineEdit *lineEdit = new QLineEdit();
    layout->addWidget(&clock);
    layout->addWidget(&CounterClock);
    window.setLayout(layout);

    window.show();


    clock.show();
    return a.exec();
}


#include <QApplication>
#include <QPushButton>

#include <QApplication>
#include "raceclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //QPushButton hello( "Hello world!", 0 );
    //hello.resize( 100, 30 );

    //hello.show();
    RaceClock clock;
    clock.show();
    return a.exec();
}

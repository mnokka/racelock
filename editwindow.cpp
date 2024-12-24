
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QtWidgets>

#include "editwindow.h"
#include <QDebug>
#include "mainwindow.h"

EditWindow::EditWindow(QWidget *parent)
    : QWidget(parent)
{
    echoLineEdit = new QLineEdit;

    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
    setLayout(echoLayout);

    setWindowTitle(tr("Next Bib number"));


    connect(echoLineEdit, SIGNAL(returnPressed()),
            this, SLOT(returnPressing()));

    qDebug() << "editwindow read memeptr:" << parentptr;

    connect(this, SIGNAL(GotBibNumber(QString)),
            parentptr, SLOT(RedoTitle(QString)));

}


void EditWindow::returnPressing()
{
    qDebug() << "Enterpressed:";

    QString bibline;
    bibline=echoLineEdit->text();
    qDebug() << "bibline:" << bibline;

    if (parentptr) { // Varmista, että MainWindow-osoitin on asetettu
        parentptr->setBibNumber(bibline); // Päivitä MainWindow:n BibNumber
    }

    //BibNumber = bibline; // extern
    echoLineEdit->clear();
    emit GotBibNumber(bibline);
}


void EditWindow::SetParentWindow(MainWindow *ptr) {
    //parentptr = ptr;
    parentptr = ptr;
    qDebug() << "set parentptr as:" << ptr;
    qDebug() << "read parentptr back:" << parentptr;
}

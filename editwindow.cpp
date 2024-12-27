
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QtWidgets>

#include "editwindow.h"
#include <QDebug>
#include "mainwindow.h"

EditWindow::EditWindow(QWidget *parent)
    : QWidget(parent), parentptr(nullptr)
{
    echoLineEdit = new QLineEdit;

    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
    setLayout(echoLayout);
    setWindowTitle(tr("Next Bib number"));

    resize(400, 120);

    EditLinePtr=this;
    echoLineEdit->setFocus();
    connect(echoLineEdit, &QLineEdit::returnPressed, this, &EditWindow::returnPressing);
}


void EditWindow::returnPressing()
{
    qDebug() << "Enterpressed:";

    QString bibline;
    QString message;
    bibline=echoLineEdit->text();
    qDebug() << "bibline:" << bibline;

    if (parentptr) {
        parentptr->setBibNumber(bibline);
        message="Bib number changed to:"+bibline;
        qDebug() << "Going to emit:" <<message;
        emit BibChanged(message);
    } else {
        qDebug() << "ERROR: Parent pointer not set!";
    }

    echoLineEdit->clear();
    close(); // Sulje ikkuna syötön jälkeen
}


void EditWindow::SetParentWindow(MainWindow *ptr) {
    //parentptr = ptr;
    parentptr = ptr;
    qDebug() << "set parentptr as:" << ptr;
    qDebug() << "read parentptr back:" << parentptr;

    if (parentptr) {
        //connect(this, &EditWindow::BibChanged, parentptr, &MainWindow::RedoTitle);
        connect(this, &EditWindow::BibChanged, parentptr, &MainWindow::logger);
        qDebug() << "GotBibNumber connected to RedoTitle";
    } else {
        qDebug() << "ERROR: parentptr is null in SetParentWindow!";
    }

}


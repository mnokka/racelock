
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
    bibline=echoLineEdit->text();
    qDebug() << "bibline:" << bibline;

    if (parentptr) {
        parentptr->setBibNumber(bibline);
        emit GotBibNumber(bibline);
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
        connect(this, &EditWindow::GotBibNumber, parentptr, &MainWindow::RedoTitle);
    }
}


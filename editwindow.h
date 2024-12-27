#ifndef EDITWINDOW_H
#define EDITWINDOW_H


#include <QWidget>
#include "mainwindow.h"


class EditWindow : public QWidget
{
    Q_OBJECT  // slotteja varten

public:

    EditWindow(QWidget *parent = 0);
    void SetParentWindow(MainWindow *ptr);
    EditWindow *EditLinePtr;

signals:
    void BibChanged(QString);

public slots:
    void returnPressing(void);

private:
    QLineEdit *echoLineEdit;
    MainWindow *parentptr;

};


#endif // EDITWINDOW_H



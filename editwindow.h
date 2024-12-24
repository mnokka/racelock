#ifndef EDITWINDOW_H
#define EDITWINDOW_H


#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
QT_END_NAMESPACE

class EditWindow : public QWidget
{
    Q_OBJECT  // slotteja varten, kts kanuunapeliĆ¤

public:

    EditWindow(QWidget *parent = 0);
    void SetParentWindow(MainWindow *ptr);

signals:
    void GotBibNumber(QString);

public slots:
    void returnPressing(void);

protected:

private:
    QLineEdit *echoLineEdit;
    MainWindow *parentptr;

};


#endif // EDITWINDOW_H



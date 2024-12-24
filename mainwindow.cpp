#include "mainwindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    memeptr=this;
    connect(this, SIGNAL(GotLogMessage(QString)),
            this, SLOT(logger(QString)));

    connect(this, SIGNAL(BibChanged(QString)),
            this, SLOT(logger(QString)));

    connect(this, SIGNAL(SettingsChanged(QString)),
            this, SLOT(logger(QString)));
}

MainWindow::~MainWindow()
{
    fileptr->close();
    delete fileptr;


}

void MainWindow::SetLog(void) {


    QTime time = QTime::currentTime();
    QString timetext = time.toString("hh-mm-ss");
    //qDebug() << "text time:" << timetext;
    QDate date= QDate::currentDate();
    QString datestring=date.toString(Qt::ISODate);
    //qDebug() << "datestring:" << datestring;
    filename="RACE_CLOCK_"+datestring+"_"+timetext+".log";
    qDebug() << "filename:" << filename;

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTime>
#include <QDate>
#include <QPushButton>
#include <QMenuBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFileDialog>


    class MainWindow : public QMainWindow
    {

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        //int steptime=30;
        //int GetStepTime(void);
        void SetLog(void);
        void createActions(void);
        void createMenus(void);
        void setBibNumber(const QString &newBibNumber);
    private:
        QFile *fileptr;
        QString filename;

        QMenu *helpMenu;
        QAction *aboutAct;

        QMenu *SettingsMenu;
        QAction *aboutSet;

        QMenu *BibMenu;
        QAction *aboutBib;


        QMenu *LogMenu;
        QAction *aboutLog;

        QString version="1.0";


        //const int STEPTIME=30;
        int steptime=15;
        int ClockStepTime=steptime;
        QString BibNumber="none";

        QMainWindow *memeptr=nullptr;

    private slots:
        void about();
        void settings();
        void bib();
        void log();
        void logger(QString message);

    signals:
        void GotLogMessage(QString);
        void BibChanged(QString);
        void SettingsChanged(QString);
        void RedoTitle(QString);

    };
#endif // MAINWINDOW_H

    QFile file(filename);

    fileptr=&file;

    if (fileptr->open(QIODevice::ReadWrite)) {

        // qDebug() << "fileptr:" << fileptr;
        // qDebug() << "file:" << &file;
        // qDebug() << "*fileptr:" << *fileptr;

        QTextStream mystream(fileptr);
        //mystream << "something" << endl;
        QString message;
        message="Created initial log file: " + filename;
        qDebug() << "message:" << message;

        emit GotLogMessage(message);
        QString steptime=QString::number(ClockStepTime);
        message="Send delay:" + steptime+ "  Bib:"+BibNumber;
        emit GotLogMessage(message);
    } else
        qDebug() << "Debug file open error";

}




void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutSet = new QAction(tr("&Settings"), this);
    aboutSet->setStatusTip(tr("Settings box"));
    connect(aboutSet, &QAction::triggered, this, &MainWindow::settings);

    aboutBib = new QAction(tr("&Bib"), this);
    aboutBib->setStatusTip(tr("Bib box"));
    connect(aboutBib, &QAction::triggered, this, &MainWindow::bib);

    aboutLog = new QAction(tr("&Log"), this);
    aboutLog->setStatusTip(tr("Log box"));
    connect(aboutLog, &QAction::triggered, this, &MainWindow::log);


}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);

    helpMenu = menuBar()->addMenu(tr("&Settings"));
    helpMenu->addAction(aboutSet);

    helpMenu = menuBar()->addMenu(tr("&Bib"));
    helpMenu->addAction(aboutBib);

    helpMenu = menuBar()->addMenu(tr("&Log"));
    helpMenu->addAction(aboutLog);

}

void MainWindow::about()
{

    /*    QMessageBox::about(this, tr("About the author and application <br>"
            "Software replacment for hardware based race clocks<br>"
               "(c) Mika Nokka 2021. <br> Development version, not licenced version: ",tr(version));
*/

    QMessageBox msgBox;
    msgBox.setWindowTitle("About the author and application");
    msgBox.setText("Software replacment for hardware based race clock");
    msgBox.setInformativeText("(c) Mika Nokka 2021 (mika.nokka1@gmail.com)<br>VERSION: "+version+"...NOT LICENCED...");
    msgBox.setStandardButtons(QMessageBox::Ok);;
    msgBox.exec();

}

void MainWindow::settings()
{
    //QMessageBox msgBox;
    //msgBox.setWindowTitle("Settings window");
    //msgBox.setText("TBD settings settings");
    //msgBox.setInformativeText("TBD settings setting");
    //msgBox.setStandardButtons(QMessageBox::Ok);
    //int ret = msgBox.exec();

    bool ok;
    int i = QInputDialog::getInt(this, tr("Set delay between starters"),
                                 tr("Delay in sec:"), ClockStepTime, steptime, 999, 1, &ok);
    if (ok) {
        ClockStepTime=i;
        // qDebug() << "ClockStepTime:" << ClockStepTime;

        QString title;
        QTextStream(&title) << "Send delay: "  << ClockStepTime <<" secs     Next BIB:" << BibNumber ;
        setWindowTitle(title);

        QString steptime=QString::number(ClockStepTime);
        QString  message="Send delay:" + steptime+ " Bib:"+BibNumber;
        emit GotLogMessage(message);
    }
    else {

    }

}

void MainWindow::bib() {
    // QMessageBox msgBox;myBibNumber
    // msgBox.setWindowTitle("Settings window");
    // msgBox.setText("TBD settings settings");
    // msgBox.setInformativeText("TBD settings setting");
    // msgBox.setStandardButtons(QMessageBox::Ok);
    // int ret = msgBox.exec();


    /* bool ok;
     QString text = QInputDialog::getText(this, tr("BIB"),
                                          tr("Next Bib number:"), QLineEdit::Normal,
                                          "", &ok);
     if (ok && !text.isEmpty()) {
         BibNumber = text;
         QString title;
           QTextStream(&title) << "Send delay: "  << ClockStepTime <<" secs     Next BIB:" << BibNumber ;
          setWindowTitle(title);
         qDebug() << "text:" << BibNumber;
     }
     */

    //meptr = this; // class variable
    //memeptr=this; //extern
    //qDebug() << "main read memeptr:" << memeptr;
    EditWindow *editWindow = new EditWindow;
    editWindow->SetParentWindow(this); // now used in crfeation, thus not avaialble there
    //qDebug() << "main: SetParentWindow:" << this;

    editWindow->show();




}

void MainWindow::log() {

    /*bool ok;
     QString text = QInputDialog::getText(this, tr("Logging"),
                                          tr("Give log file name:"), QLineEdit::Normal,
                                          "", &ok);
     if (ok && !text.isEmpty()) {
         qDebug() << "text:" << text;
     }
*/

    QString NewfileName = QFileDialog::getSaveFileName(this, "",
                                                       "","");


    if (!NewfileName.isEmpty()) {
        qDebug() << "NewfileName:" << NewfileName;

        QFile file(NewfileName);
        if (file.open(QIODevice::ReadWrite)) {

            QDate date= QDate::currentDate();
            QString datestring=date.toString(Qt::ISODate);

            QString message;
            message=datestring + "--> Created user selected log file: "+ NewfileName  ;
            filename = NewfileName; // global
            emit GotLogMessage(message);

            QString steptime=QString::number(ClockStepTime);
            message="Send delay:" + steptime+ "  Bib:"+BibNumber;
            emit GotLogMessage(message);


        } else
            qDebug() << "file open error";

    }

}

//slot
void MainWindow::RedoTitle(QString myBibnumber) {
    QString title;
    QTextStream(&title) << "Send delay: "  << ClockStepTime <<" secs     Next BIB:" << myBibnumber ;
    setWindowTitle(title);
    QString message;
    message="Bib number: " + myBibnumber +" added";
    qDebug() << message;
    emit BibChanged(message);
    //qDebug() << "newbibnumber in title:" << myBibnumber;
}



void MainWindow::logger(QString message) {
    QTime time = QTime::currentTime();
    QString timetext = time.toString("hh:mm:ss");

    QFile file(filename);
    fileptr=&file;

    if (fileptr->open(QIODevice::ReadWrite| QIODevice::Append )) {

        QTextStream mystream(fileptr);
        // qDebug() << "logger fileptr:" << fileptr;
        // qDebug() << "logger *fileptr:" << *fileptr;
        qDebug() << "logger got:" << message;

        mystream <<timetext<< " --> "<< message << endl;
    }
}


void MainWindow::setBibNumber(const QString &newBibNumber) {
    BibNumber = newBibNumber;
}

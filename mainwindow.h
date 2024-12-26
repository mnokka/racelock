#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trafficlights.h"
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
//#include "editwindow.h"

class EditWindow;

class MainWindow : public QMainWindow
{
        Q_OBJECT // for signals

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetLog(void);
    void createActions(void);
    void createMenus(void);
    void setBibNumber(const QString &newBibNumber);
    void RedoTitle(const QString &newBibNumber);
    void setEditWindow(EditWindow *ptr); // Setter
    EditWindow* getEditWindow() const;  // Getter
    MainWindow* GetMainWindow() const;

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

    MainWindow *memeptr=nullptr;

    EditWindow *editWindowPtr = nullptr;

    TrafficLights *trafficLightsPtr = nullptr;

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


};
#endif // MAINWINDOW_H

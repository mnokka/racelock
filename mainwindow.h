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
        Q_OBJECT // for signals

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
    void RedoTitle(QString);

signals:
    void GotLogMessage(QString);
    void BibChanged(QString);
    void SettingsChanged(QString);


};
#endif // MAINWINDOW_H

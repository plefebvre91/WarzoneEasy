#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "filewriter.h"
#include "errors.h"

#define WE_APP_TITLE "WarzoneEasy"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void apply();
    void chooseFile();

private:
    void displayMessage(int msgType, const char* msg);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

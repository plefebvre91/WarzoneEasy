#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(WE_APP_TITLE);

    ui->btnApply->setEnabled(false);
    QObject::connect(ui->btnApply, SIGNAL(clicked()), this, SLOT(apply()));
    QObject::connect(ui->btnFilePath, SIGNAL(clicked()), this, SLOT(chooseFile()));
    QObject::connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::apply(){
    QFile f(ui->txtFilePath->text());

    if(ui->txtFilePath->text().isEmpty())
    {
        displayMessage(WE_ERROR, WE_EMPTY_FILE);
        return;
    }

    if(!f.exists())
    {
        displayMessage(WE_ERROR, WE_FILE_DOESNT_EXIST);
        return;
    }


    FileWriter fw(ui->txtFilePath->text().toStdString().c_str());
    int power = ui->sldPower->value();

    if(fw.setPower(power) != FW_ERROR)
    {
        displayMessage(WE_INFO, WE_FILE_UPDATED);
        ui->btnApply->setEnabled(false);
    }
    else
    {
        displayMessage(WE_ERROR, WE_UNKNOWN_ERROR);
    }
}

void MainWindow::chooseFile(){
    QString s = QFileDialog::getOpenFileName(this,
         "Open saved game", "/home/pierre/.warzone2100-3.1/savegames/campaign/", "Game Files (*.gam)");
    ui->txtFilePath->setText(s);


    ui->btnApply->setEnabled(true);
    FileWriter fw(s.toStdString().c_str());

    int currentPower = fw.getPower();

    if(currentPower == FW_ERROR)
    {
        displayMessage(WE_INFO, WE_FILE_UPDATED);
        ui->btnApply->setEnabled(false);
    }

    ui->sldPower->setValue(currentPower);
    ui->lblPower->setNum((int)currentPower);

}

void MainWindow::displayMessage(int msgType, const char* msg) {
    QMessageBox messageBox;

    if(msgType == WE_ERROR)
    {
        messageBox.critical(0,WE_APP_TITLE, msg);
    }
    else
    {
        messageBox.information(0,WE_APP_TITLE, msg);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


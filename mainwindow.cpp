#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->btnApply, SIGNAL(clicked()), this, SLOT(apply()));
    QObject::connect(ui->btnFilePath, SIGNAL(clicked()), this, SLOT(chooseFile()));
    QObject::connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));

    ui->statusBar->setStatusTip(QString("lol"));

}

void MainWindow::apply(){
    FileWriter fw(ui->txtFilePath->text().toStdString().c_str());

    unsigned short power = (unsigned short)ui->sldPower->value();
    fw.setPower(power);
    ui->statusBar->setStatusTip(QString("Valeur mise a jour"));

}

void MainWindow::chooseFile(){
    QString s = QFileDialog::getOpenFileName(this,
         "Open saved game", "/home/pierre/.warzone2100-3.1/savegames/campaign/", "Game Files (*.gam)");
    ui->txtFilePath->setText(s);

    FileWriter fw(s.toStdString().c_str());

    unsigned int currentPower = fw.getPower();

    QMessageBox mb;
    mb.setText(QString((unsigned)currentPower));
    mb.exec();

    ui->sldPower->setValue(currentPower);
    ui->lblPower->setNum((int)currentPower);

}

MainWindow::~MainWindow()
{
    delete ui;
}


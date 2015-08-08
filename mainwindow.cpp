/*
    GUI main class code
    Copyright (C) 2015  Pierre Lefebvre

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set title
    this->setWindowTitle(WE_APP_TITLE);

    ui->btnApply->setEnabled(false);

    // Connect signals/slots
    QObject::connect(ui->btnApply, SIGNAL(clicked()), this, SLOT(apply()));
    QObject::connect(ui->btnFilePath, SIGNAL(clicked()), this, SLOT(chooseFile()));
    QObject::connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::apply(){

    // Display error message if text field is empty
    if(ui->txtFilePath->text().isEmpty())
    {
        displayMessage(WE_ERROR, WE_EMPTY_FILE);
        return;
    }

    // Display error message if file doesn't exist
    QFile f(ui->txtFilePath->text());
    if(!f.exists())
    {
        displayMessage(WE_ERROR, WE_FILE_DOESNT_EXIST);
        return;
    }

    // Open the game file and write the value from slider
    FileWriter fw(ui->txtFilePath->text().toStdString().c_str());
    int power = ui->sldPower->value();

    // Display error message if update failed or success message otherwise
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

    // Build the warzone game files directory
    QString dir(getenv("HOME"));
    dir.append(WE_WARZONE_DIR);

    // Get the filename from a file chooser dialog
    QString s = QFileDialog::getOpenFileName(this, "Open saved game", dir, "Game Files (*.gam)");

    if(s.isEmpty())
    {
        displayMessage(WE_ERROR, WE_EMPTY_FILE);
        return;
    }

    // Update text field
    ui->txtFilePath->setText(s);

    // Update 'apply' button state
    ui->btnApply->setEnabled(true);

    // Open the game file
    FileWriter fw(s.toStdString().c_str());

    // Get the current power resource value
    int currentPower = fw.getPower();

    // Return if it's failed
    if(currentPower == FW_ERROR)
    {
        displayMessage(WE_INFO, WE_FILE_UPDATED);
        ui->btnApply->setEnabled(false);
        return;
    }

    // Update slider and label value
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


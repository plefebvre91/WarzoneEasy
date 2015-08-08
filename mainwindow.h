/*
    GUI Main class
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "filewriter.h"
#include "errors.h"

#define WE_APP_TITLE "WarzoneEasy"
#define WE_WARZONE_DIR "/.warzone2100-3.1/savegames/campaign/"
namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
     * @brief Write the new values in the file
     */
    void apply();

    /**
     * @brief Open a file chooser dialog and updates slider value
     */
    void chooseFile();

private:
    /**
     * @brief displayMessage displays an info or error message
     * @param msgType WE_INFO or WE_ERROR
     * @param msg Message to display
     */
    void displayMessage(int msgType, const char* msg);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

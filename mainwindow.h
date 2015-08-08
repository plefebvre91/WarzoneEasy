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

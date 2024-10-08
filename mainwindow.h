#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QFileDialog>  // used to create dialog boxes allow users to select files or dir
#include <QTextStream>
#include "finddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionSave_as_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_notepad_triggered();

    void on_actionCopy_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionZoom_in_triggered();

    void on_actionZoom_out_triggered();

private:
    Ui::MainWindow *ui;
    QString _filePath;
};
#endif // MAINWINDOW_H

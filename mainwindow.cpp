#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define TIME_OUT_10_SECONDS 10000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _filePath = "";
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QString data = ui->textEdit->toPlainText();
    bool haveDataOnUi = data != "";

    if (haveDataOnUi)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                                  "Do you want to save your work?",
                                                                  "There are unsave changes in your note",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            MainWindow::on_actionSave_triggered();
        }
        else
        {
            _filePath = "";
        }
    }
    ui->textEdit->setText("");
    ui->statusbar->showMessage("Created new file", TIME_OUT_10_SECONDS);
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(file_name);
    _filePath = file_name;
    if (file.open(QIODevice::ReadOnly))
    {
        /* With QTextStream */
        // QTextStream stream(&file);
        // QString text = stream.readAll();
        // ui->textEdit->setText(text);

        /* Without QTextStream */
        QString text = file.readAll();
        ui->textEdit->setText(text);

        file.close();
        ui->statusbar->showMessage("Opened a file", TIME_OUT_10_SECONDS);
    }
    else
    {
        QMessageBox::warning(this, "Warning open file", "File can not open");
        return;
    }
}


void MainWindow::on_actionSave_triggered()
{
    if (_filePath == "")
    {
        _filePath = QFileDialog::getSaveFileName(this, "Save the file");
    }
    QFile file(_filePath);
    // ui->textEdit->setText(file_name);

    if (file.open(QIODevice::WriteOnly))
    {
        /* With QTextStream */
        QTextStream stream(&file);
        QString data = ui->textEdit->toPlainText();
        stream << data;

        /* Without QTextStream */
        // QByteArray data;
        // data.append(ui->textEdit->toPlainText().toLocal8Bit());
        // file.write(data);

        file.flush();
        file.close();
        ui->statusbar->showMessage("Saved a file", TIME_OUT_10_SECONDS);
    }
    else
    {
        QMessageBox::warning(this, "Warning save file", "File can not save");
        return;
    }
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
    ui->statusbar->showMessage("Pasted the data", TIME_OUT_10_SECONDS);
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
    ui->statusbar->showMessage("Have some data need to be pasted");
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(file_name);
    _filePath = file_name;
    if (file.open(QIODevice::WriteOnly))
    {
        /* With QTextStream */
        QTextStream stream(&file);
        QString data = ui->textEdit->toPlainText();
        stream << data;

        /* Without QTextStream */
        // QByteArray data;
        // data.append(ui->textEdit->toPlainText().toLocal8Bit());
        // file.write(data);

        file.flush();
        file.close();
        ui->statusbar->showMessage("Saved a file", TIME_OUT_10_SECONDS);
    }
    else
    {
        QMessageBox::warning(this, "Warning save file", "File can not save");
        return;
    }
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
    ui->statusbar->showMessage("Undid the data", TIME_OUT_10_SECONDS);
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
    ui->statusbar->showMessage("Redid the data", TIME_OUT_10_SECONDS);
}


void MainWindow::on_actionAbout_notepad_triggered()
{
    QString aboutText;
    aboutText.append("Author: Maxham Nguyen\n");
    aboutText.append("Date: 05/10/2024\n");
    aboutText.append("(C) Notepad 1.0.0 (R)");
    QMessageBox::information(this, "About notepad", aboutText);
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
    ui->statusbar->showMessage("Have some data need to be pasted");
}


void MainWindow::on_actionFind_triggered()
{
    FindDialog *dlg = new FindDialog(this);
    if (!dlg->exec()) return;

    QTextDocument::FindFlags flags;
    if (dlg->isMatchCase()) flags = flags | QTextDocument::FindFlag::FindCaseSensitively;
    if (dlg->isWrapAround()) flags = flags | QTextDocument::FindFlag::FindWholeWords;
    if (dlg->isBackwards()) flags = flags | QTextDocument::FindFlag::FindBackward;

    bool value = ui->textEdit->find(dlg->text(), flags);
    if (!value) QMessageBox::information(this, "Not found", "Was not able to find " + dlg->text());
}


void MainWindow::on_actionReplace_triggered()
{

}


void MainWindow::on_actionZoom_in_triggered()
{
    ui->textEdit->zoomIn(1);
}


void MainWindow::on_actionZoom_out_triggered()
{
    ui->textEdit->zoomOut(1);
}


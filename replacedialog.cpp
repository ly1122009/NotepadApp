#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    _isReplaceAll = false;
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_buttonBox_accepted()
{
    accept();
}


void ReplaceDialog::on_pushButton_ReplaceAll_clicked()
{
    _isReplaceAll = true;
    _textToFind = ui->lineEdit_TextToFind->text();
    _textToReplace = ui->lineEdit_TextToReplace->text();
    accept();
}

void ReplaceDialog::on_pushButton_Replace_clicked()
{
    _isReplaceAll = false;
    _textToFind = ui->lineEdit_TextToFind->text();
    _textToReplace = ui->lineEdit_TextToReplace->text();
    accept();
}

QString ReplaceDialog::textToReplace() const
{
    return _textToReplace;
}

QString ReplaceDialog::textToFind() const
{
    return _textToFind;
}


void ReplaceDialog::on_buttonBox_rejected()
{
    reject();
}

void ReplaceDialog::setIsReplaceAll(bool newIsReplaceAll)
{
    _isReplaceAll = newIsReplaceAll;
}

void ReplaceDialog::setTextToReplace(const QString &newTextToReplace)
{
    _textToReplace = newTextToReplace;
}

void ReplaceDialog::setTextToFind(const QString &newTextToFind)
{
    _textToFind = newTextToFind;
}

bool ReplaceDialog::isReplaceAll() const
{
    return _isReplaceAll;
}


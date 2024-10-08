#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    _init();
    _save();
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_buttonBox_accepted()
{
    _save();
    accept();
}


void FindDialog::on_buttonBox_rejected()
{
    reject();
}

void FindDialog::_init()
{
    QPushButton *btnBack = new QPushButton("Find back", this);
    connect(btnBack, &QPushButton::clicked, this, &FindDialog::goBack);
    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ActionRole);
}

void FindDialog::_save()
{
    _text = ui->lineEdit_text->text();
    _isWrapAround = ui->checkBox_WrapAround->isChecked();
    _isMatchCase = ui->checkBox_MatchCase->isChecked();
    _isBackwards = false;
}

QString FindDialog::text() const
{
    return _text;
}

bool FindDialog::isMatchCase() const
{
    return _isMatchCase;
}

bool FindDialog::isWrapAround() const
{
    return _isWrapAround;
}


bool FindDialog::isBackwards() const
{
    return _isBackwards;
}

void FindDialog::goBack()
{
    _save();
    _isBackwards = true;
    accept();
}


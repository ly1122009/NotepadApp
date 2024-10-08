#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QString>
#include <QPushButton>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();


    bool isWrapAround() const;
    bool isMatchCase() const;

    QString text() const;

    bool isBackwards() const;

    void goBack();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();




private:
    Ui::FindDialog *ui;

    QString _text;
    bool _isWrapAround;
    bool _isMatchCase;
    bool _isBackwards;

    void _init();
    void _save();
};

#endif // FINDDIALOG_H

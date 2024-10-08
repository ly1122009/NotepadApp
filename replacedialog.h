#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

    QString textToFind() const;

    QString textToReplace() const;

    bool isReplaceAll() const;

    void setTextToFind(const QString &newTextToFind);

    void setTextToReplace(const QString &newTextToReplace);

    void setIsReplaceAll(bool newIsReplaceAll);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_ReplaceAll_clicked();

    void on_pushButton_Replace_clicked();

    void on_buttonBox_rejected();

private:
    Ui::ReplaceDialog *ui;

    bool _isReplaceAll;
    QString _textToFind;
    QString _textToReplace;
};

#endif // REPLACEDIALOG_H

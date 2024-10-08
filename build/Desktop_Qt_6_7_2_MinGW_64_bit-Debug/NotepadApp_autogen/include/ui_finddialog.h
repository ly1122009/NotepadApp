/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Find;
    QLineEdit *lineEdit_text;
    QCheckBox *checkBox_WrapAround;
    QCheckBox *checkBox_MatchCase;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        FindDialog->resize(686, 622);
        widget = new QWidget(FindDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(13, 13, 258, 208));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Find = new QLabel(widget);
        label_Find->setObjectName("label_Find");

        verticalLayout->addWidget(label_Find);

        lineEdit_text = new QLineEdit(widget);
        lineEdit_text->setObjectName("lineEdit_text");

        verticalLayout->addWidget(lineEdit_text);

        checkBox_WrapAround = new QCheckBox(widget);
        checkBox_WrapAround->setObjectName("checkBox_WrapAround");

        verticalLayout->addWidget(checkBox_WrapAround);

        checkBox_MatchCase = new QCheckBox(widget);
        checkBox_MatchCase->setObjectName("checkBox_MatchCase");

        verticalLayout->addWidget(checkBox_MatchCase);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FindDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FindDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FindDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Dialog", nullptr));
        label_Find->setText(QCoreApplication::translate("FindDialog", "Find", nullptr));
        checkBox_WrapAround->setText(QCoreApplication::translate("FindDialog", "Wrap around", nullptr));
        checkBox_MatchCase->setText(QCoreApplication::translate("FindDialog", "Match case", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H

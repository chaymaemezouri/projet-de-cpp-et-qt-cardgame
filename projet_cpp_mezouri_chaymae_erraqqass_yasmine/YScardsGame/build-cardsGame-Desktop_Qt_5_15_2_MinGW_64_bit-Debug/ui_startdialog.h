/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName(QString::fromUtf8("StartDialog"));
        StartDialog->resize(760, 492);
        StartDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        buttonBox = new QDialogButtonBox(StartDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 380, 191, 71));
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Open);
        label = new QLabel(StartDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 691, 295));
        label->setStyleSheet(QString::fromUtf8("image: url(:/background/cards/32f698cc91305a1e3e6ee0acbb527faa.png);"));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(StartDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 330, 211, 61));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);\n"
"font: 18pt \"Snap ITC\";\n"
""));

        retranslateUi(StartDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StartDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StartDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QCoreApplication::translate("StartDialog", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("StartDialog", "YS CARDS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H

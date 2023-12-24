/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *computer_score;
    QSpacerItem *horizontalSpacer;
    QLabel *computer_c3;
    QLabel *computer_c2;
    QLabel *computer_c1;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *player1_score;
    QSpacerItem *horizontalSpacer_2;
    ClickableLabel *player1_c1;
    ClickableLabel *player1_c3;
    ClickableLabel *player1_c2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *table_c3;
    QLabel *table_c2;
    QLabel *table_c1;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(933, 630);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        computer_score = new QLabel(centralWidget);
        computer_score->setObjectName(QString::fromUtf8("computer_score"));
        computer_score->setMinimumSize(QSize(70, 80));
        computer_score->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
""));

        horizontalLayout_5->addWidget(computer_score);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        computer_c3 = new QLabel(centralWidget);
        computer_c3->setObjectName(QString::fromUtf8("computer_c3"));
        computer_c3->setMinimumSize(QSize(70, 80));

        horizontalLayout_5->addWidget(computer_c3);

        computer_c2 = new QLabel(centralWidget);
        computer_c2->setObjectName(QString::fromUtf8("computer_c2"));
        computer_c2->setMinimumSize(QSize(70, 80));

        horizontalLayout_5->addWidget(computer_c2);

        computer_c1 = new QLabel(centralWidget);
        computer_c1->setObjectName(QString::fromUtf8("computer_c1"));
        computer_c1->setMinimumSize(QSize(70, 80));

        horizontalLayout_5->addWidget(computer_c1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        player1_score = new QLabel(centralWidget);
        player1_score->setObjectName(QString::fromUtf8("player1_score"));
        player1_score->setMinimumSize(QSize(70, 80));
        player1_score->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(player1_score);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        player1_c1 = new ClickableLabel(centralWidget);
        player1_c1->setObjectName(QString::fromUtf8("player1_c1"));
        player1_c1->setMinimumSize(QSize(70, 80));

        horizontalLayout_3->addWidget(player1_c1);

        player1_c3 = new ClickableLabel(centralWidget);
        player1_c3->setObjectName(QString::fromUtf8("player1_c3"));
        player1_c3->setMinimumSize(QSize(70, 80));

        horizontalLayout_3->addWidget(player1_c3);

        player1_c2 = new ClickableLabel(centralWidget);
        player1_c2->setObjectName(QString::fromUtf8("player1_c2"));
        player1_c2->setMinimumSize(QSize(70, 80));

        horizontalLayout_3->addWidget(player1_c2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        table_c3 = new QLabel(centralWidget);
        table_c3->setObjectName(QString::fromUtf8("table_c3"));
        table_c3->setMinimumSize(QSize(70, 80));

        horizontalLayout_4->addWidget(table_c3);

        table_c2 = new QLabel(centralWidget);
        table_c2->setObjectName(QString::fromUtf8("table_c2"));
        table_c2->setMinimumSize(QSize(70, 80));

        horizontalLayout_4->addWidget(table_c2);

        table_c1 = new QLabel(centralWidget);
        table_c1->setObjectName(QString::fromUtf8("table_c1"));
        table_c1->setMinimumSize(QSize(70, 80));

        horizontalLayout_4->addWidget(table_c1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ronda Card Game", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "restart", nullptr));
        computer_score->setText(QCoreApplication::translate("MainWindow", "Computer Score: 00", nullptr));
        computer_c3->setText(QString());
        computer_c2->setText(QString());
        computer_c1->setText(QString());
        player1_score->setText(QCoreApplication::translate("MainWindow", "Player score: 00", nullptr));
        player1_c1->setText(QString());
        player1_c3->setText(QString());
        player1_c2->setText(QString());
        table_c3->setText(QString());
        table_c2->setText(QString());
        table_c1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

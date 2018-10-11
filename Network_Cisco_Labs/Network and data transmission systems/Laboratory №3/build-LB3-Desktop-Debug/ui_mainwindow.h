/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *CodeHex;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *TestLable;
    QLabel *NRZ_Lable;
    QLabel *NRZ_Lable_2;
    QLabel *NRZ_Lable_3;
    QLabel *NRZ_Lable_4;
    QLabel *NRZ_Lable_5;
    QLabel *NRZ_Lable_6;
    QLabel *NRZ_Lable_7;
    QLabel *NRZ_Lable_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 651);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CodeHex = new QLineEdit(centralWidget);
        CodeHex->setObjectName(QStringLiteral("CodeHex"));
        CodeHex->setGeometry(QRect(110, 20, 131, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 20, 82, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 121, 16));
        TestLable = new QLabel(centralWidget);
        TestLable->setObjectName(QStringLiteral("TestLable"));
        TestLable->setEnabled(true);
        TestLable->setGeometry(QRect(10, 40, 641, 31));
        NRZ_Lable = new QLabel(centralWidget);
        NRZ_Lable->setObjectName(QStringLiteral("NRZ_Lable"));
        NRZ_Lable->setEnabled(true);
        NRZ_Lable->setGeometry(QRect(10, 140, 35, 15));
        NRZ_Lable_2 = new QLabel(centralWidget);
        NRZ_Lable_2->setObjectName(QStringLiteral("NRZ_Lable_2"));
        NRZ_Lable_2->setEnabled(true);
        NRZ_Lable_2->setGeometry(QRect(10, 200, 35, 15));
        NRZ_Lable_3 = new QLabel(centralWidget);
        NRZ_Lable_3->setObjectName(QStringLiteral("NRZ_Lable_3"));
        NRZ_Lable_3->setEnabled(true);
        NRZ_Lable_3->setGeometry(QRect(10, 260, 35, 15));
        NRZ_Lable_4 = new QLabel(centralWidget);
        NRZ_Lable_4->setObjectName(QStringLiteral("NRZ_Lable_4"));
        NRZ_Lable_4->setEnabled(true);
        NRZ_Lable_4->setGeometry(QRect(10, 320, 35, 15));
        NRZ_Lable_5 = new QLabel(centralWidget);
        NRZ_Lable_5->setObjectName(QStringLiteral("NRZ_Lable_5"));
        NRZ_Lable_5->setEnabled(true);
        NRZ_Lable_5->setGeometry(QRect(10, 380, 35, 15));
        NRZ_Lable_6 = new QLabel(centralWidget);
        NRZ_Lable_6->setObjectName(QStringLiteral("NRZ_Lable_6"));
        NRZ_Lable_6->setEnabled(true);
        NRZ_Lable_6->setGeometry(QRect(10, 440, 41, 16));
        NRZ_Lable_7 = new QLabel(centralWidget);
        NRZ_Lable_7->setObjectName(QStringLiteral("NRZ_Lable_7"));
        NRZ_Lable_7->setEnabled(true);
        NRZ_Lable_7->setGeometry(QRect(10, 510, 41, 16));
        NRZ_Lable_8 = new QLabel(centralWidget);
        NRZ_Lable_8->setObjectName(QStringLiteral("NRZ_Lable_8"));
        NRZ_Lable_8->setEnabled(true);
        NRZ_Lable_8->setGeometry(QRect(10, 570, 41, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 851, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\264", Q_NULLPTR));
        TestLable->setText(QApplication::translate("MainWindow", "\320\222 \320\264\320\262\320\276\320\270\321\207\320\275\320\276\320\274 \320\262\320\270\320\264\320\265", Q_NULLPTR));
        NRZ_Lable->setText(QApplication::translate("MainWindow", "NRZ", Q_NULLPTR));
        NRZ_Lable_2->setText(QApplication::translate("MainWindow", "NRZI", Q_NULLPTR));
        NRZ_Lable_3->setText(QApplication::translate("MainWindow", "\320\221\320\230\320\232", Q_NULLPTR));
        NRZ_Lable_4->setText(QApplication::translate("MainWindow", "\320\234\320\220\320\235", Q_NULLPTR));
        NRZ_Lable_5->setText(QApplication::translate("MainWindow", "B8ZS", Q_NULLPTR));
        NRZ_Lable_6->setText(QApplication::translate("MainWindow", "HDB3", Q_NULLPTR));
        NRZ_Lable_7->setText(QApplication::translate("MainWindow", "2B1Q", Q_NULLPTR));
        NRZ_Lable_8->setText(QApplication::translate("MainWindow", " \320\241\320\232\320\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

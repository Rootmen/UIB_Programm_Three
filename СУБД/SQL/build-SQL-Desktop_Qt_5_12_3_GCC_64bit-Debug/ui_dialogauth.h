/********************************************************************************
** Form generated from reading UI file 'dialogauth.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAUTH_H
#define UI_DIALOGAUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAuth
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *login;
    QLineEdit *pass;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *aut;
    QPushButton *abort;
    QProgressBar *progressBar;

    void setupUi(QDialog *DialogAuth)
    {
        if (DialogAuth->objectName().isEmpty())
            DialogAuth->setObjectName(QString::fromUtf8("DialogAuth"));
        DialogAuth->resize(497, 254);
        gridLayout = new QGridLayout(DialogAuth);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(DialogAuth);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        login = new QLineEdit(DialogAuth);
        login->setObjectName(QString::fromUtf8("login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, login);

        pass = new QLineEdit(DialogAuth);
        pass->setObjectName(QString::fromUtf8("pass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pass);

        label_2 = new QLabel(DialogAuth);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        label = new QLabel(DialogAuth);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        aut = new QPushButton(DialogAuth);
        aut->setObjectName(QString::fromUtf8("aut"));

        horizontalLayout->addWidget(aut);

        abort = new QPushButton(DialogAuth);
        abort->setObjectName(QString::fromUtf8("abort"));

        horizontalLayout->addWidget(abort);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        progressBar = new QProgressBar(DialogAuth);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);


        retranslateUi(DialogAuth);

        QMetaObject::connectSlotsByName(DialogAuth);
    } // setupUi

    void retranslateUi(QDialog *DialogAuth)
    {
        DialogAuth->setWindowTitle(QApplication::translate("DialogAuth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_3->setText(QApplication::translate("DialogAuth", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QApplication::translate("DialogAuth", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QApplication::translate("DialogAuth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        aut->setText(QApplication::translate("DialogAuth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        abort->setText(QApplication::translate("DialogAuth", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAuth: public Ui_DialogAuth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAUTH_H

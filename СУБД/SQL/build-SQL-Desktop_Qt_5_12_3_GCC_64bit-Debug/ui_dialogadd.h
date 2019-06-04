/********************************************************************************
** Form generated from reading UI file 'dialogadd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADD_H
#define UI_DIALOGADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAdd
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *count;
    QLabel *label_7;
    QLabel *label;
    QLineEdit *men;
    QLineEdit *id;
    QLineEdit *state;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *totalpop;
    QLineEdit *woman;
    QLabel *label_4;

    void setupUi(QDialog *DialogAdd)
    {
        if (DialogAdd->objectName().isEmpty())
            DialogAdd->setObjectName(QString::fromUtf8("DialogAdd"));
        DialogAdd->resize(370, 285);
        pushButton = new QPushButton(DialogAdd);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 250, 371, 33));
        formLayoutWidget = new QWidget(DialogAdd);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 371, 251));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        count = new QLineEdit(formLayoutWidget);
        count->setObjectName(QString::fromUtf8("count"));

        gridLayout->addWidget(count, 1, 1, 1, 1);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        men = new QLineEdit(formLayoutWidget);
        men->setObjectName(QString::fromUtf8("men"));

        gridLayout->addWidget(men, 4, 1, 1, 1);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 1, 1, 1);

        state = new QLineEdit(formLayoutWidget);
        state->setObjectName(QString::fromUtf8("state"));

        gridLayout->addWidget(state, 2, 1, 1, 1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        totalpop = new QLineEdit(formLayoutWidget);
        totalpop->setObjectName(QString::fromUtf8("totalpop"));

        gridLayout->addWidget(totalpop, 3, 1, 1, 1);

        woman = new QLineEdit(formLayoutWidget);
        woman->setObjectName(QString::fromUtf8("woman"));

        gridLayout->addWidget(woman, 5, 1, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        retranslateUi(DialogAdd);

        QMetaObject::connectSlotsByName(DialogAdd);
    } // setupUi

    void retranslateUi(QDialog *DialogAdd)
    {
        DialogAdd->setWindowTitle(QApplication::translate("DialogAdd", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("DialogAdd", "\320\224\320\276\320\261\320\260\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        label_2->setText(QApplication::translate("DialogAdd", "\320\250\321\202\320\260\321\202", nullptr));
        label_7->setText(QApplication::translate("DialogAdd", "\320\226\320\265\320\275\321\210\320\270\320\275", nullptr));
        label->setText(QApplication::translate("DialogAdd", "id", nullptr));
        label_5->setText(QApplication::translate("DialogAdd", "\320\234\321\203\320\266\321\207\320\270\320\275", nullptr));
        label_3->setText(QApplication::translate("DialogAdd", "\320\223\321\200\320\260\320\262.", nullptr));
        label_4->setText(QApplication::translate("DialogAdd", "\320\222\321\201\320\265\320\263\320\276 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAdd: public Ui_DialogAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADD_H

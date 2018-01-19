/********************************************************************************
** Form generated from reading UI file 'administrarecompetitiepage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRARECOMPETITIEPAGE_H
#define UI_ADMINISTRARECOMPETITIEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministrareCompetitiePage
{
public:
    QPushButton *b_back;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *AdministrareCompetitiePage)
    {
        if (AdministrareCompetitiePage->objectName().isEmpty())
            AdministrareCompetitiePage->setObjectName(QStringLiteral("AdministrareCompetitiePage"));
        AdministrareCompetitiePage->resize(304, 304);
        AdministrareCompetitiePage->setStyleSheet(QStringLiteral("background-color: rgb(77, 77, 77);"));
        b_back = new QPushButton(AdministrareCompetitiePage);
        b_back->setObjectName(QStringLiteral("b_back"));
        b_back->setGeometry(QRect(10, 10, 51, 18));
        b_back->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));
        widget = new QWidget(AdministrareCompetitiePage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 50, 141, 231));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        verticalLayout->addWidget(pushButton_5);


        retranslateUi(AdministrareCompetitiePage);

        QMetaObject::connectSlotsByName(AdministrareCompetitiePage);
    } // setupUi

    void retranslateUi(QDialog *AdministrareCompetitiePage)
    {
        AdministrareCompetitiePage->setWindowTitle(QApplication::translate("AdministrareCompetitiePage", "Dialog", Q_NULLPTR));
        b_back->setText(QApplication::translate("AdministrareCompetitiePage", "Back", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AdministrareCompetitiePage", "Adaugare categorie greutate", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AdministrareCompetitiePage", "Adaugare categorie varsta", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("AdministrareCompetitiePage", "Adaugare categorie gen", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("AdministrareCompetitiePage", "Adaugare club sportiv", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("AdministrareCompetitiePage", "Adaugare sportiv", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdministrareCompetitiePage: public Ui_AdministrareCompetitiePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRARECOMPETITIEPAGE_H

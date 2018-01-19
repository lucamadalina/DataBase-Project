/********************************************************************************
** Form generated from reading UI file 'campionat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMPIONAT_H
#define UI_CAMPIONAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Campionat
{
public:
    QPushButton *b_back;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *ad_Sportiv;
    QLabel *picture;

    void setupUi(QDialog *Campionat)
    {
        if (Campionat->objectName().isEmpty())
            Campionat->setObjectName(QStringLiteral("Campionat"));
        Campionat->resize(410, 319);
        Campionat->setStyleSheet(QStringLiteral("background-color: rgb(77, 77, 77);"));
        b_back = new QPushButton(Campionat);
        b_back->setObjectName(QStringLiteral("b_back"));
        b_back->setGeometry(QRect(10, 10, 51, 18));
        b_back->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));
        textEdit = new QTextEdit(Campionat);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 201, 27));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        textEdit_2 = new QTextEdit(Campionat);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 150, 201, 27));
        textEdit_2->setStyleSheet(QLatin1String("background-color: rgb(200, 200, 200);\n"
"color: rgb(255, 255, 255);"));
        textEdit_3 = new QTextEdit(Campionat);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 100, 201, 27));
        textEdit_3->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        textEdit_4 = new QTextEdit(Campionat);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 200, 201, 27));
        textEdit_4->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        textEdit_5 = new QTextEdit(Campionat);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(10, 250, 201, 26));
        textEdit_5->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label = new QLabel(Campionat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 96, 16));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Campionat);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 107, 16));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Campionat);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 68, 16));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Campionat);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 34, 16));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(Campionat);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 230, 45, 16));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(Campionat);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 100, 75, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));
        pushButton_2 = new QPushButton(Campionat);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 50, 136, 23));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));
        ad_Sportiv = new QPushButton(Campionat);
        ad_Sportiv->setObjectName(QStringLiteral("ad_Sportiv"));
        ad_Sportiv->setGeometry(QRect(280, 240, 75, 23));
        picture = new QLabel(Campionat);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(270, 150, 111, 71));
        picture->setBaseSize(QSize(250, 250));

        retranslateUi(Campionat);

        QMetaObject::connectSlotsByName(Campionat);
    } // setupUi

    void retranslateUi(QDialog *Campionat)
    {
        Campionat->setWindowTitle(QApplication::translate("Campionat", "Dialog", Q_NULLPTR));
        b_back->setText(QApplication::translate("Campionat", "Back", Q_NULLPTR));
        label->setText(QApplication::translate("Campionat", "Categoria de varsta", Q_NULLPTR));
        label_2->setText(QApplication::translate("Campionat", "Categoria de greutate", Q_NULLPTR));
        label_3->setText(QApplication::translate("Campionat", "Categoria gen", Q_NULLPTR));
        label_4->setText(QApplication::translate("Campionat", "Locatia", Q_NULLPTR));
        label_5->setText(QApplication::translate("Campionat", "Denumire", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Campionat", "Simulare lupte", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Campionat", "Adaugare Competitie noua", Q_NULLPTR));
        ad_Sportiv->setText(QApplication::translate("Campionat", "Adauga Sportiv", Q_NULLPTR));
        picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Campionat: public Ui_Campionat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMPIONAT_H

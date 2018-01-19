/********************************************************************************
** Form generated from reading UI file 'addsportiv.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSPORTIV_H
#define UI_ADDSPORTIV_H

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

class Ui_addSportiv
{
public:
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *id;
    QLabel *label_2;
    QTextEdit *nume;
    QLabel *label_3;
    QTextEdit *prenume;
    QLabel *label_10;
    QTextEdit *tara;
    QLabel *label_5;
    QTextEdit *varsta;
    QLabel *label_6;
    QTextEdit *greutate;
    QLabel *label_4;
    QTextEdit *gen;
    QPushButton *b_adSportiv;
    QLabel *label_7;
    QTextEdit *id_club;
    QPushButton *b_back;

    void setupUi(QDialog *addSportiv)
    {
        if (addSportiv->objectName().isEmpty())
            addSportiv->setObjectName(QStringLiteral("addSportiv"));
        addSportiv->resize(384, 343);
        addSportiv->setMaximumSize(QSize(471, 531));
        addSportiv->setStyleSheet(QStringLiteral("background-color: rgb(77, 77, 77);"));
        addSportiv->setSizeGripEnabled(true);
        label_8 = new QLabel(addSportiv);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 19, 66, 16));
        label_9 = new QLabel(addSportiv);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(39, 38, 16, 16));
        id = new QTextEdit(addSportiv);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(82, 38, 151, 21));
        id->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(addSportiv);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 27, 16));
        nume = new QTextEdit(addSportiv);
        nume->setObjectName(QStringLiteral("nume"));
        nume->setGeometry(QRect(80, 70, 151, 21));
        nume->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(addSportiv);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 42, 16));
        prenume = new QTextEdit(addSportiv);
        prenume->setObjectName(QStringLiteral("prenume"));
        prenume->setGeometry(QRect(80, 100, 151, 21));
        prenume->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(addSportiv);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 130, 22, 16));
        tara = new QTextEdit(addSportiv);
        tara->setObjectName(QStringLiteral("tara"));
        tara->setGeometry(QRect(80, 130, 151, 21));
        tara->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(addSportiv);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 160, 31, 16));
        varsta = new QTextEdit(addSportiv);
        varsta->setObjectName(QStringLiteral("varsta"));
        varsta->setGeometry(QRect(80, 160, 151, 21));
        varsta->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(addSportiv);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 190, 43, 16));
        greutate = new QTextEdit(addSportiv);
        greutate->setObjectName(QStringLiteral("greutate"));
        greutate->setGeometry(QRect(80, 190, 151, 21));
        greutate->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(addSportiv);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 220, 19, 16));
        gen = new QTextEdit(addSportiv);
        gen->setObjectName(QStringLiteral("gen"));
        gen->setGeometry(QRect(80, 220, 152, 21));
        gen->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        b_adSportiv = new QPushButton(addSportiv);
        b_adSportiv->setObjectName(QStringLiteral("b_adSportiv"));
        b_adSportiv->setGeometry(QRect(120, 290, 75, 23));
        b_adSportiv->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        b_adSportiv->setAutoDefault(false);
        label_7 = new QLabel(addSportiv);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 250, 71, 16));
        id_club = new QTextEdit(addSportiv);
        id_club->setObjectName(QStringLiteral("id_club"));
        id_club->setGeometry(QRect(120, 250, 111, 21));
        id_club->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        b_back = new QPushButton(addSportiv);
        b_back->setObjectName(QStringLiteral("b_back"));
        b_back->setGeometry(QRect(10, 10, 51, 18));
        b_back->setStyleSheet(QStringLiteral("background-color: rgba(200, 200, 200, 200);"));

        retranslateUi(addSportiv);

        QMetaObject::connectSlotsByName(addSportiv);
    } // setupUi

    void retranslateUi(QDialog *addSportiv)
    {
        addSportiv->setWindowTitle(QApplication::translate("addSportiv", "Dialog", Q_NULLPTR));
        label_8->setText(QApplication::translate("addSportiv", "Detalii Sportiv", Q_NULLPTR));
        label_9->setText(QApplication::translate("addSportiv", "Id", Q_NULLPTR));
        label_2->setText(QApplication::translate("addSportiv", "Nume", Q_NULLPTR));
        label_3->setText(QApplication::translate("addSportiv", "Prenume", Q_NULLPTR));
        label_10->setText(QApplication::translate("addSportiv", "Tara", Q_NULLPTR));
        label_5->setText(QApplication::translate("addSportiv", "Varsta", Q_NULLPTR));
        label_6->setText(QApplication::translate("addSportiv", "Greutate", Q_NULLPTR));
        label_4->setText(QApplication::translate("addSportiv", "Gen", Q_NULLPTR));
        b_adSportiv->setText(QApplication::translate("addSportiv", "Adauga", Q_NULLPTR));
        label_7->setText(QApplication::translate("addSportiv", "Id Club Sportiv", Q_NULLPTR));
        b_back->setText(QApplication::translate("addSportiv", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addSportiv: public Ui_addSportiv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSPORTIV_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *p_Clasament;
    QPushButton *p_AdCompetitie;
    QPushButton *p_AdCampionat;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(521, 334);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(77, 77, 77);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(112, 62, 301, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        p_Clasament = new QPushButton(layoutWidget);
        p_Clasament->setObjectName(QStringLiteral("p_Clasament"));
        p_Clasament->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);\n"
"font: 75 14pt \"Arial\";"));

        verticalLayout->addWidget(p_Clasament);

        p_AdCompetitie = new QPushButton(layoutWidget);
        p_AdCompetitie->setObjectName(QStringLiteral("p_AdCompetitie"));
        p_AdCompetitie->setStyleSheet(QLatin1String("font: 75 14pt \"Arial\";\n"
"background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(p_AdCompetitie);

        p_AdCampionat = new QPushButton(layoutWidget);
        p_AdCampionat->setObjectName(QStringLiteral("p_AdCampionat"));
        p_AdCampionat->setEnabled(true);
        p_AdCampionat->setStyleSheet(QLatin1String("font: 75 14pt \"Arial\";\n"
"background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(p_AdCampionat);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        p_Clasament->setText(QApplication::translate("MainWindow", "Clasament", Q_NULLPTR));
        p_AdCompetitie->setText(QApplication::translate("MainWindow", "Administrare Competitie", Q_NULLPTR));
        p_AdCampionat->setText(QApplication::translate("MainWindow", "Campionat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

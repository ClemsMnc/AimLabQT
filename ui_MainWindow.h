/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *appearancesPerMinute;
    QPushButton *startButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 300);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget { background-color: #f0f0f0; }"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8("color: #333333;"));

        verticalLayout->addWidget(label);

        appearancesPerMinute = new QSpinBox(centralWidget);
        appearancesPerMinute->setObjectName(QString::fromUtf8("appearancesPerMinute"));
        appearancesPerMinute->setMaximum(60);
        appearancesPerMinute->setStyleSheet(QString::fromUtf8("QSpinBox { color: #0055ff; }"));

        verticalLayout->addWidget(appearancesPerMinute);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #00cc44; color: white; border-radius: 5px; }"));

        verticalLayout->addWidget(startButton);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Accueil AimLab", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nombre d'apparitions par minute :", nullptr));
        appearancesPerMinute->setSuffix(QCoreApplication::translate("MainWindow", " app/min", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "D\303\251marrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

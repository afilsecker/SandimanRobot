/********************************************************************************
** Form generated from reading UI file 'start_window.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_WINDOW_H
#define UI_START_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPort;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditIp;
    QPushButton *pushButtonLogin;
    QLabel *label_3;

    void setupUi(QMainWindow *StartWindowClass)
    {
        if (StartWindowClass->objectName().isEmpty())
            StartWindowClass->setObjectName(QString::fromUtf8("StartWindowClass"));
        StartWindowClass->resize(426, 420);
        centralWidget = new QWidget(StartWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditPort = new QLineEdit(centralWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditIp = new QLineEdit(centralWidget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 1, 1, 1, 1);

        pushButtonLogin = new QPushButton(centralWidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));

        gridLayout->addWidget(pushButtonLogin, 3, 0, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(20);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 2);

        StartWindowClass->setCentralWidget(centralWidget);

        retranslateUi(StartWindowClass);

        QMetaObject::connectSlotsByName(StartWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindowClass)
    {
        StartWindowClass->setWindowTitle(QCoreApplication::translate("StartWindowClass", "StartWindow", nullptr));
        lineEditPort->setText(QCoreApplication::translate("StartWindowClass", "8899", nullptr));
        label->setText(QCoreApplication::translate("StartWindowClass", "IP:", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindowClass", "Port:", nullptr));
        lineEditIp->setText(QCoreApplication::translate("StartWindowClass", "192.168.0.42", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("StartWindowClass", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("StartWindowClass", "Sandiman Robot Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindowClass: public Ui_StartWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_WINDOW_H

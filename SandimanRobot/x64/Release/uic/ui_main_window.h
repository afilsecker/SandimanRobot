/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_All;
    QAction *actionhola_ui;
    QAction *actionpene_ui;
    QAction *actionOpen_Log;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecent;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuLog;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/file.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/folder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/file-symlink.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_All = new QAction(MainWindowClass);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionhola_ui = new QAction(MainWindowClass);
        actionhola_ui->setObjectName(QString::fromUtf8("actionhola_ui"));
        actionpene_ui = new QAction(MainWindowClass);
        actionpene_ui->setObjectName(QString::fromUtf8("actionpene_ui"));
        actionOpen_Log = new QAction(MainWindowClass);
        actionOpen_Log->setObjectName(QString::fromUtf8("actionOpen_Log"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRecent = new QMenu(menuFile);
        menuRecent->setObjectName(QString::fromUtf8("menuRecent"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuLog = new QMenu(menuBar);
        menuLog->setObjectName(QString::fromUtf8("menuLog"));
        MainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLog->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuRecent->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All);
        menuRecent->addAction(actionhola_ui);
        menuRecent->addAction(actionpene_ui);
        menuLog->addAction(actionOpen_Log);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "Sandiman Robot Controller", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindowClass", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindowClass", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindowClass", "Save", nullptr));
        actionSave_All->setText(QCoreApplication::translate("MainWindowClass", "Save All", nullptr));
        actionhola_ui->setText(QCoreApplication::translate("MainWindowClass", "hola.ui", nullptr));
        actionpene_ui->setText(QCoreApplication::translate("MainWindowClass", "pene.ui", nullptr));
        actionOpen_Log->setText(QCoreApplication::translate("MainWindowClass", "Open Log", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindowClass", "File", nullptr));
        menuRecent->setTitle(QCoreApplication::translate("MainWindowClass", "Recent", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindowClass", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindowClass", "Help", nullptr));
        menuLog->setTitle(QCoreApplication::translate("MainWindowClass", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H

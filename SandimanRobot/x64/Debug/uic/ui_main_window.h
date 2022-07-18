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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
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
    QAction *actionPrograming;
    QAction *actionControls;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *labelCamera;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecent;
    QMenu *menuView;
    QDockWidget *dockWidgetControls;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QPushButton *pushButtonZneg;
    QPushButton *pushButtonZpos;
    QPushButton *pushButtonXpos;
    QPushButton *pushButtonYneg;
    QPushButton *pushButtonXneg;
    QPushButton *pushButtonYpos;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QPushButton *pushButtonXposOri;
    QPushButton *pushButtonYnegOri;
    QPushButton *pushButtonZposOri;
    QPushButton *pushButtonYposOri;
    QPushButton *pushButtonXnegOri;
    QPushButton *pushButtonZnegOri;
    QLabel *label_2;
    QFrame *frame_4;
    QLabel *label_3;
    QLabel *labelSpeed;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QScrollBar *horizontalScrollBarSpeed;
    QDockWidget *dockWidgetPrograming;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1237, 751);
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
        actionPrograming = new QAction(MainWindowClass);
        actionPrograming->setObjectName(QString::fromUtf8("actionPrograming"));
        actionPrograming->setCheckable(true);
        actionPrograming->setChecked(true);
        actionControls = new QAction(MainWindowClass);
        actionControls->setObjectName(QString::fromUtf8("actionControls"));
        actionControls->setCheckable(true);
        actionControls->setChecked(true);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        labelCamera = new QLabel(frame);
        labelCamera->setObjectName(QString::fromUtf8("labelCamera"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCamera->sizePolicy().hasHeightForWidth());
        labelCamera->setSizePolicy(sizePolicy1);
        labelCamera->setMinimumSize(QSize(480, 360));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush5(QColor(105, 105, 105, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        QBrush brush6(QColor(245, 245, 245, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        labelCamera->setPalette(palette);
        QFont font;
        font.setPointSize(27);
        labelCamera->setFont(font);
        labelCamera->setAutoFillBackground(true);
        labelCamera->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelCamera, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1237, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRecent = new QMenu(menuFile);
        menuRecent->setObjectName(QString::fromUtf8("menuRecent"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindowClass->setMenuBar(menuBar);
        dockWidgetControls = new QDockWidget(MainWindowClass);
        dockWidgetControls->setObjectName(QString::fromUtf8("dockWidgetControls"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidgetControls->sizePolicy().hasHeightForWidth());
        dockWidgetControls->setSizePolicy(sizePolicy2);
        dockWidgetControls->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        gridLayout = new QGridLayout(dockWidgetContents_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(dockWidgetContents_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 2);

        pushButtonZneg = new QPushButton(frame_2);
        pushButtonZneg->setObjectName(QString::fromUtf8("pushButtonZneg"));

        gridLayout_5->addWidget(pushButtonZneg, 1, 0, 1, 1);

        pushButtonZpos = new QPushButton(frame_2);
        pushButtonZpos->setObjectName(QString::fromUtf8("pushButtonZpos"));

        gridLayout_5->addWidget(pushButtonZpos, 1, 2, 1, 1);

        pushButtonXpos = new QPushButton(frame_2);
        pushButtonXpos->setObjectName(QString::fromUtf8("pushButtonXpos"));

        gridLayout_5->addWidget(pushButtonXpos, 2, 1, 1, 1);

        pushButtonYneg = new QPushButton(frame_2);
        pushButtonYneg->setObjectName(QString::fromUtf8("pushButtonYneg"));

        gridLayout_5->addWidget(pushButtonYneg, 3, 0, 1, 1);

        pushButtonXneg = new QPushButton(frame_2);
        pushButtonXneg->setObjectName(QString::fromUtf8("pushButtonXneg"));

        gridLayout_5->addWidget(pushButtonXneg, 3, 1, 1, 1);

        pushButtonYpos = new QPushButton(frame_2);
        pushButtonYpos->setObjectName(QString::fromUtf8("pushButtonYpos"));

        gridLayout_5->addWidget(pushButtonYpos, 3, 2, 1, 1);


        gridLayout->addWidget(frame_2, 1, 2, 6, 1);

        frame_3 = new QFrame(dockWidgetContents_3);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButtonXposOri = new QPushButton(frame_3);
        pushButtonXposOri->setObjectName(QString::fromUtf8("pushButtonXposOri"));

        gridLayout_6->addWidget(pushButtonXposOri, 3, 1, 1, 1);

        pushButtonYnegOri = new QPushButton(frame_3);
        pushButtonYnegOri->setObjectName(QString::fromUtf8("pushButtonYnegOri"));

        gridLayout_6->addWidget(pushButtonYnegOri, 3, 0, 1, 1);

        pushButtonZposOri = new QPushButton(frame_3);
        pushButtonZposOri->setObjectName(QString::fromUtf8("pushButtonZposOri"));

        gridLayout_6->addWidget(pushButtonZposOri, 1, 2, 1, 1);

        pushButtonYposOri = new QPushButton(frame_3);
        pushButtonYposOri->setObjectName(QString::fromUtf8("pushButtonYposOri"));

        gridLayout_6->addWidget(pushButtonYposOri, 3, 2, 1, 1);

        pushButtonXnegOri = new QPushButton(frame_3);
        pushButtonXnegOri->setObjectName(QString::fromUtf8("pushButtonXnegOri"));

        gridLayout_6->addWidget(pushButtonXnegOri, 2, 1, 1, 1);

        pushButtonZnegOri = new QPushButton(frame_3);
        pushButtonZnegOri->setObjectName(QString::fromUtf8("pushButtonZnegOri"));

        gridLayout_6->addWidget(pushButtonZnegOri, 1, 0, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame_3, 1, 3, 6, 1);

        frame_4 = new QFrame(dockWidgetContents_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 151, 51));

        gridLayout->addWidget(frame_4, 1, 4, 6, 1);

        labelSpeed = new QLabel(dockWidgetContents_3);
        labelSpeed->setObjectName(QString::fromUtf8("labelSpeed"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelSpeed->sizePolicy().hasHeightForWidth());
        labelSpeed->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(labelSpeed, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(dockWidgetContents_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 2);

        label_4 = new QLabel(dockWidgetContents_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        checkBox_2 = new QCheckBox(dockWidgetContents_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);

        gridLayout->addWidget(checkBox_2, 5, 0, 1, 1);

        checkBox = new QCheckBox(dockWidgetContents_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 4, 0, 1, 1);

        horizontalScrollBarSpeed = new QScrollBar(dockWidgetContents_3);
        horizontalScrollBarSpeed->setObjectName(QString::fromUtf8("horizontalScrollBarSpeed"));
        horizontalScrollBarSpeed->setValue(50);
        horizontalScrollBarSpeed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBarSpeed, 6, 1, 1, 1);

        dockWidgetControls->setWidget(dockWidgetContents_3);
        MainWindowClass->addDockWidget(Qt::BottomDockWidgetArea, dockWidgetControls);
        dockWidgetPrograming = new QDockWidget(MainWindowClass);
        dockWidgetPrograming->setObjectName(QString::fromUtf8("dockWidgetPrograming"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dockWidgetPrograming->sizePolicy().hasHeightForWidth());
        dockWidgetPrograming->setSizePolicy(sizePolicy5);
        dockWidgetPrograming->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(1, 1, 1, 1);
        scrollArea = new QScrollArea(dockWidgetContents_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 78, 498));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 2);

        pushButton = new QPushButton(dockWidgetContents_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 1, 0, 1, 2);

        dockWidgetPrograming->setWidget(dockWidgetContents_4);
        MainWindowClass->addDockWidget(Qt::RightDockWidgetArea, dockWidgetPrograming);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuRecent->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All);
        menuRecent->addAction(actionhola_ui);
        menuRecent->addAction(actionpene_ui);
        menuView->addAction(actionPrograming);
        menuView->addAction(actionControls);

        retranslateUi(MainWindowClass);
        QObject::connect(actionControls, &QAction::triggered, dockWidgetControls, &QDockWidget::setVisible);
        QObject::connect(actionPrograming, &QAction::triggered, dockWidgetPrograming, &QDockWidget::setVisible);

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
        actionPrograming->setText(QCoreApplication::translate("MainWindowClass", "Programing", nullptr));
        actionControls->setText(QCoreApplication::translate("MainWindowClass", "Controls", nullptr));
        labelCamera->setText(QCoreApplication::translate("MainWindowClass", "Camera", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindowClass", "File", nullptr));
        menuRecent->setTitle(QCoreApplication::translate("MainWindowClass", "Recent", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindowClass", "View", nullptr));
        dockWidgetControls->setWindowTitle(QCoreApplication::translate("MainWindowClass", "Controls", nullptr));
        label->setText(QCoreApplication::translate("MainWindowClass", "Position Control", nullptr));
        pushButtonZneg->setText(QCoreApplication::translate("MainWindowClass", "Z-", nullptr));
        pushButtonZpos->setText(QCoreApplication::translate("MainWindowClass", "Z+", nullptr));
        pushButtonXpos->setText(QCoreApplication::translate("MainWindowClass", "X-", nullptr));
        pushButtonYneg->setText(QCoreApplication::translate("MainWindowClass", "Y-", nullptr));
        pushButtonXneg->setText(QCoreApplication::translate("MainWindowClass", "X+", nullptr));
        pushButtonYpos->setText(QCoreApplication::translate("MainWindowClass", "Y+", nullptr));
        pushButtonXposOri->setText(QCoreApplication::translate("MainWindowClass", "rot Y+", nullptr));
        pushButtonYnegOri->setText(QCoreApplication::translate("MainWindowClass", "rot X+", nullptr));
        pushButtonZposOri->setText(QCoreApplication::translate("MainWindowClass", "rot Z-", nullptr));
        pushButtonYposOri->setText(QCoreApplication::translate("MainWindowClass", "rot X-", nullptr));
        pushButtonXnegOri->setText(QCoreApplication::translate("MainWindowClass", "rot Y-", nullptr));
        pushButtonZnegOri->setText(QCoreApplication::translate("MainWindowClass", "rot Z+", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "Orientation Control", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowClass", "Controler View", nullptr));
        labelSpeed->setText(QCoreApplication::translate("MainWindowClass", "Speed 50", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowClass", "Connect Controller", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowClass", "No Controller Connected", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindowClass", "Controller", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindowClass", "Keyboard", nullptr));
        dockWidgetPrograming->setWindowTitle(QCoreApplication::translate("MainWindowClass", "Programing", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowClass", "Add Point", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H

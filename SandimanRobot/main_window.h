#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include <QEvent>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindowClass ui;

private:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

signals:
    void moveByKey(Qt::Key key);
    void stopByKey(Qt::Key key);

private slots:
    void changeSpeedLabel(int speed);
};

#pragma once

#include <QObject>
#include <QApplication>
#include <QThread>

#include "main_window.h"
#include "start_window.h"

#include "robot.h"

class Application  : public QObject
{
    Q_OBJECT

public:
    Application(int &argc, char** argv);

    ~Application();

    int run();

private:
    QApplication m_app;

    MainWindow m_main_window;

    StartWindow m_start_window;

    Robot m_robot;

    QThread* m_robot_thread = new QThread;

public slots:

    void loginResultRecieve(bool result);

};

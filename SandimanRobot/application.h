#pragma once

#include <QObject>
#include <QApplication>
#include <QThread>

#include "main_window.h"
#include "start_window.h"

#include "robot.h"


enum KeyOrButton
{
    None = 0,
    Button,
    Key
};


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

    Qt::Key pressed_key = (Qt::Key)0;
    KeyOrButton key_or_button = None;
    const Qt::Key kAcceptedKeys[12] = {
            Qt::Key_A,
            Qt::Key_W,
            Qt::Key_S,
            Qt::Key_D,
            Qt::Key_E,
            Qt::Key_Q,
            Qt::Key_J,
            Qt::Key_K,
            Qt::Key_L,
            Qt::Key_O,
            Qt::Key_I,
            Qt::Key_U
    };

public slots:

    void loginResultRecieve(bool result);

    void moveByButton();

    void stopByButton();

    void moveByKey(Qt::Key key);

    void stopByKey(Qt::Key key);

};

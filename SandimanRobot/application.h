#pragma once

#include <QObject>
#include <QApplication>
#include <QThread>

#include "main_window.h"
#include "start_window.h"

#include "robot.h"
#include "controller.h"


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
    // To run the hole thing
    QApplication m_app;

    // This contains the main window in the stack
    MainWindow m_main_window;

    // The start window for login
    StartWindow m_start_window;

    // The robot controll
    Robot m_robot;

    Controller m_controller;

    QThread* m_controller_thread = new QThread;

    // The whole robot goes in another thread
    QThread* m_robot_thread = new QThread;

    // For controlling whith the keyboard
    Qt::Key pressed_key = (Qt::Key)0;
    KeyOrButton key_or_button = None;  // to control wether it is moving by key or bu



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

    void moveByController(teach_mode mode, bool dir);

    void stopByController();


};

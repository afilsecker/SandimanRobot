#include "application.h"
#include <QDebug>



Application::Application(int &argc, char **argv)
    : m_app(argc, argv)
{
    qDebug() << "initializing the application";

    m_robot.moveToThread(m_robot_thread);

    connect(&m_start_window, &StartWindow::requestLogin, &m_robot, &Robot::login);
    connect(&m_robot, &Robot::loginResult, this, &Application::loginResultRecieve);

    connect(m_main_window.ui.pushButtonXneg, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonXneg, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonXpos, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonXpos, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonYneg, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonYneg, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonYpos, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonYpos, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonZneg, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonZneg, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonZpos, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonZpos, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonXnegOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonXnegOri, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonXposOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonXposOri, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonYnegOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonYnegOri, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonYposOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonYposOri, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonZnegOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonZnegOri, &QPushButton::released, this, &Application::stopByButton);
    connect(m_main_window.ui.pushButtonZposOri, &QPushButton::pressed, this, &Application::moveByButton);
    connect(m_main_window.ui.pushButtonZposOri, &QPushButton::released, this, &Application::stopByButton);

    connect(&m_main_window, &MainWindow::moveByKey, this, &Application::moveByKey);
    connect(&m_main_window, &MainWindow::stopByKey, this, &Application::stopByKey);

    connect(m_main_window.ui.horizontalScrollBarSpeed, &QScrollBar::valueChanged, &m_robot, &Robot::setSpeed);

    m_robot_thread->start();
    m_start_window.show();
}

Application::~Application()
{}


int Application::run()
{
    return m_app.exec();
}

void Application::loginResultRecieve(bool result)
{
    if (result)
    {
        qDebug() << "login succesful";
        m_start_window.hide();
        m_main_window.show();
        m_main_window.ui.horizontalScrollBarSpeed->setValue(45);
    }
    else
    {
        qDebug() << "login failed";
        m_start_window.loginFailed();
    }
}

void Application::moveByButton()
{
    if (key_or_button == None) {
        key_or_button = Button;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        QString buttonText = buttonSender->text();
        if (buttonText == "X-") m_robot.teachMove(MOV_X, false);
        else if (buttonText == "X+") m_robot.teachMove(MOV_X, true);
        else if (buttonText == "Y-") m_robot.teachMove(MOV_Y, false);
        else if (buttonText == "Y+") m_robot.teachMove(MOV_Y, true);
        else if (buttonText == "Z-") m_robot.teachMove(MOV_Z, false);
        else if (buttonText == "Z+") m_robot.teachMove(MOV_Z, true);
        else if (buttonText == "rot X-") m_robot.teachMove(ROT_X, false);
        else if (buttonText == "rot X+") m_robot.teachMove(ROT_X, true);
        else if (buttonText == "rot Y-") m_robot.teachMove(ROT_Y, false);
        else if (buttonText == "rot Y+") m_robot.teachMove(ROT_Y, true);
        else if (buttonText == "rot Z-") m_robot.teachMove(ROT_Z, false);
        else if (buttonText == "rot Z+") m_robot.teachMove(ROT_Z, true);
    }
}

void Application::stopByButton()
{
    if (key_or_button == Button) {
        key_or_button = None;
        m_robot.stopTeachMove();
    }
}


void Application::moveByKey(Qt::Key key) {
    int n = sizeof(kAcceptedKeys) / sizeof(*kAcceptedKeys);
    if (key_or_button == None) {
        if (std::find(kAcceptedKeys, kAcceptedKeys + n, key) != kAcceptedKeys + n) {
            if (pressed_key == (Qt::Key)0) {
                pressed_key = key;
                key_or_button = Key;
                if (key == Qt::Key_W) m_robot.teachMove(MOV_X, false);
                else if (key == Qt::Key_S) m_robot.teachMove(MOV_X, true);
                else if (key == Qt::Key_A) m_robot.teachMove(MOV_Y, false);
                else if (key == Qt::Key_D) m_robot.teachMove(MOV_Y, true);
                else if (key == Qt::Key_Q) m_robot.teachMove(MOV_Z, false);
                else if (key == Qt::Key_E) m_robot.teachMove(MOV_Z, true);

                else if (key == Qt::Key_J) m_robot.teachMove(ROT_X, true);
                else if (key == Qt::Key_K) m_robot.teachMove(ROT_Y, true);
                else if (key == Qt::Key_L) m_robot.teachMove(ROT_X, false);
                else if (key == Qt::Key_O) m_robot.teachMove(ROT_Z, false);
                else if (key == Qt::Key_I) m_robot.teachMove(ROT_Y, false);
                else if (key == Qt::Key_U) m_robot.teachMove(ROT_Z, true);
            }
        }
    }
}


void Application::stopByKey(Qt::Key key) {
    std::cout << (int)pressed_key << std::endl;
    if (key_or_button == Key) {
        if (key == pressed_key) {
            pressed_key = (Qt::Key)0;
            key_or_button = None;
            m_robot.stopTeachMove();
        }
    }
}


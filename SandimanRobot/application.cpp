#include "application.h"
#include <QDebug>


Application::Application(int &argc, char **argv)
    : m_app(argc, argv)
{
    qDebug() << "initializing the application";

    m_robot.moveToThread(m_robot_thread);

    connect(&m_start_window, &StartWindow::requestLogin, &m_robot, &Robot::login);
    connect(&m_robot, &Robot::loginResult, this, &Application::loginResultRecieve);

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
    }
    else
    {
        qDebug() << "login failed";
        m_start_window.loginFailed();
    }
}
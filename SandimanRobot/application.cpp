#include "application.h"
#include <QDebug>

Application::Application(int &argc, char **argv)
    : m_app(argc, argv)
{
    qDebug() << "initializing the application";
    m_start_window.show();
}

Application::~Application()
{}


int Application::run()
{
    return m_app.exec();
}
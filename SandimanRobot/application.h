#pragma once

#include <QObject>
#include <QApplication>

#include "main_window.h"
#include "start_window.h"

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

};

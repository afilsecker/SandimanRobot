#pragma once

#include <QWidget>
#include "ui_start_window.h"

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QMainWindow *parent = nullptr);
    ~StartWindow();

private:
    Ui::StartWindowClass ui;
};

#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.horizontalScrollBarSpeed, &QScrollBar::valueChanged, this, &MainWindow::changeSpeedLabel);
}

MainWindow::~MainWindow()
{}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
        emit moveByKey((Qt::Key)event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
        emit stopByKey((Qt::Key)event->key());
}

void MainWindow::changeSpeedLabel(int speed)
{
    QString new_text = "Speed " + QString::number(speed + 1);
    ui.labelSpeed->setText(new_text);
}
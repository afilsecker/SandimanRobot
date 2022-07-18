#include "start_window.h"

#include <QDebug>

StartWindow::StartWindow(QMainWindow *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.labelMsg->hide();
    connect(ui.pushButtonLogin, &QPushButton::clicked, this, &StartWindow::loginButtonPressed);
}

StartWindow::~StartWindow()
{}

void StartWindow::loginButtonPressed()
{
    QString ip = ui.lineEditIp->text();
    const char *addr = ip.toStdString().c_str(); // TODO esta wea esta mala xd. investigar inline, c_str(), const char*
    int port = ui.lineEditPort->text().toInt();
    qDebug() << "ip:" << ip << "port:" << port;
    qDebug() << addr;

    ui.labelMsg->setText("Logging in...");
    ui.labelMsg->show();
    ui.pushButtonLogin->setEnabled(false);
    emit requestLogin(addr, port);
}

void StartWindow::loginFailed()
{
    ui.labelMsg->setText("LoginFailed");
    ui.pushButtonLogin->setEnabled(true);
}
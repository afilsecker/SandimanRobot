#include "controller.h"

#include <QDebug>
#include <math.h>

using namespace controller;

Controller::Controller(QObject* parent)
	: QObject(parent)
{
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &Controller::getValues);
	startController();
}

Controller::~Controller()
{}


void Controller::connectController()
{
	qDebug() << "semen";
	int connected_devices = JslConnectDevices();
	qDebug() << "number of devices:" << connected_devices;
	int deviceHandleArray[4];
	JslGetConnectedDeviceHandles(deviceHandleArray, connected_devices);
	for (int i = 0; i < connected_devices; i++)
	{
		qDebug() << deviceHandleArray[i];
	}
}


void Controller::startController()
{
	m_timer->start(m_interval);
}

void Controller::stopController()
{
	m_timer->stop();
}


void Controller::getValues()
{
	left_x = JslGetLeftX(device_id);
	left_y = JslGetLeftY(device_id);
	right_x = JslGetRightX(device_id);
	right_y = JslGetRightY(device_id);
	buttons = JslGetButtons(device_id);

	bUp = ((buttons >> JSOFFSET_UP) & 1);
	bDown = ((buttons >> JSOFFSET_DOWN) & 1);
	bLeft = ((buttons >> JSOFFSET_LEFT) & 1);
	bRight = ((buttons >> JSOFFSET_RIGHT) & 1);


	decideAndSend();
}

void Controller::decideAndSend()
{


	float value_left = hypot(left_x, left_y);
	float value_right = hypot(right_x, right_y);
	float value;

	if (active_thing == None_active)
	{
		if (value_left > m_umbral && value_right > m_umbral)
			active_thing = None_active;
		else if (value_left > m_umbral)
			active_thing = LEFT;
		else if (value_right > m_umbral)
			active_thing = RIGHT;
		else if (bUp || bDown || bLeft || bRight)
			active_thing = BUTTONS;
		else
			active_thing = None_active;
	}
	
	if (active_thing == LEFT)
	{
		value = value_left;
		if (value > m_umbral)  // umbral circular
		{
			if (abs(left_x) > abs(left_y))  // Direccion X
			{
				if (left_x > 0)
					m_new_dir = POS_X;
				else
					m_new_dir = NEG_X;
			}
			else  // Direccion Y
			{
				if (left_y > 0)
					m_new_dir = POS_Y;
				else
					m_new_dir = NEG_Y;
			}
		}
		else
		{
			active_thing = None_active;
			m_new_dir = None;
			// send stop
		}
	}
	else if (active_thing == RIGHT)
	{
		value = value_right;
		if (value > m_umbral)  // umbral circular
		{
			if (abs(right_x) > abs(right_y))  // Direccion X
			{
				if (right_x > 0)
					m_new_dir = POS_XR;
				else
					m_new_dir = NEG_XR;
			}
			else  // Direccion Y
			{
				if (right_y > 0)
					m_new_dir = POS_YR;
				else
					m_new_dir = NEG_YR;
			}
		}
		else
		{
			active_thing = None_active;
			m_new_dir = None;
			// send stop
		}
	}
	else if (active_thing == BUTTONS)
	{
		int n_botones = bUp + bDown + bRight + bLeft;
		if (n_botones == 1)
		{
			if (bUp)
				m_new_dir = POS_Z;
			else if (bDown)
				m_new_dir = NEG_Z;
			else if (bRight)
				m_new_dir = POS_ZR;
			else if (bLeft)
				m_new_dir = NEG_ZR;
		}
		else
		{
			active_thing = None_active;
			m_new_dir = None;
			// send stop
		}
	}


	if (m_new_dir != m_prev_dir)
	{
		qDebug() << "";
		qDebug() << "nueva weaaaa";
		qDebug() << "prev" << m_prev_dir << "new" << m_new_dir;

		if (m_prev_dir != None && m_new_dir != None)
		{
			sendStop();
		}

		switch (m_new_dir)
		{
		case POS_X:
			emit sendDir(aubo_robot_namespace::MOV_Y, true);
			qDebug() << "Sendig move pos y";
			break;

		case NEG_X:
			emit sendDir(aubo_robot_namespace::MOV_Y, false);
			qDebug() << "Sendig move neg y";
			break;

		case POS_Y:
			emit sendDir(aubo_robot_namespace::MOV_X, false);
			qDebug() << "Sendig move neg x";
			break;

		case NEG_Y:
			emit sendDir(aubo_robot_namespace::MOV_X, true);
			qDebug() << "Sendig move pos x";
			break;

		case POS_Z:
			emit sendDir(aubo_robot_namespace::MOV_Z, true);
			qDebug() << "Sendig move pos z";
			break;

		case NEG_Z:
			emit sendDir(aubo_robot_namespace::MOV_Z, false);
			qDebug() << "Sendig move neg z";
			break;

		case POS_XR:
			emit sendDir(aubo_robot_namespace::ROT_X, false);
			qDebug() << "Sendig rot pos y";
			break;

		case NEG_XR:
			emit sendDir(aubo_robot_namespace::ROT_X, true);
			qDebug() << "Sendig rot neg y";
			break;

		case POS_YR:
			emit sendDir(aubo_robot_namespace::ROT_Y, false);
			qDebug() << "Sendig rot neg x";
			break;

		case NEG_YR:
			emit sendDir(aubo_robot_namespace::ROT_Y, true);
			qDebug() << "Sendig rot pos x";
			break;

		case POS_ZR:
			emit sendDir(aubo_robot_namespace::ROT_Z, false);
			qDebug() << "Sendig rot neg z";
			break;

		case NEG_ZR:
			emit sendDir(aubo_robot_namespace::ROT_Z, true);
			qDebug() << "Sendig rot pos z";
			break;

		case controller::None:
			emit sendStop();
			qDebug() << "Sendig stop";
			break;
		}
	}
	else
	{
		// Do nothing
	}
	m_prev_dir = m_new_dir;
}
#pragma once

#include <QObject>
#include <QTimer>

#include "JoyShockLibrary.h"
#include "AuboRobotMetaType.h"


namespace controller
{
	enum Direction
	{
		None,
		POS_X,
		NEG_X,
		POS_Y,
		NEG_Y,
		POS_Z,
		NEG_Z,
		POS_XR,
		NEG_XR,
		POS_YR,
		NEG_YR,
		POS_ZR,
		NEG_ZR
	};

	enum Active
	{
		None_active,
		LEFT,
		RIGHT,
		BUTTONS
	};
}




class Controller : public QObject
{
	Q_OBJECT

public:
	Controller(QObject* parent=nullptr);
	~Controller();
	QTimer* m_timer;
	int m_interval = 10;
	controller::Direction m_prev_dir = controller::None;
	controller::Direction m_new_dir = controller::None;
	controller::Active active_thing = controller::None_active;

	bool bUp = false;
	bool bDown = false;
	bool bRight = false;
	bool bLeft = false;


private:
	int device_id = 0;
	float m_umbral = 0.2;

	float left_x = 0;
	float left_y = 0;
	float right_x = 0;
	float right_y = 0;
	int buttons = 0;

	void decideAndSend();
	

signals:
	void sendDir(aubo_robot_namespace::teach_mode mode, bool dir);
	
	void sendStop();

public slots:
	void connectController();

	void getValues();

	void startController();

	void stopController();
};

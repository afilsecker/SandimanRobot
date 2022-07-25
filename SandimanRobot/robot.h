#pragma once

#include <QObject>

#include "rsdef.h"

#define ROBOT_ADDR "192.168.8.127"
#define ROBOT_PORT 8899
#define M_PI_A 3.14159265358979323846

class Robot  : public QObject
{
    Q_OBJECT

public:
    Robot(QObject *parent=nullptr);

    ~Robot();

public:
	RSHD r_rshd = -1;
	double speed_ = 2;

private:
	ToolDynamicsParam tool_dynamics = { 0 };
	uint8 colli_class = 6;
	bool read_pos = true;
	bool static_colli_detect = true;
	int board_maxacc = 30000;
	ROBOT_SERVICE_STATE state = ROBOT_SERVICE_READY;

private:
	Pos posDirection(Pos& initial_position, Pos& dir);

public slots:
	// Must have the robot turned on
	bool login(const char* addr, int port);

signals:
	void loginResult(bool result);

public:
	// First thing to do
	bool startup();
	bool teachMove(teach_mode mode, bool dir);
	void stopTeachMove();
	void setSpeed(int speed);
	void my_example();
	void moveLineTo();

};

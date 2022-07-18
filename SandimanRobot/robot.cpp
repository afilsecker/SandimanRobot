#include "robot.h"

#include <iostream>
#include <QDebug>

using namespace std;

Robot::Robot(QObject *parent)
    : QObject(parent)
{
    qDebug() << "robot stated";
}

Robot::~Robot()
{}


bool Robot::login(const char* addr, int port) {
    bool result = false;
    r_rshd = RS_FAILED;
    qDebug() << "Logging in...";
    if (rs_initialize() == RS_SUCC) {
        if (rs_create_context(&r_rshd) == RS_SUCC) {
            if (rs_login(r_rshd, ROBOT_ADDR, port) == RS_SUCC) {
                result = true;
                qDebug() << "loggin successful";
                startup();
            }
            else {
                qDebug() << "loggin failed";
            }
        }
        else {
            qDebug() << "rs_create_context error";
        }
    }
    else {
        qDebug() << "rs_initialize error";
    }
    emit loginResult(result);
    return result;
}


bool Robot::startup() {
    bool result = false;
    qDebug() << "Starting up...";
    if (rs_robot_startup(r_rshd, &tool_dynamics, colli_class, read_pos, static_colli_detect,
        board_maxacc, &state) == RS_SUCC) {
        result = true;
        qDebug() << "call robot startup succ, robot state:" << state;
    }
    else {
        qDebug() << "robot startup failed";
    }
    return result;
}


void Robot::setSpeed(int speed)
{
    speed_ = speed;
    rs_init_global_move_profile(r_rshd);

    double endMoveMaxAcc;
    endMoveMaxAcc = 1;
    rs_set_global_end_max_line_acc(r_rshd, endMoveMaxAcc);
    rs_set_global_end_max_angle_acc(r_rshd, endMoveMaxAcc);

    double endMoveMaxVelc;
    endMoveMaxVelc = speed_ / 100;
    rs_set_global_end_max_line_velc(r_rshd, endMoveMaxVelc);
    rs_set_global_end_max_angle_velc(r_rshd, endMoveMaxVelc);
}


bool Robot::teachMove(teach_mode mode, bool dir) {
    setSpeed(speed_);

    bool result = false;
    if (rs_teach_move_start(r_rshd, mode, dir) == RS_SUCC) {
        result = true;
    }

    return result;
}

void Robot::stopTeachMove()
{
    rs_teach_move_stop(r_rshd);
}

void Robot::my_example()
{
    int ret;
    // speed
    rs_init_global_move_profile(r_rshd);
    aubo_robot_namespace::JointVelcAccParam jointMaxAcc;
    jointMaxAcc.jointPara[0] = 50.0 / 180.0 * M_PI_A;
    jointMaxAcc.jointPara[1] = 50.0 / 180.0 * M_PI_A;
    jointMaxAcc.jointPara[2] = 50.0 / 180.0 * M_PI_A;
    jointMaxAcc.jointPara[3] = 50.0 / 180.0 * M_PI_A;
    jointMaxAcc.jointPara[4] = 50.0 / 180.0 * M_PI_A;
    jointMaxAcc.jointPara[5] = 50.0 / 180.0 * M_PI_A;
    rs_set_global_joint_maxacc(r_rshd, &jointMaxAcc);

    aubo_robot_namespace::JointVelcAccParam jointMaxVelc;
    jointMaxVelc.jointPara[0] = 50.0 / 180.0 * M_PI_A;
    jointMaxVelc.jointPara[1] = 50.0 / 180.0 * M_PI_A;
    jointMaxVelc.jointPara[2] = 50.0 / 180.0 * M_PI_A;
    jointMaxVelc.jointPara[3] = 50.0 / 180.0 * M_PI_A;
    jointMaxVelc.jointPara[4] = 50.0 / 180.0 * M_PI_A;
    jointMaxVelc.jointPara[5] = 50.0 / 180.0 * M_PI_A;
    rs_set_global_joint_maxvelc(r_rshd, &jointMaxVelc);
    rs_init_global_move_profile(r_rshd);

    double endMoveMaxAcc;
    endMoveMaxAcc = 0.2;
    rs_set_global_end_max_line_acc(r_rshd, endMoveMaxAcc);
    rs_set_global_end_max_angle_acc(r_rshd, endMoveMaxAcc);

    double endMoveMaxVelc;
    endMoveMaxVelc = 0.2;
    rs_set_global_end_max_line_velc(r_rshd, endMoveMaxVelc);
    rs_set_global_end_max_angle_velc(r_rshd, endMoveMaxVelc);

    double jointAngle[aubo_robot_namespace::ARM_DOF] = { 0 };

    rs_init_global_move_profile(r_rshd);

    rs_set_global_joint_maxacc(r_rshd, &jointMaxAcc);
    rs_set_global_joint_maxvelc(r_rshd, &jointMaxVelc);

    // end speed


    jointAngle[0] = -0.000003;
    jointAngle[1] = -0.127267;
    jointAngle[2] = -1.321122;
    jointAngle[3] = 0.376934;
    jointAngle[4] = -1.570796;
    jointAngle[5] = -0.000008;

    //ret = rs_move_joint(r_rshd, jointAngle);
    //std::cout << "JointMove ret:" << ret << std::endl;




    rs_init_global_move_profile(r_rshd);

    rs_set_global_end_max_line_acc(r_rshd, endMoveMaxAcc);
    rs_set_global_end_max_angle_acc(r_rshd, endMoveMaxAcc);
    rs_set_global_end_max_line_velc(r_rshd, endMoveMaxVelc);
    rs_set_global_end_max_angle_velc(r_rshd, endMoveMaxVelc);

    /*
    jointAngle[0] = -0.000003;
    jointAngle[1] = -0.127267;
    jointAngle[2] = -1.321122;
    jointAngle[3] = 0.376934;
    jointAngle[4] = -1.570796;
    jointAngle[5] = -0.000008;
    rs_add_waypoint(r_rshd, jointAngle);
    */

    wayPoint_S current_waypoint;
    rs_get_current_waypoint(r_rshd, &current_waypoint);
    rs_add_waypoint(r_rshd, current_waypoint.jointpos);


    jointAngle[0] = 0.200000;
    jointAngle[1] = -0.167267;
    jointAngle[2] = -1.321122;
    jointAngle[3] = 0.376934;
    jointAngle[4] = -1.570794;
    jointAngle[5] = -0.000012;
    rs_add_waypoint(r_rshd, jointAngle);

    wayPoint_S target_waypoint;
    Pos dir = { -0.01, 0.01, 0.01 };
    Pos final_position = posDirection(current_waypoint.cartPos.position, dir);
    ret = rs_inverse_kin(r_rshd, current_waypoint.jointpos, &final_position, &current_waypoint.orientation, &target_waypoint);
    std::cout << "1 inverse kin result" << ret << std::endl;
    rs_add_waypoint(r_rshd, target_waypoint.jointpos);


    rs_set_blend_radius(r_rshd, 0.01);


    ret = rs_move_track(r_rshd, CARTESIAN_MOVEP);
    std::cout << "2 TrackMove ret:" << ret << std::endl;

    rs_get_current_waypoint(r_rshd, &current_waypoint);
    dir = { +1, -0.01, -0.01 };
    final_position = posDirection(current_waypoint.cartPos.position, dir);
    ret = rs_inverse_kin(r_rshd, current_waypoint.jointpos, &final_position, &current_waypoint.orientation, &target_waypoint);
    std::cout << "3 inverse kin result" << ret << std::endl;

    std::cout << "4 aqui voyyyyy" << std::endl;
    rs_add_waypoint(r_rshd, target_waypoint.jointpos);
    ret = rs_move_track(r_rshd, CARTESIAN_MOVEP, true);
    std::cout << "5 TrackMove ret:" << ret << std::endl;


    /*
    setSpeed();
    wayPoint_S current_waypoint;
    rs_get_current_waypoint(r_rshd, &current_waypoint);
    wayPoint_S target_waypoint;
    Pos dir = { -0.01, 0.01, 0.01 };
    Pos final_position = posDirection(current_waypoint.cartPos.position, dir);
    int resultado = rs_inverse_kin(r_rshd, current_waypoint.jointpos, &final_position, &current_waypoint.orientation, &target_waypoint);
    std::cout << resultado << std::endl;
    rs_add_waypoint(r_rshd, current_waypoint.jointpos);
    rs_add_waypoint(r_rshd, target_waypoint.jointpos);
    jointAngle[0] = 0.100000;
    jointAngle[1] = -0.147267;
    jointAngle[2] = -1.321122;
    jointAngle[3] = 0.376934;
    jointAngle[4] = -1.570794;
    jointAngle[5] = -0.000008;
    rs_add_waypoint(r_rshd, jointAngle);
    ret = rs_move_joint(r_rshd, current_waypoint.jointpos);
    if (RS_SUCC != hola)
    {
        std::cerr << "JointMove ret:" << hola << std::endl;
    }
    rs_set_blend_radius(r_rshd, 0.03);
    rs_set_circular_loop_times(r_rshd, 1);
    ret = rs_move_track(r_rshd, TRACKING);
    if (RS_SUCC != ret)
    {
        std::cout << "TrackMove failed ret:" << ret << std::endl;
    }
    */



}

void Robot::moveLineTo()
{
    ToolInEndDesc tool_params;
    wayPoint_S current_way_point;
    rs_get_tool_kinematics_param(r_rshd, &tool_params);
    rs_get_current_waypoint(r_rshd, &current_way_point);
    int output = rs_set_no_arrival_ahead(r_rshd);
    std::cout << output << std::endl;
    Pos dir = { -0.01, 0.01, 0.01 };
    Pos pos = posDirection(current_way_point.cartPos.position, dir);
    rs_move_line_to(r_rshd, &pos, &tool_params, false);
}


Pos Robot::posDirection(Pos& initial_position, Pos& dir)
{
    Pos result = {
        initial_position.x + dir.x,
        initial_position.y + dir.y,
        initial_position.z + dir.z
    };
    return result;
}
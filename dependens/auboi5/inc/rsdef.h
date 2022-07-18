#ifndef RSDEF_H
#define RSDEF_H
#include "rstype.h"
#include "AuboRobotMetaType.h"
#include <vector>

#define TRUE             1
#define FALSE            0
#define RS_SUCC          0
#define RS_FAILED       -1
#define MAX_RS_INSTANCE  32
#define POS_SIZE         3
#define ORI_SIZE         4
#define INERTIA_SIZE     6

#define RS_UNUSED(x) (void)x;
//#define _DEBUG

using namespace  aubo_robot_namespace;

typedef CoordCalibrateByJointAngleAndTool CoordCalibrate;

typedef struct {
    double rotateAxis[3];
}Move_Rotate_Axis;

#ifdef __cplusplus
extern "C" {
#endif

    //library initialize and uninitialize
    /**
     * @brief initializes the robotic arm control library
     * @return RS_SUCC success other failure
     */
    int rs_initialize(void);

    /**
     * @brief deinitialize robotic arm control library
     * @return RS_SUCC success other failure
     */
    int rs_uninitialize(void);

    //robot service context
    /**
     * @brief creates a handle to the robotic arm control context
     * @param rshd
     * @return RS_SUCC success other failure
     */
    int rs_create_context(RSHD* rshd/*returned context handle*/);

    /**
     * @brief logs out the robotic arm control context handle
     * @param rshd
     * @return RS_SUCC success other failure
     */
    int rs_destory_context(RSHD rshd);

    //login logout
    /**
     * @brief link robot server
     * @param rshd arm control context handle
     * @param addr IP address of the robotic arm server
     * @param port The port number of the robotic arm server
     * @return RS_SUCC success other failure
     */
    int rs_login(RSHD rshd, const char* addr, int port);

    /**
     * @brief disconnects the arm server link
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_logout(RSHD rshd);

    /**
     * @brief gets the current connection status
     * @param rshd arm control context handle
     * @param status true online false offline
     * @return RS_SUCC success other failure
     */
    int rs_get_login_status(RSHD rshd, bool* status);

    //set move profile
    /**
     * @brief initializes global motion properties
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_init_global_move_profile(RSHD rshd);

    //joint max acc,velc
    /**
     * @brief sets the maximum acceleration of the six joints
     * @param rshd arm control context handle
     * @param max_acc The maximum acceleration of the six joints, unit (rad/ss)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_joint_maxacc(RSHD rshd, const JointVelcAccParam* max_acc);

    /**
     * @brief sets the maximum speed of the six joints
     * @param rshd arm control context handle
     * @param max_velc The maximum speed of the six joints, unit (rad/s)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_joint_maxvelc(RSHD rshd, const JointVelcAccParam* max_velc);

    /**
     * @brief gets the maximum acceleration of the six joints
     * @param rshd arm control context handle
     * @param max_acc returns the maximum acceleration unit of the six joints (rad/s^2)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_joint_maxacc(RSHD rshd, JointVelcAccParam* max_acc);

    /**
     * @brief sets the maximum speed of the six joints
     * @param rshd arm control context handle
     * @param max_velc returns the maximum acceleration unit of the six joints (rad/s)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_joint_maxvelc(RSHD rshd, JointVelcAccParam* max_velc);

    //end line max acc,velc
    /**
     * @brief sets the maximum linear acceleration at the end of the robotic arm
     * @param rshd arm control context handle
     * @param max_acc The maximum acceleration at the end, unit (m/s^2)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_end_max_line_acc(RSHD rshd, double max_acc);

    /**
     * @brief sets the maximum linear speed of the end of the robot arm
     * @param rshd arm control context handle
     * @param max_velc The maximum linear velocity at the end, unit (m/s)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_end_max_line_velc(RSHD rshd, double max_velc);

    /**
     * @brief gets the maximum linear acceleration at the end of the robotic arm
     * @param rshd arm control context handle
     * @param max_acc The maximum linear acceleration of the end of the manipulator, unit (m/s^2)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_end_max_line_acc(RSHD rshd, double* max_acc);

    /**
     * @brief gets the maximum linear velocity of the end of the robot arm
     * @param rshd arm control context handle
     * @param max_velc The maximum linear speed of the end of the robot arm, unit (m/s)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_end_max_line_velc(RSHD rshd, double* max_velc);

    //end line max acc,velc
    /**
     * @brief sets the maximum angular acceleration of the end of the manipulator
     * @param rshd arm control context handle
     * @param max_acc The maximum angular acceleration of the end, unit (rad/s^2)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_end_max_angle_acc(RSHD rshd, double max_acc);

    /**
     * @brief sets the maximum angular velocity of the end of the manipulator
     * @param rshd arm control context handle
     * @param max_velc The maximum speed at the end, unit (rad/s)
     * @return RS_SUCC success other failure
     */
    int rs_set_global_end_max_angle_velc(RSHD rshd, double max_velc);

    /**
     * @brief gets the maximum angular acceleration of the end of the robot arm
     * @param rshd arm control context handle
     * @param max_acc The maximum angular acceleration of the end of the manipulator, unit (m/s^2)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_end_max_angle_acc(RSHD rshd, double* max_acc);

    /**
     * @brief gets the maximum angular acceleration of the end of the robot arm
     * @param rshd arm control context handle
     * @param max_velc The maximum angular velocity of the end of the manipulator, unit (m/s)
     * @return RS_SUCC success other failure
     */
    int rs_get_global_end_max_angle_velc(RSHD rshd, double* max_velc);

    //robot move
    /**
     * @brief robot arm axis move
     * @param rshd arm control context handle
     * @param joint_radian Joint angle of six joints, unit (rad)
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_joint(RSHD rshd, double joint_radian[ARM_DOF], bool isblock = true);

    /**
     * @brief manipulator keeps the current attitude and moves in a straight line
     * @param rshd arm control context handle
     * @param joint_radian Joint angle of six joints, unit (rad)
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_line(RSHD rshd, double joint_radian[ARM_DOF], bool isblock = true);

    /**
     * @brief maintains the current position and transforms the attitude to make a rotation motion
     * @param rshd arm control context handle
     * @param user_coord user coordinate system
     * @param rotate_axis : Rotation axis (x,y,z) For example: (1,0,0) means to rotate along the Y axis
     * @param rotate_angle rotation angle unit (rad)
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_rotate(RSHD rshd, const CoordCalibrate* user_coord, const Move_Rotate_Axis* rotate_axis, double rotate_angle, bool isblock = true);

    /**
     * @brief clears all set global waypoints
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_remove_all_waypoint(RSHD rshd);

    /**
     * @brief add global waypoints for trajectory motion
     * @param rshd arm control context handle
     * @param joint_radian Joint angle of six joints, unit (rad)
     * @return RS_SUCC success other failure
     */
    int rs_add_waypoint(RSHD rshd, double joint_radian[ARM_DOF]);

    /**
     * @brief set blend radius
     * @param rshd arm control context handle
     * @param radius blend radius, unit (m)
     * @return RS_SUCC success other failure
     */
    int rs_set_blend_radius(RSHD rshd, double radius);

    /**
     * @brief sets the number of circles in motion
     * @param rshd arm control context handle
     * @param times When times is greater than 0, the robotic arm performs circular motion times times
     * When times is equal to 0, the robotic arm performs circular arc trajectory motion
     * @return RS_SUCC success and other failures
     */
    int rs_set_circular_loop_times(RSHD rshd, int times);

    /**
     * @brief sets the user coordinate system
     * @param rshd arm control context handle
     * @param user_coord user coordinate system
     * @return RS_SUCC success other failure
     */
    int rs_set_user_coord(RSHD rshd, const CoordCalibrate* user_coord);

    /**
     * @brief sets the base coordinate system
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_set_base_coord(RSHD rshd);

    /**
     * @brief checks whether the user coordinate system parameter settings are reasonable
     * @param rshd arm control context handle
     * @param user_coord user coordinate system
     * @return RS_SUCC success other failure reasonable return: 0 unreasonable return: other
     */
    int rs_check_user_coord(RSHD rshd, const CoordCalibrate* user_coord);

    /**
     * @brief sets the motion offset based on the base frame
     * @param rshd arm control context handle
     * @param relative displacement (x, y, z) unit (m)
     * @return RS_SUCC success other failure
     */
    int rs_set_relative_offset_on_base(RSHD rshd, const MoveRelative* relative);

    /**
     * @brief sets the offset based on user frame motion
     * @param rshd arm control context handle
     * @param relative displacement (x, y, z) unit (m)
     * @param user_coord user coordinate system
     * @return RS_SUCC success other failure
     */
    int rs_set_relative_offset_on_user(RSHD rshd, const MoveRelative* relative, const CoordCalibrate* user_coord);

    /**
     * @brief cancels the advance setting
     * @param rshd
     * @return
     */
    int rs_set_no_arrival_ahead(RSHD rshd);

    /**
     * @brief sets the advance arrival distance in distance mode
     * @param rshd
     * @param distancein advance distance unit (meter)
     * @return
     */
    int rs_set_arrival_ahead_distance(RSHD rshd, double distance);

    /**
     * @brief sets the advance arrival time in time mode
     * @param rshd
     * @param sec Advance time unit (seconds)
     * @return
     */
    int rs_set_arrival_ahead_time(RSHD rshd, double sec);

    /**
     * @brief sets the blend radius distance in distance mode
     * @param rshd
     * @param radiusblend radius distance unit (meters)
     * @return
     */
    int rs_set_arrival_ahead_blend(RSHD rshd, double radius);

    /**
     * @brief trajectory motion
     * @param rshd arm control context handle
     * @param sub_move_mode track type:
     * 2: arc
     * 3: track
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_track(RSHD rshd, move_track sub_move_mode, bool isblock = true);

    /**
     * @brief keeps the current pose and moves to the target position by means of linear motion, where the target position is given by the offset relative to the current position
     * @param rshd arm control context handle
     * @param target is based on the target position represented by the user plane
     * @param tool   parameter
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_line_to(RSHD rshd, const Pos* target, const ToolInEndDesc* tool, bool isblock = true);

    /**
     * @brief maintains the current pose and moves to the target position by joint motion
     * @param rshd arm control context handle
     * @param target is based on the target position represented by the user plane
     * @param tool parameter
     * @param isblock    isblock==true means blocking, the robot moves until it reaches the target position or returns after a failure.
     * isblock==false means non-blocking, return immediately, return when the motion command is sent successfully, and the robot arm starts to move after the function returns.
     * @return RS_SUCC success other failure
     */
    int rs_move_joint_to(RSHD rshd, const Pos* target, const ToolInEndDesc* tool, bool isblock = true);

    /**
     * @brief sets the teaching coordinate system
     * @param rshd arm control context handle
     * @param user_coord teach coordinate system
     * @return RS_SUCC success other failure
     */
    int rs_set_teach_coord(RSHD rshd, const CoordCalibrate* teach_coord);

    /**
     * @brief start axis teaching
     * @param rshd arm control context handle
     * @param mode teach joints: JOINT1, JOINT2, JOINT3, JOINT4, JOINT5, JOINT6, position teach: MOV_X, MOV_Y, MOV_Z posture teach: ROT_X, ROT_Y, ROT_Z
     * @param dir  movement direction positive direction true negative direction false
     * @return RS_SUCC success other failure
     */
    int rs_teach_move_start(RSHD rshd, teach_mode mode, bool dir);

    /**
     * @brief end teaching
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_teach_move_stop(RSHD rshd);

    /**
     * @brief cleans up off-line trajectory motion data on the server
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_clear_offline_track(RSHD rshd);

    /**
     * @brief adds off-line trajectory motion waypoints to the server
     * @param rshd arm control context handle
     * @param waypoints waypoint array (the number of waypoints is less than or equal to 3000)
     * @param waypoint_count waypoint array size
     * @return RS_SUCC success other failure
     */
    int rs_append_offline_track_waypoint(RSHD rshd, const JointParam waypoints[], int waypoint_count);

    /**
     * @brief adds off-line trajectory motion waypoint file to server
     * @param rshd arm control context handle
     * @param filename The full path of the waypoint file, each line of the waypoint file contains the joint angles (radians) of the six joints, separated by commas
     * @return RS_SUCC success other failure
     */
    int rs_append_offline_track_file(RSHD rshd, const char* filename);

    /**
     * @brief informs the server to start off-line trajectory motion
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_startup_offline_track(RSHD rshd);

    /**
     * @brief informs the server to stop off-line trajectory motion
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_stop_offline_track(RSHD rshd);

    /**
     * @brief notifies the server to enter TCP2CANBUS transparent transmission mode
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_enter_tcp2canbus_mode(RSHD rshd);

    /**
     * @brief informs the server to exit TCP2CANBUS transparent transmission mode
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_leave_tcp2canbus_mode(RSHD rshd);

    /**
     * @brief transparently transmits the motion waypoint to CANBUS
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_set_waypoint_to_canbus(RSHD rshd, double joint_radian[ARM_DOF]);

    /**
     * @brief transparently transmits the motion waypoint to CANBUS
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_set_waypoints_to_canbus(RSHD rshd, double joint_radian[][ARM_DOF], int waypint_count);


    /**
     * @brief Positive solution This function is a positive solution function, and the joint angle is known to find the position and attitude of the corresponding position.
     * @param rshd arm control context handle
     * @param joint_radian Joint angle of six joints, unit (rad)
     * @param waypoint six joint angles, position, attitude
     * @return RS_SUCC success other failure
     */
    int rs_forward_kin(RSHD rshd, const double joint_radian[ARM_DOF], wayPoint_S* waypoint);

    /**
     * @brief inverse solution This function is the inverse solution function of the manipulator. According to the position information (x, y, z) and the reference attitude of the corresponding position (w, x, y, z), the corresponding position is obtained. Joint angle information.
     * @param rshd arm control context handle
     * @param joint_radian refers to the joint angle (usually the current arm position) in units (rad)
     * @param pos target waypoint location unit: meters
     * @param ori target waypoint
     * @param waypoint target waypoint information
     * @return RS_SUCC success other failure
     */
    int rs_inverse_kin(RSHD rshd, double joint_radian[ARM_DOF], const Pos* pos, const Ori* ori, wayPoint_S* waypoint);

    /**
     * @brief user coordinate system to base coordinate system
     * Overview: Convert the position and attitude of the flange center based on the base coordinate system to the position and attitude of the tool end based on the user coordinate system .
     *
     * Extension 1: The center of the flange can be regarded as a special tool, that is, the position of the tool is (0,0,0)
     * Therefore, when the tool is (0,0,0), it is equivalent to placing the flange The center is based on the position and attitude of the base coordinate system, and the center of the flange is based on the position and attitude of the user coordinate system.
     *
     * Extension 2: The user coordinate system can also be selected as the base coordinate system, namely: userCoord.coordType = BaseCoordinate
     * Therefore, when the user plane is the base coordinate system, it is equivalent to base the flange center on the baseThe position and attitude are converted into the position and attitude of the tool end based on the base frame,
     * that is, the tool is added to the base frame.
     * @param rshd arm control context handle
     * @param pos_onbase Flange center position information based on the base frame (x, y, z) Unit (m)
     * @param ori_onbase is based on the attitude information of the base frame (w, x, y, z)
     * @param user_coord user coordinate system
     * @param tool_pos   tool info
     * @param pos_onuser Tool end position information based on user coordinate system, output parameters
     * @param ori_onuser tool end attitude information based on user coordinate system, output parameter
     * @return RS_SUCC success other failure
     */
    int rs_base_to_user(RSHD rshd, const Pos* pos_onbase, const Ori* ori_onbase, const CoordCalibrate* user_coord, const ToolInEndDesc* tool_pos, Pos* pos_onuser, Ori* ori_onuser);

    /**
     * @brief user coordinate system turn base coordinate system
     * @param rshd arm control context handle
     * @param pos_onuser Tool end position information based on user coordinate system
     * @param ori_onuser Tool end pose information based on user coordinate system
     * @param user_coord user coordinate system
     * @param tool_pos   tool info
     * @param pos_onbase Flange center position information based on the base frame
     * @param ori_onbase is based on the attitude information of the base frame
     * @return RS_SUCC success other failures
     */
    int rs_user_to_base(RSHD rshd, const Pos* pos_onuser, const Ori* ori_onuser, const CoordCalibrate* user_coord, const ToolInEndDesc* tool_pos, Pos* pos_onbase, Ori* ori_onbase);

    /**
     * @brief base coordinate system turns the base coordinate to get the position and attitude of the tool end point
     * @param rshd arm control context handle
     * @param flange_center_pos_onbase Tool end position information based on the base frame
     * @param flange_center_ori_onbase Tool end attitude information based on base frame
     * @param tool tool information
     * @param tool_end_pos_onbase Tool end position information based on the base frame
     * @param tool_end_ori_onbase The tool end attitude information based on the base frame
     * @return RS_SUCC success other failure
     */
    int rs_base_to_base_additional_tool(RSHD rshd, const Pos* flange_center_pos_onbase, const Ori* flange_center_ori_onbase, const ToolInEndDesc* tool, Pos* tool_end_pos_onbase, Ori* tool_end_ori_onbase);

    /**
     * @brief Euler angle to four elements
     * @param rshd arm control context handle
     * @param rpy Euler angle representation method of
     * @param ori Four-element representation method of
     * @return RS_SUCC success other failure
     */
    int rs_rpy_to_quaternion(RSHD rshd, const Rpy* rpy, Ori* ori);

    /**
     * @brief four elements to Euler angles
     * @param rshd arm control context handle
     * @param ori  gesture
     * @param rpy  Euler angle representation method of
     * @return RS_SUCC success other failure
     */
    int rs_quaternion_to_rpy(RSHD rshd, const Ori* ori, Rpy* rpy);

    /**
     * @brief sets the kinematic parameters of the tool
     * @param rshd arm control context handle
     * @param Tool kinematics parameters
     * @return RS_SUCC success other failure
     */
    int rs_set_tool_end_param(RSHD rshd, const ToolInEndDesc* tool);

    //end tool parameters
    /**
     * @brief sets the dynamics parameters without tools
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_set_none_tool_dynamics_param(RSHD rshd);

    /**
     * @brief sets the dynamics parameters of the tool
     * @param rshd arm control context handle
     * @param tool dynamics parameters
     * @return RS_SUCC success other failure
     */
    int rs_set_tool_dynamics_param(RSHD rshd, const ToolDynamicsParam* tool);

    /**
     * @brief gets the dynamic parameters of the tool
     * @param rshd arm control context handle
     * @param tool dynamics parameters
     * @return RS_SUCC success other failure
     */
    int rs_get_tool_dynamics_param(RSHD rshd, ToolDynamicsParam* tool);

    /**
     * @brief sets toolless kinematics parameters
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_set_none_tool_kinematics_param(RSHD rshd);

    /**
     * @brief sets the kinematic parameters of the tool
     * @param rshd arm control context handle
     * @param Tool kinematics parameters
     * @return RS_SUCC success other failure
     */
    int rs_set_tool_kinematics_param(RSHD rshd, const ToolKinematicsParam* tool);

    /**
     * @brief gets the kinematic parameters of the tool
     * @param rshd arm control context handle
     * @param Tool kinematics parameters
     * @return RS_SUCC success other failure
     */
    int rs_get_tool_kinematics_param(RSHD rshd, ToolKinematicsParam* tool);


    //robot control
    /**
     * @brief start the robotic arm
     * @param rshd arm control context handle
     * @param tool_dynamics dynamics parameters
     * @param colli_class collision class
     * @param Does read_pos allow to read position
     * @param static_colli_detect allows to detect static collisions
     * @param board_maxacc maximum acceleration allowed by the interface board
     * @param state robot arm startup state
     * @return RS_SUCC success other failure
     */
    int rs_robot_startup(RSHD rshd, const ToolDynamicsParam* tool_dynamics, uint8 colli_class, bool read_pos, bool static_colli_detect, int board_maxacc, ROBOT_SERVICE_STATE* state);

    /**
     * @brief closes the robotic arm
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_robot_shutdown(RSHD rshd);

    /**
     * @brief stop arm movement
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_move_stop(RSHD rshd);

    /**
     * @brief stop arm movement
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_move_fast_stop(RSHD rshd);

    /**
     * @brief pauses the arm movement
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_move_pause(RSHD rshd);

    /**
     * @brief resumes robotic arm motion after pause
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_move_continue(RSHD rshd);

    /**
     * @brief recovery after arm collision
     * @param rshd arm control context handle
     * @return RS_SUCC success other failure
     */
    int rs_collision_recover(RSHD rshd);

    /**
     * @brief gets the current state of the robotic arm
     * @param rshd arm control context handle
     * @param state The current state of the robotic arm
     * The robotic arm is currently stopped: RobotStatus.Stopped
     * The robotic arm is currently running: RobotStatus.Running
     * The robotic arm is currently paused: RobotStatus.Paused
     * The robotic arm is currently resumed: RobotStatus.Resumed
     * @return RS_SUCC success and other failures
     */
    int rs_get_robot_state(RSHD rshd, RobotState* state);

    //tool ​​interface


    //robot parameters
    /**
     * @brief sets the working mode of the robotic arm server
     * @param rshd arm control context handle
     * @param mode  Robot arm server working mode
     * Robot arm simulation mode: RobotRunningMode.RobotModeSimulator
     * Robot arm real mode: RobotRunningMode.RobotModeReal
     * @return RS_SUCC success other failure
     */
    int rs_set_work_mode(RSHD rshd, RobotWorkMode  mode);

    /**
     * @brief gets the current working mode of the robotic arm server
     * @param rshd arm control context handle
     * @param mode  Robot arm server working mode
     * Robot arm simulation mode: RobotRunningMode.RobotModeSimulator
     * Robot arm real mode: RobotRunningMode.RobotModeReal
     * @return RS_SUCC success other failure
     */
    int rs_get_work_mode(RSHD rshd, RobotWorkMode* mode);

    /**
     * @brief gets the gravity component
     * @param rshd arm control context handle
     * @param gravity gravity component
     * @return RS_SUCC success other failure
     */
    int rs_get_gravity_component(RSHD rshd, RobotGravityComponent* gravity);

    /**
     * @brief sets the collision level of the robot arm
     * @param rshd arm control context handle
     * @param grade collision level range (0～10)
     * @return RS_SUCC success other failure
     */
    int rs_set_collision_class(RSHD rshd, int grade);

    /**
     * @brief get device information
     * @param rshd arm control context handle
     * @param dev device information
     * @return RS_SUCC success other failure
     */
    int rs_get_device_info(RSHD rshd, RobotDevInfo* dev);

    /**
     * @brief gets whether the real robot arm is currently linked
     * @param rshd arm control context handle
     * @param exist true: exists false: does not exist
     * @return RS_SUCC success other failure
     */
    int rs_is_have_real_robot(RSHD rshd, bool* exist);

    /**
     * @brief Whether the current robotic arm is running in online mode
     * @param rshd arm control context handle
     * @param isonline true: in false: not
     * @return RS_SUCC success else failure
     */
    int rs_is_online_mode(RSHD rshd, bool* isonline);

    /**
     * @brief Whether the current robot arm is running in online master mode
     * @param rshd arm control context handle
     * @param ismaster true: master mode false: slave mode
     * @return RS_SUCC success other failure
     */
    int rs_is_online_master_mode(RSHD rshd, bool* ismaster);

    /**
     * @brief gets the current state information of the robotic arm
     * @param rshd arm control context handle
     * @param jointStatus returns six joint status including: current, voltage, temperature
     * @return RS_SUCC success other failure
     */
    int rs_get_joint_status(RSHD rshd, JointStatus jointStatus[ARM_DOF]);

    /**
     * @brief gets the current position information of the robot arm
     * @param rshd arm control context handle
     * @param waypoint joint position information
     * @return RS_SUCC success other failure
     */
    int rs_get_current_waypoint(RSHD rshd, wayPoint_S* waypoint);

    /**
     * @brief gets the robot arm diagnostic information
     * @param rshd arm control context handle
     * @param info robot arm diagnostic information
     * @return RS_SUCC success other failure
     */
    int rs_get_diagnosis_info(RSHD rshd, RobotDiagnosis* info);

    /**
     * @brief get socket link status
     * @param rshd arm control context handle
     * @param connected true: connected false: not connected
     * @return RS_SUCC success other failure
     */
    int rs_get_socket_status(RSHD rshd, bool* connected);

    /**
     * @brief gets the speed at the end of the mechanical watch
     * @param rshd arm control context handle
     * @param endspeed end speed unit (m/s)
     * @return RS_SUCC success other failure
     */
    int rs_get_robot_end_speed(RSHD rshd, float* endspeed);

    //IO interface
    /**
     * @brief gets the configuration information of the specified IO set of the interface board
     * @param rshd arm control context handle
     * @param type IO type
     * @param config IO configuration information collection
     * @return RS_SUCC success other failure
     */
    int rs_get_board_io_config(RSHD rshd, RobotIoType type, std::vector<RobotIoDesc>* config);

    /**
     * @brief sets the IO state according to the interface board IO type and address
     * @param rshd arm control context handle
     * @param type IO type
     * @param name IO name
     * @param val  IO status
     * @return RS_SUCC success other failure
     */
    int rs_set_board_io_status_by_name(RSHD rshd, RobotIoType type, const char* name, double val);

    /**
     * @brief sets the IO status according to the IO type and address of the interface board
     * @param rshd arm control context handle
     * @param type IO type
     * @param addr IO status
     * @param val  IO status
     * @return RS_SUCC success other failure
     */
    int rs_set_board_io_status_by_addr(RSHD rshd, RobotIoType type, int addr, double val);

    /**
     * @brief gets the IO status according to the IO type and address of the interface board
     * @param rshd arm control context handle
     * @param type IO type
     * @param name IO name
     * @param val  IO status
     * @return RS_SUCC success other failure
     */
    int rs_get_board_io_status_by_name(RSHD rshd, RobotIoType type, const char* name, double* val);

    /**
     * @brief gets the IO status according to the IO type and address of the interface board
     * @param rshd arm control context handle
     * @param type IO type
     * @param addr IO address
     * @param val
     * @return RS_SUCC success other failure
     */
    int rs_get_board_io_status_by_addr(RSHD rshd, RobotIoType type, int addr, double* val);

    //tool ​​device interface
    /**
     * @brief sets the power supply voltage type of the tool terminal
     * @param rshd arm control context handle
     * @param type power_type: power type
     * 0:.OUT_0V
     * 1:.OUT_12V
     * 2:.OUT_24V
     * @return RS_SUCC success other failure
     */
    int rs_set_tool_power_type(RSHD rshd, ToolPowerType type);

    /**
     * @brief gets the power supply voltage type of the tool end
     * @param rshd arm control context handle
     * @param type power_type: power type
     * 0:.OUT_0V
     * 1:.OUT_12V
     * 2:.OUT_24V
     * @return RS_SUCC success other failure
     */
    int rs_get_tool_power_type(RSHD rshd, ToolPowerType* type);

    /**
     * @brief sets the type of tool-side digital IO
     * @param rshd arm control context handle
     * @param addr address
     * @param type type 0: input 1: output
     * @return RS_SUCC success other failure
     */
    int rs_set_tool_io_type(RSHD rshd, ToolDigitalIOAddr addr, ToolIOType type);

    /**
     * @brief gets the tool terminal voltage value
     * @param rshd arm control context handle
     * @param voltage Voltage value, unit (volts)
     * @return RS_SUCC success other failure
     */
    int rs_get_tool_power_voltage(RSHD rshd, double* voltage);

    /**
     * @brief gets the tool-side IO status
     * @param rshd arm control context handle
     * @param name IO name
     * @param val tool-side IO status
     * @return RS_SUCC success other failure
     */
    int rs_get_tool_io_status(RSHD rshd, const char* name, double* val);

    /**
     * @brief sets the IO status of the tool side
     * @param rshd arm control context handle
     * @param name IO name
     * @param status Tool-side IO status
     * @return RS_SUCC success other failures
     */
    int rs_set_tool_do_status(RSHD rshd, const char* name, IO_STATUS status);

    //callback
    /**
     * @brief registers the callback function for getting real-time waypoints
     * @param rshd arm control context handle
     * @param ptr function pointer to get real-time waypoint information
     * @param arg This parameter system does not do any processing, but only caches it. When the callback function is triggered, the parameter will be returned through the parameters of the callback function.
     * @return RS_SUCC success and other failures
     */
    int rs_setcallback_realtime_roadpoint(RSHD rshd, const RealTimeRoadPointCallback ptr, void* arg);

    /**
     * @brief registers callback function for getting joint state
     * @param rshd arm control context handle
     * @param ptr function pointer to get real-time joint state information
     * @param arg This parameter system does not do any processing, but only caches it. When the callback function is triggered, the parameter will be returned through the parameters of the callback function.
     * @return RS_SUCC success and other failures
     */
    int rs_setcallback_realtime_joint_status(RSHD rshd, const RealTimeJointStatusCallback ptr, void* arg);

    /**
     * @brief registers the callback function used to get the real-time end speed
     * @param rshd arm control context handle
     * @param ptr function pointer to get real-time terminal velocity
     * @param arg parameter system does not do any processing, but just caches it. When the callback function is triggered, the parameter will be returned through the parameters of the callback function.
     * @return RS_SUCC success and other failures
     */
    int rs_setcallback_realtime_end_speed(RSHD rshd, const RealTimeEndSpeedCallback ptr, void* arg);

    /**
     * @brief registers the callback function used to get the event information of the robot arm
     * @param rshd arm control context handle
     * @param ptr function pointer to get the event information of the manipulator
     * @param arg parameter system does not do any processing, but just caches it. When the callback function is triggered, the parameter will be returned through the parameters of the callback function.
     * @return RS_SUCC success and other failures
     */
    int rs_setcallback_robot_event(RSHD rshd, const RobotEventCallback ptr, void* arg);


    //enable push information
    /**
     * @brief sets whether to allow real-time waypoint information push
     * @param rshd arm control context handle
     * @param enable true means allow false means not allow
     * @return RS_SUCC success other failure
     */
    int rs_enable_push_realtime_roadpoint(RSHD rshd, bool enable);

    /**
     * @brief sets whether to allow real-time joint state push
     * @param rshd arm control context handle
     * @param enable true means allow false means not allow
     * @return RS_SUCC success other failure
     */
    int rs_enable_push_realtime_joint_status(RSHD rshd, bool enable);

    /**
     * @brief sets whether to allow real-time end speed push
     * @param rshd arm control context handle
     * @param enable true means allow false means not allow
     * @return RS_SUCC success other failure
     */
    int rs_enable_push_realtime_end_speed(RSHD rshd, bool enable);


#ifdef __cplusplus
}
#endif


#endif // RSDEF_H

#ifndef AUBOROBOTMETATYPE_H
#define AUBOROBOTMETATYPE_H

#include <iostream>
#include <stdint.h>

/* General types */
typedef  uint8_t     boolean;
typedef  int8_t      int8;
typedef  int16_t     int16;
typedef  int32_t     int32;
typedef  uint8_t     uint8;
typedef  uint16_t    uint16;
typedef  uint32_t    uint32;
typedef  int64_t     int64;
typedef  uint64_t    uint64;
typedef  float       float32;
typedef  double      float64;

#ifdef __cplusplus
extern "C" {
#endif
    namespace aubo_robot_namespace
    {
        enum { ARM_DOF = 6 };

#pragma pack(1)

        typedef struct {
            char hw_version[8];
            char sw_version[16];
        }JointVersion;

        typedef struct {
            char productID[16];
        }JointProductID;


        typedef struct
        {

            uint8 type;

            char revision[16];

            char manu_id[16];

            char joint_type[16];

            JointVersion joint_ver[8];

            char desc[64];

            JointProductID jointProductID[8];


            char slave_version[16];

            char extio_version[16];

        }RobotDevInfo;


        typedef struct
        {
            int    jointCurrentI;       /**< Current of driver   */
            int    jointSpeedMoto;      /**< Speed of driver */
            float  jointPosJ;           /**< Current position in radian */
            float  jointCurVol;         /**< Rated voltage of motor. Unit: mV */
            float  jointCurTemp;        /**< Current temprature of joint */
            int    jointTagCurrentI;    /**< Target current of motor */
            float  jointTagSpeedMoto;   /**< Target speed of motor */
            float  jointTagPosJ;        /**< Target position of joint in radian */
            uint16 jointErrorNum;       /**< Joint error of joint num */
        }JointStatus;



        typedef enum {
            RobotEvent_armCanbusError,
            RobotEvent_remoteHalt,
            RobotEvent_remoteEmergencyStop,
            RobotEvent_jointError,

            RobotEvent_forceControl,
            RobotEvent_exitForceControl,

            RobotEvent_softEmergency,
            RobotEvent_exitSoftEmergency,

            RobotEvent_collision,
            RobotEvent_collisionStatusChanged,
            RobotEvent_tcpParametersSucc,
            RobotEvent_powerChanged,
            RobotEvent_ArmPowerOff,
            RobotEvent_mountingPoseChanged,
            RobotEvent_encoderError,

            RobotEvent_encoderLinesError,
            RobotEvent_singularityOverspeed,
            RobotEvent_currentAlarm,
            RobotEvent_toolioError,
            RobotEvent_robotStartupPhase,
            RobotEvent_robotStartupDoneResult,
            RobotEvent_robotShutdownDone,
            RobotEvent_atTrackTargetPos,

            RobotSetPowerOnDone,
            RobotReleaseBrakeDone,
            RobotEvent_robotControllerStateChaned,
            RobotEvent_robotControllerError,
            RobotEvent_socketDisconnected,

            RobotEvent_robotControlException,
            RobotEvent_trackPlayInterrupte,

            RobotEvent_staticCollisionStatusChanged,
            RobotEvent_MountingPoseWarning,
            RobotEvent_MacDataInterruptWarning,
            RobotEvent_ToolIoError,
            RobotEvent_InterfacBoardSafeIoEvent,

            RobotEvent_RobotHandShakeSucc,
            RobotEvent_RobotHandShakeFailed,

            RobotEvent_RobotErrorInfoNotify,


            RobotEvent_exceptEvent = 100,

            //unknown event
            robot_event_unknown,

            //user event
            RobotEvent_User = 1000,                            // first user event id
            RobotEvent_MaxUser = 65535                         // last user event id

        }RobotEventType;


        typedef enum
        {
            RobotControllerErr_MotionCfgErr,    //only this is recoverable.
            RobotControllerErr_OverspeedProtect,
            RobotControllerErr_IkFailure,
            RobotControllerErr_OnlineTrajErr,
            RobotControllerErr_OfflineTrajErr,
            RobotControllerErr_StatusException,
        }RobotControllerErrorCode;


        typedef enum {
            RUN_TO_READY_POSITION,
            RUN_PROJECT,
            PAUSE_PROJECT,
            CONTINUE_PROJECT,
            SLOWLY_STOP_PROJECT,
            LOAD_PROJECT,
            ENTER_SAFEGUARD_MODE_BY_DI_EXTERNAL_SAFEGUARD_STOP,
            RELEASE_SAFEGUARD_MODE_IN_AUTOMATIC_MODE,
            RELEASE_SAFEGUARD_MODE_IN_MANUAL_MODE,
            MANUALLY_RELEASE_SAFEGUARD_MODE_PROMPT,
            ENTER_SAFEGUARD_MODE_BY_TRI_STATE_SWITCH,
            RELEASE_SAFEGUARD_MODE_BY_TRI_STATE_SWITCH,
            ENTER_REDUCE_MODE,
            RELEASE_REDUCE_MODE,
        }InterfaceBoardSafeIoEventCode;


        typedef enum {
            RobotToolNoError = 0,
            RobotToolOverVoltage = 1,
            RobotToolUnderVoltage = 2,
            RobotToolOVerTemp = 3,
            RobotToolCanBusError = 4
        }RobotToolErrorCode;



        typedef struct {
            RobotEventType  eventType;
            int             eventCode;
            std::string     eventContent;
        }RobotEventInfo;





        typedef struct
        {
            float x;
            float y;
            float z;
        }RobotGravityComponent;



        typedef struct
        {

            uint8 armCanbusStatus;

            float armPowerCurrent;

            float armPowerVoltage;

            bool  armPowerStatus;

            char  contorllerTemp;

            uint8 contorllerHumidity;

            bool  remoteHalt;

            bool  softEmergency;

            bool  remoteEmergency;

            bool  robotCollision;

            bool  forceControlMode;

            bool brakeStuats;

            float robotEndSpeed;

            int robotMaxAcc;

            bool orpeStatus;

            bool enableReadPose;

            bool robotMountingPoseChanged;

            bool encoderErrorStatus;

            bool staticCollisionDetect;

            uint8 jointCollisionDetect;

            bool encoderLinesError;
            //joint error status
            bool jointErrorStatus;

            bool singularityOverSpeedAlarm;

            bool robotCurrentAlarm;

            uint8 toolIoError;

            bool robotMountingPoseWarning;

            uint16 macTargetPosBufferSize;

            uint16 macTargetPosDataSize;

            uint8  macDataInterruptWarning;

        }RobotDiagnosis;




        typedef struct
        {

            uint8_t robot_state;

            uint8_t robot_status;

            float target_pos[6];

            float theoretical_speed[6];

            float theoretical_acc[6];

            int32_t theoretical_current[6];
        }RobotExtDiagnosis;

        typedef struct
        {
            uint16  robotReducedConfigJointSpeed[6];
            uint32  robotReducedConfigTcpSpeed;
            uint32  robotReducedConfigTcpForce;
            uint32  robotReducedConfigMomentum;
            uint32  robotReducedConfigPower;
            uint8   robotSafeguradResetConfig;
            uint8   robotOperationalModeConfig;
        }RobotSafetyConfig;


        typedef struct
        {
            uint8 orpePause;
            uint8 orpeStop;
            uint8 orpeError[16];
            uint8 systemEmergencyStop;
            uint8 reducedModeError;
            uint8 safetyguardResetSucc;
        }OrpeSafetyStatus;


        typedef struct
        {
            uint8  OriginPoseState;
            float   OriginPose[6];
        }OriginPose;



        typedef struct
        {

            uint8 ioData;

            float aiData[2];

            float systemVoltage;

            float systemTemperature;

            uint8 errorStatus;
        }RobotToolStatus;

        typedef struct
        {



            uint8 config[4];
        }RobotToolConfig;


        typedef enum {
            RobotModeSimulator,
            RobotModeReal
        }RobotWorkMode;

#pragma pack()



        typedef enum
        {
            RobotBoardControllerDI,
            RobotBoardControllerDO,
            RobotBoardControllerAI,
            RobotBoardControllerAO,

            RobotBoardUserDI,
            RobotBoardUserDO,
            RobotBoardUserAI,
            RobotBoardUserAO,

            RobotToolDI,
            RobotToolDO,
            RobotToolAI,
            RobotToolAO,

        }RobotIoType;


        typedef enum
        {
            RobotToolIoTypeDI = RobotToolDI,
            RobotToolIoTypeDO = RobotToolDO
        }RobotToolIoType;



        typedef struct
        {
            char        ioId[32];
            RobotIoType ioType;
            char        ioName[32];
            int         ioAddr;
            double      ioValue;
        }RobotIoDesc;


        typedef enum
        {
            OUT_0V = 0,
            OUT_12V = 1,
            OUT_24V = 2
        }ToolPowerType;

        typedef  enum
        {
            IO_STATUS_INVALID = 0,
            IO_STATUS_VALID
        }IO_STATUS;


        typedef enum
        {
            TOOL_DIGITAL_IO_0 = 0,
            TOOL_DIGITAL_IO_1 = 1,
            TOOL_DIGITAL_IO_2 = 2,
            TOOL_DIGITAL_IO_3 = 3

        }ToolDigitalIOAddr;


        typedef enum
        {
            IO_IN = 0,
            IO_OUT
        }ToolIOType;


        typedef struct
        {
            uint8 addr;
            uint8 value;
            uint8 type;
        }RobotDiagnosisIODesc;


        typedef struct
        {
            uint8  addr;
            float  value;
            uint8 type;
        }RobotAnalogIODesc;

        typedef enum {
            RobotMoveStop = 0,
            RobotMovePause = 1,
            RobotMoveContinue = 2,
        }RobotMoveControlCommand;


        enum RobotControlCommand {
            RobotRelease = 0,
            RobotBrake = 1,
            OverspeedWarning = 2,
            OverspeedRecover = 3,
            DisableForceControl = 4,
            EnableForceControl = 5,
            OrpeOpen = 6,
            OrpeClose = 7,
            EnableReadPose = 8,
            DisableReadPose = 9,
            MountingPoseChanged = 10,
            MountingPoseUnChanged = 11,
            EnableStaticCollisionDetect = 12,
            DisableStaticCollisionDetect = 13,
            ClearSingularityOverSpeedAlarm = 14,
            ClearRobotCurrentAlarm = 15
        };


        enum Robot_Dyn_identify_traj
        {
            Dyn_identify_traj_none = 0,
            Dyn_identify_traj_robot, //submode: 0/1 <-> internal/hybrid
            Dyn_identify_traj_tool,  //submode: 0/1 <-> tool only/tool+friction
            Dyn_identify_traj_tool_abort
        };




        enum ROBOT_INIT_PHASE {
            ROBOT_INIT_PHASE_READY = 0,
            ROBOT_INIT_PHASE_HANDSHAKE,
            ROBOT_INIT_PHASE_SET_POWER,
            ROBOT_INIT_PHASE_SET_BRAKE,
            ROBOT_INIT_PHASE_SET_COLLSION_CLASS,
            ROBOT_INIT_PHASE_SET_OTHER_CMD,
            ROBOT_INIT_PHASE_WORKING
        };

        enum ROBOT_SERVICE_STATE {
            ROBOT_SERVICE_READY = 0,
            ROBOT_SERVICE_STARTING,
            ROBOT_SERVICE_WORKING,
            ROBOT_SERVICE_CLOSING,
            ROBOT_SERVICE_CLOSED,
            ROBOT_SETVICE_FAULT_POWER,
            ROBOT_SETVICE_FAULT_BRAKE,
            ROBOT_SETVICE_FAULT_NO_ROBOT
        };



        enum RobotState
        {
            RobotStopped = 0,
            RobotRunning,
            RobotPaused,
            RobotResumed
        };


        enum move_mode
        {
            NO_MOVEMODE = 0,
            MODEJ,
            MODEL,
            MODEP
        };


        enum move_track
        {
            NO_TRACK = 0,

            //for moveJ and moveL
            TRACKING,

            //cartesian motion for movep
            ARC_CIR,
            CARTESIAN_MOVEP,
            CARTESIAN_CUBICSPLINE,
            CARTESIAN_UBSPLINEINTP,

            //joint motion  for movep
            JIONT_CUBICSPLINE,
            JOINT_UBSPLINEINTP,
        };



        enum coordinate_refer
        {
            BaseCoordinate = 0,
            EndCoordinate,
            WorldCoordinate
        };



        enum teach_mode
        {
            NO_TEACH = 0,
            JOINT1,
            JOINT2,
            JOINT3,
            JOINT4,
            JOINT5,
            JOINT6,
            MOV_X,
            MOV_Y,
            MOV_Z,
            ROT_X,
            ROT_Y,
            ROT_Z
        };



        struct Pos
        {
            double x;
            double y;
            double z;
        };


        union cartesianPos_U
        {
            Pos position;
            double positionVector[3];
        };



        struct Ori
        {
            double w;
            double x;
            double y;
            double z;
        };


        struct Rpy
        {
            double rx;
            double ry;
            double rz;
        };



        typedef struct
        {
            cartesianPos_U cartPos;

            Ori orientation;

            double jointpos[ARM_DOF];
        }wayPoint_S;



        typedef struct
        {
            double jointPara[ARM_DOF];
        }JointVelcAccParam;


        typedef struct
        {
            double jointPos[ARM_DOF];
        }JointParam;



        typedef struct
        {
            bool  ena;

            float relativePosition[3];

            Ori   relativeOri;

        }MoveRelative;





        typedef struct
        {
            Pos        toolInEndPosition;

            Ori        toolInEndOrientation;
        }ToolInEndDesc;


        typedef ToolInEndDesc ToolKinematicsParam;



        enum ToolKinematicsOriCalibrateMathod {
            ToolKinematicsOriCalibrateMathod_Invalid = -1,

            ToolKinematicsOriCalibrateMathod_xOxy,
            ToolKinematicsOriCalibrateMathod_yOyz,
            ToolKinematicsOriCalibrateMathod_zOzx,

            ToolKinematicsOriCalibrateMathod_TxRBz_TxyPBzAndTyABnz,
            ToolKinematicsOriCalibrateMathod_TyRBz_TyzPBzAndTzABnz,
            ToolKinematicsOriCalibrateMathod_TzRBz_TzxPBzAndTxABnz,
            ToolKinematicsOriCalibrateMathodCount
        };



        typedef struct
        {
            double xx;
            double xy;
            double xz;
            double yy;
            double yz;
            double zz;
        }ToolInertia;



        typedef struct
        {
            double positionX;

            double positionY;

            double positionZ;

            double payload;

            ToolInertia toolInertia;

        }ToolDynamicsParam;




        enum CoordCalibrateMathod
        {
            Origin_AnyPointOnPositiveXAxis_AnyPointOnPositiveYAxis,
            Origin_AnyPointOnPositiveYAxis_AnyPointOnPositiveZAxis,
            Origin_AnyPointOnPositiveZAxis_AnyPointOnPositiveXAxis,
            Origin_AnyPointOnPositiveXAxis_AnyPointOnFirstQuadrantOfXOYPlane,
            Origin_AnyPointOnPositiveXAxis_AnyPointOnFirstQuadrantOfXOZPlane,
            Origin_AnyPointOnPositiveYAxis_AnyPointOnFirstQuadrantOfYOZPlane,
            Origin_AnyPointOnPositiveYAxis_AnyPointOnFirstQuadrantOfYOXPlane,
            Origin_AnyPointOnPositiveZAxis_AnyPointOnFirstQuadrantOfZOXPlane,
            Origin_AnyPointOnPositiveZAxis_AnyPointOnFirstQuadrantOfZOYPlane,

            CoordTypeCount
        };



        typedef struct
        {
            coordinate_refer    coordType;

            CoordCalibrateMathod methods;

            JointParam       wayPointArray[3];

            ToolInEndDesc    toolDesc;

        }CoordCalibrateByJointAngleAndTool;




        enum
        {
            InterfaceCallSuccCode = 0,
        };

        typedef enum
        {
            ErrnoSucc = aubo_robot_namespace::InterfaceCallSuccCode,

            ErrCode_Base = 10000,
            ErrCode_Failed,
            ErrCode_ParamError,
            ErrCode_ConnectSocketFailed,
            ErrCode_SocketDisconnect,
            ErrCode_CreateRequestFailed,
            ErrCode_RequestRelatedVariableError,
            ErrCode_RequestTimeout,
            ErrCode_SendRequestFailed,
            ErrCode_ResponseInfoIsNULL,
            ErrCode_ResolveResponseFailed,
            ErrCode_FkFailed,
            ErrCode_IkFailed,
            ErrCode_ToolCalibrateError,
            ErrCode_ToolCalibrateParamError,
            ErrCode_CoordinateSystemCalibrateError,
            ErrCode_BaseToUserConvertFailed,
            ErrCode_UserToBaseConvertFailed,

            // move
            ErrCode_MotionRelatedVariableError,
            ErrCode_MotionRequestFailed,
            ErrCode_CreateMotionRequestFailed,
            ErrCode_MotionInterruptedByEvent,
            ErrCode_MotionWaypointVetorSizeError,
            ErrCode_ResponseReturnError,
            ErrCode_RealRobotNoExist,


            ErrCode_Count = ErrCode_RealRobotNoExist - ErrCode_Base + 2,

        }RobotErrorCode;

    }
#ifdef __cplusplus
}
#endif

typedef void (*RealTimeJointStatusCallback)(const aubo_robot_namespace::JointStatus* jointStatus, int size, void* arg);

typedef void (*RealTimeRoadPointCallback)  (const aubo_robot_namespace::wayPoint_S* wayPoint, void* arg);

typedef void (*RealTimeEndSpeedCallback)  (double speed, void* arg);

typedef void (*RobotEventCallback)         (const aubo_robot_namespace::RobotEventInfo* eventInfo, void* arg);

#endif // AUBOROBOTMETATYPE_H

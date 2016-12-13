# -*- encoding: UTF-8 -*- 

''' Whole Body Motion: Left or Right Arm position control '''

import sys
import motion
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python texttospeech_setparameter.py IP [PORT]'"
    sys.exit(1)

IP = sys.argv[1]
PORT = 9559

def StiffnessOn(proxy):
    # We use the "Body" name to signify the collection of all joints
    pNames = "Body"
    pStiffnessLists = 1.0
    pTimeLists = 1.0
    proxy.stiffnessInterpolation(pNames, pStiffnessLists, pTimeLists)


def main(robotIP, effectorName):
    ''' Example of a whole body Left or Right Arm position control
        Warning: Needs a PoseInit before executing
                 Whole body balancer must be inactivated at the end of the script
    '''

    # Init proxies.
    try:
        motionProxy = ALProxy("ALMotion", IP, PORT)
    except Exception, e:
        print "Could not create proxy to ALMotion"
        print "Error was: ", e

    try:
        postureProxy = ALProxy("ALRobotPosture", IP, PORT)
    except Exception, e:
        print "Could not create proxy to ALRobotPosture"
        print "Error was: ", e

    # Set NAO in Stiffness On
    StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    postureProxy.goToPosture("StandZero", 0.5)

    space     = motion.FRAME_ROBOT
    useSensor = False

    effectorInit = motionProxy.getPosition(effectorName, space, useSensor)

    # Active LArm tracking
    isEnabled = True
    motionProxy.wbEnableEffectorControl(effectorName, isEnabled)

    # Example showing how to set position target for LArm
    # The 3 coordinates are absolute LArm position in NAO_SPACE
    # Position in meter in x, y and z axis.

    # X Axis LArm Position feasible movement = [ +0.00, +0.12] meter
    # Y Axis LArm Position feasible movement = [ -0.05, +0.10] meter
    # Y Axis RArm Position feasible movement = [ -0.10, +0.05] meter
    # Z Axis LArm Position feasible movement = [ -0.10, +0.10] meter

  

    targetCoordinateList = [
    [ +0.12, +0.00, +0.00], # target 0
    [ +0.12, +0.00, -0.10], # target 1

    ]


    # wbSetEffectorControl is a non blocking function
    # time.sleep allow head go to his target
    # The recommended minimum period between two successives set commands is
    # 0.2 s.
    for targetCoordinate in targetCoordinateList:
        targetCoordinate = [targetCoordinate[i] + effectorInit[i] for i in range(3)]
        motionProxy.wbSetEffectorControl(effectorName, targetCoordinate)
        time.sleep(4.0)

    # Deactivate Head tracking
    isEnabled    = False
    motionProxy.wbEnableEffectorControl(effectorName, isEnabled)


if __name__ == "__main__":
    robotIp      = "IP"
    effectorName = "LArm"

    if (len(sys.argv) <= 1):
        print "Usage python motion_wbEffectorControlArm.py robotIP(optional default: 127.0.0.1) effectorName(RArm or LArm)"

    else:
        if (len(sys.argv) > 1):
            robotIp = sys.argv[1]

        if (len(sys.argv) > 2):
            effectorName = sys.argv[2]

    main(robotIp, effectorName)

# -*- encoding: UTF-8 -*-

import sys
from naoqi import ALProxy
import time
import almath


def main(robotIP):
    PORT = 9559

    try:
        motionProxy = ALProxy("ALMotion", robotIP, PORT)
    except Exception,e:
        print "Could not create proxy to ALMotion"
        print "Error was: ",e
        sys.exit(1)

    
    motionProxy.setStiffnesses("Body", 0.0)

    

    # Simple command for the HeadYaw joint at 10% max speed
    names            = "LShoulderPitch"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.4
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

     # Simple command for the HeadYaw joint at 10% max speed
    names            = "LShoulderRoll"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    # Simple command for the HeadYaw joint at 10% max speed
    names            = "LElbowRoll"
    angles           = -25*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    # Simple command for the HeadYaw joint at 10% max speed
    names            = "LElbowYaw"
    angles           = -85*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    # Simple command for the HeadYaw joint at 10% max speed
    names            = "LWristYaw"
    angles           = -104*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    # Simple command for the Hip joint at 10% max speed
    names            = "LHipYawPitch"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)
     # Simple command for the Hip joint at 10% max speed
    names            = "RHipYawPitch"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)
    
    time.sleep(3.0)
    # Simple command for the HeadYaw joint at 10% max speed
    names            = "LHand"
    angles           = 1.0
    fractionMaxSpeed = 0.5
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

if __name__ == "__main__":
    robotIp = "192.168.1.21"

    if len(sys.argv) <= 1:
        print "Usage python almotion_controllingjoints.py robotIP (optional default: 127.0.0.1)"
    else:
        robotIp = sys.argv[1]

    main(robotIp)

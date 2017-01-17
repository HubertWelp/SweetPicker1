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

    try:
        postureProxy = ALProxy("ALRobotPosture", robotIP, PORT)
    except Exception,e:
        print "Could not create proxy to AlRobotPosture"
        print "Error was: ",e
        sys.exit(1)

    try:
	tts = ALProxy("ALTextToSpeech", robotIP, PORT)
    except Exception,e:
	print "Could not create proxy to ALTextToSpeech"
	print "Error was: ",e
	sys.exit(1)


    tts.say("\\rspd=100\\\\vct=100\\Ja mein Lehnsherr")
    postureProxy.goToPosture("Crouch",1.0)

    time.sleep(3.0)
 
    motionProxy.setStiffnesses("Body", 0.0)
    motionProxy.setStiffnesses("LArm", 0.3)

    # Simple command for the LShoulderRoll joint at 10% max speed
    names            = "LShoulderRoll"
    angles           = 30*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    time.sleep(1.0)
    
    # Simple command for the LShoulderPitch joint at 10% max speed
    names            = "LShoulderPitch"
    angles           = 100*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    time.sleep(1.0)

     # Simple command for the LElbowRoll joint at 10% max speed
    names            = "LElbowRoll"
    angles           = -2*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    time.sleep(1.0)
    
    # Simple command for the LElbowYaw joint at 10% max speed
    names            = "LElbowYaw"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)
   

    # Simple command for the LWristYaw joint at 10% max speed
    names            = "LWristYaw"
    angles           = -100*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    time.sleep(1.0)
    motionProxy.setStiffnesses("LArm", 0.0)

    tts.say("Mehr Arbeit? Arbeit muss getan werden")

if __name__ == "__main__":
    robotIp = "192.168.0.79"

    if len(sys.argv) <= 1:
        print "Benutze PostureReset.py um NAO in Ausgangsposition zu bringen"
    else:
        robotIp = sys.argv[1]

    main(robotIp)

# -*- encoding: UTF-8 -*-

import sys
from naoqi import ALProxy
import time
import almath




def main(robotIP,roll,pitch):
    PORT = 9559

    try:
        motionProxy = ALProxy("ALMotion", robotIP, PORT)
    except Exception,e:
        print "Could not create proxy to ALMotion"
        print "Error was: ",e
        sys.exit(1)
 

    motionProxy.setStiffnesses("LArm", 0.3)

    #Nur RSchulder Joints veraendern

    # Simple command for the LShoulderR joint at 10% max speed
    names            = "LShoulderRoll"
    angles           = roll*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)

    time.sleep(0.5)
    
    # Simple command for the LShoulderP joint at 10% max speed
    names            = "LShoulderPitch"
    angles           = pitch*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)


    time.sleep(5.0)

 

    
    
    # Simple command for the LShoulderPitch joint at 10% max speed
    names            = "LShoulderPitch"
    angles           = 100*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)
	
    time.sleep(1.0)
	
    # Simple command for the LShoulderRoll joint at 10% max speed
    names            = "LShoulderRoll"
    angles           = 0*almath.TO_RAD
    fractionMaxSpeed = 0.2
    motionProxy.setAngles(names,angles,fractionMaxSpeed)
	
    time.sleep(1.0)
	
    motionProxy.setStiffnesses("LArm", 0.0)
	


if __name__ == "__main__":
    robotIp = "192.168.0.79"

    if len(sys.argv) <= 2:
        print "Geben Sie Roll und Pitch für die Linke Schulter an"
    else:
        roll = 10+float(sys.argv[1])
        pitch = 100-float(sys.argv[2])

    main(robotIp,roll,pitch)

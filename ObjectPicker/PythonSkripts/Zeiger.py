# -*- encoding: UTF-8 -*-

import os
import sys
from naoqi import ALProxy
import time
import almath
import json

RobotIP = "192.168.0.79"
RobotPORT = 9559

Distanz = sys.argv[1]
PolarWinkel = sys.argv[2]

print(type(int(Distanz)))
print(Distanz)
print(type(PolarWinkel))
print(PolarWinkel)

D = "Default"
P = "Default"


D = int(Distanz)
P = int(PolarWinkel)
print(type(D))
print(D)


try:
    tts = ALProxy("ALTextToSpeech", RobotIP, RobotPORT)
except Exception,e:
    print "Could not create proxy to ALTextToSpeech"
    print "Error was: ",e
    sys.exit(1)

try:
    motionProxy = ALProxy("ALMotion", RobotIP, RobotPORT)
except Exception,e:
        print "Could not create proxy to ALMotion"
        print "Error was: ",e
        sys.exit(1)

#tts.say("Distanz zum riegel ist"+Distanz+"Winkel zu riegel ist"+PolarWinkel)

motionProxy.setStiffnesses("LArm", 0.3)

# Anfang bewegung zu RP1
names            = "LShoulderRoll"
angles           = (D+12)*almath.TO_RAD
fractionMaxSpeed = 0.2
motionProxy.setAngles(names,angles,fractionMaxSpeed)

# Anfang bewegung zu RP1
names            = "LShoulderPitch"
angles           = (100-(P))*almath.TO_RAD
fractionMaxSpeed = 0.2
motionProxy.setAngles(names,angles,fractionMaxSpeed)

time.sleep(3.0)

tts.say("Da ist der Schokoriegel. Mars")
time.sleep(5.0)

# Simple command for the LShoulderPitch joint at 10% max speed
names            = "LShoulderPitch"
angles           = 100*almath.TO_RAD
fractionMaxSpeed = 0.2
motionProxy.setAngles(names,angles,fractionMaxSpeed)

time.sleep(1.0)

# Simple command for the LShoulderRoll joint at 10% max speed
names            = "LShoulderRoll"
angles           = 3*almath.TO_RAD
fractionMaxSpeed = 0.2
motionProxy.setAngles(names,angles,fractionMaxSpeed)

time.sleep(3.0)
    
motionProxy.setStiffnesses("LArm", 0.0)




    

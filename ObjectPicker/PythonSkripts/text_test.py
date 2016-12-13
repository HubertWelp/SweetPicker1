import sys
from naoqi import ALProxy

#if (len(sys.argv) < 2):
#    print "Usage: 'python texttospeech_setparameter.py IP [PORT]'"
#    sys.exit(1)

#IP = 192.168.0.21 #sys.argv[1]
#PORT = 9559
#if (len(sys.argv) > 2):
#   PORT = sys.argv[2]
try:
    tts = ALProxy("ALTextToSpeech", "192.168.0.21", 9559)
except Exception,e:
    print "Could not create proxy to ALTextToSpeech"
    print "Error was: ",e
    sys.exit(1)

tts.say("\\rspd=60\\\\vct=70\\Ich will nicht mehr leben \\pau=500\\ toete mich")

tts.say("\\rspd=80\\\\vct=70\\Der Semelka hat mich vergewaltigt\\pau=500\\ und mich emotional verletzt")
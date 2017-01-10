from naoqi import ALProxy
tts = ALProxy("ALTextToSpeech", "192.168.0.79", 9559)
tts.say("zeiger test!")
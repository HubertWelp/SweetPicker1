from naoqi import ALProxy
tts = ALProxy("ALTextToSpeech", "169.254.42.173", 9559)
tts.say("Hello, world!")

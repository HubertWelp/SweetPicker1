# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import os
import sys
from naoqi import ALProxy


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, rc):
	print("Connected with result code "+str(rc))
# Subscribing in on_connect() means that if we lose the connection and
# reconnect then subscriptions will be renewed.
	client.subscribe("THGA/SWT/SweetPicker/Roboteraktionen/Georg")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
	try:
		tts = ALProxy("ALTextToSpeech", "192.168.0.79", 9559)
	except Exception,e:
		print "Could not create proxy to ALTextToSpeech"
		print "Error was: ",e
		sys.exit(1)

	#Applies a pitch shifting to the voice
	tts.setParameter("pitchShift", 1.0)
	#Deactivates double voice
	tts.setParameter("doubleVoice", 0.0)

	tts.say("\\rspd=80\\\\vct=75\\Steck dir deinen Schockoriegel sonst wohin"+str(msg.payload))
	#print'Topic: ', msg.topic+'\nMessage: '+str(msg.payload)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("192.168.0.1", 8883, 60)

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.
client.loop_forever()

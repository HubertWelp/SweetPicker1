# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import os
import sys
import json
from naoqi import ALProxy


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, rc):
	print("Connected with result code "+str(rc))
# Subscribing in on_connect() means that if we lose the connection and
# reconnect then subscriptions will be renewed.
	client.subscribe("THGA/SWT/SweetPicker/Roboteraktionen/Georg")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
        parsed_msg = json.loads(msg)
		if Aktion == 'Sprechen'
			#try except ALtts
		if Aktion == 'Zeigen'
			ObjectPicker_zeigen(parsed_msg['Distanz'],parsed_msg['PolarWikel'],parse_msg['RotWinkel'])
		else 
			print "Aktion ist nicht definiert"
			sys.exit(1)

def ObjectPicker_publish(Topic,msg)

        callstring = "mqttpublisher.py"+" "+brokerIP+" "+brokerPort+" "+Topic+" "+msg
        try:
		os.system(callstring)
	except Exception,e:
		print "Konnte das publish_Skript nicht starten"
		print "Error war:  ",e
		sys.exit(1)

def ObjectPicker_reset():       
        try:
		os.system("PostureReset.py")
		ObjectPicker_publish("THGA/SWT/SweetPicker/Roboterantwort/Georg", "Reset erfolgreich")	
	except Exception,e:
		print "Konnte das reset_Skript nicht starten"
		print "Error war:  ",e
def ObjectPicker_zeigen(Distanz,PolarWinkel,RotWinkel)
        try:
                callstring = "Zeiger.py"+" "+Distanz+" "+PolarWinkel
                os.system(callstring)
        except Exception,e:
                print "Konnte das zeigen_Skript nicht starten"
                print "Error war: ",e
	

	

	
	
brokerIp = "192.168.0.1"
brokerPort = "8883"
naoIp = "192.168.0.21"
naoPort = 9559
ObjectPicker_reset()
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(brokerIp, brokerPort, 60)
client.loop_forever()

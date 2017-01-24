# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import os
import sys
import json
import time
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
                msg2 = str(msg.payload)
                nachricht = "Hallo"+msg2+"ende"
                print(nachricht)
                #msg_dumps = json.dumps(msg)
                #print(msg_dumps)
                parsed_msg = json.loads(msg2)
                print(parsed_msg)
                Distanz = parsed_msg['Distanz']
                PolarWinkel = parsed_msg['PolarWinkel']
                #Dz = int(Distanz)
                #Pw = int(PolarWinkel)
                #RotWinkel = parsed_msg['RotWinkel']
                print (Distanz)
                print (PolarWinkel)

                #print (RotWinkel)
                ObjectPicker_zeigen(Distanz,PolarWinkel)
                
        except Exception,e:
		print "auf on_massage ist ein fehler aufgetreten"
		print "Error war:  ",e
		sys.exit(1)

def ObjectPicker_publish(Topic,msg):
        
        callstring = "mqttpublisher.py"+" "+brokerIp+" "+brokerPort+" "+Topic+" "+msg
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
		
def ObjectPicker_zeigen(Distanz,PolarWinkel):
        try:
                time.sleep(3.0)
                
                callstring = "Zeiger.py"+" "+str(Distanz)+" "+str(PolarWinkel)
                os.system(callstring)
        except Exception,e:
                print "Konnte das zeigen_Skript nicht starten"
                print "Error war: ",e
	

	

msg = "default"	
Distanz = "Default"
PolarWinkel = "Default"
RotWinkel = "Default"
brokerIp = "192.168.0.1"
brokerPort = "8883"
naoIp = "192.168.0.79"
naoPort = 9559
ObjectPicker_reset()
client = mqtt.Client("Georg")
client.on_connect = on_connect
client.on_message = on_message
client.connect(brokerIp, brokerPort, 60)
client.loop_forever()

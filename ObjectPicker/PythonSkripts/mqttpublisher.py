# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import os
import sys

brokerIp = sys.argv[1]
brokerPort = sys.argv[2]
#publisherId = sys.argv[3]
publishingTopic = sys.argv[3]
publishingMessage = sys.argv[4]


client = mqtt.Client("ObjectPickerPublisher")
client.connect(brokerIp, brokerPort)
client.publish(publishingTopic, publishingMessage)
client.disconnect()

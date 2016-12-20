# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import os
import sys

brokerIp = sys.argv[1]
brokerPort = sys.argv[2]
publisherId = sys.argv[3]
publishingTopic = sys.argv[4]
publishingMessage = sys.argv[5]


client = new MqttClient(brokerIp":"brokerPort, publisherId);
client.connect();
MqttMessage message = new MqttMessage();
message.setPayload(publishingMessage.getBytes());
client.publish(publishingTopic, message);
client.disconnect();

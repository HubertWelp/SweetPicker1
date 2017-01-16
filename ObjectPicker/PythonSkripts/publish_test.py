# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import random
import json

X = str(random.randint(0, 100))
Y = str(random.randint(0, 90))
Z = str(random.randint(0, 90))

jtext={'Distanz': X,'PolarWinkel': Y, 'RotWinkel': Z}
dump_text = json.dumps(jtext)

mqttc = mqtt.Client("python-pub")
mqttc.connect("192.168.0.1", 8883)
mqttc.publish("THGA/SWT/SweetPicker/Roboteraktionen/Georg", dump_text)


#include "mqttnode.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"

#define ADDRESS     "tcp://localhost:1883"          //MQTT-Broker im IT-Labor "tcp://192.168.0.1:8883"
#define CLIENTID    "ObjectLocalizer"
#define QOS         1
#define TIMEOUT     10000L

MQTTNode::MQTTNode()
{
    //do nothing
}

void MQTTNode::publish(const char* topic,const char* message)
{
    printf("Start MQTT publisher\n");
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,                    //MQTTClient erzeugen
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;                                //regelmäßiges ping senden um zu merken falls der Broker nicht mehr läuft
    conn_opts.cleansession = 1;                                      //zum sicheren starten von Sitzungen (sessions)

    printf("Connect to MQTT server ...\n");
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    pubmsg.payload = (void*)message;                                //payload = Nutzlast
    pubmsg.payloadlen = strlen(message);

    pubmsg.qos = QOS;
    pubmsg.retained = 0;                                            //retained = zurückbehalten
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);      //Nachricht veröffentlichen
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), (char*)pubmsg.payload, topic, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);      //wartet solange bis die Nachricht veröffentlicht wurde
                                                                    //oder bis der timer (=10s) abgelaufen ist
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    //return rc;
}

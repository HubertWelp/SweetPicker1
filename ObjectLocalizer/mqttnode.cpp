#include "mqttnode.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"
#include <time.h>
#include <string>

#define ADDRESS     "tcp://192.168.0.1:8883"          //MQTT-Broker im IT-Labor "tcp://192.168.0.1:8883"
#define CLIENTID    "ObjectLocalizer"
#define TOPIC       "THGA/SWT/SweetPicker/Roboteraktionen/Georg"
#define QOS         1
#define TIMEOUT     10000L

using namespace std;


MQTTNode::MQTTNode()
{
    //do nothing
}

/*** MQTTNode-publisher ***************************************************************************************************/
void MQTTNode::sendMsg(std::string message)
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;      //verbindungsoptionen initialisieren
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;                                 //der token wird verwendet um zu überprüfen ob die Nachricht
                                                                    //erfolgreich an das Ziel gesendet wurde
    int rc;
    char* msg;

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL); //MQTTClient erzeugen
    conn_opts.keepAliveInterval = 20;                               //regelmäßiges ping senden um zu merken falls der Broker nicht mehr läuft
    conn_opts.cleansession = 1;                                     //zum sicheren starten von Sitzungen (sessions)

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    msg = (char *) message.c_str();
    pubmsg.payload = msg;                                //payload = Nutzlast
    pubmsg.payloadlen = strlen(msg);

    pubmsg.qos = QOS;
    pubmsg.retained = 0;                                            //nicht zurückbehalten
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);      //Nachricht veröffentlichen
    //printf("Waiting for up to %d seconds for publication of %s\n"
    //        "on topic %s for client with ClientID: %s\n",
    //        (int)(TIMEOUT/1000), (char*)pubmsg.payload, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);      //wartet solange bis die Nachricht veröffentlicht wurde
                                                                    //oder bis der timer (=10s) abgelaufen ist
    printf("Nachricht mit delivery token %d wurde ausgeliefert\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}
/*** MQTTNode-publisher *** ENDE *******************************************************************************************/

/*** MQTTNode-subscriber ***************************************************************************************************/
volatile MQTTClient_deliveryToken deliveredtoken;                   //Wert der variable kann sich z.B. durch Threads jederzeit ändern
int NACHRICHT_ERHALTEN = 0;
string receive_payload = "";

/*** CALL-BACK-Funktionen **************************************/
void delivered(void *context, MQTTClient_deliveryToken dt)          //delivered = ausgeliefert
{
    printf("Message with token value %d delivery confirmed\n", dt); //Auslieferung der Nachricht wurde bestätigt
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char* payloadptr;

    payloadptr = (char *)message->payload;      //Zeiger zeigt auf die Nachricht
    for(i=0; i<message->payloadlen; i++)
    {
        receive_payload += *payloadptr++;       //empfangene Zeichen an receive_payload anhängen
    }
    MQTTClient_freeMessage(&message);           //gibt den Speicher frei, der für die Nachricht reserviert wurde
    MQTTClient_free(topicName);                 //gibt den von der MQTT-Bibliothek verwendeten Speicher frei
    NACHRICHT_ERHALTEN = 1;                     //zum Beenden der receive-Methode
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}
/*** CALL-BACK-Funktionen *** ENDE *******************************/

 string MQTTNode::receiveMsg(int timeout)
 {
     MQTTClient client;
     MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;        //verbindungsoptionen initialisieren
     int rc;

     MQTTClient_create(&client, ADDRESS, CLIENTID,          //MQTTClient erzeugen
         MQTTCLIENT_PERSISTENCE_NONE, NULL);
     conn_opts.keepAliveInterval = 20;                      //regelmäßiges ping senden um zu merken falls der Broker nicht mehr läuft
     conn_opts.cleansession = 1;                            //zum sicheren starten von Sitzungen (sessions)

     MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);       //setzt den Client in den Multi-Thread-Modus

     if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
     {

         printf("Failed to connect, return code %d\n", rc);
         exit(-1);
     }

     printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n", TOPIC, CLIENTID, QOS);
     MQTTClient_subscribe(client, TOPIC, QOS);              //subscribed ein einziges Thema

     time_t timer, timer2;
     time(&timer);                                          //schreibt aktuelle Systemzeit in timer
     do
     {
         if(NACHRICHT_ERHALTEN == 1)
         {
             break;                                         //beendet die do/while-Schleife falls eine Nachricht eingetroffen ist
         }
         time(&timer2);                                     //schreibt aktuelle Systemzeit in timer2

     } while(timer2 != (timer + timeout));                  //beendet die do/while-Schleife falls der timer abgelaufen ist
     if((timer + timeout) == timer2)                        //ist "true" wenn der timer abgelaufen ist
     {
         printf("Keine Nachricht erhalten! \n"
                "Der Timer von %i Sekunde(n) ist vor eintreffen einer Nachricht abgelaufen \n\n", timeout);
     }

     MQTTClient_disconnect(client, 10000);
     MQTTClient_destroy(&client);
     return receive_payload;                                //empfangene Nachricht (Bei Ablaufen des timers ist receive_payload leer)
 }
/*** MQTTNode-subscriber *** ENDE *******************************************************************************************/

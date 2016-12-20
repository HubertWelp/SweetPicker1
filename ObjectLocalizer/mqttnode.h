#ifndef MQTTNODE_H
#define MQTTNODE_H


/**
 * @brief Schnittstelle zum MQTT-Broker
 *
 * Die Klasse dient zum publishen und subscriben von Nachrichten für den ObjectLocalizer.
 * Von dieser Klasse sollte kein Objekt erstellt werden. Die Methoden zum publishen und subscriben sind
 * Klassenmethoden, die ohne Objekt der Klasse benutzt werden können
 *
 * @author Leon Nappenfeld
 */
class MQTTNode
{
public:
    MQTTNode();

    /**
    * @brief Funktion veröffentlich eine Nachricht auf dem MQTT-Broker
    * @param [in] topic   = Thema, auf dem eine Nachricht veröffentlich werden soll
    * @param [in] message = Nachricht die veröffentlich werden soll
    */
    static void publish(const char* topic, const char* message);
};

#endif // MQTTNODE_H

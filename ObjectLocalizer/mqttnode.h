#ifndef MQTTNODE_H
#define MQTTNODE_H

#include <string>

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
    * @brief  veröffentlich eine Nachricht (die übergeben werden muss) zu einem beliebigen Thema (topic) auf dem MQTT-Broker
    * @param [in] topic   = Thema, auf dem eine Nachricht veröffentlich werden soll
    * @param [in] message = Nachricht die veröffentlich werden soll
    */
    static void publish(const char* topic, const char* message);

    /**
    * @brief    wartet so lange bis eine Nachricht eingetroffen ist oder bis der timer abgelaufen ist.
    *           Ist eine Nachricht, vor Ablaufen des timers, eingetroffen wird diese empfangen und als string zurück gegeben.
    *           Das Thema, mit dem die Nachricht erhalten werden kann,
    *           kann nicht verändert werden und lautet "THGA/SWT/SweetPicker/Roboterattion/Georg"
    *
    * @param [in] timeout = nach Ablaufen des timers wird die Funktion beendet damit das Programm nicht dauerhaft blockiert wird,
    *                       falls keine Nachricht empfangen wurde (timeout in Sekunden)
    * @retval   empfangene Nachricht
    */
    static std::string receive(int timeout);
};

#endif // MQTTNODE_H

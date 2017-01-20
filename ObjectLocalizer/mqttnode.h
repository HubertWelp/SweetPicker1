#ifndef MQTTNODE_H
#define MQTTNODE_H

#include <string>

/**
 * @brief Schnittstelle zum MQTT-Broker
 *
 * Die Klasse dient zum publishen und subscriben von Nachrichten für den ObjectLocalizer.
 * Der hierbei verwendete MQTT-Broker befindet sich im IT-Labor und ist auf dem Socket "192.168.0.1:8883" erreichbar.
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
    * @brief  Funktion veröffentlicht eine Nachricht
    *
    * Die Funktion veröffentlicht eine Nachricht (die übergeben werden muss) zu einem bestehenden Thema (topic) auf dem MQTT-Broker.
    * Das Thema, mit dem die Nachricht von einem anderen subscriber empfangen werden kann,
    * kann nicht verändert werden und lautet "THGA/SWT/SweetPicker/Roboteraktionen/Georg".
    *
    * @param [in] message = Nachricht die veröffentlich werden soll
    */
    static void sendMsg(std::string message);

    /**
    * @brief  Funktion empfängt eine Nachricht
    *
    * Die Funtkion wartet so lange bis eine Nachricht eingetroffen ist oder bis der timer abgelaufen ist.
    * Ist eine Nachricht, vor Ablaufen des timers, eingetroffen wird diese empfangen und als string zurück gegeben.
    * Das Thema, mit dem die Nachricht erhalten werden kann,
    * kann nicht verändert werden und lautet "THGA/SWT/SweetPicker/Roboteraktionen/Georg".
    *
    * @param [in] timeout = nach Ablaufen des timers wird die Funktion beendet damit das Programm nicht dauerhaft blockiert wird,
    *                       falls keine Nachricht empfangen wurde (timeout in Sekunden)
    * @retval   empfangene Nachricht
    */
    static std::string receiveMsg(int timeout);
};

#endif // MQTTNODE_H

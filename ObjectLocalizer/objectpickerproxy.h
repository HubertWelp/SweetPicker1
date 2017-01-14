#ifndef OBJECTPICKERPROXY_H
#define OBJECTPICKERPROXY_H
#include <string>
using namespace std;
/**
* @brief Platzhalter für die Robotik Anwendung
*
* Die Klasse stellt die grundsaetzlichen Funktionen des Robotiksystems für andere Anwendungen bereit
*
* @author Kai Kulik
*/
class ObjectPickerProxy
{
public:
    ObjectPickerProxy();

    /**
    * @brief Funktion uebergibt die Koordinaten für ein gefundenes Objekt
    *
    * @param [in] center = Mittelpunkt Koordinaten des gefundenen Objektes : formatierte Ausgabe XX.X-YY.Y
    *
    * @retval Dateipfad
    */
    void pick(){};
};

#endif // OBJECTPICKERPROXY_H

#ifndef IMAGESNAPPERPROXY_H
#define IMAGESNAPPERPROXY_H
#include <string>
#include <opencv/cv.h>
using namespace std;

/**
* @brief Platzhalter für die Kamera Anwendung
*
* Die Klasse stellt die grundsaetzlichen Funktionen des Kamerasystems für andere Anwendungen bereit
*
* @author Kai Kulik
*/
class ImageSnapperProxy
{

public:

    ImageSnapperProxy();

    /**
    * @brief Funktion setzt den Dateipfad fuer das Szenenbild
    *
    * @param [in] path = Dateipfad der Szene; C:/SP1/scene.jpg
    */
    void setImagePath(string path){this->scenePath = path;}

    /**
    * @brief Funktion liefert Dateipfad für die Szene
    *
    * @retval string, char* = Dateipfad
    */
    string getImagePath(){return this->scenePath;}
    /**
    * @brief Liefert ein Bild aus dem aktuellen Dateipfad
    *
    * @retval Bilddatei (Inhalt)
    */
    cv::Mat getImage();

private:
    string scenePath;
};

#endif // IMAGESNAPPERPROXY_H

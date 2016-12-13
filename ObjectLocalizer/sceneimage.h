#ifndef SCENEIMAGE_H
#define SCENEIMAGE_H
#include <string>
#include <vector>
#include <opencv/cv.h>
#include "positiont.h"
using namespace std;
/**
* @brief Klasse zum Speichern von Szenenobjekten
*
* @author Kai Kulik
*/
class SceneImage
{
public:
    SceneImage();

    /**
    * @brief Funktion setzt den Dateipfad fuer das Szenebild
    *
    * @param [in] path = Dateipfad der Szene; C:/SP1/scene.jpg
    */
    void setImage(string path){this->scenePath = path;}

    /**
    * @brief Funktion liefert Dateipfad für die Szene
    *
    * @retval Dateipfad
    */
    string getImage(){return this->scenePath;}


    /**
    * @brief Funktion setzt die Keypoints fuer das Referenzbild
    *
    * @param [in] keypoints = zu setzende Keypoints
    */
    void setKeypoints(vector<cv::KeyPoint> keypoints);

    /**
    * @brief Funktion liefert Keypoints des Referenzbildes
    *
    * @retval keypoints = keypoints des Referenzbildes
    */
    vector<cv::KeyPoint> getKeypoints();


    /**
    * @brief Funktion setzt Position fuer das gefundene Objekt in der Szene
    *
    * @param [in] path = Dateipfad der Szene; C:/SP1/scene.jpg
    */
    void setPosition(PositionT pos);

    /**
    * @brief Funktion liefert Position des gefundenen Objektes in der Szene
    *
    * @retval Dateipfad
    */
    PositionT getPosition();
private:
    string scenePath;
    vector<cv::KeyPoint> keypoints_scene;
    PositionT position;
};

#endif // SCENEIMAGE_H

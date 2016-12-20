#ifndef DETECTOR_H
#define DETECTOR_H

#include"featureimage.h"
#include"sceneimage.h"

/**
* @brief Klasse berechnet Keypoints und vergleicht Bilder
*
* @author Kai Kulik
*/
class Detector
{
public:
    Detector();
    /**
    * @brief Funktion berechnet Keypoints eines Bildes und speichert diese in dem FeatureImage Objekt
    *
    * @param [in] image = Objekt vom Typ FeatureImage mit darin enthaltenen Bild
    * @param [out] vector = Keypoints
    */
    void findKeypoints(FeatureImage* image);

    /**
    * @brief Funktion vergleicht zwei Bilder und speichert Koordinaten von evtl. Uebereinstimmungen
    *
    * @param [in] object = Referenzobjekt
    * @param [in] scene = Szene
    * @param [out] vector = Uebereinstimmungen
    */
    void compare(FeatureImage* object, SceneImage* scene);
};

#endif // DETECTOR_H

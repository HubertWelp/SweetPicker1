#ifndef FEATUREIMAGE_H
#define FEATUREIMAGE_H

#include<string>
#include<opencv/cv.h>
using namespace std;

/**
* @brief Klasse zum Speichern von Referenzobjekten
*
* @author Kai Kulik
*/
class FeatureImage
{
public:
    FeatureImage();
    /**
    * @brief Funktion setzt den Dateipfad fuer das Referenzbild
    *
    * @param [in] path = Dateipfad des Objektes; C:/SP1/ref_mars.jpg
    */
    void setImage(string path);

    /**
    * @brief Funktion liefert Dateipfad für das Referenzobjekt
    *
    * @retval Dateipfad
    */
    cv::Mat getImage();


    /**
    * @brief Funktion setzt die Keypoints fuer das Referenzbild
    *
    * @param [in] keypoints = zu setzende Keypoints
    */
    void setKeypoints(vector<cv::KeyPoint> keypoints){};

    /**
    * @brief Funktion liefert Keypoints des Referenzbildes
    *
    * @retval keypoints = keypoints des Referenzbildes
    */
    vector<cv::KeyPoint> getKeypoints(){};

private:
    string objPath;
    vector<cv::KeyPoint> keypoints_object;
};

#endif // FEATUREIMAGE_H

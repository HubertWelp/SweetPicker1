#ifndef FEATUREIMAGE_H
#define FEATUREIMAGE_H

#include<string>
#include<opencv/cv.h>
#include<opencv2/highgui/highgui.hpp>
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
    * @brief Funktion setzt ein Bild fuer das Objekt fest
    *
    * @param [in] Object-Referenz Bild
    */
    void setImage(cv::Mat img);

    /**
    * @brief Funktion liefert das Bild des Referenzobjektes
    *
    * @retval Bild
    */
    cv::Mat getImage();


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
    * @brief Funktion setzt die Descriptors fuer das Referenzbild
    *
    * @param [in] descriptors = zu setzender Descriptor
    */
    void setDescriptor(cv::Mat descriptor);

    /**
    * @brief Funktion liefert den Descriptor des Referenzbildes
    *
    * @retval Descriptor des Referenzbildes
    */
    cv::Mat getDescriptor();

private:
    cv::Mat image;
    vector<cv::KeyPoint> keypoints_object;
    cv::Mat descriptors_obj;
};

#endif // FEATUREIMAGE_H

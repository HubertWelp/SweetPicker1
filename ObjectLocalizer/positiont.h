#ifndef POSITIONT_H
#define POSITIONT_H
/**
* @brief Klasse zum Speichern von Positionen eines gefundenen Objektes
* @author Kai Kulik
*/
#include <opencv/cv.h>

using namespace std;
class PositionT
{
public:
    PositionT();
private:

    int TL[2];
    int TR[2];
    int BL[2];
    int BR[2];
    vector<cv::Point2f> Corners;


public:

    void setCorners(vector<cv::Point2f> temp);

    /**
    * @brief Funktion setzt den oberen linken Punkt des gefundenen Objektes
    *
    * @param [in] pos = Koordinaten des Punktes
    */
    void setTL(float* pos);

    /**
    * @brief Funktion liefert den oberen linken Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    float* getTL();


    /**
    * @brief Funktion setzt den oberen rechten Punkt des gefundenen Objektes
    *
    * @param [in] pos = Koordinaten des Punktes
    */
    void setTR(vector<cv::Point2f> pos);

    /**
    * @brief Funktion liefert den oberen rechten Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    vector<cv::Point2f> getTR();


    /**
    * @brief Funktion setzt den unteren linken Punkt des gefundenen Objektes
    *
    * @param [in] pos = Koordinaten des Punktes
    */
    void setBL(vector<cv::Point2f> pos);

    /**
    * @brief Funktion liefert den unteren linken Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    vector<cv::Point2f> getBL();


    /**
    * @brief Funktion setzt den unteren rechten Punkt des gefundenen Objektes
    *
    * @param [in] pos = Koordinaten des Punktes
    */
    void setBR(vector<cv::Point2f> pos);

    /**
    * @brief Funktion liefert den unteren rechten Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    vector<cv::Point2f> getBR();

    /**
    * @brief Funktion gibt den Mittelpunkt des gefundenen Objektes wieder
    *
    * @retval pos = Koordinaten des Punktes
    */
    int* getCenter();

    /**
    * @brief Funktion gibt die Orientierung des gefundenen Objektes wieder
    *
    * @retval deg = Winkel zu horizontalachse des Objektes
    */
    float getOrientation();

};

#endif // POSITIONT_H

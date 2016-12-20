#ifndef POSITIONT_H
#define POSITIONT_H
/**
* @brief Klasse zum Speichern von Positionen eines gefundenen Objektes
* @author Kai Kulik
*/
#include <vector>
#include <opencv/cv.h>

using namespace std;
class PositionT
{
public:
    PositionT();
private:

    vector<cv::Point2f> TL;
    vector<cv::Point2f> TR;
    vector<cv::Point2f> BL;
    vector<cv::Point2f> BR;

public:

    /**
    * @brief Funktion setzt den oberen linken Punkt des gefundenen Objektes
    *
    * @param [in] pos = Koordinaten des Punktes
    */
    void setTL(vector<cv::Point2f> pos);

    /**
    * @brief Funktion liefert den oberen linken Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    vector<cv::Point2f> getTL();


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
    vector<cv::Point2f> getCenter();

    /**
    * @brief Funktion gibt die Orientierung des gefundenen Objektes wieder
    *
    * @retval deg = Winkel zu horizontalachse des Objektes
    */
    float getOrientation();

};

#endif // POSITIONT_H

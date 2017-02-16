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
    /**
    * @brief Funktion setzt die Eckpunkte des gefundenen Objektes
    *
    * @param [in] pos = Eckpunkte des gefundenen Objektes
    */
    void setCorners(vector<cv::Point2f> temp);

    /**
    * @brief Funktion liefert die Eckpunkte des gefundenen Objektes
    *
    * @retval Eckpunkte des Objektes
    */
    vector<cv::Point2f> getCorners();

    /**
    * @brief Funktion setzt den oberen linken Punkt des gefundenen Objektes
    *
    * @param [in] x,y = Koordinaten des Punktes
    */
    void setTL(int x, int y);

    /**
    * @brief Funktion liefert den oberen linken Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    int* getTL();


    /**
    * @brief Funktion setzt den oberen rechten Punkt des gefundenen Objektes
    *
    * @param [in] x,y = Koordinaten des Punktes
    */
    void setTR(int x, int y);

    /**
    * @brief Funktion liefert den oberen rechten Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    int* getTR();


    /**
    * @brief Funktion setzt den unteren linken Punkt des gefundenen Objektes
    *
    * @param [in] x,y = Koordinaten des Punktes
    */
    void setBL(int x, int y);

    /**
    * @brief Funktion liefert den unteren linken Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    int* getBL();


    /**
    * @brief Funktion setzt den unteren rechten Punkt des gefundenen Objektes
    *
    * @param [in] x,y = Koordinaten des Punktes
    */
    void setBR(int x, int y);

    /**
    * @brief Funktion liefert den unteren rechten Punkt des gefundenen Objektes
    *
    * @retval Koordinaten des Punktes
    */
    int* getBR();

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

private:

    int TL[2];
    int TR[2];
    int BL[2];
    int BR[2];
    vector<cv::Point2f> Corners;

};

#endif // POSITIONT_H

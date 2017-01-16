#include "positiont.h"

PositionT::PositionT()
{
}
void PositionT::setTL(vector<cv::Point2f> pos)
{
    this->TL = pos;
}


vector<cv::Point2f> PositionT::getTL()
{
    return this->TL;
}


void PositionT::setTR(vector<cv::Point2f> pos)
{
    this->TR = pos;
}

vector<cv::Point2f> PositionT::getTR()
{
    return this->TR;
}


void PositionT::setBL(vector<cv::Point2f> pos)
{
    this->BL = pos;
}

vector<cv::Point2f> PositionT::getBL()
{
    return this->BL;
}

void PositionT::setBR(vector<cv::Point2f> pos)
{
    this->BR = pos;
}

vector<cv::Point2f> PositionT::getBR()
{
    return this->BR;
}

cv::Point2f PositionT::getCenter()
{
    /*
    cv::Point2f center;
    center.x = this->TL. + 0.5*(this->TR.front() - this->TL.front());
    center.y = this->BL.back() + 0.5*(this->BR.back() - this->BL.back());
    cout << center.x << " " << center.y << endl;
    */

}

/**
* @brief Funktion gibt die Orientierung des gefundenen Objektes wieder
*
* @retval deg = Winkel zu horizontalachse des Objektes
*/
float getOrientation();

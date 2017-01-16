#include "positiont.h"

PositionT::PositionT()
{
}

void PositionT::setCorners(vector<cv::Point2f> temp)
{
    this->Corners = temp;
    TL[0] = temp[0].x;
    TL[1] = temp[0].y;
    cout << "TL : " << TL[0] << " | " << TL[1] << endl;
    TR[0] = temp[1].x;
    TR[1] = temp[1].y;
    cout << "TR : " << TR[0] << " | " << TR[1] << endl;
    BL[0] = temp[2].x;
    BL[1] = temp[2].y;
    cout << "BL : " << BL[0] << " | " << BL[1] << endl;
    BR[0] = temp[3].x;
    BR[1] = temp[3].y;
    cout << "BR : " << BR[0] << " | " << BR[1] << endl;

}
/*
void PositionT::setTL(float* pos)
{
    this->TL = pos;
}


float* PositionT::getTL()
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
*/
int* PositionT::getCenter()
{
    int cent[2];

    cent[0] = this->TL[0] + 0.5*(this->TR[0] - this->TL[0]);
    cent[1] = this->TL[1] + 0.5*(this->BL[1] - this->TL[1]);

    cout << "x = " << cent[0] << " | y = " << cent[1] << endl;

    return cent;


}

/**
* @brief Funktion gibt die Orientierung des gefundenen Objektes wieder
*
* @retval deg = Winkel zu horizontalachse des Objektes
*/
float getOrientation()
{

}

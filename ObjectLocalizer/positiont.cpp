#include "positiont.h"

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

vector<cv::Point2f> PositionT::getCorners()
{
    return this->Corners;
}


void PositionT::setTL(int x, int y)
{
    this->TL[0] = x;
    this->TL[1] = y;
}


int* PositionT::getTL()
{
    return this->TL;
}


void PositionT::setTR(int x, int y)
{
    this->TR[0] = x;
    this->TR[1] = y;
}

int* PositionT::getTR()
{
    return this->TR;
}


void PositionT::setBL(int x, int y)
{
    this->BL[0] = x;
    this->BL[1] = y;
}

int* PositionT::getBL()
{
    return this->BL;
}

void PositionT::setBR(int x, int y)
{
    this->BR[0] = x;
    this->BR[1] = y;
}

int* PositionT::getBR()
{
    return this->BR;
}

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
float PositionT::getOrientation()
{
    float grad = 0;
    int* center = this->getCenter();
    grad = atan2(center[0],center[1]) * (180/3.141);
    return grad;
}

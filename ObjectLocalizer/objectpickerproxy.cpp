#include "objectpickerproxy.h"

ObjectPickerProxy::ObjectPickerProxy()
{
}

void ObjectPickerProxy::pick(PositionT pos)
{
    float center[2];
    //Transformation in cm
    //center = pos.getCenter();
    center[0] = pos.getCenter()[0] * 0.028125;
    center[1] = pos.getCenter()[1] * 0.028333;

    cout << "x = " << center[0] << "cm | y = " << center[1] << "cm" <<  endl;
    //Berechnung der Distanz

    //Berechnung des Polarwinkels

    //Berechnung des Rotationswinkels
}

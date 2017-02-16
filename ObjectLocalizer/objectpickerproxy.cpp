#include "objectpickerproxy.h"

ObjectPickerProxy::ObjectPickerProxy()
{
}

void ObjectPickerProxy::pick(PositionT pos)
{
    float center[2];
    //Transformation in cm
    center[0] = pos.getCenter()[0] * 0.00694; // 18cm/1333px = 0.0135
    center[1] = pos.getCenter()[1] * 0.00699; // 13,6cm/1000px = 0.0136

    cout << "x = " << center[0] << "cm | y = " << center[1] << "cm" <<  endl;
    //Berechnung der Distanz

    float dist = 0;

    dist = sqrt(pow(center[0],2) + pow(center[1],2));

    stringstream ss (stringstream::in | stringstream::out);
    ss << dist;

    string diststr = ss.str();
    string clear;Ent
    ss.str(clear);
    //Berechnung des Polarwinkels

    float grad = 0;

    grad = pos.getOrientation();

    ss << grad;

    string gradstr = ss.str();
    ss.str(clear);

    //Konvertieren in JSON
    string json;

    json = "{\"Distanz\":" + diststr + ",\"PolarWinkel\":" + gradstr + "}";
    cout << json << endl;

    MQTTNode::sendMsg(json);

}

#include "objectpickerproxy.h"

ObjectPickerProxy::ObjectPickerProxy()
{
}

void ObjectPickerProxy::pick(PositionT pos)
{
    float center[2];
    //Transformation in cm
    center[0] = pos.getCenter()[0] * 0.028125; // 18cm/1333px = 0.0135 18cm/640px = 0.028125
    center[1] = pos.getCenter()[1] * 0.028333; // 13,6cm/1000px = 0.0136 13,6cm/480px = 0.028333

    cout << "x = " << center[0] << "cm | y = " << center[1] << "cm" <<  endl;
    //Berechnung der Distanz

    int dist = 0;

    dist = sqrt(pow(center[0],2) + pow(center[1],2));

    stringstream ss (stringstream::in | stringstream::out);
    ss << dist;

    string diststr = ss.str();
    string clear;
    ss.str(clear);
    //Berechnung des Polarwinkels

    int grad = 0;

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

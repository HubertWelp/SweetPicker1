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

    float dist = 1;

    stringstream ss (stringstream::in | stringstream::out);
    ss << dist;

    string diststr = ss.str();
    string clear;
    ss.str(clear);
    //Berechnung des Polarwinkels

    float polar = 2;

    ss << polar;

    string polarstr = ss.str();
    ss.str(clear);
    //Berechnung des Rotationswinkels

    float rot = 3;

    ss << rot;

    string rotstr = ss.str();
    ss.str(clear);
    //Konvertieren in JSON
    string json;
    /*
    json_spirit::Object jsonDump;

    jsonDump.push_back( json_spirit::Pair("Distanz",dist));
    jsonDump.push_back( json_spirit::Pair("Polarwinkel",polar));
    jsonDump.push_back( json_spirit::Pair("Rotationswinkel",rot));

    */

    json = "{'Distanz' : " + diststr + ",'Polarwinkel' :  " + polarstr +",'Rotationswinkel' : " + rotstr +"}";
    cout << json << endl;

}

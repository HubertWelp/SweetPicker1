#include "olmainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "mqttnode.h"
#include <iostream>
#include <string>
#include "detector.h"
#include "imagesnapperproxy.h"
#include "objectpickerproxy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // std::cout << "Hallo" << std::endl;


/*** Zum Testen der MQTTNode-Klasse ************************/
//    char* nachricht;
//    std::string received;
//    nachricht = "Das soll veroeffentlich werden";
//
//    MQTTNode::sendMsg(nachricht);
//
//    received = MQTTNode::receiveMsg(10);
//    std::cout << "empfangene Nachricht: " + received << std::endl;
/***********************************************************/


/*** Zum Testen von opencv**********************************/
    cv::Mat mat;
    mat = cv::imread("D:\\Qt_logo.png");

//    cvNamedWindow("hoffentlichKlapptEs");
//    cv::imshow("hoffentlichKlapptEs",mat);
/***********************************************************/

/*** Test des Detectors*************************************
    FeatureImage objTest;
    SceneImage scnTest;
    Detector detect;
    ImageSnapperProxy snapper;
    ObjectPickerProxy picker;

    //Referenz laden
    cv::imshow("TEST",objTest.getImage());
    //objTest.setImage(cv::imread("referenzTwix.png"));
    //objTest.setImage(cv::imread("C:\\opencv2.4.8\\kinders.jpg"));
    detect.findKeypoints(objTest);

    //Scene laden
    //scnTest.setImage(snapper.getImage());
    //scnTest.setImage(cv::imread("C:\\opencv2.4.8\\scene2s.jpg)"));

    detect.findKeypoints(scnTest);

    //Vergleich
    detect.compare(objTest, scnTest);

    cv::imshow("TEST2",scnTest.getImage());
    picker.pick(scnTest.getPosition());
/***********************************************************/
    std::cout << "Ausgaben in Konsole moeglich" << std::endl;
    OLMainWindow w;
    w.show();

    return a.exec();
}

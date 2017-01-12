#include "olmainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "mqttnode.h"
#include <iostream>
#include <string>
#include "detector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // std::cout << "Hallo" << std::endl;


/*** Zum Testen der MQTTNode-Klasse ************************/
//    const char* thema = "SP1";
//    char* nachricht;
//    std::string received;
//    nachricht = "Das soll veroeffentlich werden";
//
//    MQTTNode::publish(thema, nachricht);
//
//    received = MQTTNode::receive(10);
//    std::cout << "empfangene Nachricht: " + received << std::endl;
/***********************************************************/


/*** Zum Testen von opencv**********************************/
    cv::Mat mat;
    mat = cv::imread("D:\\Qt_logo.png");

    //cvNamedWindow("hoffentlichKlapptEs");
    //cv::imshow("hoffentlichKlapptEs",mat);
/***********************************************************/

/*** Test des Detectors*************************************
    FeatureImage objTest;
    SceneImage scnTest;
    Detector detect;
    objTest.setImage(cv::imread("referenzTwix.png"));

    detect.findKeypoints(objTest);
    scnTest.setImage(cv::imread("sceneTest.bmp"));

    detect.findKeypoints(scnTest);

    detect.compare(objTest, scnTest);

    cv::imshow("TEST DETECTOR", cv::imread("C:\\Qt\\sceneTEST.bmp"));

/***********************************************************/
    std::cout << "Ausgaben in Konsole moeglich" << std::endl;
    OLMainWindow w;
    w.show();

    return a.exec();
}

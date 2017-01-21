#include "olmainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "mqttnode.h"
#include <iostream>
#include <string>                   //for MQTTNode-class
#include "detector.h"
#include "imagesnapperproxy.h"
#include "objectpickerproxy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // std::cout << "Hallo" << std::endl;


/*** Zum Testen der MQTTNode-Klasse ************************/
//    string nachricht;
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
    cv::Mat scene = cv::imread("C:\\opencv2.4.8\\scene2s.jpg");
    cv::Mat obj = cv::imread("C:\\opencv2.4.8\\kitkats.jpg");

    //Referenz laden
    //cv::imshow("TEST",objTest.getImage());
    //objTest.setImage(cv::imread("referenzTwix.png"));
    //objTest.setImage(cv::imread("C:\\opencv2.4.8\\kitkats.jpg"));
    objTest.setImage(obj);
    //detect.findKeypoints(objTest);

    //Scene laden
    //scnTest.setImage(snapper.getImage());
    //scnTest.setImage(cv::imread("C:\\opencv2.4.8\\scene2s.jpg)"));
    scnTest.setImage(scene);

    detect.findKeypoints(scnTest);

    //Vergleich
    detect.compare(objTest, scnTest);

    cv::imshow("TEST2",scnTest.getImage());
    scnTest.getPosition().getCenter();
    picker.pick(scnTest.getPosition());
/***********************************************************/

/*** Test der Koordinaten***********************************
    vector<cv::Point2f> test(4);
    PositionT pos;
    ObjectPickerProxy prox;

    test[0] = cvPoint(0,0);
    test[1] = cvPoint(640,0);
    test[2] = cvPoint(640,480);
    test[3] = cvPoint(0,480);

    pos.setCorners(test);
    pos.getCenter();

    prox.pick(pos);



/***********************************************************/
    std::cout << "Ausgaben in Konsole moeglich" << std::endl;
    OLMainWindow w;
    w.show();
    w.loadScene();
    return a.exec();
}

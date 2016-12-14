#include "olmainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "mqttnode.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // std::cout << "Hallo" << std::endl;


/*** Zum Testen der MQTTNode-Klasse ************************/
//    const char* thema = "SP1";
//    char* nachricht;
//    nachricht = "Das soll veroeffentlich werden";
//
//    MQTTNode::publish(thema, nachricht);
/***********************************************************/


/*** Zum Testen von opencv**********************************/
    cv::Mat mat;
    mat = cv::imread("D:\\Qt_logo.png");
    //cvNamedWindow("hoffentlichKlapptEs");
    //cv::imshow("hoffentlichKlapptEs",mat);
/***********************************************************/

    OLMainWindow w;
    w.show();

    return a.exec();
}

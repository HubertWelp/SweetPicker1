#include "olmainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // std::cout << "Hallo" << std::endl;


    cv::Mat mat;

    mat = cv::imread("D:\\tfh-bochum.png");

   //cvNamedWindow("hoffentlichKlapptEs");
    //cv::imshow("hoffentlichKlapptEs",mat);

    OLMainWindow w;
    w.show();

    return a.exec();
}

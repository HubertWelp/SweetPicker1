#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{


    cout << "IMAGESNAPPER" << endl;

    int i = 0;
    VideoCapture capture (1);
    while(i!=5){

     if(!capture.isOpened())
         return -1;
     Mat frame;
     namedWindow("Camera Stream",1);
     for(;;)
     {
         capture>>frame;
         capture.read(frame);

         imshow("Camera Stream",frame);
         imwrite("C://sp1//scene.jpeg",frame);
         if(waitKey(30)>=0)
             break;

     }

    }

    waitKey(0);

    return 0;
}


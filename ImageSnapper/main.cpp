#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

using namespace std;
using namespace cv;

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}

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


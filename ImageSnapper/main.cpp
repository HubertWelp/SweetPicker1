#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
<<<<<<< HEAD
#include <unistd.h>
=======
>>>>>>> e46db0e4a8cf0f6ea342d6058f7c8a16d631eb99

using namespace std;
using namespace cv;

<<<<<<< HEAD
/**
* @brief Funktion main.
*
* Die Funktion nimmt im Sekundentakt Bilder auf und speichert diese in einem Lokalen Ordner sp1.
* Im Ordner sp1 befindet sich genau ein Bild, das jede Sekunde überschrieben wird\n
* und durch das aktuellste ersetzt wird.
*
*/


=======
>>>>>>> e46db0e4a8cf0f6ea342d6058f7c8a16d631eb99
int main()
{

    cout << "IMAGESNAPPER" << endl;

    int i = 0;
    VideoCapture capture (1);   // 1 ist die id der Kamera.

    while(i!=5)
    {

        if(!capture.isOpened())    // ueberprüft ob Kamera initialisiert ist.
        {
            return -1;
        }

        Mat frame;
        namedWindow("Camera Stream",1);

        for(;;)
        {
            capture>>frame;
            capture.read(frame);

            imshow("Camera Stream",frame);
            imwrite("C://sp1//scene.jpeg",frame);  // Hier werden Bilder im genannten Ordner gespeichert.
            sleep(3);

            if(waitKey(1000)>=0)
            {
                break;
            }

        }

    }

    return 0;
}


#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;


/**
* @brief Funktion main.
*
* Die Funktion nimmt im Sekundentakt Bilder auf und speichert diese in einem Lokalen Ordner sp1.
* Im Ordner sp1 befindet sich genau ein Bild, das jede Sekunde überschrieben wird\n
* und durch das aktuellste ersetzt wird.
*
*/


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

        for(;;)
        {
            capture>>frame;
            capture.read(frame);

            imwrite("C://SP1//scene.png",frame);   // Hier werden Bilder im genannten Ordner gespeichert.
            sleep(1);                              // Die Funktion sleep sorgt dafür, dass das Speichern der Bilder im Sekundentakt erfolgt.

        }

    }

    return 0;
}


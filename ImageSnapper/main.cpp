#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>
#include <unistd.h>
#include <opencv2/imgproc/imgproc.hpp>

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
    VideoCapture capture (0);   // 1 ist die id der Kamera.
    cout << "IMAGESNAPPER" << endl;

    while(i!=5)
    {
        cout << "IMAGESNAPPER" << endl;

        if(!capture.isOpened())    // ueberprüft ob Kamera initialisiert ist.
        {
            cout << "kann Kamera nicht finden" << endl;

            return -1;
        }

        Mat frame;

        for(;;)
        {
            capture>>frame;
            capture.read(frame);

            Mat src =  frame;
            Mat dst = Mat(src.rows, src.cols, CV_8UC3);
            flip(src, dst, 1);

            Point2f src_center(dst.cols/2.0F, dst.rows/2.0F);

            Mat rot_matrix = getRotationMatrix2D(src_center, 180.0, 1.0);

            Mat rotated_img(Size(dst.size().height, dst.size().width), dst.type());

            warpAffine(dst, rotated_img, rot_matrix, dst.size());
            frame = rotated_img;

            imwrite("C://SP1//scene.png",frame);   // Hier werden Bilder im genannten Ordner gespeichert.
            sleep(1);                              // Die Funktion sleep sorgt dafür, dass das Speichern der Bilder im Sekundentakt erfolgt.

        }

    }

    return 0;
}


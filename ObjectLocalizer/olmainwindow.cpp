#include "olmainwindow.h"
#include "ui_olmainwindow.h"
#include "convertcvmat.h"
#include "imagesnapperproxy.h"
#include "detector.h"
#include "sceneimage.h"
#include "featureimage.h"
#include "positiont.h"
#include "objectpickerproxy.h"
#include "mqttnode.h"

#include <QCoreApplication>
#include <iostream>

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <QtWidgets/qapplication.h>
#include <QImage>
#include <QPixmap>
#include <QThread>
#include <QTimer>
#include <QTime>



OLMainWindow::OLMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OLMainWindow)
{
    ui->setupUi(this);

    // Set layout in QWidget
    QWidget *window = new QWidget();
    window->setLayout(ui->hauptgridLayout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);

    cv::Mat livebildMatvorResize;
    cv::Mat livebildMatnachResize;
    ImageSnapperProxy isp;


   // for(int i=0;i<5;i++)
   // {
        livebildMatvorResize = cv::imread("C:\\SP1\\scene.png");// isp.getImage();
        cv::resize(livebildMatvorResize,livebildMatnachResize,cv::Size(500,300),0,0,cv::INTER_LINEAR);
        QImage livebildQImageGUI = convert::cvMatToQImage(livebildMatnachResize);
        ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImageGUI));//display the image in livebildlabel

     //   delay(1);
    //}


}


OLMainWindow::~OLMainWindow()
{
    delete ui;
}

void OLMainWindow::delay(int sec)
{
    QTime dieTime = QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void OLMainWindow::start(cv::Mat referenzbild, cv::Mat livebild)
{
    Detector detec;
    SceneImage scene;
    FeatureImage feature;
    ObjectPickerProxy opp;

    //Referenz laden

    feature.setImage(referenzbild);
    detec.findKeypoints(feature);
    //feature.setKeypoints(feature.getKeypoints());

    //Scene laden
    scene.setImage(livebild);
    detec.findKeypoints(scene);
    //scene.setKeypoints(scene.getKeypoints());

    //Vergleich
    detec.compare(feature,scene);

    QImage livebildQImage = convert::cvMatToQImage(scene.getImage());
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));//display the image in livebildlabel


    //Position senden
    opp.pick(scene.getPosition());

}

void OLMainWindow::on_teasersButton_clicked()
{
    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    //referenzbildMatvorResize.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene.png");// isp.getImage();



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        rotesKreuzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(rotesKreuzQImage));//display the image in referenzbildlabel

        ol.delay(5);

        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
    /}*/
}


void OLMainWindow::on_snickersButton_clicked()
{

    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    //referenzbildMatvorResize.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene.png");// isp.getImage();


    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*/if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        referenzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

        ol.delay(5);

        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
      }*/
}

void OLMainWindow::on_twixButton_clicked()
{
    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    //referenzbildMatvorResize.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene1.png");// isp.getImage();



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*/if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        referenzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

        ol.delay(5);


        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
      }*/
}

void OLMainWindow::on_doveButton_clicked()
{
    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    //referenzbildMatvorResize.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene.png");// isp.getImage();


    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

  ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*/if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        referenzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

        ol.delay(5);

        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
     }*/
}

void OLMainWindow::on_bountyButton_clicked()
{
    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    //referenzbildMatvorResize.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene.png");// isp.getImage();


    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

  ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*/if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        referenzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

        ol.delay(5);

        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
      }*/
}

void OLMainWindow::on_milkyWayButton_clicked()
{
    QString s;

    QImage rotesKreuzQImage;
    QImage referenzbildQImageGUI1;
    QImage referenzbildQImageGUI2;
    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    referenzbildQImageGUI1.load(":/Referenzbilder/referenzMilkyWay.png");	// load and draw image
    //referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    referenzbildMatvorResize = convert::QImageToCvMat(referenzbildQImageGUI1);
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI2 = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI2));//display the image in referenzbildlabel

    livebildMatDetector = cv::imread("C:\\SP1\\scene1.png");// isp.getImage();

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   ol.start(referenzbildMatvorResize,livebildMatDetector);

    /*/if(ol.start(referenzQImage,livebildMat) == false)
    //{
        s.sprintf("Leider konnte kein passendes Objekt detektiert werden");
        ui->NachrichtentextBrowser->setText(s);
        referenzQImage.load(":/rotesKreuz/rotes_kreuz.jpg");	// load and draw image
        ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

        ol.delay(5);

        ui->referenzbildLabel->setText("Bitte Auswahl treffen");


        ui->bountyButton->setEnabled(true);
        ui->snickersButton->setEnabled(true);
        ui->doveButton->setEnabled(true);
        ui->twixButton->setEnabled(true);
        ui->milkyWayButton->setEnabled(true);
        ui->teasersButton->setEnabled(true);
     }*/
}


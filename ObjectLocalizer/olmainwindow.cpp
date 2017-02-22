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
#include <QTime>
#include <QObject>
#include <QThread>



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


void OLMainWindow::loadScene()
{
    cv::Mat livebildMatvorResize;
    cv::Mat livebildMatnachResize;
    ImageSnapperProxy isp;

    verlasseSchleife = false;

    while(1)
    {

        livebildMatvorResize =  isp.getImage();//cv::imread("C:\\SP1\\scene.png");//
        cv::resize(livebildMatvorResize,livebildMatnachResize,cv::Size(450,385),0,0,cv::INTER_LINEAR);
        QImage livebildQImageGUI = convert::cvMatToQImage(livebildMatnachResize);
        ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImageGUI));//display the image in livebildlabel

        QApplication::processEvents();
        delay(1);
        if(verlasseSchleife)
        {
            break;
        }
    }
}


void OLMainWindow::start(cv::Mat referenzbild, cv::Mat livebild)
{
    Detector detec;
    SceneImage scene;
    FeatureImage feature;
    ObjectPickerProxy opp;
    cv::Mat mitgruenenRahmen;

    //Referenz laden
    feature.setImage(referenzbild);
    detec.findKeypoints(feature);

    //Scene laden
    scene.setImage(livebild);
    detec.findKeypoints(scene);

    //Vergleich
    detec.compare(feature,scene);

    mitgruenenRahmen = scene.getImage();
    cv::imwrite("C://SP1//sceneMitRahmen.png",mitgruenenRahmen);

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

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTeasers.png");
    cv::resize(referenzbildMatvorResize,referenzbildMatnachResize ,cv::Size(300,184),0,0,cv::INTER_LINEAR);
    referenzbildQImageGUI = convert::cvMatToQImage(referenzbildMatnachResize);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbildQImageGUI));//display the image in referenzbildlabel

    livebildMatDetector = isp.getImage();//cv::imread("C:\\SP1\\scene.png");//

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    //mitgruenenRahmen = scene.getImage();
    //QImage livebildQImage = convert::cvMatToQImage(scene.getImage());
    //cv::imshow("Copyscene2",mitgruenenRahmen);
    //cv::imwrite("C://SP1//sceneMitRahmen.png",mitgruenenRahmen);
    //livebildQImage.load("C://SP1//sceneMitRahmen.png");
    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzSnickers.png");
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
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzTwix.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzTwix.png");
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
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzDove.png");
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
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzBounty.png");
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
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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
    QImage referenzbildQImageGUI;

    OLMainWindow ol;
    cv::Mat livebildMatDetector;
    cv::Mat referenzbildMatnachResize;
    cv::Mat referenzbildMatvorResize;

    ImageSnapperProxy isp;
    cv::Mat livebildMatnachResize;
    cv::Mat livebildMatvorResize;
    QImage livebildQImage;

    verlasseSchleife = true;

    //referenzbildQImageGUI.load(":/Referenzbilder/referenzMilkyWay.png");	// load and draw image
    referenzbildMatvorResize = cv::imread("C:\\SP1\\referenzMilkyWay.png");
    //referenzbildMatvorResize = convert::QImageToCvMat(referenzbildQImageGUI);
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
    delay(2);

    ol.start(referenzbildMatvorResize,livebildMatDetector);

    livebildMatvorResize = cv::imread("C:\\SP1\\sceneMitRahmen.png");
    cv::resize(livebildMatvorResize,livebildMatnachResize ,cv::Size(450,385),0,0,cv::INTER_LINEAR);
    livebildQImage = convert::cvMatToQImage(livebildMatnachResize);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));


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


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

    cv::Mat scene;
    cv::Mat livebildMat;
    ImageSnapperProxy isp;
    scene = cv::imread("D:\\scene1.png");// isp.getImage();
    cv::resize(scene,livebildMat,cv::Size(500,300),0,0,cv::INTER_LINEAR);
    QImage livebildQImage = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebildQImage));//display the image in livebildlabel



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

    QImage  refer, rotesKreuzQImage;
    OLMainWindow ol;
    cv::Mat referenz, livebildMat;

    //refer.load(":/Referenzbilder/referenzTeasers.png");	// load and draw image
    cv::Mat referMat = cv::imread("D:\\referenzTeasers2.png");
    cv::resize(referMat,referenz,cv::Size(219,154),0,0,cv::INTER_LINEAR);
    refer = convert::cvMatToQImage(referenz);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(refer));//display the image in referenzbildlabel

    livebildMat = cv::imread("D:\\scene1.png");// isp.getImage();



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

    ol.start(referenz,livebildMat);

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


    cv::Mat livebildMat;
    QImage referenzQImage;
    ImageSnapperProxy isp;
    OLMainWindow ol;


    referenzQImage.load(":/Referenzbilder/referenzSnickers.png");	// load and draw image
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel


    livebildMat = cv::imread("D:\\celebrations.jpg");
    QImage livebild = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   // ol.start(referenzQImage,livebildMat);

    //if(ol.start(referenzQImage,livebildMat) == false)
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
}

void OLMainWindow::on_twixButton_clicked()
{
    QString s;


    cv::Mat livebildMat;
    QImage referenzQImage;
    ImageSnapperProxy isp;
    OLMainWindow ol;

    referenzQImage.load(":/Referenzbilder/referenzTwix.png");	// load and draw image
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel

    livebildMat = cv::imread("D:\\celebrations.jpg");
    QImage livebild = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   // ol.start(referenzQImage,livebildMat);

    //if(ol.start(referenzQImage,livebildMat) == false)
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
}

void OLMainWindow::on_doveButton_clicked()
{
    QString s;



    cv::Mat livebildMat;
    QImage referenzQImage;
    ImageSnapperProxy isp;
    OLMainWindow ol;

    referenzQImage.load(":/Referenzbilder/referenzDove.png");	// load and draw image
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel


    livebildMat = cv::imread("D:\\celebrations.jpg");
    QImage livebild = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

  //  ol.start(referenzQImage,livebildMat);

    //if(ol.start(referenzQImage,livebildMat) == false)
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
}

void OLMainWindow::on_bountyButton_clicked()
{
    QString s;

    cv::Mat livebildMat;
    QImage referenzQImage;
    ImageSnapperProxy isp;
    OLMainWindow ol;

    referenzQImage.load(":/Referenzbilder/referenzBounty.png");	// load and draw image
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel


    livebildMat = cv::imread("D:\\celebrations.jpg");
    QImage livebild = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel



    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

  //  ol.start(referenzQImage,livebildMat);

    //if(ol.start(referenzQImage,livebildMat) == false)
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
}

void OLMainWindow::on_milkyWayButton_clicked()
{
    QString s;



    cv::Mat livebildMat;
    QImage referenzQImage;
    ImageSnapperProxy isp;
    OLMainWindow ol;

    referenzQImage.load(":/Referenzbilder/referenzMilkyWay.png");	// load and draw image
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzQImage));//display the image in referenzbildlabel


    livebildMat = cv::imread("D:\\celebrations.jpg");
    QImage livebild = convert::cvMatToQImage(livebildMat);
    ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel


    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);

   // ol.start(referenzQImage,livebildMat);

    //if(ol.start(referenzQImage,livebildMat) == false)
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
}


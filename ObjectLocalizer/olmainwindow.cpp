#include "olmainwindow.h"
#include "ui_olmainwindow.h"
#include "convertcvmat.h"
#include "imagesnapperproxy.h"

#include <QCoreApplication>
#include <iostream>

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QtWidgets/qapplication.h>
#include <QImage>
#include <QPixmap>
#include <QThread>
#include <QTimer>



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

void OLMainWindow::on_teasersButton_clicked()
{
    QString s;

    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzTeasers.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel

    //livebildimg = getImage();
    //QImage livebild = convert::cvMatToQImage(livebildimg);
    //ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel

    s.sprintf("In Kürze erhalten Sie vom Roboter ein teasers");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);




}


void OLMainWindow::on_snickersButton_clicked()
{
    QString s;


    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzSnickers.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel

    //livebildimg = getImage();
    //QImage livebild = convert::cvMatToQImage(livebildimg);
    //ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel

    s.sprintf("In Kürze erhalten Sie vom Roboter ein Snickers");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);




}

void OLMainWindow::on_twixButton_clicked()
{
    QString s;

    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzTwix.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel

    //livebildimg = getImage();
    //QImage livebild = convert::cvMatToQImage(livebildimg);
    //ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel

    s.sprintf("In Kürze erhalten Sie vom Roboter ein Twix");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);


}

void OLMainWindow::on_doveButton_clicked()
{
    QString s;


    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzDove.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel

    //livebildimg = getImage();
    //QImage livebild = convert::cvMatToQImage(livebildimg);
    //ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel

    s.sprintf("In Kürze erhalten Sie vom Roboter ein Dove");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);


}

void OLMainWindow::on_bountyButton_clicked()
{
    QString s;


    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzBounty.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel

    //livebildimg = getImage();
    //QImage livebild = convert::cvMatToQImage(livebildimg);
    //ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel

    s.sprintf("In Kürze erhalten Sie vom Roboter ein Bounty");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);


}

void OLMainWindow::on_milkyWayButton_clicked()
{
    QString s;
    QString a;
    QString b;


    cv::Mat livebildimg;
    cv::Mat referenzimg;

    referenzimg = cv::imread("D:referenzMilkyWay.png");
    QImage referenzbild = convert::cvMatToQImage(referenzimg);
    ui->referenzbildLabel->setPixmap(QPixmap::fromImage(referenzbild));//display the image in referenzbildlabel
    a.sprintf("Nun erscheint das Referenzbild vom MilkyWay im referenzbildlabel\n");
    ui->NachrichtentextBrowser->setText(a);


    // livebildimg = cv::imread("D:referenzMilkyWay.png");
    // QImage livebild = convert::cvMatToQImage(livebildimg);
    // ui->livebildLabel->setPixmap(QPixmap::fromImage(livebild));//display the image in livebildlabel
    b.sprintf("Nun erscheint das livebildbild der Szene im livebildlabel\n");
    ui->NachrichtentextBrowser->setText(a+b);


    s.sprintf("In Kürze erhalten Sie vom Roboter ein MilkyWay\n");
    ui->NachrichtentextBrowser->setText(a+b+s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);


}


#include "olmainwindow.h"
#include "ui_olmainwindow.h"

#include <QCoreApplication>
#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets/qapplication.h>

#include <QPixmap>


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


    QPixmap pmap(QString(":/Objects/GUITeasers.png")); // windows machine, hence escapes
    if (pmap.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(pmap);

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


    QPixmap snickers(QString(":/Objects/GUISnickers.png")); // windows machine, hence escapes
    if (snickers.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(snickers);

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


    QPixmap twix(QString(":/Objects/GUITwix.png")); // windows machine, hence escapes
    if (twix.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(twix);

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


    QPixmap dove(QString(":/Objects/GUIDove.png")); // windows machine, hence escapes
    if (dove.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(dove);

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


    QPixmap bounty(QString(":/Objects/GUIBounty.png")); // windows machine, hence escapes
    if (bounty.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(bounty);

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


    QPixmap pmap(QString(":/Objects/GUIMilkyWay.png")); // windows machine, hence escapes
    if (pmap.isNull())
        ui->referenzbildLabel->setText("Null pixmap!");
    else
        ui->referenzbildLabel->setPixmap(pmap);

    s.sprintf("In Kürze erhalten Sie vom Roboter ein MilkyWay");
    ui->NachrichtentextBrowser->setText(s);

    ui->bountyButton->setEnabled(false);
    ui->snickersButton->setEnabled(false);
    ui->doveButton->setEnabled(false);
    ui->twixButton->setEnabled(false);
    ui->milkyWayButton->setEnabled(false);
    ui->teasersButton->setEnabled(false);


}


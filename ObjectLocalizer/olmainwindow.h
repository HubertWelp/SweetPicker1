#ifndef OLMAINWINDOW_H
#define OLMAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <opencv/cv.h>
namespace Ui {
class OLMainWindow;
}

class OLMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OLMainWindow(QWidget *parent = 0);
    ~OLMainWindow();
    void start(QImage referenzbild, cv::Mat livebild);
    void delay(int sec);

private slots:

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzTeasers" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein Teasers gegriffen werden soll.
    *
    * @param
    */
    void on_teasersButton_clicked();

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzSnickers" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein Snickers gegriffen werden soll.
    *
    * @param
    */
    void on_snickersButton_clicked();

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzTwix" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein Twix gegriffen werden soll.
    *
    * @param
    */
    void on_twixButton_clicked();

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzDove" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein Dove gegriffen werden soll.
    *
    * @param
    */
    void on_doveButton_clicked();

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzBounty" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein Bounty gegriffen werden soll.
    *
    * @param
    */
    void on_bountyButton_clicked();

    /**
    * @brief    Die Funktion ladet das Referenzbild "referenzMilkyWay" in referenzbildLabel,
    *           macht alle Buttons inaktiv,
    *           bestimmt, dass ein MilkyWay gegriffen werden soll.
    *
    * @param
    */
    void on_milkyWayButton_clicked();



private:
    Ui::OLMainWindow *ui;
};

#endif // OLMAINWINDOW_H

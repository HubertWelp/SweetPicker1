#ifndef OLMAINWINDOW_H
#define OLMAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class OLMainWindow;
}

class OLMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OLMainWindow(QWidget *parent = 0);
    ~OLMainWindow();

private slots:
    void on_teasersButton_clicked();

    void on_snickersButton_clicked();

    void on_twixButton_clicked();

    void on_doveButton_clicked();

    void on_bountyButton_clicked();

    void on_milkyWayButton_clicked();



private:
    Ui::OLMainWindow *ui;
};

#endif // OLMAINWINDOW_H

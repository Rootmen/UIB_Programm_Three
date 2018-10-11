#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void GetNRZ(int * Mass);
    void GetNRZI(int * Mass);
    void GetB8ZS(int * Mass);
    void GetHDB3(int * Mass);
    void Get2B1Q(int * Mass);
    void GetScrem(int * Mass);
protected:
    virtual void paintEvent(QPaintEvent *event);


private:
    Ui::MainWindow *ui;
    int _NRZ[32]={0};
    int _Impyl[32]={0};
    int _AIM_NRZ[32]={0};
    int _Mancester[32]={0};
    int _2B1Q[32]={0};
    int _B8ZS[32]={0};
    int _HDB3[32]={0};
    int _NRZI[32]={0};
    int _Screm[32]={0};
};

#endif // MAINWINDOW_H

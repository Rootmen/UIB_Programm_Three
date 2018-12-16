#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void PaintConcetraror(QPainter &painter,int x, int y, QString Text);
    ~MainWindow();
protected:
    double Lbase[8]={11.8,11.8,15.3,-1,12.3,7.8,0.0};
    double Rbase[8]={169.5,169.5,165,-1,156.5,152,0.0};
    double Cbase[8]={46.5,46.5,42,24,33.5,29,0.0};
    double Lost[8]={0.0866,0.1026,0.113,0.1,0.1,0.1,0.1026};

    virtual void paintEvent(QPaintEvent *event);
private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#include "dialogauth.h"
#include "ui_dialogauth.h"
#include "mainwindow.h"
DialogAuth::DialogAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAuth)
{
    ui->setupUi(this);
}

DialogAuth::~DialogAuth()
{
    delete ui;
}

void DialogAuth::on_aut_clicked()
{
    ui->progressBar->setValue(20);
    QString pass[3] = {"rootuser","user","mimokrokodil"};
    QString log[3] =  {"rootuser","user","mimokrokodil"};
    QThread::sleep(1);
    ui->progressBar->setValue(50);
    QThread::sleep(1);
    if(pass[0] == ui->pass->text() && log[0] == ui->login->text() ){
        ui->progressBar->setValue(60);
        MainWindow *w = new MainWindow(0);
        ui->progressBar->setValue(100);
        QThread::sleep(2);
        this->hide();
        w->show();
        this->close();
        w->lvl = 0;
        return;
    }
    if(pass[1] == ui->pass->text()&& log[1] == ui->login->text() ){
        ui->progressBar->setValue(60);
        MainWindow *w = new MainWindow(1);
        ui->progressBar->setValue(100);
        QThread::sleep(2);
        this->hide();
        w->show();
        this->close();
        w->lvl = 1;
        return;
    }
    if(pass[2] == ui->pass->text() && log[2] == ui->login->text() ){
        ui->progressBar->setValue(60);
        MainWindow *w = new MainWindow(2);
        ui->progressBar->setValue(100);
        QThread::sleep(2);
        this->hide();
        w->show();
        this->close();
        w->lvl = 2;
        return;
    }
    ui->label->setText("Ошибка авторизации пользователя!");
    QThread::sleep(2);
    ui->progressBar->setValue(0);
    QThread::sleep(1);
}

void DialogAuth::on_abort_clicked()
{
    this->close();
}

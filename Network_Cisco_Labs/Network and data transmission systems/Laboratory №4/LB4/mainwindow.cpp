#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <QPainter>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("OK");
    QString MassItem[]={"10-Base-5","10-Base-2","10-Base-T","10-Base-FB","10-Base-FL","FOIR","AUL"};
       ui->comboBox->clear(); // Очистка QComboBox
       for(char i = 0; i < 7; i++){
           ui->comboBox->addItem(MassItem[i]); // Наполнение QComboBox
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: paintEvent(QPaintEvent *event)
{
      QPainter painter(this); // Создаём объект отрисовщика
      // Устанавливаем кисть абриса
      //PaintConcetraror(painter,310,70,"Концетратор 1");
}

void MainWindow::  PaintConcetraror(QPainter &painter,int x, int y, QString Text)
{
    int Xsize = 80, Ysize = 20;
    y=y+50;
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    for(int g = x+5; g<Xsize+x;g=g+20)
    {
        int XsizeL = 10, YsizeL = 10;
        int yy=y+5;
        painter.drawLine(g,yy,g+XsizeL,yy);
        painter.drawLine(g,yy,g,yy+YsizeL);
        painter.drawLine(g,yy+YsizeL,g+XsizeL,yy+YsizeL);
        painter.drawLine(g+XsizeL,yy,g+XsizeL,yy+YsizeL);

    }
    painter.drawText(x-10,y-10,Text);
    painter.drawLine(x,y,x+Xsize,y);
    painter.drawLine(x,y,x,y+Ysize);
    painter.drawLine(x,y+Ysize,x+Xsize,y+Ysize);
    painter.drawLine(x+Xsize,y,x+Xsize,y+Ysize);
}


void MainWindow::on_pushButton_clicked()
{
    int Num = ui->comboBox->currentIndex();
    int Size = ui->lineEdit_9->text().toInt();
    std::stringstream StringMy;
    StringMy<<this->Lbase[Num]<< " + "<<this->Lost[Num]<<" * "<<Size<<" = "<<(Lbase[Num]+Lost[Num]*Size);
    ui->label->setText(QString(StringMy.str().c_str()));
    StringMy.str(std::string());
    StringMy<<this->Rbase[Num]<< " + "<<this->Lost[Num]<<" * "<<Size<<" = "<<(Rbase[Num]+Lost[Num]*Size);
    ui->label_2->setText(QString(StringMy.str().c_str()));
    StringMy.str(std::string());
    StringMy<<this->Cbase[Num]<< " + "<<this->Lost[Num]<<" * "<<Size<<" = "<<(Cbase[Num]+Lost[Num]*Size);
    ui->label_3->setText(QString(StringMy.str().c_str()));

}

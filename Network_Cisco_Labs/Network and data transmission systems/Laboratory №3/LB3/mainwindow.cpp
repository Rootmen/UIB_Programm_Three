    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <QPainter>

void HexToBin(int * Mass,std::string Hex);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString QCode = ui->CodeHex->text();
    std::string Code=QCode.toLocal8Bit().constData();
    std::transform(Code.begin(), Code.end(), Code.begin(), ::tolower);
    if(Code.size()>8){
        ui->TestLable->setText(QString("Количество символов больше 8"));
        return;
    }
    int CodeByte[32]={0};
    HexToBin(CodeByte,Code);
    std::string CodeByteString = "В двоичном виде: ";
    for(int g=0;g<32;g++)
        if(CodeByte[g]==1) CodeByteString.append("1");
        else CodeByteString.append("0");
    GetNRZ(CodeByte);
    GetNRZI(CodeByte);
    GetB8ZS(CodeByte);
    GetHDB3(CodeByte);
    Get2B1Q(CodeByte);
    GetScrem(CodeByte);
    ui->TestLable->setText(QString(CodeByteString.c_str()));
    this->update();
}

void HexToBin(int * Mass, std::string Hex)
{
    for(int g=0;g<Hex.size();g++)
    {
            switch (Hex.at(g))
            {
                case '0': Mass[g*4]=0;Mass[g*4+1]=0;Mass[g*4+2]=0;Mass[g*4+3]=0; break;
                case '1': Mass[g*4]=0;Mass[g*4+1]=0;Mass[g*4+2]=0;Mass[g*4+3]=1; break;
                case '2': Mass[g*4]=0;Mass[g*4+1]=0;Mass[g*4+2]=1;Mass[g*4+3]=0; break;
                case '3': Mass[g*4]=0;Mass[g*4+1]=0;Mass[g*4+2]=1;Mass[g*4+3]=1; break;
                case '4': Mass[g*4]=0;Mass[g*4+1]=1;Mass[g*4+2]=0;Mass[g*4+3]=0; break;
                case '5': Mass[g*4]=0;Mass[g*4+1]=1;Mass[g*4+2]=0;Mass[g*4+3]=1; break;
                case '6': Mass[g*4]=0;Mass[g*4+1]=1;Mass[g*4+2]=1;Mass[g*4+3]=0; break;
                case '7': Mass[g*4]=0;Mass[g*4+1]=1;Mass[g*4+2]=1;Mass[g*4+3]=1; break;
                case '8': Mass[g*4]=1;Mass[g*4+1]=0;Mass[g*4+2]=0;Mass[g*4+3]=0; break;
                case '9': Mass[g*4]=1;Mass[g*4+1]=0;Mass[g*4+2]=0;Mass[g*4+3]=1; break;
                case 'a': Mass[g*4]=1;Mass[g*4+1]=0;Mass[g*4+2]=1;Mass[g*4+3]=0; break;
                case 'b': Mass[g*4]=1;Mass[g*4+1]=0;Mass[g*4+2]=1;Mass[g*4+3]=1; break;
                case 'c': Mass[g*4]=1;Mass[g*4+1]=1;Mass[g*4+2]=0;Mass[g*4+3]=0; break;
                case 'd': Mass[g*4]=1;Mass[g*4+1]=1;Mass[g*4+2]=0;Mass[g*4+3]=1; break;
                case 'e': Mass[g*4]=1;Mass[g*4+1]=1;Mass[g*4+2]=1;Mass[g*4+3]=0; break;
                case 'f': Mass[g*4]=1;Mass[g*4+1]=1;Mass[g*4+2]=1;Mass[g*4+3]=1; break;
            }
    }
}

void MainWindow:: GetNRZ(int * Mass)
{
     for(int g=0;g<32;g++)
         if(Mass[g]==1) this->_NRZ[g]=1;
         else           this->_NRZ[g]=0;
}

void MainWindow:: GetNRZI(int * Mass)
{
     bool log = true;
     for(int g=0;g<32;g++){
         if(Mass[g]==1) {
             if(log) {
                 this->_NRZI[g]=1;
                 log=!log;
             }else{
                 this->_NRZI[g]=-1;
                 log=!log;
             }
         }
         else           this->_NRZI[g]=0;

     this->_B8ZS[g]=this->_NRZI[g];
     this->_HDB3[g]=this->_NRZI[g];
     }
}

void MainWindow:: GetB8ZS(int * Mass)
{
     int col=0;
     for(int g=0;g<32;g++){
             if(this->_NRZI[g]==0) col++;
             else col=0;
             if(col==8){
                 if(g<8){
                     _B8ZS[g-4]=-1;
                     _B8ZS[g-3]=1;
                     _B8ZS[g-1]=1;
                     _B8ZS[g]=-1;
                 }
                 else if(_NRZI[g-8]==1){
                     _B8ZS[g-4]=1;
                     _B8ZS[g-3]=-1;
                     _B8ZS[g-1]=-1;
                     _B8ZS[g]=1;
                 } else{
                     _B8ZS[g-4]=-1;
                     _B8ZS[g-3]=1;
                     _B8ZS[g-1]=1;
                     _B8ZS[g]=-1;
                 }
                 col=0;
             }

         }

}


void MainWindow:: GetHDB3(int * Mass)
{
     bool chet=false;
     int col=0;
     for(int g=0;g<32;g++){
             if(this->_NRZI[g]==0) col++;
             else {
                 chet=!chet;
                 col=0;
             }
             if(col==4){
                 if(g<5){
                     _HDB3[g-3]=1;
                     _HDB3[g]=1;

                 }
                 else if(chet){
                     if(_HDB3[g-4]==1) _HDB3[g]=1;
                     else _HDB3[g]=-1;
                     chet=!chet;
                 }
                  else{
                     if(_HDB3[g-4]==1){
                         _HDB3[g-3]=-1;
                         _HDB3[g]=-1;}
                     else {
                         _HDB3[g-3]=1;
                         _HDB3[g]=1;}
                     chet=!chet;
                 }
                 col=0;
             }

         }

}


void MainWindow:: Get2B1Q(int * Mass)
{
     for(int g=0;g<32;g++){
           if(Mass[g]==0&&Mass[g+1]==0){
               this->_2B1Q[g]=-2; this->_2B1Q[g+1]=-2;
           }else if(Mass[g]==0&&Mass[g+1]==1){
                this->_2B1Q[g]=-1; this->_2B1Q[g+1]=-1;
           }else if(Mass[g]==1&&Mass[g+1]==1){
                this->_2B1Q[g]=1; this->_2B1Q[g+1]=1;
           }else if(Mass[g]==1&&Mass[g+1]==0){
                this->_2B1Q[g]=2; this->_2B1Q[g+1]=2;
           }
           g++;
         }
}

void MainWindow:: GetScrem(int * Mass)
{
     for(int g=0;g<32;g++)
         if(g<3) this->_Screm[g]=Mass[g];
         else if(g<5) this->_Screm[g]=Mass[g]^this->_Screm[g-3];
          else this->_Screm[g]=Mass[g]^this->_Screm[g-3]^this->_Screm[g-5];
}


void MainWindow:: paintEvent(QPaintEvent *event)
{
      QPainter painter(this); // Создаём объект отрисовщика
      // Устанавливаем кисть абриса
      painter.setPen(QPen(Qt::black, 1, Qt::DashLine, Qt::FlatCap));
      int StartX=(45) , StartY=(175);

      for(int g=0;g<=32;g++)
      {
          if(g!=32){
           std::string CodeByteString = std::to_string(this->_NRZ[g]);
           painter.drawText(StartX+g*25+9,StartY-85+12,StartX+g*25, StartY-45+25, Qt::AlignLeft|Qt::AlignTop, QString(CodeByteString.c_str()));
          }
           painter.drawLine(StartX+g*25,StartY-85,StartX+g*25,800);
      }
      painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      std::cout<<StartX<<" "<<StartY<<std::endl;
      {
          if(this->_NRZ[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-50);
                      StartY=StartY-50;
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;
          }
          else{
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                       StartX=StartX+25;
          }
          for(int g=1;g<32;g++){
              if(this->_NRZ[g] == 1)
              {
                  if(this->_NRZ[g-1] == 0){
                          painter.drawLine(StartX,StartY,StartX,StartY-50);
                          StartY=StartY-50;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                  }else {
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                  }
              }
              else
              {
                  if(this->_NRZ[g-1] == 0){
                           painter.drawLine(StartX,StartY,StartX+25,StartY);
                           StartX=StartX+25;
                   }else {
                           painter.drawLine(StartX,StartY,StartX,StartY+50);
                           StartY=StartY+50;
                           painter.drawLine(StartX,StartY,StartX+25,StartY);
                           StartX=StartX+25;
                   }
              }

          }
      }
      StartX=(45); StartY=(205-7+30);
      {
          if(this->_NRZI[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
          }
         else{
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                       StartX=StartX+25;
          }
          for(int g=1;g<32;g++){
              if(this->_NRZI[g] == 1)
              {
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
              }
              else if(this->_NRZI[g] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
              }
              else
              {
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;

              }

          }
      }

      StartX=(45); StartY=(205-7+30+60);
      for(int g=0;g<32;g++)
      {
          if(this->_NRZ[g] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+12,StartY);
                      StartX=StartX+12;
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
                      painter.drawLine(StartX,StartY,StartX+13,StartY);
                      StartX=StartX+13;
          }
         else{
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
                      painter.drawLine(StartX,StartY,StartX+12,StartY);
                      StartX=StartX+12;
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+13,StartY);
                      StartX=StartX+13;
          }
       }

      StartX=(45); StartY=(205-7+30+60*2);
      {
          if(this->_NRZ[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
                      painter.drawLine(StartX,StartY,StartX+12,StartY);
                      StartX=StartX+12;
                      painter.drawLine(StartX,StartY,StartX,StartY-50);
                      StartY=StartY-50;
                      painter.drawLine(StartX,StartY,StartX+13,StartY);
                      StartX=StartX+13;
          }
          else{       painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+12,StartY);
                      StartX=StartX+12;
                      painter.drawLine(StartX,StartY,StartX,StartY+50);
                      StartY=StartY+50;
                      painter.drawLine(StartX,StartY,StartX+13,StartY);
                      StartX=StartX+13;
          }
          for(int g=1;g<32;g++){
              if(this->_NRZ[g] == 1)
              {
                  if(this->_NRZ[g-1] == 0){
                          painter.drawLine(StartX,StartY,StartX+12,StartY);
                          StartX=StartX+12;
                          painter.drawLine(StartX,StartY,StartX,StartY-50);
                          StartY=StartY-50;
                          painter.drawLine(StartX,StartY,StartX+13,StartY);
                          StartX=StartX+13;
                  }else {

                          painter.drawLine(StartX,StartY,StartX,StartY+50);
                          StartY=StartY+50;
                          painter.drawLine(StartX,StartY,StartX+12,StartY);
                          StartX=StartX+12;
                          painter.drawLine(StartX,StartY,StartX,StartY-50);
                          StartY=StartY-50;
                          painter.drawLine(StartX,StartY,StartX+13,StartY);
                          StartX=StartX+13;
                  }
              }
              else
              {
                  if(this->_NRZ[g-1] == 0){
                          painter.drawLine(StartX,StartY,StartX,StartY-50);
                          StartY=StartY-50;
                          painter.drawLine(StartX,StartY,StartX+12,StartY);
                          StartX=StartX+12;
                          painter.drawLine(StartX,StartY,StartX,StartY+50);
                          StartY=StartY+50;
                          painter.drawLine(StartX,StartY,StartX+13,StartY);
                          StartX=StartX+13;
                   }else {
                          painter.drawLine(StartX,StartY,StartX+12,StartY);
                          StartX=StartX+12;
                          painter.drawLine(StartX,StartY,StartX,StartY+50);
                          StartY=StartY+50;
                          painter.drawLine(StartX,StartY,StartX+13,StartY);
                          StartX=StartX+13;
                   }
              }

          }
      }

      StartX=(45); StartY=(205-7+30+60*3);
      {
          if(this->_B8ZS[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
          }
         else{
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                       StartX=StartX+25;
          }
          for(int g=1;g<32;g++){
              if(this->_B8ZS[g] == 1)
              {
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
              }
              else if(this->_B8ZS[g] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
              }
              else
              {
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;

              }

          }
      }
      StartX=(45); StartY=(205-7+30+60*4);
      {
          if(this->_HDB3[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
          }
         else{
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                       StartX=StartX+25;
          }
          for(int g=1;g<32;g++){
              if(this->_HDB3[g] == 1)
              {
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
              }
              else if(this->_HDB3[g] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY+25);
                          StartY=StartY+25;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                          painter.drawLine(StartX,StartY,StartX,StartY-25);
                          StartY=StartY-25;
              }
              else
              {
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;

              }

          }
      }
      StartX=(45); StartY=(205-7+30+60*4+70);
      {
          if(this->_2B1Q[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-10);
                      StartY=StartY-10;
                      painter.drawLine(StartX,StartY,StartX+50,StartY);
                      StartX=StartX+50;
          } else if(this->_2B1Q[0] == 2){
                      painter.drawLine(StartX,StartY,StartX,StartY-25);
                      StartY=StartY-25;
                      painter.drawLine(StartX,StartY,StartX+50,StartY);
                      StartX=StartX+50;
          } else if(this->_2B1Q[0] == -1){
                      painter.drawLine(StartX,StartY,StartX,StartY+10);
                      StartY=StartY+10;
                      painter.drawLine(StartX,StartY,StartX+50,StartY);
                      StartX=StartX+50;
          } else if(this->_2B1Q[0] == -2){
                      painter.drawLine(StartX,StartY,StartX,StartY+25);
                      StartY=StartY+25;
                      painter.drawLine(StartX,StartY,StartX+50,StartY);
                      StartX=StartX+50;
          }

          for(int g=2;g<32;g=g+2){
              if(this->_2B1Q[g] == 2){
                  if(this->_2B1Q[g-1] == 2){
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 1){
                          painter.drawLine(StartX,StartY,StartX,StartY-15);
                          StartY=StartY-15;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY-35);
                          StartY=StartY-35;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -2){
                      painter.drawLine(StartX,StartY,StartX,StartY-50);
                      StartY=StartY-50;
                      painter.drawLine(StartX,StartY,StartX+50,StartY);
                      StartX=StartX+50;
              }}
              else if(this->_2B1Q[g] == 1) {
                  if(this->_2B1Q[g-1] == 1){
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 2){
                          painter.drawLine(StartX,StartY,StartX,StartY+15);
                          StartY=StartY+15;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY-20);
                          StartY=StartY-20;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -2){
                          painter.drawLine(StartX,StartY,StartX,StartY-35);
                          StartY=StartY-35;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
              }} else if(this->_2B1Q[g] == -1) {
                  if(this->_2B1Q[g-1] == -1){
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 2){
                          painter.drawLine(StartX,StartY,StartX,StartY+35);
                          StartY=StartY+35;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 1){
                          painter.drawLine(StartX,StartY,StartX,StartY+20);
                          StartY=StartY+20;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -2){
                          painter.drawLine(StartX,StartY,StartX,StartY-15);
                          StartY=StartY-15;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
              }}else if(this->_2B1Q[g] == -2) {
                  if(this->_2B1Q[g-1] == -2){
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 2){
                          painter.drawLine(StartX,StartY,StartX,StartY+50);
                          StartY=StartY+50;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == 1){
                          painter.drawLine(StartX,StartY,StartX,StartY+35);
                          StartY=StartY+35;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
                  }else if(this->_2B1Q[g-1] == -1){
                          painter.drawLine(StartX,StartY,StartX,StartY+15);
                          StartY=StartY+15;
                          painter.drawLine(StartX,StartY,StartX+50,StartY);
                          StartX=StartX+50;
              }}


          }
      }
      StartX=(45); StartY=(205-7+30+60*4+70+60+25);
      {
          if(this->_Screm[0] == 1){
                      painter.drawLine(StartX,StartY,StartX,StartY-50);
                      StartY=StartY-50;
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                      StartX=StartX+25;
          }
          else{
                      painter.drawLine(StartX,StartY,StartX+25,StartY);
                       StartX=StartX+25;
          }
          for(int g=1;g<32;g++){
              if(this->_Screm[g] == 1)
              {
                  if(this->_Screm[g-1] == 0){
                          painter.drawLine(StartX,StartY,StartX,StartY-50);
                          StartY=StartY-50;
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                  }else {
                          painter.drawLine(StartX,StartY,StartX+25,StartY);
                          StartX=StartX+25;
                  }
              }
              else
              {
                  if(this->_Screm[g-1] == 0){
                           painter.drawLine(StartX,StartY,StartX+25,StartY);
                           StartX=StartX+25;
                   }else {
                           painter.drawLine(StartX,StartY,StartX,StartY+50);
                           StartY=StartY+50;
                           painter.drawLine(StartX,StartY,StartX+25,StartY);
                           StartX=StartX+25;
                   }
              }

          }
      }
}

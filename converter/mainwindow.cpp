#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <parser.h>
#include <QTextEdit>
#include <QFileDialog>
#include <QQueue>
#include "parser.h"
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


extern QString result;
extern int HB0;
extern int HB1;
extern int HB2;
extern int SB0;
extern int SB1;
extern int SB2;
extern int SB3;
extern int SB4;
extern int SB5;
extern int SB6;
extern int PB0;
extern int PB1;
extern int PB2;
extern int PB3;
extern int PB4;
extern int PB5;
extern int PB6;
extern int PB7;
extern int PB8;
extern int PB9;
extern int PB10;
extern int PB11;
extern int PB12;
extern int PB13;
extern int PB14;
extern int PB15;
extern int PB16;
extern int PB17;
extern int PB18;
extern int PB19;
extern int PB20;
extern int PB21;
extern int PB22;
extern int PB23;
extern int PB24;
extern int PB25;
extern int PB26;
extern int PB27;
QByteArray Bytes;


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Txt (*.txt );;All files (*.*)");
    ui->path1->setText(fileName);
}

void MainWindow::on_parsestart_clicked()
{
    if(ui->radioButton_2->isChecked()){
        ui->path1->clear();
    }
    QString path2;
    path2 = ui->path1->text();
    Bytes[ 0 ]=ui->hb0->text().toInt();
    Bytes[ 1 ]=ui->hb1->text().toInt();
    Bytes[ 2 ]=ui->hb2->text().toInt();
    Bytes[ 3 ]=ui->sb0->text().toInt();
    Bytes[ 4 ]=ui->sb1->text().toInt();
    Bytes[ 5 ]=ui->sb2->text().toInt();
    Bytes[ 6 ]=ui->sb3->text().toInt();
    Bytes[ 7 ]=ui->sb4->text().toInt();
    Bytes[ 8 ]=ui->sb5->text().toInt();
    Bytes[ 9 ]=ui->sb6->text().toInt();
    Bytes[ 10 ]=ui->pb0->text().toInt();
    Bytes[ 11 ]=ui->pb1->text().toInt();
    Bytes[ 12 ]=ui->pb2->text().toInt();
    Bytes[ 13 ]=ui->pb3->text().toInt();
    Bytes[ 14 ]=ui->pb4->text().toInt();
    Bytes[ 15 ]=ui->pb5->text().toInt();
    Bytes[ 16 ]=ui->pb6->text().toInt();
    Bytes[ 17 ]=ui->pb7->text().toInt();
    Bytes[ 18 ]=ui->pb8->text().toInt();
    Bytes[ 19 ]=ui->pb9->text().toInt();
    Bytes[ 20 ]=ui->pb10->text().toInt();
    Bytes[ 21 ]=ui->pb11->text().toInt();
    Bytes[ 22 ]=ui->pb12->text().toInt();
    Bytes[ 23 ]=ui->pb13->text().toInt();
    Bytes[ 24 ]=ui->pb14->text().toInt();
    Bytes[ 25 ]=ui->pb15->text().toInt();
    Bytes[ 26 ]=ui->pb16->text().toInt();
    Bytes[ 27 ]=ui->pb17->text().toInt();
    Bytes[ 28 ]=ui->pb18->text().toInt();
    Bytes[ 29 ]=ui->pb19->text().toInt();
    Bytes[ 30 ]=ui->pb20->text().toInt();
    Bytes[ 31 ]=ui->pb21->text().toInt();
    Bytes[ 32 ]=ui->pb22->text().toInt();
    Bytes[ 33 ]=ui->pb23->text().toInt();
    Bytes[ 34 ]=ui->pb24->text().toInt();
    Bytes[ 35 ]=ui->pb25->text().toInt();
    Bytes[ 36 ]=ui->pb26->text().toInt();
    Bytes[ 37 ]=ui->pb27->text().toInt();
    parser_packet objParse(path2);
    objParse.parse(path2);
    QFile fileCheck(path2);
    if(ui->radioButton_2->isChecked()){
    ui->textEdit->setText(result);
   }


    else{if(ui->radioButton_3->isChecked()){
            if (ui->sb0_0->text().toInt() == 1){
                SB0=0x01;
                result+=QString::number(SB0);
            }
            if (ui->sb0_1->text().toInt() == 1){
                SB0=0x02;
                result+=QString::number(SB0);
            }
            if (ui->sb0_2->text().toInt() == 1){
                SB0=0x04;
                result+=QString::number(SB0);
            }
            if (ui->sb0_3->text().toInt() == 1){
                SB0=0x08;
                result+=QString::number(SB0);
            }
        ui->textEdit->setText(result);
       }
        else{
    if(fileCheck.open(QIODevice::ReadOnly))
    {
            ui->textEdit->setText(result);
        }
    else{
            ui->textEdit->setText("Invalid path");
    }
}
    }
    ui->hb0->setText(QString::number(HB0));
    ui->hb1->setText(QString::number(HB1));
    ui->hb2->setText(QString::number(HB2));
    ui->sb0->setText(QString::number(SB0));
    ui->sb1->setText(QString::number(SB1));
    ui->sb2->setText(QString::number(SB2));
    ui->sb3->setText(QString::number(SB3));
    ui->sb4->setText(QString::number(SB4));
    ui->sb5->setText(QString::number(SB5));
    ui->sb6->setText(QString::number(SB6));
    ui->pb0->setText(QString::number(PB0));
    ui->pb1->setText(QString::number(PB1));
    ui->pb2->setText(QString::number(PB2));
    ui->pb3->setText(QString::number(PB3));
    ui->pb4->setText(QString::number(PB4));
    ui->pb5->setText(QString::number(PB5));
    ui->pb6->setText(QString::number(PB6));
    ui->pb7->setText(QString::number(PB7));
    ui->pb8->setText(QString::number(PB8));
    ui->pb9->setText(QString::number(PB9));
    ui->pb10->setText(QString::number(PB10));
    ui->pb11->setText(QString::number(PB11));
    ui->pb12->setText(QString::number(PB12));
    ui->pb13->setText(QString::number(PB13));
    ui->pb14->setText(QString::number(PB14));
    ui->pb15->setText(QString::number(PB15));
    ui->pb16->setText(QString::number(PB16));
    ui->pb17->setText(QString::number(PB17));
    ui->pb18->setText(QString::number(PB18));
    ui->pb19->setText(QString::number(PB19));
    ui->pb20->setText(QString::number(PB20));
    ui->pb21->setText(QString::number(PB21));
    ui->pb22->setText(QString::number(PB22));
    ui->pb23->setText(QString::number(PB23));
    ui->pb24->setText(QString::number(PB24));
    ui->pb25->setText(QString::number(PB25));
    ui->pb26->setText(QString::number(PB26));
    ui->pb27->setText(QString::number(PB27));

}

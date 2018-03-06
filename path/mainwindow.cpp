#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <parser.h>
#include <QTextEdit>
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

void MainWindow::readFile()
{
}
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
extern QString result;



void MainWindow::on_pathstart_clicked()
{

    QString path = ui->path1->text();
    QFile fileIn(path);
    QFile fileOut("E://test_files/good.txt");
        if(fileIn.open(QIODevice::ReadOnly) && fileOut.open(QIODevice::WriteOnly))
        {
            QByteArray Byte = fileIn.read(38);
            fileOut.write(Byte);
            HB0=Byte[0];
            HB1=Byte[1];
            HB2=Byte[2];
            SB0=Byte[3];
            SB1=Byte[4];
            SB2=Byte[5];
            SB3=Byte[6];
            SB4=Byte[7];
            SB5=Byte[8];
            SB6=Byte[9];
            PB0=Byte[10];
            PB1=Byte[11];
            PB2=Byte[12];
            PB3=Byte[13];
            PB4=Byte[14];
            PB5=Byte[15];
            PB6=Byte[16];
            PB7=Byte[17];
            PB8=Byte[18];
            PB9=Byte[19];
            PB10=Byte[20];
            PB11=Byte[21];
            PB12=Byte[22];
            PB13=Byte[23];
            PB14=Byte[24];
            PB15=Byte[25];
            PB16=Byte[26];
            PB17=Byte[27];
            PB18=Byte[28];
            PB19=Byte[29];
            PB20=Byte[30];
            PB21=Byte[31];
            PB22=Byte[32];
            PB23=Byte[33];
            PB24=Byte[34];
            PB25=Byte[35];
            PB26=Byte[36];
            PB27=Byte[37];

            parser_packet objParse;
            objParse.parse();
            ui->textEdit->setText(result);
        }
        else{
            ui->textEdit->setText("Invalid path");
        }




fileIn.close();
fileOut.close();

}






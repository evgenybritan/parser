#include "parserlib.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <parser.h>
#include <QTextEdit>
#include <QFileDialog>
#include <QQueue>


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


QString res;
int HB0, HB1, HB2, SB0, SB1, SB2, SB3, SB4, SB5, SB6, PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15, PB16, PB17, PB18, PB19, PB20, PB21, PB22, PB23, PB24, PB25, PB26, PB27;
QByteArray Bytes;
int way,h0,h1,h2;
QString path2, s0,s1,s2,s3,s4,s5,s6,p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27;
void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Txt (*.txt );;Hex (*.hex);;All files (*.*)");
    ui->path1->setText(fileName);
}



void MainWindow::on_parsestart_clicked()
{
    path2 = ui->path1->text();
    if(ui->radioButton->isChecked()){
        way=1;
        Parserlib objParse(QString path2);
        QFile fileCheck(path2);
        if(fileCheck.open(QIODevice::ReadOnly))
        {

                ui->textEdit->setText(res);
            }
        else{
                ui->textEdit->setText("Invalid path");
        }

    }
    if(ui->radioButton_2->isChecked()){
        way=2;
        ui->path1->clear();
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
        Parserlib objParse(QString path2, QByteArray Bytes);
        ui->textEdit->setText(res);
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
        ui->pb20->setText(QString::number(PB20));
        ui->pb21->setText(QString::number(PB21));
        ui->pb22->setText(QString::number(PB22));
        ui->pb23->setText(QString::number(PB23));
        ui->pb24->setText(QString::number(PB24));
        ui->pb25->setText(QString::number(PB25));
        ui->pb26->setText(QString::number(PB26));
        ui->pb27->setText(QString::number(PB27));
    }
    if(ui->radioButton_3->isChecked()){
        way=3;
        h0=ui->hb0->text().toInt();
        h1=ui->hb1->text().toInt();
        h2=ui->hb2->text().toInt();
        s0=ui->sb0_7->text()+ui->sb0_6->text()+ui->sb0_5->text()+ui->sb0_4->text()+ui->sb0_3->text()+ui->sb0_2->text()+ui->sb0_1->text()+ui->sb0_0->text();
        s1=ui->sb1_7->text()+ui->sb1_6->text()+ui->sb1_5->text()+ui->sb1_4->text()+ui->sb1_3->text()+ui->sb1_2->text()+ui->sb1_1->text()+ui->sb1_0->text();
        s2=ui->sb2_7->text()+ui->sb2_6->text()+ui->sb2_5->text()+ui->sb2_4->text()+ui->sb2_3->text()+ui->sb2_2->text()+ui->sb2_1->text()+ui->sb2_0->text();
        s3=ui->sb3_7->text()+ui->sb3_6->text()+ui->sb3_5->text()+ui->sb3_4->text()+ui->sb3_3->text()+ui->sb3_2->text()+ui->sb3_1->text()+ui->sb3_0->text();
        s4=ui->sb4_7->text()+ui->sb4_6->text()+ui->sb4_5->text()+ui->sb4_4->text()+ui->sb4_3->text()+ui->sb4_2->text()+ui->sb4_1->text()+ui->sb4_0->text();
        s5=ui->sb5_7->text()+ui->sb5_6->text()+ui->sb5_5->text()+ui->sb5_4->text()+ui->sb5_3->text()+ui->sb5_2->text()+ui->sb5_1->text()+ui->sb5_0->text();
        s6=ui->sb6_7->text()+ui->sb6_6->text()+ui->sb6_5->text()+ui->sb6_4->text()+ui->sb6_3->text()+ui->sb6_2->text()+ui->sb6_1->text()+ui->sb6_0->text();
        p0=ui->pb0_7->text()+ui->pb0_6->text()+ui->pb0_5->text()+ui->pb0_4->text()+ui->pb0_3->text()+ui->pb0_8->text()+ui->pb0_1->text()+ui->pb0_0->text();
        p1=ui->pb1_7->text()+ui->pb1_6->text()+ui->pb1_5->text()+ui->pb1_4->text()+ui->pb1_3->text()+ui->pb1_8->text()+ui->pb1_1->text()+ui->pb1_0->text();
        p2=ui->pb2_7->text()+ui->pb2_6->text()+ui->pb2_5->text()+ui->pb2_4->text()+ui->pb2_3->text()+ui->pb2_8->text()+ui->pb2_1->text()+ui->pb2_0->text();
        p3=ui->pb3_7->text()+ui->pb3_6->text()+ui->pb3_5->text()+ui->pb3_4->text()+ui->pb3_3->text()+ui->pb3_8->text()+ui->pb3_1->text()+ui->pb3_0->text();
        p4=ui->pb4_7->text()+ui->pb4_6->text()+ui->pb4_5->text()+ui->pb4_4->text()+ui->pb4_3->text()+ui->pb4_8->text()+ui->pb4_1->text()+ui->pb4_0->text();
        p5=ui->pb5_7->text()+ui->pb5_6->text()+ui->pb5_5->text()+ui->pb5_4->text()+ui->pb5_3->text()+ui->pb5_8->text()+ui->pb5_1->text()+ui->pb5_0->text();
        p6=ui->pb6_7->text()+ui->pb6_6->text()+ui->pb6_5->text()+ui->pb6_4->text()+ui->pb6_3->text()+ui->pb6_8->text()+ui->pb6_1->text()+ui->pb6_0->text();
        p7=ui->pb7_7->text()+ui->pb7_6->text()+ui->pb7_5->text()+ui->pb7_4->text()+ui->pb7_3->text()+ui->pb7_8->text()+ui->pb7_1->text()+ui->pb7_0->text();
        p8=ui->pb8_7->text()+ui->pb8_6->text()+ui->pb8_5->text()+ui->pb8_4->text()+ui->pb8_3->text()+ui->pb8_8->text()+ui->pb8_1->text()+ui->pb8_0->text();
        p9=ui->pb9_7->text()+ui->pb9_6->text()+ui->pb9_5->text()+ui->pb9_4->text()+ui->pb9_3->text()+ui->pb9_8->text()+ui->pb9_1->text()+ui->pb9_0->text();
        p10=ui->pb10_7->text()+ui->pb10_6->text()+ui->pb10_5->text()+ui->pb10_4->text()+ui->pb10_3->text()+ui->pb10_8->text()+ui->pb10_1->text()+ui->pb10_0->text();
        p11=ui->pb11_7->text()+ui->pb11_6->text()+ui->pb11_5->text()+ui->pb11_4->text()+ui->pb11_3->text()+ui->pb11_8->text()+ui->pb11_1->text()+ui->pb11_0->text();
        p12=ui->pb12_7->text()+ui->pb12_6->text()+ui->pb12_5->text()+ui->pb12_4->text()+ui->pb12_3->text()+ui->pb12_8->text()+ui->pb12_1->text()+ui->pb12_0->text();
        p13=ui->pb13_7->text()+ui->pb13_6->text()+ui->pb13_5->text()+ui->pb13_4->text()+ui->pb13_3->text()+ui->pb13_8->text()+ui->pb13_1->text()+ui->pb13_0->text();
        p14=ui->pb14_7->text()+ui->pb14_6->text()+ui->pb14_5->text()+ui->pb14_4->text()+ui->pb14_3->text()+ui->pb14_8->text()+ui->pb14_1->text()+ui->pb14_0->text();
        p15=ui->pb15_7->text()+ui->pb15_6->text()+ui->pb15_5->text()+ui->pb15_4->text()+ui->pb15_3->text()+ui->pb15_8->text()+ui->pb15_1->text()+ui->pb15_0->text();
        p16=ui->pb16_7->text()+ui->pb16_6->text()+ui->pb16_5->text()+ui->pb16_4->text()+ui->pb16_3->text()+ui->pb16_8->text()+ui->pb16_1->text()+ui->pb16_0->text();
        p17=ui->pb17_7->text()+ui->pb17_6->text()+ui->pb17_5->text()+ui->pb17_4->text()+ui->pb17_3->text()+ui->pb17_8->text()+ui->pb17_1->text()+ui->pb17_0->text();
        p18=ui->pb18_7->text()+ui->pb18_6->text()+ui->pb18_5->text()+ui->pb18_4->text()+ui->pb18_3->text()+ui->pb18_8->text()+ui->pb18_1->text()+ui->pb18_0->text();
        p19=ui->pb19_7->text()+ui->pb19_6->text()+ui->pb19_5->text()+ui->pb19_4->text()+ui->pb19_3->text()+ui->pb19_8->text()+ui->pb19_1->text()+ui->pb19_0->text();
        p20=ui->pb20_7->text()+ui->pb20_6->text()+ui->pb20_5->text()+ui->pb20_4->text()+ui->pb20_3->text()+ui->pb20_8->text()+ui->pb20_1->text()+ui->pb20_0->text();
        p21=ui->pb21_7->text()+ui->pb21_6->text()+ui->pb21_5->text()+ui->pb21_4->text()+ui->pb21_3->text()+ui->pb21_8->text()+ui->pb21_1->text()+ui->pb21_0->text();
        p22=ui->pb22_7->text()+ui->pb22_6->text()+ui->pb22_5->text()+ui->pb22_4->text()+ui->pb22_3->text()+ui->pb22_8->text()+ui->pb22_1->text()+ui->pb22_0->text();
        p23=ui->pb23_7->text()+ui->pb23_6->text()+ui->pb23_5->text()+ui->pb23_4->text()+ui->pb23_3->text()+ui->pb23_8->text()+ui->pb23_1->text()+ui->pb23_0->text();
        p24=ui->pb24_7->text()+ui->pb24_6->text()+ui->pb24_5->text()+ui->pb24_4->text()+ui->pb24_3->text()+ui->pb24_8->text()+ui->pb24_1->text()+ui->pb24_0->text();
        p25=ui->pb25_7->text()+ui->pb25_6->text()+ui->pb25_5->text()+ui->pb25_4->text()+ui->pb25_3->text()+ui->pb25_8->text()+ui->pb25_1->text()+ui->pb25_0->text();
        p26=ui->pb26_7->text()+ui->pb26_6->text()+ui->pb26_5->text()+ui->pb26_4->text()+ui->pb26_3->text()+ui->pb26_8->text()+ui->pb26_1->text()+ui->pb26_0->text();
        p27=ui->pb27_7->text()+ui->pb27_6->text()+ui->pb27_5->text()+ui->pb27_4->text()+ui->pb27_3->text()+ui->pb27_8->text()+ui->pb27_1->text()+ui->pb27_0->text();
        Parserlib objParse(QString path2);
        ui->textEdit->setText(res);
    }
    if(ui->radioButton_4->isChecked()){
        way=4;
        Parserlib objParse(QString path2);
        QFile fileCheck(path2);
        if(fileCheck.open(QIODevice::ReadOnly))
        {
                resultt();
                ui->textEdit->setText(res);
            }
        else{
                ui->textEdit->setText("Invalid path");
        }

    }
}
Parserlib::Parserlib(QString){
    res = result;

}
QString resultt()
{
    return (res);
}


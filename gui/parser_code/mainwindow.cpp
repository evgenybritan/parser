#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"
#include "version.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>

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

void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Hex (*.hex);;All files (*.*)");
    ui->path->setText(fileName);
}

 void MainWindow::on_start_clicked()
{
    QByteArray Input;
    static const int INFO_FRAME_PACKET_BIT = 0x80;
    QString packetInfo = "";
    QString filename =ui->path->text();
        QFile fileIn(filename);
        if(fileIn.open(QIODevice::ReadOnly)){
            bool ok;
            QString h0=fileIn.read(2);
            QString h1=fileIn.read(3);
            QString h2=fileIn.read(3);
            Input[0]=h0.toInt(&ok,16);
            Input[1]=h1.toInt(&ok,16);
            Input[2]=h2.toInt(&ok,16);
            int HB0=Input[0];
            if (((HB0&INFO_FRAME_PACKET_BIT) ==0) || (HB0!=0x04) || (HB0!=0x05) || (HB0!=0x06)){
            QString s0=fileIn.read(4);
            QString s1=fileIn.read(3);
            QString s2=fileIn.read(3);
            QString s3=fileIn.read(3);
            QString s4=fileIn.read(3);
            QString s5=fileIn.read(3);
            QString s6=fileIn.read(3);
            Input[3]=s0.toInt(&ok,16);
            Input[4]=s1.toInt(&ok,16);
            Input[5]=s2.toInt(&ok,16);
            Input[6]=s3.toInt(&ok,16);
            Input[7]=s4.toInt(&ok,16);
            Input[8]=s5.toInt(&ok,16);
            Input[9]=s6.toInt(&ok,16);
            }
            else{
            QString p0=fileIn.read(4);
            QString p1=fileIn.read(3);
            QString p2=fileIn.read(3);
            QString p3=fileIn.read(3);
            QString p4=fileIn.read(3);
            QString p5=fileIn.read(3);
            QString p6=fileIn.read(3);
            QString p7=fileIn.read(3);
            QString p8=fileIn.read(3);
            QString p9=fileIn.read(3);
            QString p10=fileIn.read(3);
            QString p11=fileIn.read(3);
            QString p12=fileIn.read(3);
            QString p13=fileIn.read(3);
            QString p14=fileIn.read(3);
            QString p15=fileIn.read(3);
            QString p16=fileIn.read(3);
            QString p17=fileIn.read(3);
            QString p18=fileIn.read(3);
            QString p19=fileIn.read(3);
            QString p20=fileIn.read(3);
            QString p21=fileIn.read(3);
            QString p22=fileIn.read(3);
            QString p23=fileIn.read(3);
            QString p24=fileIn.read(3);
            QString p25=fileIn.read(3);
            QString p26=fileIn.read(3);
            QString p27=fileIn.read(3);
            Input[3]=p0.toInt(&ok,16);
            Input[4]=p1.toInt(&ok,16);
            Input[5]=p2.toInt(&ok,16);
            Input[6]=p3.toInt(&ok,16);
            Input[7]=p4.toInt(&ok,16);
            Input[8]=p5.toInt(&ok,16);
            Input[9]=p6.toInt(&ok,16);
            Input[10]=p7.toInt(&ok,16);
            Input[11]=p8.toInt(&ok,16);
            Input[12]=p9.toInt(&ok,16);
            Input[13]=p10.toInt(&ok,16);
            Input[14]=p11.toInt(&ok,16);
            Input[15]=p12.toInt(&ok,16);
            Input[16]=p13.toInt(&ok,16);
            Input[17]=p14.toInt(&ok,16);
            Input[18]=p15.toInt(&ok,16);
            Input[19]=p16.toInt(&ok,16);
            Input[20]=p17.toInt(&ok,16);
            Input[21]=p18.toInt(&ok,16);
            Input[22]=p19.toInt(&ok,16);
            Input[23]=p20.toInt(&ok,16);
            Input[24]=p21.toInt(&ok,16);
            Input[25]=p22.toInt(&ok,16);
            Input[26]=p23.toInt(&ok,16);
            Input[27]=p24.toInt(&ok,16);
            Input[28]=p25.toInt(&ok,16);
            Input[29]=p26.toInt(&ok,16);
            Input[30]=p27.toInt(&ok,16);
            }
        }



    switch (Parser::parse(Input, packetInfo))
    {
        case Parser::NO_ERRORS: ui->result->setText(packetInfo); break;
        case Parser::FILE_NOT_FOUND: ui->result->setText("FNF"); break;
        case Parser::INVALID_PACKET: ui->result->setText("Invalid packet"); break;
    }

    Version::Info versionInfo = Version::getVersionInfo();
    ui->libVer->setText(versionInfo.major + versionInfo.minor);
    ui->spec->setText(versionInfo.specifications);

}

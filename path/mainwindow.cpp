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
QString pathCheck;


void MainWindow::on_pathstart_clicked()
{
    extern QString path;
    path = ui->path1->text();
    parser_packet objParse;
    objParse.parse();
    QFile fileCheck(pathCheck);
    if(fileCheck.open(QIODevice::ReadOnly))
    {
            ui->textEdit->setText(result);
        }
    else{
            ui->textEdit->setText("Invalid path");
    }

}






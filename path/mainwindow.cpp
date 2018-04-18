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

void MainWindow::readFile()
{
}

extern QString result;
QByteArray Bytes;

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Txt (*.txt );;All files (*.*)");
    ui->path1->setText(fileName);

}
void MainWindow::on_pathstart_clicked()
{
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
    ui->textEdit->setText("Good");
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








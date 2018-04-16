#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <parser.h>
#include <QTextEdit>
#include <QFileDialog>
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
    parser_packet objParse(path2);
    objParse.parse(path2);
    QFile fileCheck(path2);
    if(ui->radioButton_2->isChecked()){
    ui->textEdit->setText("Good");
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








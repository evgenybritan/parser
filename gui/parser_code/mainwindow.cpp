#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"
#include "version.h"
#include <QString>
#include <QFileDialog>

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
    QString packetInfo = "";
    QString filename =ui->path->text();
    switch (Parser::parse(filename, packetInfo))
    {
        case Parser::NO_ERRORS: ui->result->setText(packetInfo); break;
        case Parser::FILE_NOT_FOUND: ui->result->setText("FNF"); break;
        case Parser::INVALID_PACKET: ui->result->setText("Invalid packet"); break;
    }

    Version::Info versionInfo = Version::getVesionInfo();
    ui->libVer->setText(versionInfo.major + versionInfo.minor);
    ui->spec->setText(versionInfo.specifications);
}

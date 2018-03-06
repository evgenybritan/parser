#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pathstart_clicked();

    void on_pushButton_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
public:
    void readFile();
};

#endif // MAINWINDOW_H

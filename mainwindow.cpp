#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include "WorkThread.h"

#define LINID_0x2A 0x2A

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this,&MainWindow::colorSelect,this,&MainWindow::sendLinMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::config()
{
    bool ret;
    workThread = new WorkThread();
//    workThread->config();
    workThread->start();
    connect(this,&MainWindow::sendMsg,workThread,&WorkThread::sendMsgSlot);
    connect(workThread,&WorkThread::wellDone,this,&MainWindow::sendMsgRetSlot);
    return ret;
}

void MainWindow::sendMsgRetSlot(bool ret)
{
    qDebug()<<"ret "<<ret;
}

void MainWindow::on_label_1_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_2_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_3_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_4_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_5_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_6_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_7_clicked()
{
    QColor color(255,0,0);
    emit colorSelect(color);
}

void MainWindow::sendLinMsg(QColor color)
{
    dat[0] = 0xFF;
    dat[1] = 0xFF;
    dat[2] = 0xFF;

    dat[3] = color.red();
    dat[4] = color.green();
    dat[5] = color.blue();

    dat[6] = ui->hSlider_level->value();//function and brightness
    dat[7] = 0xAA;//crc
    emit sendMsg(dat);
}

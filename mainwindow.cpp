#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include "WorkThread.h"
#include <QButtonGroup>

#define LINID_0x2A 0x2A

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btngroup = new QButtonGroup(this);
    btngroup->addButton(ui->radioBtn_off,0);
    btngroup->addButton(ui->radioBtn_on,1);
    btngroup->addButton(ui->radioBtn_slow,2);
    btngroup->addButton(ui->radioBtn_fast,3);
    btngroup->addButton(ui->radioBtn_gra,4);

    connect(this,&MainWindow::colorSelect,this,&MainWindow::sendLinMsg);
    connect(btngroup,(void (QButtonGroup::*)(int))&QButtonGroup::buttonClicked,this,&MainWindow::sendLinMsg);
    connect(ui->hSlider_level,&QSlider::valueChanged,this,&MainWindow::sendLinMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::config()
{
    workThread = new WorkThread();

    workThread->start();
    connect(this,&MainWindow::sendMsg,workThread,&WorkThread::sendMsgSlot);
    connect(workThread,&WorkThread::wellDone,this,&MainWindow::sendMsgRetSlot);
    return true;
}

void MainWindow::sendMsgRetSlot(bool ret)
{
    qDebug()<<"ret "<<ret;
}

void MainWindow::on_label_1_clicked()
{
    color = QColor(255,0,0);
    emit colorSelect(color);
}

void MainWindow::on_label_2_clicked()
{
    color = QColor(0,255,0);
    emit colorSelect(color);
}

void MainWindow::on_label_3_clicked()
{
    color = QColor(0,0,255);
    emit colorSelect(color);
}

void MainWindow::on_label_4_clicked()
{
    color = QColor(255,255,0);
    emit colorSelect(color);
}

void MainWindow::on_label_5_clicked()
{
    color = QColor(255,0,255);
    emit colorSelect(color);
}

void MainWindow::on_label_6_clicked()
{
    color = QColor(0,255,255);
    emit colorSelect(color);
}

void MainWindow::on_label_7_clicked()
{
    color = QColor(255,255,255);
    emit colorSelect(color);
}

void MainWindow::sendLinMsg()
{
    uint8_t fun=0;

    dat[0] = 0xFF;
    dat[1] = 0xFF;
    dat[2] = 0xFF;

    dat[3] = color.red();
    dat[4] = color.green();
    dat[5] = color.blue();

    fun = (btngroup->checkedId() << 5);
    dat[6] = fun | ui->hSlider_level->value();//function and brightness
    dat[7] = 0xAA;//crc
    emit sendMsg(dat);
}

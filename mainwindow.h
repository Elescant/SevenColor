#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Lin.h>
#include <QSerialPort>
#include "WorkThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool config(void);
public slots:
    void sendMsgRetSlot(bool ret);
signals:
    void colorSelect(QColor);
    void sendMsg(uint8_t *dat);

private slots:

    void on_label_1_clicked();

    void on_label_2_clicked();

    void on_label_3_clicked();

    void on_label_4_clicked();

    void on_label_5_clicked();

    void on_label_6_clicked();

    void on_label_7_clicked();
    void sendLinMsg(QColor color);

private:
    Ui::MainWindow *ui;
    WorkThread *workThread;
    uint8_t dat[8];
};

#endif // MAINWINDOW_H

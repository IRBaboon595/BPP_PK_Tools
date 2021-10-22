#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTextEdit>
#include <iostream>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <QtMath>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QFile>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <QLabel>
#include <QDataStream>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QDial>
#include <QThread>
#include "hardwaredevice.h"
#include "geterodinemodule.h"
#include "receivermodule.h"
#include "transmittermodule.h"
#include <QByteArray>
#include <QTest>

#define	SYNCHRO                     0x02
#define UART_ADDR                   0x0A
#define SERVICE_BITS_LEN            0x06

#define ECHO						0x00
#define SUPPLY_CTRL					0x01
#define ATT_CTRL					0x02
#define DAC_REVISION				0x03
#define	DAC_CTRL					0x04

#define	OUT_POW_13dBm               0x0
#define	OUT_POW_11dBm               0x1
#define	OUT_POW_8dBm                0x2
#define	OUT_POW_6dBm                0x3

#define	PRESC_8_9					0x0
#define	PRESC_16_17                 0x1
#define	PRESC_32_33                 0x2
#define	PRESC_32_33_d               0x3

#define ON                          0x01
#define OFF                         0x00

#define MASK_3_3V                   0x04

#define SPI1                        0x00
#define SPI4                        0x01

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef union{
    uint16_t 	istd;
    uint8_t 	cstd[2];
}std_union;

typedef union{
    uint32_t 	listd;
    uint16_t 	istd[2];
    uint8_t 	cstd[4];
}long_std_union;

typedef union{
    uint64_t 	llistd;
    uint32_t 	listd[2];
    uint16_t 	istd[4];
    uint8_t 	cstd[8];
}long_long_std_union;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class testGUI;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSerialPort                     *COM;
    QFile                           *File;
    QTime                           *Timer_Data;
    char                            CRC = 0;
    uint8_t                         com_mode;
    uint8_t                         uart_command;
    uint64_t                        time;
    QTimer                          *timer_1;
    QElapsedTimer                   *timer_2;
    QTimer                          *timer_3;
    QTimer                          *timer_echo;
    QByteArray                      ba;
    bool                            plus_3_3V_state;
    bool                            minus_5V_state;
    int                             attenuation_selected;

    GeterodineModule                *geterodine;
    ReceiverModule                  *receiver;
    TransmitterModule               *transmitter;
    QThread                         thread_1;

    Ui::MainWindow                  *ui;

public slots:
    void getEcho(void);
    void connectCOM(void);
    void readData(void);
    void on_com_refresh_button_clicked();
    void timer_echo_timeout();

    void power_ctrl_Data(void);
    void setAttenuation(void);
    void selectAtt(void);
    void writeAtt(void);
    void setSyntParam(void);

private slots:
    void on_plus_5_LO_toggled(bool checked);
    void on_plus_5_RX_toggled(bool checked);
    void on_plus_5_TX_toggled(bool checked);
};
#endif // MAINWINDOW_H

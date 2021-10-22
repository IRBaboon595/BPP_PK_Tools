/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *synt_ctrl;
    QDial *synt_power;
    QDial *synt_presc;
    QLabel *powSelLabel;
    QLabel *rpescSelLabel;
    QLabel *labelPow13;
    QLabel *labelPow11;
    QLabel *labelPow8;
    QLabel *labelPow6;
    QLabel *labelPres32;
    QLabel *labelPres8;
    QLabel *labelPres16;
    QLabel *labelPres32_2;
    QLineEdit *a_lineedit;
    QLineEdit *b_lineedit;
    QLineEdit *r_lineedit;
    QLabel *labelCounterA;
    QLabel *labelCounterB;
    QLabel *labelCounterR;
    QPushButton *synt_send;
    QRadioButton *synt1_check;
    QRadioButton *synt2_check;
    QGroupBox *SupplyCtrl;
    QCheckBox *plus_5_LO;
    QCheckBox *plus_3_3;
    QCheckBox *minus_5;
    QCheckBox *plus_5_RX_2_1;
    QCheckBox *plus_5_RX_2_2;
    QCheckBox *plus_5_TX;
    QCheckBox *plus_5_TX_2;
    QCheckBox *plus_5_TX_1;
    QCheckBox *plus_5_RX_1_2;
    QCheckBox *plus_5_RX;
    QCheckBox *plus_5_RX_1_1;
    QPushButton *SupplyButton;
    QCheckBox *plus_5_LO_2;
    QCheckBox *plus_5_LO_1;
    QGroupBox *attenuator;
    QSlider *att_slider;
    QLineEdit *att_line_edit;
    QPushButton *att_ctrl_pushbutton;
    QComboBox *att_address_combo;
    QGroupBox *com_groupbox;
    QPushButton *com_button;
    QComboBox *com_combobox;
    QLabel *comstate_label;
    QPushButton *echo_button;
    QLabel *service_message;
    QPushButton *com_refresh_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        synt_ctrl = new QGroupBox(centralwidget);
        synt_ctrl->setObjectName(QString::fromUtf8("synt_ctrl"));
        synt_ctrl->setGeometry(QRect(430, 10, 141, 511));
        synt_power = new QDial(synt_ctrl);
        synt_power->setObjectName(QString::fromUtf8("synt_power"));
        synt_power->setGeometry(QRect(30, 30, 81, 81));
        synt_power->setMaximum(4);
        synt_power->setSliderPosition(0);
        synt_power->setWrapping(true);
        synt_power->setNotchTarget(5.000000000000000);
        synt_power->setNotchesVisible(true);
        synt_presc = new QDial(synt_ctrl);
        synt_presc->setObjectName(QString::fromUtf8("synt_presc"));
        synt_presc->setGeometry(QRect(30, 170, 81, 81));
        synt_presc->setMaximum(4);
        synt_presc->setWrapping(true);
        synt_presc->setNotchTarget(5.000000000000000);
        synt_presc->setNotchesVisible(true);
        powSelLabel = new QLabel(synt_ctrl);
        powSelLabel->setObjectName(QString::fromUtf8("powSelLabel"));
        powSelLabel->setGeometry(QRect(30, 130, 81, 20));
        powSelLabel->setAlignment(Qt::AlignCenter);
        rpescSelLabel = new QLabel(synt_ctrl);
        rpescSelLabel->setObjectName(QString::fromUtf8("rpescSelLabel"));
        rpescSelLabel->setGeometry(QRect(30, 270, 81, 20));
        rpescSelLabel->setAlignment(Qt::AlignCenter);
        labelPow13 = new QLabel(synt_ctrl);
        labelPow13->setObjectName(QString::fromUtf8("labelPow13"));
        labelPow13->setGeometry(QRect(60, 110, 21, 20));
        labelPow13->setAlignment(Qt::AlignCenter);
        labelPow11 = new QLabel(synt_ctrl);
        labelPow11->setObjectName(QString::fromUtf8("labelPow11"));
        labelPow11->setGeometry(QRect(10, 60, 21, 20));
        labelPow11->setAlignment(Qt::AlignCenter);
        labelPow8 = new QLabel(synt_ctrl);
        labelPow8->setObjectName(QString::fromUtf8("labelPow8"));
        labelPow8->setGeometry(QRect(60, 10, 21, 20));
        labelPow8->setAlignment(Qt::AlignCenter);
        labelPow6 = new QLabel(synt_ctrl);
        labelPow6->setObjectName(QString::fromUtf8("labelPow6"));
        labelPow6->setGeometry(QRect(110, 60, 21, 20));
        labelPow6->setAlignment(Qt::AlignCenter);
        labelPres32 = new QLabel(synt_ctrl);
        labelPres32->setObjectName(QString::fromUtf8("labelPres32"));
        labelPres32->setGeometry(QRect(110, 200, 21, 20));
        labelPres32->setAlignment(Qt::AlignCenter);
        labelPres8 = new QLabel(synt_ctrl);
        labelPres8->setObjectName(QString::fromUtf8("labelPres8"));
        labelPres8->setGeometry(QRect(60, 250, 21, 20));
        labelPres8->setAlignment(Qt::AlignCenter);
        labelPres16 = new QLabel(synt_ctrl);
        labelPres16->setObjectName(QString::fromUtf8("labelPres16"));
        labelPres16->setGeometry(QRect(10, 200, 21, 20));
        labelPres16->setAlignment(Qt::AlignCenter);
        labelPres32_2 = new QLabel(synt_ctrl);
        labelPres32_2->setObjectName(QString::fromUtf8("labelPres32_2"));
        labelPres32_2->setGeometry(QRect(60, 150, 21, 20));
        labelPres32_2->setAlignment(Qt::AlignCenter);
        a_lineedit = new QLineEdit(synt_ctrl);
        a_lineedit->setObjectName(QString::fromUtf8("a_lineedit"));
        a_lineedit->setGeometry(QRect(10, 360, 113, 20));
        b_lineedit = new QLineEdit(synt_ctrl);
        b_lineedit->setObjectName(QString::fromUtf8("b_lineedit"));
        b_lineedit->setGeometry(QRect(10, 400, 113, 20));
        r_lineedit = new QLineEdit(synt_ctrl);
        r_lineedit->setObjectName(QString::fromUtf8("r_lineedit"));
        r_lineedit->setGeometry(QRect(10, 440, 113, 20));
        labelCounterA = new QLabel(synt_ctrl);
        labelCounterA->setObjectName(QString::fromUtf8("labelCounterA"));
        labelCounterA->setGeometry(QRect(30, 380, 81, 20));
        labelCounterA->setAlignment(Qt::AlignCenter);
        labelCounterB = new QLabel(synt_ctrl);
        labelCounterB->setObjectName(QString::fromUtf8("labelCounterB"));
        labelCounterB->setGeometry(QRect(30, 420, 81, 20));
        labelCounterB->setAlignment(Qt::AlignCenter);
        labelCounterR = new QLabel(synt_ctrl);
        labelCounterR->setObjectName(QString::fromUtf8("labelCounterR"));
        labelCounterR->setGeometry(QRect(30, 460, 81, 20));
        labelCounterR->setAlignment(Qt::AlignCenter);
        synt_send = new QPushButton(synt_ctrl);
        synt_send->setObjectName(QString::fromUtf8("synt_send"));
        synt_send->setGeometry(QRect(10, 480, 111, 21));
        synt1_check = new QRadioButton(synt_ctrl);
        synt1_check->setObjectName(QString::fromUtf8("synt1_check"));
        synt1_check->setGeometry(QRect(20, 310, 82, 17));
        synt1_check->setChecked(true);
        synt2_check = new QRadioButton(synt_ctrl);
        synt2_check->setObjectName(QString::fromUtf8("synt2_check"));
        synt2_check->setGeometry(QRect(20, 330, 82, 17));
        SupplyCtrl = new QGroupBox(centralwidget);
        SupplyCtrl->setObjectName(QString::fromUtf8("SupplyCtrl"));
        SupplyCtrl->setGeometry(QRect(10, 220, 411, 171));
        plus_5_LO = new QCheckBox(SupplyCtrl);
        plus_5_LO->setObjectName(QString::fromUtf8("plus_5_LO"));
        plus_5_LO->setGeometry(QRect(10, 30, 101, 17));
        plus_3_3 = new QCheckBox(SupplyCtrl);
        plus_3_3->setObjectName(QString::fromUtf8("plus_3_3"));
        plus_3_3->setGeometry(QRect(10, 50, 111, 17));
        minus_5 = new QCheckBox(SupplyCtrl);
        minus_5->setObjectName(QString::fromUtf8("minus_5"));
        minus_5->setGeometry(QRect(10, 70, 70, 17));
        plus_5_RX_2_1 = new QCheckBox(SupplyCtrl);
        plus_5_RX_2_1->setObjectName(QString::fromUtf8("plus_5_RX_2_1"));
        plus_5_RX_2_1->setGeometry(QRect(150, 90, 131, 17));
        plus_5_RX_2_2 = new QCheckBox(SupplyCtrl);
        plus_5_RX_2_2->setObjectName(QString::fromUtf8("plus_5_RX_2_2"));
        plus_5_RX_2_2->setGeometry(QRect(150, 110, 131, 17));
        plus_5_TX = new QCheckBox(SupplyCtrl);
        plus_5_TX->setObjectName(QString::fromUtf8("plus_5_TX"));
        plus_5_TX->setGeometry(QRect(290, 30, 131, 17));
        plus_5_TX_2 = new QCheckBox(SupplyCtrl);
        plus_5_TX_2->setObjectName(QString::fromUtf8("plus_5_TX_2"));
        plus_5_TX_2->setGeometry(QRect(290, 70, 131, 17));
        plus_5_TX_1 = new QCheckBox(SupplyCtrl);
        plus_5_TX_1->setObjectName(QString::fromUtf8("plus_5_TX_1"));
        plus_5_TX_1->setGeometry(QRect(290, 50, 141, 17));
        plus_5_RX_1_2 = new QCheckBox(SupplyCtrl);
        plus_5_RX_1_2->setObjectName(QString::fromUtf8("plus_5_RX_1_2"));
        plus_5_RX_1_2->setGeometry(QRect(150, 70, 131, 17));
        plus_5_RX = new QCheckBox(SupplyCtrl);
        plus_5_RX->setObjectName(QString::fromUtf8("plus_5_RX"));
        plus_5_RX->setGeometry(QRect(150, 30, 131, 17));
        plus_5_RX_1_1 = new QCheckBox(SupplyCtrl);
        plus_5_RX_1_1->setObjectName(QString::fromUtf8("plus_5_RX_1_1"));
        plus_5_RX_1_1->setGeometry(QRect(150, 50, 131, 17));
        SupplyButton = new QPushButton(SupplyCtrl);
        SupplyButton->setObjectName(QString::fromUtf8("SupplyButton"));
        SupplyButton->setGeometry(QRect(180, 140, 75, 23));
        plus_5_LO_2 = new QCheckBox(SupplyCtrl);
        plus_5_LO_2->setObjectName(QString::fromUtf8("plus_5_LO_2"));
        plus_5_LO_2->setGeometry(QRect(10, 110, 131, 17));
        plus_5_LO_1 = new QCheckBox(SupplyCtrl);
        plus_5_LO_1->setObjectName(QString::fromUtf8("plus_5_LO_1"));
        plus_5_LO_1->setGeometry(QRect(10, 90, 131, 17));
        attenuator = new QGroupBox(centralwidget);
        attenuator->setObjectName(QString::fromUtf8("attenuator"));
        attenuator->setGeometry(QRect(220, 10, 201, 151));
        att_slider = new QSlider(attenuator);
        att_slider->setObjectName(QString::fromUtf8("att_slider"));
        att_slider->setGeometry(QRect(10, 30, 181, 16));
        att_slider->setMaximum(63);
        att_slider->setOrientation(Qt::Horizontal);
        att_slider->setTickPosition(QSlider::TicksAbove);
        att_slider->setTickInterval(2);
        att_line_edit = new QLineEdit(attenuator);
        att_line_edit->setObjectName(QString::fromUtf8("att_line_edit"));
        att_line_edit->setGeometry(QRect(10, 80, 181, 21));
        att_ctrl_pushbutton = new QPushButton(attenuator);
        att_ctrl_pushbutton->setObjectName(QString::fromUtf8("att_ctrl_pushbutton"));
        att_ctrl_pushbutton->setGeometry(QRect(10, 110, 181, 21));
        att_address_combo = new QComboBox(attenuator);
        att_address_combo->setObjectName(QString::fromUtf8("att_address_combo"));
        att_address_combo->setGeometry(QRect(10, 50, 181, 22));
        com_groupbox = new QGroupBox(centralwidget);
        com_groupbox->setObjectName(QString::fromUtf8("com_groupbox"));
        com_groupbox->setGeometry(QRect(10, 10, 201, 191));
        com_button = new QPushButton(com_groupbox);
        com_button->setObjectName(QString::fromUtf8("com_button"));
        com_button->setGeometry(QRect(100, 30, 91, 21));
        com_combobox = new QComboBox(com_groupbox);
        com_combobox->setObjectName(QString::fromUtf8("com_combobox"));
        com_combobox->setGeometry(QRect(10, 30, 81, 22));
        comstate_label = new QLabel(com_groupbox);
        comstate_label->setObjectName(QString::fromUtf8("comstate_label"));
        comstate_label->setGeometry(QRect(10, 60, 181, 16));
        comstate_label->setAlignment(Qt::AlignCenter);
        echo_button = new QPushButton(com_groupbox);
        echo_button->setObjectName(QString::fromUtf8("echo_button"));
        echo_button->setGeometry(QRect(10, 120, 181, 21));
        service_message = new QLabel(com_groupbox);
        service_message->setObjectName(QString::fromUtf8("service_message"));
        service_message->setGeometry(QRect(10, 150, 181, 16));
        service_message->setAlignment(Qt::AlignCenter);
        com_refresh_button = new QPushButton(com_groupbox);
        com_refresh_button->setObjectName(QString::fromUtf8("com_refresh_button"));
        com_refresh_button->setGeometry(QRect(10, 80, 181, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        synt_ctrl->setTitle(QCoreApplication::translate("MainWindow", "Synthesizer 1 control", nullptr));
#if QT_CONFIG(tooltip)
        synt_presc->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        powSelLabel->setText(QCoreApplication::translate("MainWindow", "Power select", nullptr));
        rpescSelLabel->setText(QCoreApplication::translate("MainWindow", "Prescaler select", nullptr));
        labelPow13->setText(QCoreApplication::translate("MainWindow", "-13", nullptr));
        labelPow11->setText(QCoreApplication::translate("MainWindow", "-11", nullptr));
        labelPow8->setText(QCoreApplication::translate("MainWindow", "-8", nullptr));
        labelPow6->setText(QCoreApplication::translate("MainWindow", "-6", nullptr));
        labelPres32->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        labelPres8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        labelPres16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        labelPres32_2->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        labelCounterA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        labelCounterB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        labelCounterR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        synt_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        synt1_check->setText(QCoreApplication::translate("MainWindow", "Syntesizer 1", nullptr));
        synt2_check->setText(QCoreApplication::translate("MainWindow", "Syntesizer 2", nullptr));
        SupplyCtrl->setTitle(QCoreApplication::translate("MainWindow", "Supply control", nullptr));
        plus_5_LO->setText(QCoreApplication::translate("MainWindow", "+5V LO", nullptr));
        plus_3_3->setText(QCoreApplication::translate("MainWindow", "+3.3V", nullptr));
        minus_5->setText(QCoreApplication::translate("MainWindow", "-5V Supply", nullptr));
        plus_5_RX_2_1->setText(QCoreApplication::translate("MainWindow", "+5V RX Amplifier 2_1", nullptr));
        plus_5_RX_2_2->setText(QCoreApplication::translate("MainWindow", "+5V RX Amplifier 2_2", nullptr));
        plus_5_TX->setText(QCoreApplication::translate("MainWindow", "+5V TX", nullptr));
        plus_5_TX_2->setText(QCoreApplication::translate("MainWindow", "+5V TX Amplifier 2 ", nullptr));
        plus_5_TX_1->setText(QCoreApplication::translate("MainWindow", "+5V TX Amplifier 1", nullptr));
        plus_5_RX_1_2->setText(QCoreApplication::translate("MainWindow", "+5V RX Amplifier 1_2", nullptr));
        plus_5_RX->setText(QCoreApplication::translate("MainWindow", "+5V RX", nullptr));
        plus_5_RX_1_1->setText(QCoreApplication::translate("MainWindow", "+5V RX Amplifier 1_1", nullptr));
        SupplyButton->setText(QCoreApplication::translate("MainWindow", "Send Supply", nullptr));
        plus_5_LO_2->setText(QCoreApplication::translate("MainWindow", "+5V LO Amplifier 2", nullptr));
        plus_5_LO_1->setText(QCoreApplication::translate("MainWindow", "+5V LO Amplifier 1", nullptr));
        attenuator->setTitle(QCoreApplication::translate("MainWindow", "Attenuator Control", nullptr));
        att_ctrl_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        com_groupbox->setTitle(QCoreApplication::translate("MainWindow", "COM Port", nullptr));
        com_button->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        comstate_label->setText(QCoreApplication::translate("MainWindow", "Closed", nullptr));
        echo_button->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
        service_message->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        com_refresh_button->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

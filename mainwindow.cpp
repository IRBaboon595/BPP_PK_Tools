#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    geterodine = new GeterodineModule();
    receiver = new ReceiverModule();
    transmitter = new TransmitterModule();

    geterodine->moveToThread(&thread_1);
    receiver->moveToThread(&thread_1);
    transmitter->moveToThread(&thread_1);

    thread_1.start();

    timer_echo = new QTimer();
    plus_3_3V_state = true;
    minus_5V_state = false;

    ui->att_address_combo->addItem("Address 0x00");
    ui->att_address_combo->addItem("Address 0x01");
    ui->att_address_combo->addItem("Address 0x02");
    ui->att_address_combo->addItem("Address 0x03");
    ui->att_address_combo->addItem("Address 0x04");
    ui->att_address_combo->addItem("Address 0x05");
    ui->att_address_combo->addItem("Address 0x06");
    ui->att_address_combo->addItem("Address 0x07");

    ui->plus_3_3->setChecked(true);
    ui->plus_3_3->setDisabled(true);

    ui->plus_5_LO_1->setDisabled(true);
    ui->plus_5_LO_2->setDisabled(true);

    ui->plus_5_TX_1->setDisabled(true);
    ui->plus_5_TX_2->setDisabled(true);

    ui->plus_5_RX_1_1->setDisabled(true);
    ui->plus_5_RX_1_2->setDisabled(true);
    ui->plus_5_RX_2_1->setDisabled(true);
    ui->plus_5_RX_2_2->setDisabled(true);

    COM = new QSerialPort(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());

    connect(ui->com_button, SIGNAL(clicked(bool)), this, SLOT(connectCOM()));
    connect(ui->echo_button, SIGNAL(clicked(bool)), this, SLOT(getEcho()));
    connect(timer_echo, SIGNAL(timeout()), this, SLOT(timer_echo_timeout()));
    connect(ui->SupplyButton, SIGNAL(clicked(bool)), this, SLOT(power_ctrl_Data()));
    connect(ui->att_slider, SIGNAL(valueChanged(int)), this, SLOT(selectAtt()));
    connect(ui->att_line_edit, SIGNAL(editingFinished()), this, SLOT(writeAtt()));
    connect(ui->att_ctrl_pushbutton, SIGNAL(clicked(bool)), this, SLOT(setAttenuation()));
    connect(ui->synt_send, SIGNAL(clicked(bool)), this, SLOT(setSyntParam()));

    connect(COM, SIGNAL(readyRead()), this, SLOT(readData()));
}

/**************************************** Service Functions ****************************************/

void MainWindow::connectCOM(void)
{
    if(COM->portName() != ui->com_combobox->currentText())
    {
        COM->close();
        COM->setPortName(ui->com_combobox->currentText());
    }

    COM->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    COM->setDataBits(QSerialPort::Data8);
    COM->setParity(QSerialPort::NoParity);
    COM->setStopBits(QSerialPort::OneStop);
    COM->setFlowControl(QSerialPort::NoFlowControl);
    COM->setReadBufferSize(0);
    if(COM->open(QSerialPort::ReadWrite))
    {
        ui->comstate_label->setText("<FONT COLOR=#008000>Opened</FONT>");
        com_mode = 1;
        ui->com_button->setText("Close port");
    }
    else
    {
        COM->close();
        ui->comstate_label->setText("<FONT COLOR=red>Closed</FONT>");
        ui->com_button->setText("Open port");
        com_mode = 0;
    }


}

/***************************************** Control Functions *********************************************/

void MainWindow::getEcho(void)
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;
    char echo = ECHO;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(echo);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    //qDebug() << COM->readBufferSize();
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }

}

void MainWindow::timer_echo_timeout()
{
    ui->service_message->setText("Empty");
}

void MainWindow::on_com_refresh_button_clicked()
{
    ui->com_combobox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());
}

void MainWindow::readData(void)
{
    char temp = 0;
    bool trigger = true;
    std_union len;
    len.istd = 0;
    qDebug() << "ReadyRead_Got";
    ba.append(COM->readAll());
    qDebug() << ba.size();
    int idx = ba.indexOf(SYNCHRO, 0);
    if(idx >= 0)
    {
        qDebug() << "Synchro byte found";
        if(idx > 0)
        {
            ba.remove(0,idx);
            idx = 0;
        }
        while((ba.size() >= 6) && (trigger))
        {
            qDebug() << "Potential parcel len achieved";
            len.cstd[1] = uint8_t(ba[1]);
            len.cstd[0] = uint8_t(ba[2]);
            qDebug() << len.istd;
            temp = ba[3];
            if(temp == UART_ADDR)
            {
                qDebug() << "Address achieved";
                for(int i = 0; i < len.istd; i++)
                {
                    CRC ^= ba[i];
                }
                if(CRC == 0)
                {
                    qDebug() << "XOR approved";
                    temp = ba[4];
                    switch (temp)
                    {
                    case ECHO:
                        ui->service_message->setText("Echo Got");
                        timer_echo->start(1000);
                        uart_command = 0;
                        break;
                    case SUPPLY_CTRL:

                        break;
                    default:

                        uart_command = 255;
                        timer_1->start();
                        break;
                    }
                    trigger = false;
                    ba.clear();
                }
                else
                {
                    qDebug() << "XOR error";
                    idx = ba.indexOf(SYNCHRO, 1);
                    int bad_len = idx;
                    ba.remove(0, bad_len);
                }

            }
            else
            {
                qDebug() << "Address error";
                idx = ba.indexOf(SYNCHRO, 1);
                int bad_len = idx;
                ba.remove(0, bad_len);
            }
        }
    }
    else
    {
        qDebug() << "No Synchro";
        ba.clear();
    }
    CRC = 0;
}


void MainWindow::power_ctrl_Data(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data_1 = 0;
    char data_2 = 0;
    bool state = false;

    receiver->setSup(ui->plus_5_RX->isChecked());
    transmitter->setSup(ui->plus_5_TX->isChecked());
    geterodine->setSup(ui->plus_5_LO->isChecked());

    if(receiver->getSup())
    {
        receiver->setAmpState(ui->plus_5_RX_1_1->isChecked(), 0);
        receiver->setAmpState(ui->plus_5_RX_1_2->isChecked(), 1);
        receiver->setAmpState(ui->plus_5_RX_2_1->isChecked(), 2);
        receiver->setAmpState(ui->plus_5_RX_2_2->isChecked(), 3);
    }
    else
    {
        receiver->setAmpState(false, 0);
        receiver->setAmpState(false, 1);
        receiver->setAmpState(false, 2);
        receiver->setAmpState(false, 3);
    }

    if(transmitter->getSup())
    {
        transmitter->setAmpState(ui->plus_5_TX_1->isChecked(), 0);
        transmitter->setAmpState(ui->plus_5_TX_2->isChecked(), 1);
    }
    else
    {
        transmitter->setAmpState(false, 0);
        transmitter->setAmpState(false, 1);
    }

    if(geterodine->getSup())
    {
        geterodine->setAmpState(ui->plus_5_LO_1->isChecked(), 0);
        geterodine->setAmpState(ui->plus_5_LO_2->isChecked(), 1);
    }
    else
    {
        geterodine->setAmpState(false, 0);
        geterodine->setAmpState(false, 1);
    }

    plus_3_3V_state = ui->plus_3_3->isChecked();
    minus_5V_state = ui->minus_5->isChecked();

    //first power byte ctrl
    for (int i = 0; i < 8; i++)
    {
        if(i < 4)
        {
            state = receiver->getAmpState(i);
            if(state)
            {
                data_1 &=~ (1 << i);
            }
            else
            {
                data_1 |= (1 << i);
            }
        }
        else if(i < 6)
        {
            state = transmitter->getAmpState(i - 4);
            if(state)
            {
                data_1 &=~ (1 << i);
            }
            else
            {
                data_1 |= (1 << i);
            }
        }
        else
        {
            state = geterodine->getAmpState(i - 6);
            if(state)
            {
                data_1 &=~ (1 << i);
            }
            else
            {
                data_1 |= (1 << i);
            }
        }
    }

    //second power byte ctrl
    for (int i = 0; i < 5; i++)
    {
        if(i == 0)
        {
            state = geterodine->getSup();
            if(state)
            {
                data_2 |= (1 << i);
            }
            else
            {
                data_2 &=~ (1 << i);
            }
        }
        else if(i == 1)
        {
            if(minus_5V_state)
            {
                data_2 |= (1 << i);
            }
            else
            {
                data_2 &=~ (1 << i);
            }
        }
        else if(i == 2)
        {
            if(plus_3_3V_state)
            {
                data_2 |= (1 << i);
            }
            else
            {
                data_2 &=~ (1 << i);
            }
        }
        else if(i == 3)
        {
            state = transmitter->getSup();
            if(state)
            {
                data_2 |= (1 << i);
            }
            else
            {
                data_2 &=~ (1 << i);
            }
        }
        else if(i == 4)
        {
            state = receiver->getSup();
            if(state)
            {
                data_2 |= (1 << i);
            }
            else
            {
                data_2 &=~ (1 << i);
            }
        }
    }

    data_2 |= MASK_3_3V;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }
}



/**************************************** Attenuator control ***********************************************/

void MainWindow::setAttenuation(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data_1 = 0;
    char data_2 = 0;

    data_2 = char(ui->att_address_combo->currentIndex());
    //data_1 = char(attenuation_selected);

    switch (data_2) {
    case 0x00:
        data_1 = char(receiver->getAtt(int(data_2)) * 2);
        break;
    case 0x01:
        data_1 = char(receiver->getAtt(int(data_2)) * 2);
        break;
    case 0x02:
        data_1 = char(receiver->getAtt(int(data_2)) * 2);
        break;
    case 0x03:
        data_1 = char(receiver->getAtt(int(data_2)) * 2);
        break;
    case 0x04:
        data_1 = char(transmitter->getAtt(0x00) * 2);
        break;
    case 0x05:
        data_1 = char(transmitter->getAtt(0x01) * 2);
        break;
    case 0x06:
        data_1 = char(geterodine->getAtt(0x00) * 2);
        break;
    case 0x07:
        data_1 = char(geterodine->getAtt(0x01) * 2);
        break;
    default:
        data_1 = char(0xFF);
        data_2 = char(0xFF);
        break;
    }

    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(ATT_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    ba = ba_1;
    qDebug() << ba_1;
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }
}

void MainWindow::selectAtt(void)
{
    float temp;
    int index = ui->att_address_combo->currentIndex();
    qDebug() << ui->att_slider->pos();
    qDebug() << ui->att_slider->cursor().pos();
    attenuation_selected = ui->att_slider->value();
    temp = attenuation_selected;
    temp /= 2;

    if(index < 4)
        receiver->setAtt(temp, index);

    switch (index) {
    case 0x04:
        transmitter->setAtt(temp, index - 4);
        break;
    case 0x05:
        transmitter->setAtt(temp, index - 4);
        break;
    case 0x06:
        geterodine->setAtt(temp, index - 6);
        break;
    case 0x07:
        geterodine->setAtt(temp, index - 6);
        break;
    default:
        break;
    }
    ui->att_line_edit->setText(QString::number(double(temp)));
}

void MainWindow::writeAtt(void)
{
    QString string(ui->att_line_edit->text());
    float temp = string.toFloat();
    int index = ui->att_address_combo->currentIndex();
    switch (index) {
    case 0x04:
        transmitter->setAtt(temp, index - 4);
        break;
    case 0x05:
        transmitter->setAtt(temp, index - 4);
        break;
    case 0x06:
        geterodine->setAtt(temp, index - 6);
        break;
    case 0x07:
        geterodine->setAtt(temp, index - 6);
        break;
    default:
        break;
    }

    qDebug() << temp;
    attenuation_selected = int(temp * 2);
}

/************************************** Synthesizer Functions *****************************************/

void MainWindow::setSyntParam(void)
{
    QByteArray ba_1;
    QString string;
    long_std_union temp;
    char len = 0x0E;
    char crc = 0;
    char data[8];

    if(ui->synt1_check->isChecked())
    {
        data[0] = SPI4;
    }
    else if(ui->synt2_check->isChecked())
    {
        data[0] = SPI1;
    }

    if(ui->synt_power->value() != 4)
    {
        data[1] = char(ui->synt_power->value());
    }
    else
    {
        data[1] = 0;
    }

    if(ui->synt_presc->value() != 4)
    {
        data[2] = char(ui->synt_presc->value());
    }
    else
    {
        data[2] = 0;
    }

    string = ui->a_lineedit->text();
    data[3] = char(string.toInt(nullptr, 10));

    string = ui->b_lineedit->text();
    temp.istd[1] = uint16_t(string.toInt(nullptr, 10));

    string = ui->r_lineedit->text();
    temp.istd[0] = uint16_t(string.toInt(nullptr, 10));

    data[4] = char(temp.cstd[3]);
    data[5] = char(temp.cstd[2]);
    data[6] = char(temp.cstd[1]);
    data[7] = char(temp.cstd[0]);

    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(ATT_CTRL);
    ba_1.append(data[0]);
    ba_1.append(data[1]);
    ba_1.append(data[2]);
    ba_1.append(data[3]);
    ba_1.append(data[4]);
    ba_1.append(data[5]);
    ba_1.append(data[6]);
    ba_1.append(data[7]);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }
}


MainWindow::~MainWindow()
{
    thread_1.terminate();

    delete ui;
}

void MainWindow::on_plus_5_LO_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_LO_1->setDisabled(true);
        ui->plus_5_LO_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_LO_1->setDisabled(false);
        ui->plus_5_LO_2->setDisabled(false);
    }
}

void MainWindow::on_plus_5_RX_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_RX_1_1->setDisabled(true);
        ui->plus_5_RX_1_2->setDisabled(true);
        ui->plus_5_RX_2_1->setDisabled(true);
        ui->plus_5_RX_2_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_RX_1_1->setDisabled(false);
        ui->plus_5_RX_1_2->setDisabled(false);
        ui->plus_5_RX_2_1->setDisabled(false);
        ui->plus_5_RX_2_2->setDisabled(false);
    }
}

void MainWindow::on_plus_5_TX_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_TX_1->setDisabled(true);
        ui->plus_5_TX_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_TX_1->setDisabled(false);
        ui->plus_5_TX_2->setDisabled(false);
    }
}

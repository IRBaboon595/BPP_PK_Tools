#ifndef HARDWAREDEVICE_H
#define HARDWAREDEVICE_H

#include <QObject>
#include <QString>
#include <stdint-gcc.h>
#include <stdlib.h>

class hardwareDevice : public QObject
{
    Q_OBJECT
public:
    explicit hardwareDevice(QObject *parent = nullptr);
    explicit hardwareDevice(hardwareDevice *device);
    explicit hardwareDevice(QString name);
    ~hardwareDevice();

    QString getName();
    uint8_t getID();
    QString getStatus();

    void setName(QString name);
    void setID(uint8_t id);
    void setStatus(QString stat);

    void operator=(hardwareDevice *other);
    void operator=(hardwareDevice other);

private:
    QString         devName;
    uint8_t         devID;
    QString         devStatus;



signals:

public slots:
};

#endif // HARDWAREDEVICE_H

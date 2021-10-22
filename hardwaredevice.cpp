#include "hardwaredevice.h"

hardwareDevice::hardwareDevice(QObject *parent) : QObject(parent)
{
    devName = "Blank";
    devID = 0xFF;
    devStatus = "Pre-initialized";
}

hardwareDevice::hardwareDevice(hardwareDevice *device)
{
    devName = device->devName;
    devID = device->devID;
    devStatus = device->devStatus;
}

hardwareDevice::hardwareDevice(QString name)
{
   devName = name;
}

QString hardwareDevice::getName()
{
    return this->devName;
}

uint8_t hardwareDevice::getID()
{
    return this->devID;
}

QString hardwareDevice::getStatus()
{
    return this->devStatus;
}

void hardwareDevice::setName(QString name)
{
    devName = name;
}

void hardwareDevice::setID(uint8_t id)
{
    devID = id;
}

void hardwareDevice::setStatus(QString stat)
{
    devStatus = stat;
}

void hardwareDevice::operator=(hardwareDevice *other)
{
    devName = other->devName;
    devID = other->devID;
    devStatus = other->devStatus;
}

void hardwareDevice::operator=(hardwareDevice other)
{
    devName = other.devName;
    devID = other.devID;
    devStatus = other.devStatus;
}

hardwareDevice::~hardwareDevice()
{

}

#include "testdev.h"

testDev::testDev(QObject *parent) : QObject(parent)
{

}

void testDev::initTestCase()
{
    qDebug("Called before everything else.");
}

void testDev::init()
{
    qDebug("Called before every test");
}

void testDev::setUserName()
{
    hardwareDevice *temp = new hardwareDevice("Piotr");

    QCOMPARE(temp->getName(), "Piotr");
}

void testDev::setFreq()
{
    GeterodineModule *temp = new GeterodineModule();
    ReceiverModule *temp_1 = new ReceiverModule();
    TransmitterModule *temp_2 = new TransmitterModule();

    QCOMPARE(temp->getName(), "Гетеродин");
    QCOMPARE(temp_1->getName(), "Приёмник");
    QCOMPARE(temp_2->getName(), "Передатчик");
    QCOMPARE(temp->getFreq(0), 1150);
    QCOMPARE(temp_1->getAtt(0), 31.5);
    QCOMPARE(temp_2->getDac(0), -5);
}

void testDev::cleanup()
{
    qDebug("Called after any test");
}

void testDev::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}

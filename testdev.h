#ifndef TESTDEV_H
#define TESTDEV_H

#include <QObject>
#include <QTest>
#include "hardwaredevice.h"
#include "geterodinemodule.h"
#include "transmittermodule.h"
#include <QString>
#include "mainwindow.h"

class testDev : public QObject
{
    Q_OBJECT
public:
    explicit testDev(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void initTestCase(); //will be called before the first test function is executed.
    //void initTestCase_data(); //will be called to create a global test data table.
    void cleanupTestCase(); //will be called after the last test function was executed.
    void init(); //will be called before each test function is executed.
    void cleanup(); //will be called after every test function.
    void setUserName();
    void setFreq();

};

#endif // TESTDEV_H

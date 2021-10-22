#include "mainwindow.h"
#include "testdev.h"
#include "testgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new testDev, argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new testGUI, argc, argv);
    return a.exec();
}

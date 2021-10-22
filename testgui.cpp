#include "testgui.h"

testGUI::testGUI(QObject *parent) : QObject(parent)
{

}

void testGUI::initTestCase()
{
    qDebug("Called before everything else.");
}

void testGUI::init()
{
    qDebug("Called before every test");
}

void testGUI::testAtt()
{
    m = new MainWindow();
    QTest::mouseClick(m->ui->att_ctrl_pushbutton, Qt::LeftButton);
    QCOMPARE(m->ba.at(5), 63);
    m->~MainWindow();
}

void testGUI::testAttSlider()
{
    m = new MainWindow();
    QPoint point;
    QSize sl_size;
    int sl_wid = 0;
    int sl_h = 0;
    int x = 0;
    int y = 0;
    int ticks = 63;
    int tick = 1;
    sl_size = m->ui->att_slider->size();
    sl_wid = sl_size.width();
    sl_h = sl_size.height();
    y = m->ui->att_slider->pos().y();
    qDebug() << m->ui->att_slider->pos();
    x = m->ui->att_slider->pos().x() - sl_wid / 2;
    point.setX(798);
    point.setY(273);

    qDebug() << point;
    qDebug() << m->ui->att_slider->value();
    QTest::mousePress(m->ui->att_slider, Qt::LeftButton, Qt::NoModifier, point);
    point.setX(877);
    qDebug() << point;
    //QTest::mouseDClick(m.ui->att_slider, Qt::LeftButton);
    QTest::mouseMove(m->ui->att_slider, point);
    QTest::mouseRelease(m->ui->att_slider, Qt::LeftButton);
    qDebug() << m->ui->att_slider->value();
    //QCOMPARE(m.ui->att_line_edit->text(), "10");
    m->~MainWindow();
}

void testGUI::cleanup()
{
    qDebug("Called after any test");
}

void testGUI::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}


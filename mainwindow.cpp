#include "mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QBitmap>

const int WIDTH = 640;
const int HEIGHT = 480;
const int SPIDERW = 25;
const int SPIDERH = 25;


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), m_web(WIDTH, HEIGHT)
{
    m_web.fill();

    if (!m_spider.load("./Images_lab2/spider1.bmp")) {
        qDebug() << "cannot load spider image";
        exit(1);
    }
    m_spider.setMask( QBitmap("./Images_lab2/spider1.bmp") );
    setFixedSize(WIDTH, HEIGHT);
    show();
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    m_oldPos = m_newPos;
    m_newPos += QPoint(m_stepX, m_stepY);
    if (m_newPos.x() + m_stepX > WIDTH || m_newPos.x() + m_stepX < 0) {
        m_stepX = -m_stepX;
    }
    if (m_newPos.y() + m_stepX > HEIGHT || m_newPos.y() + m_stepY < 0) {
        m_stepY = -m_stepY;
    }
    update();

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!m_timerOnFlag) {
        m_timerOnFlag = true;
        m_timerId = startTimer(50);
    }
    else {
        m_timerOnFlag = false;
        killTimer(m_timerId);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painterPix(&m_web);
    painterPix.setPen( QPen (Qt::black, 2) );
    painterPix.drawLine(m_oldPos, m_newPos);

    QPainter painterWidget(this);
    painterWidget.drawPixmap(rect(), m_web);
    painterWidget.drawPixmap(m_newPos.x() - SPIDERW/2, m_newPos.y() - SPIDERH/2, SPIDERW, SPIDERH, m_spider);
}

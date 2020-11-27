#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>

class MainWindow : public QWidget
{
    Q_OBJECT
    
    bool m_timerOnFlag = false;
    int m_timerId;
    QPixmap m_web;
    QPixmap m_spider;
    QPoint m_oldPos = QPoint(0, 0);
    QPoint m_newPos = QPoint(0, 0);
    int m_stepX = 4;
    int m_stepY = 4;
    
public:
    
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
protected:
    
    void timerEvent(QTimerEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H

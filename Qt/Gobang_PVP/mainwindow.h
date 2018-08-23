#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);//鼠标按下事件
    void drawCrossLine();//画棋盘
    void Win();//判断输赢
    int situation1();
    int situation2();
    int situation3();
    int situation4();
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItem *item;
    int palyer;
    int a[15][15];
};

#endif // MAINWINDOW_H

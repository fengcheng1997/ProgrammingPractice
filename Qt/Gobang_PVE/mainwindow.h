#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>

#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

//
// FIXME:
//    (1) think how to seperate the game algoritm and GUI
//        The GUI part just draw the board and get the user input
//        passing the data between GUI and game algorithm to make the program more clear
//    (2) There are memory abuse case, please check the pointer usage
//

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);

    void drawCrossLine();   //chessboard
    void Win(); //decide whether to win or not.

    int situation1();
    int situation2();
    int situation3();
    int situation4();
    void CalculateScore(int player);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItem *item;

    int player;
    int a[15][15];
    int score_max = 0,x_max = -1, y_max = -1;
    int playerScore[15][15];
    int AIScore[15][15];
};

#endif // MAINWINDOW_H

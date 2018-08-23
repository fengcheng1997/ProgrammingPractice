#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*将每个落点的默认值设为2, 数组a用来标记落点是否有棋子*/
    for(int i = 0; i<15; ++i)
    {
        for(int j = 0; j<15; ++j)
        {
            a[i][j] = 2;
        }
    }

    palyer = 0;
    setStatusBar(0);
    scene = new QGraphicsScene;
  scene->setSceneRect(-320, -320, 600, 600);//设置场景大小

    drawCrossLine();//画棋盘

    view = new QGraphicsView;
    view->setBackgroundBrush(QColor(219, 202, 68));//设置背景颜色
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//去除QGraphicsView的滚动条
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);//设置反走样(抗锯齿)
    setCentralWidget(view);

    /*固定大小*/
    setMaximumSize(600, 600);
    setMinimumSize(600, 600);
    setWindowTitle("Chess");//设置窗口标题

}

void MainWindow::mousePressEvent( QMouseEvent *e )
{
    int x, y;
    int m, n;

    /*鼠标事件的坐标系是view,而不是scene*/
    if(e->x()<=300)
        x =(e->x()-320)/40 -1;
    else if(e->x()>300)
        x =(e->x()-320)/40;
    if(e->y()<=300)
        y = (e->y()-320)/40-1;
    else if(e->y()>300)
        y = (e->y()-320)/40;

    m = x+8;
    n = y+8;

    /*如果当前落点有棋子,弹出警告*/
    if(a[m][n] != 2)
    {
        QMessageBox::warning(this, "warning", "This Position has Already had chess!", QMessageBox::Ok);
    }
    else
    {
        if(!palyer )
        {
            a[m][n] = 0;
            scene->addEllipse(40*x, 40*y, 35, 35, QPen(Qt::NoPen),QBrush(Qt::black));//添加黑棋
        }
        else if(palyer )
        {
            a[m][n] = 1;
            scene->addEllipse(40*x, 40*y, 35, 35, QPen(Qt::NoPen),QBrush(Qt::white));//添加白棋
        }
        palyer = !palyer;//转换黑白棋子
    }

    Win();//判断输赢
}

void MainWindow::drawCrossLine()
{
    for(int i = 0; i<15; ++i)
    {
        scene->addLine(-320, -300+40*i, 280, -300+40*i);    //x1:-320,y1:-300+40*i,x2:320,y2:300+40*i
        scene->addLine(-300+40*i, -320, -300+40*i, 280);
    }
}

void MainWindow::Win()
{
    int okButton;
    if((situation1() ==1)
        ||(situation2() ==1)
        || (situation3() ==1)
        || (situation4() ==1))
    {
        view->setBackgroundBrush(QColor(100, 100, 100));
         okButton= QMessageBox::information(this, "win", "black win!", QMessageBox::Ok);
    }
    if((situation1() ==2)
        ||(situation2() ==2)
        || (situation3() ==2)
        || (situation4() ==2))
    {
        view->setBackgroundBrush(QColor(240, 240, 240));
        okButton = QMessageBox::information(this, "win", "white win!", QMessageBox::Ok);
    }


    if(okButton == QMessageBox::Ok)
    {
        /*清除棋盘*/
        QList<QGraphicsItem*> list = scene->items();
        while(!list.empty())
        {
            scene->removeItem(list.at(0));
            list.removeAt(0);
        }
        /*初始化棋盘*/
        view->setBackgroundBrush(QColor(219, 202, 68));
        for(int i = 0; i<15; ++i)
        {
            for(int j = 0; j<15; ++j)
            {
                a[i][j] = 2;
            }
        }
        palyer = 0;
        drawCrossLine();
    }
}

int   MainWindow::situation1()//五个棋子横着
{
    for(int i = 0; i< 15; ++i)
        for(int j = 0; j<15; ++j)
        {
            if(i>=0 && i<11 && j >=0 &&j<15)
            {
                if(	a[i][j] == 0
                    &&a[i+1][j] == 0
                    &&a[i+2][j] == 0
                    &&a[i+3][j] == 0
                    &&a[i+4][j] == 0)
                    return 1;
                if(	a[i][j] == 1
                    &&a[i+1][j] == 1
                    &&a[i+2][j] == 1
                    &&a[i+3][j] == 1
                    &&a[i+4][j] == 1)
                    return 2;
            }
        }
        return 0;
}

int MainWindow::situation2()//五个棋子竖着
{
    for(int i = 0; i< 15; ++i)
        for(int j = 0; j<15; ++j)
        {
            if(i>=0 &&i<15 &&j>=0 &&j<11)
            {
                if(	a[i][j] == 0
                    &&a[i][j+1] == 0
                    &&a[i][j+2] == 0
                    &&a[i][j+3] == 0
                    &&a[i][j+4] == 0)
                    return 1;
                if(	a[i][j] == 1
                    &&a[i][j+1] == 1
                    &&a[i][j+2] == 1
                    &&a[i][j+3] == 1
                    &&a[i][j+4] == 1)
                    return 2;
            }
        }
        return 0;
}

int MainWindow::situation3()//五个棋子向下斜着
{
    for(int i = 0; i< 15; ++i)
        for(int j = 0; j<15; ++j)
        {
            if(i>=0&& i<11&&j>=4&&j<15)
            {
                if(	a[i][j] == 0
                    &&a[i+1][j-1] == 0
                    &&a[i+2][j-2] == 0
                    &&a[i+3][j-3] == 0
                    &&a[i+4][j-4] == 0)
                    return 1;
                if(	a[i][j] == 1
                    &&a[i+1][j-1] == 1
                    &&a[i+2][j-2] == 1
                    &&a[i+3][j-3] == 1
                    &&a[i+4][j-4] == 1)
                    return 2;
            }

        }
        return 0;
}

int MainWindow::situation4()//五个棋子向上斜着
{
    for(int i = 0; i< 15; ++i)
        for(int j = 0; j<15; ++j)
        {
            if(i>=0&& i<15&&j>=0&&j<11)
            {
                if(	a[i][j] == 0
                    &&a[i+1][j+1] == 0
                    &&a[i+2][j+2] == 0
                    &&a[i+3][j+3] == 0
                    &&a[i+4][j+4] == 0)
                    return 1;
                if(	a[i][j] == 1
                    &&a[i+1][j+1] == 1
                    &&a[i+2][j+2] == 1
                    &&a[i+3][j+3] == 1
                    &&a[i+4][j+4] == 1)
                    return 2;
            }
        }
        return 0;
}

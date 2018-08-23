#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*set the default value as 2*/
    for(int i = 0; i<15; i++)
    {
        for(int j = 0; j<15; j++)
        {
            a[i][j] = 0;
        }
    }

    player = -1;
    setStatusBar(0);    //Setting the status bar to 0 will remove it from the main window.
    scene = new QGraphicsScene;
    scene->setSceneRect(-320, -320, 600, 600);  //set a rectangle: x:-300,y:-300,w:600,h:600

    drawCrossLine();    //the a of Gobang

    view = new QGraphicsView;
    view->setBackgroundBrush(QColor(219, 202, 68));    //set the player of background
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //remove the scroll bar for good
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);  //Sets the current scene to scene.
    view->setRenderHint(QPainter::Antialiasing);    //make the scene more fluent
    setCentralWidget(view); //Sets the given widget to be the main window's central widget.

    /*set the size of mainwindow to be 600x600 forever*/
    setMaximumSize(600, 600);   //Sets the maximum width to maxw and the maximum height to maxh.
    setMinimumSize(600, 600);
    setWindowTitle("Chess");    //set the title of the window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawCrossLine()    //the coordinates of scene
{
    for(int i = 0; i<15; i++)
    {
        scene->addLine(-320, -300+40*i, 280, -300+40*i);    //x1:-320,y1:-300+40*i,x2:320,y2:300+40*i
        scene->addLine(-300+40*i, -320, -300+40*i, 280);
    }
}

void MainWindow::mousePressEvent( QMouseEvent *e )  //the coordinates of view which is different form scene
{
    int x = -1, y = -1;
    int m = -1, n = -1;

    /*the coordinates of mouse events is the coordinates of view, rather than those of scene*/
    if(e->x()<=300) //Mouse move events will occur only when a mouse button is pressed down, so when the user press it, e->x()can be used.
        x =(e->x()-320)/40 -1; //e->x():Returns the x position of the mouse cursor, relative to the widget that received the event.
    else if(e->x()>300)
        x =(e->x()-320)/40;
    if(e->y()<=300)
        y = (e->y()-320)/40-1;
    else if(e->y()>300)
        y = (e->y()-320)/40;

    m = x+8;
    n = y+8;

    /*If a pawn is at the current landing point, a warning is popped out.*/
    if(a[m][n] != 0)
    {
        QMessageBox::warning(this, "warning", "This Position has Already had chess!", QMessageBox::Ok);
    }
    else
    {
        if(player == -1 )
        {
            a[m][n] = -1;
            scene->addEllipse(40*x, 40*y, 35, 35, QPen(Qt::NoPen),QBrush(Qt::black));   //(x,y,w,h,the kind of pen, the player of the ellipse)
        }
        else if(player == 1 )
        {
            a[m][n] = 1;
            scene->addEllipse(40*x, 40*y, 35, 35, QPen(Qt::NoPen),QBrush(Qt::white));   //white chess
        }

     player *= -1; //change player
     CalculateScore(player);
     scene->addEllipse(40*(x_max-8), 40*(y_max-8), 35, 35, QPen(Qt::NoPen),QBrush(Qt::white));
     player *= -1; //change player
     Win();//判断输赢
    }

}


void MainWindow::Win()
{
    int okButton = 0;
    if((situation1() ==-1)
        ||(situation2() ==-1)
        || (situation3() ==-1)
        || (situation4() ==-1))
    {
        view->setBackgroundBrush(QColor(100, 100, 100));    //set the player of background
         okButton= QMessageBox::information(this, "win", "black win!", QMessageBox::Ok); //QMessageBox::information has a return which is QMessageBox::Ok, and it assigns to okButton
    }
    if((situation1() ==1)
        ||(situation2() ==1)
        || (situation3() ==1)
        || (situation4() ==1))
    {
        view->setBackgroundBrush(QColor(240, 240, 240));    //set the player of background
        okButton = QMessageBox::information(this, "win", "white win!", QMessageBox::Ok);
    }

    if(okButton == QMessageBox::Ok)
    {
        /*clear the chessa*/
        QList<QGraphicsItem*> list = scene->items(); //use Qlist to store items of scene
        while(!list.empty())
        {
            scene->removeItem(list.at(0)); //Removes the item item and all its children from the scene.
            list.removeAt(0); //Removes the item at index position i.
        }
        /*Initialize chessa*/
        view->setBackgroundBrush(QColor(219, 202, 68));    //set the player of background
        for(int i = 0; i<15; i++)
        {
            for(int j = 0; j<15; j++)
            {
                a[i][j] = 0;
            }
        }
        player = -1;
        drawCrossLine();
    }
}

int   MainWindow::situation1() //sidewards
{
    for(int i = 0; i< 15; i++)
        for(int j = 0; j<15; j++)
        {
            if(i>=0 && i<11 && j >=0 &&j<15)
            {
                if(	a[i][j] == -1
                    &&a[i+1][j] == -1
                    &&a[i+2][j] == -1
                    &&a[i+3][j] == -1
                    &&a[i+4][j] == -1)
                {
                    return -1;
                }

                if(	a[i][j] == 1
                    &&a[i+1][j] == 1
                    &&a[i+2][j] == 1
                    &&a[i+3][j] == 1
                    &&a[i+4][j] == 1)
                {
                    return 1;
                }
            }
        }
        return 0;
}

int MainWindow::situation2() //Obliquely
{
    for(int i = 0; i< 15; i++)
        for(int j = 0; j<15; j++)
        {
            if(i>=0 &&i<15 &&j>=0 &&j<11)
            {
                if(	a[i][j] == -1
                    &&a[i][j+1] == -1
                    &&a[i][j+2] == -1
                    &&a[i][j+3] == -1
                    &&a[i][j+4] == -1)
                {
                    return -1;
                }
                if(	a[i][j] == 1
                    &&a[i][j+1] == 1
                    &&a[i][j+2] == 1
                    &&a[i][j+3] == 1
                    &&a[i][j+4] == 1)
                {
                    return 1;
                }
            }
        }
        return 0;
}

int MainWindow::situation3() //down Obliquely
{
    for(int i = 0; i< 15; i++)
        for(int j = 0; j<15; j++)
        {
            if(i>=0&& i<11&&j>=4&&j<15)
            {
                if(	a[i][j] == -1
                    &&a[i+1][j-1] == -1
                    &&a[i+2][j-2] == -1
                    &&a[i+3][j-3] == -1
                    &&a[i+4][j-4] == -1)
                {
                    return -1;
                }
                if(	a[i][j] == 1
                    &&a[i+1][j-1] == 1
                    &&a[i+2][j-2] == 1
                    &&a[i+3][j-3] == 1
                    &&a[i+4][j-4] == 1)
                {
                    return 1;
                }
            }

        }
        return 0;
}

int MainWindow::situation4() //up Obliquely
{
    for(int i = 0; i< 15; i++)
        for(int j = 0; j<15; j++)
        {
            if(i>=0&& i<15&&j>=0&&j<11)
            {
                if(	a[i][j] == -1
                    &&a[i+1][j+1] == -1
                    &&a[i+2][j+2] == -1
                    &&a[i+3][j+3] == -1
                    &&a[i+4][j+4] == -1)
                {
                    return -1;
                }
                if(	a[i][j] == 1
                    &&a[i+1][j+1] == 1
                    &&a[i+2][j+2] == 1
                    &&a[i+3][j+3] == 1
                    &&a[i+4][j+4] == 1)
                {
                    return 1;
                }
            }
        }
        return 0;
}

void MainWindow::CalculateScore(int player)
{
    int k = -1;
    int x_AI = -1, y_AI = -1, x_P = -1, y_p = -1;
    int score_AI = 0, score_P = 0;
    int Oppositeplayer = (-1 * player);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            AIScore[i][j] = 0;
            playerScore[i][j] = 0;
        }
    }


    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(a[i][j] == 0)
        {
            /***** the score of AI  ****/
            k = 1;
            while (a[i][j + k] == player && (j + k) < 15)    //Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;
            }

            k = 1;
            while (a[i][j - k] == player && (j - k) >= 0)    //the opposite of Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j] == player && (i + k) < 15)    //X direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j] == player && (i - k) >= 0)    //the opposite of x direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j + k] == player && (i + k) < 15 && (j + k) < 15)    //Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j - k] == player && (i - k) >= 0 && (j - k) >= 0)    //the opposite of Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j - k] == player && (j - k) >= 0 && (i + k) < 15)    //left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j + k] == player && (i - k) >= 0 && (j + k) < 15)    //the opposite of left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: AIScore[i][j] += 0;break;
                case 1: AIScore[i][j] += 10;break;
                case 2: AIScore[i][j] += 100;break;
                case 3: AIScore[i][j] += 1000;break;
                case 4: AIScore[i][j] += 5000;break;

            }

/***** the score of player  ****/

            k = 1;
            while (a[i][j + k] == Oppositeplayer && (j + k) < 15)    //Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i][j - k] == Oppositeplayer && (j - k) >= 0)    //the opposite of Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j] == Oppositeplayer && (i + k) < 15)    //X direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j] == Oppositeplayer && (i - k) >= 0)    //the opposite of x direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j + k] == Oppositeplayer && (i + k) < 15 && (j + k) < 15)    //Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j - k] == Oppositeplayer && (i - k) >= 0 && (j - k) >= 0)    //the opposite of Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i + k][j - k] == Oppositeplayer && (j - k) >= 0 && (i + k) < 15)    //left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }

            k = 1;
            while (a[i - k][j + k] == Oppositeplayer && (i - k) >= 0 && (j + k) < 15)    //the opposite of left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: playerScore[i][j] += 0;break;
                case 1: playerScore[i][j] += 10;break;
                case 2: playerScore[i][j] += 100;break;
                case 3: playerScore[i][j] += 1000;break;
                case 4: playerScore[i][j] += 5000;break;

            }
        }
    }

    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(AIScore[i][j] > score_AI)
        {
            score_AI = AIScore[i][j];
            x_AI = i;
            y_AI = j;
        }
    }

    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(playerScore[i][j] > score_P)
        {
            score_P = playerScore[i][j];
            x_P = i;
            y_p = j;
        }
    }

    if(score_AI > score_P)
    {
        score_max = score_AI;
        x_max = x_AI;
        y_max = y_AI;
    }
    else
    {
        score_max = score_P;
        x_max = x_P;
        y_max = y_p;
    }

     a[x_max][y_max] = player;
}

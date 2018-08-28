#ifndef GOBANG_H
#define GOBANG_H

#include <iostream>
#include <string.h>

using std::cout; // FIXME: do not using using in header file
using std::cin;
using std::endl;

class Gobang
{
private:
    int Board[15][15];
    int score[2][15][15] = {{{0}}}; //score[0][15][15]:AI; score[1][15][15]:Player 
                                // FIXME: think to use 1-D array to make the program easy to read
                                //        The initialize is not correct in some compiler, I can not compile the code
    int score_max = 0,x_max = -1, y_max = -1;

public:
    Gobang();
    ~Gobang();

    int getX(){return x_max;}
    int getY(){return y_max;}

	int CheckWin();
	void Show();
	void PeopleGo(int Color);
	void AIGo(int x_max, int y_max, int Color);
	void CalculateScore(int Color);

};

#endif // GOBANG_H

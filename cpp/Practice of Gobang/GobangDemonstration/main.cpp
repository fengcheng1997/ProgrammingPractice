#include <iostream>
#include <unistd.h>
#include <fstream>



#include "include/Gobang.h"

using namespace std;

int main()
{
	int IsWin = -1;
	int Color;
	char _NextStep[3];

	Gobang gobang;

	//cout << "First hand:-1, Back hand:1" << endl;
	//cin >> Color;
	Color = 1;

    gobang.Show();

    fstream infile;
    infile.open("test.dat");

    for(int i = 0; i < 2; i++)
    {
        infile >> _NextStep[i];
    }
    gobang.PeopleGo(Color, _NextStep);

    Color *= (-1);
    gobang.CalculateScore(Color);
    gobang.AIGo(gobang.getX(), gobang.getY(), Color);

    //system("clear");
    gobang.Show();

	while (1)
	{

        Color *= (-1);
		for(int i = 0; i < 2; i++)
        {
            infile >> _NextStep[i];
        }
        gobang.PeopleGo(Color, _NextStep);

        IsWin = gobang.CheckWin();
		if (IsWin != 0)
		{
		    //system("clear");
		    //gobang.Show();
			cout << "Congraduate " << (IsWin == 1 ? "Black" : "White")  << endl;
            break;
		}

		Color *= (-1);
        gobang.CalculateScore(Color);
        gobang.AIGo(gobang.getX(), gobang.getY(), Color);

        //system("clear");
        gobang.Show();

        IsWin = gobang.CheckWin();
		if (IsWin != 0)
		{
		    //system("clear");
		    //gobang.Show();
			cout << "Congraduate " << (IsWin == 1 ? "Black" : "White")  << endl;
            break;
		}
	}

	return 0;
}

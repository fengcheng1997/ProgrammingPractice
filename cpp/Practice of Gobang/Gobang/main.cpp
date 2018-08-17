#include <iostream>
#include <unistd.h>



#include "include/Gobang.h"

using namespace std;

int main()
{
	int IsWin = -1;
	int Color;
	Gobang gobang;

	//cout << "First hand:-1, Back hand:1" << endl;
	//cin >> Color;
	Color = 1;

    gobang.Show();

    gobang.PeopleGo(Color);

    Color *= (-1);
    gobang.CalculateScore(Color);
    gobang.AIGo(gobang.getX(), gobang.getY(), Color);

    system("clear");
    gobang.Show();

	while (1)
	{

        Color *= (-1);
		gobang.PeopleGo(Color);

        IsWin = gobang.CheckWin();
        cout << IsWin << endl;
		if (IsWin != 0)
		{
		    system("clear");
		    gobang.Show();
			cout << "Congraduate " << (IsWin == 1 ? "Black" : "White")  << endl;
            break;
		}

		Color *= (-1);
        gobang.CalculateScore(Color);
        gobang.AIGo(gobang.getX(), gobang.getY(), Color);

        system("clear");
        gobang.Show();

        IsWin = gobang.CheckWin();
        cout << IsWin << endl;
		if (IsWin != 0)
		{
		    system("clear");
		    gobang.Show();
			cout << "Congraduate " << (IsWin == 1 ? "Black" : "White")  << endl;
            break;
		}
	}

	return 0;
}

#include "Gobang.h"

#include <iostream>


Gobang::Gobang()
{
   for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			Board[i][j] = 0;
		}
	}
}

Gobang::~Gobang()
{
    //dtor
}

void Gobang::Show()
{
	cout << "  ";
	for (int i = 0; i <  15; i++)
    {
		cout << " " << (char)(i + 'a');
	}
	cout << endl;

	for (int i = 0; i <  15; i++)
	{
        cout << " " << (char)(i + 'A');

		for (int j = 0; j <  15; j++)
		{
			if (Board[i][j] == 0)
			{
				cout << "十";
			}
			else if (Board[i][j] == 1)
			{
				cout << "○ ";
			}
			else if (Board[i][j] == -1)
			{
				cout << "● ";
			}
		}
		cout << endl;
	}
}


int Gobang::CheckWin()
{
	int k = 1;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
		    if(Board[i][j] != 0)
            {
                while (Board[i][j] == Board[i][j + k])    //Y direction
                {
                    k++;
                    if (k == 5)
                        return Board[i][j];
                }

                k = 1;
                while (Board[i][j] == Board[i+k][j + k])  //Right oblique underneath
                {
                    k++;
                    if (k == 5)
                        return Board[i][j];
                }

                k = 1;
                while (Board[i][j] == Board[i+k][j])  //X direction
                {
                    k++;
                    if (k == 5)
                        return Board[i][j];
                }

                k = 1;
                while (Board[i][j] == Board[i - k][j + k])    //Left oblique underneath
                {
                    k++;
                    if (k == 5)
                        return Board[i][j];
                }
            }
		}
	}
	return 0;
}


void Gobang::PeopleGo(int Color)
{
	int x, y;
	char NextStep[3];

	cout << "Please input coordinates like Aa" << endl;
	cin >> NextStep;

	while (strlen(NextStep) != 2 || !(NextStep[0] >= 'A' && NextStep[0] <= 'O') || !(NextStep[1] >= 'a' && NextStep[1] <= 'o'))
	{
		cout << "Format error!"<< endl;
		cin >> NextStep;
	}

	x = NextStep[1] - 97;
	y = NextStep[0] - 65;

	while (Board[y][x] != 0)
	{
		cout << "Coordinates error, please input again!" << endl;
		cin >> NextStep;

        x = NextStep[1] - 97;
        y = NextStep[0] - 65;
	}

    Board[y][x] = Color;
}

void Gobang::CalculateScore(int Color)
{
    int k = -1;
    int x_AI = 0, y_AI = 0, x_P = 0 y_p = 0;
    int score_AI = 0, score_P = 0;
    int OppositeColor = (-1 * Color);

    for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			score[0][i][j] = 0;
			score[1][i][j] = 0;
		}
	}


    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(Board[i][j] == 0)
        {
            /***** the score of AI  ****/
            k = 1;
            while (Board[i][j + k] == Color && (j + k) < 15)    //Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;
            }

            k = 1;
            while (Board[i][j - k] == Color && (j - k) >= 0)    //the opposite of Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j] == Color && (i + k) < 15)    //X direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j] == Color && (i - k) >= 0)    //the opposite of x direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j + k] == Color && (i + k) < 15 && (j + k) < 15)    //Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j - k] == Color && (i - k) >= 0 && (j - k) >= 0)    //the opposite of Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j - k] == Color && (j - k) >= 0 && (i + k) < 15)    //left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j + k] == Color && (i - k) >= 0 && (j + k) < 15)    //the opposite of left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[0][i][j] += 0;break;
                case 1: score[0][i][j] += 10;break;
                case 2: score[0][i][j] += 100;break;
                case 3: score[0][i][j] += 1000;break;
                case 4: score[0][i][j] += 5000;break;

            }
           /* switch(k-1)
            {
            case 0:
                {
                    if(Board[i][j-1] == Color && Board[i][j-2] == Color && Board[i][j-3] == Color && Board[i][j-4] == Color && j-4 >= 0 && (j-5 < 0 || Board[i][j-5] == OppositeColor) && (j+1 >= 15 || Board[i][j+1] == OppositeColor))
                        score[0][i][j] += 720;
                    break;
                }
            case 1:
                {
                    if(Board[i][j-2] == 0 && Board[i][j-1] == 0 && Board[i][j+2] == 0 && Board[i][j+3] == 0 && j-2 >= 0 && j+3 < 15)
                        score[0][i][j] += 20;    //type 13
                    if(Board[i][j-1] == 0 && Board[i][j+2] == 0 && Board[i][j+3] == 0 && Board[i][j+4] == 0 && j-1 >= 0 && j+4 < 15)
                        score[0][i][j] += 20;   //type 14
                    if(Board[i][j-2] == 0 && Board[i][j-3] == 0 && Board[i][j+2] == 0  && j-2 >= 0  && j+2 < 15)
                        score[0][i][j] += 120;  //type 11
                    if(Board[i][j-2] == 0 && Board[i][j+2] == 0 && Board[i][j+3] == 0  && j-2 >= 0  && j+3 < 15)
                        score[0][i][j] += 120;  //type 12
                    if(Board[i][j-1] == Color && Board[i][j-2] == Color && Board[i][j-3] == 0 && Board[i][j+2] == 0 && j-1 >= 0 && j+2 < 15)
                        score[0][i][j] += 720;  //type 3
                    if(Board[i][j-1] == Color && Board[i][j-2] == Color && Board[i][j-3] == Color && Board[i][j+2] == 0 && j-3 >= 0 && j+2 < 15 && j-4 <0 && j+3 >= 15 )
                        {
                            score[0][i][j] += 720;  //type 9
                        }
                        break;
                }
            case 2:
                {
                    if(Board[i][j-1] == 0 && Board[i][j+3] == 0 && Board[i][j+4] == 0  && j-1 >= 0  && j+4 < 15)
                        score[0][i][j] += 120;  //type 10
                    if(Board[i][j-1] == Color && Board[i][j-2] == 0 && Board[i][j+3] == 0  && j-2 >= 0 && j+3 < 15)
                        score[0][i][j] += 720;  //type 4
                    if(Board[i][j-1] == Color && Board[i][j-2] == Color && j-2 >= 0  && (j-3 < 0 || Board[i][j-3] == OppositeColor) && (j+3 >= 15 || Board[i][j+3] == OppositeColor))
                        {
                            score[0][i][j] += 720;  //type 7
                        }
                        break;
                }
            case 3:
                {
                    if(Board[i][j+4] == 0 && Board[i][j+5] == 0 && j+5 < 15)
                        score[0][i][j] += 720;  //type 1
                    if(Board[i][j-1] == 0 && Board[i][j+4] == 0 && j+4 < 15 && j-1 >= 0)
                        score[0][i][j] += 720;  //type 2
                    if(Board[i][j-1] == Color && (j-2 < 0 || Board[i][j-2] == OppositeColor) && (j+4 >= 15 || Board[i][j+4] == OppositeColor))
                        score[0][i][j] += 720;  //type 8
                    break;
                }
            case 4:
                {
                    if(Board[i][j+5] == 0)
                       {
                           score[0][i][j] += 4320;  //type 0
                       }
                    if((j-1 < 0 || Board[i][j-1] == OppositeColor) && (j+5 >= 15 || Board[i][j+5] == OppositeColor))
                       {
                           score[0][i][j] += 720;  //type 6
                       }
                       break;
                }
            }

            k = 1;
            while (Board[i][j - k] == Color && (j - k) >= 0)    //the opposite of Y direction
                {

                    k++;
                }

            k = 1;
            while (Board[i + k][j] == Color && (i + k) < 15)    //X direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }

            k = 1;
            while (Board[i - k][j] == Color && (i - k) >= 0)    //the opposite of x direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }

            k = 1;
            while (Board[i + k][j + k] == Color && (i + k) < 15 && (j + k) < 15)    //Right oblique underneath direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }

            k = 1;
            while (Board[i - k][j - k] == Color && (i - k) >= 0 && (j - k) >= 0)    //the opposite of Right oblique underneath direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }

            k = 1;
            while (Board[i + k][j - k] == Color && (j - k) >= 0 && (i + k) < 15)    //left oblique underneath direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }

            k = 1;
            while (Board[i - k][j + k] == Color && (i - k) >= 0 && (j + k) < 15)    //the opposite of left oblique underneath direction
                {
                    score[0][i][j] += 2^k;

                    k++;
                }
                */ //uncomplete program
/***** the score of Player  ****/

            k = 1;
            while (Board[i][j + k] == OppositeColor && (j + k) < 15)    //Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i][j - k] == OppositeColor && (j - k) >= 0)    //the opposite of Y direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j] == OppositeColor && (i + k) < 15)    //X direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j] == OppositeColor && (i - k) >= 0)    //the opposite of x direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j + k] == OppositeColor && (i + k) < 15 && (j + k) < 15)    //Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j - k] == OppositeColor && (i - k) >= 0 && (j - k) >= 0)    //the opposite of Right oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i + k][j - k] == OppositeColor && (j - k) >= 0 && (i + k) < 15)    //left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }

            k = 1;
            while (Board[i - k][j + k] == OppositeColor && (i - k) >= 0 && (j + k) < 15)    //the opposite of left oblique underneath direction
                {
                    k++;
                }
            switch(k-1)
            {
                case 0: score[1][i][j] += 0;break;
                case 1: score[1][i][j] += 10;break;
                case 2: score[1][i][j] += 100;break;
                case 3: score[1][i][j] += 1000;break;
                case 4: score[1][i][j] += 5000;break;

            }
        }
    }

    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(score[0][i][j] > score_AI)
        {
            score_AI = score[0][i][j];
            x_AI = i;
            y_AI = j;
        }
    }

    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
    {
        if(score[1][i][j] > score_P)
        {
            score_P = score[1][i][j];
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
}

void Gobang::AIGo(int x_max, int y_max, int Color)
{
    Board[x_max][y_max] = Color;
}







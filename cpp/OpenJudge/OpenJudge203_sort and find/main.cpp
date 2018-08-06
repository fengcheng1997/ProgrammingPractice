#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n, k;
	double temp1;
	double temp2;
	cin >> n >> k;
	double score[n][2];
	for(int i =0; i < n; i++)
		{
				for(int j = 0; j < 2; j++)
			{
				cin >> score[i][j];
			}
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(score[j][1] < score[j+1][1] )
			{
				temp1 = score[j][1];
				score[j][1] = score[j+1][1];
				score[j+1][1] = temp1;
				temp2 = score[j][0];
				score[j][0] = score[j+1][0];
				score[j+1][0] = temp2;
			}
		}
		printf("%d %g", (int)score[k-1][0],score[k-1][1]);//开始错了五遍，最后发现学号应该是int型
		cout << endl;
	return 0;
}

	/*for(int i =0; i < n; i++)
		{
				for(int j = 0; j < 2; j++)
			{
				cout << score[i][j] ;
			}
			cout <<endl;
		}
    */





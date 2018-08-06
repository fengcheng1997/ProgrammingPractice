#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for(int m = 0; m < T; m++)
	{
		int N;
		cin >> N;
		int sum = 0;
		struct ET{
		int year;//记录年份
		int number;//每年出生的小ET
		};
		ET A[N];
		for(int i = 0; i < N; i++)
		{
			A[i].year = i + 1;
		}
		for(int j = 0; j < N; j++)
		{
			if(A[j].year < 5)
			A[j].number = 1;//前四年出生的ET数
			else//之后出生的ET数
			{
				A[j].number = 0;
				for(int i = 0; i < j - 2 ; i++ )
				{
					A[j].number += A[i].number;
				}
			}
		}
		for(int i = 0; i < N; i++)
			{
				sum += A[i].number;//ET数之和
			}
		cout << sum << endl;
	}
	return 0;
}

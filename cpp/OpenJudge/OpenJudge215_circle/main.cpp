#include <cmath>//�õ���pow����

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int m = 0; m < T; m++)
	{
		int N,X,Y,R;
		cin >>N >> X >> Y >> R;
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j  < N; j++)
			{
				if((pow((X - 1 -i),2) + pow((Y - 1 -j),2)) > R*R)//���Ե㵽Բ�ĵľ�����Բ�뾶�Ĵ�С��ϵ
					cout << "x";
				else
					cout << "O";
			}

		cout << endl;
		}
	}

	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	struct Student{
	int no;
	int score;
	int number;//����һ���������������¼����˳��
	};

	Student A[N], t;
	for(int i = 0; i < N; i++)
		{
			cin >> A[i].no >> A[i].score;
			A[i].number = i;
		}

	for(int i = 0; i < N - 1; i++)
		for(int j = 0; j < N - i -1; j++)
		{
			if(A[j].score < A[j+1].score)
			{
				t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}

		for(int i = 0; i < N - 1; i++)
			for(int j = i + 1; j < N; j++)
			{
				if(A[i].score == A[j].score && A[i].number > A[j].number)//���ռ�¼��˳���ٴ�����
				{
					t = A[i];
					A[i] = A[j];
					A[j] = t;
				}
			}

	for(int i = 0; i < N; i++)

	cout << A[i].no << endl;

	return 0;
}

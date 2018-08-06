#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int m = 0; m < T; m++)
	{
		int  N;
		cin >> N;
		int A[N];
		int B[N/2];
		int temp = 0;
		int sum = 0;

		for(int i = 0; i < N; i++)
		{
			cin >> A[i];
		}

		for(int i = 0; i < N - 1; i++)
			for(int j = 0; j < N-i-1; j++)
		{
			if(A[j] < A[j+1])
			{
				temp = A[j] ;
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}//排序

		for(int i = 0; i < N/2; i++)
		{
			if(sum < 0)
				sum += B[i];
			else
				sum -= B[i];
		}//差值之和大于0则减去下一个差值，小于0则减去下一个差值

		if(sum > 0)
		cout << sum<< endl;
		else
			cout << -sum << endl;
	}
	
	return 0;
}

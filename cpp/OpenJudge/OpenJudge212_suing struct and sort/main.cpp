
#include <iostream>

using namespace std;

int main()
{
	int T,N;
		struct Coco{
		int L;
		int D;
		long int M;
	};

	cin >> T;

	int B[T];

	for(int m =0; m < T; m++)
	{
	cin >> N;
	Coco A[N], temp;

	for(int i = 0; i < N; i++)
		cin >> A[i].L >> A[i].D >> A[i].M;

	for(int i = 0 ; i < N - 1; i++)
		for(int j = 0; j < N - i -1; j++)
			if(A[j].L < A[j+1].L || (A[j].L == A[j+1].L && A[j].D > A[j+1].D) ||
				(A[j].L == A[j+1].L && A[j].D == A[j+1].D && A[j].M < A[j+1].M))//一次性满足三个条件
			{
				temp  = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}//排序

			B[m] = A[0].M;//将每组巧克力的最大值存储
	}

	for(int i = 0; i < T; i++)

	cout << B[i] << endl;

	return 0;
}
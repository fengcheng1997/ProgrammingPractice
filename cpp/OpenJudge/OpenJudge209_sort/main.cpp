
#include <iostream>

using namespace std;

int main()
{
	int N = 10;
	int temp = 0;
	int num[N] {0};

	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for(int i = 0; i < N - 1; i++)
		for(int j = 0; j < N - i -1; j ++)
		{
			if(num[j] > num[j+1])
				{
					temp = num[j];
					num[j] = num[j+1];
					num[j+1]  = temp;
				}
		}

	cout << num[0] << " " << num[1] << endl;

	return 0;
}
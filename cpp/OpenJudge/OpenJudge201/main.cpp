#include <iostream>
using namespace std;

string   sum(int * nums, int n, int k)
{
		for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if((nums[i] + nums[j]) == k)
			{
				return "yes";
			}
		}
	}
	return "no";
}

int main()
{
	int n , k;
	cin >> n >> k;
	int nums[n];
	for(int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cout << sum(nums, n, k) << endl;
	return 0;
}


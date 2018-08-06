#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int k;
	int nums[n];

	cin >> n;

	for(int i = 0; i < n; i ++)
	{
		cin >> nums[i];
	}

	cin >> k;

	cout << nums[k - 1] << endl;

	return 0;
}

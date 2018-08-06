#include <iostream>
using namespace std;
int main()
{
	int n;
	int k;
	cin >> n;
	int nums[n];
	for(int i = 0; i < n; i ++)
	{
		cin >> nums[i];
	}
	cin >> k;
	cout << nums[k - 1] << endl;
	return 0;
}

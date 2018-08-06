#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int m,n;
	cin >> m;
	cin >> n;
	int nums[m];
	double sum = 0;
	double avg = 0;
	int j = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> nums[i];
		if(nums[i] > n)
		{
			sum += nums[i];
			j++;
		}
	}
	cout << fixed << setprecision(2);
	avg = sum / j;
	cout << avg << endl;
	return 0;
}

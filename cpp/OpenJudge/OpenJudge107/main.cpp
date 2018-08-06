#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	double avg;
	cin >> n ;
	for(int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		sum += j;
	}
	avg = (double)sum / n;
	cout << fixed << setprecision(5) << sum << " " << avg << endl;
	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int Chinese = 89;
	int Math = 96;
	int English = 99;
	int sum;
	double avg;

	sum = Chinese + Math + English;
	avg = (double)(sum / 3);
	
	cout << sum << endl;
	cout << avg << endl;

	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int year,month,n = 0;
	cin >> year >> month;
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		{
			n = 31;
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		{
			n = 30;
		}
	case 2: n = 28;
	}

	if(year % 4 == 0 && year  % 100 != 0){
		n += 1;
	}

	cout << n << endl;

	return 0;
}

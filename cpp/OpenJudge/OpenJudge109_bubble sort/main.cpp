#include <iostream>

using namespace std;

int main()
{
	int nums[5];
	int temp = 0;
	int j = 0;

	for(int i = 0; i < 5; i++)
	{
		cin >> nums[i];
	}

	for(int i = 0; i < 4; i++)
	{
		j = i;
		if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
	}

	cout << nums[4] << endl;
	
	return 0;
}

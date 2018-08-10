#include <iostream>

using namespace std;

int main()
{
	int nums[5];
	int temp = 0;
	int j = 0;

    // FIXME: can you using file to load data, and make some test case to evalue
    // the program
    // FIXME: how to make the sort algorithm to be a function, therefore, it can
    // be used by other program

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

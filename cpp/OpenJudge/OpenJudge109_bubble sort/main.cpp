#include <iostream>

using namespace std;

void bubble_sort(int n, int nums[]);

int main()
{
	int nums[5];

    // FIXME: can you using file to load data, and make some test case to evalue
    // the program
    // FIXME: how to make the sort algorithm to be a function, therefore, it can
    // be used by other program

	for(int i = 0; i < 5; i++)
	{
		cin >> nums[i];
	}

    bubble_sort(5, nums);

	cout << nums[4] << endl;

	return 0;
}

void bubble_sort(int n, int nums[]) //make the sort algorithm to be a function, so it can be used by other program
{
    int j = 0, temp = 0;

		for(int i = 0; i < n-1; i++)
	{
		j = i;
		if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
	}
}

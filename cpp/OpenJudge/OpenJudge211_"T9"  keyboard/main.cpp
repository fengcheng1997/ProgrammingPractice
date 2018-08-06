#include <iostream>
using namespace std;
int main()
{
	int n;
	char nums1[100];
	int counter1 = 0;
	int counter2 = 0;
	int nums2 [10];

	cin >>n;

	for(int m = 0; m < n; m++)
	{
		counter2 = 0;//复原counter2
		cin >> nums1;
		int length = 0;

		while(1)
		{
			if(nums1[length++] == 0)
				break;
		}

		length--;//计算字符串的长度

		for(int i = 0; i < 10 ; i++)
		{
			nums2[i] = 0;//复原nums2
		}

		for(int i = 0; i < length - 1; i++)
		{
			for(int j = i; j < i + 2; j++)
			{
				if(nums1[j] < 'C' + 1)
				nums2[2] = 2;
			else if(nums1[j] < 'F' + 1)
				nums2[3] = 3;
			else if(nums1[j] < 'I' + 1)
				nums2[4] = 4;
			else if(nums1[j] < 'L' + 1)
				nums2[5] = 5;
			else if(nums1[j] < 'O' + 1)
				nums2[6] = 6;
			else if(nums1[j] < 'S' + 1)
				nums2[7] = 7;
			else if(nums1[j] < 'V' + 1)
				nums2[8] = 8;
			else if(nums1[j] < 'Z' + 1)
				nums2[9] = 9;
			}

			for(int j = 2; j < 10; j++)
			{
				if(nums2[j] != 0)
					counter1++;
			}

			if(	counter1 == 2)
					counter2 += 1;

			counter1 = 0;//复原counter1

			for(int i = 0; i < 10 ; i++)
			{
				nums2[i] = 0;
			}
		}

	cout << "Case #" << m+1 << ": " << counter2 << endl;

	}
	
	return 0;
}

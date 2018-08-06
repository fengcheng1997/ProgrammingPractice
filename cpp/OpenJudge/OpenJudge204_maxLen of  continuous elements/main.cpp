#include <iostream>

using namespace std;

int main()
{
	int n = -1;
	int maxLen = 0;
	int len = 0;
    
    // FIXME: How to exit the loop?, better way?
	for(;n != 0;)
	{
		cin >> n;
		int nums[n];
		for(int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		for(int i = 0; i < n - 1; i++)
		{
			if(nums[i] == nums[i+1])
			{
				len += 1;
				if(len > maxLen)  maxLen = len;
			}
			else len = 0;
		}
			maxLen++;//上述maxLen比实际的少1 FIXME: use English comment is better

			if(n != 0)

			cout << maxLen << endl;
		
			maxLen = 0;
			len = 0;
	 }

	return 0;
}

#include <iostream>
#include <stdio.h>
#include<string.h>

using namespace std;
int main()
{
	char s1[30];
	int s2[30] ;
	char s3[30] = {'A'} ;
	int k = 0;
	int len = 0;
	int temp;
	while((scanf("%s", s1))!=EOF)
	{
	cin >> k;
	len = strlen(s1);
	for(int i = 0; i < len; i++)
	{
		cin >> s2[i];
	}
	for(int i = 0; i < len; i++)
	{
		temp = s2[i]-1;
		s3[i] = (char)(s1[temp] + k);
	}
		for(int i = 0; i < len; i++)
	{
		if(s3[i]  > 'Z' )
		s3[i] = (char)(s3[i] - 26) ;
	}
		cout << s3 <<endl;
	}
	return 0;
}

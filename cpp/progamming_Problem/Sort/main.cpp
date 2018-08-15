#include <iostream>
#include <algorithm>

using namespace std;

bool cmp1(int a,int b);

int main()
{
    int A[] = {0,2,7,3};

    sort(A,A+4,cmp1);

    for(int i = 0; i < 4 ; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

bool cmp1(int a,int b)//int为数组数据类型
{
    return a>b;//降序排列
    //return a<b;//默认的升序排列
}

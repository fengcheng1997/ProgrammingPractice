#include <iostream>
#include <vector>

using namespace std;

void Arrangement(int A[], int n, int _n);

int main()
{
    int n = 0, _n = 0;
    cout << "请输入个数n:";
    cin >> n;
    _n = n;
    int A[n];

    for(int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }


    Arrangement(A, n, _n);
    return 0;
}

void Arrangement(int A[], int n, int _n)
{
    int B[n];
    for(int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }

    if(_n == 1)
    {
        for(int i = 0; i < n; i++)
        {
            cout << A[i] << " " ;   //_n == 1时，输出所有元素
        }
        cout << endl;
    }

    if(_n >= 2)
    {
        for(int j = 0; j < _n; j++)
        {
            for(int i = 0; i < n; i++)
                {
                    A[i] = B[i];    //用B[n]储存原始数组，用其将A[n]初始化
                }


            int temp = A[j];
            for(int i = j; i < _n-1; i++)
            {
                A[i] = A[i+1];
            }
            A[_n-1] = temp; //将首元素移到尾部，其他元素向前移动

            Arrangement(A, n, _n-1);    //_n-1在下一个函数处

        }
    }
}

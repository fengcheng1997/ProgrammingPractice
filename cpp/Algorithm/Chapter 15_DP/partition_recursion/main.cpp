#include <iostream>
#include <limits.h>

using namespace std;

int cut(int p[], int n)
{
    if(n == 0)
        return 0;

    int q = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        q = max(q, (p[i]+cut(p, n-i)));
    }

    return q;
}

int main()
{
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 4;

    cout << cut(p, n) << endl;

    return 0;
}

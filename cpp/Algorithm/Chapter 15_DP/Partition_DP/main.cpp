#include <iostream>
#include <limits.h>

using namespace std;

int cut(int p[], int n)
{
    int r[n] = {0};

    for(int i = 1; i <= n; i++)
    {
        int q = INT_MIN;

        for(int j = 1; j <= i; j++)
        {
            q = max(q, (p[j]+r[i-j]));
        }

        r[i] = q;
    }

    return r[n];
}

int main()
{
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 4;

    cout << cut(p, n) << endl;

    return 0;
}

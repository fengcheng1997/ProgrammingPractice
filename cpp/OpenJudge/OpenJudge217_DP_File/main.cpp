#include <iostream>
#include <limits.h>
#include <fstream>

using namespace std;

long int minimum(long int s, long int t, long int L[], long int C[], long int distance[])
{
    if(s == t)
        return 0;

    long int total_distance = 0;
    long int total_cost = 0;
    long int Min = INT_MAX;

    for(long int i = s; i < t; i++)
    {

        for(long int j = i; j<t ;j++)    //caculate the total_cost
        {
             total_distance += distance[j];

            if(total_distance <=3)
            {
                total_cost = C[1];
            }
            else if(total_distance <= 6)
            {
                total_cost = C[2];
            }
            else if(total_distance <= 8)
            {
                total_cost = C[3];
            }
            else
            {
                break;
            }

            Min = min(Min, (total_cost+minimum(j+1, t , L, C, distance)));
        }
    }


    return Min;
}

int main()
{
    long int L[4] = {0}, C[4] = {0};
    long int n, s, t;

    fstream infile;
    infile.open("railway.in");

    for(long int i = 0; i < 3; i++)
    {
        infile >> L[i+1];
    }

        for(long int i = 0; i < 3; i++)
    {
        infile >> C[i+1];
    }

    infile >> n;
    infile >> s;
    infile >> t;

    long int len[n] = {0}, distance[n] = {0};

    for(long int i = 1; i < n; i++)
    {
        infile >> len[i];
    }

    infile.close();

    for(long int i = 1; i < n; i++)
    {
        distance[i] = len[i] - len[i-1];
    }

    if(s > t)
    {
        long int temp = s;
        s = t;
        t =temp;
    }

        long int Min = 100000;

    Min = minimum(s, t, L, C, distance);

    cout << Min << endl;
    return 0;
}


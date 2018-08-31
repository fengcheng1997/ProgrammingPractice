#include <iostream>

using namespace std;

int main()
{
    int front = 0, rear = 0, count = 0, n = 0, temp = 0;
    cin >> n;
    int data[n];
    for(int i = 0; i < n; i++)
    {
        data[i] = i + 1;
        rear = (rear + 1) % n;
        count++;
    }
    while(count != 0)
    {
        if(count != 0)
        {
            temp = data[front];
            cout << temp << " ";    //output the number of people speaking "1"
            data[front] = 0;
            front = (front + 1) % n;
            count--;
        }

        if(count != 0)
        {
            data[rear] = data[front];
            data[front] = 0;                //set people speaking "2" in the tail of the queue
            front = (front + 1) % n;
            rear = (rear + 1) % n;
        }
    }
    return 0;
}

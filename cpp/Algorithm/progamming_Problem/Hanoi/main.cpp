#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int n, char X, char Y, char Z)
{
    if(n < 1)   cout << "块数n小于1，错误" << endl;
    if(n > 1)
    {
        Hanoi(n-1,X,Z,Y);
        cout << "将" << X << "上的第"<< n << "块移动到" << Z << "上" << endl;
        Hanoi(n-1,Y,X,Z);
    }
    else if(n == 1)  cout << "将" << X << "上的第1块移动到" << Z << "上" << endl;
}

int main()
{
    cout << "请输入Hanoi问题的块数n" << endl;
    int n;
    char X = 'X', Y = 'Y', Z = 'Z';
    cin >> n;
    Hanoi(n,X,Y,Z);
    cout << "移动的总次数为" << pow(2, n) - 1 << "次" << endl;
    return 0;
}

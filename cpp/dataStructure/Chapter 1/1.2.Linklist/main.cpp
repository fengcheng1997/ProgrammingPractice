#include <iostream>
#include"include/Linklist.hpp"

using namespace std;

int main()
{
	Linklist<int> linklist;

	for(int i = 0; i < 5; i++)
	{
		linklist.insertNode(i+1);
	}

	cout << "链表内的数据为：" << endl;
    linklist.showData();

    linklist.removeNode(1);
    linklist.removeNode(1);
    linklist.findNode(3);
    linklist.clearNode();

    return 0;
}

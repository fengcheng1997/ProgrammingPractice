#include <iostream>

#include "include/Linklist.hpp"     // FIXME: add a space between include and file

using namespace std;

int main()
{
	Linklist<int> linklist;

	for(int i = 0; i < 5; i++)
	{
		linklist.insertNode(i+1);
	}

	cout << "show the data of Linklist:" << endl;
    linklist.showData();

    linklist.removeNode(1);
    linklist.removeNode(1);
    linklist.findNode(3);
    linklist.clearNode();

    return 0;
}

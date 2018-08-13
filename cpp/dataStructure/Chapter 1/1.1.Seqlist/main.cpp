#include <iostream>
#include "Seqlist.hpp"

using namespace std;

int main()
{
	cout << "Please input the length N:" << endl;

	int N = 0, data;
	cin >> N;
	Seqlist<int> seqlist(N);

	cout << "Please input N numbers:" << endl;
	for(int i = 0; i < N; i++)
	{
		cin >> data;
		seqlist.InsertElem(data);
	}

	seqlist.allElem();
	seqlist.DeletElem(1);
	seqlist.InsertElem(1,99);
	seqlist.DeletElem(99);
	seqlist.allElem();
	seqlist.ChangeElem(2,100);
	seqlist.LocatElem(1);
	seqlist.allElem();

	return 0;
}



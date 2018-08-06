#include <iostream>
#include "Seqlist.hpp"

using namespace std;

int main()
{
	cout << "若想要创建指定长度的顺序表，请输入长度N" << endl;

	int N = 0, data;
	cin >> N;
	Seqlist<int> seqlist(N);

	cout << "请输入想要储存的N个值" << endl;
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



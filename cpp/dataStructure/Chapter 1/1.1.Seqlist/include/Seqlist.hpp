#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>

using namespace std;

template <class T>
class Seqlist
{
	public:
		Seqlist(int);
		virtual ~Seqlist();

		int GetLen() { return Len; }
		bool InsertElem(T data);
		bool InsertElem(int location, T data);
		bool DeletElem(int location);
		bool DeletElem(T& data);
		T GetElem(int location);
		int LocatElem(T data);
		void allElem();
		bool ChangeElem(int location, T newData);

	private:
		T *elem;
		int maxLen;
		int Len;
};


template <class T>
Seqlist<T>::Seqlist(int defaultLen)
{
	maxLen = defaultLen;
	Len = 0;
	elem = new T[maxLen];

	for(int i = 0; i < maxLen; i++){
		elem[i] = 0;
	}
}

template <class T>
Seqlist<T>::~Seqlist()
{
	delete [] elem;
}

template <class T>
bool Seqlist<T>::InsertElem(T data)
{
	if(Len < maxLen){
		elem[Len] = data;
		Len++;
		return true;
	}
	else return false;
}

template <class T>
bool Seqlist<T>::InsertElem(int location, T data)
{
	if(Len < maxLen-1){
		for(int i = Len; i > location; i--)
		{
			elem[i] = elem[i-1];
		}

		Len++;
		elem[location] = data;
		return true;
	}

	else return false;
}

template <class T>
bool Seqlist<T>::DeletElem(int location)
{
	if(location < 0 || location > Len-1)
		return false;

	for(int i = location; i < Len; i++)
		elem[i] = elem[i+1];

	elem[Len -1] = 0;
	Len--;
	return true;
}

template <class T>
bool Seqlist<T>::DeletElem(T& data)
{
	int index = -1;
	for(int i = 0; i < Len; i++){
		if(elem[i] == data){
			index = i;
			break;
		}
	}

	if(index >= 0){
		for(int i = index; i < Len; i++)
		elem[i] = elem[i+1];

		elem[Len-1] = 0;
		Len--;
		return true;
	}
	else return false;
}

template <class T>
T Seqlist<T>::GetElem(int location)
{
	if(location < 0 || location > Len-1){
		cout << "Invalid parameter" << endl;
		return 0;
	}

	else
		return elem[location];
}

template <class T>
int Seqlist<T>::LocatElem(T data)			//����ָ��Ԫ�ص�λ��
{
	int index = -1;
	for(int i = 0; i < Len; i++){
		if(elem[i] == data){
			index = i;
			break;
		}
	}

	if(index >= 0){
		cout <<	"Ԫ��" << data << "��λ��Ϊ��" << index << endl;
		return index;
	}
	else{
		cout << "δ�ҵ�ָ��Ԫ��" << endl;
		return false;
	}
}

template <class T>
void Seqlist<T>::allElem()
{
	cout <<	"˳����е�" << Len << "��Ԫ��Ϊ��"<< endl;
	for(int i =0; i < Len; i++)
	{
		cout <<GetElem(i) << " " ;
	}

	cout << endl;
}

template <class T>
bool Seqlist<T>::ChangeElem(int location, T newData)		//�滻ָ��λ�õ�Ԫ��
{
	if(location < 0 || location > Len-1)
		return false;

	elem[location] = newData;
	return true;
}

#endif // SEQLIST_H


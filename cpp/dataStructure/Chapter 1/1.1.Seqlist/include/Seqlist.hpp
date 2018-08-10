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

		int GetLen() { return Len; }				//����˳������Ч���� FIXME: use English comment is better
		bool InsertElem(T data);					//�������ݵ�˳���β��
		bool InsertElem(int location, T data);	//�������أ��������ݵ�˳���ָ��λ��
		bool DeletElem(int location);			//ɾ��ָ��λ�õ�Ԫ��
		bool DeletElem(T& data);					//ɾ��ָ��Ԫ��(˳����е�һ��Ԫ�ر�ɾԪ�أ�,��������,ע�ⲻ��д(T data)����ΪT=intʱ������̻����
		T GetElem(int location);					//����ָ��λ�õ�Ԫ��
		int LocatElem(T data);						//����ָ��Ԫ�ص�λ��
		void allElem();								//����˳���
		bool ChangeElem(int location, T newData);	//�滻ָ��λ�õ�Ԫ��

	private:
		T *elem;		//˳�����׵�ַ
		int maxLen;	//˳������󳤶�
		int Len;			//˳������Ч����
};


template <class T>
Seqlist<T>::Seqlist(int defaultLen)
{
	maxLen = defaultLen;		//��¼��󳤶�
	Len = 0;						//��ʼ��Ч����Ϊ0
	elem = new T[maxLen];	//��������ΪmaxLen��˳���

	for(int i = 0; i < maxLen; i++){
		elem[i] = 0;
	}
}

template <class T>
Seqlist<T>::~Seqlist()
{
	delete [] elem;		//�ͷ�T[maxLen]���ڴ棻
}

template <class T>
bool Seqlist<T>::InsertElem(T data)	//�������ݵ�˳���β��
{
	if(Len < maxLen){	//elem������±�Ϊ(maxLen - 1)
		elem[Len] = data;
		Len++;
		return true;
	}
	else return false;
}

template <class T>
bool Seqlist<T>::InsertElem(int location, T data)	//�������أ��������ݵ�˳���ָ��λ��
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
bool Seqlist<T>::DeletElem(int location)		//ɾ��ָ��λ�õ�Ԫ��
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
bool Seqlist<T>::DeletElem(T& data)		//ɾ��ָ��Ԫ��(˳����е�һ��Ԫ�ر�ɾԪ�أ�,��������,ע�ⲻ��д(T data)����ΪT=intʱ������̻����
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
T Seqlist<T>::GetElem(int location)		//����ָ��λ�õ�Ԫ��
{
	if(location < 0 || location > Len-1){
		cout << "������Ч" << endl;
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


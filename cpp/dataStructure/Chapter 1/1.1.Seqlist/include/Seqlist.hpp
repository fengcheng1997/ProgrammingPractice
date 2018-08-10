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

		int GetLen() { return Len; }				//返回顺序表的有效长度 FIXME: use English comment is better
		bool InsertElem(T data);					//插入数据到顺序表尾部
		bool InsertElem(int location, T data);	//函数重载，插入数据到顺序表指定位置
		bool DeletElem(int location);			//删除指定位置的元素
		bool DeletElem(T& data);					//删除指定元素(顺序表中第一个元素被删元素）,函数重载,注意不能写(T data)，因为T=int时编译过程会混淆
		T GetElem(int location);					//返回指定位置的元素
		int LocatElem(T data);						//返回指定元素的位置
		void allElem();								//遍历顺序表
		bool ChangeElem(int location, T newData);	//替换指定位置的元素

	private:
		T *elem;		//顺序表的首地址
		int maxLen;	//顺序表的最大长度
		int Len;			//顺序表的有效长度
};


template <class T>
Seqlist<T>::Seqlist(int defaultLen)
{
	maxLen = defaultLen;		//记录最大长度
	Len = 0;						//初始有效长度为0
	elem = new T[maxLen];	//创建长度为maxLen的顺序表

	for(int i = 0; i < maxLen; i++){
		elem[i] = 0;
	}
}

template <class T>
Seqlist<T>::~Seqlist()
{
	delete [] elem;		//释放T[maxLen]的内存；
}

template <class T>
bool Seqlist<T>::InsertElem(T data)	//插入数据到顺序表尾部
{
	if(Len < maxLen){	//elem的最大下标为(maxLen - 1)
		elem[Len] = data;
		Len++;
		return true;
	}
	else return false;
}

template <class T>
bool Seqlist<T>::InsertElem(int location, T data)	//函数重载，插入数据到顺序表指定位置
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
bool Seqlist<T>::DeletElem(int location)		//删除指定位置的元素
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
bool Seqlist<T>::DeletElem(T& data)		//删除指定元素(顺序表中第一个元素被删元素）,函数重载,注意不能写(T data)，因为T=int时编译过程会混淆
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
T Seqlist<T>::GetElem(int location)		//返回指定位置的元素
{
	if(location < 0 || location > Len-1){
		cout << "参数无效" << endl;
		return 0;
	}

	else
		return elem[location];
}

template <class T>
int Seqlist<T>::LocatElem(T data)			//返回指定元素的位置
{
	int index = -1;
	for(int i = 0; i < Len; i++){
		if(elem[i] == data){
			index = i;
			break;
		}
	}

	if(index >= 0){
		cout <<	"元素" << data << "的位置为：" << index << endl;
		return index;
	}
	else{
		cout << "未找到指定元素" << endl;
		return false;
	}
}

template <class T>
void Seqlist<T>::allElem()
{
	cout <<	"顺序表中的" << Len << "个元素为："<< endl;
	for(int i =0; i < Len; i++)
	{
		cout <<GetElem(i) << " " ;
	}

	cout << endl;
}

template <class T>
bool Seqlist<T>::ChangeElem(int location, T newData)		//替换指定位置的元素
{
	if(location < 0 || location > Len-1)
		return false;

	elem[location] = newData;
	return true;
}

#endif // SEQLIST_H


# C++学习笔记

## 常用头文件
```
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
```

## 冒泡排序法
1、第一轮比较的次数： 数组的总长度；
2、下一轮比上一轮比较的次数： 少一次；

双循环
外层循环控制比较的轮数
内层循环控制每轮的比较和交换
```
int temp;
int nums[] = {14, 23, 11. 52 .3}

for(int i = 0; i < 5-1; i++)
	for(int j = 0; j < 5 - i; j++)//0-4,0-3，0-2,0-1
	{
		if(nums[j] < nums[j+1])
		{
			temp = nums[j];
			nums[j] = nums[j+1];
			nums[j+1] = temp;
		}
	}
```

## 选择排序  
1、假设第一元素是最小值  min: 45  minIndex: 0
2、第0元素分别和后面的比较，得到最小值
3、将下一元素分别和后面的比，得到接下来的最小值
```
	int nums[] {8, 4, 2, 123, 23, 344, 12};
	int numsLen = sizeof(nums) / sizeof(int);
	int min = nums[0];
	int minIndex = 0;
	int temp;

	for(int i = 0; i < numsLen - 1; i++)
	{
		min = nums[i];
		minIndex = i;

		for(int j = i + 1; j < numsLen ; j++)
		{
			if(nums[j] < min)
			{
				min = nums[j];
				minIndex = j;
			}
		}

		temp = nums[i];
		nums[i] = nums[minIndex];
		nums[minIndex] = temp;
	}

	cout << "排序后的数组" << endl;

	for(int i = 0; i < numsLen; i++)
	{
		cout << nums[i] << endl;
	}

	return 0;
```
实现数组元素的删除和插入
```
#include <iostream>
using namespace std;
int main()
{
	//double powerExample[4];
	//数组的大小一旦确定了，就不能再更改了！！
	double power[99]; //定义足够大的数组
	int powerCount = 0; //当前数组中的元素个数
	power[powerCount++] = 45771;
	power[powerCount++] = 42322;
	power[powerCount++] = 40907;
	power[powerCount++] = 40706;
	double temp;

	for(int i = 0; i < powerCount; i++)
	{
		for(int j = 0; j < powerCount - i -1; j++)
		{
			if(power[j] < power[j+1])
			{
				temp = power[j];
				power[j] = power[j+1];
				power[j+1] = temp;
			}
		}
	}

	cout << "排序后： " << endl;

	for(int i = 0; i < powerCount; i++)
	{
		cout << power[i] << '\t' ;
	}

	cout << endl;
	cout << "请输入要插入的数字：" << endl;

	int insertPower;   //放在最上面，为了便于理解在这定义了
	int insertIndex = powerCount;
	//如果比最后一个都小，就在插入到最后一个，插入后powerCount＋1
	//所以最后一个的下标就为powerCount(不用-1)
	cin >> insertPower;

	for(int i = 1; i < powerCount; i++)
	{
		if(insertPower > power[i])
		insertIndex = i;
		break;
	}

	for(int i = powerCount - 1; i > insertIndex; i--)
	{
		power[i+1] = power[i];
	}

	power[insertIndex] = insertPower;
	powerCount++;  //将数组的长度加一！！！！

	cout << "插入后： " << endl;

	for(int i = 0; i < powerCount; i++)
	{
		cout <<power[i] << "" ;
	}

	//删除
	double deletePower;
	int deleteIndex = INT_MIN;

	cout <<  "请输入要删除的数字： " << endl;
	cin >> deletePower;

	for(int i = 0; i < powerCount; i++)
	{
		if(deletePower == power[i])
		{
			deleteIndex = i;
			break;
		}
	}

	if(deleteIndex != INT_MIN)
	{
		powerCount--;
		for(int i = deleteIndex; i < powerCount; i++ )
		{
			power[i] = power[i+1];
		}

		cout << "插入后： " << endl;

		for(int i = 0; i < powerCount; i++)
		{
			cout << power[i] << "    " ;
		}
	}
	else
	{
		cout << "没有找到要删除的数字 " <<endl;
	}

	return 0;
}
```

## vector的基本用法
```
#include <vector>	
vector<double> vecDouble = {98.5, 67.9, 43.6, 32.9}
//向数组冲插入数字
vecDouble.push_back(100.8);//在尾部插入
//遍历
for(int = 0; i < vecDouble.size(); i++)
{
	cout << vecDouble[i] << endl;
}

//集合的通用遍历方法： 使用迭代器 iterator
//一下是迭代器的基本用法，高能谨慎！
vector<double>::iterator it;//得到迭代器对象,实际上是一个指针对象
//it.begin
for(it = vecDouble.begin(); it != vecDouble.end(); ++it)
{
	cout << *it << endl;	
}
```



## 内联函数与宏定义的区别
内联函数  inline    关键词：替换
区别宏定义：#define N 5//注意没有逗号（；） //以后在使用N的所有场合，都会被自动替换成5
eg.
#include <iostream>
#define s(num) num * num
inline int S(int);


using namespace std;
int main()
{
	int result1 = s(5);//25
	double result2 = s(2.5);//6,25
	int result3 = s(5 + 10);//65
	int result4 = S(5 + 10);//225
	cout << result1 << endl;
	cout << result2 << endl;
	cout	<< result3 << endl;
	cout << result4 << endl;

}

int S(int num)
{
	return num * num;
}


## 引用（reference)
引用：为对象起了另一个名字（引用即别名）
```
int int_value = 1024;
int& refValue = int_value;
//refValue指向int_value,是它的另一个名字

int& refValue2;//错，引用必须初始化
double& d = 12.3;//错，不能直接引用常量
const double& d = 12.3;//指向常量的引用
//使用引用比指针的效率高且较安全
```
注意
1、引用并非对象，只是为一个已经存在的对象起的别名
2、引用更接近const指针，一旦与某个变量关联起来，就将一直效忠于它
3、将引用变量用作参数时，函数将使用原始数据，并非副本
4、当数据所占内存比较大时，建议使用引用参数

三个版本的“交换”
```
#include <iostream>

using namespace std;
 void Swap1(int, int);
 void Swap2(int*, int*);
 void Swap3(int&, int&);
int main()
{
	int num1 = 10, num2 = 5;
	Swap1(num1, num2);
	cout << num1 << "\t" << num2 << endl;
	Swap2(&num1, &num2);//指针是地址
	cout << num1 << "\t" << num2 << endl;
	Swap3(num1, num2);//引用是别名
	cout << num1 << "\t" << num2 << endl;
	return 0;
}
 void Swap1(int num1, int num2)
 {
 	int temp;
 	temp = num1;
 	num1 = num2;
 	num2 = temp;
 }
 void Swap2(int* p1, int* p2)
 {
 	int temp;
 	temp = *p1;
 	*p1 = *p2;
 	*p2 = temp;
 }
 void Swap3(int& ref1, int& ref2)
 {
 	int temp;
 	temp = ref1;
 	ref1 = ref2;
 	ref2 = temp;
 }
 ```
 使用引用的理由
 可以更加简便的书写代码
 可以直接传递某个对象，而不只是把对象复制一份

使用引用的时候最好加一个const
eg.   void show(const int& num);//防止对象被修改

## 重载
```
bool DeletElem(int location);			//删除指定位置的元素
bool DeletElem(T& data);					//删除指定元素(顺序表中第一个元素被删元素）,函数重载,注意不能写(T data)，因为T=int时编译过程会混淆		
```
函数重载,上述代码中不能写(T data)，因为T=int时编译过程会混淆，出现问题

## 数组传参和其返回值

```
int main()
{...
	int nums[5];
...
	nums = bubble_sort(5, nums);		//数组的首地址是不能被赋值的
...
}

int* bubble_sort(int n, int nums[])
{
    int j = 0, temp = 0;

		for(int i = 0; i < n; i++)
	{
		j = i;
		if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
	}

	return 0;
}
```

 注意 
* 数组名在参数传递中可以退化为指针，但它本身是一个地址常量而不是指针（地址变量）。int[1000]是一个常量类型，对应数组名的类型等价于int* const（注意const修饰的是指针本身而不是指向的内容，即不是const int*），是个常量，无法被赋值。
* 把数组的首地址传给函数后，函数已经获得修改数组元素的能力，即和引用类型差不多，但是不能对数组的首地址再使用引用。
# sort函数
## 声明：
```#include <algorithm>```
## 原型：
```sort(first_pointer,first_pointer+n,cmp)```
## 参数解释： 第一个参数是数组的首地址，一般写上数组名就可以，因为数组名是一个指针常量。第二个参数相对较好理解，即首地址加上数组的长度n（代表尾地址的下一地址）。最后一个参数是比较函数的名称（自定义函数cmp），这个比较函数可以不写，即第三个参数可以缺省，这样sort会默认按数组升序排序。
简单例子：对数组A的0~n-1元素进行升序排序，只要写sort(A,A+n)即可；对于向量V也一样，sort(v.begin(),v.end())即可。

## 举例
```
int A[100];
bool cmp1(int a,int b)//int为数组数据类型
{
    return a>b;//降序排列
    //return a<b;//默认的升序排列
}
sort(A,A+100,cmp1);

//情况二：结构体排序
Student Stu[100];
bool cmp2(Student a,Student b)
{
    return a.id>b.id;//按照学号降序排列
    //return a.id<b.id;//按照学号升序排列
}
sort(Stu,Stu+100,cmp2);
```
# C++学习笔记

```
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>


using namespace std;
int main()
{
	cout<<"Hello world!"<<endl;
}	


#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout<<"英雄名称：\n";
	cout<<"伤害:\t\t\n"
		<<"护甲:\t\t\n"<<endl;
}

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	const float PI = 3.14f; //定义一个float类型的常量
	float radius = 4.5f; //班级
	float height = 4.0f; //高
	float volume = PI * pow(radius.2) * height; //圆柱体体积=底面积*高
	cout << "圆柱体面积为：" << volume << endl;
	getchar();
	return 0;
}
{
     cout << fixed << setprecision(2);
     float floatNum = 10.0 / 3.0;
     double doubleNum = 1.0 /3.0;
     const folat mil = 1000000;
     cout << "floatNum = " << floatNum << endl;
     cout << "100w * floatNum = " << mil * floatNum\n
     	  << "1000w * floatNum = " << 10 * mil * floatNum << endl;
	/*
	//控制cout的显示精度
	//1.强制以小数的方式显示
	cout << fixed ;
	//2.控制显示的进度
	cout << fixed << setprecision(2);
	//固定以小数的方式显示，并保留小数点后2位
	cout << setw(8) << endl;
	*/
}
```

1、多敲代码

2、完成课后作业
```
	cout << sizeof(double) << endl; //
	SetConsoleTitle("810的小实验")；
	/** 伤害 */
	double value_attack = 57.88;
	/** 攻击距离 */
	double value_


	#include <iostream>

	using namespace std;
	int main()
	{
		SetConsoleTitle
		cout << "#                    预处理    " << endl;
		     << "include              包含      " << endl;
		     << "cout                 输出      " << endl;
		     << "<<                   插入运算符" << endl;
		     << "endl                 结束输出  " << endl;
		     << "iostream             头文件    " << endl;
		     << "main                 主要的    " << endl;
		     << "using namespace std  使用命名空间" << endl;
		     getchar();
		     return 0;
	}

		//string 字符串类型
		string str = "你好，他是小臭猪"；
		cout << str << endl;

		//为数字类型起别名
		typedef int xiaochouzhu;
		xiangchouzhu num1 = 90;
		typedef string chouzhu;
		chouzhu hezhuoyue = "何卓越是臭猪"；


		#include <iomanip>

		double attack1 = 272;
		double attack2 = 250;
		double attack3 = 240;
		cout << left; \\左对齐，如果没有的话，就是右对齐
		cout << setfill('_');  \\空格处填充_
		cout << setw(8) << attack1 <<
				setw(8) << attack2 << 
				setw(8) << attack3 << endl;

	int num1 = 5, num2 =2;
	cout << num1 / num2 <<  //取除数
		 << num1 % num2 << endl;  //取余数
		 //取模（余数）的场景
		 //1、取某个数字的个位   5 % 10
		 //2、取45天是一个月零几天  45 % 30

		 double num3 = num1 / num2;
		 cout << num3 << endl;  
		  //num3 = 2 (double类型)， 因为是从右到左的运算，右边整形计算出2在赋值到num3，但是num3是double类型。
		 double num3 = (double) num1 / num2;
		 cout << num3 << endl;  
		 //num3 = 2.5   强制转换成double 


	 int num = 1024;
	 num += 90;  //num = num + 90
	 num -= 90;
	 num *= 90;
	 num /= 90;


	 //关系运算符
	 //C语言中。0表示假，非0表示真
	 //C++中，引入了布尔类型 bool
	 //bool flag = ture;  
	 //bool flag = false;
	 cout << boolalfha; //把0表示成false,1表示成true
	 cout << "15 > 88 吗? " << (15 > 88) << \n
	      << "16 < 99 吗？" << (16 < 99) << endl;

	 //逻辑运算符
	 && //两个条件都为真，结果才为真
	 || //两个条件有一个为真，结果就为真
	 !  //条件为真的时候，结果为假，反之亦然

	 2 << 3； //左移位 00000010  变为  00010000  十进制 16 
	 //空位补零
	 //要区分cout中的情况
	 cout << 3； //运算符重载了，意思是  在不同的对象时，作用是变化的


	 sizeof(type_name); //结果以字节为单位  
	 cout << sizeof(char); //1
	 cout << sizeof(string); //1
	 cout << sizeof("中文")； //5

	 int num = 5 > 6 ? 10 : 12;  //答案为12


	 if(条件为真)
	 {
	 	//
	 }

 #include <iostream>
 #include <cmath>

 using namespace std;

 int main()
 {
 	//吃用程序判断用户输入的字符是否是合法额硬盘盘符
 	char pan = '\0'
 	cin >> pan;
 	if(pan > = 'A' && pan <= 'Z')
 	{
 		cout << "是合法盘符！ " << endl;
 	}
 	else 
 	{
 		cout << "不是合法盘符！ " << endl;
 	}
 	return 0;
 }



 	//败家MM的购物车
 	double price_louis = 35000.0;
 	double price_hemes = 11044.5;
 	double price_chanel = 1535.0;
 	double total = 0;  //总价
 	double discount = 0; 
 	total = price_louis + price_hemes +price_chanel;
 	if(total > )50000
 	cout << discount = 0.7;
 	}
 	else
 	{
 		discount = 0.9; 
 	}
 	total = discount * total;
 	cout << "最终付款 " << total << endl;
 	return 0; 

 	double flowerPrice = 0;
 	cin >> flowerPrice;
 	if(flowerPrice >= 50000)
 	{
 		cout << "走！扯证去！" << endl;
 	}
 	if else(price 10000 <= flowerPrice < 50000)


 	int choice = 1;
 	switch(choice)
 	{
 	case 1: 
 		cout << 1 << endl;
 		//break;
 	case 2:
 		cout << 2 << endl;
 		break;	
 	case 3:
 		cout << 3 << endl;
 	case 4:
 		cout << 4 << endl;									
 	default:
	cout << 998 << endl;		
		case 5									
 	} 

 	int num = 5;
	cout << sizeof(num++) << endl;					
 	cout << num << endl;
 	//输出  4
		    5 //sizeof  只量取字节长度  ，里面表达式不运算 	

int i=1; //循环变量的初值；
while(i <= 10) //判断
{
	cout << "小臭猪" << endl;
	i++;
}

int i = 1;
int total = 0;
while(i <= 100)
{
	total = total + i;
	i++;
}
	cout << "1+...+100的总和" << total << endl;

//使用循环实现三次密码输入错误退出系统
int i = 1；
string password;
while（i <= 3)
{
	cout << "请输入您的密码 " << endl;
	cin >> password;
	cout << "您输入的密码的是 " << password;
	if(password ！= "12345678")
	{
		if(i != 3)
		cout << "密码错误，请再次输入密码 " << endl;
		else
		cout << "已输入三次密码，程序关闭 " << endl;
	}
}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
	//使用循环模拟拳皇对战
	int hp1 = 100;
	int hp2 = 100;
	int attack1 = 0;
	int attack2 = 0;

	srand(time(NULL));//与rand()一起用，设置一个随机数种子
	int random;
	//1.模拟玩家出招： 可以采用随机数是单数/偶数的方式来决定谁来攻击
	//奇数-八神   偶数-草薙京
	random = rand();
	whlie(hp1 > 0 && hp2 >0)
	if(random % 2 == 1)
	{
		attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
		attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
		hp2 -= attack1;
		hp1 -= attack2;
	}
	else
		{
		attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
		attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
		hp1 -= attack2;
		hp2 -= attack1;
	}
	if(hp1 < 0 && hp2 < 0)
	cout << "平局" << endl
	cout << "八神赢" << endl;
	else
	cout << "草薙京赢" << endl;
	return 0;
}

do
{
	cout << "小臭猪" << endl;
}while(i < 0);

for(表达式1; 表达式2； 表达式3)
const int N = 20； //真常量
for（int i = 0; i < 2; i++）；


//定义变量
int day = 31; //七月一共有31天
int dayOfWeek = 2;
cout << "一\t二\t三\t四\t五\t六\t日" << endl;
for(int i = 0; i < dayOfWeel - 1; i++)
{
	cout << "\t" << endl;
}
for(int i = 1; i <= day; i++)
{
	cout << i << \t << endl;
	if(i %= 7 == 0)
	cout << \n << endl;
}
return 0;


const N = 5;
int nums[N];
int numsLength	 = siseof(nums) / sizeof(int);
cout << "输出数组的长度 " << numsLength << endl;

int max = nums[0];
int maxIndex = 0;
for(int i = 1; i < numsLength; i++)
{
	if(nums[i] > max)
	{
	max = nums[i];
	maxIndex = i;
}
cout << max << i <<endl;

//冒泡排序法
1、第一轮比较的次数： 数组的总长度；
2、下一轮比上一轮比较的次数： 少一次；

双循环
外层循环控制比较的轮数
内层循环控制每轮的比较和交换

int temp;
int nums[] = {14, 23, 11. 52 .3}
for(int i = 0; i < 5-1; i++)
	for(int j = 0; j < 5 - i; j++)//0-4,0-3，0-2,0-1
	{
		if(nums[j] < nums[j+1])
		temp = nums[j];
		nums[j] = nums[j+1];
		nums[j+1] = temp;

	}

//选择排序  45,32,56,90,21
1、假设第一元素是最小值  min: 45  minIndex: 0
2、第0元素分别和后面的比较，得到最小值
3、将下一元素分别和后面的比，得到接下来的最小值

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


#include <iostream>
using namespace std;
int main()
{
	//实现数组元素的删除和插入
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

#include <iostream>
using namespace std;
int main()
{

string stu_names[] {"刘备","关羽", "张飞"};
string course_names[] {"语文", "数学", "英语"};
const int ROW = 3;
const int COL = 3;
double scores[ROW][COL];
for(int i = 0; i < ROW;  i++)//外层循环控制学生
	{
		for(int j = 0; j < COL; j++) //内层循环控制课程
		{
			cout << stu_names[i] << "的" << course_names[j] << "成绩: " ;
			cin >> scores[i][j];
		}
	}

	cout << "\t";
	for(int i = 0; i < ROW; i++)
	{
		cout << course_names[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < COL; i++)
	{
		cout << stu_names[i] << "\t";
		for(int j = 0; j < COL;  j++)
		{
			cout << scores[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}

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

//排序
sort(vecDouble.begin(),vecDouble.end());
//逆序
reverse(vecDouble.begin(),vecDouble.end());




void * ptr_num1 = &nums1;

(void *) ptr_chars；//强制把字符串指针换成空指针

double * ptr_double = nullptr; //先赋初值  空指针，一定要初始化所有的指针
double *ptr_double = 0;
double *ptr_double = NULL; //上三个式子等价


double score[] {11, 22, 33, 44, 55};
double * ptr_score = score;
cout << ptr_score[3] << endl; //输出44
cout << sizeof(score) << "\t" << sizeof(ptr_score) << endl;
//输出40  和  4     指针占四个字节
//数组-数组名就是数组的首地址
//所以指针引用的时候不用加*

int i;
double score[5] {98, 87, 65, 43, 76};
double * ptr_score;
ptr_score = score;
for(i = 0; i < 5; i++)
{
	cout << * pre_score++ << endl;
}
//指针占4个字节，但是一次移动sizeof(T)个字节（T为指针类型）

int num[5];//占20个字节
int* nums = new int[5];//占4个直接

int arrays[] {15,23,43,53,23};
int * p_arrays = arrays;
for(int i = 0; i < 5; i++)
{
	cout << *(p_arrays+i) << endl;
	//不要用p_array++，因为指针会移动
}

int arrays[] {15, 23, 43, 343, 22};
int * ptr_start = arrays;
int * ptr_end = arrays + 4;
int temp;

#include <iostream>
#include <cmath>

using namespace std;

void calcCuboid();
void calcCyclinder();
int main()
{
	int choic = -1;
	while(choice)
	{
		cout << "1、长方体" << endl;
		cout << "2、圆柱体" << endl;
		cout << "0、退出" << endl;
		cin >> choice;
		switch(choice)
		case 1: 
			calcCuboid();
			breaks;
		case 2：
			caclCyclinder();
			breaks;
	}
	return 0;
}

void calcCuboid()
{
	//输入长宽高
	double len,width,height;
	cout << "请输入长宽高： "；
	cin >> len >> width >> height;
	double v = len * width * height;
	cout << " 长方体的体积：" << v << endl;
}

void calcCycinder()
{
	double radius, height;
	cout << "请输入半径和高： " << endl;
	cin >> radius >> height;
	double Pi = 4 * atan(1.0);
	double v = Pi * pow(radius,2) * height;
	cout << "圆柱体的体积： " << v << endl;
}


//二维数组的传参
#unclude <iostream>
 using namespace std;

 viod show(double [][5], int);
 viod show(double )

int power(int, int);

int power(int num1, int num2)
{
	int result = 1;
	for(int i = 0; i < num2; i++)
	{
		result *= num1;
	}
	return result;
}

int main()
{
	int（*ptrPower)(int, int);
	ptrPower = power;
	cout << *ptrPower(3,4) << endl;
}

#include <iosream>
using namespace std;
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
void print_result(double (*)(double, double), double, double);
double addition(double num1, double num2)
{
	return num1 + num2;
}
double addition(double num1, double num2)
{
	return num1 - num2;
}
double addition(double num1, double num2)
{
	return num1 * num2;
}
double addition(double num1, double num2)
{
	if(num2 == 0)
	{
		cout << "除数不能为0！！ " << endl;
		return 0;
}
	return num1 / num2;
}

void print_result(double (*ptrCalc)(double, double), double num1, double num2)
{
	double result = ptrcalc(num1, num2);
	cout << "运算的结果为： " << result << endl; 
}


#endif


7.22  
内联函数与宏定义的区别
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


引用（reference):为对象起了另一个名字（引用即别名）
int int_value = 1024;
int& refValue = int_value;
//refValue指向int_value,是它的另一个名字

int& refValue2;//错，引用必须初始化
double& d = 12.3;//错，不能直接引用常量
const double& d = 12.3;//指向常量的引用

//使用引用比指针的效率高且较安全
注意
1、引用并非对象，只是为一个已经存在的对象起的别名
2、引用更接近const指针，一旦与某个变量关联起来，就将一直效忠于它
3、将引用变量用作参数时，函数将使用原始数据，并非副本
4、当数据所占内存比较大时，建议使用引用参数

三个版本的“交换”

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
 使用引用的理由
 可以更加简便的书写代码
 可以直接传递某个对象，而不只是把对象复制一份

使用引用的时候最好加一个const
eg.   void show(const int& num);//防止对象被修改
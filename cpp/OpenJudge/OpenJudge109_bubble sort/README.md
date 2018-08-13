# 数组传参和其返回值

```
int main()
{...
nums = bubble_sort(5, nums);
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


## 注意 
* 数组名在参数传递中可以退化为指针，但它本身是一个地址常量而不是指针（地址变量）。int[1000]是一个常量类型，对应数组名的类型等价于int* const（注意const修饰的是指针本身而不是指向的内容，即不是const int*），是个常量，无法被赋值。
* 把数组的首地址传给函数后，函数已经获得修改数组元素的能力，即和引用类型差不多，但是不能对数组的首地址再使用引用。
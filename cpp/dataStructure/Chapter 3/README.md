# 创建图

## 调试

###构建邻接表
反复出现
```
 error ld returned 1 exit status
```
百度后的含义：函数定义与调用名称不匹配
反复检查后，发现是只声明但没有定义析构函数
```
～Graphic();
```
修改成下列式子，问题解决
```
～Graphic(){}
```

增加边的时候，出现
```
warning: comparison between signed and unsigned integer expressions
```
百度后的含义：两个变量类型不一致

将
```
if(num1 > node.size()-1 || num2 > node.size()-1) return false;
```
查了vector.size()的类型，发现是无符号的整型，改为下列式子，问题解决
```
if(num1+1 > (int)node.size() || num2+1 > (int)node.size()) return false;
```

### 构建邻接矩阵

想用二级指针和二维数组来构建邻接矩阵，结果一直出现错误，改用vector<vector<int>>后解决

## 注意的问题
* 构造函数如果没有参数列表，在实例化的时候不加()，另外析构函数要声明和定义；
* 添加友元时，要注意是否先声明过类模板
* vector的size()函数返回值是无符号的整型，若用vector.size()-1可能会出现错误（无符号整型的计算与整型的不同）
* 使用类模板时尽量不要使用二级指针以及将二维数组作为函数参数，使用vector<vector<int>>可以代替二维数组
# dataStructure
Learning of datastructure


//## 新的体会
//**需要把编程过程的心得体会总结一下**

##  创建二叉树


看二叉树相关内容的时候，发现了`递归遍历`，不懂`递归`是什么意思，于是翻了其他的书看了递归的相关内容，并写和分析了`Haboi塔`的问题

接着二叉树相关内容，层序遍历需要用到`队`的知识，前几天只是粗略的看了一下，所以又翻开了其他书详细的看了一遍，并做了一个队的题目

想建立一个完全二叉树，并实现从左到右，从上到下的构建，准备用`指针数组`来保存每个节点的地址，结果出现一直出现`segmentation fault`

百度后，问题是访问了不该访问的内存，可能是使用指针出现了问题

百度的解决方法：
1、定义了指针以后记得初始化，在使用的时候记得判断是否为NULL；
2、在使用数组的时候是否被初始化，数组下标是否越界，数组元素是否存在等；
3、在变量处理的时候变量的格式控制是否合理等；

将指针数组初始化为NULL，还是不行，所以放弃了使用指针数组来储存各节点的地址，改用`vector`来储存各节点的地址

改后还是出现segmentation fault，可能是使用`new函数`造成的问题

原来：
``` 
vector<btNode<T>*> ve;
btNode *q;
q = new btNode<T>;
ve.push_back(q);
```


改：
```
vector<btNode<T>*> ve;
btNode<T> node;
node.data = 1;
ve.push_back(&node);
```
这种出现了  no match for call to 的错误，查百度是由于不匹配的问题，可能不能直接用&node

进一步改：
```
vector<btNode<T>*> ve;
btNode<T> *pNode，node;
pNode = &node;
node.data = 1;
ve.push_back(&node);
```


想用迭代器遍历vector中的数据，但是出现```need ‘typename' before 'std::vector<btNode<T>*>::iterator it = ve.begin();```,不知道是什么问题

改：  ```auto iterator = ve.begin();```
改完之后编译没有问题了，但是运行后还是出现segmentation fault，那么问题应该是在其他地方，推测是父子节点的赋值弄错了

结果发现是下标错了，vector的下标从0开始，而树的下标从1开始

解决问题后发现用其他函数如先序遍历（preOrder)还是会出现segmentation fault。想了会，应该是vector保存的东西只能相应函数里使用，不是在全局变量，
所以把vector写在树的模板类里面后，问题解决了

求父节点的时候，用下列代码又出现了segmentation fault，仔细看了一下，发现最下层的叶子节点是没有左右子节点的，所以```(*it)->lChild->data```不存在，
```
for(auto it = ve.begin()+1;it != ve.end(); it++)
{
    if((*it)->lChild->data == _data || (*it)->rChild->data == _data)
    {
        cout << _data << "的父节点为" << (*it)->data << endl;
    }
} 
```
改成下列代码，先判断有没有子节点，再判断子节点的data值是不是输入的值
```
for(auto it = ve.begin()+1;it != ve.end(); it++)
{
    if((*it)->lChild != 0 && (*it)->lChild->data == _data)
    {
        cout << _data << "的父节点为" << (*it)->data << endl;
    }

    if((*it)->rChild != 0 && (*it)->rChild->data == _data)
    {
        cout << _data << "的父节点为" << (*it)->data << endl;
    }
}
```
### 启发：
* 使用指针的时候要注意空指针，否则很容易出现egmentation fault的情况

* vector可以代替指针数组，且安全


## 创建图

### 构建邻接表
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

### 注意的问题
* 构造函数如果没有参数列表，在实例化的时候不加()，另外析构函数要声明和定义；
* 添加友元时，要注意是否先声明过类模板
* vector的size()函数返回值是无符号的整型，若用vector.size()-1可能会出现错误（无符号整型的计算与整型的不同）
* 使用类模板时尽量不要使用二级指针以及将二维数组作为函数参数，使用vector<vector<int>>可以代替二维数组





## 深度思考
* 程序里面的格式需要注意
* 程序里面写死的数字，如何避免？
* 构建树的代码，需要考虑，那些是放在类的定义，那些是放在测试代码里面
* 如何从文件读取数据来构建树？这样是否避免每次都输入数据，加快测试的过程。

上述问题都出现在二叉树里， 我准备在下一周重写一遍二叉树来解决上述问题

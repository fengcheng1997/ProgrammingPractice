# 创建二叉树

##18.08.07
@[递归|层序遍历|队]
看二叉树相关内容的时候，发现了**递归遍历**，不懂**递归**是什么意思，于是翻了其他的书看了递归的相关内容，并写和分析了**Haboi塔**的问题

接着二叉树相关内容，层序遍历需要用到队的知识，前几天只是粗略的看了一下，所以又翻开了其他书详细的看了一遍，并做了一个队的题目

##18.08.08
@[segmentation fault|指针数组|vector]
想建立一个完全二叉树，并实现从左到右，从上到下的构建，准备用**指针数组**来保存每个节点的地址，结果出现一直出现**segmentation fault**

百度后，问题是访问了不该访问的内存，可能是使用指针出现了问题

百度的解决方法：
1、定义了指针以后记得初始化，在使用的时候记得判断是否为NULL；
2、在使用数组的时候是否被初始化，数组下标是否越界，数组元素是否存在等；
3、在变量处理的时候变量的格式控制是否合理等；

将指针数组初始化为NULL，还是不行，所以放弃了使用指针数组来储存各节点的地址，改用**vector**来储存各节点的地址

改后还是出现segmentation fault，可能是使用**new函数**造成的问题

原来：
``` python
vector<btNode<T>*> ve;
btNode *q;
q = new btNode<T>;
ve.push_back(q);
```


改：
```python
vector<btNode<T>*> ve;
btNode<T> node;
node.data = 1;
ve.push_back(&node);
```
这种出现了  no match for call to 的错误，查百度是由于不匹配的问题，可能不能直接用&node

进一步改：
```python
vector<btNode<T>*> ve;
btNode<T> *pNode，node;
pNode = &node;
node.data = 1;
ve.push_back(&node);
```

##18.08.09
@[迭代器|auto|]
想用迭代器遍历vector中的数据，但是出现need ‘typename' before 'std::vector<btNode<T>*>::iterator it = ve.begin();',不知道是什么问题

改：  auto iterator = ve.begin();
改完之后编译没有问题了，但是运行后还是出现segmentation fault，那么问题应该是在其他地方，推测是父子节点的赋值弄错了

结果发现是下标错了，vector的下标从0开始，而树的下标从1开始

解决问题后发现用其他函数如先序遍历（preOrder)还是会出现segmentation fault。想了会，应该是vector保存的东西只能相应函数里使用，不是在全局变量，
所以把vector写在树的模板类里面后，问题解决了

求父节点的时候，用下列代码又出现了segmentation fault，仔细看了一下，发现最下层的叶子节点是没有左右子节点的，所以(*it)->lChild->data不存在，
```python
for(auto it = ve.begin()+1;it != ve.end(); it++)
{
    if((*it)->lChild->data == _data || (*it)->rChild->data == _data)
    {
        cout << _data << "的父节点为" << (*it)->data << endl;
    }
} 
```
改成下列代码，先判断有没有子节点，再判断子节点的data值是不是输入的值
```python
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

##最终结果
![Aaron Swartz](https://raw.githubusercontent.com/fengcheng1997/ProgrammingPractice/master/img-storage/%247%407CC6STI9CB0%7D%403OC%7D7XP.png)

##启发：
使用指针的时候要注意空指针，否则很容易出现egmentation fault的情况
vector可以代替指针数组，且安全


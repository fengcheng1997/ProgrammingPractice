#ifndef BTNODE_H
#define BTNODE_H

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <class T> class BinaryTree;

// FIXME: please use the following code style and format
template <class T>
class btNode
{
private:
    btNode<T>* lChild;
    btNode<T>* rChild;
    T data;

    friend class BinaryTree<T>;


public:
    btNode()
    {
        data = 0;
        lChild = NULL;
        rChild = NULL;
    }
    btNode(T _data)
    {
        data = _data;
        lChild = NULL;
        rChild = NULL;
    }
    virtual ~btNode()
    {
    }

    T getData() {return data;}
    btNode* getLChild() {return lChild;}
    btNode* getRChild() {return rChild;}
};

template <class T>
class BinaryTree
{
    private:
        btNode<T>* root;
        vector<btNode<T>*> ve;      // FIXME: the name 've' can be better
        btNode<T> node[10000];      // FIXME: using fixed '10000' is not good in source, how to avoid it?

    public:
        BinaryTree()
        {
            root = new btNode<T>();
            node[0] = 0;
        }
        BinaryTree(btNode<T> *_root)
        {
            root = _root;
            node[0] = 0;
        }

       ~BinaryTree()
       {
            delete root;
            root = NULL;
       }

    btNode<T>* getRoot() {return root;}

    void createBt();
    void layOrder();
    void layOrder(btNode<T> *node);
    void preOrder(btNode<T> *node);
    void inOrder(btNode<T> *node);
    void postOrder(btNode<T> *node);
    void insertNode(T _data);
    bool changeNode(T _data, T newdata);
    void parentNode();
    void sonNode();
    void getDepth();


};

template <class T>
void BinaryTree<T>::createBt()
{
    // FIXME: create data using std::cin in class file is not good, this code
    // can be placed in main.cpp or test program
    int n = 0;
    cout << "请输入想要用完全二叉树储存数值的数量n(10000以内):   ";
    cin >> n;

    cout << "请输入n个值：" << endl;
    btNode<T> *pNode;
    cin >> root->data;

    pNode = &node[0];
    ve.push_back(pNode);    //vector下标为0的数不需要，所以用node[0]占个位置
    ve.push_back(root);  //vector下标为1存储的是root

    for(int i = 1; i < n; i++)
    {
        cin >> node[i].data;
        pNode = &node[i];
        ve.push_back(pNode);
        pNode = NULL;
    }

    for(int i = 1; i <= n; i++)
    {
        if(2*i <= n)
        {
            ve[i]->lChild = ve[2*i];
        }
        else ve[i]->lChild = NULL;

        if(2*i+1 <=n)
        {
            ve[i]->rChild = ve[2*i+1];
        }
        else ve[i]->rChild = NULL;
    }
}

template <class T>
void BinaryTree<T>::layOrder()
{
    cout << "层序遍历" << endl;

    for(auto it = ve.begin()+1;it != ve.end(); it++)    //起始下标为1
    {
        cout << (*it)->data << " ";
    }

    cout << endl;
}

template <class T>
void BinaryTree<T>::preOrder(btNode<T> *node)
{
    if(node != NULL)
    {
        cout << node->getData() << " ";
        preOrder(node->getLChild());
        preOrder(node->getRChild());
    }
}

template <class T>
void BinaryTree<T>::inOrder(btNode<T> *node)
{
    if(node != NULL)
    {
        inOrder(node->getLChild());
        cout << node->getData() << " ";
        inOrder(node->getRChild());
    }
}

template <class T>
void BinaryTree<T>::postOrder(btNode<T> *node)
{
    if(node != NULL)
    {
        postOrder(node->getLChild());
        postOrder(node->getRChild());
        cout << node->getData() << " ";
    }
}

template <class T>
void BinaryTree<T>::parentNode()
{
    cout << "请输入想要查找对应父节点的子节点的值: " << endl;
    T _data;
    cin >> _data;

    if(ve[1]->data == _data)
    {
        cout << "根节点不存在父节点" << endl;
    }

    for(auto it = ve.begin()+1;it != ve.end(); it++)
    {
        if((*it)->lChild != NULL && (*it)->lChild->data == _data)
        {
            cout << _data << "的父节点为" << (*it)->data << endl;
        }

        if((*it)->rChild != NULL && (*it)->rChild->data == _data)
        {
            cout << _data << "的父节点为" << (*it)->data << endl;
        }
    }
}

template <class T>
void BinaryTree<T>::sonNode()
{
    cout << "请输入想要查找对应子节点的父节点的值: " << endl;
    T _data;
    cin >> _data;

    for(auto it = ve.begin()+1;it != ve.end(); it++)
    {
        if((*it)->data == _data)
        {
            if((*it)->lChild != NULL)
            {
                cout << _data << "的左孩子节点为" << (*it)->lChild->data;
            }
            else cout << _data << "不存在左孩子节点";

            if((*it)->rChild != NULL)
            {
                cout << "，右孩子节点为" << (*it)->rChild->data;
            }
            else cout << " " << "不存在右孩子节点";
        }
    }

}


template <class T>
void BinaryTree<T>::insertNode(T _data)
{
    cout << "在末尾插入" << _data << endl;

    int i = 0;

    for(auto it = ve.begin()+1;it != ve.end(); it++)
    {
        i++;
    }

    btNode<T> *p = &node[i];
    node[i].data = _data;

    ve.push_back(p);

    if(i%2 == 0)
    {
        ve[i/2]->lChild = ve[i];
    }
    else ve[i/2]->rChild = ve[i];

}

template <class T>
bool BinaryTree<T>::changeNode(T _data, T newdata)
{
    for(auto it = ve.begin()+1;it != ve.end(); it++)
    {
        if((*it)->data == _data)
        {
            (*it)->data = newdata;
            cout << "改变后的树" ;
            return true;
        }
    }

    return false;
}



template <class T>
void BinaryTree<T>::getDepth()
{
    int i = 0, j = 1;
    for(auto it = ve.begin()+1;it != ve.end(); it++)
    {
        i++;
    }

    while(i != 1)
    {
        i = i / 2;
        j++;
    }

    cout << "该树的深度为:" << j << endl;
}

#endif // BTNODE_H

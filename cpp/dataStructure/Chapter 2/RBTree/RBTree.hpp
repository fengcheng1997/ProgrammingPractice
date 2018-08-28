#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <memory>

template <class T> class TNode;

template <class T>
class RBTree
{
private:
    std::shared_ptr<TNode<T>>  root;
    std::shared_ptr<TNode<T>>  nil;


public:
    RBTree()
    {
        nil = std::make_shared<TNode<T>>();
        nil->lchild = nil;
        nil->rchild = nil;
        nil->parent = nil;
        nil->color = -1;

        root = nil;
    }

    RBTree(std::shared_ptr<TNode<T>>  _root)
    {
        root = _root;

        nil = new TNode<T>();
        nil->lchild = nil;
        nil->rchild = nil;
        nil->parent = nil;
        nil->color = -1;
    }

    ~RBTree()
    {
    }

    std::shared_ptr<TNode<T>>  getRoot(){return root;}
    std::shared_ptr<TNode<T>>  getNil(){return nil;}

    void leftRotate(std::shared_ptr<TNode<T>> node);
    void rightRotate(std::shared_ptr<TNode<T>> node);
    void insertNode(T _data);
    void insertFixup(std::shared_ptr<TNode<T>> newnode);
    void inOrder(std::shared_ptr<TNode<T>> node);
    void getDeepth(std::shared_ptr<TNode<T>> node,int temp, int &k);
    void transParent(std::shared_ptr<TNode<T>> oldnode, std::shared_ptr<TNode<T>> newnode);
    void deleteNode(std::shared_ptr<TNode<T>> oldnode);
    void deleteNode(T _data);
    std::shared_ptr<TNode<T>>   minimum(std::shared_ptr<TNode<T>> node);
    void deleteFixup(std::shared_ptr<TNode<T>> node);
    std::shared_ptr<TNode<T>>  findData(std::shared_ptr<TNode<T>> node, T _data);


};

template <class T>
class TNode
{
private:
    std::shared_ptr<TNode<T>> lchild, rchild, parent;
    T data;
    char color; //Red = 1, Black = -1

    friend class RBTree<T>;

public:
    TNode()
    {
        lchild = NULL;
        rchild = NULL;
        parent = NULL;
        color = 1;
    }

    TNode(T _data)
    {
        lchild = NULL;
        rchild = NULL;
        parent = NULL;
        data = _data;
        color = 1;
    }

    ~TNode(){}

    T getData() {return data;}
    std::shared_ptr<TNode<T>>  getLChild() {return lchild;}
    std::shared_ptr<TNode<T>>  getRChild() {return rchild;}
    std::shared_ptr<TNode<T>>  getParent() {return parent;}
    char getColor() {return color;}
};

template <class T>
void RBTree<T>::inOrder(std::shared_ptr<TNode<T>> node)
{
    if(node != nil)
    {
        inOrder(node->getLChild());
        std::cout << node->getData() << " ";
        inOrder(node->getRChild());
    }
}

template <class T>
void RBTree<T>::leftRotate(std::shared_ptr<TNode<T>> node)
{
    std::shared_ptr<TNode<T>> temp; //use temp to record node's rchild
    temp = node->rchild;

    node->rchild = temp->lchild;
    if(temp != nil)
    {
        if(temp->lchild != nil)
        {
            temp->lchild->parent = node;
        }

    }

    temp->parent = node->parent;
    if(node->parent != nil)
    {
        if(node == node->parent->rchild)
        {
            node->parent->rchild = temp;
        }
        else    //node == node.parent.lchild
        {
            node->parent->lchild = temp;
        }
    }
    else
    {
        root = temp;
    }

    node->parent = temp;
    temp->lchild = node;
}

template <class T>
void RBTree<T>::rightRotate(std::shared_ptr<TNode<T>> node)
{
    std::shared_ptr<TNode<T>> temp; //use temp to record node's rchild
    temp = node->lchild;

    node->lchild = temp->rchild;
    if(temp != nil)
    {
        if(temp->rchild != nil)
        {
            temp->rchild->parent = node;
        }
    }

    if(node->parent != nil)
    {
        if(node == node->parent->lchild)
        {
            node->parent->lchild = temp;
            temp->parent = node->parent;
        }
        else    //node == node.parent.lchild
        {
            node->parent->rchild = temp;
            temp->parent = node->parent;
        }
    }
    else
    {
        root = temp;
        temp->parent = nil;
    }

    node->parent = temp;
    temp->rchild = node;
}

template <class T>
void RBTree<T>::insertNode(T _data)
{
    std::shared_ptr<TNode<T>> newnode, p1, p2;   //p1:find the position of newnode  p2: find the parent of newnode

    newnode = std::make_shared<TNode<T>>();
    newnode->data = _data;
    newnode->parent = nil;
    newnode->lchild = nil;
    newnode->rchild = nil;

    p1 = root;
    p2 = nil;

    while(p1 != nil)
    {
        p2 = p1;

        if(_data < p1->data )
            p1 = p1->lchild;

        else
            p1 = p1->rchild;
    }

    newnode->parent = p2;
     if(p2 == nil)
     {
         root = newnode;
     }
    else if(p2->data > _data)
       p2->lchild = newnode;
    else p2->rchild = newnode;

    insertFixup(newnode);
}

template <class T>
void RBTree<T>::insertFixup(std::shared_ptr<TNode<T>> newnode)
{
    std::shared_ptr<TNode<T>> uncle = NULL;

    while(newnode->parent->color == 1)
    {
        if(newnode->parent == newnode->parent->parent->lchild)
        {
            uncle = newnode->parent->parent->rchild;

            if(uncle->color == 1)
            {
                newnode->parent->color = -1;
                newnode->parent->parent->color = 1;
                uncle->color = -1;
                newnode = newnode->parent->parent;
            }
            else    //uncle.color == -1
            {
                if(newnode == newnode->parent->rchild)
                {
                    newnode = newnode->parent;
                    leftRotate(newnode);
                }
                else    //newnode == newnode.parent.lchild
                {
                    newnode->parent->color = -1;
                    newnode->parent->parent->color = 1;
                    rightRotate(newnode->parent->parent);
                }
            }
        }
        else    //newnode.parent = newnode.parent.parent.rchild
        {
            uncle = newnode->parent->parent->lchild;

            if(uncle->color == 1)
            {
                newnode->parent->color = -1;
                newnode->parent->parent->color = 1;
                uncle->color = -1;
                newnode = newnode->parent->parent;
            }
            else    //uncle.color == -1
            {
                if(newnode == newnode->parent->lchild)
                {
                    newnode = newnode->parent;
                    rightRotate(newnode);
                }
                else    //newnode == newnode.parent.rchild
                {
                    newnode->parent->color = -1;
                    newnode->parent->parent->color = 1;
                    leftRotate(newnode->parent->parent);
                }
            }
        }
    }

    root->color = -1;
}

template <class T>
void RBTree<T>::getDeepth(std::shared_ptr<TNode<T>> node,int temp, int &k)
{
    if(node == nil) return;
    else
    {
        if(temp >= k)
        {
            temp++;
            k = temp;
        }
    }

    getDeepth(node->lchild, temp, k);
    getDeepth(node->rchild, temp, k);
}

template <class T>
void RBTree<T>::transParent(std::shared_ptr<TNode<T>> oldnode, std::shared_ptr<TNode<T>> newnode)
{
    if(oldnode->parent == nil)
    {
        root = newnode;
    }

    if(oldnode == oldnode->parent->lchild)
    {
        oldnode->parent->lchild = newnode;
    }

    if(oldnode == oldnode->parent->rchild)
    {
        oldnode->parent->rchild = newnode;
    }

    newnode->parent = oldnode->parent;
}


template <class T>
std::shared_ptr<TNode<T>>  RBTree<T>::minimum(std::shared_ptr<TNode<T>> node)
{
    std::shared_ptr<TNode<T>> temp = node;

    while(temp->lchild != nil)
    {
        temp = temp->lchild;
    }

    return temp;
}

template <class T>
void RBTree<T>::deleteNode(std::shared_ptr<TNode<T>> node)
{
    std::shared_ptr<TNode<T>> record = node, temp_son;
    char original_color = node->color;

    if(node->lchild == nil)
    {
        temp_son = node->rchild;
        transParent(node, node->rchild);
    }
    else if(node->rchild == nil)
    {
        temp_son = node->lchild;
        transParent(node, node->lchild);
    }
    else //Two children case
    {
        record = minimum(node->rchild);
        original_color = record->color;
        temp_son = record->rchild;

        if(record->parent == node)
            temp_son->parent = record;
        else
        {
            transParent(record, temp_son);
            record->rchild = node->rchild;
            record->rchild->parent = record;
        }
    }

    transParent(node, record);
    record->lchild = node->lchild;
    record->lchild->parent = record;
    record->color = node->color;

    if(original_color == -1)
    {
        deleteFixup(temp_son);
    }
}


template <class T>
void RBTree<T>::deleteFixup(std::shared_ptr<TNode<T>> node)
{
    std::shared_ptr<TNode<T>> brother;

    while(node != root && node->color == -1)
    {
        if(node == node->parent->lchild)
        {
            brother = node->parent->rchild;
            if(brother->color == 1)
            {
                brother->color = -1;
                node->parent->color = 1;
                leftRotate(node->parent);
                brother = node->parent->rchild;
            }

            if(brother->lchild->color == -1 && brother->rchild->color == -1)
            {
                brother->color = 1;
                node = node->parent;
            }
            else if(node->rchild->color == -1)
            {
                brother->lchild->color = -1;
                brother->color = 1;
                rightRotate(brother);
                brother = node->parent->rchild;
            }

            brother->color = node->parent->color;
            node->parent->color = -1;
            brother->rchild->color = -1;
            leftRotate(node->parent);
            node = root;
        }
        else    //node == node->parent->rchild
        {
            brother = node->parent->lchild;
            if(brother->color == 1)
            {
                brother->color = -1;
                node->parent->color = 1;
                rightRotate(node->parent);
                brother = node->parent->lchild;
            }

            if(brother->rchild->color == -1 && brother->lchild->color == -1)
            {
                brother->color = 1;
                node = node->parent;
            }
            else if(node->lchild->color == -1)
            {
                brother->rchild->color = -1;
                brother->color = 1;
                leftRotate(brother);
                brother = node->parent->lchild;
            }
        }
    }

    node->color = -1;
}

template <class T>
std::shared_ptr<TNode<T>>  RBTree<T>::findData(std::shared_ptr<TNode<T>> node, T _data)
{
    if(node->data == _data)
    {
        return node;
    }
    else
    {
        if(node->lchild != nil)
            return findData(node->lchild, _data);
        if(node->rchild != nil)
            return findData(node->rchild, _data);
    }

    return NULL;
}


template <class T>
void RBTree<T>::deleteNode(T _data)
{
    std::shared_ptr<TNode<T>> temp;
    temp = findData(root, _data);

    if(temp == NULL)
    {
        std::cout << "Can't find the data you want to delete!" << std::endl;
        return;
    }
    else
        deleteNode(temp);
}

#endif // RBTREE_H








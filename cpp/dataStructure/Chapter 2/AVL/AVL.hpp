#ifndef AVL_H
#define AVL_H

#include <memory>


template <class T> class AVLNode;

template <class T>
class AVL
{
private:
    std::shared_ptr<AVLNode<T>> root;

public:
    AVL()
    {
        root = NULL;
    }
    AVL(std::shared_ptr<AVLNode<T>> _root)
    {
        root = _root;
    }
    ~AVL() {}

    std::shared_ptr<AVLNode<T>> getRoot(){return root;}

    int setH(std::shared_ptr<AVLNode<T>> node);
    void insertNode(std::shared_ptr<AVLNode<T>> &node, T _data);
    void insertNode(T _data);
    std::shared_ptr<AVLNode<T>> LLCase(std::shared_ptr<AVLNode<T>> node);
    std::shared_ptr<AVLNode<T>> RRCase(std::shared_ptr<AVLNode<T>> node);
    std::shared_ptr<AVLNode<T>> LRCase(std::shared_ptr<AVLNode<T>> node);
    std::shared_ptr<AVLNode<T>> RLCase(std::shared_ptr<AVLNode<T>> node);
    void inOrder();
    void inOrder(std::shared_ptr<AVLNode<T>> node);
    void preOrder();
    void preOrder(std::shared_ptr<AVLNode<T>> node);
    void deleteNode(T _data);
    void deleteNode(std::shared_ptr<AVLNode<T>> &node, T _data);
    void minimum(std::shared_ptr<AVLNode<T>> &node);
    void deleteFixup(std::shared_ptr<AVLNode<T>> &node);
    void minimumFixup(std::shared_ptr<AVLNode<T>> &nodeParent, std::shared_ptr<AVLNode<T>> &node);

};

template <class T>
class AVLNode
{
private:
    std::shared_ptr<AVLNode<T>> lchild, rchild;
    T data;
    int h;

    friend class AVL<T>;

public:
    AVLNode()
    {
        lchild = NULL;
        rchild = NULL;
        h = 0;
    }
    ~AVLNode(){}

    std::shared_ptr<AVLNode<T>> getLchild(){return lchild;}
    std::shared_ptr<AVLNode<T>> getRchild(){return rchild;}
    T getData(){return data;}
    int getH(){return h;}

};

template <class T>
int AVL<T>::setH(std::shared_ptr<AVLNode<T>> node)
{
    if(node == NULL)
    {
        return 0;
    }

    return (std::max(setH(node->lchild),setH(node->rchild)) + 1);
}

template <class T>
std::shared_ptr<AVLNode<T>> AVL<T>::LLCase(std::shared_ptr<AVLNode<T>> node)
{
    std::shared_ptr<AVLNode<T>> temp;

    temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;

    return temp;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVL<T>::RRCase(std::shared_ptr<AVLNode<T>> node)
{
    std::shared_ptr<AVLNode<T>> temp;

    temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;

    return temp;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVL<T>::LRCase(std::shared_ptr<AVLNode<T>> node)
{
    std::shared_ptr<AVLNode<T>> temp1, temp2;

    temp1 = node->lchild;
    temp2 = temp1->rchild;

    temp1->rchild = temp2->lchild;
    temp2->lchild = temp1;

    node->lchild = temp2->rchild;
    temp2->rchild = node;

    return temp2;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVL<T>::RLCase(std::shared_ptr<AVLNode<T>> node)
{
    std::shared_ptr<AVLNode<T>> temp1, temp2;

    temp1 = node->rchild;
    temp2 = temp1->lchild;

    temp1->lchild = temp2->rchild;
    temp2->rchild = temp1;

    node->rchild = temp2->lchild;
    temp2->lchild = node;

    return temp2;
}

template <class T>
void AVL<T>::insertNode(std::shared_ptr<AVLNode<T>> &node, T _data)
{
    if(node == NULL)
    {
        std::shared_ptr<AVLNode<T>> newnode;

        newnode = std::make_shared<AVLNode<T>>();
        newnode->data = _data;
        node = newnode;
        return;
    }

    if(_data < node->data)
    {
        insertNode(node->lchild, _data);
        if(setH(node->lchild)-setH(node->rchild) >= 2)
           {
                if(setH(node->lchild->lchild)-setH(node->lchild->rchild) == 1)
                    node = LLCase(node);
                else    //setH(node->lchild->lchild)-setH(node->lchild->lchild) == -1
                    node = LRCase(node);
           }
    }
    else if(_data > node->data)
    {
        insertNode(node->rchild, _data);
        if(setH(node->rchild)-setH(node->lchild) >= 2)
           {
                if(setH(node->rchild->rchild)-setH(node->rchild->lchild) == 1)
                    node = RRCase(node);
                else    //setH(node->lchild->lchild)-setH(node->lchild->lchild) == -1
                    node = RLCase(node);
           }
    }
    else
    {
        std::cout << _data << " has been stored in AVLTree" << std::endl;
    }
}


template <class T>
void AVL<T>::insertNode(T _data)
{
    insertNode(root, _data);

}

template <class T>
void AVL<T>::inOrder()
{
    inOrder(root);
}


template <class T>
void AVL<T>::inOrder(std::shared_ptr<AVLNode<T>> node)
{
    if(node != NULL)
    {
        inOrder(node->getLchild());
        std::cout << node->getData() << "   ";
        inOrder(node->getRchild());
    }
}

template <class T>
void AVL<T>::preOrder()
{
    preOrder(root);
}


template <class T>
void AVL<T>::preOrder(std::shared_ptr<AVLNode<T>> node)
{
    if(node != NULL)
    {
        std::cout << node->getData() << " ";
        preOrder(node->getLchild());
        preOrder(node->getRchild());
    }
}


template <class T>
void AVL<T>::deleteNode(T _data)
{
    deleteNode(root, _data);

}


template <class T>
void AVL<T>::deleteNode(std::shared_ptr<AVLNode<T>> &node,T _data)
{
    std::shared_ptr<AVLNode<T>> temp;

    if(node == NULL)
    {
        std::cout << "Can't the data you want to delete!" << std::endl;
    }
    else
    {
        if(_data > node->data)
        {
            deleteNode(node->rchild, _data);
            deleteFixup(node);
        }
        else if(_data < node->data)
        {
            return deleteNode(node->lchild, _data);
            deleteFixup(node);
        }
        else
        {
            minimum(node);
        }
    }
}


template <class T>
void AVL<T>::minimum(std::shared_ptr<AVLNode<T>> &node)
{
    std::shared_ptr<AVLNode<T>> temp = node;

    if(node->lchild == NULL)
    {
        node = node->rchild;
    }
    else if(node->rchild == NULL)
    {
        node = node->lchild;
    }
    else
    {
        std::shared_ptr<AVLNode<T>> min = node->rchild;

        while(min->lchild != NULL)
        {
            min = min->lchild;
        }

        node->data = min->data;
        minimumFixup(node->rchild,node->rchild->lchild);
    }

}

template <class T>
void AVL<T>::minimumFixup(std::shared_ptr<AVLNode<T>> &nodeParent, std::shared_ptr<AVLNode<T>> &node)
{
    if(node->lchild != NULL)
    {
        minimumFixup(node, node->lchild);
        deleteFixup(nodeParent);
    }
    else
    {
        nodeParent->lchild = node->rchild;
        deleteFixup(nodeParent);
    }
}

template <class T>
void AVL<T>::deleteFixup(std::shared_ptr<AVLNode<T>> &node)
{
    if(setH(node->lchild)-setH(node->rchild) >= 2)
   {
        if(setH(node->lchild->lchild)-setH(node->lchild->rchild) == 1)
            node = LLCase(node);
        else    //setH(node->lchild->lchild)-setH(node->lchild->lchild) == -1
            node = LRCase(node);
   }
   else if(setH(node->rchild)-setH(node->lchild) >= 2)
   {
        if(setH(node->rchild->rchild)-setH(node->rchild->lchild) == 1)
            node = RRCase(node);
        else    //setH(node->lchild->lchild)-setH(node->lchild->lchild) == -1
            node = RLCase(node);
   }
}

#endif // AVL_H

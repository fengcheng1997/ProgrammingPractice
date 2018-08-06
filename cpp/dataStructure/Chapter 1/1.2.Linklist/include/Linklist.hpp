#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>

using namespace std;
template <class T> class ListNode;
template <class T>
class Linklist
{
    public:
        Linklist()
        {
            head = new ListNode<T>();
        }

        Linklist(ListNode<T>* node)
        {
            head = node;
        }
        ~Linklist()
        {
            delete head;
        }

        ListNode<T>* Gethead() { return head; }

        bool insertNode(int i, T newData);          //插入
        bool insertNode(T newData);                 //插入到尾部
        bool removeNode(ListNode<T> *q);            //移除，已知节点地址
        bool removeNode(int i);                     //移除，已知节点位置
        bool findNode(T _data);                     //查找
        bool clearNode();                           //清空链表
        bool showData();                            //显示所有的数据

    private:
        ListNode<T>* head;
};

template <class T>
class ListNode
{
    public:
        ListNode(){ next = NULL;}
        ListNode(T _data, ListNode<T> *nextNode = NULL)
        {
            data = _data;
            next = nextNode;
        }
        ~ListNode()
        {
            next = NULL;
        }
        T getData(){return data;};
        ListNode* getNext(){return next;}
    private:
        ListNode* next;                               //保存下一个节点的地址
        T data;                                       //改节点的数据
        friend class Linklist<T>;                     //讲Linklist设置为友元
};




template <class T>
bool Linklist<T>::insertNode(int i, T newData)                //插入
{
    ListNode<T> *q = head, *s;
    int j = 1;
    for(; j < i; j++)
    {
        q = q->next;    //移动到插入位置之前的节点
        if(q == NULL)
        {
            break;
        }
    }
    if(q == NULL && j < i) return false;
    s = new ListNode<T>;
    s->next = q->next;
    s->data = newData;
    q->next = s;
    return true;
}

template <class T>
bool Linklist<T>::insertNode(T newData) //插入至尾部
{
    ListNode<T> *q = head,*s;
    while(q->next != NULL)  //尾节点只想NULL
    {
        q = q->next;
    }
    s = new ListNode<T>;
    q->next = s;
    s->next = NULL;
    s->data = newData;
    return true;
}

template <class T>
bool Linklist<T>::removeNode(ListNode<T> *q)               //移除，已知节点地址
{
    ListNode<T> *temp = head;
    while(temp->next != q)
    {
        temp = temp->next;
        if(temp->next == NULL)
        {
            break;
        }
    }

    if(temp == NULL)  return false;

    temp->next = q->next;
    delete q;
    showData();
    return true;
}

template <class T>
bool Linklist<T>::removeNode(int i)               //移除，已知节点位置
{
    ListNode<T> *temp = head, *q;
    for(int j = 1; j < i; j++)
    {
        temp = temp->next;
        if(temp->next == NULL)
        {
            break;
        }
    }

    if(temp == NULL)  return false;

    q = temp->next;
    temp->next = q->next;
    delete q;
    cout << "移除第" << i <<"个数据后链表内的数据：" << endl;
    showData();
    return true;
}

template <class T>
bool Linklist<T>::findNode(T _data)              //查找
{
    ListNode<T> *q = head->next;    //头结点不存储数据，所以从第一个节点开始
    int i = 1;
    while(q->data != _data)
    {
        i++;
        q = q->next;
        if(q == NULL)
        {
            break;
        }
    }

    if(q == NULL) return false;

    cout << "该数据在第" << i << "个，且其坐标为：" << q << endl;
    return true;
}

template <class T>
bool Linklist<T>::clearNode()   //清空链表
{
    ListNode<T> *q = head->next;
    if(q != NULL)
    {
        q = q->next;
        delete q;
    }

    cout << "该链表已经被清空！" << endl;
    return true;
}

template <class T>
bool Linklist<T>::showData()    //输出链表内所有数据
{
    ListNode<T> *q = head;
    while(q->next != NULL)
    {
        q = q->next;
        cout << q->data << " ";
    }
    cout << endl;
    return true;
}

#endif // LINKLIST_H

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

// FIXME: Try best to avoid `using namespace` in include file
//using namespace std;

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

    bool insertNode(int i, T newData);          
    bool insertNode(T newData);                
    bool removeNode(ListNode<T> *q);           
    bool removeNode(int i);                     
    bool findNode(T _data);                     
    bool clearNode();                           
    bool showData();                            

private:
    ListNode<T>* head;
};

// FIXME: please idendent using 4 space (or tab with 4 space)
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
    ListNode* next;                               
    T data;                                       
    friend class Linklist<T>;                     
};




template <class T>
bool Linklist<T>::insertNode(int i, T newData)                
{
    ListNode<T> *q = head, *s;
    int j = 1;
    for(; j < i; j++)
    {
        q = q->next;    
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
bool Linklist<T>::insertNode(T newData) 
{
    ListNode<T> *q = head,*s;
    while(q->next != NULL)  
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
bool Linklist<T>::removeNode(ListNode<T> *q)               
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
bool Linklist<T>::removeNode(int i)               
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
    std::cout << "after removing the data of " << i <<", show the list:" << std::endl;
    showData();
    return true;
}

template <class T>
bool Linklist<T>::findNode(T _data)              
{
    ListNode<T> *q = head->next;   
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

    std::cout << "the data lies in " << i << "，and its address is" << q << std::endl;
    return true;
}

template <class T>
bool Linklist<T>::clearNode()   
{
    ListNode<T> *q = head->next;
    if(q != NULL)
    {
        q = q->next;
        delete q;
    }

    std::cout << "The linked list has been emptied." << std::endl;
    return true;
}

template <class T>
bool Linklist<T>::showData()    
{
    ListNode<T> *q = head;
    while(q->next != NULL)
    {
        q = q->next;
        cout << q->data << " ";
    }
    std::cout << std::endl;
    return true;
}

#endif // LINKLIST_H


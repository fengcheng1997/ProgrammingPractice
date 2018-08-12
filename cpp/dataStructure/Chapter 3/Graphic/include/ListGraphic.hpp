#ifndef ListGraph_H
#define ListGraph_H

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <class T> class ListGraph;

template <class T>
class ArcNode
{
private:
    int number; //vertex number
    ArcNode *nextArc;
    T data; //the data user want to store

public:
    ArcNode()
    {
        nextArc = NULL;
    }

    ArcNode(T _data)
    {
        data = _data;
        nextArc = NULL;
    }

    ~ArcNode(){}

    T getData() {return data;}
    ArcNode* getNextarc() {return nextArc;}

    friend class ListGraph<T>;

};

template <class T>
class ListGraph
{
private:
    vector<ArcNode<T>>  node; //'firstArc is the head of a edge and we can also use subscript to store the vertex number
    int n, e;

public:
    ListGraph()
    {
        n = 0;
        e = 0;
    }

    ~ListGraph(){}

    int getN(){return n;}
    int getE(){return e;}

    void createGraph(int _n);
    vector<ArcNode<T>>& getVector(){return node;}
    bool insertEdge(int num1, int num2);    //insert num1 into num2
    bool deleteEdge(int num1, int num2);
    void showALGraph(vector<ArcNode<T>>& node); //show the Adjacency List of the Graph


};

template <class T>
void ListGraph<T>::createGraph(int _n)
{
    ArcNode<T> _node[_n];
    n = _n;

    for(int i = 0; i < n; i++)
    {
        _node[i].number = i;
        node.push_back(_node[i]);
    }
}

template <class T>
bool ListGraph<T>::insertEdge(int num1, int num2)
{
    if(num1+1 > (int)node.size() || num2+1 > (int)node.size()) return false;

    ArcNode<T>* temp;
    temp = new ArcNode<T>();
    temp->number = num1;

    temp->nextArc = node[num2].nextArc;
    node[num2].nextArc = temp; //Head insert method

    e++;
    return true;
}

template <class T>
bool ListGraph<T>::deleteEdge(int num1, int num2)
{
    if(num1+1 > (int)node.size() || num2+1 > (int)node.size()) return false;

    ArcNode<T> *temp = node[num2].nextArc, *_temp = NULL;

    while(temp != NULL)
    {
        if(temp->number == num1)
        {
            if(temp == node[num2].nextArc)
            {
                node[num2].nextArc = temp->nextArc;
                delete temp;
                break;
            }

            _temp->nextArc = temp->nextArc;
            delete temp;
            break;
        }
        _temp = temp;
        temp = temp->nextArc;
    }

    _temp = NULL;
    e--;
    return true;
}

template <class T>
void ListGraph<T>::showALGraph(vector<ArcNode<T>>& node)
{
    ArcNode<T> *p = NULL;
    for(auto it = node.begin(); it != node.end(); ++it)
    {
        p = it->nextArc;
        cout << it->number << "  " ;
        while(p != NULL)
        {
            cout << p->number << " ";
            p = p->nextArc;
        }
        cout << endl;
    }
    p = NULL;
}

#endif // ListGraph_H

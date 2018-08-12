#ifndef MatrixGraph_H
#define MatrixGraph_H

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <class T> class  MatrixGraph;

template <class T>
class vertexType
{
private:
    int number;
    T data;

public:
    vertexType(){number = -1;}
    vertexType(int _number){number = _number;}
    ~vertexType(){}

    T getDdata(){return data;}

    friend class MatrixGraph<T>;
};

template <class T>
class MatrixGraph
{
private:
    int n, e;
    vector<vector<int>> edges;
    vector<vertexType<T>> vertex;

public:
    MatrixGraph()
     {
         n = 0;
         e = 0;
     }
    ~MatrixGraph(){}

    void createMGraph(int _n, vector<vector<int>> _edges);
    bool addEdge(int num1, int num2);
    bool deleteEdge(int num1, int num2);
    void showMGraph();
};

template <class T>
void MatrixGraph<T>::createMGraph(int _n, vector<vector<int>> _edges)
{
    n = _n;
    edges.resize(n);

   for(int i = 0; i < n; i++)
   {
       edges[i].resize(n);

        for(int j = 0; j < n; j++)
       {
           edges[i][j] = _edges[i][j];

           if(_edges[i][j] != 0)
            e++;
       }
   }
}

template <class T>
bool MatrixGraph<T>::addEdge(int num1, int num2)
{
    if(edges[num2][num1] == 0)
    {
        edges[num2][num1] = 1;
        return true;
    }
    else
    {
        cout << "This edge has existed.";
        return false;
    }
}

template <class T>
bool MatrixGraph<T>::deleteEdge(int num1, int num2)
{
     if(edges[num2][num1] == 1)
    {
        edges[num2][num1] = 0;
        return true;
    }
    else
    {
        cout << "This edge hasn't existed.";
        return false;
    }
}

template <class T>
void MatrixGraph<T>::showMGraph()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << edges[i][j] << " " ;
        }
        cout << endl;
    }
}

#endif // MatrixGraph_H

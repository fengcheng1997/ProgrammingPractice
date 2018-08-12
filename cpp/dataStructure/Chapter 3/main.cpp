#include <iostream>
#include "include/ListGraphic.hpp"
#include "include/MatrixGraph.hpp"

#include <vector>

using namespace std;

int main()
{
/*******  ListGraph    *******/
    ListGraph<int> listGraph;

    listGraph.createGraph(3);
    listGraph.insertEdge(0,1);
    listGraph.insertEdge(1,0);
    listGraph.insertEdge(1,2);
    listGraph.insertEdge(0,2);
    listGraph.insertEdge(2,1);

    cout << "the Adjacency List of the Graph:" << endl;
    listGraph.showALGraph(listGraph.getVector());

    cout << endl <<"delete some edge and the Adjacency List of the Graph became:" << endl;
    listGraph.deleteEdge(1,0);
    listGraph.deleteEdge(0,1);
    listGraph.showALGraph(listGraph.getVector());

    cout << "the number of vertex:" << listGraph.getN() << endl;
    cout << "the number of edge  :" << listGraph.getE() << endl;

/*******  MatrixGraph    ********/
    MatrixGraph<int> matrixGraph;

    int _edges[3][3] = {{0,1,0},{1,0,1},{1,1,0}};
    vector<vector<int>> edges;

    edges.resize(3);
   for(int i = 0; i < 3; i++)
   {
       edges[i].resize(3);
        for(int j = 0; j < 3; j++)
       {
           edges[i][j] = _edges[i][j];
       }
   }

    matrixGraph.createMGraph(3, edges);
    matrixGraph.deleteEdge(1,0);
    matrixGraph.addEdge(2,0);

    cout << endl <<"the Adjacency Matrix of the Graph:" << endl;
    matrixGraph.showMGraph();
    return 0;
}

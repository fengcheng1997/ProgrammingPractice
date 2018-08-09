#include <iostream>
#include "include/btNode.hpp"

using namespace std;

int main()
{
    BinaryTree<int> BinaryTree;

    BinaryTree.createBt();

    cout << "先序遍历:" << endl;
    BinaryTree.preOrder(BinaryTree.getRoot());
    cout << endl;   //写在oreOrder里面，在递归的过程中会换行很多次，所以在preOrder下写一个换行

    cout << "中序遍历:" << endl;
    BinaryTree.inOrder(BinaryTree.getRoot());
    cout << endl;

    cout << "后序遍历:" << endl;
    BinaryTree.postOrder(BinaryTree.getRoot());
    cout << endl;

    BinaryTree.layOrder();

    BinaryTree.insertNode(99);
    BinaryTree.layOrder();

    BinaryTree.parentNode();
    BinaryTree.sonNode();
    cout << endl;

    BinaryTree.changeNode(99,100);
    BinaryTree.layOrder();

    BinaryTree.getDepth();

    return 0;
}

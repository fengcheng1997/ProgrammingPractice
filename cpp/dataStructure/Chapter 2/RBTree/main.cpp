#include <iostream>
#include "include/RBTree.hpp"

using namespace std;

int main()
{
    RBTree<int> rbtree;


    rbtree.insertNode(3);
    rbtree.insertNode(5);
    rbtree.insertNode(1);
    rbtree.insertNode(2);
    rbtree.insertNode(8);
    rbtree.insertNode(10);
    rbtree.insertNode(-2);
    rbtree.insertNode(-4);
    rbtree.insertNode(-1);
    rbtree.insertNode(28);
    rbtree.insertNode(77);
    rbtree.insertNode(-10);

    rbtree.inOrder(rbtree.getRoot());

    int k = 0, temp = 0;
    rbtree.getDeepth(rbtree.getRoot(),temp,k);
    cout << '\n' << "the deepth of the RBTree: " << k << '\n'<< endl;

    rbtree.deleteNode(1000000);

    rbtree.deleteNode(-10);
    cout  << '\n' << "After the deletion, the inorder of RBTree is:" << endl;
    rbtree.inOrder(rbtree.getRoot());

    k = 0;
    temp = 0;
    rbtree.getDeepth(rbtree.getRoot(),temp,k);
    cout << '\n' << "the deepth of the RBTree: " << k << endl;


    return 0;
}

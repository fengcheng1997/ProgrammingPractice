#include <iostream>
#include "AVL.hpp"

using namespace std;

int main()
{
    AVL<int> avl;

    avl.insertNode(-11);
    avl.insertNode(-1);
    avl.insertNode(10);
    avl.insertNode(3);
    avl.insertNode(51);
    avl.insertNode(5);
    avl.insertNode(7);
    avl.insertNode(-13);
    avl.insertNode(9);
    avl.insertNode(-23);
    avl.insertNode(8);
    avl.insertNode(92);
    avl.insertNode(-63);


    for(int i = 0; i < 10; i++)
    {
        avl.insertNode(100*i);
    }

    //avl.preOrder();
    avl.inOrder();
    cout << '\n' << "the deepth of the AVLTree is " << avl.setH(avl.getRoot()) << endl;

    avl.deleteNode(3);
    avl.deleteNode(8);
    avl.deleteNode(7);

    cout << '\n' << "After the deletion :" << endl;
    //avl.preOrder();
    avl.inOrder();


    cout << '\n' << "the deepth of the AVLTree is " << avl.setH(avl.getRoot()) << endl;

    return 0;
}

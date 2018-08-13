#include <iostream>
#include "include/btNode.hpp"

using namespace std;

int main()
{
    BinaryTree<int> BinaryTree;

    BinaryTree.createBt();

    cout << "Preorder traversal:" << endl;
    BinaryTree.preOrder(BinaryTree.getRoot());
    cout << endl;

    cout << "Inorder traversal:" << endl;
    BinaryTree.inOrder(BinaryTree.getRoot());
    cout << endl;

    cout << "Postorder traversal:" << endl;
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

    cout << "The structure of the binarytree:" << endl;
    BinaryTree.display(BinaryTree.getRoot());

    return 0;
}

#include <iostream>
using namespace std;

/*
A refresher of preorder transveral of a tree. Starting from the root, the left branch is outputed until a leaf is reached.
At this stage transversal is backtracked and the first right branch becomes the new root the new root.
*/

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};



void preOrder(Node *root) {

    if(root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

int main()
{
    Node n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
    n1.right = &n2;
    n2.right = &n5;
    n5.right = &n6;
    n5.left = &n3;
    n3.right = &n4;

    preOrder(&n1);


    return 0;
}

/*
     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  

Answer: 1 2 5 3 4 6 
*/



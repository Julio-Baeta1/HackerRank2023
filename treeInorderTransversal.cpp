#include <iostream>
using namespace std;

/*
A refresher of inorder transveral of a tree. A node is only printed if it is the current leftmost node that has not been printed yet in
its branch. This will output the tree in numerical order. 
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



void inOrder(Node *root) {

    if(root == NULL)
        return;
    
    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);

}

int main()
{
    Node n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
    n1.right = &n2;
    n2.right = &n5;
    n5.right = &n6;
    n5.left = &n3;
    n3.right = &n4;

    inOrder(&n1);


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
Sample Output

1 2 3 4 5 6 
*/
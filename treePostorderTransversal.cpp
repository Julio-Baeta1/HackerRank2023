#include <iostream>
using namespace std;

/*
A refresher of postorder transveral of a tree. The node's data is only outputed when it is a leaf or all the nodes below it have been
printed. Thus we swap the order of printing and transversal from preorder transversal and hence the post.
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



void postOrder(Node *root) {

    if(root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";

}

int main()
{
    Node n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
    n1.right = &n2;
    n2.right = &n5;
    n5.right = &n6;
    n5.left = &n3;
    n3.right = &n4;

    postOrder(&n1);


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

4 3 6 5 2 1 
*/
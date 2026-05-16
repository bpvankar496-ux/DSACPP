//transform the sum of tree branch
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int transform(Node* root) {
    if (root == NULL) return 0;

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if (root->left != NULL)
        root->data += root->left->data;

    if (root->right != NULL)
        root->data += root->right->data;  

    return currOld;
}

// Inorder print
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    transform(root);

    cout << "Inorder after transform: ";
    inorder(root);

    return 0;
}

//ANS:=
//Inorder after transform: 0 9 0 20 6 0 
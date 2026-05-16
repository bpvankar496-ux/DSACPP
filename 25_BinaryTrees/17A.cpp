//Q2: Invert Binary Tree
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

Node* invertTree(Node* root) {
    if (!root) return NULL;

    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root = invertTree(root);

    inorder(root);
}

//ANS:=
//3 1 2 
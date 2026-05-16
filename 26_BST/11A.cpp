//Question 1: Range Sum in BST 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int rangeSumBST(Node* root, int low, int high) {
    if (!root) return 0;

    if (root->data >= low && root->data <= high)
        return root->data +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);

    if (root->data < low)
        return rangeSumBST(root->right, low, high);

    return rangeSumBST(root->left, low, high);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << rangeSumBST(root, 5, 15);
}

//ANS:=
//37
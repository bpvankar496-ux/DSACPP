//delete node in BST
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

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return NULL;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // case 1: leaf node → delete
        // case 2: one child → return that child
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        if (!root->left || !root->right) {
            return root->left ? root->left : root->right;
        }

        // case 3: two children → use inorder successor
        Node* IS = root->right;
        while (IS->left) IS = IS->left;

        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr, 9);

    root = deleteNode(root, 5);

    inorder(root);

    return 0;
}

//ANS:=
//1 3 4 6 8 10 11 14 
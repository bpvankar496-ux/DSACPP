//Q1: Univalued Binary Tree
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

bool isUnival(Node* root) {
    if (!root) return true;

    if (root->left && root->data != root->left->data) return false;
    if (root->right && root->data != root->right->data) return false;

    return isUnival(root->left) && isUnival(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(1);

    cout << isUnival(root) << endl; // 1 = true
}

//ANS:=
//1
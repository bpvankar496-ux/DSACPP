//Question 3: Kth Smallest 
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

void inorder(Node* root, int& k, int& ans) {
    if (!root) return;

    inorder(root->left, k, ans);

    k--;
    if (k == 0) {
        ans = root->data;
        return;
    }

    inorder(root->right, k, ans);
}

int kthSmallest(Node* root, int k) {
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    cout << kthSmallest(root, 2);
}

//ANS:=
//5
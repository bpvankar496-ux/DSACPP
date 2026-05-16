//merge 2 BST
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

// Inorder traversal
void getInorder(Node* root, vector<int>& arr) {
    if (!root) return;
    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
}

// Sorted array → BST
Node* BSTfromSortedVec(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = BSTfromSortedVec(arr, start, mid - 1);
    root->right = BSTfromSortedVec(arr, mid + 1, end);

    return root;
}

// Merge 2 BST
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1, nodes2, merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;

    // merge 2 sorted arrays
    while (i < nodes1.size() && j < nodes2.size()) {
        if (nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }

    while (i < nodes1.size()) merged.push_back(nodes1[i++]);
    while (j < nodes2.size()) merged.push_back(nodes2[j++]);

    // build balanced BST
    return BSTfromSortedVec(merged, 0, merged.size() - 1);
}

// Preorder print
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1, root2);

    preorder(root);
}

//ANS:=
//3 1 2 9 4 12 
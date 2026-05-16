//normal BST convert in balnced BST
#include <iostream>
#include <vector>
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

// Step 1: Store inorder (sorted)
void getInorder(Node* root, vector<int>& nodes) {
    if (root == NULL) return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

// Step 2: Build balanced BST
Node* BSTfromSortedVec(vector<int>& nodes, int st, int end) {
    if (st > end) return NULL;

    int mid = st + (end - st) / 2;

    Node* root = new Node(nodes[mid]);

    root->left = BSTfromSortedVec(nodes, st, mid - 1);
    root->right = BSTfromSortedVec(nodes, mid + 1, end);

    return root;
}

// Main conversion function
Node* balanceBST(Node* root) {
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, nodes.size() - 1);
}

// Preorder (to see structure)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Driver
int main() {
    // Skewed BST
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    // Balance it
    root = balanceBST(root);

    // Print
    preorder(root);
    cout << endl;

    return 0;
}

//ANS:=
// After insertion:
// 101 -> rahul
// 110 -> neha
// 131 -> amit

// Size of map: 3

// Value at key 110: neha

// Finding key 101:
// Key 101 found, value = rahul

// Deleting key 110...
// After deletion:
// 101 -> rahul
// 131 -> amit

// Check key 131 exists or not:
// Yes exists

// Is map empty? No

// Clearing map...
// Size after clear: 0

//ANS:=
//6 4 3 5 8 7 9 
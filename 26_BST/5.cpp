//leaf path in BST
#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Build BST from array
Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Print path
void printPath(vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

// Helper function
void pathHelper(Node* root, vector<int>& path) {
    if (root == NULL) {
        return;
    }

    path.push_back(root->data);

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    // Backtracking
    path.pop_back();
}

// Main function to print all root-to-leaf paths
void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

// Driver code
int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr, 9);

    rootToLeafPath(root);

    return 0;
}

//ANS:=
// 8 5 3 1 
// 8 5 3 4 
// 8 5 6 
// 8 10 11 14 
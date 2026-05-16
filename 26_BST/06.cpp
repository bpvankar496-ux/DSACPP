//valid or not BST
#include <iostream>
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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Build BST
Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Helper function
bool validateHelper(Node* root, Node* min, Node* max) {
    if (root == NULL) return true;

    if (min != NULL && root->data <= min->data) return false;
    if (max != NULL && root->data >= max->data) return false;

    return validateHelper(root->left, min, root) &&
           validateHelper(root->right, root, max);
}

// Main validator
bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

// Driver
int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr, 9);

    if (validateBST(root))
        cout << "Valid BST\n";
    else
        cout << "Invalid BST\n";

    return 0;
}

//ANS:=
//Valid BST
//sort arr balance BST or not
#include <iostream>
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

// Build Balanced BST from sorted array
Node* buildBSTfromSorted(int arr[], int st, int end) {
    if (st > end) return NULL;

    int mid = st + (end - st) / 2;

    Node* root = new Node(arr[mid]);

    root->left = buildBSTfromSorted(arr, st, mid - 1);
    root->right = buildBSTfromSorted(arr, mid + 1, end);

    return root;
}

// Inorder traversal (to verify BST)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // sorted array
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBSTfromSorted(arr, 0, n - 1);

    cout << "Inorder: ";
    inorder(root);  // should print sorted order

    return 0;
}

//ANS:=
//Inorder: 1 2 3 4 5 6 7 
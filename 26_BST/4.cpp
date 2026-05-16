//print range in BST
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

void printInRange(Node* root, int start, int end) {
    if (!root) return;

    // case 1: in range → LNR
    if (start <= root->data && root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }
    // case 2: smaller → go right
    else if (root->data < start) {
        printInRange(root->right, start, end);
    }
    // case 3: bigger → go left
    else {
        printInRange(root->left, start, end);
    }
}

int main() {
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr, 9);

    printInRange(root, 5, 11);

    return 0;
}

//ANS:=
//5 6 8 10 11 
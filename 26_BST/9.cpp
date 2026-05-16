//largest BST in BT
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

struct Info {
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

int maxSize = 0;

Info* largestBST(Node* root) {
    // Base case
    if (root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->size + rightInfo->size + 1;

    if (leftInfo->isBST && rightInfo->isBST &&
        root->data > leftInfo->max &&
        root->data < rightInfo->min) {

        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}

int main() {
    /*
            50
           /  \
         30    60
        / \    / \
      5   20  45  70
                    / \
                  65  80
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);

    cout << "Largest BST size: " << maxSize;

    return 0;
}

//ANS:=
//Largest BST size: 5
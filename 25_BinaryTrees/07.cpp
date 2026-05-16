//subroot same ch k nai e check karvu  same hoi to 1 nai to 0
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

// Build Tree
int idx = -1;
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

// Check if identical
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    if (root1->data != root2->data) return false;

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Check subtree
bool isSubtree(Node* root, Node* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL || subRoot == NULL) return false;

    if (root->data == subRoot->data) {
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    bool isLeft = isSubtree(root->left, subRoot);
    if (isLeft) return true;

    return isSubtree(root->right, subRoot);


}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubtree(root, subRoot) << endl; // Output: 1 (true)

    return 0;
}

//ANS:=
//1
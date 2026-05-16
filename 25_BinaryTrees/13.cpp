//distence betweeen two nodes
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

// LCA (optimized)
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left && right) return root;

    return (left != NULL) ? left : right;
}

// Distance from node
int dist(Node* root, int n) {
    if (root == NULL) return -1;

    if (root->data == n) return 0;

    int leftDist = dist(root->left, n);
    if (leftDist != -1) return leftDist + 1;

    int rightDist = dist(root->right, n);
    if (rightDist != -1) return rightDist + 1;

    return -1;
}

// Min distance
int minDist(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);

    int d1 = dist(lca, n1);
    int d2 = dist(lca, n2);

    return d1 + d2;
}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 6;

    cout << "Distance: " << minDist(root, n1, n2) << endl;

    return 0;
}

//ANS:=
//Distance: 4
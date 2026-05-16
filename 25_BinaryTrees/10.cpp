//kth level print num
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

// Helper
void KthHelper(Node* root, int K, int currLevel) {
    if (root == NULL) return;

    if (currLevel == K) {
        cout << root->data << " ";
        return;
    }

    KthHelper(root->left, K, currLevel + 1);
    KthHelper(root->right, K, currLevel + 1);
}

// Main function
void KthLevel(Node* root, int K) {
    KthHelper(root, K, 1);
    cout << endl;
}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    int K = 3;
    cout << "Nodes at level " << K << ": ";
    KthLevel(root, K);

    return 0;
}

//ANS:=
//Nodes at level 3: 4 5 6 
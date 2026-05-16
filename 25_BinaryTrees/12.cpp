//O(n)
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

// Build Tree (preorder with -1 as NULL)
int idx = -1;
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

//  Optimized LCA
Node* LCA_fast(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA_fast(root->left, n1, n2);
    Node* rightLCA = LCA_fast(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 5;

    Node* lca = LCA_fast(root, n1, n2);

    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found\n";

    return 0;
}

//ANS:=
//LCA of 4 and 5 is: 2
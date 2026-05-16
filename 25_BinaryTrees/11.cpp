//lowest common  ancestor
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

// Root to node path
bool getPath(Node* root, int n, vector<Node*>& path) {
    if (root == NULL) return false;

    path.push_back(root);

    if (root->data == n) return true;

    if (getPath(root->left, n, path) || 
        getPath(root->right, n, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

// LCA
Node* LCA(Node* root, int n1, int n2) {
    vector<Node*> path1, path2;

    getPath(root, n1, path1);
    getPath(root, n2, path2);

    int i = 0;
    for (; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) break;
    }

    return path1[i - 1];
}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 5;

    Node* lca = LCA(root, n1, n2);

    cout << "LCA: " << lca->data << endl;

    return 0;
}

//ANS:=
//LCA: 2
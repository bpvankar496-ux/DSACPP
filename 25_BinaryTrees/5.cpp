//dimeter of tree==> biggest chain O(n^2)
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

// Height
int height(Node* root) {
    if (root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

// Diameter (O(n^2))
int diameter(Node* root) {
    if (root == NULL) return 0;

    int currDiam = height(root->left) + height(root->right) + 1;

    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << "Diameter (O(n^2)): " << diameter(root) << endl;

    return 0;
}

//ANS:=
//Diameter (O(n^2)): 5
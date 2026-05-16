//dimeter of tree==> biggest chain O(n)
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

// Pair: height + diameter
pair<int, int> diameterFast(Node* root) {
    if (root == NULL) return {0, 0};

    auto left = diameterFast(root->left);
    auto right = diameterFast(root->right);

    int height = max(left.first, right.first) + 1;

    int currDiam = left.first + right.first + 1;
    int maxDiam = max(currDiam, max(left.second, right.second));

    return {height, maxDiam};
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << "Diameter (O(n)): " << diameterFast(root).second << endl;

    return 0;
}

//ANS:=
//Diameter (O(n)): 5
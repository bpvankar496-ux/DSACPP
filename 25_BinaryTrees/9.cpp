//top view on binary tree
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

// Top View
void topView(Node* root) {
    if (root == NULL) return;

    queue<pair<Node*, int>> q;   // node, horizontal distance
    map<int, int> m;             // hd -> node data

    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int hd = curr.second;

        // store first node at each hd
        if (m.count(hd) == 0) {
            m[hd] = currNode->data;
        }

        if (currNode->left != NULL) {
            q.push({currNode->left, hd - 1});
        }

        if (currNode->right != NULL) {
            q.push({currNode->right, hd + 1});  // ✅ fixed
        }
    }

    // print result (sorted by hd)
    cout << "Top View: ";
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

// Main
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    topView(root);

    return 0;
}

//ANS:=
//Top View: 4 2 1 3 6 
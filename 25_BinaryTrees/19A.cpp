//Q4: Find Duplicate Subtree
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

string solve(Node* root, unordered_map<string,int>& mp, vector<Node*>& ans) {
    if (!root) return "#";

    string s = to_string(root->data) + "," +
               solve(root->left, mp, ans) + "," +
               solve(root->right, mp, ans);

    mp[s]++;

    if (mp[s] == 2) ans.push_back(root);

    return s;
}

vector<Node*> findDuplicateSubtrees(Node* root) {
    unordered_map<string,int> mp;
    vector<Node*> ans;
    solve(root, mp, ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->left = new Node(4);

    vector<Node*> res = findDuplicateSubtrees(root);

    for (auto n : res)
        cout << n->data << " ";
}

//ANS:=
//4 2
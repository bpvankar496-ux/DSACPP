//Question 1 : Bottom View of Binary Tree
#include <iostream>
#include <queue>
#include <map>
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

void bottomView(Node* root) {

    if(root == NULL) return;

    map<int,int> mp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()) {

        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        // overwrite for bottom view
        mp[hd] = node->data;

        if(node->left) {
            q.push({node->left, hd-1});
        }

        if(node->right) {
            q.push({node->right, hd+1});
        }
    }

    for(auto p : mp) {
        cout << p.second << " ";
    }
}

int main() {

    Node* root = new Node(20);

    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right->right = new Node(25);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    bottomView(root);

    return 0;
}

//ANS:=
//5 10 3 14 25 
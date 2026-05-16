//Q5: Maximum Path Sum
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

int maxPath = INT_MIN;

int helper(Node* root) {
    if (!root) return 0;

    int left = max(0, helper(root->left));
    int right = max(0, helper(root->right));

    maxPath = max(maxPath, left + right + root->data);

    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    helper(root);
    return maxPath;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << maxPathSum(root);
}

//ANS:=
//6
//kth ansestor
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

int KthAncestor(Node* root, int node, int K) {
    if (root == NULL) return -1;

    if (root->data == node) return 0;

    int leftDist = KthAncestor(root->left, node, K);
    int rightDist = KthAncestor(root->right, node, K); // ✅ FIX

    if (leftDist == -1 && rightDist == -1) return -1;

    int valid = (leftDist != -1) ? leftDist : rightDist;

    if (valid + 1 == K) {
        cout << "Kth Ancestor: " << root->data << endl;
    }

    return valid + 1;
}

// Demo
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int node = 5;
    int K = 2;

    KthAncestor(root, node, K);

    return 0;
}

//ANS:=
//Kth Ancestor: 1
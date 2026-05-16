//Question 4: Two BST Sum = Target
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool twoSumBST(Node* root1, Node* root2, int target) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);

    int i = 0, j = b.size() - 1;

    while (i < a.size() && j >= 0) {
        int sum = a[i] + b[j];

        if (sum == target) return true;
        else if (sum < target) i++;
        else j--;
    }

    return false;
}

int main() {
    Node* root1 = new Node(5);
    root1->left = new Node(3);

    Node* root2 = new Node(10);
    root2->left = new Node(6);

    cout << (twoSumBST(root1, root2, 16) ? "Yes" : "No");
}

//ANS:=
//No
//Question 2: Closest Value to K
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

int closestValue(Node* root, int k) {
    int ans = -1, minDiff = INT_MAX;

    while (root) {
        int diff = abs(root->data - k);

        if (diff < minDiff) {
            minDiff = diff;
            ans = root->data;
        }

        if (k < root->data) root = root->left;
        else root = root->right;
    }

    return ans;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);

    cout << closestValue(root, 19);
}

//ANS:=
//11
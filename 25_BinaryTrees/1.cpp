//tree chart

// Preorder Traversal = Root → Left → Right
// Inorder Traversal = Left → Root → Right
// Postorder Traversal = Left → Right → Root

#include <iostream>
#include <vector>
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

static int idx = -1;

// Build tree (preorder with -1 as NULL)
Node* buildTree(vector<int> &nodes) {
    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);   // left
    currNode->right = buildTree(nodes);  // right

    return currNode;
}

//  Preorder print
void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//  Inorder print
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//  Postorder print
void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}

//ANS:=
// Preorder: 1 2 4 5 3 6 
// Inorder: 4 2 5 1 3 6 
// Postorder: 4 5 2 6 3 1 
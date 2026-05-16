//Question 5: Maximum Sum BST 
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

struct Info {
    int minVal, maxVal, sum;
    bool isBST;

    Info(int minVal, int maxVal, int sum, bool isBST) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
        this->isBST = isBST;
    }
};

int maxSum = 0;

Info solve(Node* root) {
    if (!root)
        return Info(INT_MAX, INT_MIN, 0, true);

    Info left = solve(root->left);
    Info right = solve(root->right);

    if (left.isBST && right.isBST &&
        root->data > left.maxVal &&
        root->data < right.minVal) {

        int currSum = left.sum + right.sum + root->data;
        maxSum = max(maxSum, currSum);

        return Info(
            min(root->data, left.minVal),
            max(root->data, right.maxVal),
            currSum,
            true
        );
    }

    return Info(INT_MIN, INT_MAX, 0, false);
}

int maxSumBST(Node* root) {
    maxSum = 0;
    solve(root);
    return maxSum;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    cout << maxSumBST(root);
}




// ## Self Balancing Binary Search Trees
// Self Balancing BST evi binary search trees che je insertion ane deletion operations pachi potani height ne minimum rakhva mate automatic balance maintain kare che. Aa thi tree skew nathi thati ane badha operations jeva ke searching, insertion ane deletion ni time complexity O(log n) rahe che.

// Self-balancing BST na mukhya be prakar che:

// ### 1. AVL Tree
// AVL Tree ma darek node mate balance factor calculate thay che, je left subtree ni height minus right subtree ni height hoy che. Aa balance factor ni value -1, 0 athva +1 hovi joiye. Jo aa range thi bahar jai to tree imbalance thai gayu manay ane tene balance karva mate rotations kariye che.
// Rotations na prakar:
// * LL (Left Left)
// * RR (Right Right)
// * LR (Left Right)
// * RL (Right Left)
// AVL Tree strict balancing follow kare che, etle searching fast hoy che pan insertion ane deletion ma vadhu rotations lage che.

// ### 2. Red-Black Tree
// Red-Black Tree ma darek node ne ek color assign karelo hoy che (Red athva Black). Aa tree niche na rules follow kare che:
// * Root node hamesha black hoy che
// * Red node na children black hoy che
// * Be red nodes continuous nathi hova joiye
// * Dareka path ma same number of black nodes hoy che
// Tree balance maintain karva mate recoloring ane rotations use thay che. Aa tree AVL karta ochhu strict balance rakhe che, etle insertion ane deletion fast hoy che.
// ### Difference between AVL and Red-Black Tree
// AVL Tree strictly balanced hoy che, jyare Red-Black Tree loosely balanced hoy che. AVL ma searching faster hoy che, pan Red-Black Tree ma insertion ane deletion operations vadhu efficient hoy che.

// ### Conclusion

// Self-balancing BSTs tree ni height control kari ne badha operations ne efficient banave che ane real-world applications ma widely use thay che.

//ANS:=
//16
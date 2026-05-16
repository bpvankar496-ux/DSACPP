// Question 5: Merge K Sorted Lists
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* merge(Node* l1, Node* l2) {
    Node* merged = new Node(-1);
    Node* mCurr = merged;
    Node* mC1 = l1;
    Node* mC2 = l2;

    while (mC1 != NULL && mC2 != NULL) {
        if (mC1->data <= mC2->data) {
            mCurr->next = mC1;
            mC1 = mC1->next;
        } else {
            mCurr->next = mC2;
            mC2 = mC2->next;
        }
        mCurr = mCurr->next;
    }

    if (mC1 != NULL) {
        mCurr->next = mC1;
    }
    if (mC2 != NULL) {
        mCurr->next = mC2;
    }

    return merged->next;
}

Node* mergeKLists(vector<Node*> lists) {
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists[0];

    Node* head = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        head = merge(head, lists[i]);
    }
    return head;
}

int main() {
    // l1 = 1->3
    Node* l1 = new Node(1);
    l1->next = new Node(3);

    // l2 = 6->8
    Node* l2 = new Node(6);
    l2->next = new Node(8);

    // l3 = 9->10
    Node* l3 = new Node(9);
    l3->next = new Node(10);

    vector<Node*> lists = {l1, l2, l3};

    Node* result = mergeKLists(lists);
    printList(result);
    // 1->3->6->8->9->10->NULL

    return 0;
}

//ANS:=
//1 -> 3 -> 6 -> 8 -> 9 -> 10 -> NULL
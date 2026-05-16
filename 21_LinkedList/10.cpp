// Topic 2: Zig Zag LL (Alternate Merging)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

struct List {
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void alternateMerge(Node* left, Node* right) {
    while (left != NULL && right != NULL) {
        Node* leftNext = left->next;
        Node* rightNext = right->next;

        left->next = right;
        right->next = leftNext;

        left = leftNext;
        right = rightNext;
    }
}

int main() {
    List ll1;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);

    List ll2;
    ll2.push_back(4);
    ll2.push_back(5);
    ll2.push_back(6);

    printList(ll1.head);
    // 1->2->3->NULL
    printList(ll2.head);
    // 4->5->6->NULL

    alternateMerge(ll1.head, ll2.head);
    printList(ll1.head);
    // 1->4->2->5->3->6->NULL

    return 0;
}

// ANS:=
// 1 -> 2 -> 3 -> NULL
// 4 -> 5 -> 6 -> NULL
// 1 -> 4 -> 2 -> 5 -> 3 -> 6 -> NULL
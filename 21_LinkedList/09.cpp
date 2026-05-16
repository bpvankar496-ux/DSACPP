// Topic 1: Zig Zag Linked List
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

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void zigZag(Node* head) {
    // Step 1: get mid
    Node* mid = getMid(head);

    // Step 2: reverse 2nd half
    Node* curr = mid->next;
    mid->next = NULL;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Node* right = prev;

    // Step 3: alternate merge
    Node* left = head;
    while (right != NULL) {
        Node* leftNext = left->next;
        Node* rightNext = right->next;

        left->next = right;
        right->next = leftNext;

        left = leftNext;
        right = rightNext;
    }
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    printList(ll.head);
    // 1->2->3->4->5->NULL

    zigZag(ll.head);
    printList(ll.head);
    // 1->5->2->4->3->NULL

    return 0;
}

// ANS:=
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// 1 -> 5 -> 2 -> 4 -> 3 -> NULL
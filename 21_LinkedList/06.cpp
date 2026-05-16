// Topic 1: Split at Mid
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

int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(3);
    ll.push_back(8);
    ll.push_back(1);
    ll.push_back(2);

    printList(ll.head);
    // 5->3->8->1->2->NULL

    Node* mid = getMid(ll.head);
    cout << "Mid = " << mid->data << endl;
    // Mid = 8

    return 0;
}
// ANS:=
// 5 -> 3 -> 8 -> 1 -> 2 -> NULL
// Mid = 8
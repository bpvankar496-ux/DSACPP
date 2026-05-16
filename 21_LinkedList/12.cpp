// Topic 4: Doubly Linked List (Pop Front)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

struct List {
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3->NULL

    printList(ll.head);

    ll.pop_front();
    printList(ll.head);
    // 2->3->NULL

    ll.pop_front();
    printList(ll.head);
    // 3->NULL

    return 0;
}

// ANS:=
// 1 -> 2 -> 3 -> NULL
// 2 -> 3 -> NULL
// 3 -> NULL
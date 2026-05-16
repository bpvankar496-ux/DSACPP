//detect cycle
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    // push front
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // pop front
    void pop_front() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
};

// cycle check function (Floyd's Algorithm)
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // +1 step
        fast = fast->next->next;    // +2 step

        if (slow == fast) {
            cout << "cycle exists\n";
            return true;
        }
    }

    cout << "cycle doesn't exist\n";
    return false;
}

int main() {
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // list: 1 -> 2 -> 3 -> 4

    // cycle create
    ll.tail->next = ll.head;

    isCycle(ll.head);

    return 0;
}

// ANS:=
// cycle exists
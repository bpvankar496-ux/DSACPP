// Topic 2: Merge 2 Sorted Lists
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

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

int main() {
    List ll1;
    ll1.push_back(1);
    ll1.push_back(3);
    ll1.push_back(5);

    List ll2;
    ll2.push_back(2);
    ll2.push_back(4);
    ll2.push_back(6);

    printList(ll1.head);
    // 1->3->5->NULL
    printList(ll2.head);
    // 2->4->6->NULL

    Node* result = merge(ll1.head, ll2.head);
    printList(result);
    // 1->2->3->4->5->6->NULL

    return 0;
}
// ANS:=
// 1 -> 3 -> 5 -> NULL
// 2 -> 4 -> 6 -> NULL
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
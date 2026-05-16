// Question 1: Intersection of Two Linked Lists
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

int getSize(Node* head) {
    int size = 0;
    while (head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getSize(headA);
    int lenB = getSize(headB);
    Node* c1 = headA;
    Node* c2 = headB;
    int diff = 0;

    if (lenA > lenB) {
        diff = lenA - lenB;
        for (int i = 0; i < diff; i++) {
            c1 = c1->next;
        }
    } else {
        diff = lenB - lenA;
        for (int i = 0; i < diff; i++) {
            c2 = c2->next;
        }
    }

    while (c1 != NULL && c2 != NULL && c1 != c2) {
        c1 = c1->next;
        c2 = c2->next;
    }

    if (c1 == NULL) {
        return NULL;
    } else {
        return c1;
    }
}

int main() {
    // Common nodes: 3->6->7
    Node* common = new Node(3);
    common->next = new Node(6);
    common->next->next = new Node(7);

    // List 1: 4->5->3->6->7
    Node* head1 = new Node(4);
    head1->next = new Node(5);
    head1->next->next = common;

    // List 2: 1->2->3->6->7
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = common;

    Node* result = getIntersectionNode(head1, head2);
    if (result != NULL)
        cout << "Intersection at: " << result->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

//ANS:=
//Intersection at: 3

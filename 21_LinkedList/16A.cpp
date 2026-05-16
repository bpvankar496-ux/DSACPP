// Question 4: Odd Even Linked List
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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* oddEvenList(Node* head) {
    if (head == NULL || head->next == NULL ||
        head->next->next == NULL) {
        return head;
    }

    Node* evenStart = head->next;
    Node* odd = head;
    Node* even = evenStart;

    while (odd->next != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    return head;
}

int main() {
    // 8->12->10->5->4->1->6->NULL
    Node* head = new Node(8);
    head->next = new Node(12);
    head->next->next = new Node(10);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(6);

    printList(head);
    head = oddEvenList(head);
    printList(head);
    // 8->12->10->4->6->5->1->NULL

    return 0;
}

// ANS:=
// 8 -> 12 -> 10 -> 5 -> 4 -> 1 -> 6 -> NULL
// 8 -> 10 -> 4 -> 6 -> 12 -> 5 -> 1 -> NULL
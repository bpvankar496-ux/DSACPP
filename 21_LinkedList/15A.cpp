// Question 3: Swapping Nodes in a Linked List
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

int getSize(Node* head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

Node* NthFromEnd(Node* head, int N) {
    int len = getSize(head);
    Node* curr = head;
    for (int i = 0; i < len - N; i++) {
        curr = curr->next;
    }
    return curr;
}

Node* swapNodes(Node* head, int x, int y) {
    Node* left = NULL;
    Node* right = NULL;

    for (int i = 0; i < x-1; i++) {
        left = left == NULL ? head : left->next;
    }

    Node* signLeft = NthFromEnd(head, x);
    Node* signRight = NthFromEnd(head, y);

    int temp = signLeft->data;
    signLeft->data = signRight->data;
    signRight->data = temp;

    return head;
}

int main() {
    // 1->2->3->4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printList(head);
    head = swapNodes(head, 2, 4);
    printList(head);
    // 1->4->3->2

    return 0;
}

// ANS:=
// 1 -> 2 -> 3 -> 4 -> NULL
// 3 -> 2 -> 1 -> 4 -> NULL
// Question 2: Delete N Nodes After M Nodes
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

Node* deleteNAfterM(Node* head, int m, int n) {
    Node* prev = head;
    while (prev) {
        // M nodes rakho
        for (int i = 1; i < m && prev != NULL; i++) {
            prev = prev->next;
        }

        if (prev) return head;

        // N nodes delete karo
        Node* curr = prev->next;
        for (int i = 0; i < n && curr != NULL; i++) {
            curr = curr->next;
        }

        prev->next = curr;
        prev = curr;
    }
    return head;
}

int main() {
    // 1->2->3->4->5->6->7->8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    printList(head);
    head = deleteNAfterM(head, 2, 2);
    printList(head);
    // 1->2->5->6->NULL

    return 0;
}

// ANS:=
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
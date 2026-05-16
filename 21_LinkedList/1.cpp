// Create LL → Node banavi ne chain banavvu
// Push Front → starting ma node add
// Push Back → end ma node add
// Print LL → badha node print
// Insert Middle → vachche position par add
// Delete → value delete
// Pop Front → first node remove
// Pop Back → last node remove
// Search → value find karvi
// Reverse → list ulati karvi

#include <iostream>
#include <vector>
using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

struct Node {
    int data;
    Node* next;

    ~Node() {
        cout << "Deleted: " << data << endl;
    }
};

// Print
void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Push Front
void pushFront(Node*& head, int val) {
    Node* temp = new Node{val, head};
    head = temp;
}

// Push Back
void pushBack(Node*& head, int val) {
    Node* temp = new Node{val, NULL};

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

// Insert Middle
void insertMiddle(Node*& head, int pos, int val) {
    Node* curr = head;
    for(int i = 0; i < pos-1; i++) {
        curr = curr->next;
    }

    Node* temp = new Node{val, curr->next};
    curr->next = temp;
}

// Delete List
void deleteList(Node*& head) {
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Pop Front
void popFront(Node*& head) {
    if(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Pop Back
void popBack(Node*& head) {
    if(head == NULL || head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = NULL;
}

// Iterative Search
bool search(Node* head, int key) {
    while(head != NULL) {
        if(head->data == key) return true;
        head = head->next;
    }
    return false;
}

// Recursive Search
bool searchRec(Node* head, int key) {
    if(head == NULL) return false;
    if(head->data == key) return true;
    return searchRec(head->next, key);
}

// Reverse
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Remove Nth from End
Node* removeNth(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    //if(fast == NULL) return head->next;
    if(fast == NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    //slow->next = slow->next->next;
    Node* temp = slow->next;
slow->next = slow->next->next;
delete temp;

    return head;
}

int main() {
    Node* head = NULL;

    cout << "Push Back:\n";
    pushBack(head, 1);
    pushBack(head, 2);
    pushBack(head, 3);
    print(head);

    cout << "Push Front:\n";
    pushFront(head, 0);
    print(head);

    cout << "Insert Middle (pos=2):\n";
    insertMiddle(head, 2, 9);
    print(head);

    cout << "Pop Front:\n";
    popFront(head);
    print(head);

    cout << "Pop Back:\n";
    popBack(head);
    print(head);

    cout << "Search 9: ";
    cout << (search(head, 9) ? "Found\n" : "Not Found\n");

    cout << "Recursive Search 3: ";
    cout << (searchRec(head, 3) ? "Found\n" : "Not Found\n");

    cout << "Reverse:\n";
    head = reverse(head);
    print(head);

    cout << "Remove 2nd from end:\n";
    head = removeNth(head, 2);
    print(head);

    cout << "Delete Full List:\n";
    deleteList(head);
    print(head);

    return 0;
}

// ANS:=
// Push Back:
// 1 -> 2 -> 3 -> NULL
// Push Front:
// 0 -> 1 -> 2 -> 3 -> NULL
// Insert Middle (pos=2):
// 0 -> 1 -> 9 -> 2 -> 3 -> NULL
// Pop Front:
// Deleted: 0
// 1 -> 9 -> 2 -> 3 -> NULL
// Pop Back:
// Deleted: 3
// 1 -> 9 -> 2 -> NULL
// Search 9: Found
// Recursive Search 3: Not Found
// Reverse:
// 2 -> 9 -> 1 -> NULL
// Remove 2nd from end:
// Deleted: 9
// 2 -> 1 -> NULL
// Delete Full List:
// Deleted: 2
// Deleted: 1
// NULL

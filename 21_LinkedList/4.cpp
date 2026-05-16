//Removing Cycle in a Linked List
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

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
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

void removeCycle(Node* head) {
    // Step 1: detect cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "cycle exists\n";
            isCycle = true;
            break;
        }
    }

    // cycle nahi to return
    if (!isCycle) {
        cout << "cycle doesn't exist\n";
        return;
    }

    // Step 2: remove cycle
    slow = head;

    if (slow == fast) {
        // special case: tail -> head
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL; // remove cycle
    } else {
        // general case
        Node* prev = fast;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // remove cycle
    }
}

int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3->4->1
    ll.tail->next = ll.head;

    removeCycle(ll.head);
    printList(ll.head);
}

// Removing Cycle in LL - Math Proof
// ==================================
// slow dist = x + a*d + y
// (x chale, cycle ma a vaar ghume, meeting point par ave)
// fast dist = x + b*d + y
// (x chale, cycle ma b vaar ghume, meeting point par ave)

// Variables:
// x = head થી cycle start સુધી distance
// y = meeting point થી cycle start સુધી distance
// d = cycle ની length
// Step 1: Distances
// slow dist = x + a*d + y
// fast dist = x + b*d + y
// Step 2: fast = 2 * slow
// x + b*d + y = 2 * (x + a*d + y)
// x + b*d + y = 2x + 2a*d + 2y
// b*d - 2a*d  = x + y
// d(b - 2a)   = x + y
// b-2a = K
// ∴ Kd = x + y
// Step 3: x nikalo
// x = Kd - y
// x = (K-1)d + (d-y)
// Conclusion:
// (K-1)d = cycle na pura rounds
// (d-y)  = meeting point thi cycle start sudhi distance

// ∴ head thi x steps = meeting point thi (d-y) steps
//   Banne cycle start par mळse!

// Isliye: slow = head mukine banne 1-1 step chalava thi
//         cycle start node mळe = tyathi next = NULL karo!

//node vagr j akho code lkhya vagr j easy way ch list<int>ll avu lkhvathi avi j jay

// ANS:=
// cycle exists
// 1 -> 2 -> 3 -> 4 -> NULL
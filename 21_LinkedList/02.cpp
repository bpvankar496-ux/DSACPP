//Palindrome Linked List 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Print Linked List
void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Check Palindrome
bool isPalindrome(Node* head) {
    vector<int> arr;

    // Step 1: LL → array
    Node* temp = head;
    while(temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // Step 2: check palindrome
    int l = 0, r = arr.size() - 1;

    while(l < r) {
        if(arr[l] != arr[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

int main() {

    // Create Linked List: 1 -> 2 -> 2 -> 1
    Node* head = new Node{1,
                    new Node{2,
                    new Node{2,
                    new Node{1, NULL}}}};

    cout << "Linked List:\n";
    print(head);

    if(isPalindrome(head)) {
        cout << "It is Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
}

// ANS:=
// Linked List:
// 1 -> 2 -> 2 -> 1 -> NULL
// It is Palindrome
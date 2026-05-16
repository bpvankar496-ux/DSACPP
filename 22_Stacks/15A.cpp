//Question 1: Linked List Palindrome (Complete Code)
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

bool isPalindrome(ListNode* head) {
    stack<int> st;
    ListNode* temp = head;

    while (temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (temp->val != st.top()) {
            return false;
        }
        st.pop();
        temp = temp->next;
    }

    return true;
}

int main() {
    // Example: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}

//ANS:=
//true
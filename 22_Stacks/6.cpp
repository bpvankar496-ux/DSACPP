//5. Reverse a Stack==> Recursion + pushAtBottom use kari pura stack reverse kariye.
#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, val);

    s.push(temp);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();

    reverseStack(s);

    pushAtBottom(s, temp);
}

int main() {
    stack<int> s;

    // Stack elements
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp1 = s;
    while (!temp1.empty()) {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    // Reverse stack
    reverseStack(s);

    cout << "Reversed Stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

// ANS:=
// Original Stack (top to bottom): 4 3 2 1 
// Reversed Stack (top to bottom): 1 2 3 4 
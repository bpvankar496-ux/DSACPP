//3. Push at Bottom of Stack==>Recursion thi stack empty sudhi jaine
#include <iostream>
#include <stack>
using namespace std;

// Push element at bottom of stack using recursion
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

int main() {
    stack<int> s;

    // Example elements
    s.push(1);
    s.push(2);
    s.push(3);

    int val = 4;

    pushAtBottom(s, val);

    // Print stack (top to bottom)
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

//ANS:=
//3 2 1 4
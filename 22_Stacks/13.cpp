// 12.Push at Bottom using Recursion
#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();

    pushAtBottom(s, x);

    s.push(top); // restore
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 4);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

//ANS:=
//1 2 3 4
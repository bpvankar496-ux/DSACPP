// Topic: Reverse a Queue

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int>& q) {
    stack<int> s;

    // push into stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // push back to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    reverse(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

//ANS:=
//3 2 1 
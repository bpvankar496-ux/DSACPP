// Topic: Stack using Deque

#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> dq;

public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        dq.pop_back();
    }

    int top() {
        return dq.back();
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}

//ANS:=
//3
//2
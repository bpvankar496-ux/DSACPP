// Topic: Queue using Deque

#include <iostream>
#include <deque>
using namespace std;

class Queue {
    deque<int> dq;

public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        dq.pop_front();
    }

    int front() {
        return dq.front();
    }
};

int main() {
    Queue q;

    q.push(5);
    q.push(10);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}

//ANS:=
//5
//10
// Topic: Interleave 2 Halves of Queue

#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    queue<int> first;

    // first half
    for(int i = 0; i < n/2; i++) {
        first.push(q.front());
        q.pop();
    }

    // merge alternately
    while(!first.empty()) {
        q.push(first.front());
        first.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    for(int i = 1; i <= 6; i++) q.push(i);

    interleave(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

//ANS:=
//1 4 2 5 3 6 
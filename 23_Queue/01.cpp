// Topic: Queue Introduction (STL)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // enqueue
    q.push(1);
    q.push(2);
    q.push(3);

    // front element
    cout << "Front: " << q.front() << endl;

    // dequeue
    q.pop();

    cout << "After pop, Front: " << q.front() << endl;

    return 0;
}

//ANS:=
//Front: 1
//After pop, Front: 2
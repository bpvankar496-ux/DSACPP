// Topic: Deque (Double Ended Queue)

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);

    cout << dq.front() << " " << dq.back() << endl;

    dq.pop_front();
    dq.pop_back();

    return 0;
}

//ANS:=
//3 2
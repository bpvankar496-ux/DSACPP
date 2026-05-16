//Bouns==>Queue (Reverse First K Elements of Queue)
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseK(queue<int>& q, int k) {
    stack<int> st;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push back from stack
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements
    int t = q.size() - k;
    while (t--) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5);

    int k = 3;
    reverseK(q, k);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

//ANS:=
//3 2 1 4 5 
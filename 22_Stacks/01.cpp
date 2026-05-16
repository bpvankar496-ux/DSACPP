//Stack in STL ==>STL stack ready-made container che (push, pop, top O(1))

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

//ANS:=
//3 2 1
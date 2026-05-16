// 11.Stack using Vector
#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int x) {
        v.push_back(x); // insert
    }

    void pop() {
        if(!v.empty()) v.pop_back(); // remove
    }

    int top() {
        return v.back(); // last element
    }

    bool empty() {
        return v.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

//ANS:=
//3 2 1
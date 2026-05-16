//1. Stack using Vector==>Vector na end ne stack top tariqe use kari push/pop kariye.
#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> vec;

public:
    void push(int val) {
        vec.push_back(val);
    }

    void pop() {
        if (isEmpty()) return;
        vec.pop_back();
    }

    int top() {
        if (isEmpty()) return -1;
        return vec.back();
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

//ANS:=
//3 2 1
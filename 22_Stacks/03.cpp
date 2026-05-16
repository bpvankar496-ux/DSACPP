//2. Stack using Linked List==>Head node ne stack top banavi push/pop front thi kariye.
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <class T>
class Stack {
    Node<T>* head;

public:
    Stack() {
        head = NULL;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == NULL) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() {
        if (head == NULL) return -1;
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    Stack<int> s;
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
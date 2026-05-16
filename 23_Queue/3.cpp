// Topic: Circular Queue using Array

#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    void enqueue(int val) {
        if((rear + 1) % size == front) {
            cout << "Queue Full\n";
            return;
        }

        if(front == -1) front = 0;

        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    void dequeue() {
        if(front == -1) return;

        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if(front == -1) return;

        int i = front;
        while(true) {
            cout << arr[i] << " ";
            if(i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}

//ANS:=
// 1 2 3 
// 2 3 
//Priority Queue for Object
#include <iostream>
#include <queue>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string n, int m) {
        name = n;
        marks = m;
    }

    //  Important: operator <
    bool operator<(const Student &obj) const {
        return this->marks < obj.marks; // max heap
    }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("Harsh", 500));
    pq.push(Student("Bhoomika", 1000));
    pq.push(Student("Vivek", 100));

    while(!pq.empty()) {
        cout << pq.top().name << " " << pq.top().marks << endl;
        pq.pop();
    }
}

// ANS:=
// Bhoomika 1000
// Harsh 500
// Vivek 100
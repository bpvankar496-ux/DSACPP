//Q3: Person → Student Inheritance
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person {
    string studentID;

public:
    // Child(x) : Parent(x) syntax
    Student(string n, int a, string id) : Person(n, a) {
        studentID = id;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "StudentID: " << studentID << endl;
    }
};

int main() {
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();
    return 0;
}
// ANS:=
// Name: Alice
// Age: 20
// StudentID: S12345
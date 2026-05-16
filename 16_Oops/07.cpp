// Single Inheritan==>ekk Parent → ekk Child

#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    
    void studentInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class Result : public Student {   // Single Inheritance
public:
    float marks;
    
    void resultInfo() {
        studentInfo();   // Parent ni method vapri
        cout << "Marks: " << marks << endl;
        
        if(marks >= 35)
            cout << "Result: PASS " << endl;
        else
            cout << "Result: FAIL " << endl;
    }
};

int main() {
    Result r;
    r.name = "Raj";
    r.rollNo = 101;
    r.marks = 75.5;
    
    r.resultInfo();
    
    return 0;
}

// ANS:=
// Name: Raj
// Roll No: 101
// Marks: 75.5
// Result: PASS 
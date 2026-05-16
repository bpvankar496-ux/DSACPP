// Virtual Function==>Parent pointer Thi Child no function call thy 
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal *a;
    Dog d;
    a = &d;
    a->speak();  // → Dog barks (bcz of virtual so child ne call thayo)
    return 0;
}

//ANS:=
//Dog barks
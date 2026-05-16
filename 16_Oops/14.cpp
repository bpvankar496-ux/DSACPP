//Overriding ==>Parent class Na function ne Child class ma redefine karvo.

#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    // Override - same name, same params
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal a;
    Dog d;
    
    a.speak();  // → Animal speaks
    d.speak();  // → Dog barks
    
    return 0;
}

// Overloading  →  Same class, Different params
//                 show(int) & show(string)

// Overriding   →  Parent-Child, Same params
//                 Animal::speak() & Dog::speak()

// ANS:=
// Animal speaks
// Dog barks
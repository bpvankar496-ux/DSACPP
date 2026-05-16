// Inheritance ==>Jem child n parents na gun made varsama, તtem Child class ne Parent class na properties ane methods made
#include<iostream>
using namespace std;

// Parent Class (Base Class)
class Animal {
public:
    string name;

    void eat() {
        cout << "Animal is eating" << endl;
    }

    void breathe() {
        cout << "Animal is breathing" << endl;
    }
};

// Child Class (Derived Class) - Animal ના ગુણ મળ્યા
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking: Woof!" << endl;
    }
};

int main() {
    Dog d;
    d.name = "Tommy";        // Animal class  mathi made
    d.eat();                 // Animal class  mathi made
    d.breathe();             // Animal class mathi made
    d.bark();                // Dog class potanu
    
    return 0;
}
// ANS:=
// Animal is eating
// Animal is breathing
// Dog is barking: Woof!
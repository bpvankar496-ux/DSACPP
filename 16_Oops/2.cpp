// Encapsulation → data ane functions ne ek class ma wrap karvu + data hiding (security mate)
//  Example: private variables + getter/setter
// Inheritance → ek class biji class na properties/functions use kare
//  Code reuse thay
// Abstraction → unnecessary details hide kari ne only important part batavu
//  User ne andar su thay e janvu jaruri nathi
// Polymorphism → ek function/naam na alag-alag forms hoy
// Same function, different behavior

#include <iostream>
using namespace std;

class Car {
    string name;
    string color;

public:
    // Default Constructor
    Car() {
        cout << "Constructor without params\n";
    }

    // Parameterized Constructor
    Car(string name, string color) {
        cout << "Constructor with params\n";
        this->name = name;
        this->color = color;
    }

    // Copy Constructor
Car(const Car &c) {
    cout << "Copy constructor called\n";
    this->name = c.name;
    this->color = c.color;
}

    void start() {
        cout << "Car has started...\n";
    }

    void stop() {
        cout << "Car has stopped...\n";
    }

    // Getter
    string getName() {
        return name;
    }
};

int main() {
    Car c0; // non-parameter constructor
    Car c1("Maruti 800", "White"); // parameter constructor
    Car c2("Fortuner", "White");
    Car c3 = c1;

    cout << "\nCar 1 Name: " << c1.getName() << endl;
    cout << "Car 2 Name: " << c2.getName() << endl;
    cout << "Car 3 Name (copy of c1): " << c3.getName() << endl;

    return 0;
}
// ANS:=
// Constructor without params
// Constructor with params
// Constructor with params
// Copy constructor called

// Car 1 Name: Maruti 800
// Car 2 Name: Fortuner
// Car 3 Name (copy of c1): Maruti 800
//Default copy shallow hoy chhe, etle hu custom copy constructor thi deep copy implement kari....
//Destructor ek special member function che je object destroy thay tyare automatically call thay che ane object dwara use thayeli memory/resources ne free kare che.

#include <iostream>
using namespace std;

class Demo {
public:
    int *data;

    // Constructor
    Demo(int val) {
        data = new int(val);
    }

    // shallow Deep Copy Constructor (IMPORTANT)
    Demo(const Demo &obj) {
        data = new int(*obj.data);   // separate memory
    }

    //  Destructor
    ~Demo() {
        delete data;
        cout << "Destructor called" << endl;
    }

    void show() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Demo obj1(10);
    Demo obj2 = obj1;

    *obj2.data = 50;

    obj1.show();
    obj2.show();
}
// ANS:=
// Value: 10
// Value: 50
// Destructor called
// Destructor called
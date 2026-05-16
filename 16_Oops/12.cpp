//Polymorphism==>Polymorphism એટલે "એક નામ, અનેક રૂપ". Same function અલગ અલગ રીતે કામ કરે.

// Compile-time → Function Overloading
// Run-time → Virtual Functions

#include <iostream>
using namespace std;

class Print {
public:
    // Int
    void show(int x) {
        cout << "int: " << x << endl;
    }

    // String
    void show(string str) {
        cout << "string: " << str << endl;
    }

    // Float
    void show(float f) {
        cout << "float: " << f << endl;
    }
};

int main() {
    Print obj1;

    obj1.show(25);           // → int: 25
    obj1.show("apnacollege"); // → string: apnacollege
    obj1.show(3.14f);        // → float: 3.14

    return 0;
}
// ANS:=
// int: 25
// string: apnacollege
// float: 3.14
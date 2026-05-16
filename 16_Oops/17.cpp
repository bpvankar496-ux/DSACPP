// Pure Virtual Function==>Child class ne forcefully function define karvo pade - Abstract Class bne
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;  // Pure virtual - "= 0" key 
};

class Circle : public Shape {
public:
    void area() {
        cout << "Circle area = 3.14 * r * r" << endl;
    }
};

int main() {
    // Shape s; no Object draw
    Circle c;
    c.area();  // → Circle area = 3.14 * r * r
    return 0;
}
// ANS:=
// Circle area = 3.14 * r * r
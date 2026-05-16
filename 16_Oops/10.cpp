//Hierarchical Inheritance==>એક Parent → Multiple Children
#include<iostream>
using namespace std;

class Shape {
public:
    float a, b;
    
    void setValues(float x, float y) {
        a = x;
        b = y;
    }
};

// Shape ના 3 અલગ-અલગ Children
class Rectangle : public Shape {
public:
    void area() {
        cout << "Rectangle Area = " << a * b << endl;
    }
};

class Triangle : public Shape {
public:
    void area() {
        cout << "Triangle Area = " << 0.5 * a * b << endl;
    }
};

class Cylinder : public Shape {
public:
    void volume() {
        cout << "Cylinder Volume = " << 3.14 * a * a * b << endl;
    }
};

int main() {
    Rectangle r;
    r.setValues(5, 3);
    r.area();       // 15
    
    Triangle t;
    t.setValues(4, 6);
    t.area();       // 12
    
    Cylinder c;
    c.setValues(3, 7);
    c.volume();     // ~197.82
    
    return 0;
}
// ANS:=
// Rectangle Area = 15
// Triangle Area = 12
// Cylinder Volume = 197.82
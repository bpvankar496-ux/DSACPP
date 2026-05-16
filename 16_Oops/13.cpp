// Operator Overloading==>+, -, *  operators Ne custom classes mate redefine karva
#include <iostream>
using namespace std;

class Complex {
public:
    int real, img;

    // Constructor
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i" << endl;
    }

    // Operator Overloading - + define 
    Complex operator+(Complex &c2) {
        int resReal = this->real + c2.real;
        int resImg  = this->img  + c2.img;
        Complex c3(resReal, resImg);
        return c3;
    }
};

int main() {
    Complex c1(1, 2);   // 1 + 2i
    Complex c2(3, 4);   // 3 + 4i

    cout << "c1 = ";
    c1.showNum();  

    cout << "c2 = ";
    c2.showNum();
    
    Complex c3 = c1 + c2;  // Operator overloading call 
     cout << "res = ";
    c3.showNum();           // → 4 + 6i
    
    return 0;
}
// ANS:=
// c1 = 1 + 2i
// c2 = 3 + 4i
// res = 4 + 6i
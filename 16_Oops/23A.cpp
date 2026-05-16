//Q1: Complex Number Subtraction
#include <iostream>
using namespace std;

class Complex {
public:
    int real, img;
    Complex(int r, int i) { real = r; img = i; }
    
    void showNum() {
        cout << real << " + " << img << "i" << endl;
    }
    
    Complex operator-(Complex &c2) {
        return Complex(this->real - c2.real, this->img - c2.img);
    }
};

int main() {
    Complex c1(5, 3);
    Complex c2(2, 1);
    Complex c3 = c1 - c2;
    c3.showNum();  // → 3 + 2i
    return 0;
}
//ANS:=
//3 + 2i
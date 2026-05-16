//Static Objects==>Static object program end સુધી memory માં રહે.
#include <iostream>
using namespace std;

class Demo {
public:
    Demo()  { cout << "Created" << endl; }
    ~Demo() { cout << "Destroyed" << endl; }
};

void fun() {
    static Demo d;  //only ek var bane function end thy to pn
}

int main() {
    fun();  //  Created
    fun();  //  already exist
    cout << "Main end" << endl;
    return 0;
    //  Main end
    //  Destroyed  (program end thy tyare)
}
// ANS:=
// Created
// Main end
// Destroyed
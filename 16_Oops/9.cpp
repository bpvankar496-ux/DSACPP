// Multiple Inheritance==>EKK Child → Multiple Parents
#include<iostream>
using namespace std;

class Mother {
public:
    void cooking() {
        cout << "from mother: cooking" << endl;
    }
};

class Father {
public:
    void driving() {
        cout << "from father: drive a car" << endl;
    }
};

// Child ne Mother + Father banne na guno
class Child : public Mother, public Father {
public:
    void study() {
        cout << "student ni study" << endl;
    }
};

int main() {
    Child c;
    
    c.cooking();   // Mother 
    c.driving();   // Father 
    c.study();     // potani
    
    return 0;
}
// ANS:=
// from mother: cooking
// from father: drive a car
// student ni study
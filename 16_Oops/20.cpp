//Friend Functions & Class==>Private data Ne baharthi access apvo hoi tyare friend vapro
#include <iostream>
using namespace std;

class Box {
private:
    int length = 10;
    
    friend void showLength(Box b);  // Friend declare
};

void showLength(Box b) {
    cout << "Length: " << b.length << endl;  // Private access 
}

int main() {
    Box b;
    showLength(b);  // Length: 10
    return 0;
}
// ANS:=
// Length: 10
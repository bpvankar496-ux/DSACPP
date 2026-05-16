//check power of 2 or not
#include <iostream>
using namespace std;

bool isPowerOf2(int num) {
    if(!(num & (num-1))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << isPowerOf2(4) << endl;
    cout << isPowerOf2(15) << endl;
    return 0;
}
//ANS:=
//1
//0
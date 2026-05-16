//Possible pairing P&C
#include <iostream>
#include <string>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }
    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}

int main() {
    cout << friendsPairing(4) << endl; //4 ways
    return 0;
}
//f(n) = f(n-1) + (n-1) * f(n-2)

//ANS:=
//10
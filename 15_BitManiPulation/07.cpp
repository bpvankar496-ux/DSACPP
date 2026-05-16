//clear ith bit==> ...0 hoik 1  convert 0
//   00000110   (6)
// & 11111101   (mask)
// -----------
//   00000100

#include <iostream>
using namespace std;

int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);
    return num & bitMask;
}

int main() {
    cout << clearIthBit(6, 1) << endl;
    return 0;
}
//ANS:=
//4
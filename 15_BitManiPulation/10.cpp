//WAF for clear last i bits
#include <iostream>
using namespace std;

void clearIBits(int num, int i) {
    int bitMask = (~0) << i;
    num = num & bitMask;

    cout << num << endl;
}

int main() {
    clearIBits(15, 2); //12
    return 0;
}

//step-1
//0  = 0 0 0 0
//~0 = 1 1 1 1

//step-2
// ~0     = 1 1 1 1
// << 2   = 1 1 0 0  = bitMask

//step-3
// num     = 1 1 1 1
// bitMask = 1 1 0 0
//         & ---------
//           1 1 0 0  = 12

//ANS:=
//12
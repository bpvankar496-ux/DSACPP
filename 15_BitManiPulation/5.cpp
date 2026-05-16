//Get ith in bit==>question n bitmask no & karo jo nonzero ave to  ans nai to 0 ave to 0==>concept=AND operator
// (num & (1 << i)) ≠ 0 → bit = 1
// (num & (1 << i)) = 0 → bit = 0

// ex-1(6,2)
//   00000110   (6)
// & 00000100   (mask)//i 2 ch so 2nd position ma 1 ch te rakhi bija badha 0 karva e amsk
// -----------
//   00000100 //nonzero ch so ans 1 baki 0 avt ans

#include <iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMask = 1 << i;

    if (!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    cout << getIthBit(6, 2) << endl;
    cout << getIthBit(7, 1) << endl;
    return 0;
}

//ANS:=
//1
//1
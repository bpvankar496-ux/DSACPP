//set ith bit==>cocept=OR operator...0 hoi k 1 convert in 1
//  00000110   (6)
// | 00001000   (mask)
// -----------
//   00001110

#include <iostream>
using namespace std;

int setIthBit(int num, int i) {
    int bitMask = 1 << i;
    return (num | bitMask);
}

int main() {
    cout << setIthBit(6, 3) << endl;
    return 0;
}
//ANS:=
//14
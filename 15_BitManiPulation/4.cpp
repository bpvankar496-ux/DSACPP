//binary ma odd even sodhva mate
//BITMASK=>& jeva oparator sathe su use karine logic sathe solve kare problm e sankhya like ahi &1 ee bitmask
//binary ma last ma 0 hoi to to e sankhya even thy n last ma 1 hoi to odd so e logic thi  koi pn sathe &1 karse to  last sankhya sathe thse 
//ex-1
//   00001000   (8)      
// & 00000001   (1)
// -----------
//   00000000  ==> last ma 0 so even

//ex-2
//   00000101   (5)
// & 00000001   (1)
// -----------
//   00000001  ==>lat ma 1 so odd
#include <iostream>
using namespace std;

void oddOrEven(int num) {
    if (!(num & 1)) {
        cout << "even\n";
    } else {
        cout << "odd\n";
    }
}

int main() {
    oddOrEven(5);
    oddOrEven(8);
    return 0;
}

//ANS:=
//odd
//even
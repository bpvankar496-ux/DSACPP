//update number....number apelo hase position apeli hase n su chnge karvanu tya te apelu hse e chnge karo e answer
// num = 7      =  0 1 1 1
// 1 << 2       =  0 1 0 0   (4)
// ~(1 << 2)    =  1 0 1 1   (complement)

// num & ~(1<<2)=  0 1 1 1
//              &  1 0 1 1
//              = ---------
//                 0 0 1 1   = 3

// val << i     =  0 << 2
//              =  0 0 0 0

// num | (val<<i)= 0 0 1 1
//              |  0 0 0 0
//              = ---------
//                 0 0 1 1   = 3

// Output = 3

#include <iostream>
using namespace std;

void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i); //clear ith bit

    num = num | (val << i);

    cout << num << endl;
}

int main() {
    updateIthBit(7, 2, 0);
    return 0;
}
//ANS:=
//3
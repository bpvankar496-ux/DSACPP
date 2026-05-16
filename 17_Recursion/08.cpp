#include <iostream>
using namespace std;

int pow(int x, int n) { //O(logn)
    if(n == 0) {
        return 1;
    }

    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;

    if(n % 2 != 0) {
        //odd
        return x * halfPowSquare;
    }
    return halfPowSquare;
}

int main() {
    cout << pow(2, 10) << endl;
    return 0;
}


// (2^10):

// pow(2,10) → half=pow(2,5)
// pow(2,5)  → half=pow(2,2)
// pow(2,2)  → half=pow(2,1)
// pow(2,1)  → half=pow(2,0)
// pow(2,0)  → return 1

// pachu return  thta
// pow(2,1) → 1*1=1, odd → 2*1 = 2
// pow(2,2) → 2*2=4, even → 4
// pow(2,5) → 4*4=16, odd → 2*16 = 32
// pow(2,10)→ 32*32=1024 

//ANS:=
//1024
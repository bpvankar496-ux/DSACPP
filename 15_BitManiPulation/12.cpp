//fast exponentitions==>X^n
#include <iostream>
using namespace std;

void fastExpo(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans = ans * x;
        }

        x = x * x;
        n = n >> 1;
    }

    cout << ans << endl;
}

int main() {
    fastExpo(2, 10);
    return 0;
}

//   n       n&1(lastBit)   ans      x = x*x    n >> 1
//10(1010)       0           1       2*2=4        5
//5 (0101)       1          1*4=4    4*4=16       2
//2 (0010)       0          4        16*16=256    1
//1 (0001)       1       4*256=1024  256*256      0
//Output = 1024 

//ANS:=
//1024

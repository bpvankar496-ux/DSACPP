// Q4: Tower of Hanoi - n disks ne A thi C maa move karo B helper vade
#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest) {
    if(n == 1) {
        cout << "transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }

    //transfer top n-1 from src to helper using dest as 'helper'
    towerOfHanoi(n-1, src, dest, helper);
    //transfer nth from src to dest
    cout << "transfer disk " << n << " from " << src << " to " << helper << endl;
    //transfer n-1 from helper to dest using src as 'helper'
    towerOfHanoi(n-1, helper, src, dest);
}

int main() {
    int n = 4;
    towerOfHanoi(4, "A", "B", "C");
    return 0;
}

// ANS:=
// transfer disk 1 from A to B
// transfer disk 2 from A to B
// transfer disk 1 from B to C
// transfer disk 3 from A to C
// transfer disk 1 from C to A
// transfer disk 2 from C to A
// transfer disk 1 from A to B
// transfer disk 4 from A to B
// transfer disk 1 from B to C
// transfer disk 2 from B to C
// transfer disk 1 from C to A
// transfer disk 3 from B to A
// transfer disk 1 from A to B
// transfer disk 2 from A to B
// transfer disk 1 from B to C

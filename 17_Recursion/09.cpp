//TILIMG problem
#include <iostream>
#include <string>
using namespace std;

int tilingProblem(int n) { //2xn
    if(n == 0 || n == 1) {
        return 1;
    }
    return tilingProblem(n-1) + tilingProblem(n-2);
}

int main() {
    int n = 3;
    cout << tilingProblem(5) << endl; //2x5
    return 0;
}
// Vertical MUKO  → bakinu 2×(n-1) → tilingProblem(n-1)
// Horizontal MUKO → bakinu2×(n-2) → tilingProblem(n-2)

//ANS:=
//8
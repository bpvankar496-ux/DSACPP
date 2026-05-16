//search perticular element ni jagay i j ma
//1=>Approach=Brute Force
// Time Complexity =O(n×m)

#include <iostream>
using namespace std;

bool bruteForce(int mat[][4], int n, int m, int key) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == key) {
                cout << "Found at (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Not Found" << endl;
    return false;
}

int main() {
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    bruteForce(mat, 4, 4, 33);
    return 0;
}

//ANS:=
//Found at (3, 1)
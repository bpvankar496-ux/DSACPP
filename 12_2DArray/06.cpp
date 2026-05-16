//3=>approach=Staircase
//time comp.=O(n+m)
#include <iostream>
using namespace std;

bool staircaseSearch(int mat[][4], int n, int m, int key) {
    int row = 0, col = m-1;  

    while(row < n && col >= 0) {
        if(mat[row][col] == key) {
            cout << "Found at (" << row << ", " << col << ")" << endl;
            return true;
        }
        else if(mat[row][col] > key) {
            col--;  
        }
        else {
            row++;  
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
    staircaseSearch(mat, 4, 4, 33);
    return 0;
}

//ANS:=
//Found at (3, 1)
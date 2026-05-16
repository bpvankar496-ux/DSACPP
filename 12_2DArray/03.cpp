//diagonal sum 
#include <iostream>
using namespace std;

int diagonalSum(int mat[3][3], int n) {
    int sum = 0;

    //O(N)
    for(int i=0; i<n; i++) {
        sum += mat[i][i]; //pd
        if(i != n-i-1) {
            sum += mat[i][n-i-1]; //sd
        }
    }

    cout << "sum = " << sum << endl;
    return sum;
}

int main() {
   
    int matrix[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

     diagonalSum(matrix, 3); 

    return 0;
}

//ANS:=
//sum = 25
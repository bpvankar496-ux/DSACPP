//matrix pointer in function==>2D array pointer thi access 
//void func(int mat[][4], int n, int m)   // simple
//void func(int (*mat)[4], int n, int m)  //  pointer syntax
//void func(int **mat, int n, int m)      // dynamic mate


#include <iostream>
using namespace std;

void func(int mat[][4], int n, int m) {
    // cout << "0th row ptr " << mat << endl;
    // cout << "1st row ptr " << mat+1 << endl;
    // cout << "2nd row ptr " << mat+2 << endl;

    // cout << "0th row value " << *mat << endl;
    // cout << "1st row value " << *(mat+1) << endl;
    // cout << "2nd row value " << *(mat+2) << endl;

    cout << *(*(mat + 2) + 2) << endl;//mat[row][col] same j thyy pelu only pointer ma ch 2 row 2 col vado elemnt print kre
}

// void func2(int (*mat)[4], int n, int m) {

// }

int main() {
    int mat[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};

    func(mat, 3, 4);
    return 0;
}

//*(*(mat + row) + col)=mat[row][col]

//ANS:=
//11
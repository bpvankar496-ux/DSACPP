// Question 3: Knight's Tour
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int sol[][8], int N){
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

void printSolution(int sol[][8], int N) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << sol[x][y] << " ";
        cout << endl;
    }
}

bool solveKTUtil(int x, int y, int movei, int sol[][8],
                 int xMove[], int yMove[], int N) {
    int k, next_x, next_y;
    if (movei == N * N)
        return true;

    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol, N)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei+1,
                            sol, xMove, yMove, N))
                return true;
            else
                sol[next_x][next_y] = -1; // backtracking
        }
    }
    return false;
}

bool solveKT(int N) {
    int sol[8][8];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    //As the Knight starts from cell(0,0)
    sol[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove, N)) {
        cout << "Solution does not exist\n";
        return false;
    }
    else
        printSolution(sol, N);

    return true;
}

int main(){
    int N = 8;
    solveKT(N);
}

// 8x8 board chhe
// Knight (0,0) thi start kare
// Drek cell exactly 1 vaar visit karvu joie
// sol[][] ma move number store thay chhe
// Logic:

// Knight na 8 possible moves chhe — xMove[] and yMove[]
// drek move try karo
// isSafe check karo — board ni andar chhe? already visited nathi?
// movei == N*N thay to badha cells visit thaya — print karo
// Nahi thay to backtrack — sol[x][y] = -1 karo

// ANS:=
// 0 59 38 33 30 17 8 63 
// 37 34 31 60 9 62 29 16 
// 58 1 36 39 32 27 18 7 
// 35 48 41 26 61 10 15 28 
// 42 57 2 49 40 23 6 19 
// 47 50 45 54 25 20 11 14 
// 56 43 52 3 22 13 24 5 
// 51 46 55 44 53 4 21 12 
//spiral matrix print (jalebi) 

#include <iostream>
using namespace std;

void spiral(int mat[4][4]) {

    int top = 0;
    int bottom = 3;
    int left = 0;
    int right = 3;

    while(top <= bottom && left <= right) {

        //TOP
        for(int j=left; j<=right; j++)
            cout << mat[top][j] << " ";

        //RIGHT
        for(int i=top+1; i<=bottom; i++)
            cout << mat[i][right] << " ";

        //BOTTOM
        for(int j=right-1; j>=left; j--)
            cout << mat[bottom][j] << " ";

        //LEFT
        for(int i=bottom-1; i>=top+1; i--)
            cout << mat[i][left] << " ";

        top++;
        bottom--;
        left++;
        right--;
    }
}

int main() {

    int mat[4][4] = {

        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}

    };

    spiral(mat);

    return 0;
}



//ANS:=
//1 2 3 4 8 12 16 15 9 6 7 11 10 


//input and output 2D array
#include <iostream>
using namespace std;

int main() {

    int arr[3][4];
    int n = 3, m = 4;
    cout << "Enter 12 elements:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j]<<" " ;
        }
        cout << endl;
    }
    return 0;
}

// ANS:=
// Enter 12 elements:
// 1 2 3 4 5 6 7 8 9 10 11 12
// Matrix:
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
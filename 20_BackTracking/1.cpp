// Backtracking ==>Pehla ek choice lo → aagad jao → jo wrong lage to pacho fari ne biji choice try karo”
// Simple==>try → Fail → Undo → Try again

//change arr
#include <iostream>
using namespace std;

// print array
void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// backtracking function
void changeArr(int arr[], int n, int i) {
    if(i == n) {
        printArr(arr, n);
        return;
    }

    // kaam karo (fill value)
    arr[i] = i + 1;

    // recursion call
    changeArr(arr, n, i + 1);

    // backtracking (undo)
    arr[i] -= 2;
}

int main() {
    int arr[5] = {0};
    int n = 5;

    changeArr(arr, n, 0);

    cout << "Final Array: ";
    printArr(arr, n);

    return 0;
}

// ANS:=
// 1 2 3 4 5 
// Final Array: -1 0 1 2 3 
// PS C:\Users\div
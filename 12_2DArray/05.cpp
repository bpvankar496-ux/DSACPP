//2=>approach=Row-wise Binary Search
//time comp.=O(n×logm)
#include <iostream>
using namespace std;

int binarySearch(int arr[], int m, int key) {
    int s = 0, e = m-1;
    while(s <= e) {
        int mid = (s+e)/2;
        if(arr[mid] == key) return mid;  
        else if(arr[mid] < key) s = mid+1;
        else e = mid-1;
    }
    return -1;  // not found
}

bool rowWiseBS(int mat[][4], int n, int m, int key) {
    for(int i=0; i<n; i++) {
        int col = binarySearch(mat[i], m, key);
        if(col != -1) {
            cout << "Found at (" << i << ", " << col << ")" << endl;
            return true;
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
    rowWiseBS(mat, 4, 4, 33);
    return 0;
}

//ANS:=
//Found at (3, 1)
// Q1: Recursive Binary Search - arr ma  key  no  index sodho
#include <iostream>
using namespace std;

int binSearch(int arr[], int si, int ei, int key) {
    if(si > ei) {
        return -1;
    }

    int mid = si + (ei - si)/2;
    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] > key) { //left half call
        return binSearch(arr, si, mid-1, key);
    } else { //right half call
        return binSearch(arr, mid+1, ei, key);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7, key = 5;
    cout << binSearch(arr, 0, n-1, key) << endl;
    return 0;
}
//ANS:=
//4
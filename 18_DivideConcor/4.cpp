#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int si, int ei, int tar) {

    int mid = si + (ei - si) / 2;
    if(arr[mid] == tar) {
        return mid;
    }

    if(arr[si] <= arr[mid]) { //L1
        if(arr[si] <= tar && tar <= arr[mid]) {
            //left half
            return search(arr, si, mid-1, tar);
        } else {
            //right half
            return search(arr, mid+1, ei, tar);
        }
    } else {
        //L2
        if(arr[mid] <= tar && tar <= arr[ei]) {
            //right half
            return search(arr, mid+1, ei, tar);
        } else {
            //left half
            return search(arr, si, mid-1, tar);
        }
    }
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7, tar = 4;
    cout << search(arr, 0, n-1, tar) << endl;
    return 0;
}

//ANS:=
//0
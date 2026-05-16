//Quick sort
#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1;

    for(int j = si; j < ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[ei]);
    //pivotIdx = i
    return i+1;
}

void quickSort(int arr[], int si, int ei) { //O(n* logn)
    if(si >= ei) {
        return;
    }

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx-1); //left half
    quickSort(arr, pivotIdx+1, ei); //right half
}

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    quickSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}

// Pivot = LAST element (4)
// SMALL left, BIG right

// {6,3,7,5,2,4} → pivot=4
// {3,2} [4] {6,7,5}
//   ↓           ↓
// {2,3}      {5,6,7}
// → 2 3 4 5 6 7 

//ANS:=
//2 3 4 5 6 7 
// Q3: Array માં inversions count કરો - a[i]>a[j] અને i<j હોય તે pairs
#include <iostream>
#include <vector>
using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1;
    int invCount = 0;
    vector<int> temp;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid - i);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int x = left, k = 0; x <= right; x++, k++) {
        arr[x] = temp[k];
    }

    return invCount;
}

int mergeSort(int arr[], int left, int right) {
    int invCount = 0;
    if(right > left) {
        int mid = (right + left) / 2;
        invCount  = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

int getInversions(int arr[], int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = 5;
    cout << "Inversion Count = " << getInversions(arr, n) << endl;
    return 0;
}

//ANS:=
//Inversion Count = 2
// Q1: String array ne Merge Sort vde alphabetically sort karp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(string arr[], int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;
    vector<string> temp;

    while(i <= mid && j <= hi) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= hi) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0, x = lo; idx < temp.size(); idx++, x++) {
        arr[x] = temp[idx];
    }
}

void mergeSort(string arr[], int lo, int hi) {
    if(lo >= hi) {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);

    merge(arr, lo, mid, hi);
}

int main() {
    string arr[4] = {"sun", "march", "mars", "mercury"};

    mergeSort(arr, 0, 3);

    for(int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

//ANS:=
// march
// mars
// mercury
// sun
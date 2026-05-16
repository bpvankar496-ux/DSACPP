//last accurrence
#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> arr, int i, int target) {
    if(i == arr.size()) {
        return -1;
    }
    if(arr[i] == target) {
        return i;
    }
    return firstOccur(arr, i+1, target);
}

int lastOccur(vector<int> arr, int target, int i) {
    if(i == arr.size()) {
        return -1;
    }

    int idxFound = lastOccur(arr, target, i+1);

    if(idxFound == -1 && arr[i] == target) {
        return i;
    }
    return idxFound;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4};

    cout << "First: " << firstOccur(arr, 0, 3) << endl;
    cout << "Last: "  << lastOccur(arr, 3, 0)  << endl;

    return 0;
}

// Array:  1  2  3  3  3  4
// Index:  0  1  2  3  4  5

// First 3 → index 2
// Last  3 → index 4

//ANS:=
//First: 2
//Last: 4
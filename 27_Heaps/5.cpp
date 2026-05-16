//heap sort
#include <iostream>
#include <vector>
using namespace std;

// Heapify function (Max Heap)
void heapify(int i, vector<int>& arr, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if (left < n && arr[left] > arr[maxI]) {
        maxI = left;
    }

    if (right < n && arr[right] > arr[maxI]) {
        maxI = right;
    }

    if (maxI != i) {
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n);
    }
}

// Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(i, arr, n);
    }

    // Step 2: Extract elements
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move max to end
        heapify(0, arr, i);     // fix heap
    }
}

// Print function
void print(vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};

    heapSort(arr);

    cout << "Sorted: ";
    print(arr);

    return 0;
}

//ANS:=
//Sorted: 1 2 3 4 5 
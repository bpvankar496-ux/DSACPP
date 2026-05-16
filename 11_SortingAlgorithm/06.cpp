//ch sort
//METHOD 1

#include <iostream>
#include <algorithm>
using namespace std;

void sortChar(char arr[], int n) {
    sort(arr, arr+n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    char arr[] = {'d','b','f','e','d','a','c'};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortChar(arr, n);
    return 0;
}

//METHOD 2

#include <iostream>
using namespace std;

void print(char arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(char arr[], int n) {
    for(int i=1; i<n; i++) {
        char curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr;
    }

    print(arr, n);
}

int main() {
    char arr[8] = {'d', 'b','f' ,'e','d', 'a', 'c'};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, 8);
    return 0;
}

//ANS:=
//a b c d d e f 
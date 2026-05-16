//subarray
//METHOD 1
#include <iostream>
using namespace std;

int count=0;
void printSubarrays(int *arr, int n) {
    for(int i = 0; i< n; i++) {
        for(int j= i; j< n; j++) {
           //cout << "(" << i<< "," << j<< ") ";
            for(int k= i; k <= j; k++) {
                cout << arr[k];
            }
            count++;
            cout << ", ";
        }
        cout << endl;
    }
     cout << "Total Subarrays = " << count;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printSubarrays(arr, n);

    return 0;
}

//total subarr ==>math formula=n*(n+1)/2
//time compl.=O(n^3) bcz 3 var n sudhu so....


// ANS:=
// 1, 12, 123, 1234, 12345, 
// 2, 23, 234, 2345, 
// 3, 34, 345, 
// 4, 45, 
// 5, 
//Total Subarrays = 15


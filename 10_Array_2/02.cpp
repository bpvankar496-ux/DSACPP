//max subarray sum
//1=brute force approch max subarray sum
//time comp.=O(n^3)

#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum1(int arr[], int n) {
    int maxSum = INT_MIN;

    for (int i= 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int currSum = 0;

            for (int k=i; k<=j; k++) {
                currSum += arr[k];
            }

            cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }
    cout<<"maximum subarray sum ="<<maxSum<<endl;
}

int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxSubarraySum1(arr,n);

    return 0;
}

// ANS:=
// 2, -1, 5, 0, 4, 6, 
// -3, 3, -2, 2, 4, 
// 6, 1, 5, 7, 
// -5, -1, 1, 
// 4, 6, 
// 2, 
// maximum subarray sum =7
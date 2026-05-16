//3=kadanes algorithm DP max subarray sum
//ama jo koi ek subarry nn total negative ave to ene add karvathi ghte j max made nai  etle ava case ma reintilization 0 kari n karvu
 
#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum1(int arr[], int n) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0;i<n;i++){
        currSum+=arr[i];
        maxSum=max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
        }
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
// maximum subarray sum =7
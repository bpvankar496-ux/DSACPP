//Question 5: Split Array Largest Sum
#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& nums, int k, int maxSum) {
    int count = 1, currSum = 0;

    for(int num : nums) {
        if(currSum + num > maxSum) {
            count++;
            currSum = num;
        } else {
            currSum += num;
        }
    }

    return count <= k;
}

int splitArray(vector<int>& nums, int k) {
    int low = 0, high = 0;

    for(int num : nums) {
        low = max(low, num);
        high += num;
    }

    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canSplit(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7,2,5,10,8};
    int k = 2;

    cout << "Output: " << splitArray(nums, k) << endl;
    return 0;
}

//ANS:=
//Output: 18
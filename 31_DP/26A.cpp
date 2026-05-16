// Question 8: Mountain Array (Longest Bitonic Subsequence)
// Minimum elements remove karo jathi mountain array bane
#include <iostream>
#include <vector>
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();

    // LIS from left
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    // LDS from right
    vector<int> lds(n, 1);
    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    // max bitonic length find karo
    int maxBitonic = 0;
    for (int i = 1; i < n-1; i++) {
        if (lis[i] > 1 && lds[i] > 1) {
            maxBitonic = max(maxBitonic, lis[i] + lds[i] - 1);
        }
    }

    return n - maxBitonic;
}

int main() {
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << minimumMountainRemovals(nums) << endl;
    // 3
    return 0;
}

//ANS:=
//3
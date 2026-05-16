// Question 5: House Thief (House Robber)
// Adjacent houses rob na karo — maximum amount find karo
#include <iostream>
#include <vector>
using namespace std;

int houseRobber(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }
    return dp[n-1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << houseRobber(nums) << endl;
    // 12 (2+9+1)
    return 0;
}

//ANS:=
//12
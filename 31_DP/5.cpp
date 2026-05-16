//  Target Sum Subset
// Array ma subset chhe ke nahi je target sum bane
#include <iostream>
#include <vector>
using namespace std;

bool targetSubset(vector<int>& arr, int n, int target) {
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << (targetSubset(arr, arr.size(), target) ? "Yes" : "No") << endl;
    // Yes (4+5=9)
    return 0;
}

//ANS:=
//Yes
// Question 7: Equal Subset Sum Difference
// Array ne 2 subsets ma divide karo jathi sum equal hoy
#include <iostream>
#include <vector>
using namespace std;

bool equalSubsetSum(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    for (int x : arr) sum += x;

    // odd sum hoy to equal partition possible nathi
    if (sum % 2 != 0) return false;

    int target = sum / 2;
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
    vector<int> arr = {1, 5, 11, 5};
    cout << (equalSubsetSum(arr) ? "true" : "false") << endl;
    // true (1+5+5 = 11)
    return 0;
}

//ANS:=
//true
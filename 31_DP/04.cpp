//DP PART 2

//  0-1 Knapsack - Recursion + Memoization + Tabulation
// Weight limit ma maximum value items rakho
#include <iostream>
#include <vector>
using namespace std;

// Recursion
int knapsackRec(vector<int>& val, vector<int>& wt, int n, int W) {
    if (n == 0 || W == 0) return 0;

    if (wt[n-1] <= W) {
        int include = val[n-1] + knapsackRec(val, wt, n-1, W-wt[n-1]);
        int exclude = knapsackRec(val, wt, n-1, W);
        return max(include, exclude);
    }
    return knapsackRec(val, wt, n-1, W);
}

// Memoization
int knapsackMemo(vector<int>& val, vector<int>& wt, int n, int W,
                 vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n-1] <= W) {
        int include = val[n-1] + knapsackMemo(val, wt, n-1, W-wt[n-1], dp);
        int exclude = knapsackMemo(val, wt, n-1, W, dp);
        dp[n][W] = max(include, exclude);
    } else {
        dp[n][W] = knapsackMemo(val, wt, n-1, W, dp);
    }
    return dp[n][W];
}

// Tabulation
int knapsackTab(vector<int>& val, vector<int>& wt, int n, int W) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50, n = val.size();

    cout << "Recursion: "   << knapsackRec(val, wt, n, W) << endl;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << "Memoization: " << knapsackMemo(val, wt, n, W, dp) << endl;

    cout << "Tabulation: "  << knapsackTab(val, wt, n, W) << endl;
    // 220
    return 0;
}

// ANS:=
// Recursion: 220
// Memoization: 220
// Tabulation: 220
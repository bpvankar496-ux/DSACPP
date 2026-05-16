//DP PART 6

// Matrix Chain Multiplication - Recursion + Memoization + Tabulation
// Matrices multiply karva minimum operations find karo
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion
int mcmRec(vector<int>& arr, int i, int j) {
    if (i >= j) return 0;
    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcmRec(arr, i, k) +
                   mcmRec(arr, k+1, j) +
                   arr[i-1] * arr[k] * arr[j];
        minCost = min(minCost, cost);
    }
    return minCost;
}

// Memoization
int mcmMemo(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcmMemo(arr, i, k, dp) +
                   mcmMemo(arr, k+1, j, dp) +
                   arr[i-1] * arr[k] * arr[j];
        dp[i][j] = min(dp[i][j], cost);
    }
    return dp[i][j];
}

// Tabulation
int mcmTab(vector<int>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] +
                           arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();

    cout << "Recursion: "   << mcmRec(arr, 1, n-1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: " << mcmMemo(arr, 1, n-1, dp) << endl;

    cout << "Tabulation: "  << mcmTab(arr, n) << endl;
    // 30
    return 0;
}

// ANS:=
// Recursion: 30
// Memoization: 30
// Tabulation: 30
// Climbing Stairs - Recursion + Memoization + Tabulation
// N stairs chadhva mate minimum steps find karo
#include <iostream>
#include <vector>
using namespace std;

// Recursion
int climbRec(int n) {
    if (n == 0 || n == 1) return 1;
    return climbRec(n-1) + climbRec(n-2);
}

// Memoization
int climbMemo(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = climbMemo(n-1, dp) + climbMemo(n-2, dp);
    return dp[n];
}

// Tabulation
int climbTab(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 5;

    cout << "Recursion: " << climbRec(n) << endl;

    vector<int> dp(n+1, -1);
    cout << "Memoization: " << climbMemo(n, dp) << endl;

    cout << "Tabulation: " << climbTab(n) << endl;
    // 8
    return 0;
}

//ANS:=
// Recursion: 8
// Memoization: 8
// Tabulation: 8
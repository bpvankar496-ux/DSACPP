//  Nth Catalan Number - Recursion + Memoization + Tabulation
// Nth Catalan number find karo
#include <iostream>
#include <vector>
using namespace std;

// Recursion
int catalanRec(int n) {
    if (n == 0 || n == 1) return 1;
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += catalanRec(i) * catalanRec(n-1-i);
    }
    return result;
}

// Memoization
int catalanMemo(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    for (int i = 0; i < n; i++) {
        dp[n] += catalanMemo(i, dp) * catalanMemo(n-1-i, dp);
    }
    return dp[n];
}

// Tabulation
int catalanTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 5;

    cout << "Recursion: "   << catalanRec(n) << endl;

    vector<int> dp(n+1, -1);
    cout << "Memoization: " << catalanMemo(n, dp) << endl;

    cout << "Tabulation: "  << catalanTab(n) << endl;
    // 42
    return 0;
}

// ANS:=
// Recursion: 42
// Memoization: 42
// Tabulation: 42